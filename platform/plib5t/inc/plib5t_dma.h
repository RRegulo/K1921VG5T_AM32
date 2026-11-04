/**
  ******************************************************************************
  * @file    plib5t_dma.h
  *
  * @brief   Файл содержит прототипы и компактные inline реализации функций для
  *          DMA, а также сопутствующие макроопределения и перечисления
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
  * <h2><center>&copy; 2026 АО "НИИЭТ"</center></h2>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PLIB5T_DMA_H
#define __PLIB5T_DMA_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "plib5t.h"

/** @addtogroup Peripheral
  * @{
  */

/** @defgroup DMA
  * @brief Драйвер для работы с DMA
  * @{
  */

/** @defgroup DMA_Exported_Defines Константы
  * @{
  */

/** @defgroup DMA_Channel_Define Маски каналов DMA
   * @{
   */

/** @defgroup DMA_Channel_Num_Define Маски каналов по номеру
  * @{
  */

#define DMA_Channel_MSK(X) (1<<X)
#define DMA_Channel_MSK_All 0xFFFFFFFFUL /*!< Все каналы DMA */

/**
  * @}
  */

/**
  * @brief  Номер канала DMA
  */
typedef enum {
    DMA_Channel_0,      /*!< Канал DMA 0 */
    DMA_Channel_1,      /*!< Канал DMA 1 */
    DMA_Channel_2,      /*!< Канал DMA 2 */
    DMA_Channel_3,      /*!< Канал DMA 3 */
    DMA_Channel_4,      /*!< Канал DMA 4 */
    DMA_Channel_5,      /*!< Канал DMA 5 */
    DMA_Channel_6,      /*!< Канал DMA 6 */
    DMA_Channel_7,      /*!< Канал DMA 7 */
    DMA_Channel_8,      /*!< Канал DMA 8 */
    DMA_Channel_9,      /*!< Канал DMA 9 */
    DMA_Channel_10,      /*!< Канал DMA 10 */
    DMA_Channel_11,      /*!< Канал DMA 11 */
    DMA_Channel_12,      /*!< Канал DMA 12 */
    DMA_Channel_13,      /*!< Канал DMA 13 */
    DMA_Channel_14,      /*!< Канал DMA 14 */
    DMA_Channel_15,      /*!< Канал DMA 15 */
    DMA_Channel_16,      /*!< Канал DMA 16 */
    DMA_Channel_17,      /*!< Канал DMA 17 */
    DMA_Channel_18,      /*!< Канал DMA 18 */
    DMA_Channel_19,      /*!< Канал DMA 19 */
    DMA_Channel_20,      /*!< Канал DMA 20 */
    DMA_Channel_21,      /*!< Канал DMA 21 */
    DMA_Channel_22,      /*!< Канал DMA 22 */
    DMA_Channel_23,      /*!< Канал DMA 23 */
    DMA_Channel_24,      /*!< Канал DMA 24 */
    DMA_Channel_25,      /*!< Канал DMA 25 */
    DMA_Channel_26,      /*!< Канал DMA 26 */
    DMA_Channel_27,      /*!< Канал DMA 27 */
    DMA_Channel_28,      /*!< Канал DMA 28 */
    DMA_Channel_29,      /*!< Канал DMA 29 */
    DMA_Channel_30,      /*!< Канал DMA 30 */
    DMA_Channel_31,      /*!< Канал DMA 31 */
} DMA_Channel_Num_TypeDef;

#define IS_DMA_CHANNEL(VALUE) (((VALUE) == (DMA_Channel_0)) ||  \
                                   ((VALUE) == (DMA_Channel_1)) ||  \
                                   ((VALUE) == (DMA_Channel_2)) ||  \
                                   ((VALUE) == (DMA_Channel_3)) ||  \
                                   ((VALUE) == (DMA_Channel_4)) ||  \
                                   ((VALUE) == (DMA_Channel_5)) ||  \
                                   ((VALUE) == (DMA_Channel_6)) ||  \
                                   ((VALUE) == (DMA_Channel_7)) ||  \
                                   ((VALUE) == (DMA_Channel_8)) ||  \
                                   ((VALUE) == (DMA_Channel_9)) ||  \
                                   ((VALUE) == (DMA_Channel_10)) || \
                                   ((VALUE) == (DMA_Channel_11)) || \
                                   ((VALUE) == (DMA_Channel_12)) || \
                                   ((VALUE) == (DMA_Channel_13)) || \
                                   ((VALUE) == (DMA_Channel_14)) || \
                                   ((VALUE) == (DMA_Channel_15)) || \
                                   ((VALUE) == (DMA_Channel_16)) || \
                                   ((VALUE) == (DMA_Channel_17)) || \
                                   ((VALUE) == (DMA_Channel_18)) || \
                                   ((VALUE) == (DMA_Channel_19)) || \
                                   ((VALUE) == (DMA_Channel_20)) || \
                                   ((VALUE) == (DMA_Channel_21)) || \
                                   ((VALUE) == (DMA_Channel_22)) || \
                                   ((VALUE) == (DMA_Channel_23)) || \
                                   ((VALUE) == (DMA_Channel_24)) || \
                                   ((VALUE) == (DMA_Channel_25)) || \
                                   ((VALUE) == (DMA_Channel_26)) || \
                                   ((VALUE) == (DMA_Channel_27)) || \
                                   ((VALUE) == (DMA_Channel_28)) || \
                                   ((VALUE) == (DMA_Channel_29)) || \
                                   ((VALUE) == (DMA_Channel_30)) || \
                                   ((VALUE) == (DMA_Channel_31)))

/**
  * @}
  */

/**
  * @brief  Номер аппаратного источника запроса каналов DMA
  */
