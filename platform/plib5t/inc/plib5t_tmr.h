/**
  ******************************************************************************
  * @file    plib5t_tmr.h
  *
  * @brief   Файл содержит прототипы и компактные inline реализации функций для
  *          TMR, а также сопутствующие макроопределения и перечисления
  *
  * @author  НИИЭТ, Александр Дыхно <dykhno@niiet.ru>
  * @author  НИИЭТ, Штоколов Филипп
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
#ifndef __PLIB5T_TMR_H
#define __PLIB5T_TMR_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "plib5t.h"

/** @addtogroup Peripheral
  * @{
  */

/** @defgroup TMR
  * @brief Драйвер для работы с TMR
  * @{
  */

/** @defgroup TMR_Exported_Defines Константы
  * @{
  */

/**
  * @}
  */

/** @defgroup TMR_Exported_Types Типы
  * @{
  */

/**
  * @brief  Настройка способа счёта таймера
  */
typedef enum {
    TMR_Mode_Stop = TMR_CTRL_MODE_Stop,             /*!< Свободный счёт */
    TMR_Mode_Capcom_Up = TMR_CTRL_MODE_Up,                 /*!< Счёт вверх */
    TMR_Mode_Multiple = TMR_CTRL_MODE_Multiple, 	/*!< Непрерывный счёт */
    TMR_Mode_Capcom_UpDown = TMR_CTRL_MODE_UpDown,         /*!< Счёт вверх/вниз */
} TMR_Mode_TypeDef;
#define IS_TMR_MODE(VALUE) (((VALUE) == TMR_Mode_Stop) || \
                              ((VALUE) == TMR_Mode_Up) || \
                              ((VALUE) == TMR_Mode_Multiple) || \
                              ((VALUE) == TMR_Mode_UpDown))

/**
  * @brief  Выбор источника тактированного сигнала
  */
typedef enum {
	TMR_Clksel_SysClk = TMR_CTRL_CLKSEL_SysClk,	/*!< Тактовый сигнал SYSCLK */
	TMR_Clksel_ExtClk = TMR_CTRL_CLKSEL_ExtClk, /*!< Внешний источник синхронизации */
} TMR_Clksel_TypeDef;
#define IS_TMR_CLKSEL(VALUE) (((VALUE) == TMR_CTRL_CLKSEL_SysClk) || \
                              ((VALUE) == TMR_CTRL_CLKSEL_ExtClk))

/**
  * @brief  Настройка режима захвата
  */
typedef enum {
    TMR_CAPCOM_Mode_None =  0,//TMR_CAPCOM_CTRL_CAPMODE_None,     /*!< Нет захвата */
    TMR_CAPCOM_Mode_Raise,// = TMR_CAPCOM_CTRL_CAPMODE_Raise,    /*!< Захват по переднему фронту */
    TMR_CAPCOM_Mode_Fail, //=  TMR_CAPCOM_CTRL_CAPMODE_Fail,     /*!< Захват по заднему фронту */
    TMR_CAPCOM_Mode_Edge //=  TMR_CAPCOM_CTRL_CAPMODE_Edge,     /*!< Захват по обоим фронтам */
} TMR_CAPCOM_Mode_TypeDef;
#define IS_TMR_CAPCOM_MODE(VALUE) (((VALUE) == TMR_CAPCOM_Mode_None) ||  \
                                  ((VALUE) == TMR_CAPCOM_Mode_Raise) || \
                                  ((VALUE) == TMR_CAPCOM_Mode_Fail)  || \
								  ((VALUE) == TMR_CAPCOM_Mode_Edge))

/**
  * @brief  Настройка режима выхода CAPCOM
  */
