/**
  ******************************************************************************
  * @file    plib5t_cap.h
  *
  * @brief   Файл содержит прототипы и компактные inline реализации функций для
  *          CAP, а также сопутствующие макроопределения и перечисления
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
  * <h2><center>&copy; 2025 ОАО "НИИЭТ"</center></h2>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PLIB5T_CAP_H
#define __PLIB5T_CAP_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "plib5t.h"

/** @addtogroup Peripheral
  * @{
  */

/** @defgroup CAP
  * @brief Драйвер для работы с CAP
  * @{
  */

/** @defgroup CAP_Exported_Defines Константы
  * @{
  */

/** @defgroup CAP_ITStatus_Define Флаги прерываний
  * @{
  */

#define CAP_ITStatus_GeneralInt CAP_ECFLG_INT_Msk        /*!< Общее прерывание */
#define CAP_ITStatus_CapEvt0 CAP_ECFLG_CEVT0_Msk         /*!< Событие захвата 0 */
#define CAP_ITStatus_CapEvt1 CAP_ECFLG_CEVT1_Msk         /*!< Событие захвата 1 */
#define CAP_ITStatus_CapEvt2 CAP_ECFLG_CEVT2_Msk         /*!< Событие захвата 2 */
#define CAP_ITStatus_CapEvt3 CAP_ECFLG_CEVT3_Msk         /*!< Событие захвата 3 */
#define CAP_ITStatus_TimerOvf CAP_ECFLG_CTROVF_Msk       /*!< Переполнение счетчика таймера */
#define CAP_ITStatus_TimerEqPeriod CAP_ECFLG_CTRPRD_Msk  /*!< Счетчик таймера равен периоду (в режиме ШИМ) */
#define CAP_ITStatus_TimerEqCompare CAP_ECFLG_CTRCMP_Msk /*!< Счетчик таймера равен значению сравнения (в режиме ШИМ) */
#define CAP_ITStatus_All (CAP_ITStatus_GeneralInt |    \
                           CAP_ITStatus_CapEvt0 |       \
                           CAP_ITStatus_CapEvt1 |       \
                           CAP_ITStatus_CapEvt2 |       \
                           CAP_ITStatus_CapEvt3 |       \
                           CAP_ITStatus_TimerOvf |      \
                           CAP_ITStatus_TimerEqPeriod | \
                           CAP_ITStatus_TimerEqCompare) /*!< Все флаги выбраны */

#define IS_CAP_IT_STATUS(VALUE) (((VALUE) & ~CAP_ITStatus_All) == 0)

/**
  * @}
  */

/** @defgroup CAP_ITSource_Define Маски источников прерываний
  * @{
  */

#define CAP_ITSource_CapEvt0 CAP_ECEINT_CEVT0_Msk         /*!< Событие захвата 0 */
#define CAP_ITSource_CapEvt1 CAP_ECEINT_CEVT1_Msk         /*!< Событие захвата 1 */
#define CAP_ITSource_CapEvt2 CAP_ECEINT_CEVT2_Msk         /*!< Событие захвата 2 */
#define CAP_ITSource_CapEvt3 CAP_ECEINT_CEVT3_Msk         /*!< Событие захвата 3 */
#define CAP_ITSource_TimerOvf CAP_ECEINT_CTROVF_Msk       /*!< Переполнение счетчика таймера */
#define CAP_ITSource_TimerEqPeriod CAP_ECEINT_CTRPRD_Msk  /*!< Счетчик таймера равен периоду (в режиме ШИМ) */
#define CAP_ITSource_TimerEqCompare CAP_ECEINT_CTRCMP_Msk /*!< Счетчик таймера равен значению сравнения (в режиме ШИМ) */
#define CAP_ITSource_All (CAP_ITSource_CapEvt0 |       \
                           CAP_ITSource_CapEvt1 |       \
                           CAP_ITSource_CapEvt2 |       \
                           CAP_ITSource_CapEvt3 |       \
                           CAP_ITSource_TimerOvf |      \
                           CAP_ITSource_TimerEqPeriod | \
                           CAP_ITSource_TimerEqCompare) /*!< Все источники выбраны */

#define IS_CAP_IT_SOURCE(VALUE) (((VALUE) & ~CAP_ITSource_All) == 0)

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup CAP_Exported_Types Типы
  * @{
  */

/**
  * @brief  Выбор фронта захвата
  */
typedef enum {
    CAP_Capture_Polarity_PosEdge, /*!< Захват по переднему фронту */
    CAP_Capture_Polarity_NegEdge  /*!< Захват по заднему фронту */
} CAP_Capture_Polarity_TypeDef;
#define IS_CAP_CAPTURE_POLARITY(VALUE) (((VALUE) == CAP_Capture_Polarity_PosEdge) || \
                                         ((VALUE) == CAP_Capture_Polarity_NegEdge))