typedef enum {
    DMA_Request_Memory = MEMORY_DMA_REQUESTOR_IDX,		/*!< Запрос памяти */
    DMA_Request_SPI0 = SPI0_DMA_REQUESTOR_IDX,			/*!< Запрос блока SPI0 */
    DMA_Request_SPI1 = SPI1_DMA_REQUESTOR_IDX,			/*!< Запрос блока SPI1 */
    DMA_Request_UART0 = UART0_DMA_REQUESTOR_IDX,		/*!< Запрос блока UART0 */
    DMA_Request_UART1 = UART1_DMA_REQUESTOR_IDX,		/*!< Запрос блока UART1 */
    DMA_Request_TMR0 = TMR0_DMA_REQUESTOR_IDX,			/*!< Запрос блока TMR0 */
    DMA_Request_TMR1 = TMR1_DMA_REQUESTOR_IDX,			/*!< Запрос блока TMR1 */
    DMA_Request_TMR2 = TMR2_DMA_REQUESTOR_IDX,			/*!< Запрос блока TMR2 */
    DMA_Request_TMR3 = TMR3_DMA_REQUESTOR_IDX,			/*!< Запрос блока TMR3 */
    DMA_Request_ADCSEQ0 = ADCSEQ0_DMA_REQUESTOR_IDX,	/*!< Запрос блока ADCSEQ0 */
    DMA_Request_ADCSEQ1 = ADCSEQ1_DMA_REQUESTOR_IDX,	/*!< Запрос блока ADCSEQ1 */
    DMA_Request_GPIOA = GPIOA_DMA_REQUESTOR_IDX,		/*!< Запрос блока GPIOA */
    DMA_Request_GPIOB = GPIOB_DMA_REQUESTOR_IDX,		/*!< Запрос блока GPIOB */
    DMA_Request_PWM0 = PWM0_DMA_REQUESTOR_IDX,			/*!< Запрос блока PWM0 */
    DMA_Request_PWM1 = PWM1_DMA_REQUESTOR_IDX,			/*!< Запрос блока PWM1 */
    DMA_Request_PWM2 = PWM2_DMA_REQUESTOR_IDX,			/*!< Запрос блока PWM2 */
    DMA_Request_QEP = QEP_DMA_REQUESTOR_IDX,			/*!< Запрос блока QEP */
    DMA_Request_CAP0 = CAP0_DMA_REQUESTOR_IDX,			/*!< Запрос блока CAP0 */
    DMA_Request_CAP1 = CAP1_DMA_REQUESTOR_IDX,			/*!< Запрос блока CAP1 */
    DMA_Request_CAP2 = CAP2_DMA_REQUESTOR_IDX,			/*!< Запрос блока CAP2 */
} DMA_Request_TypeDef;

#define IS_DMA_SOURCE(VALUE) (((VALUE) == (DMA_Request_Memory)) ||  \
                                   ((VALUE) == (DMA_Request_SPI0)) ||  \
                                   ((VALUE) == (DMA_Request_SPI1)) ||  \
                                   ((VALUE) == (DMA_Request_UART0)) ||  \
                                   ((VALUE) == (DMA_Request_UART1)) ||  \
                                   ((VALUE) == (DMA_Request_TMR0)) ||  \
                                   ((VALUE) == (DMA_Request_TMR1)) ||  \
                                   ((VALUE) == (DMA_Request_TMR2)) ||  \
                                   ((VALUE) == (DMA_Request_TMR3)) ||  \
                                   ((VALUE) == (DMA_Request_ADCSEQ0)) ||  \
                                   ((VALUE) == (DMA_Request_ADCSEQ1)) ||  \
                                   ((VALUE) == (DMA_Request_GPIOA)) ||  \
                                   ((VALUE) == (DMA_Request_GPIOB)) ||  \
                                   ((VALUE) == (DMA_Request_PWM0)) ||  \
                                   ((VALUE) == (DMA_Request_PWM1)) ||  \
                                   ((VALUE) == (DMA_Request_PWM2)) ||  \
								   ((VALUE) == (DMA_Request_QEP)) ||  \
								   ((VALUE) == (DMA_Request_CAP0)) ||  \
                                   ((VALUE) == (DMA_Request_CAP1)) ||  \
                                   ((VALUE) == (DMA_Request_CAP2)))

/**
  * @}
  */


/** @defgroup DMA_Exported_Types Типы
  * @{
  */

/**
  * @brief Выбор замены байтов по порядку следования
  */

typedef enum {
    DMA_DataSwap_Disable = 0,                         							/*!< Без замены байт */
	DMA_DataSwap_16,                          									/*!< Поменять местами байты в пределах 16 бит */
	DMA_DataSwap_32,                      										/*!< Поменять местами байты в пределах 32 бит */
} DMA_DataSwap_TypeDef;
#define IS_DMA_DATASWAP(VALUE) (((VALUE) == DMA_DataSwap_Disable) ||   \
                                ((VALUE) == DMA_DataSwap_16) ||            \
                                ((VALUE) == DMA_DataSwap_32))

/**
  * @brief  Разрядность данных источника или приемника
  */
typedef enum {
    DMA_DataSize_8 = 1,     /*!< Разрядность данных 8 бит */
    DMA_DataSize_16 = 2, 	/*!< Разрядность данных 16 бит */
    DMA_DataSize_32 = 4,     /*!< Разрядность данных 32 бит */
	DMA_DataSize_8byte = 8,  /*!< Разрядность данных 8 байт */
	DMA_DataSize_16byte = 16,/*!< Разрядность данных 16 байт */
	DMA_DataSize_32byte = 32,/*!< Разрядность данных 32 байт */
	DMA_DataSize_64byte = 64,/*!< Разрядность данных 64 байт */
} DMA_DataSize_TypeDef;
#define IS_DMA_DATA_SIZE(VALUE) (((VALUE) == DMA_DataSize_8) ||  \
                                 ((VALUE) == DMA_DataSize_16) || \
                                 ((VALUE) == DMA_DataSize_32) || \
                                 ((VALUE) == DMA_DataSize_8byte) || \
                                 ((VALUE) == DMA_DataSize_16byte) || \
                                 ((VALUE) == DMA_DataSize_32byte) || \
                                 ((VALUE) == DMA_DataSize_64byte))

