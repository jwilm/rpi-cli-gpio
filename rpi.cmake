set(toolchain_dir /usr/local/toolchains/arm-unknown-linux-gnueabihf )
set(toolchain_bin_dir ${toolchain_dir}/bin)
set(toolchain_inc_dir ${toolchain_dir}/include)
set(toolchain_lib_dir ${toolchain_dir}/lib)
set(toolchain_sysroot ${toolchain_dir}/arm-unknown-linux-gnueabihf/sysroot)

set(CMAKE_CROSSCOMPILING True)
set(CROSSCOMPILING True)

set(CMAKE_SYSTEM_NAME Linux CACHE INTERNAL "system name")
set(CMAKE_SYSTEM_PROCESSOR arm CACHE INTERNAL "processor")
set(CMAKE_C_COMPILER ${toolchain_bin_dir}/arm-unknown-linux-gnueabihf-gcc)
set(CMAKE_CXX_COMPILER ${toolchain_bin_dir}/arm-unknown-linux-gnueabihf-g++)
set(CMAKE_C_FLAGS "-mfloat-abi=hard --sysroot=${toolchain_sysroot}" CACHE INTERNAL "c compiler flags")
set(CMAKE_CXX_FLAGS "-mfloat-abi=hard --sysroot=${toolchain_sysroot}" CACHE INTERNAL "cxx compiler flags")

set(link_flags "-ldl")

set(CMAKE_EXE_LINKER_FLAGS ${link_flags} CACHE INTERNAL "exe link flags")
set(CMAKE_MODULE_LINKER_FLAGS ${link_flags} CACHE INTERNAL "module link flags")
set(CMAKE_SHARED_LINKER_FLAGS ${link_flags} CACHE INTERNAL "shared link flags")
set(CMAKE_FIND_ROOT_PATH ${toolchain_lib_dir} CACHE INTERNAL "cross root directory")
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM BOTH CACHE INTERNAL "")
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY CACHE INTERNAL "")
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY CACHE INTERNAL "")