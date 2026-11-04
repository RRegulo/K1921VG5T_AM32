/**
  ******************************************************************************
  * @file    plib5t_rcu.h
  *
  * @brief   Файл содержит прототипы и компактные inline реализации функций для
  *          RCU (Reset & Clock control Unit), а также сопутствующие
  *          макроопределения и перечисления
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PLIB5T_RCU_H
#define __PLIB5T_RCU_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "plib5t.h"

/** @addtogroup Peripheral
  * @{
  */

/** @defgroup RCU
  * @brief Драйвер для работы с тактированием и сбросом периферийных блоков
  * @{
  */

/** @defgroup RCU_Exported_Defines Константы
  * @{
  */

#define HSICLK_VAL 4000000
#define HSECLK_VAL 16000000
#define EXTCLK_VAL 1000000

/** @defgroup RCU_ClkStatus_Define Cтатусы источников тактового сигнала
  * @{
  */

#define RCU_ClkStatus_HSEClkFail RCU_CLKSTAT_CLKERR1_Msk          /*!< Ошибка сигнала внешнего осциллятора */
#define RCU_ClkStatus_PLLClkFail RCU_CLKSTAT_CLKERR2_Msk          /*!< Ошибка сигнала с PLL */
#define RCU_ClkStatus_LSIClkFail RCU_CLKSTAT_CLKERR3_Msk          /*!< Ошибка сигнала с LSI */
#define RCU_ClkStatus_HSEClkGood RCU_CLKSTAT_CLKGOOD1_Msk         /*!< Нормальная работа сигнала внешнего осциллятора */
#define RCU_ClkStatus_PLLClkGood RCU_CLKSTAT_CLKGOOD2_Msk         /*!< Нормальная работа сигнала с PLL */
#define RCU_ClkStatus_LSIClkGood RCU_CLKSTAT_CLKGOOD3_Msk         /*!< Нормальная работа сигнала с LSI */

#define IS_RCU_CLK_STATUS(VALUE) (((VALUE) == RCU_ClkStatus_HSEClkFail) ||    \
                                  ((VALUE) == RCU_ClkStatus_PLLClkFail) ||    \
                                  ((VALUE) == RCU_ClkStatus_LSIClkFail) ||    \
                                  ((VALUE) == RCU_ClkStatus_HSEClkGood) ||    \
                                  ((VALUE) == RCU_ClkStatus_PLLClkGood) ||    \
                                  ((VALUE) == RCU_ClkStatus_LSIClkGood))
/**
  * @}
  */

/** @defgroup RCU_RstStatus_Define Источник, вызвавший последний сброс системы
  * @{
  */

#define RCU_RstStatus_POR     RCU_RSTSTAT_POR_Msk         /*!< Сброс от блока POR */
#define RCU_RstStatus_WDOG    RCU_RSTSTAT_WDOG_Msk        /*!< Сброс от сторожевого таймера */
#define RCU_RstStatus_Sys     RCU_RSTSTAT_SYSRST_Msk      /*!< Системный сброс */

#define IS_RCU_RST_STATUS(VALUE) (((VALUE) == RCU_RstStatus_POR) || \
                                  ((VALUE) == RCU_RstStatus_WDOG) || \
                                  ((VALUE) == RCU_RstStatus_Sys))
/**
  * @}
  */

/** @defgroup RCU_ITSource_Define Источники прерываний
  * @{
  */

#define RCU_ITSource_SRCClkFail RCU_INTEN_SRCCLKERR_Msk       /*!< Произошла ошибка сигнала внешнего осциллятора */
#define RCU_ITSource_PLLClkFail RCU_INTEN_PLLCLKERR_Msk       /*!< Произошла ошибка сигнала с PLL */
#define RCU_ITSource_PLLDivClkFail RCU_INTEN_PLLDIVCLKERR_Msk /*!< Произошла ошибка сигнала с деленного выхода PLL */
#define RCU_ITSource_SRCClkGood RCU_INTEN_SRCCLKOK_Msk        /*!< Произошел переход к нормальной работе сигнала внешнего осциллятора */
#define RCU_ITSource_PLLClkGood RCU_INTEN_PLLCLKOK_Msk        /*!< Произошел переход к нормальной работе сигнала с PLL */
#define RCU_ITSource_PLLDivClkGood RCU_INTEN_PLLDIVCLKOK_Msk  /*!< Произошел переход к нормальной работе сигнала с деленного выхода PLL */
#define RCU_ITSource_PLLLock RCU_INTEN_PLLLOCK_Msk            /*!< Произошел захват частоты PLL */

#define IS_RCU_IT_SOURCE(VALUE) (((VALUE) == RCU_ITSource_SRCClkFail) ||    \
                                 ((VALUE) == RCU_ITSource_PLLClkFail) ||    \
                                 ((VALUE) == RCU_ITSource_PLLDivClkFail) || \
                                 ((VALUE) == RCU_ITSource_SRCClkGood) ||    \
                                 ((VALUE) == RCU_ITSource_PLLClkGood) ||    \
                                 ((VALUE) == RCU_ITSource_PLLDivClkGood) || \
                                 ((VALUE) == RCU_ITSource_PLLLock))