/**
  * @brief  Выбор режима остановки таймера при отладке
  */
typedef enum {
    CAP_Halt_Stop = CAP_ECCTL0_FREESOFT_Stop,             /*!< Мгновенная остановка таймера при отладке */
    CAP_Halt_StopOnZero = CAP_ECCTL0_FREESOFT_StopAtZero, /*!< Остановка таймера при переполнении или сбросе (событие достижения 0) */
    CAP_Halt_Free = CAP_ECCTL0_FREESOFT_Free              /*!< Нормальный режим */
} CAP_Halt_TypeDef;
#define IS_CAP_HALT(VALUE) (((VALUE) == CAP_Halt_Stop) ||       \
                             ((VALUE) == CAP_Halt_StopOnZero) || \
                             ((VALUE) == CAP_Halt_Free))

/**
  * @brief  Выбор источника входного сигнала
  */
typedef enum {
    CAP_In_CAPx_IO = SIU_CAPMUX_CAPINSEL0_CAP0,         /*!< Вход по умолчанию с внешнего вывода CAPx_IO */
    CAP_In_QEPA = SIU_CAPMUX_CAPINSEL0_QEPA,          	/*!< Вход A блока QEP */
    CAP_In_QEPB = SIU_CAPMUX_CAPINSEL0_QEPB,          	/*!< Вход B блока QEP */
	CAP_In_QEPI = SIU_CAPMUX_CAPINSEL0_QEPI,          	/*!< Вход I блока QEP */
} CAP_In_TypeDef;
#define IS_CAP_IN(VALUE) (((VALUE) == CAP_In_CAPx_IO) ||        \
                                 ((VALUE) == CAP_In_QEPA) || \
                                 ((VALUE) == CAP_In_QEPB) || \
                                 ((VALUE) == CAP_In_QEPI))

/**
  * @brief  Выбор источника выходного сигнала синхронизации
  */
typedef enum {
    CAP_SyncOut_Bypass = CAP_ECCTL1_SYNCOSEL_Bypass,          /*!< Пропуск синхросигнала со входа на выход */
    CAP_SyncOut_TimerEqPeriod = CAP_ECCTL1_SYNCOSEL_CTREqPrd, /*!< Передача события равенства таймера и значения периода в качестве выходного сигнала синхронизации */
    CAP_SyncOut_Disable = CAP_ECCTL1_SYNCOSEL_Disable         /*!< Выходной сигнал синхронизации запрещен */
} CAP_SyncOut_TypeDef;
#define IS_CAP_SYNC_OUT(VALUE) (((VALUE) == CAP_SyncOut_Bypass) ||        \
                                 ((VALUE) == CAP_SyncOut_TimerEqPeriod) || \
                                 ((VALUE) == CAP_SyncOut_Disable))

/**
  * @brief  Выбор режима работы захвата
  */
typedef enum {
    CAP_Capture_Mode_Cycle, /*!< Цикличный захват */
    CAP_Capture_Mode_Single /*!< Однократный захват */
} CAP_Capture_Mode_TypeDef;
#define IS_CAP_CAPTURE_MODE(VALUE) (((VALUE) == CAP_Capture_Mode_Single) || \
                                     ((VALUE) == CAP_Capture_Mode_Cycle))

/**
  * @brief  Выбор активного уровня в режиме ШИМ
  */
typedef enum {
    CAP_PWM_Polarity_Pos, /*!< Высокий уровень является активным */
    CAP_PWM_Polarity_Neg  /*!< Низкий уровень является активным */
} CAP_PWM_Polarity_TypeDef;
#define IS_CAP_PWM_POLARITY(VALUE) (((VALUE) == CAP_PWM_Polarity_Pos) || \
                                     ((VALUE) == CAP_PWM_Polarity_Neg))

/**
  * @brief  Выбор режима работы блока захвата
  */
typedef enum {
    CAP_Mode_Capture, /*!< Режим захвата */
    CAP_Mode_PWM      /*!< Режим ШИМ */
} CAP_Mode_TypeDef;
#define IS_CAP_MODE(VALUE) (((VALUE) == CAP_Mode_Capture) || \
                             ((VALUE) == CAP_Mode_PWM))

/**
  * @brief  Структура инициализации блока захвата в целом
  */
