cmake_minimum_required(VERSION 3.10)
set(PROJECT_NAME "firebase_core_linux")
project(${PROJECT_NAME} LANGUAGES CXX)

# This value is used when generating builds using this plugin, so it must
# not be changed

set(PLUGIN_NAME "firebase_core_linux_plugin")
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)


add_library(${PLUGIN_NAME} STATIC
  "firebase_core_linux_plugin.cc"
  "firebase_core_common.cc"
  "lib/libfirebase_app.a"
)

apply_standard_settings(${PLUGIN_NAME})

set_target_properties(${PLUGIN_NAME} PROPERTIES
  CXX_VISIBILITY_PRESET hidden)
target_compile_definitions(${PLUGIN_NAME} PRIVATE FLUTTER_PLUGIN_IMPL)

target_include_directories(${PLUGIN_NAME} PUBLIC
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
target_link_libraries(${PLUGIN_NAME} PRIVATE flutter)
target_link_libraries(${PLUGIN_NAME} PRIVATE PkgConfig::GTK)
# target_link_libraries(${PLUGIN_NAME} PRIVATE firebase_app)

# List of absolute paths to libraries that should be bundled with the plugin
set(firebase_core_linux_bundled_libraries
  ""
  PARENT_SCOPE

)
