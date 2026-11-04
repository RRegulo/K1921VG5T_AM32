/**
  ******************************************************************************
  * @file    plib5t_uart.c
  *
  * @brief   Файл содержит реализацию функций для работы с UART
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
#include "plib5t_uart.h"

/** @addtogroup Peripheral
  * @{
  */

/** @addtogroup UART
  * @{
  */

/** @defgroup UART_Private Приватные данные
  * @{
  */

/** @defgroup UART_Private_Defines Приватные константы
  * @{
  */

/**
  * @}
  */

/** @defgroup UART_Private_Functions Приватные функции
  * @{
  */

/**
  * @brief   Автоматический расчёт и установка делителей для нужной скорости передачи
  * @param   UARTx  Выбор модуля UART, где x=0|1|2|3
  * @param   State  Выбор состояния
  * @retval  void
  */
void UART_AutoBaudConfig(UART_TypeDef* UARTx, uint32_t BaudRate)
{
    UART_Num_TypeDef UARTx_Num;
    uint32_t uart_clk_freq, int_div, frac_div;

    assert_param(IS_UART_PERIPH(UARTx));

    if (UARTx == UART0) {
        UARTx_Num = UART0_Num;
    } else if (UARTx == UART1) {
        UARTx_Num = UART1_Num;
    }

    uart_clk_freq = RCU_GetUARTClkFreq(UARTx_Num);
    /* integer only: BRD = clk / (16 * baud), FBRD = round(frac(BRD) * 64).
     * round(BRD * 64) = (4 * clk + baud / 2) / baud. The float version
     * compiled to fdiv/fmadd with operands loaded from flash (.srodata) —
     * the pattern of the NIIET RISC-V FPU errata (VG015 FDIV, VG7T constant
     * multiply at -Os). */
    {
        uint32_t brd64 = (uint32_t)(((uint64_t)uart_clk_freq * 4u + BaudRate / 2u) / BaudRate);
        int_div = brd64 >> 6;
        frac_div = brd64 & 0x3Fu;
    }
    UART_BaudDivConfig(UARTx, int_div, frac_div);
}

/**
  * @brief   Устанавливает все регистры UART значениями по умолчанию
  * @param   UARTx   Выбор модуля UART, где x=0|1|2|3
  * @retval  void
  */
void UART_DeInit(UART_TypeDef* UARTx)
{
    UART_Num_TypeDef UARTx_Num;

    assert_param(IS_UART_PERIPH(UARTx));

    if (UARTx == UART0) {
        UARTx_Num = UART0_Num;
    } else if (UARTx == UART1) {
        UARTx_Num = UART1_Num;
    }

    RCU_UARTRstCmd(UARTx_Num, DISABLE);
    RCU_UARTRstCmd(UARTx_Num, ENABLE);
}

/**
  * @brief   Инициализирует UARTx согласно параметрам структуры InitStruct.
  * @param   UARTx   Выбор модуля UART, где x=0|1|2|3
  * @param   InitStruct  Указатель на структуру типа @ref UART_Init_TypeDef,
  *                      которая содержит конфигурационную информацию.
  * @retval  Status  Статус результата инициализации
  */
void UART_Init(UART_TypeDef* UARTx, UART_Init_TypeDef* InitStruct)
{
    UART_AutoBaudConfig(UARTx, InitStruct->BaudRate);
    UART_DataWidthConfig(UARTx, InitStruct->DataWidth);
    UART_StopBitConfig(UARTx, InitStruct->StopBit);
    UART_ParityBitConfig(UARTx, InitStruct->ParityBit);
    UART_FIFOCmd(UARTx, InitStruct->FIFO);
    UART_TxCmd(UARTx, InitStruct->Tx);
    UART_RxCmd(UARTx, InitStruct->Rx);
}

/**
  * @brief   Заполнение каждого члена структуры InitStruct значениями по умолчанию.
  * @param   InitStruct  Указатель на структуру типа @ref UART_Init_TypeDef,
  *                      которую необходимо проинициализировать.
  * @retval  void
  */
void UART_StructInit(UART_Init_TypeDef* InitStruct)
{
    InitStruct->BaudRate = 9600;
    InitStruct->DataWidth = UART_DataWidth_8;
    InitStruct->FIFO = DISABLE;
    InitStruct->ParityBit = UART_ParityBit_Disable;
    InitStruct->StopBit = UART_StopBit_1;
    InitStruct->Rx = DISABLE;
    InitStruct->Tx = DISABLE;
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

/******************* (C) COPYRIGHT 2022 NIIET *****END OF FILE****/