typedef struct
{
    CAP_Halt_TypeDef Halt;       /*!< Выбор режима остановки таймера при отладке */
    FunctionalState SyncEn;       /*!< Определеяет возможность синхронизации */
    CAP_SyncOut_TypeDef SyncOut; /*!< Выбор источника выходного сигнала синхронизации */
    CAP_Mode_TypeDef Mode;       /*!< Выбор режима работы блока захвата */
} CAP_Init_TypeDef;

/**
  * @brief  Структура инициализации режима захвата
  */
typedef struct
{
    uint32_t Prescale;                          /*!< Предварительный делитель событий.
                                                     Параметр может принимать любое значение из диапазона 0-63. 0 - делитель выключен. */
    CAP_Capture_Mode_TypeDef Mode;             /*!< Определеяет режим работы захвата */
    uint32_t StopVal;                           /*!< Значение счетчика событий для остановки одиночного режима захвата.
                                                     Параметр может принимать любое значение из диапазона 0-3. */
    FunctionalState RstEvt0;                    /*!< Определеяет сброс таймера после события захвата 0 */
    FunctionalState RstEvt1;                    /*!< Определеяет сброс таймера после события захвата 1 */
    FunctionalState RstEvt2;                    /*!< Определеяет сброс таймера после события захвата 2 */
    FunctionalState RstEvt3;                    /*!< Определеяет сброс таймера после события захвата 3 */
    CAP_Capture_Polarity_TypeDef PolarityEvt0; /*!< Определеяет фронт события захвата 0 */
    CAP_Capture_Polarity_TypeDef PolarityEvt1; /*!< Определеяет фронт события захвата 1 */
    CAP_Capture_Polarity_TypeDef PolarityEvt2; /*!< Определеяет фронт события захвата 2 */
    CAP_Capture_Polarity_TypeDef PolarityEvt3; /*!< Определеяет фронт события захвата 3 */
} CAP_Capture_Init_TypeDef;
#define IS_CAP_CAPTURE_PRESCALE(VALUE) ((VALUE) < 0x40)
#define IS_CAP_CAPTURE_STOP(VALUE) ((VALUE) < 0x4)

/**
  * @brief  Структура инициализации режима ШИМ
  */
typedef struct
{
    uint32_t Period;                    /*!< Значение периода ШИМ.
                                             Параметр может принимать любое значение из диапазона 0x00000000-0xFFFFFFFF. */
    uint32_t Compare;                   /*!< Значение сравнения ШИМ.
                                             Параметр может принимать любое значение из диапазона 0x00000000-0xFFFFFFFF. */
    CAP_PWM_Polarity_TypeDef Polarity; /*!< Выбор полярности ШИМ сигнала */
} CAP_PWM_Init_TypeDef;

/**
  * @}
  */

/** @defgroup CAP_Exported_Functions Функции
  * @{
  */

/** @defgroup CAP_Config Конфигурация
  * @{
  */

void CAP_DeInit(CAP_TypeDef* CAPx);
void CAP_Init(CAP_TypeDef* CAPx, CAP_Init_TypeDef* InitStruct);
void CAP_StructInit(CAP_Init_TypeDef* InitStruct);

/**
  * @brief   Выбор источника входного сигнала
  * @param   CAPx   Выбор модуля CAP, где x лежит в диапазоне 0-2
  * @param   Input  Выбор источника входного сигнала
  * @retval  void
  */
__STATIC_INLINE void CAP_InputConfig(CAP_TypeDef* CAPx, CAP_In_TypeDef Input)
{
    assert_param(IS_CAP_PERIPH(CAPx));
    assert_param(IS_CAP_IN(Input));

    //WRITE_REG(CAPx->ECCTL0_bit.FREESOFT, Halt);
    if(CAPx == CAP0) WRITE_REG(SIU->CAPMUX_bit.CAPINSEL0,Input);
    else if (CAPx == CAP1) WRITE_REG(SIU->CAPMUX_bit.CAPINSEL1,Input);
    	else if (CAPx == CAP2) WRITE_REG(SIU->CAPMUX_bit.CAPINSEL2,Input);
}

/**
  * @brief   Настройка режима остановки таймера при отладке
  * @param   CAPx  Выбор модуля CAP, где x лежит в диапазоне 0-2
  * @param   Halt  Выбор режима
  * @retval  void
  */
__STATIC_INLINE void CAP_HaltConfig(CAP_TypeDef* CAPx, CAP_Halt_TypeDef Halt)
{
    assert_param(IS_CAP_PERIPH(CAPx));
    assert_param(IS_CAP_HALT(Halt));

    WRITE_REG(CAPx->ECCTL0_bit.FREESOFT, Halt);
}

/**
  * @brief   Настройка режима работы блока захвата
  * @param   CAPx  Выбор модуля CAP, где x лежит в диапазоне 0-2
  * @param   Mode  Выбор режима
  * @retval  void
  */
