//
//  Generated file. Do not edit.
//

// clang-format off

#include "generated_plugin_registrant.h"

#include <firebase_auth_linux/firebase_auth_linux_plugin.h>

void fl_register_plugins(FlPluginRegistry* registry) {
  g_autoptr(FlPluginRegistrar) firebase_auth_linux_registrar =
      fl_plugin_registry_get_registrar_for_plugin(registry, "FirebaseAuthLinuxPlugin");
  firebase_auth_linux_plugin_register_with_registrar(firebase_auth_linux_registrar);
}
