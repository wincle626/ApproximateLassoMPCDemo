#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::QmlDebugPrivate" for configuration "Release"
set_property(TARGET Qt6::QmlDebugPrivate APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Qt6::QmlDebugPrivate PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libQt6QmlDebug.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS Qt6::QmlDebugPrivate )
list(APPEND _IMPORT_CHECK_FILES_FOR_Qt6::QmlDebugPrivate "${_IMPORT_PREFIX}/lib/libQt6QmlDebug.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