/**
  * @brief  Структура инициализации канала DMA
  */
typedef struct
{
    void* SrcDataPtr;                         	/*!< Указатель начала данных источника */
    void* DstDataPtr;                         	/*!< Указатель начала данных приемника */
    void* NextDescrPtr;                       	/*!< Указатель следующего дескриптора канала DMA
     	 	 	 	 	 	 	 	 	 	 	 	 Для циклического режима указать адрес регистра SRC_PTR текущего канала */
    uint32_t BytesTotal;                    	/*!< Количество байт для передачи DMA.
                                                     Параметр может принимать любое значение из диапазона 1-1024 */
    DMA_Request_TypeDef SrcReqest;              /*!< Номер аппаратного источника запроса при чтении из источника через DMA */
    DMA_Request_TypeDef DstReqest;              /*!< Номер аппаратного источника запроса при записи в приемник через DMA */
    DMA_DataSize_TypeDef SrcDataSize;			/*!< Разрядность данных источника */
    DMA_DataSize_TypeDef DstDataSize;           /*!< Разрядность данных приемника */
    FunctionalState SrcDataInc;             	/*!< Включение инкремента адреса источника при чтении */
    FunctionalState DstDataInc;             	/*!< Включение инкремента адреса приемника при записи */
    FunctionalState LastDescr;	             	/*!< Если значение равно ENABLE, то канал остановится после передачи всего буфера */
    FunctionalState InterruptEnable;           	/*!< Включение прерывания по окончанию передачи всего буфера */
} DMA_ChannelInit_TypeDef;

#define IS_DMA_TRANSFERS_TOTAL(VALUE) (((VALUE) <= 1024) && ((VALUE) >= 1))

/**
  * @brief  Структура инициализации контроллера DMA
  */
typedef struct
{
    uint32_t Channel;                /*!< Определяет каналы, которые будут настроены.
                                          Параметр может принимать значение любой комбинации масок DMA_Channel_x из @ref DMA_Channel_Define. */
    FunctionalState RxHighPriority;  /*!< Установка высокого приоритета при чтении каналов DMA */
    FunctionalState TxHighPriority;  /*!< Установка высокого приоритета при записи каналов DMA */
    FunctionalState ChannelEnable;   /*!< Разрешение работы каналов DMA */
} DMA_Init_TypeDef;

/**
  * @}
  */

/** @defgroup DMA_Exported_Functions Функции
  * @{
  */

/** @defgroup DMA_Exported_Functions_Init_Channel Инициализация каналов DMA
  * @{
  */

void DMA_ChannelDeInit(DMA_ChannelInit_TypeDef* ChannelInitStruct);
void DMA_ChannelInit(uint32_t Channel, DMA_ChannelInit_TypeDef* ChannelInitStruct);
void DMA_ChannelStructInit(DMA_ChannelInit_TypeDef* ChannelInitStruct);

/**
  * @}
  */

/** @defgroup DMA_Exported_Functions_Init Инициализация контроллера DMA
  * @{
  */

void DMA_DeInit(void);
void DMA_Init(DMA_Init_TypeDef* InitStruct);
void DMA_StructInit(DMA_Init_TypeDef* InitStruct);

/**
  * @}
  */

/** @defgroup DMA_Exported_Functions_Config Конфигурация контроллера DMA
  * @{
  */

/**
  * @brief   Включение совместного режима DMA
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void DMA_JointModeCmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(DMA->CONTROL_bit.JOINT_MODE, State);
}

/**
  * @brief   Включение приоритета каналов DMA при чтении
  * @param   Channel  Выбор канала
  *                   Параметр принимает любую комбинацию масок DMA_Channel_x из @ref DMA_Channel_Define.
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void DMA_RxHighPriorityCmd(uint32_t Channel, FunctionalState State)
{
    assert_param(IS_DMA_CHANNEL(Channel));
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (State == ENABLE)
    	SET_BIT(DMA->RD_PRIORITY, Channel);
    else
    	CLEAR_BIT(DMA->RD_PRIORITY, Channel);
}

/**
  * @brief   Включение приоритета каналов DMA при записи
  * @param   Channel  Выбор канала
  *                   Параметр принимает любую комбинацию масок DMA_Channel_x из @ref DMA_Channel_Define.
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void DMA_TxHighPriorityCmd(uint32_t Channel, FunctionalState State)
{
    assert_param(IS_DMA_CHANNEL(Channel));
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (State == ENABLE)
    	SET_BIT(DMA->WR_PRIORITY, Channel);
    else
    	CLEAR_BIT(DMA->WR_PRIORITY, Channel);
}

/**
  * @brief   Запуск каналов DMA
  * @param   Channel  Выбор канала
  *                   Параметр принимает любую комбинацию масок DMA_Channel_x из @ref DMA_Channel_Define.
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void DMA_ChannelStartCmd(uint32_t Channel, FunctionalState State)
{
    assert_param(IS_DMA_CHANNEL(Channel));
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (State == ENABLE)
    	SET_BIT(DMA->CH_START, Channel);
    else
    	CLEAR_BIT(DMA->CH_START, Channel);
}

/**
  * @brief   Включение каналов DMA
  * @param   Channel  Выбор канала
  *                   Параметр принимает любую комбинацию масок DMA_Channel_x из @ref DMA_Channel_Define.
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void DMA_ChannelEnableCmd(uint32_t Channel, FunctionalState State)
{
    assert_param(IS_DMA_CHANNEL(Channel));
    assert_param(IS_FUNCTIONAL_STATE(State));

    if (State == ENABLE)
    	SET_BIT(DMA->CH_ENABLE, Channel);
    else
    	CLEAR_BIT(DMA->CH_ENABLE, Channel);
}

/**
  * @}
  */

