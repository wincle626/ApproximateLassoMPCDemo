#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::WebSockets" for configuration "Release"
set_property(TARGET Qt6::WebSockets APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Qt6::WebSockets PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libQt6WebSockets.so.6.4.0"
  IMPORTED_SONAME_RELEASE "libQt6WebSockets.so.6"
  )

list(APPEND _IMPORT_CHECK_TARGETS Qt6::WebSockets )
list(APPEND _IMPORT_CHECK_FILES_FOR_Qt6::WebSockets "${_IMPORT_PREFIX}/lib/libQt6WebSockets.so.6.4.0" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
