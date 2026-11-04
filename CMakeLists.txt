cmake_minimum_required(VERSION 3.21)

if(CMAKE_HOST_WIN32 AND CMAKE_GENERATOR STREQUAL "Ninja")
    find_program(NINJA_EXECUTABLE NAMES ninja.exe
        HINTS "${CMAKE_CURRENT_SOURCE_DIR}/xpacks/@xpack-dev-tools/ninja-build/.content/bin"
        REQUIRED)
    set(CMAKE_MAKE_PROGRAM "${NINJA_EXECUTABLE}" CACHE FILEPATH "Ninja executable" FORCE)
endif()

project(K1921VG5T_AM32 VERSION 2.4 LANGUAGES C ASM)

option(USE_BOOTLOADER "Place the application after a 4 KiB bootloader" OFF)
option(VG5T_DEBUG_NO_RESET "Disable watchdog and signal-loss system reset for debugger bring-up" OFF)

add_subdirectory(platform)

add_executable(K1921VG5T_AM32
    Src/main.c
    Src/functions.c
    Src/sounds.c
    Src/signal.c
    Src/IO.c
    Src/peripherals.c
    Src/phaseouts.c
    Src/comparator.c
    Src/ADC.c
    Src/K19xxVG5T_it.c
    Src/irq_entry_nofp.S
    Src/settings.c
)

target_include_directories(K1921VG5T_AM32 PRIVATE Inc)
target_link_libraries(K1921VG5T_AM32 PRIVATE vg5tsdk m nosys)
target_compile_definitions(K1921VG5T_AM32 PRIVATE
    MCU_K19XXVG5T HSECLK_VAL=16000000 SYSCLK_PLL CKO_NONE
    MTIME_FREQ_HZ=96000000ULL
    FIRMWARE_VERSION_MAJOR=${PROJECT_VERSION_MAJOR}
    FIRMWARE_VERSION_MINOR=${PROJECT_VERSION_MINOR})
if(VG5T_DEBUG_NO_RESET)
    target_compile_definitions(K1921VG5T_AM32 PRIVATE VG5T_DEBUG_NO_RESET=1)
endif()
target_compile_options(K1921VG5T_AM32 PRIVATE -Os -Wall -Wextra -ffunction-sections -fdata-sections)
target_link_options(K1921VG5T_AM32 PRIVATE
    -nostartfiles
    -Wl,--gc-sections
    -Wl,--print-memory-usage
    -Wl,-Map=${CMAKE_CURRENT_BINARY_DIR}/K1921VG5T_AM32.map
)

if(USE_BOOTLOADER)
    target_compile_definitions(K1921VG5T_AM32 PRIVATE USE_BOOTLOADER=1)
    set(APP_LINKER_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/ldscripts/vg5t_bootloader.ld)
else()
    set(APP_LINKER_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/ldscripts/vg5t_standalone.ld)
endif()

target_link_options(K1921VG5T_AM32 PRIVATE -L${CMAKE_CURRENT_SOURCE_DIR}/ldscripts -T${APP_LINKER_SCRIPT})
set_property(TARGET K1921VG5T_AM32 APPEND PROPERTY LINK_DEPENDS
    ${APP_LINKER_SCRIPT}
    ${CMAKE_CURRENT_SOURCE_DIR}/ldscripts/vg5t_common.ld
    ${CMAKE_CURRENT_SOURCE_DIR}/ldscripts/vg5t_sections.ld)

add_custom_command(TARGET K1921VG5T_AM32 POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:K1921VG5T_AM32> K1921VG5T_AM32.bin
    COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:K1921VG5T_AM32> K1921VG5T_AM32.hex
)