/** @defgroup DMA_Exported_Functions_ChannelsConfig Конфигурация канала DMA
  * @{
  */

/**
  * @brief   Установка адреса источника данных (Rx) для канала DMA
  * @param   Channel     Номер канала (0-31)
  * @param   ReadAddr    Адрес источника данных
  * @retval  void
  */
__STATIC_INLINE void DMA_CH_SrcPtrConfig(uint32_t Channel, uint32_t ReadAddr)
{
    WRITE_REG(DMA->CH[Channel].SRC_PTR, ReadAddr);
}

/**
  * @brief   Установка адреса назначения (Tx) для канала DMA
  * @param   Channel     Номер канала (0-31)
  * @param   WriteAddr   Адрес назначения данных
  * @retval  void
  */
__STATIC_INLINE void DMA_CH_DstPtrConfig(uint32_t Channel, uint32_t WriteAddr)
{
    WRITE_REG(DMA->CH[Channel].DST_PTR, WriteAddr);
}

/**
  * @brief   Установка размера буфера для передачи в линейном режиме
  * @param   Channel     Номер канала (0-31)
  * @param   BufferSize  Размер буфера для передачи (0-1023)
  * @retval  void
  */
__STATIC_INLINE void DMA_CH_DataSizeConfig(uint32_t Channel, uint32_t BufferSize)
{
    MODIFY_REG(DMA->CH[Channel].NDTL, 
               DMA_CH_NDTL_BUFFER_SIZE_Msk, 
               (BufferSize << DMA_CH_NDTL_BUFFER_SIZE_Pos) & DMA_CH_NDTL_BUFFER_SIZE_Msk);
}

/**
  * @brief   Установка адреса следующего дескриптора
  * @param   Channel     Номер канала (0-31)
  * @param   NextAddr    Адрес следующей команды (выровненный по 4 байтам)
  * @retval  void
  */
__STATIC_INLINE void DMA_CH_NextAddressConfig(uint32_t Channel, uint32_t NextAddr)
{
    MODIFY_REG(DMA->CH[Channel].CONFIG, 
               DMA_CH_CONFIG_NEXT_ADDR_Msk, 
               (NextAddr << DMA_CH_CONFIG_NEXT_ADDR_Pos) & DMA_CH_CONFIG_NEXT_ADDR_Msk);
}

/**
  * @brief   Установка последнего дескриптора
  * @param   Channel     Номер канала (0-31)
  * @param   State    	 Если бит установлен, канал остановится после передачи
  *                      всего буфера. Если нет, то следующая команда будет загружена
  *                      с адреса, указанного в поле NEXT_ADDR (ENABLE/DISABLE)
  * @retval  void
  */
__STATIC_INLINE void DMA_CH_LastDescrCmd(uint32_t Channel, FunctionalState State)
{

	WRITE_REG(DMA->CH[Channel].CONFIG_bit.CMD_LAST,State);
}

/**
  * @brief   Установка максимального количества байт для AXI read burst (RX)
  * @param   Channel     Номер канала (0-31)
  * @param   MaxBurst    Максимальное количество байт (1-64)
  * @retval  void
  */
__STATIC_INLINE void DMA_CH_SrcDataSizeConfig(uint32_t Channel, uint32_t MaxBurst)
{
    MODIFY_REG(DMA->CH[Channel].STATIC0, 
               DMA_CH_STATIC0_RD_BURST_MAX_Msk, 
               (MaxBurst << DMA_CH_STATIC0_RD_BURST_MAX_Pos) & DMA_CH_STATIC0_RD_BURST_MAX_Msk);
}

/**
  * @brief   Установка количества AXI read команд до освобождения шины
  * @param   Channel     Номер канала (0-31)
  * @param   Tokens      Количество команд (0-63)
  * @retval  void
  */
__STATIC_INLINE void DMA_CH_ReadTokensConfig(uint32_t Channel, uint32_t Tokens)
{
    MODIFY_REG(DMA->CH[Channel].STATIC0, 
               DMA_CH_STATIC0_RD_TOKENS_Msk, 
               (Tokens << DMA_CH_STATIC0_RD_TOKENS_Pos) & DMA_CH_STATIC0_RD_TOKENS_Msk);
}

/**
  * @brief   Установка максимального количества ожидающих AXI read команд
  * @param   Channel     Номер канала (0-31)
  * @param   MaxOuts     Максимальное количество команд (0-15)
  * @retval  void
  */
__STATIC_INLINE void DMA_CH_ReadOutstandingMaxConfig(uint32_t Channel, uint32_t MaxOuts)
{
    MODIFY_REG(DMA->CH[Channel].STATIC0, 
               DMA_CH_STATIC0_RD_OUTS_MAX_Msk, 
               (MaxOuts << DMA_CH_STATIC0_RD_OUTS_MAX_Pos) & DMA_CH_STATIC0_RD_OUTS_MAX_Msk);
}

/**
  * @brief   Включение конфигурации использования AXI read команд при полном FIFO
  * @param   Channel     Номер канала (0-31)
  * @param   State       Состояние (ENABLE/DISABLE)
  * @retval  void
  */
__STATIC_INLINE void DMA_CH_SetReadOutstandingCmd(uint32_t Channel, FunctionalState State)
{
    if (State == ENABLE)
    {
        SET_BIT(DMA->CH[Channel].STATIC0, DMA_CH_STATIC0_RD_OUTSTCFG_Msk);
    }
    else
    {
        CLEAR_BIT(DMA->CH[Channel].STATIC0, DMA_CH_STATIC0_RD_OUTSTCFG_Msk);
    }
}

/**
  * @brief   Установка инкремента адреса следующего burst
  * @param   Channel     Номер канала (0-31)
  * @param   State       Состояние (ENABLE/DISABLE)
  * @retval  void
  */