/**
  * @}
  */

/** @defgroup RCU_ITStatus_Define Статусы прерываний
  * @{
  */

#define RCU_ITStatus_SRCClkFail RCU_INTSTAT_SRCCLKERR_Msk       /*!< Флаг ошибки сигнала внешнего осциллятора */
#define RCU_ITStatus_PLLClkFail RCU_INTSTAT_PLLCLKERR_Msk       /*!< Флаг ошибки сигнала с PLL */
#define RCU_ITStatus_SRCClkGood RCU_INTSTAT_SRCCLKOK_Msk        /*!< Флаг перехода к нормальной работе сигнала внешнего осциллятора */
#define RCU_ITStatus_PLLClkGood RCU_INTSTAT_PLLCLKOK_Msk        /*!< Флаг перехода к нормальной работе сигнала с PLL */
#define RCU_ITStatus_PLLLock    RCU_INTSTAT_PLLLOCK_Msk            /*!< Флаг захвата частоты PLL */
#define RCU_ITStatus_PLLFail    RCU_INTSTAT_PLLFAIL_Msk            /*!< Флаг сбоя системной частоты */

#define IS_RCU_IT_STATUS(VALUE) (((VALUE) == RCU_ITStatus_SRCClkFail) ||    \
                                 ((VALUE) == RCU_ITStatus_PLLClkFail) ||    \
                                 ((VALUE) == RCU_ITStatus_SRCClkGood) ||    \
                                 ((VALUE) == RCU_ITStatus_PLLClkGood) ||    \
                                 ((VALUE) == RCU_ITStatus_PLLLock) ||       \
                                 ((VALUE) == RCU_ITStatus_PLLFail))

/**
  * @}
  */

/** @defgroup RCU_AHBClk_Define Управление тактированием периферийных блоков AHB
  * @{
  */

#define RCU_AHBClk_ADC      RCU_CGCFGAHB_ADCEN_Msk     /*!< Управление тактированием блока ADC */
#define RCU_AHBClk_CAN      RCU_CGCFGAHB_CANEN_Msk     /*!< Управление тактированием блока CAN */
#define RCU_AHBClk_GPIOA    RCU_CGCFGAHB_GPIOAEN_Msk   /*!< Управление тактированием блока GPIOA */
#define RCU_AHBClk_GPIOB    RCU_CGCFGAHB_GPIOBEN_Msk   /*!< Управление тактированием блока GPIOB */

#define IS_RCU_AHB_CLK(VALUE)   (((VALUE) == RCU_AHBClk_ADC) || \
                                 ((VALUE) == RCU_AHBClk_CAN) || \
                                 ((VALUE) == RCU_AHBClk_GPIOA) || \
                                 ((VALUE) == RCU_AHBClk_GPIOB))

/**
  * @}
  */

/** @defgroup RCU_APBClk_Define Управление тактированием периферийных блоков APB
  * @{
  */

#define RCU_APBClk_DMA    RCU_CGCFGAPB_DMAEN_Msk     /*!< Управление тактированием блока DMA */
#define RCU_APBClk_RTC    RCU_CGCFGAPB_RTCEN_Msk     /*!< Управление тактированием блока RTC */
#define RCU_APBClk_WDT    RCU_CGCFGAPB_WDTEN_Msk     /*!< Управление тактированием блока WDT */
#define RCU_APBClk_CAP0   RCU_CGCFGAPB_CAP0EN_Msk    /*!< Управление тактированием блока CAP0 */
#define RCU_APBClk_CAP1   RCU_CGCFGAPB_CAP1EN_Msk    /*!< Управление тактированием блока CAP1 */
#define RCU_APBClk_CAP2   RCU_CGCFGAPB_CAP2EN_Msk    /*!< Управление тактированием блока CAP2 */
#define RCU_APBClk_TMR0   RCU_CGCFGAPB_TMR0EN_Msk    /*!< Управление тактированием блока TMR 0 */
#define RCU_APBClk_TMR1   RCU_CGCFGAPB_TMR1EN_Msk    /*!< Управление тактированием блока TMR 1 */
#define RCU_APBClk_TMR2   RCU_CGCFGAPB_TMR2EN_Msk    /*!< Управление тактированием блока TMR 2 */
#define RCU_APBClk_TMR3   RCU_CGCFGAPB_TMR3EN_Msk    /*!< Управление тактированием блока TMR 3 */
#define RCU_APBClk_SPI0   RCU_CGCFGAPB_SPI0EN_Msk    /*!< Управление тактированием блока SPI 0 */
#define RCU_APBClk_SPI1   RCU_CGCFGAPB_SPI1EN_Msk    /*!< Управление тактированием блока SPI 1 */
#define RCU_APBClk_UART0  RCU_CGCFGAPB_UART0EN_Msk   /*!< Управление тактированием блока UART 0 */
#define RCU_APBClk_UART1  RCU_CGCFGAPB_UART1EN_Msk   /*!< Управление тактированием блока UART 1 */
#define RCU_APBClk_PWM0   RCU_CGCFGAPB_PWM0EN_Msk    /*!< Управление тактированием блока PWM0 */
#define RCU_APBClk_PWM1   RCU_CGCFGAPB_PWM1EN_Msk    /*!< Управление тактированием блока PWM1 */
#define RCU_APBClk_PWM2   RCU_CGCFGAPB_PWM2EN_Msk    /*!< Управление тактированием блока PWM2 */
#define RCU_APBClk_I2C    RCU_CGCFGAPB_I2CEN_Msk     /*!< Управление тактированием блока I2C */
#define RCU_APBClk_QEP    RCU_CGCFGAPB_QEPEN_Msk     /*!< Управление тактированием блока QEP */

