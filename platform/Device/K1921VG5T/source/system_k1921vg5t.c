/*==============================================================================
 * Инициализация K1921VG5T
 *------------------------------------------------------------------------------
 * НИИЭТ, Александр Дыхно <dykhno@niiet.ru>
 *==============================================================================
 * ДАННОЕ ПРОГРАММНОЕ ОБЕСПЕЧЕНИЕ ПРЕДОСТАВЛЯЕТСЯ «КАК ЕСТЬ», БЕЗ КАКИХ-ЛИБО
 * ГАРАНТИЙ, ЯВНО ВЫРАЖЕННЫХ ИЛИ ПОДРАЗУМЕВАЕМЫХ, ВКЛЮЧАЯ ГАРАНТИИ ТОВАРНОЙ
 * ПРИГОДНОСТИ, СООТВЕТСТВИЯ ПО ЕГО КОНКРЕТНОМУ НАЗНАЧЕНИЮ И ОТСУТСТВИЯ
 * НАРУШЕНИЙ, НО НЕ ОГРАНИЧИВАЯСЬ ИМИ. ДАННОЕ ПРОГРАММНОЕ ОБЕСПЕЧЕНИЕ
 * ПРЕДНАЗНАЧЕНО ДЛЯ ОЗНАКОМИТЕЛЬНЫХ ЦЕЛЕЙ И НАПРАВЛЕНО ТОЛЬКО НА
 * ПРЕДОСТАВЛЕНИЕ ДОПОЛНИТЕЛЬНОЙ ИНФОРМАЦИИ О ПРОДУКТЕ, С ЦЕЛЬЮ СОХРАНИТЬ ВРЕМЯ
 * ПОТРЕБИТЕЛЮ. НИ В КАКОМ СЛУЧАЕ АВТОРЫ ИЛИ ПРАВООБЛАДАТЕЛИ НЕ НЕСУТ
 * ОТВЕТСТВЕННОСТИ ПО КАКИМ-ЛИБО ИСКАМ, ЗА ПРЯМОЙ ИЛИ КОСВЕННЫЙ УЩЕРБ, ИЛИ
 * ПО ИНЫМ ТРЕБОВАНИЯМ, ВОЗНИКШИМ ИЗ-ЗА ИСПОЛЬЗОВАНИЯ ПРОГРАММНОГО ОБЕСПЕЧЕНИЯ
 * ИЛИ ИНЫХ ДЕЙСТВИЙ С ПРОГРАММНЫМ ОБЕСПЕЧЕНИЕМ.
 *
 *                              2025 АО "НИИЭТ"
 *==============================================================================
 */

//-- Includes ------------------------------------------------------------------
#include "system_k1921vg5t.h"
#include "plic.h"
#include "K1921VG5T.h"

//-- Variables -----------------------------------------------------------------
uint32_t SystemCoreClock; // System Clock Frequency (Core Clock)
uint32_t SystemPllClock; // System PLL0Clock Frequency

//-- Functions -----------------------------------------------------------------
void SystemCoreClockUpdate(void)
{
    uint32_t current_sysclk;
    //uint32_t pll_fvco;
    //uint32_t pll_prediv;
    uint32_t pll_refclk, pll_pda, pll_pdb, pll_rdiv, pll_ndiv;
    current_sysclk = RCU->CLKSTAT_bit.SRC;
    if(RCU->PLLCFG_bit.CLKSEL) pll_refclk = EXTCLK_VAL;
    else pll_refclk = HSECLK_VAL;
   	//pll_prediv = RCU->PLLDIV_bit.PREDIV;
   	pll_rdiv = RCU->PLLDIV_bit.RDIV + 1;
    pll_ndiv = RCU->PLLDIV_bit.NDIV;
   	pll_pda = RCU->PLLDIV_bit.DIV1A + 1;
   	pll_pdb = RCU->PLLDIV_bit.DIV1B + 1;
   	//pll_fvco = pll_refclk*pll_ndiv*pll_prediv/pll_rdiv;
   	SystemPllClock = pll_refclk*pll_ndiv/(pll_rdiv*pll_pda*pll_pdb);
    switch (current_sysclk) {
    case RCU_CLKSTAT_SRC_HSICLK:
        SystemCoreClock = HSICLK_VAL;
        break;
    case RCU_CLKSTAT_SRC_HSECLK:
        SystemCoreClock = HSECLK_VAL;
        break;
    case RCU_CLKSTAT_SRC_PLLCLK:
    	SystemCoreClock = SystemPllClock;
    	break;
    case RCU_CLKSTAT_SRC_EXTCLK:
    	SystemCoreClock = EXTCLK_VAL;
        break;
    }

}