__STATIC_INLINE void CAP_ModeConfig(CAP_TypeDef* CAPx, CAP_Mode_TypeDef Mode)
{
    assert_param(IS_CAP_PERIPH(CAPx));
    assert_param(IS_CAP_MODE(Mode));

    WRITE_REG(CAPx->ECCTL1_bit.CAPAPWM, Mode);
}

/**
  * @brief   Разрешение работы таймера, выбранного блока захвата
  * @param   CAPx  Выбор модуля CAP, где x лежит в диапазоне 0-2
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void CAP_TimerCmd(CAP_TypeDef* CAPx, FunctionalState State)
{
    assert_param(IS_CAP_PERIPH(CAPx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(CAPx->ECCTL1_bit.TSCTRSTOP, State);
}

/**
  * @brief   Установка текущего значения счетчика напрямую
  * @param   CAPx  Выбор модуля CAP, где x лежит в диапазоне 0-2
  * @param   TimerVal  Значение таймера
  * @retval  void
  */
__STATIC_INLINE void CAP_SetTimer(CAP_TypeDef* CAPx, uint32_t TimerVal)
{
    assert_param(IS_CAP_PERIPH(CAPx));

    WRITE_REG(CAPx->TSCTR, TimerVal);
}

/**
  * @brief   Установка теневого значения таймера для отложенной записи
  * @param   CAPx  Выбор модуля CAP, где x лежит в диапазоне 0-2
  * @param   TimerVal  Значение таймера
  * @retval  void
  */
__STATIC_INLINE void CAP_SetShadowTimer(CAP_TypeDef* CAPx, uint32_t TimerVal)
{
    assert_param(IS_CAP_PERIPH(CAPx));

    WRITE_REG(CAPx->CTRPHS, TimerVal);
}

/**
  * @brief   Получение текущего значения таймера
  * @param   CAPx  Выбор CAP, где x лежит в диапазоне 0-2
  * @retval  Val  Значение таймера
  */
__STATIC_INLINE uint32_t CAP_GetTimer(CAP_TypeDef* CAPx)
{
    assert_param(IS_CAP_PERIPH(CAPx));

    return READ_REG(CAPx->TSCTR);
}

/**
  * @brief   Получение отложенного значения таймера
  * @param   CAPx  Выбор CAP, где x лежит в диапазоне 0-2
  * @retval  Val  Значение таймера
  */
__STATIC_INLINE uint32_t CAP_GetShadowTimer(CAP_TypeDef* CAPx)
{
    assert_param(IS_CAP_PERIPH(CAPx));

    return READ_REG(CAPx->CTRPHS);
}

/**
  * @brief   Настройка источника выходного сигнала синхронизации
  * @param   CAPx  Выбор модуля CAP, где x лежит в диапазоне 0-2
  * @param   SyncOut  Выбор режима
  * @retval  void
  */
__STATIC_INLINE void CAP_SyncOutConfig(CAP_TypeDef* CAPx, CAP_SyncOut_TypeDef SyncOut)
{
    assert_param(IS_CAP_PERIPH(CAPx));
    assert_param(IS_CAP_SYNC_OUT(SyncOut));

    WRITE_REG(CAPx->ECCTL1_bit.SYNCOSEL, SyncOut);
}

/**
  * @brief   Разрешение синхронизации
  * @param   CAPx  Выбор модуля CAP, где x лежит в диапазоне 0-2
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void CAP_SyncCmd(CAP_TypeDef* CAPx, FunctionalState State)
{
    assert_param(IS_CAP_PERIPH(CAPx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(CAPx->ECCTL1_bit.SYNCIEN, State);
}

/**
  * @brief   Проведение программной синхронизации
  * @param   CAPx  Выбор модуля CAP, где x лежит в диапазоне 0-2
  * @retval  void
  */
__STATIC_INLINE void CAP_SwSync(CAP_TypeDef* CAPx)
{
    assert_param(IS_CAP_PERIPH(CAPx));

    WRITE_REG(CAPx->ECCTL1_bit.SWSYNC, 1);
}

/**
  * @}
  */

/** @defgroup CAP_Config_PWM_Mode Режим ШИМ
  * @{
  */

void CAP_PWM_Init(CAP_TypeDef* CAPx, CAP_PWM_Init_TypeDef* InitStruct);
void CAP_PWM_StructInit(CAP_PWM_Init_TypeDef* InitStruct);

/**
  * @brief   Настройка полярности ШИМ сигнала
  * @param   CAPx  Выбор модуля CAP, где x лежит в диапазоне 0-2
  * @param   Polarity  Выбор режима
  * @retval  void
  */