typedef enum {
    TMR_CAPCOM_OutMode_BitOUT,// = TMR_CAPCOM_CTRL_OUTMODE_BitOUT,     		/*!< Выход правляется значение бита OUT */
    TMR_CAPCOM_OutMode_Set,// = TMR_CAPCOM_CTRL_OUTMODE_Set,           		/*!< установка (Set) */
    TMR_CAPCOM_OutMode_Toggle_Reset,// = TMR_CAPCOM_CTRL_OUTMODE_Toggle_Reset, /*!< переключение/сброс (Toggle/Reset) */
    TMR_CAPCOM_OutMode_Set_Reset,// = TMR_CAPCOM_CTRL_OUTMODE_Set_Reset,     	/*!< установка/сброс (Set/Reset) */
    TMR_CAPCOM_OutMode_Toggle,// = TMR_CAPCOM_CTRL_OUTMODE_Toggle,        		/*!< переключение (Toggle) */
    TMR_CAPCOM_OutMode_Reset,// = TMR_CAPCOM_CTRL_OUTMODE_Reset,         		/*!< сброс (Reset) */
    TMR_CAPCOM_OutMode_Toggle_Set,// = TMR_CAPCOM_CTRL_OUTMODE_Toggle_Set,    	/*!< переключение/установка (Toggle/Set) */
    TMR_CAPCOM_OutMode_Reset_Set,// = TMR_CAPCOM_CTRL_OUTMODE_Reset_Set,     	/*!< сброс/установка (Reset/Set) */

} TMR_CAPCOM_OutMode_TypeDef;
#define IS_TMR_CAPCOM_OUTMODE(VALUE) (((VALUE) == TMR_CAPCOM_OutMode_BitOUT) ||  \
                                  ((VALUE) == TMR_CAPCOM_OutMode_Set) || \
                                  ((VALUE) == TMR_CAPCOM_OutMode_Toggle_Reset) || \
                                  ((VALUE) == TMR_CAPCOM_OutMode_Set_Reset) || \
                                  ((VALUE) == TMR_CAPCOM_OutMode_Toggle) || \
                                  ((VALUE) == TMR_CAPCOM_OutMode_Reset) || \
                                  ((VALUE) == TMR_CAPCOM_OutMode_Toggle_Set) || \
                                  ((VALUE) == TMR_CAPCOM_OutMode_Reset_Set))

/**
  * @brief  Конфигурируемые регистры захвата/сравнения
  */
typedef enum {
	TMR_CAPCOM_0,
	TMR_CAPCOM_1,
	TMR_CAPCOM_2,
	TMR_CAPCOM_3
} TMR_CAPCOM_Num_TypeDef;
#define IS_TMR_CAPCOM_NUM(VALUE) (((VALUE) == TMR_CAPCOM_0) || \
                              ((VALUE) == TMR_CAPCOM_1) || \
                              ((VALUE) == TMR_CAPCOM_2) || \
                              ((VALUE) == TMR_CAPCOM_3))

/**
  * @brief  Поля для регистров прерывания блока TMR
  */
typedef enum {
	TMR_IT_TimerUpdate	= 0x1,
	TMR_IT_CAPCOM_0		= 0x2,
	TMR_IT_CAPCOM_1		= 0x4,
	TMR_IT_CAPCOM_2		= 0x8,
	TMR_IT_CAPCOM_3		= 0x10
} TMR_IT_TypeDef;
#define IS_TMR_IT(VALUE) (((VALUE) == TMR_IT_TimerUpdate) || \
                              ((VALUE) == TMR_IT_CAPCOM_0) || \
                              ((VALUE) == TMR_IT_CAPCOM_1) || \
                              ((VALUE) == TMR_IT_CAPCOM_2) || \
							  ((VALUE) == TMR_IT_CAPCOM_3))

/**
  * @brief  Поля для регистров формирования запросов блока TMR
  */
typedef enum {
	TMR_REQ_TimerUpdate	= 0x1,
	TMR_REQ_CAPCOM_0 		= 0x2,
	TMR_REQ_CAPCOM_1 		= 0x4,
	TMR_REQ_CAPCOM_2 		= 0x8,
	TMR_REQ_CAPCOM_3 		= 0x10
} TMR_REQ_TypeDef;
#define IS_TMR_REQ(VALUE) (((VALUE) == TMR_REQ_TimerUpdate) || \
                              ((VALUE) == TMR_REQ_CAPCOM_0) || \
                              ((VALUE) == TMR_REQ_CAPCOM_1) || \
                              ((VALUE) == TMR_REQ_CAPCOM_2) || \
							  ((VALUE) == TMR_REQ_CAPCOM_3))

