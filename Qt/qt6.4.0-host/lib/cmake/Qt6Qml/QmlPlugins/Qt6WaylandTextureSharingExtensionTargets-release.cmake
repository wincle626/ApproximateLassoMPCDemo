#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::WaylandTextureSharingExtension" for configuration "Release"
set_property(TARGET Qt6::WaylandTextureSharingExtension APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Qt6::WaylandTextureSharingExtension PROPERTIES
  IMPORTED_COMMON_LANGUAGE_RUNTIME_RELEASE ""
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/./qml/QtWayland/Compositor/TextureSharingExtension/libwaylandtexturesharingextensionplugin.so"
  IMPORTED_NO_SONAME_RELEASE "TRUE"
  )

list(APPEND _IMPORT_CHECK_TARGETS Qt6::WaylandTextureSharingExtension )
list(APPEND _IMPORT_CHECK_FILES_FOR_Qt6::WaylandTextureSharingExtension "${_IMPORT_PREFIX}/./qml/QtWayland/Compositor/TextureSharingExtension/libwaylandtexturesharingextensionplugin.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
