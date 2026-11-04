/**
  ******************************************************************************
  * @file    plib5t_can.c
  *
  * @brief   Файл содержит реализацию функций для работы с CAN
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
#include <plib5t_can.h>

/** @addtogroup Peripheral
  * @{
  */

/** @addtogroup CAN
  * @{
  */

/** @defgroup CAN_Private Приватные данные
  * @{
  */

/** @defgroup CAN_Private_Defines Приватные константы
  * @{
  */

/**
  * @}
  */

/** @defgroup CAN_Private_Functions Приватные функции
  * @{
  */

/**
  * @brief   Инициализирует CAN согласно параметрам структуры InitStruct.
  * @param   InitStruct  Указатель на структуру типа @ref CAN_Init_TypeDef,
  *                      которая содержит конфигурационную информацию.
  * @retval  Status  Статус результата инициализации
  */
void CAN_Init(CAN_Init_TypeDef* InitStruct)
{

}

/**
  * @brief   Инициализирует узел CAN согласно параметрам структуры InitStruct.
  * @param   NODEx   Выбор узла CAN, где x=0|1  
  * @param   InitStruct  Указатель на структуру типа @ref CAN_NODE_Init_TypeDef,
  *                      которая содержит конфигурационную информацию.
  * @retval  Status  Статус результата инициализации
  */
void CAN_NODE_Init(uint8_t NODEx, CAN_NODE_Init_TypeDef* InitStruct)
{

}

/**
  * @brief   Конфигурирует команду работы со списками согласно параметрам структуры InitStruct.
  * @param   InitStruct  Указатель на структуру типа @ref CAN_PANELCMD_Init_TypeDef,
  *                      которая содержит конфигурационную информацию.
  * @retval  Status  Статус результата инициализации
  */
void CAN_PANELCMD_Config(CAN_PANELCMD_Init_TypeDef* InitStruct)
{
	assert_param(IS_GET_CAN_PANELCMD(InitStruct->PanelCommand));

    CAN->PANCTR = (InitStruct->PanelCommand << CAN_PANCTR_PANCMD_Pos) |
                  (InitStruct->Arg1 << CAN_PANCTR_PANAR1_Pos) |
                  (InitStruct->Arg2 << CAN_PANCTR_PANAR2_Pos);
}

/**
  * @brief   Инициализирует список CAN согласно параметрам структуры InitStruct.
  * @param   NODEx   Выбор списка CAN, где x=0|1
  * @param   InitStruct  Указатель на структуру типа @ref CAN_LIST_Init_TypeDef,
  *                      которая содержит конфигурационную информацию.
  * @retval  Status  Статус результата инициализации
  */
void CAN_LIST_Init(uint8_t LISTx, CAN_LIST_Init_TypeDef* InitStruct)
{
    unsigned int x;
    CAN_PANELCMD_Init_TypeDef CmdStruct;
	assert_param(IS_GET_CAN_LIST(LISTx));
    assert_param(IS_GET_CAN_MSG(InitStruct->MsgLo));
    assert_param(IS_GET_CAN_MSG(InitStruct->MsgHi));

    for (x = InitStruct->MsgFirst; x <= InitStruct->MsgLast; x++) {
        // PANCMD_field=0x02-static location objects to one of the CAN-lists
    	CmdStruct.PanelCommand = CAN_PanelCmd_ListStaticAdd;
    	CmdStruct.Arg1 = x;
    	CmdStruct.Arg2 = LISTx;
    	CAN_PANELCMD_Config(&CmdStruct);
        while (CAN_PANELCMD_FlagStatus(CAN_PanelCmdState_Busy) | CAN_PANELCMD_FlagStatus(CAN_PanelCmdState_RBusy)) {
        };
    }
}

/**
  * @brief   Инициализирует объект сообщения CAN согласно параметрам структуры InitStruct.
  * @param   MSGx   Выбор объекта сообщения CAN, где x от 0 до 127
  * @param   InitStruct  Указатель на структуру типа @ref CAN_MSG_Init_TypeDef,
  *                      которая содержит конфигурационную информацию.
  * @retval  Status  Статус результата инициализации
  */
void CAN_MSG_Init(uint8_t MSGx, CAN_MSG_Init_TypeDef* InitStruct)
{
	assert_param(IS_GET_CAN_MSG(MSGx));
	assert_param(IS_CAN_MSG_DIR_BIT(InitStruct->MsgDir));

	if(InitStruct->MsgDir == CAN_MSG_Dir_Tx)
	{
        if (InitStruct->MsgMode == CAN_MSG_Mode_Standart)
        {
        	CAN_Msg_FlagConfig(MSGx,(CAN_Msg_Flag_Direction|CAN_Msg_Flag_TxEnable0|CAN_Msg_Flag_TxEnable1), 0);
        }
        	else if(InitStruct->MsgMode == CAN_MSG_Mode_RemoteReqest)
        	{
        		CAN_Msg_FlagConfig(MSGx,(CAN_Msg_Flag_TxEnable0|CAN_Msg_Flag_TxEnable1), CAN_Msg_Flag_Direction);
        	}
	}
		else if(InitStruct->MsgDir == CAN_MSG_Dir_Rx)
		{
			if (InitStruct->MsgMode == CAN_MSG_Mode_Standart)
			{
				CAN_Msg_FlagConfig(MSGx,CAN_Msg_Flag_RxEnable, CAN_Msg_Flag_Direction);
			}
				else if(InitStruct->MsgMode == CAN_MSG_Mode_RemoteReqest)
				{
					CAN_Msg_FlagConfig(MSGx,(CAN_Msg_Flag_Direction | CAN_Msg_Flag_RxEnable), 0);
				}
		}
}

/**
  * @brief   Инициализирует передачу объекта сообщения CAN.
  * @param   MSGx   Выбор объекта сообщения CAN, где x от 0 до 127
  * @retval  void
  */
void CAN_MSG_StartTransmit(uint8_t MSGx)
{
	assert_param(IS_GET_CAN_MSG(MSGx));

	CAN_Msg_FlagConfig(MSGx,(CAN_Msg_Flag_TxRemoteReqest | CAN_Msg_Flag_Active), 0);
}

/**
  * @brief   Инициализирует прием объекта сообщения CAN.
  * @param   MSGx   Выбор объекта сообщения CAN, где x от 0 до 127
  * @retval  void
  */
void CAN_MSG_StartReceive(uint8_t MSGx)
{
	assert_param(IS_GET_CAN_MSG(MSGx));

	CAN_Msg_FlagConfig(MSGx,CAN_Msg_Flag_Active, 0);
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

/******************* (C) COPYRIGHT 2026 NIIET *****END OF FILE****/
