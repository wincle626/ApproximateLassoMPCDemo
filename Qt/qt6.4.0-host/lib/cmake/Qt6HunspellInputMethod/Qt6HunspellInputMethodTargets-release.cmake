#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::HunspellInputMethod" for configuration "Release"
set_property(TARGET Qt6::HunspellInputMethod APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Qt6::HunspellInputMethod PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "Qt6::Core;Qt6::Gui;Qt6::Qml"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libQt6HunspellInputMethod.so.6.4.0"
  IMPORTED_SONAME_RELEASE "libQt6HunspellInputMethod.so.6"
  )

list(APPEND _IMPORT_CHECK_TARGETS Qt6::HunspellInputMethod )
list(APPEND _IMPORT_CHECK_FILES_FOR_Qt6::HunspellInputMethod "${_IMPORT_PREFIX}/lib/libQt6HunspellInputMethod.so.6.4.0" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
