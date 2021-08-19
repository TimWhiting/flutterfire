#ifndef FLUTTER_PLUGIN_FIREBASE_CORE_COMMON_H_
#define FLUTTER_PLUGIN_FIREBASE_CORE_COMMON_H_

#include <flutter_linux/flutter_linux.h>
#include <firebase/app.h>
#include <map>
#include <vector>
#include <string>

#define FIREBASE_CORE_METHOD_CHANNEL_NAME "plugins.flutter.io/firebase_core"
#define FIREBASE_INITIALIZE_CORE "Firebase#initializeCore"
#define FIREBASE_INITIALIZE_APP "Firebase#initializeApp"
#define FIREBASEAPP_DELETE "FirebaseApp#delete"
#define FIREBASEAPP_SET_AUTOMATIC_DATA_COLLECTION_ENABLED "FirebaseApp#setAutomaticDataCollectionEnabled"
#define FIREBASEAPP_SET_AUTOMATIC_RESOURCE_MANAGEMENT_ENABLED "FirebaseApp#setAutomaticResourceManagementEnabled"


#ifdef FLUTTER_PLUGIN_IMPL
#define FLUTTER_PLUGIN_EXPORT __attribute__((visibility("default")))
#else
#define FLUTTER_PLUGIN_EXPORT
#endif


std::vector<std::map<std::string, std::string>> firebase_initializeCore();
void firebase_initializeApp(std::string appName, std::map<std::string, std::string> options);
void firebaseApp_delete(std::string appName, std::map<std::string, std::string> options);
void firebaseApp_setAutomaticDataCollectionEnabled(bool enabled);
void firebaseApp_setAutomaticResourceManagementEnabled(bool enabled);


#endif  // FLUTTER_PLUGIN_FIREBASE_CORE_COMMON_H_