__STATIC_INLINE void CAP_PWM_PolarityConfig(CAP_TypeDef* CAPx, CAP_PWM_Polarity_TypeDef Polarity)
{
    assert_param(IS_CAP_PERIPH(CAPx));
    assert_param(IS_CAP_PWM_POLARITY(Polarity));

    WRITE_REG(CAPx->ECCTL1_bit.APWMPOL, Polarity);
}

/**
  * @brief   Установка значения периода ШИМ
  * @param   CAPx  Выбор CAP, где x лежит в диапазоне 0-2
  * @param   PeriodVal  Значение периода
  * @retval  void
  */
__STATIC_INLINE void CAP_PWM_SetPeriod(CAP_TypeDef* CAPx, uint32_t PeriodVal)
{
    assert_param(IS_CAP_PERIPH(CAPx));

    WRITE_REG(CAPx->PRD, PeriodVal);
}

/**
  * @brief   Установка значения сравнения ШИМ.
  * @param   CAPx  Выбор CAP, где x лежит в диапазоне 0-2
  * @param   CompareVal  Значение сравнения.
  * @retval  void
  */
__STATIC_INLINE void CAP_PWM_SetCompare(CAP_TypeDef* CAPx, uint32_t CompareVal)
{
    assert_param(IS_CAP_PERIPH(CAPx));

    WRITE_REG(CAPx->CMP, CompareVal);
}

/**
  * @brief   Установка значения периода ШИМ для отложенной записи
  * @param   CAPx  Выбор CAP, где x лежит в диапазоне 0-2
  * @param   PeriodVal  Значение периода
  * @retval  void
  */
__STATIC_INLINE void CAP_PWM_SetShadowPeriod(CAP_TypeDef* CAPx, uint32_t PeriodVal)
{
    assert_param(IS_CAP_PERIPH(CAPx));

    WRITE_REG(CAPx->PRDSHDW, PeriodVal);
}

/**
  * @brief   Установка значения сравнения ШИМ для отложенной записи
  * @param   CAPx  Выбор CAP, где x лежит в диапазоне 0-2
  * @param   CompareVal  Значение сравнения
  * @retval  void
  */
__STATIC_INLINE void CAP_PWM_SetShadowCompare(CAP_TypeDef* CAPx, uint32_t CompareVal)
{
    assert_param(IS_CAP_PERIPH(CAPx));

    WRITE_REG(CAPx->CMPSHDW, CompareVal);
}

/**
  * @brief   Получение текущего периода ШИМ
  * @param   CAPx  Выбор CAP, где x лежит в диапазоне 0-2
  * @retval  Val  Значение периода
  */
__STATIC_INLINE uint32_t CAP_PWM_GetPeriod(CAP_TypeDef* CAPx)
{
    assert_param(IS_CAP_PERIPH(CAPx));

    return READ_REG(CAPx->PRD);
}

/**
  * @brief   Получение текущего значения сравнения ШИМ
  * @param   CAPx  Выбор CAP, где x лежит в диапазоне 0-2
  * @retval  Val  Значение сравнения
  */
__STATIC_INLINE uint32_t CAP_PWM_GetCompare(CAP_TypeDef* CAPx)
{
    assert_param(IS_CAP_PERIPH(CAPx));

    return READ_REG(CAPx->CMP);
}

/**
  * @brief   Получение отложенного значения периода ШИМ
  * @param   CAPx  Выбор CAP, где x лежит в диапазоне 0-2
  * @retval  Val  Значение периода
  */
__STATIC_INLINE uint32_t CAP_PWM_GetShadowPeriod(CAP_TypeDef* CAPx)
{
    assert_param(IS_CAP_PERIPH(CAPx));

    return READ_REG(CAPx->PRDSHDW);
}

/**
  * @brief   Получение отложенного значения сравнения ШИМ
  * @param   CAPx  Выбор CAP, где x лежит в диапазоне 0-2
  * @retval  Val  Значение сравнения
  */
__STATIC_INLINE uint32_t CAP_PWM_GetShadowCompare(CAP_TypeDef* CAPx)
{
    assert_param(IS_CAP_PERIPH(CAPx));

    return READ_REG(CAPx->CMPSHDW);
}

/**
  * @}
  */

/** @defgroup CAP_Config_CAP_Mode Режим захвата
  * @{
  */

void CAP_Capture_Init(CAP_TypeDef* CAPx, CAP_Capture_Init_TypeDef* InitStruct);
void CAP_Capture_StructInit(CAP_Capture_Init_TypeDef* InitStruct);

