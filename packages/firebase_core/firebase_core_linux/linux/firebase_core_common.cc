#include "firebase_core_linux/firebase_core_common.h"
#include <cstring>
#include <iostream>
#include <flutter_linux/flutter_linux.h>
#include <firebase/app.h>


std::map<std::string,firebase::App*> apps_ {};

FlValue* firebase_initializeCore(FlValue* params) {

  if (apps_.size() == 0){
    firebase::App* app = firebase::App::Create();
    if (app == nullptr){
      // std::cerr << "Failed to initialize default app" << std::endl;
    }
    //else {
    //   apps_.emplace(firebase::kDefaultAppName, app);
    //   // std::cout << "Initialized Default App" << std::endl;
    // }
  }
  FlValue* list = fl_value_new_list();

  for (auto& app_entry : apps_){
    // std::cout << app_entry.first << std::endl;
    auto app = app_entry.second;
    FlValue* info = fl_value_new_map();
    fl_value_set_string_take(info, KEY_API_KEY, fl_value_new_string(app->options().api_key()));
    fl_value_set_string_take(info, KEY_APP_ID, fl_value_new_string(app->options().app_id()));
    fl_value_set_string_take(info, KEY_MESSAGING_SENDER_ID, fl_value_new_string(app->options().messaging_sender_id()));
    fl_value_set_string_take(info, KEY_DATABASE_URL, fl_value_new_string(app->options().database_url()));
    fl_value_set_string_take(info, KEY_TRACKING_ID, fl_value_new_string(app->options().ga_tracking_id()));
    fl_value_set_string_take(info, KEY_STORAGE_BUCKET, fl_value_new_string(app->options().storage_bucket()));
    fl_value_set_string_take(info, KEY_PROJECT_ID, fl_value_new_string(app->options().project_id()));
    fl_value_append(list, info);
  }

  return list;
}
void firebase_initializeApp(FlValue* params){
  auto options = fl_value_lookup_string(params, KEY_OPTIONS);
  auto appName = fl_value_get_string(fl_value_lookup_string(options, KEY_APP_NAME));

  firebase::AppOptions appOptions;
  for (uint8_t option = 0; option < fl_value_get_length(options); option++){
    auto key = fl_value_get_string(fl_value_get_map_key(options, option));
    auto value = fl_value_get_string(fl_value_get_map_value(options, option));
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
  apps_[appName] = firebase::App::Create(appOptions);
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
