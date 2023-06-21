#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::BundledResonanceAudio" for configuration "Release"
set_property(TARGET Qt6::BundledResonanceAudio APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Qt6::BundledResonanceAudio PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C;CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libQt6BundledResonanceAudio.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS Qt6::BundledResonanceAudio )
list(APPEND _IMPORT_CHECK_FILES_FOR_Qt6::BundledResonanceAudio "${_IMPORT_PREFIX}/lib/libQt6BundledResonanceAudio.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