/**
  * @brief   Настройка режима захвата
  * @param   CAPx  Выбор модуля CAP, где x лежит в диапазоне 0-2
  * @param   Mode  Выбор режима
  * @retval  void
  */
__STATIC_INLINE void CAP_Capture_ModeConfig(CAP_TypeDef* CAPx, CAP_Capture_Mode_TypeDef Mode)
{
    assert_param(IS_CAP_PERIPH(CAPx));
    assert_param(IS_CAP_CAPTURE_MODE(Mode));

    WRITE_REG(CAPx->ECCTL1_bit.CONTOST, Mode);
}

/**
  * @brief   Настройка счетчика событий для остановки одиночного режима захвата
  * @param   CAPx  Выбор модуля CAP, где x лежит в диапазоне 0-2
  * @param   StopVal  Значение
  * @retval  void
  */
__STATIC_INLINE void CAP_Capture_StopConfig(CAP_TypeDef* CAPx, uint32_t StopVal)
{
    assert_param(IS_CAP_PERIPH(CAPx));
    assert_param(IS_CAP_CAPTURE_STOP(StopVal));

    WRITE_REG(CAPx->ECCTL1_bit.STOPWRAP, StopVal);
}

/**
  * @brief   Настройка предварительного делителя событий
  * @param   CAPx  Выбор модуля CAP, где x лежит в диапазоне 0-2
  * @param   PrescaleVal  Значение
  * @retval  void
  */
__STATIC_INLINE void CAP_Capture_PrescaleConfig(CAP_TypeDef* CAPx, uint32_t PrescaleVal)
{
    assert_param(IS_CAP_PERIPH(CAPx));
    assert_param(IS_CAP_CAPTURE_PRESCALE(PrescaleVal));

    WRITE_REG(CAPx->ECCTL0_bit.PRESCALE, PrescaleVal);
}

/**
  * @brief   Настройка фронта события захвата 0
  * @param   CAPx  Выбор модуля CAP, где x лежит в диапазоне 0-2
  * @param   Polarity  Значение режима
  * @retval  void
  */
__STATIC_INLINE void CAP_Capture_PolarityEvt0Config(CAP_TypeDef* CAPx, CAP_Capture_Polarity_TypeDef Polarity)
{
    assert_param(IS_CAP_PERIPH(CAPx));
    assert_param(IS_CAP_CAPTURE_POLARITY(Polarity));

    WRITE_REG(CAPx->ECCTL0_bit.CAP0POL, Polarity);
}

/**
  * @brief   Настройка фронта события захвата 1
  * @param   CAPx  Выбор модуля CAP, где x лежит в диапазоне 0-2
  * @param   Polarity  Значение режима
  * @retval  void
  */
__STATIC_INLINE void CAP_Capture_PolarityEvt1Config(CAP_TypeDef* CAPx, CAP_Capture_Polarity_TypeDef Polarity)
{
    assert_param(IS_CAP_PERIPH(CAPx));
    assert_param(IS_CAP_CAPTURE_POLARITY(Polarity));

    WRITE_REG(CAPx->ECCTL0_bit.CAP1POL, Polarity);
}

/**
  * @brief   Настройка фронта события захвата 2
  * @param   CAPx  Выбор модуля CAP, где x лежит в диапазоне 0-2
  * @param   Polarity  Значение режима
  * @retval  void
  */
__STATIC_INLINE void CAP_Capture_PolarityEvt2Config(CAP_TypeDef* CAPx, CAP_Capture_Polarity_TypeDef Polarity)
{
    assert_param(IS_CAP_PERIPH(CAPx));
    assert_param(IS_CAP_CAPTURE_POLARITY(Polarity));

    WRITE_REG(CAPx->ECCTL0_bit.CAP2POL, Polarity);
}

/**
  * @brief   Настройка фронта события захвата 3
  * @param   CAPx  Выбор модуля CAP, где x лежит в диапазоне 0-2
  * @param   Polarity  Значение режима
  * @retval  void
  */
__STATIC_INLINE void CAP_Capture_PolarityEvt3Config(CAP_TypeDef* CAPx, CAP_Capture_Polarity_TypeDef Polarity)
{
    assert_param(IS_CAP_PERIPH(CAPx));
    assert_param(IS_CAP_CAPTURE_POLARITY(Polarity));

    WRITE_REG(CAPx->ECCTL0_bit.CAP3POL, Polarity);
}