#define IS_RCU_APB_CLK(VALUE)   (((VALUE) == RCU_APBClk_DMA) ||  \
                                 ((VALUE) == RCU_APBClk_RTC) ||  \
                                 ((VALUE) == RCU_APBClk_WDT) ||  \
                                 ((VALUE) == RCU_APBClk_CAP0) ||  \
                                 ((VALUE) == RCU_APBClk_CAP1) ||  \
                                 ((VALUE) == RCU_APBClk_CAP2) ||  \
                                 ((VALUE) == RCU_APBClk_TMR0) ||  \
                                 ((VALUE) == RCU_APBClk_TMR1) ||  \
                                 ((VALUE) == RCU_APBClk_TMR2) ||  \
                                 ((VALUE) == RCU_APBClk_TMR3) ||  \
                                 ((VALUE) == RCU_APBClk_SPI0) ||  \
                                 ((VALUE) == RCU_APBClk_SPI1) ||  \
                                 ((VALUE) == RCU_APBClk_UART0) || \
                                 ((VALUE) == RCU_APBClk_UART1) || \
                                 ((VALUE) == RCU_APBClk_PWM0) ||  \
                                 ((VALUE) == RCU_APBClk_PWM1) ||  \
                                 ((VALUE) == RCU_APBClk_PWM2) ||  \
                                 ((VALUE) == RCU_APBClk_I2C) ||   \
                                 ((VALUE) == RCU_APBClk_QEP))

/**
  * @}
  */

/** @defgroup RCU_AHBRst_Define Управление сбросом периферийных блоков AHB
 * @{
 */

#define RCU_AHBRst_ADC      RCU_RSTDISAHB_ADCEN_Msk     /*!< Управление сбросом блока ADC */
#define RCU_AHBRst_CAN      RCU_RSTDISAHB_CANEN_Msk     /*!< Управление сбросом блока CAN */
#define RCU_AHBRst_GPIOA    RCU_RSTDISAHB_GPIOAEN_Msk   /*!< Управление сбросом блока GPIOA */
#define RCU_AHBRst_GPIOB    RCU_RSTDISAHB_GPIOBEN_Msk   /*!< Управление сбросом блока GPIOB */

#define IS_RCU_AHB_RST(VALUE)   (((VALUE) == RCU_AHBRst_ADC) || \
                                 ((VALUE) == RCU_AHBRst_CAN) || \
                                 ((VALUE) == RCU_AHBRst_GPIOA) || \
                                 ((VALUE) == RCU_AHBRst_GPIOB))

/**
 * @}
 */

/** @defgroup RCU_APBRst_Define Управление сбросом периферийных блоков APB
  * @{
  */

#define RCU_APBRst_DMA    RCU_RSTDISAPB_DMAEN_Msk     /*!< Управление сбросом блока DMA */
#define RCU_APBRst_RTC    RCU_RSTDISAPB_RTCEN_Msk     /*!< Управление сбросом блока RTC */
#define RCU_APBRst_WDT    RCU_RSTDISAPB_WDTEN_Msk     /*!< Управление сбросом блока WDT */
#define RCU_APBRst_CAP0   RCU_RSTDISAPB_CAP0EN_Msk    /*!< Управление сбросом блока CAP 0 */
#define RCU_APBRst_CAP1   RCU_RSTDISAPB_CAP1EN_Msk    /*!< Управление сбросом блока CAP 1 */
#define RCU_APBRst_CAP2   RCU_RSTDISAPB_CAP2EN_Msk    /*!< Управление сбросом блока CAP 2 */
#define RCU_APBRst_TMR0   RCU_RSTDISAPB_TMR0EN_Msk    /*!< Управление сбросом блока TMR 0 */
#define RCU_APBRst_TMR1   RCU_RSTDISAPB_TMR1EN_Msk    /*!< Управление сбросом блока TMR 1 */
#define RCU_APBRst_TMR2   RCU_RSTDISAPB_TMR2EN_Msk    /*!< Управление сбросом блока TMR 2 */
#define RCU_APBRst_TMR3   RCU_RSTDISAPB_TMR3EN_Msk    /*!< Управление сбросом блока TMR 3 */
#define RCU_APBRst_SPI0   RCU_RSTDISAPB_SPI0EN_Msk    /*!< Управление сбросом блока SPI 0 */
#define RCU_APBRst_SPI1   RCU_RSTDISAPB_SPI1EN_Msk    /*!< Управление сбросом блока SPI 1 */
#define RCU_APBRst_UART0  RCU_RSTDISAPB_UART0EN_Msk   /*!< Управление сбросом блока UART 0 */
#define RCU_APBRst_UART1  RCU_RSTDISAPB_UART1EN_Msk   /*!< Управление сбросом блока UART 1 */
#define RCU_APBRst_PWM0   RCU_RSTDISAPB_PWM0EN_Msk    /*!< Управление сбросом блока PWM 0 */
#define RCU_APBRst_PWM1   RCU_RSTDISAPB_PWM1EN_Msk    /*!< Управление сбросом блока PWM 1 */
#define RCU_APBRst_PWM2   RCU_RSTDISAPB_PWM2EN_Msk    /*!< Управление сбросом блока PWM 2 */
#define RCU_APBRst_I2C    RCU_RSTDISAPB_I2CEN_Msk     /*!< Управление сбросом блока I2C */
#define RCU_APBRst_QEP    RCU_RSTDISAPB_QEPEN_Msk     /*!< Управление сбросом блока QEP */

