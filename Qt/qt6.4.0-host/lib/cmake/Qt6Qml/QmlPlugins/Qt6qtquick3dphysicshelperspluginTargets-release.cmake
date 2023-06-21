#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::qtquick3dphysicshelpersplugin" for configuration "Release"
set_property(TARGET Qt6::qtquick3dphysicshelpersplugin APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Qt6::qtquick3dphysicshelpersplugin PROPERTIES
  IMPORTED_COMMON_LANGUAGE_RUNTIME_RELEASE ""
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/./qml/QtQuick3D/Physics/Helpers/libqtquick3dphysicshelpersplugin.so"
  IMPORTED_NO_SONAME_RELEASE "TRUE"
  )

list(APPEND _IMPORT_CHECK_TARGETS Qt6::qtquick3dphysicshelpersplugin )
list(APPEND _IMPORT_CHECK_FILES_FOR_Qt6::qtquick3dphysicshelpersplugin "${_IMPORT_PREFIX}/./qml/QtQuick3D/Physics/Helpers/libqtquick3dphysicshelpersplugin.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