/**
  * @brief  Настройка входа захвата/сравнения
  */
typedef enum {
	TMR_CAPCOM_CapChannel_CCIA,
	TMR_CAPCOM_CapChannel_CCIB,
	TMR_CAPCOM_CapChannel_Low,	/*!<  Уровень логического нуля   */
	TMR_CAPCOM_CapChannel_High	/*!<  Уровень логической единицы */
} TMR_CAPCOM_CAPCOM_Channel_Typedef;
#define IS_TMR_CAPCOM_CHANNEL (((VALUE) == TMR_CAPCOM_CapChannel_CCIA) || \
								((VALUE) == TMR_CAPCOM_CapChannel_CCIB) || \
								((VALUE) == TMR_CAPCOM_CapChannel_Low) || \
								((VALUE) == TMR_CAPCOM_CapChannel_High))

/**
  * @}
  */

/** @defgroup TMR_Exported_Functions Функции
  * @{
  */

/**
  * @brief   Сброс счётчика, делителя и направления счёта
  * @param 	 TMRx Выбор таймера где x лежит между 0 и 3 типа @ref TMR_TypeDef
  * @retval  void
  */
__STATIC_INLINE void TMR_Clear(TMR_TypeDef* TMRx)
{
	assert_param(IS_TMR_PERIPH(TMRx));

    SET_BIT(TMRx->CTRL, TMR_CTRL_CLR_Msk);
}

/**
  * @brief   Выбор режима счёта
  * @param 	 TMRx Выбор таймера где x лежит между 0 и 3 типа @ref TMR_TypeDef
  * @param   mode Режим счёта
  * @retval  void
  */
__STATIC_INLINE void TMR_SetMode(TMR_TypeDef* TMRx, TMR_Mode_TypeDef mode)
{
	assert_param(IS_TMR_PERIPH(TMRx));
	assert_param(IS_TMR_MODE(mode));

    MODIFY_REG(TMRx->CTRL, TMR_CTRL_MODE_Msk, (uint32_t) mode << TMR_CTRL_MODE_Pos);
}

/**
  * @brief   Выбор выходного делителя частоты таймера
  * @param 	 TMRx Выбор таймера где x лежит между 0 и 3 типа @ref TMR_TypeDef
  * @param   div Делитель частоты
  * @retval  void
  */
__STATIC_INLINE void TMR_SetDivider(TMR_TypeDef* TMRx, uint32_t div)
{
	assert_param(IS_TMR_PERIPH(TMRx));

	WRITE_REG(TMRx->CLKDIV, div);
}

/**
  * @brief   Выбор источника тактированного сигнала
  * @param 	 TMRx Выбор таймера где x лежит между 0 и 3 типа @ref TMR_TypeDef
  * @param   sel Источник тактирования
  * @retval  void
  */
__STATIC_INLINE void TMR_SetClksel(TMR_TypeDef* TMRx, TMR_Clksel_TypeDef sel)
{
	assert_param(IS_TMR_PERIPH(TMRx));
	assert_param(IS_TMR_CLKSEL(sel));

    MODIFY_REG(TMRx->CTRL, TMR_CTRL_CLKSEL_Msk, (uint32_t) sel << TMR_CTRL_CLKSEL_Pos);
}

/**
  * @brief   Установка значения периода таймера
  * @param 	 TMRx Выбор таймера где x лежит между 0 и 15 типа @ref TMR_TypeDef
  * @param   Period  Значение периода
  * @retval  void
  */
__STATIC_INLINE void TMR_SetPeriod(TMR_TypeDef* TMRx, uint32_t Period)
{
	assert_param(IS_TMR_PERIPH(TMRx));

    WRITE_REG(TMRx->PERIOD, Period);
}

/**
  * @brief   Установка значения счетчика
  * @param 	 TMRx Выбор таймера где x лежит между 0 и 3 типа @ref TMR_TypeDef
  * @param   CountVal  Значение счетчика
  * @retval  void
  */