#define IS_RCU_APB_RST(VALUE)   (((VALUE) == RCU_APBRst_DMA) || \
                                 ((VALUE) == RCU_APBRst_RTC) || \
                                 ((VALUE) == RCU_APBRst_WDT) || \
                                 ((VALUE) == RCU_APBRst_CAP0) || \
                                 ((VALUE) == RCU_APBRst_CAP1) || \
                                 ((VALUE) == RCU_APBRst_CAP2) || \
                                 ((VALUE) == RCU_APBRst_TMR0) || \
                                 ((VALUE) == RCU_APBRst_TMR1) || \
                                 ((VALUE) == RCU_APBRst_TMR2) || \
                                 ((VALUE) == RCU_APBRst_TMR3) || \
                                 ((VALUE) == RCU_APBRst_SPI0) || \
                                 ((VALUE) == RCU_APBRst_SPI1) || \
                                 ((VALUE) == RCU_APBRst_UART0) || \
                                 ((VALUE) == RCU_APBRst_UART1) || \
                                 ((VALUE) == RCU_APBRst_PWM0) || \
                                 ((VALUE) == RCU_APBRst_PWM1) || \
								 ((VALUE) == RCU_APBRst_PWM2) || \
                                 ((VALUE) == RCU_APBRst_I2C) || \
                                 ((VALUE) == RCU_APBRst_QEP))

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup RCU_Exported_Types Типы
  * @{
  */

/**
  * @brief  Выбор источника тактирования для периферийного блока
  *         c несколькими тактовыми доменами - UART, QSPI, SPI, WDT, ADCSAR, ADCSD
  */
typedef enum {
    RCU_PeriphClk_HsiClk = RCU_UARTCFG_CLKSEL_REFCLK,       /*!< Сигнал HSICLK ( REFCLK ) */
    RCU_PeriphClk_HseClk = RCU_UARTCFG_CLKSEL_SRCCLK,       /*!< Сигнал HSECLK ( SRCCLK ) */
    RCU_PeriphClk_PllClk = RCU_UARTCFG_CLKSEL_PLLCLK,       /*!< Сигнал PLLCLK */
    RCU_PeriphClk_ExtClk = RCU_UARTCFG_CLKSEL_EXTCLK        /*!< Сигнал EXTCLK */
} RCU_PeriphClk_TypeDef;
#define IS_RCU_PERIPH_CLK(VALUE) (((VALUE) == RCU_PeriphClk_HsiClk) ||    \
                                  ((VALUE) == RCU_PeriphClk_HseClk) ||    \
                                  ((VALUE) == RCU_PeriphClk_PllClk) || \
                                  ((VALUE) == RCU_PeriphClk_ExtClk))

/**
  * @brief  Выбор источника тактирования для CLKOUT
  */
typedef enum {
    RCU_ClkoutClk_HsiClk = RCU_CLKOUTCFG_CLKSEL_HSICLK,      /*!< Сигнал HSICLK */
    RCU_ClkoutClk_HseClk = RCU_CLKOUTCFG_CLKSEL_HSECLK,      /*!< Сигнал HSECLK */
    RCU_ClkoutClk_PLLClk = RCU_CLKOUTCFG_CLKSEL_PLLCLK,      /*!< Сигнал SYSPLL0CL */
    RCU_ClkoutClk_RTCClk = RCU_CLKOUTCFG_CLKSEL_RTCCLK       /*!< Сигнал RTCCLK */
} RCU_ClkoutClk_TypeDef;
#define IS_RCU_SPWR_CLK(VALUE) (((VALUE) == RCU_ClkoutClk_HsiClk) ||    \
                                ((VALUE) == RCU_ClkoutClk_HseClk) ||    \
                                ((VALUE) == RCU_ClkoutClk_SysPLL0Clk) || \
                                ((VALUE) == RCU_ClkoutClk_LsiClk))

/**
  * @brief  Выбор источника системной частоты
  */