/**
  * @brief   Разрешение сброса таймера после события захвата 0
  * @param   CAPx  Выбор модуля CAP, где x лежит в диапазоне 0-2
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void CAP_Capture_RstEvt0Cmd(CAP_TypeDef* CAPx, FunctionalState State)
{
    assert_param(IS_CAP_PERIPH(CAPx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(CAPx->ECCTL0_bit.CTRRST0, State);
}

/**
  * @brief   Разрешение сброса таймера после события захвата 1
  * @param   CAPx  Выбор модуля CAP, где x лежит в диапазоне 0-2
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void CAP_Capture_RstEvt1Cmd(CAP_TypeDef* CAPx, FunctionalState State)
{
    assert_param(IS_CAP_PERIPH(CAPx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(CAPx->ECCTL0_bit.CTRRST1, State);
}

/**
  * @brief   Разрешение сброса таймера после события захвата 2
  * @param   CAPx  Выбор модуля CAP, где x лежит в диапазоне 0-2
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void CAP_Capture_RstEvt2Cmd(CAP_TypeDef* CAPx, FunctionalState State)
{
    assert_param(IS_CAP_PERIPH(CAPx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(CAPx->ECCTL0_bit.CTRRST2, State);
}

/**
  * @brief   Разрешение сброса таймера после события захвата 3
  * @param   CAPx  Выбор модуля CAP, где x лежит в диапазоне 0-2
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void CAP_Capture_RstEvt3Cmd(CAP_TypeDef* CAPx, FunctionalState State)
{
    assert_param(IS_CAP_PERIPH(CAPx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(CAPx->ECCTL0_bit.CTRRST3, State);
}

/**
  * @brief   Разрешение захвата для выбранного блока захвата
  * @param   CAPx  Выбор модуля CAP, где x лежит в диапазоне 0-2
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void CAP_Capture_Cmd(CAP_TypeDef* CAPx, FunctionalState State)
{
    assert_param(IS_CAP_PERIPH(CAPx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(CAPx->ECCTL1_bit.REARM, State);
    WRITE_REG(CAPx->ECCTL0_bit.CAPLDEN, State);
}

/**
  * @brief   Установка значения регистра захвата 0
  * @param   CAPx  Выбор таймера, где x лежит в диапазоне 0-2
  * @param   Value  Значение
  * @retval  void
  */
__STATIC_INLINE void CAP_Capture_SetCap0(CAP_TypeDef* CAPx, uint32_t Value)
{
    assert_param(IS_CAP_PERIPH(CAPx));

    WRITE_REG(CAPx->CAPREG0, Value);
}

/**
  * @brief   Установка значения регистра захвата 1
  * @param   CAPx  Выбор таймера, где x лежит в диапазоне 0-2
  * @param   Value  Значение
  * @retval  void
  */
__STATIC_INLINE void CAP_Capture_SetCap1(CAP_TypeDef* CAPx, uint32_t Value)
{
    assert_param(IS_CAP_PERIPH(CAPx));

    WRITE_REG(CAPx->CAPREG1, Value);
}

/**
  * @brief   Установка значения регистра захвата 2
  * @param   CAPx  Выбор таймера, где x лежит в диапазоне 0-2
  * @param   Value  Значение
  * @retval  void
  */
__STATIC_INLINE void CAP_Capture_SetCap2(CAP_TypeDef* CAPx, uint32_t Value)
{
    assert_param(IS_CAP_PERIPH(CAPx));

    WRITE_REG(CAPx->CAPREG2, Value);
}

/**
  * @brief   Установка значения регистра захвата 3
  * @param   CAPx  Выбор таймера, где x лежит в диапазоне 0-2
  * @param   Value  Значение
  * @retval  void
  */
__STATIC_INLINE void CAP_Capture_SetCap3(CAP_TypeDef* CAPx, uint32_t Value)
{
    assert_param(IS_CAP_PERIPH(CAPx));

    WRITE_REG(CAPx->CAPREG3, Value);
}

/**
  * @brief   Получение текущего значения из регистра захвата 0
  * @param   CAPx  Выбор CAP, где x лежит в диапазоне 0-2
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t CAP_Capture_GetCap0(CAP_TypeDef* CAPx)
{
    assert_param(IS_CAP_PERIPH(CAPx));

    return READ_REG(CAPx->CAPREG0);
}

/**
  * @brief   Получение текущего значения из регистра захвата 1
  * @param   CAPx  Выбор CAP, где x лежит в диапазоне 0-2
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t CAP_Capture_GetCap1(CAP_TypeDef* CAPx)
{
    assert_param(IS_CAP_PERIPH(CAPx));

    return READ_REG(CAPx->CAPREG1);
}

/**
  * @brief   Получение текущего значения из регистра захвата 2
  * @param   CAPx  Выбор CAP, где x лежит в диапазоне 0-2
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t CAP_Capture_GetCap2(CAP_TypeDef* CAPx)
{
    assert_param(IS_CAP_PERIPH(CAPx));

    return READ_REG(CAPx->CAPREG2);
}

/**
  * @brief   Получение текущего значения из регистра захвата 3
  * @param   CAPx  Выбор CAP, где x лежит в диапазоне 0-2
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t CAP_Capture_GetCap3(CAP_TypeDef* CAPx)
{
    assert_param(IS_CAP_PERIPH(CAPx));

    return READ_REG(CAPx->CAPREG3);
}

/**
  * @}
  */

