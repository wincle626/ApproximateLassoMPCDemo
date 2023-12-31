QT_CPU_FEATURES.arm64 = cx16 neon
QT.global_private.enabled_features = reduce_exports neon posix_fallocate alloca_h alloca system-zlib dbus dbus-linked gui network printsupport sql testlib widgets xml libudev dlopen relocatable largefile precompile_header enable_new_dtags neon
QT.global_private.disabled_features = use_bfd_linker use_gold_linker use_lld_linker use_mold_linker android-style-assets gc_binaries developer-build no-prefix private_tests debug no_direct_extern_access sse2 sse3 ssse3 sse4_1 sse4_2 avx f16c avx2 avx512f avx512er avx512cd avx512pf avx512dq avx512bw avx512vl avx512ifma avx512vbmi avx512vbmi2 aesni vaes rdrnd rdseed shani mips_dsp mips_dspr2 arm_crc32 arm_crypto alloca_malloc_h stack-protector-strong stdlib-libcpp intelcet
CONFIG += largefile precompile_header enable_new_dtags neon
PKG_CONFIG_EXECUTABLE = /usr/bin/pkg-config
QT_COORD_TYPE = double
QT_BUILD_PARTS = libs tools

QMAKE_LIBS_ZLIB = -lz
QMAKE_INCDIR_DBUS = /usr/lib/aarch64-linux-gnu/dbus-1.0/include
QMAKE_LIBS_DBUS = -ldbus-1
QMAKE_LIBS_LIBUDEV = -ludev
