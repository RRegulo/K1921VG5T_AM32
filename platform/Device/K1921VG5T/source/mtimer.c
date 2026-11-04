#include "mtimer.h"
#include "arch.h"
#include "csr.h"

#define MPU_SEL_CSR  (SCR_CSR_MPU_BASE + 0)
#define MPU_CTRL_CSR (SCR_CSR_MPU_BASE + 1)
#define MPU_ADDR_CSR (SCR_CSR_MPU_BASE + 2)
#define MPU_MASK_CSR (SCR_CSR_MPU_BASE + 3)
#define MPU_CTRL_VALID (1u << 0)
#define MPU_CTRL_MMR   (1u << 1)
#define MPU_CTRL_MMW   (1u << 2)
#define MPU_CTRL_MTYPE_MMIO_CFG (3u << 16)

void mtimer_mpu_init(void)
{
    write_csr(MPU_SEL_CSR, RISCV_MTIMER_MPU_ENTRY);
    write_csr(MPU_CTRL_CSR, 0);
    write_csr(MPU_ADDR_CSR, RISCV_MMCFG_BASE >> 2);
    write_csr(MPU_MASK_CSR, (~(RISCV_MMCFG_SIZE - 1u)) >> 2);
    /* M-mode R/W, no execute (execute is rejected for MTYPE=3) */
    write_csr(MPU_CTRL_CSR, MPU_CTRL_VALID | MPU_CTRL_MMR | MPU_CTRL_MMW | MPU_CTRL_MTYPE_MMIO_CFG);
    __asm__ volatile("fence.i" ::: "memory");

    volatile uint32_t *ctrl = (volatile uint32_t *)RISCV_MTIMER_CTRL_ADDR;
    volatile uint32_t *div  = (volatile uint32_t *)RISCV_MTIMER_DIV_ADDR;
    volatile uint32_t *cmph = (volatile uint32_t *)(RISCV_MTIMECMP_ADDR + 4);
    *cmph = 0xFFFFFFFFu;   /* no spurious MTI before the first compare */
    *div  = 0;             /* tick every core clock */
    *ctrl = 1;             /* ENABLE=1, CLKSRC=0 (core clock) */
}

void mtimer_set_raw_time_cmp_abs(uint64_t new_mtimecmp) {
    volatile uint32_t *mtimecmpl = (volatile uint32_t *)(RISCV_MTIMECMP_ADDR);
    volatile uint32_t *mtimecmph = (volatile uint32_t *)(RISCV_MTIMECMP_ADDR+4);
    *mtimecmph = 0xFFFFFFFF;
    *mtimecmpl = (uint32_t)(new_mtimecmp & 0x0FFFFFFFFUL);
    *mtimecmph = (uint32_t)(new_mtimecmp >> 32);
}

void mtimer_set_raw_time_cmp(uint64_t clock_offset) {
    // First of all set 
    uint64_t new_mtimecmp = mtimer_get_raw_time() + clock_offset;
    volatile uint32_t *mtimecmpl = (volatile uint32_t *)(RISCV_MTIMECMP_ADDR);
    volatile uint32_t *mtimecmph = (volatile uint32_t *)(RISCV_MTIMECMP_ADDR+4);
    // AS we are doing 32 bit writes, an intermediate mtimecmp value may cause spurious interrupts.
    // Prevent that by first setting the dummy MSB to an unacheivable value
    *mtimecmph = 0xFFFFFFFF;  // cppcheck-suppress redundantAssignment
    // set the LSB
    *mtimecmpl = (uint32_t)(new_mtimecmp & 0x0FFFFFFFFUL);
    // Set the correct MSB
    *mtimecmph = (uint32_t)(new_mtimecmp >> 32); // cppcheck-suppress redundantAssignment
}
 
/** Read the raw time of the system timer in system timer clocks
 */
uint64_t mtimer_get_raw_time(void) {

    volatile uint32_t * mtimel = (volatile uint32_t *)(RISCV_MTIME_ADDR);
    volatile uint32_t * mtimeh = (volatile uint32_t *)(RISCV_MTIME_ADDR+4);
    uint32_t mtimeh_val;
    uint32_t mtimel_val;
    do {
        // There is a small risk the mtimeh will tick over after reading mtimel
        mtimeh_val = *mtimeh;
        mtimel_val = *mtimel;
        // Poll mtimeh to ensure it's consistent after reading mtimel
        // The frequency of mtimeh ticking over is low
    } while (mtimeh_val != *mtimeh);
    return (uint64_t) ( ( ((uint64_t)mtimeh_val)<<32) | mtimel_val);
} 