typedef enum {
    RCU_SysClk_HsiClk = RCU_SYSCLKCFG_SRC_HSICLK,     /*!< Сигнал HSICLK */
    RCU_SysClk_HseClk = RCU_SYSCLKCFG_SRC_HSECLK,     /*!< Сигнал HSECLK */
    RCU_SysClk_PLLClk = RCU_SYSCLKCFG_SRC_PLLCLK,     /*!< Сигнал SYSPLL0CLK */
    RCU_SysClk_ExtClk = RCU_SYSCLKCFG_SRC_EXTCLK      /*!< Сигнал LSICLK */
} RCU_SysClk_TypeDef;
#define IS_RCU_SYS_CLK(VALUE) (((VALUE) == RCU_SysClk_HsiClk) || \
                               ((VALUE) == RCU_SysClk_HseClk) || \
                               ((VALUE) == RCU_SysClk_PLLClk) || \
                               ((VALUE) == RCU_SysClk_ExtClk))

/**
  * @brief  Структура инициализации PLL
  *
  */
typedef struct
{
    uint32_t RDiv;               /*!< Делитель опорного сигнала PLL (M).
                                   Параметр может принимать любое значение из диапазона 1-63. */
    uint32_t NDiv;               /*!< Делитель опорного сигнала PLL (M).
                                   Параметр может принимать любое значение из диапазона 1-63. */
    uint32_t PreDiv;            /*!< Делитель опорного сигнала PLL (M).
                                   Параметр может принимать любое значение из диапазона 1-63. */
    uint32_t FbDiv;           	/*!< Делитель обратной связи (N).
                                   Параметр может принимать любое значение из диапазона:
                                      16-160 (без дробного делителя),
                                      20-160 (с дробным делителем) */
    uint32_t FracDiv;         /*!< Дробный делитель.
                                   Параметр может принимать любое значение из диапазона 1-255. */                                   
    uint32_t DivA;           /*!< Внутренний делитель PLL A (итоговое значение (DivA+1))
                                   Параметр может принимать любое значение из диапазона 0-7. */
    uint32_t DivB;           /*!< Внутренний делитель PLL B (итоговое значение (DivB+1))
                                   Параметр может принимать любое значение из диапазона 0-63. */
} RCU_PLL_Init_TypeDef;

#define IS_RCU_PLL_REF_DIV(VALUE) (((VALUE) <= 63) && ((VALUE) >= 1))
#define IS_RCU_PLL_FB_DIV(VALUE) (((VALUE) <= 160) && ((VALUE) >= 16))
#define IS_RCU_PLL_DIV0A(VALUE) (((VALUE) <= 7) && ((VALUE) >= 0))
#define IS_RCU_PLL_DIV0B(VALUE) (((VALUE) <= 7) && ((VALUE) >= 0))
#define IS_RCU_PLL_DIV1A(VALUE) (((VALUE) <= 7) && ((VALUE) >= 0))
#define IS_RCU_PLL_DIV1B(VALUE) (((VALUE) <= 7) && ((VALUE) >= 0))
#define IS_RCU_PLL_DIVA_DIVB(VALUE_A,VALUE_B) (VALUE_A > VALUE_B)
#define IS_RCU_PLL_REF_FREQ(VALUE) (((VALUE) <= 800000000) && ((VALUE) >= 10000000))
#define IS_RCU_PLL_OUT_FREQ(VALUE) (((VALUE) <= 1600000000) && ((VALUE) >= 8000000))
#define IS_RCU_PLL_FVCO_FREQ(VALUE) (((VALUE) <= 1600000000) && ((VALUE) >= 200000000))
#define IS_RCU_PLL_FREF_DIV_FREQ(VALUE) ((VALUE) >= 10000000)
#define IS_RCU_SYSCLK_FREQ(VALUE) (((VALUE) <= 60000000) && ((VALUE) >= 1000000))
#define IS_RCU_SECPRD(VALUE) (((VALUE)&0xFFFFFF00) == 0)
#define IS_RCU_PERIPH_DIV(VALUE) (((VALUE)&0xFFFFFFC0) == 0)
#define IS_RCU_CLKOUT_DIV(VALUE) (((VALUE)&0xFFFFFFF8) == 0)

/**
  * @}
  */

/** @defgroup RCU_Exported_Functions Функции
  * @{
  */

uint32_t RCU_GetHSIClkFreq(void);
uint32_t RCU_GetHSEClkFreq(void);
uint32_t RCU_GetEXTClkFreq(void);
uint32_t RCU_GetRTCClkFreq(void);
uint32_t RCU_GetPLLClkFreq(void);

