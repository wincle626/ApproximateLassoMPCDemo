# Additional target information for Qt63DExtras
if(NOT DEFINED QT_DEFAULT_IMPORT_CONFIGURATION)
    set(QT_DEFAULT_IMPORT_CONFIGURATION RELEASE)
endif()
__qt_internal_promote_target_to_global_checked(Qt6::3DExtras)
get_target_property(_qt_imported_location Qt6::3DExtras IMPORTED_LOCATION_RELEASE)
get_target_property(_qt_imported_soname Qt6::3DExtras IMPORTED_SONAME_RELEASE)
get_target_property(_qt_imported_location_default Qt6::3DExtras IMPORTED_LOCATION_${QT_DEFAULT_IMPORT_CONFIGURATION})
get_target_property(_qt_imported_soname_default Qt6::3DExtras IMPORTED_SONAME_${QT_DEFAULT_IMPORT_CONFIGURATION})

# Import target "Qt6::3DExtras" for configuration "RelWithDebInfo"
set_property(TARGET Qt6::3DExtras APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)

if(_qt_imported_location)
    set_property(TARGET Qt6::3DExtras PROPERTY IMPORTED_LOCATION_RELWITHDEBINFO "${_qt_imported_location}")
endif()
if(_qt_imported_soname)
    set_property(TARGET Qt6::3DExtras PROPERTY IMPORTED_SONAME_RELWITHDEBINFO "${_qt_imported_soname}")
endif()

# Import target "Qt6::3DExtras" for configuration "MinSizeRel"
set_property(TARGET Qt6::3DExtras APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)

if(_qt_imported_location)
    set_property(TARGET Qt6::3DExtras PROPERTY IMPORTED_LOCATION_MINSIZEREL "${_qt_imported_location}")
endif()
if(_qt_imported_soname)
    set_property(TARGET Qt6::3DExtras PROPERTY IMPORTED_SONAME_MINSIZEREL "${_qt_imported_soname}")
endif()

# Default configuration
if(_qt_imported_location_default)
    set_property(TARGET Qt6::3DExtras PROPERTY IMPORTED_LOCATION "${_qt_imported_location_default}")
endif()
if(_qt_imported_soname_default)
    set_property(TARGET Qt6::3DExtras PROPERTY IMPORTED_SONAME "${_qt_imported_soname_default}")
endif()
__qt_internal_promote_target_to_global_checked(Qt6::3DExtrasPrivate)

unset(_qt_imported_location)
unset(_qt_imported_location_default)
unset(_qt_imported_soname)
unset(_qt_imported_soname_default)
unset(_qt_imported_configs)