__STATIC_INLINE void DMA_CH_SrcDataIncConfig(uint32_t Channel, FunctionalState State)
{
    if (State == ENABLE)
    {
        SET_BIT(DMA->CH[Channel].STATIC0, DMA_CH_STATIC0_RD_INCR_Msk);
    }
    else
    {
        CLEAR_BIT(DMA->CH[Channel].STATIC0, DMA_CH_STATIC0_RD_INCR_Msk);
    }
}

/**
  * @brief   Установка максимального количества байт для AXI write burst (TX)
  * @param   Channel     Номер канала (0-31)
  * @param   MaxBurst    Максимальное количество байт (1-64)
  * @retval  void
  */
__STATIC_INLINE void DMA_CH_DstDataSizeConfig(uint32_t Channel, uint32_t MaxBurst)
{
    MODIFY_REG(DMA->CH[Channel].STATIC1, 
               DMA_CH_STATIC1_WR_BURST_MAX_Msk, 
               (MaxBurst << DMA_CH_STATIC1_WR_BURST_MAX_Pos) & DMA_CH_STATIC1_WR_BURST_MAX_Msk);
}

/**
  * @brief   Установка количества AXI write команд до освобождения шины
  * @param   Channel     Номер канала (0-31)
  * @param   Tokens      Количество команд (0-63)
  * @retval  void
  */
__STATIC_INLINE void DMA_CH_WriteTokensConfig(uint32_t Channel, uint32_t Tokens)
{
    MODIFY_REG(DMA->CH[Channel].STATIC1, 
               DMA_CH_STATIC1_WR_TOKENS_Msk, 
               (Tokens << DMA_CH_STATIC1_WR_TOKENS_Pos) & DMA_CH_STATIC1_WR_TOKENS_Msk);
}

/**
  * @brief   Установка максимального количества ожидающих AXI write команд
  * @param   Channel     Номер канала (0-31)
  * @param   MaxOuts     Максимальное количество команд (0-15)
  * @retval  void
  */
__STATIC_INLINE void DMA_CH_WriteOutstandingMaxConfig(uint32_t Channel, uint32_t MaxOuts)
{
    MODIFY_REG(DMA->CH[Channel].STATIC1, 
               DMA_CH_STATIC1_WR_OUTS_MAX_Msk, 
               (MaxOuts << DMA_CH_STATIC1_WR_OUTS_MAX_Pos) & DMA_CH_STATIC1_WR_OUTS_MAX_Msk);
}

/**
  * @brief   Включение конфигурации использования AXI write команд при полном FIFO
  * @param   Channel     Номер канала (0-31)
  * @param   State       Состояние (ENABLE/DISABLE)
  * @retval  void
  */
__STATIC_INLINE void DMA_CH_WriteOutstandingCmd(uint32_t Channel, FunctionalState State)
{
    if (State == ENABLE)
    {
        SET_BIT(DMA->CH[Channel].STATIC1, DMA_CH_STATIC1_WR_OUTSTCFG_Msk);
    }
    else
    {
        CLEAR_BIT(DMA->CH[Channel].STATIC1, DMA_CH_STATIC1_WR_OUTSTCFG_Msk);
    }
}

/**
  * @brief   Включение инкремента адреса следующего burst
  * @param   Channel     Номер канала (0-31)
  * @param   State       Состояние (ENABLE/DISABLE)
  * @retval  void
  */
__STATIC_INLINE void DMA_CH_DstDataIncConfig(uint32_t Channel, FunctionalState State)
{
    if (State == ENABLE)
    {
        SET_BIT(DMA->CH[Channel].STATIC1, DMA_CH_STATIC1_WR_INCR_Msk);
    }
    else
    {
        CLEAR_BIT(DMA->CH[Channel].STATIC1, DMA_CH_STATIC1_WR_INCR_Msk);
    }
}

/**
  * @brief   Установка ширины кадра для блочного режима
  * @param   Channel     Номер канала (0-31)
  * @param   FrameWidth  Ширина кадра (0-4095)
  * @retval  void
  */
__STATIC_INLINE void DMA_CH_FrameWidthConfig(uint32_t Channel, uint32_t FrameWidth)
{
    MODIFY_REG(DMA->CH[Channel].STATIC2, 
               DMA_CH_STATIC2_FRAME_WIDTH_Msk, 
               (FrameWidth << DMA_CH_STATIC2_FRAME_WIDTH_Pos) & DMA_CH_STATIC2_FRAME_WIDTH_Msk);
}

/**
  * @brief   Включение режима работы в блочном режиме
  * @param   Channel     Номер канала (0-31)
  * @param   State       Состояние (ENABLE/DISABLE)
  * @retval  void
  */
__STATIC_INLINE void DMA_CH_BlockModeCmd(uint32_t Channel, FunctionalState State)
{
    if (State == ENABLE)
    {
        SET_BIT(DMA->CH[Channel].STATIC2, DMA_CH_STATIC2_BLOCK_Msk);
    }
    else
    {
        CLEAR_BIT(DMA->CH[Channel].STATIC2, DMA_CH_STATIC2_BLOCK_Msk);
    }
}

/**
  * @brief   Включение режима совместной работы каналов
  * @param   Channel     Номер канала (0-31)
  * @param   State       Состояние (ENABLE/DISABLE)
  * @retval  void
  */
__STATIC_INLINE void DMA_CH_JointModeCmd(uint32_t Channel, FunctionalState State)
{
    if (State == ENABLE)
    {
        SET_BIT(DMA->CH[Channel].STATIC2, DMA_CH_STATIC2_JOINT_Msk);
    }
    else
    {
        CLEAR_BIT(DMA->CH[Channel].STATIC2, DMA_CH_STATIC2_JOINT_Msk);
    }
}

/**
  * @brief   Включение автоматического повтора передачи при переполнении/недополнении
  * @param   Channel     Номер канала (0-31)
  * @param   State       Состояние (ENABLE/DISABLE)
  * @retval  void
  */
