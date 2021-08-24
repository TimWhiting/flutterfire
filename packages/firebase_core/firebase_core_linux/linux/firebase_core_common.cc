#include <cstring>
#include <iostream>
#include <assert.h>
#include <firebase/app.h>
#include "firebase_core_linux/firebase_core_common.h"



std::map<std::string,firebase::App*> apps_ {};

FlValue* firebaseAppToMap(firebase::App* app){
  FlValue* appMap = fl_value_new_map();
  FlValue* optionsMap = fl_value_new_map();
  fl_value_set_string_take(optionsMap, KEY_API_KEY, fl_value_new_string(app->options().api_key()));
  fl_value_set_string_take(optionsMap, KEY_APP_ID, fl_value_new_string(app->options().app_id()));
  fl_value_set_string_take(optionsMap, KEY_MESSAGING_SENDER_ID, fl_value_new_string(app->options().messaging_sender_id()));
  fl_value_set_string_take(optionsMap, KEY_PROJECT_ID, fl_value_new_string(app->options().project_id()));
  fl_value_set_string_take(optionsMap, KEY_DATABASE_URL, fl_value_new_string(app->options().database_url()));
  fl_value_set_string_take(optionsMap, KEY_STORAGE_BUCKET, fl_value_new_string(app->options().storage_bucket()));
  fl_value_set_string_take(optionsMap, KEY_TRACKING_ID, fl_value_new_string(app->options().ga_tracking_id()));
  fl_value_set_string_take(appMap, KEY_NAME, fl_value_new_string(app->name()));
  fl_value_set_string_take(appMap, KEY_OPTIONS, optionsMap);
  fl_value_set_string_take(appMap, KEY_IS_AUTOMATIC_DATA_COLLECTION_ENABLED, fl_value_new_bool(false));
  // TODO: Do plugin constants from other firebase plugins via some sort of registry
  fl_value_set_string_take(appMap, KEY_PLUGIN_CONSTANTS, fl_value_new_map());
  return appMap;
}

FlValue* firebase_initializeCore(FlValue* params) {

  if (apps_.size() == 0){
    firebase::App* app = firebase::App::Create();
    if (app == nullptr){
      std::cerr << "Failed to initialize default app" << std::endl;
    } else {
      apps_.emplace(firebase::kDefaultAppName, app);
    }
  }
  FlValue* list = fl_value_new_list();

  for (auto& app_entry : apps_){
    auto app = app_entry.second;
    auto appMap = firebaseAppToMap(app);
    fl_value_append(list, appMap);
  }

  return list;
}
FlValue* firebase_initializeApp(FlValue* params){
  auto options = fl_value_lookup_string(params, KEY_OPTIONS);
  auto appName = fl_value_get_string(fl_value_lookup_string(params, KEY_APP_NAME));

  firebase::AppOptions appOptions;

  for (uint16_t option = 0; option < fl_value_get_length(options); option++){
    auto key = fl_value_get_string(fl_value_get_map_key(options, option));
    auto flvalue = fl_value_get_map_value(options, option);

    if (fl_value_get_type(flvalue) == FL_VALUE_TYPE_STRING){ // Avoid nulls
      auto value = fl_value_get_string(flvalue);

      if (strcmp(key, KEY_APP_ID) == 0){
        appOptions.set_app_id(value);
      }
      if (strcmp(key, KEY_API_KEY) == 0){
        appOptions.set_api_key(value);
      }
      if (strcmp(key, KEY_MESSAGING_SENDER_ID) == 0){
        appOptions.set_messaging_sender_id(value);
      }
      if (strcmp(key, KEY_DATABASE_URL) == 0){
        appOptions.set_database_url(value);
      }
      if (strcmp(key, KEY_TRACKING_ID) == 0){
        appOptions.set_ga_tracking_id(value);
      }
      if (strcmp(key, KEY_STORAGE_BUCKET) == 0){
        appOptions.set_storage_bucket(value);
      }
      if (strcmp(key, KEY_PROJECT_ID) == 0){
        appOptions.set_project_id(value);
      }
    }
  }
  apps_[appName] = firebase::App::Create(appOptions, appName);
  return firebaseAppToMap(apps_[appName]);
}

void firebaseApp_delete(FlValue* params){
  auto appName = fl_value_get_string(fl_value_lookup_string(params, KEY_APP_NAME));
  auto app = apps_[appName];
  apps_.erase(appName);
  delete app;
}

void firebaseApp_setAutomaticDataCollectionEnabled(FlValue* params) {

}
void firebaseApp_setAutomaticResourceManagementEnabled(FlValue* params){
}