/**
  * @brief   Включение тактирования выбранного APB блока периферии.
  * @param   APBClk  Выбор периферии. Любая совокупность значений значений RCU_APBClk_x (@ref RCU_APBClk_Define).
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_APBClkCmd(uint32_t APBClk, FunctionalState State)
{
    assert_param(IS_RCU_APB_CLK(APBClk));
    assert_param(IS_FUNCTIONAL_STATE(State));

    MODIFY_REG(RCU->CGCFGAPB, APBClk, State ? APBClk : 0);
}

/**
  * @brief   Включение тактирования выбранного AHB блока периферии
  * @param   AHBClk  Выбор периферии. Любая совокупность значений значений RCU_AHBClk_x (@ref RCU_AHBClk_Define).
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_AHBClkCmd(uint32_t AHBClk, FunctionalState State)
{
    assert_param(IS_RCU_AHB_CLK(AHBClk));
    assert_param(IS_FUNCTIONAL_STATE(State));

    MODIFY_REG(RCU->CGCFGAHB, AHBClk, State ? AHBClk : 0);
}

/**
  * @brief   Вывод из состояния сброса периферийных блоков APB
  * @param   APBRst  Выбор периферийного модуля. Любая совокупность значений значений RCU_APBRst0_x (@ref RCU_APBRst0_Define).
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_APBRstCmd(uint32_t APBRst, FunctionalState State)
{
    assert_param(IS_RCU_APB_RST(APBRst));
    assert_param(IS_FUNCTIONAL_STATE(State));

    MODIFY_REG(RCU->RSTDISAPB, APBRst, State ? APBRst : 0);
}

/**
  * @brief   Вывод из состояния сброса периферийных блоков APB
  * @param   AHBRst  Выбор периферийного модуля. Любая совокупность значений значений RCU_AHBRst_x (@ref RCU_AHBRst_Define).
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_AHBRstCmd(uint32_t AHBRst, FunctionalState State)
{
    assert_param(IS_RCU_AHB_RST(AHBRst));
    assert_param(IS_FUNCTIONAL_STATE(State));

    MODIFY_REG(RCU->RSTDISAHB, AHBRst, State ? AHBRst : 0);
}

/**
  * @brief   Установка опорного тактового сигнала для системной частоты
  * @param   SysClk  Выбор тактового сигнала
  * @retval  void
  */
__STATIC_INLINE void RCU_SysClkConfig(RCU_SysClk_TypeDef SysClk)
{
    assert_param(IS_RCU_SYS_CLK(SysClk));

    WRITE_REG(RCU->SYSCLKCFG_bit.SRC, SysClk);
}

/**
  * @brief   Получение текущего опорного тактового сигнала для системной частоты
  * @retval  Val  Выбранный сигнал
  */
__STATIC_INLINE RCU_SysClk_TypeDef RCU_SysClkStatus(void)
{
    return (RCU_SysClk_TypeDef)READ_REG(RCU->CLKSTAT_bit.SRC);
}

/**
  * @brief   Получение статуса выбранного тактового сигнала
  * @param   ClkStatus  Выбор тактового сигнала. Любая совокупность значений значений RCU_ClkStatus_x (@ref RCU_ClkStatus_Define).
  * @retval  Status  Статус
  */
__STATIC_INLINE FlagStatus RCU_ClkStatus(uint32_t ClkStatus)
{
    return (FlagStatus)READ_BIT(RCU->CLKSTAT, ClkStatus);
}

uint32_t RCU_GetSysClkFreq(void);

/**
  * @brief   Включение системы слежения за системным тактовым сигналом
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_SecurityCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(RCU->SYSCLKCFG_bit.SECEN, State);
}

/**
  * @brief   Настройка периода срабатывания системы слежения
  * @param   HsePrd  Максимальное значение счетчика слежения за сигналом HSeCLK
  * @param   PLLPrd  Максимальное значение счетчика слежения за сигналом SYSPLL0CLK
  * @param   LsiPrd  Максимальное значение счетчика слежения за сигналом LSICLK
  * @retval  void
  */
__STATIC_INLINE void RCU_SecurityConfig(uint32_t HsePrd, uint32_t PLLPrd, uint32_t LsiPrd)
{
    assert_param(IS_RCU_SECPRD(HsePrd));
    assert_param(IS_RCU_SECPRD(PLLPrd));
    assert_param(IS_RCU_SECPRD(LsiPrd));

    WRITE_REG(RCU->SECCNT0, (HsePrd << RCU_SECCNT0_VAL1_Pos));
    WRITE_REG(RCU->SECCNT1, (LsiPrd << RCU_SECCNT1_VAL3_Pos)|PLLPrd);
}

/**
  * @brief   Получение статуса выбранного типа сброса
  * @param   RstStatus  Выбранный тип сброса. Любая совокупность значений значений RCU_RstStatus_x (@ref RCU_RstStatus_Define).
  * @retval  Status  Статус активности
  */
__STATIC_INLINE FlagStatus RCU_RstStatus(uint32_t RstStatus)
{
    return (FlagStatus)READ_BIT(RCU->RSTSTAT, RstStatus);
}

/**
  * @brief   Очистка статуса выбранного типа сброса
  * @param   RstStatus  Выбранный тип сброса. Любая совокупность значений значений RCU_RstStatus_x (@ref RCU_RstStatus_Define).
  * @retval  void
  */
__STATIC_INLINE void RCU_RstStatusClear(uint32_t RstStatus)
{
    assert_param(IS_RCU_RST_STATUS(RstStatus));

    WRITE_REG(RCU->RSTSTAT, RstStatus);
}