void ClkInit()
{
    uint32_t timeout_counter = 0;
    uint32_t sysclk_source;

    //clockout control
    #ifndef CKO_NONE
		//A0 clockout
		RCU->CGCFGAHB_bit.GPIOAEN = 1;
		RCU->RSTDISAHB_bit.GPIOAEN = 1;
		GPIOA->ALTFUNCNUM_bit.PIN0 = 2;
		GPIOA->ALTFUNCSET_bit.PIN0 = 1;
    #endif

#if defined CKO_HSI
    RCU->CLKOUTCFG = (RCU_CLKOUTCFG_CLKSEL_HSICLK << RCU_CLKOUTCFG_CLKSEL_Pos) |
    				  (1 << RCU_CLKOUTCFG_DIVN_Pos) |
					  (0 << RCU_CLKOUTCFG_DIVEN_Pos) |
					  RCU_CLKOUTCFG_CLKEN_Msk; //CKO = HSICLK
#elif defined CKO_HSE
    RCU->CLKOUTCFG = (RCU_CLKOUTCFG_CLKSEL_HSECLK << RCU_CLKOUTCFG_CLKSEL_Pos) |
			  (1 << RCU_CLKOUTCFG_DIVN_Pos) |
			  (0 << RCU_CLKOUTCFG_DIVEN_Pos) |
			  RCU_CLKOUTCFG_CLKEN_Msk; //CKO = HSECLK
#elif defined CKO_PLL0
    RCU->CLKOUTCFG = (RCU_CLKOUTCFG_CLKSEL_PLL0CLK << RCU_CLKOUTCFG_CLKSEL_Pos) |
			  	  	  (1 << RCU_CLKOUTCFG_DIVN_Pos) |
					  (1 << RCU_CLKOUTCFG_DIVEN_Pos) |
					  RCU_CLKOUTCFG_RSTDIS_Msk | RCU_CLKOUTCFG_CLKEN_Msk; //CKO = PLL0CLK
#elif defined CKO_RTC
    RCU->CLKOUTCFG = (RCU_CLKOUTCFG_CLKSEL_RTCCLK << RCU_CLKOUTCFG_CLKSEL_Pos) |
			  	  	  (1 << RCU_CLKOUTCFG_DIVN_Pos) |
					  (0 << RCU_CLKOUTCFG_DIVEN_Pos) |
					  RCU_CLKOUTCFG_RSTDIS_Msk | RCU_CLKOUTCFG_CLKEN_Msk; //CKO = RTCCLK
#endif

//select system clock
#ifdef SYSCLK_PLL
	//PLLCLK = REFCLK * (FBDIV+FRAC/2^24) / (REFDIV*(1+PD0A)*(1+PD0B))
	
	//select HSE as source system clock while config PLL
	RCU->SYSCLKCFG = (RCU_SYSCLKCFG_SRC_HSECLK << RCU_SYSCLKCFG_SRC_Pos);
    // Wait switching done
    timeout_counter = 0;
    while ((RCU->CLKSTAT_bit.SRC != RCU->SYSCLKCFG_bit.SRC) && (timeout_counter < 100)){ //SYSCLK_SWITCH_TIMEOUT))
        timeout_counter++;
    }  						  
#if (HSECLK_VAL == 10000000)
    //FOUT = 120 000 000 Hz  from 10 MHz HSE
    // RCU->PLLDIV is equivalent for RCU->PLL[0].DIV
    RCU->PLLDIV = ( 1 << RCU_PLLDIV_DIV1A_Pos ) |
                  ( 1 << RCU_PLLDIV_DIV1B_Pos ) |
                  ( 1 << RCU_PLLDIV_PREDIV_Pos) |
                  ( 1 << RCU_PLLDIV_NNCLR_Pos ) |             // N-divider enable
                  ( 1 << RCU_PLLDIV_RNCLR_Pos ) |             // R-divider enable
                  ( 1 << RCU_PLLDIV_RDIV_Pos  ) |
                  (80 << RCU_PLLDIV_NDIV_Pos );
	RCU->PLLMOD  = (1 << RCU_PLLFRAC_FRAC_Pos );
	RCU->PLLFRAC = (1 << RCU_PLLMOD_MOD_Pos   );
	RCU->PLLCFG  = (1 << RCU_PLLCFG_FOUTEN_Pos ) |			// Fout enable
			       (3 << RCU_PLLCFG_PFD_Pos    ) |
			       (0 << RCU_PLLCFG_CLKSEL_Pos ) |
			       (1 << RCU_PLLCFG_VCOMODE_Pos) |
			       (0 << RCU_PLLCFG_ST_Pos) ;				  // ST = 0 for integer divider
#elif (HSECLK_VAL == 12000000)
    //FOUT = 120 000 000 Hz  from 12 MHz HSE
    // RCU->PLLDIV is equivalent for RCU->PLL[0].DIV
    RCU->PLLDIV = ( 2 << RCU_PLLDIV_DIV1A_Pos ) |
                  ( 1 << RCU_PLLDIV_DIV1B_Pos ) |             // DIV1B + 1
                  ( 1 << RCU_PLLDIV_PREDIV_Pos) |
                  ( 1 << RCU_PLLDIV_NNCLR_Pos ) |             // N-divider enable
                  ( 1 << RCU_PLLDIV_RNCLR_Pos ) |             // R-divider enable
                  ( 1 << RCU_PLLDIV_RDIV_Pos  ) |
                  (100 << RCU_PLLDIV_NDIV_Pos );
	RCU->PLLMOD  = (1 << RCU_PLLFRAC_FRAC_Pos );
	RCU->PLLFRAC = (1 << RCU_PLLMOD_MOD_Pos   );
	RCU->PLLCFG  = (1 << RCU_PLLCFG_FOUTEN_Pos ) |			// Fout enable
			       (3 << RCU_PLLCFG_PFD_Pos    ) |
			       (0 << RCU_PLLCFG_CLKSEL_Pos ) |
			       (1 << RCU_PLLCFG_VCOMODE_Pos) |
			       (0 << RCU_PLLCFG_ST_Pos) ;				  // ST = 0 for integer divider
#elif (HSECLK_VAL == 16000000)
    //FOUT = 96 000 000 Hz  from 16 MHz HSE
    // RCU->PLLDIV is equivalent for RCU->PLL[0].DIV
    RCU->PLLDIV = ( 3 << RCU_PLLDIV_DIV1A_Pos ) |
                  ( 1 << RCU_PLLDIV_DIV1B_Pos ) |
                  ( 1 << RCU_PLLDIV_PREDIV_Pos) |
                  ( 1 << RCU_PLLDIV_NNCLR_Pos ) |             // N-divider enable
                  ( 1 << RCU_PLLDIV_RNCLR_Pos ) |             // R-divider enable
                  ( 1 << RCU_PLLDIV_RDIV_Pos  ) |
                  (96 << RCU_PLLDIV_NDIV_Pos );
	RCU->PLLMOD  = (1 << RCU_PLLFRAC_FRAC_Pos );
	RCU->PLLFRAC = (1 << RCU_PLLMOD_MOD_Pos   );
	RCU->PLLCFG  = (1 << RCU_PLLCFG_FOUTEN_Pos ) |			// Fout enable
			       (3 << RCU_PLLCFG_PFD_Pos    ) |
			       (0 << RCU_PLLCFG_CLKSEL_Pos ) |
			       (1 << RCU_PLLCFG_VCOMODE_Pos) |
			       (0 << RCU_PLLCFG_ST_Pos) ;				  // ST = 0 for integer divider

#elif (HSECLK_VAL == 20000000)
    //FOUT = 120 000 000 Hz  from 20 MHz HSE
    // RCU->PLLDIV is equivalent for RCU->PLL[0].DIV
    RCU->PLLDIV = ( 1 << RCU_PLLDIV_DIV1A_Pos ) |
                  ( 1 << RCU_PLLDIV_DIV1B_Pos ) |
                  ( 1 << RCU_PLLDIV_PREDIV_Pos) |
                  ( 1 << RCU_PLLDIV_NNCLR_Pos ) |             // N-divider enable
                  ( 1 << RCU_PLLDIV_RNCLR_Pos ) |             // R-divider enable
                  ( 4 << RCU_PLLDIV_RDIV_Pos  ) |
                  (100 << RCU_PLLDIV_NDIV_Pos );
	RCU->PLLMOD  = (1 << RCU_PLLFRAC_FRAC_Pos );
	RCU->PLLFRAC = (1 << RCU_PLLMOD_MOD_Pos   );
	RCU->PLLCFG  = (1 << RCU_PLLCFG_FOUTEN_Pos ) |			// Fout enable
			       (3 << RCU_PLLCFG_PFD_Pos    ) |
			       (0 << RCU_PLLCFG_CLKSEL_Pos ) |
			       (1 << RCU_PLLCFG_VCOMODE_Pos) |
			       (0 << RCU_PLLCFG_ST_Pos) ;				  // ST = 0 for integer divider
#elif (HSECLK_VAL == 24000000)
    //FOUT = 120 000 000 Hz  from 24 MHz HSE
    // RCU->PLLDIV is equivalent for RCU->PLL[0].DIV
    RCU->PLLDIV = ( 1 << RCU_PLLDIV_DIV1A_Pos ) |
                  ( 1 << RCU_PLLDIV_DIV1B_Pos ) |
                  ( 1 << RCU_PLLDIV_PREDIV_Pos) |
                  ( 1 << RCU_PLLDIV_NNCLR_Pos ) |             // N-divider enable
                  ( 1 << RCU_PLLDIV_RNCLR_Pos ) |             // R-divider enable
                  ( 5 << RCU_PLLDIV_RDIV_Pos  ) |
                  (100 << RCU_PLLDIV_NDIV_Pos );
	RCU->PLLMOD  = (1 << RCU_PLLFRAC_FRAC_Pos );
	RCU->PLLFRAC = (1 << RCU_PLLMOD_MOD_Pos   );
	RCU->PLLCFG  = (1 << RCU_PLLCFG_FOUTEN_Pos ) |			// Fout enable
			       (3 << RCU_PLLCFG_PFD_Pos    ) |
			       (0 << RCU_PLLCFG_CLKSEL_Pos ) |
			       (1 << RCU_PLLCFG_VCOMODE_Pos) |
			       (0 << RCU_PLLCFG_ST_Pos) ;				  // ST = 0 for integer divider
#else
#error "Please define HSECLK_VAL with correct values!"
#endif
	//select PLL as source system clock
	sysclk_source = RCU_SYSCLKCFG_SRC_PLLCLK;
    // FLASH control settings.
    // The stock NIIET code only writes LAT and leaves the fetch buffer off.
    // The working K1921VG7T bare-metal reference (same SCR4 core) flushes the
    // fetch buffer, sets latency = ceil(fclk / 35 MHz) and *enables* prefetch
    // (FBEN). At 96 MHz latency = 2, matching the previous hard-coded value.
    FLASH->CTRL_bit.CFLUSH = 1;
    (void)FLASH->CTRL;
    FLASH->CTRL = (2u << FLASH_CTRL_LAT_Pos) | FLASH_CTRL_FBEN_Msk;
    // enable/init caches
    //cache_enable(1,0); // Cash enable for Flash
#elif defined SYSCLK_HSI
    sysclk_source = RCU_SYSCLKCFG_SRC_HSICLK;
#elif defined SYSCLK_HSE
    sysclk_source = RCU_SYSCLKCFG_SRC_HSECLK;
#elif defined SYSCLK_LSI
    sysclk_source = RCU_SYSCLKCFG_SRC_LSICLK;
#else
#error "Please define SYSCLK source (SYSCLK_PLL | SYSCLK_HSE | SYSCLK_HSI | SYSCLK_EXT)!"
#endif

    //switch sysclk
    RCU->SYSCLKCFG = (sysclk_source << RCU_SYSCLKCFG_SRC_Pos);
    // Wait switching done
    timeout_counter = 0;
    while ((RCU->CLKSTAT_bit.SRC != RCU->SYSCLKCFG_bit.SRC) && (timeout_counter < 100)) //SYSCLK_SWITCH_TIMEOUT))
        timeout_counter++;
/*    if (timeout_counter == SYSCLK_SWITCH_TIMEOUT) //SYSCLK failed to switch
        while (1) {
        };*/

}

void InterruptEnable()
{
	//allow all interrupts in machine mode
	PLIC_SetThreshold (Plic_Mach_Target, 0); //allow all interrupts in machine mode
    // disable timer interrupt
    clear_csr(mie, MIE_MTIMER);
    // enable machine external interrupt
    set_csr(mie, MIE_MEXTERNAL);
    // enable global interrupts
    set_csr(mstatus, MSTATUS_MIE);
}

void InterruptDisable()
{
	//disable all interrupts in machine mode
	PLIC_SetThreshold (Plic_Mach_Target, 7); //Disable all interrupts in machine mode
    // disable machine external interrupt
    clear_csr(mie, MIE_MEXTERNAL);
    // disable global interrupts
    clear_csr(mstatus, MSTATUS_MIE);
}

void SystemInit(void)
{
	// PLIC configuration
	// disable timer interrupt
//	clear_csr(mie, MIE_MTIMER);
	// enable machine external interrupt
//	set_csr(mie, MIE_MEXTERNAL);
	// enable global interrupts
//	set_csr(mstatus, MSTATUS_MIE);
	ClkInit();
}

