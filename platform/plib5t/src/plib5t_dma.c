/**
  ******************************************************************************
  * @file    plib5t_dma.c
  *
  * @brief   Файл содержит реализацию функций для работы с DMA
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

/* Includes ------------------------------------------------------------------*/
#include "plib5t_dma.h"

/** @addtogroup Peripheral
  * @{
  */

/** @addtogroup DMA
  * @{
  */

/** @defgroup DMA_Private Приватные данные
  * @{
  */

/** @defgroup DMA_Private_Defines Приватные константы
  * @{
  */

/**
  * @}
  */

/** @defgroup DMA_Private_Functions Приватные функции
  * @{
  */

/**
  * @brief   Деинициализация канала DMA
  * @param   ChannelStruct  Указатель на структуру типа @ref DMA_Channel_TypeDef,
  *                         которая содержит конфигурационную информацию канала
  * @retval  void
  */
void DMA_ChannelDeInit(DMA_ChannelInit_TypeDef* ChannelInitStruct)
{
    ChannelInitStruct->SrcDataPtr = 0;
    ChannelInitStruct->DstDataPtr = 0;
    ChannelInitStruct->NextDescrPtr = 0;
    ChannelInitStruct->BytesTotal = 0;
}

/**
  * @brief   Инициализация канала DMA
  * @param   ChannelStruct Непосредственно сама структура канала
  * @param   ChannelInitStruct  Указатель на структуру типа @ref DMA_ChannelInit_TypeDef,
  *                             которая содержит конфигурационную информацию канала
  * @retval  void
  */
void DMA_ChannelInit(uint32_t Channel, DMA_ChannelInit_TypeDef* ChannelInitStruct)
{
    assert_param(IS_DMA_DATA_SIZE(ChannelInitStruct->SrcDataSize));
    assert_param(IS_DMA_DATA_SIZE(ChannelInitStruct->DstDataSize));
    assert_param(IS_DMA_TRANSFERS_TOTAL(ChannelInitStruct->BytesTotal));

    /* Источник */
    DMA_CH_SrcPtrConfig(Channel, (uint32_t)ChannelInitStruct->SrcDataPtr);
    DMA_CH_SrcDataSizeConfig(Channel, ChannelInitStruct->SrcDataSize);
    DMA_CH_SrcDataIncConfig(Channel, ChannelInitStruct->SrcDataInc);
    DMA_CH_ReadPeripheralNumConfig(Channel, ChannelInitStruct->SrcReqest);
    /* Приёмник */
    DMA_CH_DstPtrConfig(Channel, (uint32_t)ChannelInitStruct->DstDataPtr);
    DMA_CH_DstDataSizeConfig(Channel, ChannelInitStruct->DstDataSize);
    DMA_CH_DstDataIncConfig(Channel, ChannelInitStruct->DstDataInc);
    DMA_CH_WritePeripheralNumConfig(Channel, ChannelInitStruct->DstReqest);
    /* Дескриптор */
    DMA_CH_NextAddressConfig(Channel, (uint32_t)ChannelInitStruct->NextDescrPtr);
    DMA_CH_LastDescrCmd(Channel, ChannelInitStruct->LastDescr);
    DMA_CH_DataSizeConfig(Channel, ChannelInitStruct->BytesTotal);
}

/**
  * @brief   Заполнение каждого члена структуры ChannelInitStruct значениями по умолчанию
  * @param   ChannelInitStruct  Указатель на структуру типа @ref DMA_ChannelInit_TypeDef,
  *                             которую необходимо проинициализировать
  * @retval  void
  */