OperationStatus RCU_SysClkChangeCmd(RCU_SysClk_TypeDef SysClk);

/** @defgroup RCU_Init_Deinit Конфигурация PLL
  * @{
  */

//OperationStatus RCU_PLL_AutoConfig(uint32_t SysClkFreq, RCU_PLL_Ref_TypeDef Ref);
OperationStatus RCU_PLL_Init(RCU_PLL_Init_TypeDef* InitStruct);
void RCU_PLL_DeInit(void);
void RCU_PLL_StructInit(RCU_PLL_Init_TypeDef* InitStruct);

/**
  * @brief   Разрешение работы выхода SYSPLL0
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_PLL_OutCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(RCU->PLLCFG_bit.FOUTEN, State);
}


/**
  * @brief   Статус блокировки PLL (PLL Lock)
  * @retval  SET   PLL locked
  * @retval  CLEAR PLL not locked
  */
__STATIC_INLINE FlagStatus RCU_PLL_LockStatus(void)
{
    return (FlagStatus)READ_BIT(RCU->INTSTAT, RCU_INTSTAT_PLLLOCK_Msk);
}


/**
  * @brief   Включение режима bypass PLL
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_PLL_BypassCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(RCU->PLLCFG_bit.BYPASS, State);
}

/**
  * @}
  */

/** @defgroup RCU_CLK_Config_ClkOut Настройка выдачи тактового сигнала CLKOUT
  * @{
  */

uint32_t RCU_GetClkOutFreq(void);

/**
  * @brief   Настройка тактирования ClkOut
  * @param   ClkOut  Источник тактового сигнала
  * @param   DivVal  Значение делителя (деление на 2*(DivVal+1))
  * @param   DivState  Разрешение работы делителя
  * @retval  void
  */
__STATIC_INLINE void RCU_ClkOutConfig(RCU_ClkoutClk_TypeDef ClkOut, uint32_t DivVal, FunctionalState DivState)
{
    assert_param(IS_RCU_SYS_PERIPH_CLK(ClkOut));
    assert_param(IS_RCU_PERIPH_DIV(DivVal));
    assert_param(IS_FUNCTIONAL_STATE(DivState));

    MODIFY_REG(RCU->CLKOUTCFG, (RCU_CLKOUTCFG_CLKSEL_Msk | RCU_CLKOUTCFG_DIVN_Msk | RCU_CLKOUTCFG_DIVEN_Msk),
               ((ClkOut << RCU_CLKOUTCFG_CLKSEL_Pos) | (DivVal << RCU_CLKOUTCFG_DIVN_Pos) | (DivState << RCU_CLKOUTCFG_DIVEN_Pos)));
}

/**
  * @brief   Включение тактирования ClkOut
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_ClkOutCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(RCU->CLKOUTCFG_bit.CLKEN, State);
}

/**
  * @}
  */

/** @defgroup RCU_CLK_RST_Config_UART Тактирование и сброс UART
  * @{
  */

uint32_t RCU_GetUARTClkFreq(UART_Num_TypeDef UARTx_Num);

/**
  * @brief   Настройка тактирования UART
  * @param   UARTx_Num  Порядковый номер блока UART
  * @param   UARTClk  Источник тактового сигнала
  * @param   DivVal  Значение делителя (деление на 2*(DivVal+1))
  * @param   DivState  Разрешение работы делителя
  * @retval  void
  */
__STATIC_INLINE void RCU_UARTClkConfig(UART_Num_TypeDef UARTx_Num, RCU_PeriphClk_TypeDef UARTClk, uint32_t DivVal, FunctionalState DivState)
{
    assert_param(IS_RCU_PERIPH_CLK(UARTClk));
    assert_param(IS_RCU_PERIPH_DIV(DivVal));
    assert_param(IS_FUNCTIONAL_STATE(DivState));

    MODIFY_REG(RCU->UARTCFG[UARTx_Num].UARTCFG, (RCU_UARTCFG_CLKEN_Msk | RCU_UARTCFG_DIVN_Msk | RCU_UARTCFG_DIVEN_Msk),
               ((UARTClk << RCU_UARTCFG_CLKSEL_Pos) | (DivVal << RCU_UARTCFG_DIVN_Pos) | (DivState << RCU_UARTCFG_DIVEN_Pos)));
}

/**
  * @brief   Включение тактирования UART
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_UARTClkCmd(UART_Num_TypeDef UARTx_Num, FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(RCU->UARTCFG[UARTx_Num].UARTCFG_bit.CLKEN, State);
}

/**
  * @brief   Cнятие сброса UART
  * @param   UARTx_Num  Порядковый номер блока UART
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_UARTRstCmd(UART_Num_TypeDef UARTx_Num, FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(RCU->UARTCFG[UARTx_Num].UARTCFG_bit.RSTDIS, State);
}

/**
  * @}
  */

/** @defgroup RCU_CLK_RST_Config_SPI Тактирование и сброс SPI
  * @{
  */

uint32_t RCU_GetSPIClkFreq(SPI_Num_TypeDef SPIx_Num);

