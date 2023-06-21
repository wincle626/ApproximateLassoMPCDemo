#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::qscxmlc" for configuration "Release"
set_property(TARGET Qt6::qscxmlc APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Qt6::qscxmlc PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/./libexec/qscxmlc"
  )

list(APPEND _IMPORT_CHECK_TARGETS Qt6::qscxmlc )
list(APPEND _IMPORT_CHECK_FILES_FOR_Qt6::qscxmlc "${_IMPORT_PREFIX}/./libexec/qscxmlc" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
