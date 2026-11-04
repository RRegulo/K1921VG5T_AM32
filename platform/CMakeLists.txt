set(VG5TSDK_DIR ${CMAKE_CURRENT_LIST_DIR})

add_library(vg5tsdk INTERFACE)

# Expose linker script directory so projects can reference k1921vg5t_flash.ld by name
target_link_options(vg5tsdk INTERFACE
    -L ${VG5TSDK_DIR}/Device/K1921VG5T/ldscripts
)

target_include_directories(vg5tsdk
    INTERFACE
        ${VG5TSDK_DIR}/Device/K1921VG5T/include
        ${VG5TSDK_DIR}/plib5t/inc
)

target_sources(vg5tsdk
    INTERFACE
        # Device startup & system init
        ${VG5TSDK_DIR}/Device/K1921VG5T/source/startup_k1921vg5t.S
        ${VG5TSDK_DIR}/Device/K1921VG5T/source/system_k1921vg5t.c
        ${VG5TSDK_DIR}/Device/K1921VG5T/source/plic.c
        ${VG5TSDK_DIR}/Device/K1921VG5T/source/riscv-irq.c
        ${VG5TSDK_DIR}/Device/K1921VG5T/source/sys_init.c
        ${VG5TSDK_DIR}/Device/K1921VG5T/source/mtimer.c
        ${VG5TSDK_DIR}/plib5t/src/plib5t_wdt.c

        # Peripheral library sources
        ${VG5TSDK_DIR}/plib5t/src/plib5t_adc.c
        ${VG5TSDK_DIR}/plib5t/src/plib5t_gpio.c
        ${VG5TSDK_DIR}/plib5t/src/plib5t_rcu.c

        # Peripheral library headers (for IDE source navigation)
        ${VG5TSDK_DIR}/plib5t/inc/plib5t.h
        ${VG5TSDK_DIR}/plib5t/inc/plib5t_adc.h
        ${VG5TSDK_DIR}/plib5t/inc/plib5t_assert.h
        ${VG5TSDK_DIR}/plib5t/inc/plib5t_conf.h
        ${VG5TSDK_DIR}/plib5t/inc/plib5t_gpio.h
        ${VG5TSDK_DIR}/plib5t/inc/plib5t_pwm.h
        ${VG5TSDK_DIR}/plib5t/inc/plib5t_rcu.h
        ${VG5TSDK_DIR}/plib5t/inc/plib5t_tmr.h
        ${VG5TSDK_DIR}/plib5t/inc/plib5t_version.h

        # Device headers
        ${VG5TSDK_DIR}/Device/K1921VG5T/include/K1921VG5T.h
        ${VG5TSDK_DIR}/Device/K1921VG5T/include/system_k1921vg5t.h
        ${VG5TSDK_DIR}/Device/K1921VG5T/include/plic.h
        ${VG5TSDK_DIR}/Device/K1921VG5T/include/riscv-irq.h
        ${VG5TSDK_DIR}/Device/K1921VG5T/include/riscv-csr.h
        ${VG5TSDK_DIR}/Device/K1921VG5T/include/arch.h
        ${VG5TSDK_DIR}/Device/K1921VG5T/include/csr.h
        ${VG5TSDK_DIR}/Device/K1921VG5T/include/memasm.h
        ${VG5TSDK_DIR}/Device/K1921VG5T/include/plf.h
        ${VG5TSDK_DIR}/Device/K1921VG5T/include/stdio.h
        ${VG5TSDK_DIR}/Device/K1921VG5T/include/stringify.h
)