/**
  * @brief   Настройка тактирования SPI
  * @param   SPIx_Num  Порядковый номер блока SPI
  * @param   SPIClk  Источник тактового сигнала
  * @param   DivVal  Значение делителя (деление на 2*(DivVal+1))
  * @param   DivState  Разрешение работы делителя
  * @retval  void
  */
__STATIC_INLINE void RCU_SPIClkConfig(SPI_Num_TypeDef SPIx_Num, RCU_PeriphClk_TypeDef SPIClk, uint32_t DivVal, FunctionalState DivState)
{
    assert_param(IS_RCU_PERIPH_CLK(SPIClk));
    assert_param(IS_RCU_PERIPH_DIV(DivVal));
    assert_param(IS_FUNCTIONAL_STATE(DivState));

    MODIFY_REG(RCU->SPICFG[SPIx_Num].SPICFG, (RCU_SPICFG_CLKSEL_Msk | RCU_SPICFG_DIVN_Msk | RCU_SPICFG_DIVEN_Msk),
               ((SPIClk << RCU_SPICFG_CLKSEL_Pos) | (DivVal << RCU_SPICFG_DIVN_Pos) | (DivState << RCU_SPICFG_DIVEN_Pos)));
}

/**
  * @brief   Включение тактирования SPI
  * @param   SPIx_Num  Порядковый номер блока SPI
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_SPIClkCmd(SPI_Num_TypeDef SPIx_Num, FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(RCU->SPICFG[SPIx_Num].SPICFG_bit.CLKEN, State);
}

/**
  * @brief   Cнятие сброса SPI
  * @param   SPIx_Num  Порядковый номер блока SPI
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_SPIRstCmd(SPI_Num_TypeDef SPIx_Num, FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(RCU->SPICFG[SPIx_Num].SPICFG_bit.RSTDIS, State);
}

/**
  * @}
  */

/** @defgroup RCU_CLK_RST_Config_WDT Тактирование и сброс WDT
  * @{
  */

uint32_t RCU_GetWDTClkFreq(void);

/**
  * @brief   Настройка тактирования сторожевого таймера
  * @param   WDTClk  Источник тактового сигнала
  * @param   DivVal  Значение делителя (деление на 2*(DivVal+1))
  * @param   DivState  Разрешение работы делителя
  * @retval  void
  */
__STATIC_INLINE void RCU_WDTClkConfig(RCU_PeriphClk_TypeDef WDTClk, uint32_t DivVal, FunctionalState DivState)
{
    assert_param(IS_RCU_SYS_PERIPH_CLK(WDTClk));
    assert_param(IS_RCU_PERIPH_DIV(DivVal));
    assert_param(IS_FUNCTIONAL_STATE(DivState));

    MODIFY_REG(RCU->WDTCFG, (RCU_WDTCFG_CLKSEL_Msk | RCU_WDTCFG_DIVN_Msk | RCU_WDTCFG_DIVEN_Msk),
               ((WDTClk << RCU_WDTCFG_CLKSEL_Pos) | (DivVal << RCU_WDTCFG_DIVN_Pos) | (DivState << RCU_WDTCFG_DIVEN_Pos)));
}

/**
  * @brief   Включение тактирования сторожевого таймера
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_WDTClkCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(RCU->WDTCFG_bit.CLKEN, State);
}

/**
  * @brief   Cнятие сброса сторожевого таймера
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_WDTRstCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(RCU->WDTCFG_bit.RSTDIS, State);
}

/**
  * @}
  */

/** @defgroup RCU_CLK_RST_Config_ADC Тактирование и сброс ADC
  * @{
  */

uint32_t RCU_GetADCClkFreq(void);

/**
  * @brief   Настройка тактирования АЦП
  * @param   ADCClk  Источник тактового сигнала
  * @param   DivVal  Значение делителя (деление на 2*(DivVal+1))
  * @param   DivState  Разрешение работы делителя
  * @retval  void
  */
__STATIC_INLINE void RCU_ADCClkConfig(RCU_PeriphClk_TypeDef ADCClk, uint32_t DivVal, FunctionalState DivState)
{
    assert_param(IS_RCU_PERIPH_CLK(ADCClk));
    assert_param(IS_RCU_PERIPH_DIV(DivVal));
    assert_param(IS_FUNCTIONAL_STATE(DivState));

    MODIFY_REG(RCU->ADCCFG, (RCU_ADCCFG_CLKSEL_Msk | RCU_ADCCFG_DIVN_Msk | RCU_ADCCFG_DIVEN_Msk),
               ((ADCClk << RCU_ADCCFG_CLKSEL_Pos) | (DivVal << RCU_ADCCFG_DIVN_Pos) | (DivState << RCU_ADCCFG_DIVEN_Pos)));
}

/**
  * @brief   Включение тактирования АЦП
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_ADCClkCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(RCU->ADCCFG_bit.CLKEN, State);
}

/**
  * @brief   Cнятие сброса АЦП
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void RCU_ADCRstCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(RCU->ADCCFG_bit.RSTDIS, State);
}

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __PLIB5T_RCU_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2025 NIIET *****END OF FILE****/
