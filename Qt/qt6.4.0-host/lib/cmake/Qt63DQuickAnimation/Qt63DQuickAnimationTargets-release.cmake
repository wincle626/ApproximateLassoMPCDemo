#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::3DQuickAnimation" for configuration "Release"
set_property(TARGET Qt6::3DQuickAnimation APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Qt6::3DQuickAnimation PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libQt63DQuickAnimation.so.6.4.0"
  IMPORTED_SONAME_RELEASE "libQt63DQuickAnimation.so.6"
  )

list(APPEND _IMPORT_CHECK_TARGETS Qt6::3DQuickAnimation )
list(APPEND _IMPORT_CHECK_FILES_FOR_Qt6::3DQuickAnimation "${_IMPORT_PREFIX}/lib/libQt63DQuickAnimation.so.6.4.0" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)