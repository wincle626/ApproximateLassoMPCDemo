#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::BundledPhysX" for configuration "Release"
set_property(TARGET Qt6::BundledPhysX APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Qt6::BundledPhysX PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libQt6BundledPhysX.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS Qt6::BundledPhysX )
list(APPEND _IMPORT_CHECK_FILES_FOR_Qt6::BundledPhysX "${_IMPORT_PREFIX}/lib/libQt6BundledPhysX.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