__STATIC_INLINE void DMA_CH_RetryCmd(uint32_t Channel, FunctionalState State)
{
    if (State == ENABLE)
    {
        SET_BIT(DMA->CH[Channel].STATIC2, DMA_CH_STATIC2_RETRY_Msk);
    }
    else
    {
        CLEAR_BIT(DMA->CH[Channel].STATIC2, DMA_CH_STATIC2_RETRY_Msk);
    }
}

/**
  * @brief   Установка режима байтового обмена (endianness)
  * @param   Channel     Номер канала (0-31)
  * @param   EndSwapMode Режим байтового обмена (из DMA_CH_STATIC2_END_SWAP_Enum)
  * @retval  void
  */
__STATIC_INLINE void DMA_CH_EndSwapConfig(uint32_t Channel, uint32_t EndSwapMode)
{
    MODIFY_REG(DMA->CH[Channel].STATIC2, 
               DMA_CH_STATIC2_END_SWAP_Msk, 
               (EndSwapMode << DMA_CH_STATIC2_END_SWAP_Pos) & DMA_CH_STATIC2_END_SWAP_Msk);
}

/**
  * @brief   Установка максимального количества циклов ожидания для чтения
  * @param   Channel     Номер канала (0-31)
  * @param   WaitLimit   Максимальное количество циклов ожидания (0-4095)
  * @retval  void
  */
__STATIC_INLINE void DMA_CH_ReadWaitLimitConfig(uint32_t Channel, uint32_t WaitLimit)
{
    MODIFY_REG(DMA->CH[Channel].STATIC3, 
               DMA_CH_STATIC3_RD_WAIT_LIM_Msk, 
               (WaitLimit << DMA_CH_STATIC3_RD_WAIT_LIM_Pos) & DMA_CH_STATIC3_RD_WAIT_LIM_Msk);
}

/**
  * @brief   Установка максимального количества циклов ожидания для записи
  * @param   Channel     Номер канала (0-31)
  * @param   WaitLimit   Максимальное количество циклов ожидания (0-4095)
  * @retval  void
  */
__STATIC_INLINE void DMA_CH_WriteWaitLimitConfig(uint32_t Channel, uint32_t WaitLimit)
{
    MODIFY_REG(DMA->CH[Channel].STATIC3, 
               DMA_CH_STATIC3_WR_WAIT_LIM_Msk, 
               (WaitLimit << DMA_CH_STATIC3_WR_WAIT_LIM_Pos) & DMA_CH_STATIC3_WR_WAIT_LIM_Msk);
}

/**
  * @brief   Установка номера периферийного устройства для чтения
  * @param   Channel     Номер канала (0-31)
  * @param   PerNum      Номер периферийного устройства (0-127)
  * @retval  void
  */
__STATIC_INLINE void DMA_CH_ReadPeripheralNumConfig(uint32_t Channel, uint32_t PerNum)
{
    MODIFY_REG(DMA->CH[Channel].STATIC4, 
               DMA_CH_STATIC4_RD_PER_NUM_Msk, 
               (PerNum << DMA_CH_STATIC4_RD_PER_NUM_Pos) & DMA_CH_STATIC4_RD_PER_NUM_Msk);
}

/**
  * @brief   Установка задержки периферии для операции чтения AXI
  * @param   Channel     Номер канала (0-31)
  * @param   Delay       Задержка (0-7)
  * @retval  void
  */
__STATIC_INLINE void DMA_CH_ReadPeripheralDelayConfig(uint32_t Channel, uint32_t Delay)
{
    MODIFY_REG(DMA->CH[Channel].STATIC4, 
               DMA_CH_STATIC4_RD_PER_DELAY_Msk, 
               (Delay << DMA_CH_STATIC4_RD_PER_DELAY_Pos) & DMA_CH_STATIC4_RD_PER_DELAY_Msk);
}

/**
  * @brief   Установка блочного режима управления периферией для чтения
  * @param   Channel     Номер канала (0-31)
  * @param   State       Состояние (ENABLE/DISABLE)
  * @retval  void
  */
__STATIC_INLINE void DMA_CH_ReadPeripheralBlockConfig(uint32_t Channel, FunctionalState State)
{
    if (State == ENABLE)
    {
        SET_BIT(DMA->CH[Channel].STATIC4, DMA_CH_STATIC4_RD_PER_BLOCK_Msk);
    }
    else
    {
        CLEAR_BIT(DMA->CH[Channel].STATIC4, DMA_CH_STATIC4_RD_PER_BLOCK_Msk);
    }
}

/**
  * @brief   Установка номера периферийного устройства для записи
  * @param   Channel     Номер канала (0-31)
  * @param   PerNum      Номер периферийного устройства (0-127)
  * @retval  void
  */
__STATIC_INLINE void DMA_CH_WritePeripheralNumConfig(uint32_t Channel, uint32_t PerNum)
{
    MODIFY_REG(DMA->CH[Channel].STATIC4, 
               DMA_CH_STATIC4_WR_PER_NUM_Msk, 
               (PerNum << DMA_CH_STATIC4_WR_PER_NUM_Pos) & DMA_CH_STATIC4_WR_PER_NUM_Msk);
}

/**
  * @brief   Установка задержки периферии для операции записи AXI
  * @param   Channel     Номер канала (0-31)
  * @param   Delay       Задержка (0-7)
  * @retval  void
  */
__STATIC_INLINE void DMA_CH_WritePeripheralDelayConfig(uint32_t Channel, uint32_t Delay)
{
    MODIFY_REG(DMA->CH[Channel].STATIC4, 
               DMA_CH_STATIC4_WR_PER_DELAY_Msk, 
               (Delay << DMA_CH_STATIC4_WR_PER_DELAY_Pos) & DMA_CH_STATIC4_WR_PER_DELAY_Msk);
}