__STATIC_INLINE void TMR_SetCounter(TMR_TypeDef* TMRx, uint16_t CountVal)
{
	assert_param(IS_TMR_PERIPH(TMRx));

    WRITE_REG(TMRx->COUNT, CountVal);
}

/**
  * @brief   Установка маски прерывания
  * @param 	 TMRx Выбор таймера где x лежит между 0 и 3 типа @ref TMR_TypeDef
  * @retval  void
  */
__STATIC_INLINE uint16_t TMR_GetCounter(TMR_TypeDef* TMRx)
{
	assert_param(IS_TMR_PERIPH(TMRx));

    return READ_REG(TMRx->COUNT);
}

//						 IT

/**
  * @brief   Установка флага для маскированного прерывания
  * @param 	 TMRx Выбор таймера где x лежит между 0 и 3 типа @ref TMR_TypeDef
  * @param   it Номер маскированного прерывания типа @ref TMR_IT_TypeDef
  * @param   state Флаг для включения маскированного прерывания
  * @retval  void
  */
__STATIC_INLINE void TMR_ITCmd(TMR_TypeDef* TMRx, TMR_IT_TypeDef it, FunctionalState state)
{
	assert_param(IS_TMR_PERIPH(TMRx));
    assert_param(IS_TMR_IT(it));
    assert_param(IS_FUNCTIONAL_STATE(state));

    MODIFY_REG(TMRx->IM, (uint32_t) it, ((state == ENABLE) ? (uint32_t) it : 0u));
}


/**
  * @brief   Установка значения регистра сравнения
  * @param 	 TMRx Выбор таймера где x лежит между 0 и 3 типа @ref TMR_TypeDef
  * @param   it Маскированное прерывание прерывания типа @ref TMR_IT_TypeDef
  * @retval  void
  */
__STATIC_INLINE FunctionalState TMR_ITMaskedStatus(TMR_TypeDef* TMRx, TMR_IT_TypeDef it)
{
	assert_param(IS_TMR_PERIPH(TMRx));
    assert_param(IS_TMR_IT(it));

    return READ_BIT(TMRx->MIS, (uint32_t) it);
}

/**
  * @brief   Чтение значения немаскированного прерывания.
  * @param 	 TMRx Выбор таймера где x лежит между 0 и 3 типа @ref TMR_TypeDef
  * @param   it Маскированное прерывание прерывания типа @ref TMR_IT_TypeDef
  * @retval  void
  */
__STATIC_INLINE FunctionalState TMR_ITRawStatus(TMR_TypeDef* TMRx, TMR_IT_TypeDef it)
{
	assert_param(IS_TMR_PERIPH(TMRx));
    assert_param(IS_TMR_IT(it));

    return READ_BIT(TMRx->RIS, (uint32_t) it);
}

/**
  * @brief   Сброс прерываний
  * @param 	 TMRx Выбор таймера где x лежит между 0 и 3 типа @ref TMR_TypeDef
  * @param   it Маскированное прерывание прерывания типа @ref TMR_IT_TypeDef
  * @retval  void
  */
__STATIC_INLINE void TMR_ITClear(TMR_TypeDef* TMRx, TMR_IT_TypeDef it)
{
	assert_param(IS_TMR_PERIPH(TMRx));
    assert_param(IS_TMR_IT(it));

    WRITE_REG(TMRx->IC, (uint32_t) it); /* write-1-to-clear, no RMW */
}

/**
  * @brief   Разрешение формирования запросов Rx DMA
  * @param 	 TMRx Выбор таймера где x лежит между 0 и 3 типа @ref TMR_TypeDef
  * @param   it Номер маскированного прерывания типа @ref TMR_IT_TypeDef
  * @param   state Флаг для разрешения формирования запросов
  * @retval  void
  */
__STATIC_INLINE void TMR_DMARxReqCmd(TMR_TypeDef* TMRx, TMR_REQ_TypeDef it, FunctionalState state)
{
	assert_param(IS_TMR_PERIPH(TMRx));
    assert_param(IS_TMR_REQ(it));
    assert_param(IS_FUNCTIONAL_STATE(state));

    MODIFY_REG(TMRx->DMA_RXIM, (uint32_t) it, ((state == ENABLE) ? (uint32_t) it : 0u));
}

