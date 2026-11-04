set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR riscv32)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

if(CMAKE_HOST_WIN32)
    if(RISCV_GCC AND NOT RISCV_GCC MATCHES "\\.exe$")
        unset(RISCV_GCC CACHE)
    endif()
    find_program(RISCV_GCC NAMES riscv-none-elf-gcc.exe
        HINTS "${CMAKE_CURRENT_LIST_DIR}/../xpacks/@xpack-dev-tools/riscv-none-elf-gcc/.content/bin"
        REQUIRED)
else()
    find_program(RISCV_GCC riscv-none-elf-gcc
        HINTS "${CMAKE_CURRENT_LIST_DIR}/../xpacks/@xpack-dev-tools/riscv-none-elf-gcc/.content/bin"
        REQUIRED)
endif()
get_filename_component(RISCV_BIN_DIR "${RISCV_GCC}" DIRECTORY)
get_filename_component(RISCV_TOOLCHAIN_DIR "${RISCV_BIN_DIR}" DIRECTORY)

set(CMAKE_C_COMPILER "${RISCV_GCC}")
set(CMAKE_ASM_COMPILER "${RISCV_GCC}")
set(CMAKE_OBJCOPY "${RISCV_BIN_DIR}/riscv-none-elf-objcopy")
set(CMAKE_SIZE "${RISCV_BIN_DIR}/riscv-none-elf-size")

set(CMAKE_C_FLAGS_INIT "-march=rv32imafc_zicsr_zifencei -mabi=ilp32f -ffunction-sections -fdata-sections -fno-common")
set(CMAKE_ASM_FLAGS_INIT "-march=rv32imafc_zicsr_zifencei -mabi=ilp32f")