/**
  * @brief   Установка блочного режима управления периферией для записи
  * @param   Channel     Номер канала (0-31)
  * @param   State       Состояние (ENABLE/DISABLE)
  * @retval  void
  */
__STATIC_INLINE void DMA_CH_WritePeripheralBlockConfig(uint32_t Channel, FunctionalState State)
{
    if (State == ENABLE)
    {
        SET_BIT(DMA->CH[Channel].STATIC4, DMA_CH_STATIC4_WR_PER_BLOCK_Msk);
    }
    else
    {
        CLEAR_BIT(DMA->CH[Channel].STATIC4, DMA_CH_STATIC4_WR_PER_BLOCK_Msk);
    }
}




/**
  * @brief   Получение состояния ограничения размера burst для чтения
  * @param   Channel     Номер канала (0-31)
  * @retval  Состояние (SET/RESET)
  */
__STATIC_INLINE FlagStatus DMA_CH_RESTRICT_GetReadAllowFifo(uint32_t Channel)
{
    return (READ_BIT(DMA->CH[Channel].RESTRICT, DMA_CH_RESTRICT_RD_ALLOWFIFO_Msk) ? SET : CLEAR);
}

/**
  * @brief   Получение состояния ограничения размера burst для записи
  * @param   Channel     Номер канала (0-31)
  * @retval  Состояние (SET/RESET)
  */
__STATIC_INLINE FlagStatus DMA_CH_RESTRICT_GetWriteAllowFifo(uint32_t Channel)
{
    return (READ_BIT(DMA->CH[Channel].RESTRICT, DMA_CH_RESTRICT_WR_ALLOWFIFO_Msk) ? SET : CLEAR);
}

/**
  * @brief   Получение возможности равенства размера burst размеру буфера данных
  * @param   Channel     Номер канала (0-31)
  * @retval  Состояние (SET/RESET)
  */
__STATIC_INLINE FlagStatus DMA_CH_RESTRICT_GetAllowFifo(uint32_t Channel)
{
    return (READ_BIT(DMA->CH[Channel].RESTRICT, DMA_CH_RESTRICT_ALLOW_FIFO_Msk) ? SET : CLEAR);
}

/**
  * @brief   Получение возможности использования максимальных burst из 16 стробов
  * @param   Channel     Номер канала (0-31)
  * @retval  Состояние (SET/RESET)
  */
__STATIC_INLINE FlagStatus DMA_CH_RESTRICT_GetAllowFullBurst(uint32_t Channel)
{
    return (READ_BIT(DMA->CH[Channel].RESTRICT, DMA_CH_RESTRICT_ALLOW_FBURST_Msk) ? SET : CLEAR);
}

/**
  * @brief   Получение активности совместных burst
  * @param   Channel     Номер канала (0-31)
  * @retval  Состояние (SET/RESET)
  */
__STATIC_INLINE FlagStatus DMA_CH_RESTRICT_GetAllowJointBurst(uint32_t Channel)
{
    return (READ_BIT(DMA->CH[Channel].RESTRICT, DMA_CH_RESTRICT_ALLOW_JBURST_Msk) ? SET : CLEAR);
}

/**
  * @brief   Получение активности ожидающих операций чтения
  * @param   Channel     Номер канала (0-31)
  * @retval  Состояние (SET/RESET)
  */
__STATIC_INLINE FlagStatus DMA_CH_RESTRICT_GetReadOutstanding(uint32_t Channel)
{
    return (READ_BIT(DMA->CH[Channel].RESTRICT, DMA_CH_RESTRICT_RD_OUTSTAND_Msk) ? SET : CLEAR);
}

/**
  * @brief   Получение активности ожидающих операций записи
  * @param   Channel     Номер канала (0-31)
  * @retval  Состояние (SET/RESET)
  */
__STATIC_INLINE FlagStatus DMA_CH_RESTRICT_GetWriteOutstanding(uint32_t Channel)
{
    return (READ_BIT(DMA->CH[Channel].RESTRICT, DMA_CH_RESTRICT_WR_OUTSTAND_Msk) ? SET : CLEAR);
}

/**
  * @brief   Получение состояния выравнивания конфигурации блока
  * @param   Channel     Номер канала (0-31)
  * @retval  Состояние (SET/RESET)
  */
__STATIC_INLINE FlagStatus DMA_CH_RESTRICT_GetNonAligned(uint32_t Channel)
{
    return (READ_BIT(DMA->CH[Channel].RESTRICT, DMA_CH_RESTRICT_NONALIGN_Msk) ? SET : CLEAR);
}

/**
  * @brief   Получение простого состояния конфигурации
  * @param   Channel     Номер канала (0-31)
  * @retval  Состояние (SET/RESET)
  */
__STATIC_INLINE FlagStatus DMA_CH_RESTRICT_GetSimpleStatus(uint32_t Channel)
{
    return (READ_BIT(DMA->CH[Channel].RESTRICT, DMA_CH_RESTRICT_SIMPLE_STAT_Msk) ? SET : CLEAR);
}




/**
  * @brief   Получение смещения чтения от начала буфера
  * @param   Channel     Номер канала (0-31)
  * @retval  Смещение чтения
  */
__STATIC_INLINE uint32_t DMA_CH_GetReadOffset(uint32_t Channel)
{
    return (READ_REG(DMA->CH[Channel].RDOFFSET) & DMA_CH_RDOFFSET_RD_OFFSET_Msk) >> DMA_CH_RDOFFSET_RD_OFFSET_Pos;
}

/**
  * @brief   Получение смещения записи от начала буфера
  * @param   Channel     Номер канала (0-31)
  * @retval  Смещение записи
  */
__STATIC_INLINE uint32_t DMA_CH_GetWriteOffset(uint32_t Channel)
{
    return (READ_REG(DMA->CH[Channel].WROFFSET) & DMA_CH_WROFFSET_WR_OFFSET_Msk) >> DMA_CH_WROFFSET_WR_OFFSET_Pos;
}