/**
  * @brief   Разрешение формирования запросов Tx DMA
  * @param 	 TMRx Выбор таймера где x лежит между 0 и 3 типа @ref TMR_TypeDef
  * @param   it Номер маскированного прерывания типа @ref TMR_IT_TypeDef
  * @param   state Флаг для разрешения формирования запросов
  * @retval  void
  */
__STATIC_INLINE void TMR_DMATxReqCmd(TMR_TypeDef* TMRx, TMR_REQ_TypeDef it, FunctionalState state)
{
	assert_param(IS_TMR_PERIPH(TMRx));
    assert_param(IS_TMR_REQ(it));
    assert_param(IS_FUNCTIONAL_STATE(state));

    MODIFY_REG(TMRx->DMA_TXIM, (uint32_t) it, ((state == ENABLE) ? (uint32_t) it : 0u));
}

/**
  * @brief   Разрешение формирования запросов внешних событий
  * @param 	 TMRx Выбор таймера где x лежит между 0 и 3 типа @ref TMR_TypeDef
  * @param   it Номер маскированного прерывания типа @ref TMR_IT_TypeDef
  * @param   state Флаг для разрешения формирования запросов
  * @retval  void
  */
__STATIC_INLINE void TMR_EventReqCmd(TMR_TypeDef* TMRx, TMR_REQ_TypeDef it, FunctionalState state)
{
	assert_param(IS_TMR_PERIPH(TMRx));
    assert_param(IS_TMR_REQ(it));
    assert_param(IS_FUNCTIONAL_STATE(state));

    MODIFY_REG(TMRx->EXTEVT_IM, (uint32_t) it, ((state == ENABLE) ? (uint32_t) it : 0u));
}

// CAPCOM

/**
  * @brief   Установка значения регистра сравнения 0
  * @param 	 TMRx Выбор таймера где x лежит между 0 и 3 типа @ref TMR_TypeDef
  * @param   capcomx номер регистра capcom @ref TMR_CAPCOM_Num_TypeDef.
  * @param   CapComVal  Значение регистра сравнения
  * @retval  void
  */
__STATIC_INLINE void TMR_CAPCOM_SetComparator0(TMR_TypeDef* TMRx, TMR_CAPCOM_Num_TypeDef capcomx, uint16_t capcomVal)
{
	assert_param(IS_TMR_PERIPH(TMRx));
    assert_param(IS_TMR_CAPCOM(capcomx));

    WRITE_REG(TMRx->CAPCOM[capcomx].VAL0, capcomVal);
}

/**
  * @brief   Установка значения регистра сравнения 1
  * @param 	 TMRx Выбор таймера где x лежит между 0 и 3 типа @ref TMR_TypeDef
  * @param   capcomx номер регистра capcom @ref TMR_CAPCOM_Num_TypeDef.
  * @param   CapComVal  Значение регистра сравнения
  * @retval  void
  */
__STATIC_INLINE void TMR_CAPCOM_SetComparator1(TMR_TypeDef* TMRx, TMR_CAPCOM_Num_TypeDef capcomx, uint16_t capcomVal)
{
	assert_param(IS_TMR_PERIPH(TMRx));
    assert_param(IS_TMR_CAPCOM(capcomx));

    WRITE_REG(TMRx->CAPCOM[capcomx].VAL1, capcomVal);
}

/**
  * @brief   Получение статуса переполнения.
  * @param 	 TMRx Выбор таймера где x лежит между 0 и 3 типа @ref TMR_TypeDef
  * @param   capcomx номер регистра capcom @ref TMR_CAPCOM_Num_TypeDef.
  * @retval  FunctionalState сосотяние переполнения
  */
__STATIC_INLINE FunctionalState TMR_CAPCOM_OverflowStatus(TMR_TypeDef* TMRx, TMR_CAPCOM_Num_TypeDef capcomx)
{
	assert_param(IS_TMR_PERIPH(TMRx));
	assert_param(IS_TMR_CAPCOM_NUM(capcomx));

    return READ_BIT(TMRx->CAPCOM[capcomx].CTRL, TMR_CAPCOM_CTRL_OVF_Msk);
}

