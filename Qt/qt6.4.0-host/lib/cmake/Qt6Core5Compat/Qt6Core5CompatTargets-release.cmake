#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::Core5Compat" for configuration "Release"
set_property(TARGET Qt6::Core5Compat APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Qt6::Core5Compat PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libQt6Core5Compat.so.6.4.0"
  IMPORTED_SONAME_RELEASE "libQt6Core5Compat.so.6"
  )

list(APPEND _IMPORT_CHECK_TARGETS Qt6::Core5Compat )
list(APPEND _IMPORT_CHECK_FILES_FOR_Qt6::Core5Compat "${_IMPORT_PREFIX}/lib/libQt6Core5Compat.so.6.4.0" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