void DMA_ChannelStructInit(DMA_ChannelInit_TypeDef* ChannelInitStruct)
{
    /* источник */
    ChannelInitStruct->SrcDataPtr = (uint32_t*)0x00000000;
    ChannelInitStruct->SrcDataSize = DMA_DataSize_8;
    ChannelInitStruct->SrcDataInc = DISABLE;
    ChannelInitStruct->SrcReqest = DMA_Request_Memory;
    /* приемник */
    ChannelInitStruct->DstDataPtr = (uint32_t*)0x00000000;
    ChannelInitStruct->DstDataSize = DMA_DataSize_8;
    ChannelInitStruct->DstDataInc = DISABLE;
    ChannelInitStruct->DstReqest = DMA_Request_Memory;
    /* общее */
    ChannelInitStruct->NextDescrPtr = (uint32_t*)0x00000000;
    ChannelInitStruct->LastDescr = ENABLE;
    ChannelInitStruct->InterruptEnable = DISABLE;
    ChannelInitStruct->BytesTotal = 1;
}

/**
  * @brief   Деинициализация контроллера DMA
  * @retval  void
  */
void DMA_DeInit()
{
    CLEAR_REG(DMA->CH_START);
    CLEAR_REG(DMA->CH_ENABLE);
    CLEAR_REG(DMA->CONTROL);
}

/**
  * @brief  Инициализация контроллера DMA
  * @attention  Прежде чем инициализировать DMA, необходимо проинициализоровать каналы
  *             с помощью @ref DMA_ChannelInit и сконфигурировать базовый адрес управляющей структуры
  *             с помощью @ref DMA_BasePtrConfig
  * @param   InitStruct  Указатель на структуру типа @ref DMA_Init_TypeDef,
  *                      которая содержит конфигурационную информацию
  * @retval  void
  */
void DMA_Init(DMA_Init_TypeDef* InitStruct)
{
    DMA_RxHighPriorityCmd(InitStruct->Channel, InitStruct->RxHighPriority);
    DMA_TxHighPriorityCmd(InitStruct->Channel, InitStruct->TxHighPriority);
    DMA_ChannelEnableCmd(InitStruct->Channel, InitStruct->ChannelEnable);
}

/**
  * @brief   Заполнение каждого члена структуры DMA_InitStruct значениями по умолчанию
  * @param   InitStruct  Указатель на структуру типа @ref DMA_Init_TypeDef,
  *                      которую необходимо проинициализировать
  * @retval  void
  */
void DMA_StructInit(DMA_Init_TypeDef* InitStruct)
{
    InitStruct->Channel = DMA_Channel_MSK_All;
    InitStruct->ChannelEnable = DISABLE;
    InitStruct->RxHighPriority = DISABLE;
    InitStruct->TxHighPriority = DISABLE;

}

/**
  * @brief   Программный запрос приема DMA по выбранному источнику запроса
  * @param   SrcRequest Выбор источника запроса.
  *                   	Параметр принимает любую комбинацию масок DMA_Channel_x из @ref DMA_Channel_Define.
  * @retval  void
  */
void DMA_SwRxRequestCmd(DMA_Request_TypeDef SrcRequest)
{
	uint32_t *reg_ptr;
	uint32_t src_temp;

	assert_param(IS_DMA_SOURCE(SrcRequest));

	src_temp = (uint32_t)SrcRequest;
	reg_ptr = (uint32_t*)DMA->PER_RX0_CTRL;

    WRITE_REG(*reg_ptr, (1 << src_temp));
}

/**
  * @brief   Программный запрос передачи DMA по выбранному источнику запроса
  * @param   SrcRequest Выбор источника запроса.
  *                   	Параметр принимает любую комбинацию масок DMA_Channel_x из @ref DMA_Channel_Define.
  * @retval  void
  */
void DMA_SwTxRequestCmd(DMA_Request_TypeDef SrcRequest)
{
	uint32_t *reg_ptr;
	uint32_t src_temp;

	assert_param(IS_DMA_SOURCE(SrcRequest));

	src_temp = (uint32_t)SrcRequest;
	reg_ptr = (uint32_t *)DMA->PER_TX0_CTRL;

    WRITE_REG(*reg_ptr, (1 << src_temp));
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

/******************* (C) COPYRIGHT 2024 NIIET *****END OF FILE****/
