#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::quick3dlogicplugin" for configuration "Release"
set_property(TARGET Qt6::quick3dlogicplugin APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Qt6::quick3dlogicplugin PROPERTIES
  IMPORTED_COMMON_LANGUAGE_RUNTIME_RELEASE ""
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/./qml/Qt3D/Logic/libquick3dlogicplugin.so"
  IMPORTED_NO_SONAME_RELEASE "TRUE"
  )

list(APPEND _IMPORT_CHECK_TARGETS Qt6::quick3dlogicplugin )
list(APPEND _IMPORT_CHECK_FILES_FOR_Qt6::quick3dlogicplugin "${_IMPORT_PREFIX}/./qml/Qt3D/Logic/libquick3dlogicplugin.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
