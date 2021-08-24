#include "firebase_core_linux/firebase_core_linux_plugin.h"

#include <flutter_linux/flutter_linux.h>
#include <gtk/gtk.h>

#include <cstring>

#include "firebase/app.h"
#include "firebase_core_linux/firebase_core_common.h"

#define FIREBASE_CORE_LINUX_PLUGIN(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj), firebase_core_linux_plugin_get_type(), \
                              FirebaseCoreLinuxPlugin))

struct _FirebaseCoreLinuxPlugin {
  GObject parent_instance;
};

G_DEFINE_TYPE(FirebaseCoreLinuxPlugin, firebase_core_linux_plugin, g_object_get_type())

// Called when a method call is received from Flutter.
static void firebase_core_linux_plugin_handle_method_call(
    FirebaseCoreLinuxPlugin* self,
    FlMethodCall* method_call) {
  g_autoptr(FlMethodResponse) response = nullptr;

  const gchar* method = fl_method_call_get_name(method_call);
  FlValue* args = fl_method_call_get_args(method_call);

  if (strcmp(method, FIREBASE_INITIALIZE_CORE) == 0) {
    FlValue* initResult = firebase_initializeCore(args);
    response = FL_METHOD_RESPONSE(fl_method_success_response_new(initResult));
  } else if (strcmp(method, FIREBASE_INITIALIZE_APP) == 0) {
    FlValue* initResult = firebase_initializeApp(args);
    response = FL_METHOD_RESPONSE(fl_method_success_response_new(initResult));
  } else if (strcmp(method, FIREBASEAPP_DELETE) == 0) {
    firebaseApp_delete(args);
    response = FL_METHOD_RESPONSE(fl_method_success_response_new(fl_value_new_null()));
  } else {
    response = FL_METHOD_RESPONSE(fl_method_not_implemented_response_new());
  }

  fl_method_call_respond(method_call, response, nullptr);
}

static void firebase_core_linux_plugin_dispose(GObject* object) {
  G_OBJECT_CLASS(firebase_core_linux_plugin_parent_class)->dispose(object);
}

static void firebase_core_linux_plugin_class_init(FirebaseCoreLinuxPluginClass* klass) {
  G_OBJECT_CLASS(klass)->dispose = firebase_core_linux_plugin_dispose;
}

static void firebase_core_linux_plugin_init(FirebaseCoreLinuxPlugin* self) {}

static void method_call_cb(FlMethodChannel* channel, FlMethodCall* method_call,
                           gpointer user_data) {
  FirebaseCoreLinuxPlugin* plugin = FIREBASE_CORE_LINUX_PLUGIN(user_data);
  firebase_core_linux_plugin_handle_method_call(plugin, method_call);
}

void firebase_core_linux_plugin_register_with_registrar(FlPluginRegistrar* registrar) {
  FirebaseCoreLinuxPlugin* plugin = FIREBASE_CORE_LINUX_PLUGIN(
      g_object_new(firebase_core_linux_plugin_get_type(), nullptr));

  g_autoptr(FlStandardMethodCodec) codec = fl_standard_method_codec_new();
  g_autoptr(FlMethodChannel) channel =
      fl_method_channel_new(fl_plugin_registrar_get_messenger(registrar),
                            FIREBASE_CORE_METHOD_CHANNEL_NAME,
                            FL_METHOD_CODEC(codec));
  fl_method_channel_set_method_call_handler(channel, method_call_cb,
                                            g_object_ref(plugin),
                                            g_object_unref);

  g_object_unref(plugin);
}
