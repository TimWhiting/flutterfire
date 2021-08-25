#include "firebase_auth_linux/firebase_auth_linux_plugin.h"
#include "firebase_auth_linux/firebase_auth_common_plugin.h"

#include <flutter_linux/flutter_linux.h>
#include <gtk/gtk.h>
#include <sys/utsname.h>

#include <cstring>

#define FIREBASE_AUTH_LINUX_PLUGIN(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj), firebase_auth_linux_plugin_get_type(), \
                              FirebaseAuthLinuxPlugin))

struct _FirebaseAuthLinuxPlugin {
  GObject parent_instance;
};

G_DEFINE_TYPE(FirebaseAuthLinuxPlugin, firebase_auth_linux_plugin, g_object_get_type())

// Called when a method call is received from Flutter.
static void firebase_auth_linux_plugin_handle_method_call(
    FirebaseAuthLinuxPlugin* self,
    FlMethodCall* method_call) {
  g_autoptr(FlMethodResponse) response = nullptr;

  const gchar* method = fl_method_call_get_name(method_call);

  if (strcmp(method, "getPlatformVersion") == 0) {
    struct utsname uname_data = {};
    uname(&uname_data);
    g_autofree gchar *version = g_strdup_printf("Linux %s", uname_data.version);
    g_autoptr(FlValue) result = fl_value_new_string(version);
    response = FL_METHOD_RESPONSE(fl_method_success_response_new(result));
  } else {
    response = FL_METHOD_RESPONSE(fl_method_not_implemented_response_new());
  }

  fl_method_call_respond(method_call, response, nullptr);
}

static void firebase_auth_linux_plugin_dispose(GObject* object) {
  G_OBJECT_CLASS(firebase_auth_linux_plugin_parent_class)->dispose(object);
}

static void firebase_auth_linux_plugin_class_init(FirebaseAuthLinuxPluginClass* klass) {
  G_OBJECT_CLASS(klass)->dispose = firebase_auth_linux_plugin_dispose;
}

static void firebase_auth_linux_plugin_init(FirebaseAuthLinuxPlugin* self) {}

static void method_call_cb(FlMethodChannel* channel, FlMethodCall* method_call,
                           gpointer user_data) {
  FirebaseAuthLinuxPlugin* plugin = FIREBASE_AUTH_LINUX_PLUGIN(user_data);
  firebase_auth_linux_plugin_handle_method_call(plugin, method_call);
}

void firebase_auth_linux_plugin_register_with_registrar(FlPluginRegistrar* registrar) {
  FirebaseAuthLinuxPlugin* plugin = FIREBASE_AUTH_LINUX_PLUGIN(
      g_object_new(firebase_auth_linux_plugin_get_type(), nullptr));

  g_autoptr(FlStandardMethodCodec) codec = fl_standard_method_codec_new();
  g_autoptr(FlMethodChannel) channel =
      fl_method_channel_new(fl_plugin_registrar_get_messenger(registrar),
                            FIREBASE_AUTH_METHOD_CHANNEL_NAME,
                            FL_METHOD_CODEC(codec));
  fl_method_channel_set_method_call_handler(channel, method_call_cb,
                                            g_object_ref(plugin),
                                            g_object_unref);

  g_object_unref(plugin);
}
