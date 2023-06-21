#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::GLTFSceneExportPlugin" for configuration "Release"
set_property(TARGET Qt6::GLTFSceneExportPlugin APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Qt6::GLTFSceneExportPlugin PROPERTIES
  IMPORTED_COMMON_LANGUAGE_RUNTIME_RELEASE ""
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/./plugins/sceneparsers/libgltfsceneexport.so"
  IMPORTED_NO_SONAME_RELEASE "TRUE"
  )

list(APPEND _IMPORT_CHECK_TARGETS Qt6::GLTFSceneExportPlugin )
list(APPEND _IMPORT_CHECK_FILES_FOR_Qt6::GLTFSceneExportPlugin "${_IMPORT_PREFIX}/./plugins/sceneparsers/libgltfsceneexport.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
