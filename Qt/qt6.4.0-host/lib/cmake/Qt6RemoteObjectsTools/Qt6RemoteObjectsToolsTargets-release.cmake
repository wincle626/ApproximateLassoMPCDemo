#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::repc" for configuration "Release"
set_property(TARGET Qt6::repc APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Qt6::repc PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/./libexec/repc"
  )

list(APPEND _IMPORT_CHECK_TARGETS Qt6::repc )
list(APPEND _IMPORT_CHECK_FILES_FOR_Qt6::repc "${_IMPORT_PREFIX}/./libexec/repc" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