/**
  * @brief   Сброс статуса переполнения.
  * @param 	 TMRx Выбор таймера где x лежит между 0 и 3 типа @ref TMR_TypeDef
  * @param   capcomx номер регистра capcom @ref TMR_CAPCOM_Num_TypeDef.
  * @retval  void
  */
__STATIC_INLINE void TMR_CAPCOM_OverflowClear(TMR_TypeDef* TMRx, TMR_CAPCOM_Num_TypeDef capcomx)
{
	assert_param(IS_TMR_PERIPH(TMRx));
	assert_param(IS_TMR_CAPCOM_NUM(capcomx));

    SET_BIT(TMRx->CAPCOM[capcomx].CTRL, TMR_CAPCOM_CTRL_OVF_Msk);
}

/**
  * @brief   Выбор состояния выхода, которое будет выставлено при OUTMODE = TMR_CAPCOM_OutMode_BitOUT = 0.
  * @param 	 TMRx Выбор таймера где x лежит между 0 и 3 типа @ref TMR_TypeDef
  * @param   capcomx номер регистра capcom @ref TMR_CAPCOM_Num_TypeDef.
  * @param   out состояние выхода.
  * @retval  void
  */
__STATIC_INLINE void TMR_CAPCOM_OutBitConfig(TMR_TypeDef* TMRx, TMR_CAPCOM_Num_TypeDef capcomx, FunctionalState out)
{
	assert_param(IS_TMR_PERIPH(TMRx));
	assert_param(IS_TMR_CAPCOM_NUM(capcomx));
	assert_param(IS_FUNCTIONAL_STATE(out));

    MODIFY_REG(TMRx->CAPCOM[capcomx].CTRL, TMR_CAPCOM_CTRL_OUT_Msk, (uint32_t) out << TMR_CAPCOM_CTRL_OUT_Pos);
}

/**
  * @brief   Выбор режима вывода.
  * @param 	 TMRx Выбор таймера где x лежит между 0 и 3 типа @ref TMR_TypeDef
  * @param   capcomx Нномер регистра capcom @ref TMR_CAPCOM_Num_TypeDef.
  * @param   outMode Режим вывода.
  * @retval  void
  */
__STATIC_INLINE void TMR_CAPCOM_OutModeConfig(TMR_TypeDef* TMRx, TMR_CAPCOM_Num_TypeDef capcomx, TMR_CAPCOM_OutMode_TypeDef outMode)
{
	assert_param(IS_TMR_PERIPH(TMRx));
	assert_param(IS_TMR_CAPCOM_NUM(capcomx));
	assert_param(IS_TMR_CAPCOM_OUTMODE(outMode));

    MODIFY_REG(TMRx->CAPCOM[capcomx].CTRL, TMR_CAPCOM_CTRL_OUTMODE_Msk, (uint32_t) outMode << TMR_CAPCOM_CTRL_OUTMODE_Pos);
}

/**
  * @brief   Выбор режима захвата/сравнения.
  * @param 	 TMRx Выбор таймера где x лежит между 0 и 3 типа @ref TMR_TypeDef
  * @param   capcomx Номер регистра capcomx @ref TMR_CAPCOM_Num_TypeDef.
  * @param   capMode Режим вывода.
  * @retval  void
  */
__STATIC_INLINE void TMR_CAPCOM_CapModeConfig(TMR_TypeDef* TMRx, TMR_CAPCOM_Num_TypeDef capcomx, TMR_CAPCOM_Mode_TypeDef capcomMode)
{
	assert_param(IS_TMR_PERIPH(TMRx));
	assert_param(IS_TMR_CAPCOM_NUM(capcomx));
	assert_param(IS_TMR_CAPCOM_MODE(capcomMode));

    MODIFY_REG(TMRx->CAPCOM[capcomx].CTRL, TMR_CAPCOM_CTRL_CAPMODE_Msk, (uint32_t) capcomMode << TMR_CAPCOM_CTRL_CAPMODE_Pos);
}

