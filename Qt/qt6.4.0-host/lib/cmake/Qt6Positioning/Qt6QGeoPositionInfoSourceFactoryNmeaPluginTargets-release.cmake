#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Qt6::QGeoPositionInfoSourceFactoryNmeaPlugin" for configuration "Release"
set_property(TARGET Qt6::QGeoPositionInfoSourceFactoryNmeaPlugin APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Qt6::QGeoPositionInfoSourceFactoryNmeaPlugin PROPERTIES
  IMPORTED_COMMON_LANGUAGE_RUNTIME_RELEASE ""
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/./plugins/position/libqtposition_nmea.so"
  IMPORTED_NO_SONAME_RELEASE "TRUE"
  )

list(APPEND _IMPORT_CHECK_TARGETS Qt6::QGeoPositionInfoSourceFactoryNmeaPlugin )
list(APPEND _IMPORT_CHECK_FILES_FOR_Qt6::QGeoPositionInfoSourceFactoryNmeaPlugin "${_IMPORT_PREFIX}/./plugins/position/libqtposition_nmea.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