/**
  * @brief   Получение оставшегося места в FIFO для данных чтения
  * @param   Channel     Номер канала (0-31)
  * @retval  Оставшееся место в FIFO
  */
__STATIC_INLINE uint32_t DMA_CH_GetReadGap(uint32_t Channel)
{
    return (READ_REG(DMA->CH[Channel].FIFOSTAT) & DMA_CH_FIFOSTAT_RD_GAP_Msk) >> DMA_CH_FIFOSTAT_RD_GAP_Pos;
}

/**
  * @brief   Получение занятого места в FIFO для данных записи
  * @param   Channel     Номер канала (0-31)
  * @retval  Занятое место в FIFO
  */
__STATIC_INLINE uint32_t DMA_CH_GetWriteFullness(uint32_t Channel)
{
    return (READ_REG(DMA->CH[Channel].FIFOSTAT) & DMA_CH_FIFOSTAT_WR_FULLNESS_Msk) >> DMA_CH_FIFOSTAT_WR_FULLNESS_Pos;
}

/**
  * @brief   Получение количества ожидающих AXI команд чтения
  * @param   Channel     Номер канала (0-31)
  * @retval  Количество ожидающих команд чтения
  */
__STATIC_INLINE uint32_t DMA_CH_GetReadCmdOutstanding(uint32_t Channel)
{
    return (READ_REG(DMA->CH[Channel].CMD_OUTS) & DMA_CH_CMD_OUTS_RD_CMD_OUTS_Msk) >> DMA_CH_CMD_OUTS_RD_CMD_OUTS_Pos;
}

/**
  * @brief   Получение количества ожидающих AXI команд записи
  * @param   Channel     Номер канала (0-31)
  * @retval  Количество ожидающих команд записи
  */
__STATIC_INLINE uint32_t DMA_CH_GetWriteCmdOutstanding(uint32_t Channel)
{
    return (READ_REG(DMA->CH[Channel].CMD_OUTS) & DMA_CH_CMD_OUTS_WR_CMD_OUTS_Msk) >> DMA_CH_CMD_OUTS_WR_CMD_OUTS_Pos;
}

/**
  * @brief   Установка состояния активности канала
  * @param   Channel     Номер канала (0-31)
  * @param   State       Состояние (ENABLE/DISABLE)
  * @retval  void
  */
__STATIC_INLINE void DMA_CH_ActiveCmd(uint32_t Channel, FunctionalState State)
{
    if (State == ENABLE)
    {
        SET_BIT(DMA->CH[Channel].CH_ACTIVE, DMA_CH_CH_ACTIVE_CH_ACTIVE_Msk);
    }
    else
    {
        CLEAR_BIT(DMA->CH[Channel].CH_ACTIVE, DMA_CH_CH_ACTIVE_CH_ACTIVE_Msk);
    }
}

/**
  * @brief   Получение состояния активности канала
  * @param   Channel     Номер канала (0-31)
  * @retval  Состояние активности (SET/RESET)
  */
__STATIC_INLINE FlagStatus DMA_CH_GetActive(uint32_t Channel)
{
    return (READ_BIT(DMA->CH[Channel].CH_ACTIVE, DMA_CH_CH_ACTIVE_CH_ACTIVE_Msk) ? SET : CLEAR);
}

/**
  * @brief   Запуск канала DMA
  * @param   Channel     Номер канала (0-31)
  * @retval  void
  */
__STATIC_INLINE void DMA_CH_StartCmd(uint32_t Channel)
{
    SET_BIT(DMA->CH[Channel].CH_START, DMA_CH_CH_START_CH_START_Msk);
}


/**
  * @brief   Получение состояния активности чтения на шине AXI
  * @param   Channel     Номер канала (0-31)
  * @retval  Состояние (SET/RESET)
  */
__STATIC_INLINE FlagStatus DMA_CH_GetReadActive(uint32_t Channel)
{
    return (READ_BIT(DMA->CH[Channel].CH_STATUS, DMA_CH_CH_STATUS_CH_RD_ACTIVE_Msk) ? SET : CLEAR);
}

/**
  * @brief   Получение состояния активности записи на шине AXI
  * @param   Channel     Номер канала (0-31)
  * @retval  Состояние (SET/RESET)
  */
__STATIC_INLINE FlagStatus DMA_CH_GetWriteActive(uint32_t Channel)
{
    return (READ_BIT(DMA->CH[Channel].CH_STATUS, DMA_CH_CH_STATUS_CH_WR_ACTIVE_Msk) ? SET : CLEAR);
}

/**
  * @brief   Получение количества переданных буферов
  * @param   Channel     Номер канала (0-31)
  * @retval  Количество переданных буферов
  */
__STATIC_INLINE uint32_t DMA_CH_GetBufferCount(uint32_t Channel)
{
    return (READ_REG(DMA->CH[Channel].COUNT) & DMA_CH_COUNT_BUFF_COUNT_Msk) >> DMA_CH_COUNT_BUFF_COUNT_Pos;
}

/**
  * @brief   Получение количества необслуженных прерываний окончания
  * @param   Channel     Номер канала (0-31)
  * @retval  Количество необслуженных прерываний
  */
__STATIC_INLINE uint32_t DMA_CH_GetInterruptCount(uint32_t Channel)
{
    return (READ_REG(DMA->CH[Channel].COUNT) & DMA_CH_COUNT_INT_COUNT_Msk) >> DMA_CH_COUNT_INT_COUNT_Pos;
}

/**
  * @}
  */

/** @defgroup DMA_Exported_Functions_Status Статусная информация
  * @{
  */



/**
  * @}
  */

/** @defgroup DMA_Exported_Functions_Interrupt Прерывания
  * @{
  */



/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __PLIB5T_DMA_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2026 NIIET *****END OF FILE****/
