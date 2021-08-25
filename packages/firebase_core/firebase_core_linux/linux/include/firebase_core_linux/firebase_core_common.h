#ifndef FLUTTER_PLUGIN_FIREBASE_CORE_COMMON_H_
#define FLUTTER_PLUGIN_FIREBASE_CORE_COMMON_H_

#include <flutter_linux/flutter_linux.h>
#include <map>
#include <vector>
#include <string>

#define FIREBASE_CORE_METHOD_CHANNEL_NAME "plugins.flutter.io/firebase_core"
#define FIREBASE_INITIALIZE_CORE "Firebase#initializeCore"
#define FIREBASE_INITIALIZE_APP "Firebase#initializeApp"
#define FIREBASEAPP_DELETE "FirebaseApp#delete"
#define FIREBASEAPP_SET_AUTOMATIC_DATA_COLLECTION_ENABLED "FirebaseApp#setAutomaticDataCollectionEnabled"
#define FIREBASEAPP_SET_AUTOMATIC_RESOURCE_MANAGEMENT_ENABLED "FirebaseApp#setAutomaticResourceManagementEnabled"
#define KEY_API_KEY "apiKey"
#define KEY_APP_ID "appId"
#define KEY_MESSAGING_SENDER_ID "messagingSenderId"
#define KEY_PROJECT_ID "projectId"
#define KEY_DATABASE_URL "databaseURL"
#define KEY_STORAGE_BUCKET "storageBucket"
#define KEY_OPTIONS "options"
#define KEY_TRACKING_ID "trackingId"
#define KEY_IS_AUTOMATIC_DATA_COLLECTION_ENABLED "isAutomaticDataCollectionEnabled"
#define KEY_PLUGIN_CONSTANTS "pluginConstants"
#define KEY_NAME "name"
#define KEY_ENABLED "enabled"
#define KEY_APP_NAME "appName"

#ifdef FLUTTER_PLUGIN_IMPL
#define FLUTTER_PLUGIN_EXPORT __attribute__((visibility("default")))
#else
#define FLUTTER_PLUGIN_EXPORT
#endif

FlValue* firebase_initializeCore(FlValue* params);
void firebase_initializeApp(FlValue* params);
void firebaseApp_delete(FlValue* params);
void firebaseApp_setAutomaticDataCollectionEnabled(FlValue* params);
void firebaseApp_setAutomaticResourceManagementEnabled(FlValue* params);

#endif  // FLUTTER_PLUGIN_FIREBASE_CORE_COMMON_H_
