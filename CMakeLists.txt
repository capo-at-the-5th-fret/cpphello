cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    hello
    VERSION 0.1.0
    DESCRIPTION "Short description"
    HOMEPAGE_URL "https://example.com/"
    LANGUAGES NONE
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

add_library(hello_hello INTERFACE)
add_library(hello::hello ALIAS hello_hello)

set_property(
    TARGET hello_hello PROPERTY
    EXPORT_NAME hello
)

target_include_directories(
    hello_hello ${warning_guard}
    INTERFACE
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
)

target_compile_features(hello_hello INTERFACE cxx_std_23)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT hello_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of hello"
  )
endif()

include(cmake/dev-mode.cmake)
