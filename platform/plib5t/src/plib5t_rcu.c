/**
  ******************************************************************************
  * @file    plib5t_rcu.c
  *
  * @brief   Файл содержит реализацию функций для работы с RCU
  *
  * @author  НИИЭТ, Александр Дыхно <dykhno@niiet.ru>
  *
  ******************************************************************************
  * @attention
  *
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
  * <h2><center>&copy; 2025 АО "НИИЭТ"</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "plib5t_rcu.h"

/** @addtogroup Peripheral
  * @{
  */

/** @addtogroup RCU
  * @{
  */

/** @defgroup RCU_Private Приватные данные
  * @{
  */

/** @defgroup RCU_Private_Defines Приватные константы
  * @{
  */

#define RCU_PLLSYSCFG0_RST_VAL 0x34111101 /*!< Значение по сбросу регистра PLLSYSCFG0 */

/** @defgroup RCU_TIMEOUT_DEFINE Значения для таймаутов
  * @{
  */

#define RCU_SYSCLK_CHANGE_TIMEOUT 10000 /*!< Время ожидания смены источника тактирования */
#define RCU_PLLCLK_LOCK_TIMEOUT 10000   /*!< Время ожидания стабилизации выходной частоты PLL */

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup RCU_Private_Functions Приватные функции
  * @{
  */

/**
  * @brief   Получение значения частоты генерации выбранного источника
  * @param   Clk  Выбор тактового сигнала
  * @retval  Val  Значение Гц
  */
static uint32_t getSysClkFreq(RCU_SysClk_TypeDef Clk)
{
    uint32_t clk_freq = 0;

    switch (Clk) {
    case RCU_SysClk_HsiClk:
        clk_freq = RCU_GetHSIClkFreq();
        break;
    case RCU_SysClk_HseClk:
        clk_freq = RCU_GetHSEClkFreq();
        break;
    case RCU_SysClk_PLLClk:
        clk_freq = RCU_GetPLLClkFreq();
        break;
    case RCU_SysClk_ExtClk:
        clk_freq = RCU_GetEXTClkFreq();
        break;
    }

    return clk_freq;
}

/**
  * @brief   Получение значения частоты генерации выбранного источника
  * @param   Clk  Выбор тактового сигнала
  * @retval  Val  Значение Гц
  */
static uint32_t getPeriphClkFreq(RCU_PeriphClk_TypeDef Clk)
{
    uint32_t clk_freq = 0;

    switch (Clk) {
    case RCU_PeriphClk_HsiClk:
        clk_freq = RCU_GetHSIClkFreq();
        break;
    case RCU_PeriphClk_HseClk:
        clk_freq = RCU_GetHSEClkFreq();
        break;
    case RCU_SysClk_PLLClk:
        clk_freq = RCU_GetPLLClkFreq();
        break;
    case RCU_SysClk_ExtClk:
        clk_freq = RCU_GetEXTClkFreq();
        break;
    }

    return clk_freq;
}

/**
  * @brief   Получение значения частоты генерации выбранного источника
  * @param   Clk  Выбор тактового сигнала
  * @retval  Val  Значение Гц
  */
static uint32_t getSysPeriphClkFreq(RCU_PeriphClk_TypeDef Clk)
{
    uint32_t clk_freq = 0;

    switch (Clk) {
    case RCU_PeriphClk_HsiClk:
        clk_freq = RCU_GetHSIClkFreq();
        break;
    case RCU_PeriphClk_HseClk:
        clk_freq = RCU_GetHSEClkFreq();
        break;
    case RCU_SysClk_PLLClk:
        clk_freq = RCU_GetPLLClkFreq();
        break;
    case RCU_SysClk_ExtClk:
        clk_freq = RCU_GetEXTClkFreq();
        break;
    }

    return clk_freq;
}

/**
  * @brief   Получение значения частоты тактового сигнала HSICLK
  * @retval  Val  Значение Гц
  */
uint32_t RCU_GetHSIClkFreq()
{
    return HSICLK_VAL;
}

/**
  * @brief   Получение значения частоты тактового сигнала HSECLK
  * @retval  Val  Значение Гц
  */
uint32_t RCU_GetHSEClkFreq()
{
    return HSECLK_VAL;
}

/**
  * @brief   Получение значения частоты тактового сигнала EXTCLK
  * @retval  Val  Значение Гц
  */
uint32_t RCU_GetEXTClkFreq()
{
    return (uint32_t)EXTCLK_VAL;
}

   FunctionalState FracDivEn;   /*!< Активация дробного делителя PLL*/
    uint32_t RefDiv;          /*!< Делитель опорного сигнала PLL (M).
                                   Параметр может принимать любое значение из диапазона 1-63. */
    uint32_t FbDiv;           /*!< Делитель обратной связи (N).
                                   Параметр может принимать любое значение из диапазона:
                                      16-160 (без дробного делителя),
                                      20-160 (с дробным делителем) */
    uint32_t FracDiv;         /*!< Дробный делитель.
                                   Параметр может принимать любое значение из диапазона 1-255. */                                   
    uint32_t Div0A;           /*!< Внутренний делитель PLL A канала 0 (итоговое значение (Div0A+1))
                                   Параметр может принимать любое значение из диапазона 0-7. */
    uint32_t Div0B;           /*!< Внутренний делитель PLL B канала 0 (итоговое значение (Div0BA+1))
                                   Параметр может принимать любое значение из диапазона 0-7. */
    uint32_t Div1A;           /*!< Внутренний делитель PLL A канала 1 (итоговое значение (Div1A+1))
                                   Параметр может принимать любое значение из диапазона 0-7. */
    uint32_t Div1B;           /*!< Внутренний делитель PLL B канала 1 (итоговое значение (Div1BA+1))
                                   Параметр может принимать любое значение из диапазона 0-7. */

/**
  * @brief   Получение значения частоты тактового сигнала PLLCLK
  * @retval  Val  Значение Гц
  */
uint32_t RCU_GetPLLClkFreq()
{
    uint32_t pll_div1a, pll_div1b, pll_refclk, pll_ndiv, pll_rdiv;

    pll_div1a = READ_REG(RCU->PLLDIV_bit.DIV1A)+1;
    pll_div1b = READ_REG(RCU->PLLDIV_bit.DIV1B)+1;
    pll_rdiv = READ_REG(RCU->PLLDIV_bit.RDIV) +1;
    pll_ndiv = READ_REG(RCU->PLLDIV_bit.NDIV);
    if(READ_REG(RCU->PLLCFG_bit.CLKSEL))  pll_refclk = EXTCLK_VAL;
    else pll_refclk = HSECLK_VAL;

    return (uint32_t)((pll_refclk * pll_ndiv) / (pll_rdiv * pll_div1a * pll_div1b));
}

/**
  * @brief   Получение значения частоты SYSCLK
  * @retval  Val  Значение Гц
  */
uint32_t RCU_GetSysClkFreq()
{
    RCU_SysClk_TypeDef sys_clk;

    sys_clk = RCU_SysClkStatus();

    return getSysClkFreq(sys_clk);
}

/**
  * @brief   Получение значения частоты UARTCLK
  * @param   UARTx_Num  Порядковый номер блока UART
  * @retval  Val  Значение Гц
  */
uint32_t RCU_GetUARTClkFreq(UART_Num_TypeDef UARTx_Num)
{
    RCU_PeriphClk_TypeDef uart_clk;
    uint32_t div_val;

    uart_clk = (RCU_PeriphClk_TypeDef)READ_REG(RCU->UARTCFG[UARTx_Num].UARTCFG_bit.CLKSEL);
    if (READ_REG(RCU->UARTCFG[UARTx_Num].UARTCFG_bit.DIVEN))
        div_val = 2 * (READ_REG(RCU->UARTCFG[UARTx_Num].UARTCFG_bit.DIVN) + 1);
    else
        div_val = 1;

    return getPeriphClkFreq(uart_clk) / div_val;
}

/**
  * @brief   Получение значения частоты SPICLK
  * @param   SPIx_Num  Порядковый номер блока SPI
  * @retval  Val  Значение Гц
  */
uint32_t RCU_GetSPIClkFreq(SPI_Num_TypeDef SPIx_Num)
{
    RCU_PeriphClk_TypeDef spi_clk;
    uint32_t div_val;

    spi_clk = (RCU_PeriphClk_TypeDef)READ_REG(RCU->SPICFG[SPIx_Num].SPICFG_bit.CLKSEL);
    if (READ_REG(RCU->SPICFG[SPIx_Num].SPICFG_bit.DIVEN))
        div_val = 2 * (READ_REG(RCU->SPICFG[SPIx_Num].SPICFG_bit.DIVN) + 1);
    else
        div_val = 1;

    return getPeriphClkFreq(spi_clk) / div_val;
}

/**
  * @brief   Получение значения частоты ADCCLK
  * @retval  Val  Значение Гц
  */
uint32_t RCU_GetADCClkFreq()
{
    RCU_PeriphClk_TypeDef adc_clk;
    uint32_t div_val;

    adc_clk = (RCU_PeriphClk_TypeDef)READ_REG(RCU->ADCCFG_bit.CLKSEL);
    if (READ_REG(RCU->ADCCFG_bit.DIVEN))
        div_val = 2 * (READ_REG(RCU->ADCCFG_bit.DIVN) + 1);
    else
        div_val = 1;

    return getPeriphClkFreq(adc_clk) / div_val;
}

/**
  * @brief   Получение значения частоты WDTCLK
  * @retval  Val  Значение Гц
  */
uint32_t RCU_GetWDTClkFreq()
{
    RCU_PeriphClk_TypeDef wdt_clk;
    uint32_t div_val;

    wdt_clk = (RCU_PeriphClk_TypeDef)READ_REG(RCU->WDTCFG_bit.CLKSEL);
    if (READ_REG(RCU->WDTCFG_bit.DIVEN))
        div_val = 2 * (READ_REG(RCU->WDTCFG_bit.DIVN) + 1);
    else
        div_val = 1;

    return getSysPeriphClkFreq(wdt_clk) / div_val;
}

/**
  * @brief   Получение значения частоты CLKOUT
  * @retval  Val  Значение Гц
  */
uint32_t RCU_GetClkOutFreq()
{
    RCU_PeriphClk_TypeDef clkout;
    uint32_t div_val;

    clkout = (RCU_PeriphClk_TypeDef)READ_REG(RCU->CLKOUTCFG_bit.CLKSEL);
    if (READ_REG(RCU->CLKOUTCFG_bit.DIVEN))
        div_val = 2 * (READ_REG(RCU->CLKOUTCFG_bit.DIVN) + 1);
    else
        div_val = 1;

    return getSysPeriphClkFreq(clkout) / div_val;
}

/**
  * @brief      Инициализирует PLL согласно параметрам структуры InitStruct.
  *             Значение выходной частоты PLL вычисляется по формуле:<br><br>
  *             <center>FOUT = (FREF x FBDIV) / (REFDIV x DIV1 x DIV2),</center>
  *             где FREF – опорная частота PLL.<br>
  * @attention  При расчете коэффициентов деления PLL должны выполняться следующие условия:
  *             - 8 МГц <= FREF <= 800 МГц (REF),
  *             - 400 МГц <= FIN*FBDIV/REFDIV <= 16000 МГц (VCO),
  *             - 8 МГц <= FOUT <= 1600 МГц;
  *
  * @param      InitStruct  Указатель на структуру типа @ref RCU_PLL_Init_TypeDef,
  *                         которая содержит конфигурационную информацию
  * @retval     Status
  */
OperationStatus RCU_PLL_Init(RCU_PLL_Init_TypeDef* InitStruct)
{
    uint32_t timeout = RCU_PLLCLK_LOCK_TIMEOUT;
    OperationStatus status = OK;

    assert_param(IS_FUNCTIONAL_STATE(InitStruct->DivEn));
    assert_param(IS_RCU_PLL_DIV(InitStruct->DivVal));
    assert_param(IS_RCU_PLL_FB_DIV(InitStruct->FbDiv));
    assert_param(IS_RCU_PLL_REF_DIV(InitStruct->RefDiv));
    assert_param(IS_RCU_PLL_REF(InitStruct->Ref));
    assert_param(IS_RCU_PLL_DIV1(InitStruct->Div1));
    assert_param(IS_RCU_PLL_DIV2(InitStruct->Div2));

    MODIFY_REG(RCU->PLLDIV,	(RCU_PLLDIV_RDIV_Msk | RCU_PLLDIV_RDIV_Msk | RCU_PLLDIV_DIV1A_Msk | RCU_PLLDIV_DIV1B_Msk),
               (InitStruct->NDiv << RCU_PLLDIV_NDIV_Pos |
            	InitStruct->RDiv << RCU_PLLDIV_RDIV_Pos |
                InitStruct->DivA << RCU_PLLDIV_DIV1A_Pos |
                InitStruct->DivB << RCU_PLLDIV_DIV1B_Pos));

    RCU_PLL_OutCmd(ENABLE);
    while (timeout) {
        if (RCU_PLL_LockStatus()) {
            break;
        } else {
            timeout--;
        }
    }
    if (!timeout) {
        status = ERROR;
    }

    return status;
}

/**
  * @brief   Заполнение каждого члена структуры InitStruct значениями по умолчанию
  * @param   InitStruct  Указатель на структуру типа @ref RCU_PLL_Init_TypeDef,
  *                      которую необходимо проинициализировать
  * @retval  void
  */
void RCU_PLL_StructInit(RCU_PLL_Init_TypeDef* InitStruct)
{
    InitStruct->FbDiv = 16;
    InitStruct->RDiv = 1;
    InitStruct->NDiv = 1;
    InitStruct->PreDiv = 1;
    InitStruct->DivA = 1;
    InitStruct->DivB = 1;
}

/**
  * @brief   Устанавливает все регистры PLL значениями по умолчанию
  * @retval  void
  */
void RCU_PLL_DeInit()
{
    RCU_PLL_OutCmd(DISABLE);
    WRITE_REG(RCU->PLLCFG, 0x0010F001);
}

/**
  * @brief   Переключение источника для системного тактового сигнала
  * @param   SysClk  Выбор источника
  * @retval  void
  */
OperationStatus RCU_SysClkChangeCmd(RCU_SysClk_TypeDef SysClk)
{
    uint32_t timeout = RCU_SYSCLK_CHANGE_TIMEOUT;
    OperationStatus status = OK;

    assert_param(IS_RCU_SYS_CLK(SysClk));

    RCU_SysClkConfig(SysClk);

    while (timeout) {
        if ((RCU_SysClkStatus() != SysClk)) {
            timeout--;
        } else {
            break;
        }
    }

    if (!timeout) {
        status = ERROR;
    }

    return status;
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2019 NIIET *****END OF FILE****/