/** @defgroup CAP_IT Прерывания
  * @{
  */

/**
  * @brief   Разрешение генерации прерываний
  * @param   CAPx  Выбор CAP, где x лежит в диапазоне 0-2
  * @param   ITSource  Выбор источников прерывания
  *                    Параметр принимает любою совокупность значений CAP_ITSource_x из @ref CAP_ITSource_define.
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void CAP_ITCmd(CAP_TypeDef* CAPx, uint32_t ITSource, FunctionalState State)
{
    assert_param(IS_CAP_PERIPH(CAPx));
    assert_param(IS_CAP_IT_SOURCE(ITSource));
    assert_param(IS_FUNCTIONAL_STATE(State));

    MODIFY_REG(CAPx->ECEINT, ITSource, State ? (uint32_t)ITSource : 0);
}

/**
  * @brief   Принудительный вызов прерывания выбранного блока захвата
  * @param   CAPx  Выбор CAP, где x лежит в диапазоне 0-2
  * @param   ITSource  Выбор источников прерывания
  *                    Параметр принимает любою совокупность значений CAP_ITSource_x из @ref CAP_ITSource_define.
  * @retval  void
  */
__STATIC_INLINE void CAP_ITForceCmd(CAP_TypeDef* CAPx, uint32_t ITSource)
{
    assert_param(IS_CAP_PERIPH(CAPx));
    assert_param(IS_CAP_IT_SOURCE(ITSource));

    WRITE_REG(CAPx->ECFRC, ITSource);
}

/**
  * @brief   Чтение статуса прерывания выбранного блока захвата
  * @param   CAPx  Выбор CAP, где x лежит в диапазоне 0-2
  * @param   ITStatus  Выбор флага прерывания.
  *                    Параметр принимает любою совокупность значений CAP_ITStatus_x из @ref CAP_ITStatus_define.
  * @retval  Status  Статус прерывания. Если выбрано несколько прерываний,
  *                  то результат соответсвует логическому ИЛИ их состояний.
  */
__STATIC_INLINE FlagStatus CAP_ITStatus(CAP_TypeDef* CAPx, uint32_t ITStatus)
{
    assert_param(IS_CAP_PERIPH(CAPx));
    assert_param(IS_CAP_IT_STATUS(ITStatus));

    return (FlagStatus)READ_BIT(CAPx->ECFLG, ITStatus);
}

/**
  * @brief   Сброс статуса прерывания выбранного блока захвата
  * @param   CAPx  Выбор CAP, где x лежит в диапазоне 0-2
  * @param   ITStatus  Выбор флага прерывания.
  *                    Параметр принимает любою совокупность значений CAP_ITStatus_x из @ref CAP_ITStatus_define.
  * @retval  void
  */
__STATIC_INLINE void CAP_ITStatusClear(CAP_TypeDef* CAPx, uint32_t ITStatus)
{
    assert_param(IS_CAP_PERIPH(CAPx));
    assert_param(IS_CAP_IT_STATUS(ITStatus));

    WRITE_REG(CAPx->ECCLR, ITStatus);
}

/**
  * @brief   Чтение активного статуса прерывания выбранного блока захвата
  * @param   CAPx  Выбор CAP, где x лежит в диапазоне 0-2
  * @retval  Status  Статус прерывания
  */
__STATIC_INLINE FlagStatus CAP_ITPendStatus(CAP_TypeDef* CAPx)
{
    assert_param(IS_CAP_PERIPH(CAPx));

    return (FlagStatus)READ_BIT(CAPx->PEINT, CAP_PEINT_PEINT_Msk);
}

/**
  * @brief   Сброс активности прерывания выбранного блока захвата.
  * @param   CAPx  Выбор CAP, где x лежит в диапазоне 0-2
  * @retval  void
  */
__STATIC_INLINE void CAP_ITPendStatusClear(CAP_TypeDef* CAPx)
{
    assert_param(IS_CAP_PERIPH(CAPx));

    WRITE_REG(CAPx->PEINT, CAP_PEINT_PEINT_Msk);
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

#endif /* __PLIB5T_CAP_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2025 NIIET *****END OF FILE****/
