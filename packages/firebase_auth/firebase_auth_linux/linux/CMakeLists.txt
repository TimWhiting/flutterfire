cmake_minimum_required(VERSION 3.10)
set(PROJECT_NAME "firebase_auth_linux")
project(${PROJECT_NAME} LANGUAGES CXX)

# This value is used when generating builds using this plugin, so it must
# not be changed
set(PLUGIN_NAME "firebase_auth_linux_plugin")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GLIBCXX_USE_CXX11_ABI=0")
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)

add_library(${PLUGIN_NAME} SHARED
  "firebase_auth_common.cc"
  "firebase_auth_linux_plugin.cc"
)
apply_standard_settings(${PLUGIN_NAME})
set_target_properties(${PLUGIN_NAME} PROPERTIES
  CXX_VISIBILITY_PRESET hidden)

target_compile_definitions(${PLUGIN_NAME} PRIVATE FLUTTER_PLUGIN_IMPL)
target_include_directories(${PLUGIN_NAME} INTERFACE
  "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(${PLUGIN_NAME} PRIVATE flutter)
target_link_libraries(${PLUGIN_NAME} PRIVATE PkgConfig::GTK)
target_link_libraries(${PLUGIN_NAME} PRIVATE firebase_auth)
target_link_libraries(${PLUGIN_NAME} PRIVATE firebase_app)
target_link_libraries(${PLUGIN_NAME} PRIVATE firebase_core_linux)
target_link_libraries(${PLUGIN_NAME} PRIVATE flatbuffers)

# List of absolute paths to libraries that should be bundled with the plugin
set(firebase_auth_linux_bundled_libraries
  ""
  PARENT_SCOPE
)
