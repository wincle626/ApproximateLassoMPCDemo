#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::QuickDialogs2QuickImpl" for configuration "Release"
set_property(TARGET Qt6::QuickDialogs2QuickImpl APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Qt6::QuickDialogs2QuickImpl PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "Qt6::QuickTemplates2;Qt6::QuickDialogs2Utils;Qt6::Qml"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libQt6QuickDialogs2QuickImpl.so.6.4.0"
  IMPORTED_SONAME_RELEASE "libQt6QuickDialogs2QuickImpl.so.6"
  )

list(APPEND _IMPORT_CHECK_TARGETS Qt6::QuickDialogs2QuickImpl )
list(APPEND _IMPORT_CHECK_FILES_FOR_Qt6::QuickDialogs2QuickImpl "${_IMPORT_PREFIX}/lib/libQt6QuickDialogs2QuickImpl.so.6.4.0" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