/**
  * @brief   Выбор режима входа захвата/сравнения.
  * @param 	 TMRx Выбор таймера где x лежит между 0 и 3 типа @ref TMR_TypeDef
  * @param   capcomx Нномер регистра capcomx @ref TMR_CAPCOM_Num_TypeDef.
  * @param   capMode Режим вывода.
  * @retval  void
  */
__STATIC_INLINE void TMR_CAPCOM_CapChannelConfig(TMR_TypeDef* TMRx, TMR_CAPCOM_Num_TypeDef capcomx, TMR_CAPCOM_CAPCOM_Channel_Typedef capcomChannel)
{
	assert_param(IS_TMR_PERIPH(TMRx));
	assert_param(IS_TMR_CAPCOM_NUM(capcomx));
	assert_param(IS_TMR_CAPCOM_CHANNEL(capcomChannel));

    MODIFY_REG(TMRx->CAPCOM[capcomx].CTRL, TMR_CAPCOM_CTRL_CCISEL_Msk, (uint32_t) capcomChannel << TMR_CAPCOM_CTRL_CCISEL_Pos);
}

/**
  * @brief   Получение состояния синхронизированного входа захвата/сравнения.
  * @param 	 TMRx Выбор таймера где x лежит между 0 и 3 типа @ref TMR_TypeDef
  * @param   capcomx Нномер регистра capcomx @ref TMR_CAPCOM_Num_TypeDef.
  * @retval  statys сосотяние выбранного синхронизированного входа CapCom
  */
__STATIC_INLINE FunctionalState TMR_CAPCOM_GetSyncedCapComInput(TMR_TypeDef* TMRx, TMR_CAPCOM_Num_TypeDef capcomx)
{
	assert_param(IS_TMR_PERIPH(TMRx));
	assert_param(IS_TMR_CAPCOM_NUM(capcomx));

    return (FunctionalState) READ_BIT(TMRx->CAPCOM[capcomx].CTRL, TMR_CAPCOM_CTRL_SCCI_Msk);
}

/**
  * @brief   Получение состояния входа захвата/сравнения.
  * @param 	 TMRx Выбор таймера где x лежит между 0 и 3 типа @ref TMR_TypeDef
  * @param   capcomx Нномер регистра capcomx @ref TMR_CAPCOM_Num_TypeDef.
  * @retval  status состояние выбранного входа CapCom
  */
__STATIC_INLINE FunctionalState TMR_CAPCOM_GetCapComInput(TMR_TypeDef* TMRx, TMR_CAPCOM_Num_TypeDef capcomx)
{
	assert_param(IS_TMR_PERIPH(TMRx));
	assert_param(IS_TMR_CAPCOM_NUM(capcomx));

    return (FunctionalState) READ_BIT(TMRx->CAPCOM[capcomx].CTRL, TMR_CAPCOM_CTRL_CCI_Msk);
}

/**
  * @brief   Выбор режима захвата/сравнения.
  * @param 	 TMRx Выбор таймера где x лежит между 0 и 3 типа @ref TMR_TypeDef
  * @param   capcomx Нномер регистра capcomx @ref TMR_CAPCOM_Num_TypeDef.
  * @param   state Режим захвата 0 - режим сравнения; 1 - режим захвата.
  * @retval  void
  */
__STATIC_INLINE void TMR_CAPCOM_CaptureConfig(TMR_TypeDef* TMRx, TMR_CAPCOM_Num_TypeDef capcomx, FunctionalState state)
{
	assert_param(IS_TMR_PERIPH(TMRx));
	assert_param(IS_TMR_CAPCOM_NUM(capcomx));
	assert_param(IS_FUNCTIONAL_STATE(state));

    MODIFY_REG(TMRx->CAPCOM[capcomx].CTRL, TMR_CAPCOM_CTRL_CAP_Msk, (uint32_t) state << TMR_CAPCOM_CTRL_CAP_Pos);
}



/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __PLIB5T_TMR_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2025 NIIET *****END OF FILE****/
