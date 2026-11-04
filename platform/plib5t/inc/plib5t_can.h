/**
  ******************************************************************************
  * @file    plib5t_can.h
  *
  * @brief   Файл содержит прототипы и компактные inline реализации функций для
  *          CAN, а также сопутствующие макроопределения и перечисления
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
#ifndef __PLIB5T_CAN_H
#define __PLIB5T_CAN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "plib5t.h"

/** @addtogroup Peripheral
  * @{
  */

/** @defgroup CAN
  * @brief Драйвер для работы с CAN
  * @{
  */

/** @defgroup CAN_Exported_Defines Константы
  * @{
  */

/** @defgroup CAN_List_Define Списки Can
  * @{
  */

#define CAN_List_0 0x0000UL           /*!< Список 0 выбран */
#define CAN_List_1 0x0001UL           /*!< Список 1 выбран */
#define CAN_List_2 0x0002UL           /*!< Список 2 выбран */

#define IS_CAN_LIST(VALUE) (((VALUE) != 0) && (((VALUE)&0xFFFF0000) == 0))

#define IS_GET_CAN_LIST(VALUE) (((VALUE) == CAN_List_0) ||  \
                                ((VALUE) == CAN_List_1) ||  \
                                ((VALUE) == CAN_List_2))

/**
  * @}
  */

/** @defgroup CAN_Node_Define Узлы Can
  * @{
  */

#define CAN_Node_0 0x0000UL           /*!< Узел 0 выбран */
#define CAN_Node_1 0x0001UL           /*!< Узел 1 выбран */

#define IS_GET_CAN_NODE(VALUE) (((VALUE) == CAN_Node_0) ||  \
                                ((VALUE) == CAN_Node_1))

/**
  * @}
  */

/** @defgroup CAN_Msg_Define Объекты сообщений Can
  * @{
  */

#define CAN_Msg_0 0x0000UL           /*!< Объект сообщения 0 выбран */
#define CAN_Msg_1 0x0001UL           /*!< Объект сообщения 1 выбран */
#define CAN_Msg_2 0x0002UL           /*!< Объект сообщения 2 выбран */
#define CAN_Msg_3 0x0003UL           /*!< Объект сообщения 3 выбран */
#define CAN_Msg_4 0x0004UL           /*!< Объект сообщения 4 выбран */
#define CAN_Msg_5 0x0005UL           /*!< Объект сообщения 5 выбран */
#define CAN_Msg_6 0x0006UL           /*!< Объект сообщения 6 выбран */
#define CAN_Msg_7 0x0007UL           /*!< Объект сообщения 7 выбран */
#define CAN_Msg_8 0x0008UL           /*!< Объект сообщения 8 выбран */
#define CAN_Msg_9 0x0009UL           /*!< Объект сообщения 9 выбран */
#define CAN_Msg_10 0x000AUL           /*!< Объект сообщения 10 выбран */
#define CAN_Msg_11 0x000BUL           /*!< Объект сообщения 11 выбран */
#define CAN_Msg_12 0x000CUL           /*!< Объект сообщения 12 выбран */
#define CAN_Msg_13 0x000DUL           /*!< Объект сообщения 13 выбран */
#define CAN_Msg_14 0x000EUL           /*!< Объект сообщения 14 выбран */
#define CAN_Msg_15 0x000FUL           /*!< Объект сообщения 15 выбран */
#define CAN_Msg_16 0x0010UL           /*!< Объект сообщения 16 выбран */
#define CAN_Msg_17 0x0011UL           /*!< Объект сообщения 17 выбран */
#define CAN_Msg_18 0x0012UL           /*!< Объект сообщения 18 выбран */
#define CAN_Msg_19 0x0013UL           /*!< Объект сообщения 19 выбран */
#define CAN_Msg_20 0x0014UL           /*!< Объект сообщения 20 выбран */
#define CAN_Msg_21 0x0015UL           /*!< Объект сообщения 21 выбран */
#define CAN_Msg_22 0x0016UL           /*!< Объект сообщения 22 выбран */
#define CAN_Msg_23 0x0017UL           /*!< Объект сообщения 23 выбран */
#define CAN_Msg_24 0x0018UL           /*!< Объект сообщения 24 выбран */
#define CAN_Msg_25 0x0019UL           /*!< Объект сообщения 25 выбран */
#define CAN_Msg_26 0x001AUL           /*!< Объект сообщения 26 выбран */
#define CAN_Msg_27 0x001BUL           /*!< Объект сообщения 27 выбран */
#define CAN_Msg_28 0x001CUL           /*!< Объект сообщения 28 выбран */
#define CAN_Msg_29 0x001DUL           /*!< Объект сообщения 29 выбран */
#define CAN_Msg_30 0x001EUL           /*!< Объект сообщения 30 выбран */
#define CAN_Msg_31 0x001FUL           /*!< Объект сообщения 31 выбран */
#define CAN_Msg_32 0x0020UL           /*!< Объект сообщения 32 выбран */
#define CAN_Msg_33 0x0021UL           /*!< Объект сообщения 33 выбран */
#define CAN_Msg_34 0x0022UL           /*!< Объект сообщения 34 выбран */
#define CAN_Msg_35 0x0023UL           /*!< Объект сообщения 35 выбран */
#define CAN_Msg_36 0x0024UL           /*!< Объект сообщения 36 выбран */
#define CAN_Msg_37 0x0025UL           /*!< Объект сообщения 37 выбран */
#define CAN_Msg_38 0x0026UL           /*!< Объект сообщения 38 выбран */
#define CAN_Msg_39 0x0027UL           /*!< Объект сообщения 39 выбран */
#define CAN_Msg_40 0x0028UL           /*!< Объект сообщения 40 выбран */
#define CAN_Msg_41 0x0029UL           /*!< Объект сообщения 41 выбран */
#define CAN_Msg_42 0x002AUL           /*!< Объект сообщения 42 выбран */
#define CAN_Msg_43 0x002BUL           /*!< Объект сообщения 43 выбран */
#define CAN_Msg_44 0x002CUL           /*!< Объект сообщения 44 выбран */
#define CAN_Msg_45 0x002DUL           /*!< Объект сообщения 45 выбран */
#define CAN_Msg_46 0x002EUL           /*!< Объект сообщения 46 выбран */
#define CAN_Msg_47 0x002FUL           /*!< Объект сообщения 47 выбран */
#define CAN_Msg_48 0x0030UL           /*!< Объект сообщения 48 выбран */
#define CAN_Msg_49 0x0031UL           /*!< Объект сообщения 49 выбран */
#define CAN_Msg_50 0x0032UL           /*!< Объект сообщения 50 выбран */
#define CAN_Msg_51 0x0033UL           /*!< Объект сообщения 51 выбран */
#define CAN_Msg_52 0x0034UL           /*!< Объект сообщения 52 выбран */
#define CAN_Msg_53 0x0035UL           /*!< Объект сообщения 53 выбран */
#define CAN_Msg_54 0x0036UL           /*!< Объект сообщения 54 выбран */
#define CAN_Msg_55 0x0037UL           /*!< Объект сообщения 55 выбран */
#define CAN_Msg_56 0x0038UL           /*!< Объект сообщения 56 выбран */
#define CAN_Msg_57 0x0039UL           /*!< Объект сообщения 57 выбран */
#define CAN_Msg_58 0x003AUL           /*!< Объект сообщения 58 выбран */
#define CAN_Msg_59 0x003BUL           /*!< Объект сообщения 59 выбран */
#define CAN_Msg_60 0x003CUL           /*!< Объект сообщения 60 выбран */
#define CAN_Msg_61 0x003DUL           /*!< Объект сообщения 61 выбран */
#define CAN_Msg_62 0x003EUL           /*!< Объект сообщения 62 выбран */
#define CAN_Msg_63 0x003FUL           /*!< Объект сообщения 63 выбран */
#define CAN_Msg_64 0x0040UL           /*!< Объект сообщения 64 выбран */
#define CAN_Msg_65 0x0041UL           /*!< Объект сообщения 65 выбран */
#define CAN_Msg_66 0x0042UL           /*!< Объект сообщения 66 выбран */
#define CAN_Msg_67 0x0043UL           /*!< Объект сообщения 67 выбран */
#define CAN_Msg_68 0x0044UL           /*!< Объект сообщения 68 выбран */
#define CAN_Msg_69 0x0045UL           /*!< Объект сообщения 69 выбран */
#define CAN_Msg_70 0x0046UL           /*!< Объект сообщения 70 выбран */
#define CAN_Msg_71 0x0047UL           /*!< Объект сообщения 71 выбран */
#define CAN_Msg_72 0x0048UL           /*!< Объект сообщения 72 выбран */
#define CAN_Msg_73 0x0049UL           /*!< Объект сообщения 73 выбран */
#define CAN_Msg_74 0x004AUL           /*!< Объект сообщения 74 выбран */
#define CAN_Msg_75 0x004BUL           /*!< Объект сообщения 75 выбран */
#define CAN_Msg_76 0x004CUL           /*!< Объект сообщения 76 выбран */
#define CAN_Msg_77 0x004DUL           /*!< Объект сообщения 77 выбран */
#define CAN_Msg_78 0x004EUL           /*!< Объект сообщения 78 выбран */
#define CAN_Msg_79 0x004FUL           /*!< Объект сообщения 79 выбран */
#define CAN_Msg_80 0x0050UL           /*!< Объект сообщения 80 выбран */
#define CAN_Msg_81 0x0051UL           /*!< Объект сообщения 81 выбран */
#define CAN_Msg_82 0x0052UL           /*!< Объект сообщения 82 выбран */
#define CAN_Msg_83 0x0053UL           /*!< Объект сообщения 83 выбран */
#define CAN_Msg_84 0x0054UL           /*!< Объект сообщения 84 выбран */
#define CAN_Msg_85 0x0055UL           /*!< Объект сообщения 85 выбран */
#define CAN_Msg_86 0x0056UL           /*!< Объект сообщения 86 выбран */
#define CAN_Msg_87 0x0057UL           /*!< Объект сообщения 87 выбран */
#define CAN_Msg_88 0x0058UL           /*!< Объект сообщения 88 выбран */
#define CAN_Msg_89 0x0059UL           /*!< Объект сообщения 89 выбран */
#define CAN_Msg_90 0x005AUL           /*!< Объект сообщения 90 выбран */
#define CAN_Msg_91 0x005BUL           /*!< Объект сообщения 91 выбран */
#define CAN_Msg_92 0x005CUL           /*!< Объект сообщения 92 выбран */
#define CAN_Msg_93 0x005DUL           /*!< Объект сообщения 93 выбран */
#define CAN_Msg_94 0x005EUL           /*!< Объект сообщения 94 выбран */
#define CAN_Msg_95 0x005FUL           /*!< Объект сообщения 95 выбран */
#define CAN_Msg_96 0x0060UL           /*!< Объект сообщения 96 выбран */
#define CAN_Msg_97 0x0061UL           /*!< Объект сообщения 97 выбран */
#define CAN_Msg_98 0x0062UL           /*!< Объект сообщения 98 выбран */
#define CAN_Msg_99 0x0063UL           /*!< Объект сообщения 99 выбран */
#define CAN_Msg_100 0x0064UL           /*!< Объект сообщения 100 выбран */
#define CAN_Msg_101 0x0065UL           /*!< Объект сообщения 101 выбран */
#define CAN_Msg_102 0x0066UL           /*!< Объект сообщения 102 выбран */
#define CAN_Msg_103 0x0067UL           /*!< Объект сообщения 103 выбран */
#define CAN_Msg_104 0x0068UL           /*!< Объект сообщения 104 выбран */
#define CAN_Msg_105 0x0069UL           /*!< Объект сообщения 105 выбран */
#define CAN_Msg_106 0x006AUL           /*!< Объект сообщения 106 выбран */
#define CAN_Msg_107 0x006BUL           /*!< Объект сообщения 107 выбран */
#define CAN_Msg_108 0x006CUL           /*!< Объект сообщения 108 выбран */
#define CAN_Msg_109 0x006DUL           /*!< Объект сообщения 109 выбран */
#define CAN_Msg_110 0x006EUL           /*!< Объект сообщения 110 выбран */
#define CAN_Msg_111 0x006FUL           /*!< Объект сообщения 111 выбран */
#define CAN_Msg_112 0x0070UL           /*!< Объект сообщения 112 выбран */
#define CAN_Msg_113 0x0071UL           /*!< Объект сообщения 113 выбран */
#define CAN_Msg_114 0x0072UL           /*!< Объект сообщения 114 выбран */
#define CAN_Msg_115 0x0073UL           /*!< Объект сообщения 115 выбран */
#define CAN_Msg_116 0x0074UL           /*!< Объект сообщения 116 выбран */
#define CAN_Msg_117 0x0075UL           /*!< Объект сообщения 117 выбран */
#define CAN_Msg_118 0x0076UL           /*!< Объект сообщения 118 выбран */
#define CAN_Msg_119 0x0077UL           /*!< Объект сообщения 119 выбран */
#define CAN_Msg_120 0x0078UL           /*!< Объект сообщения 120 выбран */
#define CAN_Msg_121 0x0079UL           /*!< Объект сообщения 121 выбран */
#define CAN_Msg_122 0x007AUL           /*!< Объект сообщения 122 выбран */
#define CAN_Msg_123 0x007BUL           /*!< Объект сообщения 123 выбран */
#define CAN_Msg_124 0x007CUL           /*!< Объект сообщения 124 выбран */
#define CAN_Msg_125 0x007DUL           /*!< Объект сообщения 125 выбран */
#define CAN_Msg_126 0x007EUL           /*!< Объект сообщения 126 выбран */
#define CAN_Msg_127 0x007FUL           /*!< Объект сообщения 127 выбран */

#define IS_CAN_MSG(VALUE) (((VALUE)&0xFFFFFF80) == 0)

#define IS_GET_CAN_MSG(VALUE) (((VALUE) == CAN_Msg_0) ||  \
                                ((VALUE) == CAN_Msg_1) ||  \
                                ((VALUE) == CAN_Msg_2) ||  \
                                ((VALUE) == CAN_Msg_3) ||  \
                                ((VALUE) == CAN_Msg_4) ||  \
                                ((VALUE) == CAN_Msg_5) ||  \
                                ((VALUE) == CAN_Msg_6) ||  \
                                ((VALUE) == CAN_Msg_7) ||  \
                                ((VALUE) == CAN_Msg_8) ||  \
                                ((VALUE) == CAN_Msg_9) ||  \
                                ((VALUE) == CAN_Msg_10) ||  \
                                ((VALUE) == CAN_Msg_11) ||  \
                                ((VALUE) == CAN_Msg_12) ||  \
                                ((VALUE) == CAN_Msg_13) ||  \
                                ((VALUE) == CAN_Msg_14) ||  \
                                ((VALUE) == CAN_Msg_15) ||  \
                                ((VALUE) == CAN_Msg_16) ||  \
                                ((VALUE) == CAN_Msg_17) ||  \
                                ((VALUE) == CAN_Msg_18) ||  \
                                ((VALUE) == CAN_Msg_19) ||  \
                                ((VALUE) == CAN_Msg_20) ||  \
                                ((VALUE) == CAN_Msg_21) ||  \
                                ((VALUE) == CAN_Msg_22) ||  \
                                ((VALUE) == CAN_Msg_23) ||  \
                                ((VALUE) == CAN_Msg_24) ||  \
                                ((VALUE) == CAN_Msg_25) ||  \
                                ((VALUE) == CAN_Msg_26) ||  \
                                ((VALUE) == CAN_Msg_27) ||  \
                                ((VALUE) == CAN_Msg_28) ||  \
                                ((VALUE) == CAN_Msg_29) ||  \
                                ((VALUE) == CAN_Msg_30) ||  \
                                ((VALUE) == CAN_Msg_31) ||  \
                                ((VALUE) == CAN_Msg_32) ||  \
                                ((VALUE) == CAN_Msg_33) ||  \
                                ((VALUE) == CAN_Msg_34) ||  \
                                ((VALUE) == CAN_Msg_35) ||  \
                                ((VALUE) == CAN_Msg_36) ||  \
                                ((VALUE) == CAN_Msg_37) ||  \
                                ((VALUE) == CAN_Msg_38) ||  \
                                ((VALUE) == CAN_Msg_39) ||  \
                                ((VALUE) == CAN_Msg_40) ||  \
                                ((VALUE) == CAN_Msg_41) ||  \
                                ((VALUE) == CAN_Msg_42) ||  \
                                ((VALUE) == CAN_Msg_43) ||  \
                                ((VALUE) == CAN_Msg_44) ||  \
                                ((VALUE) == CAN_Msg_45) ||  \
                                ((VALUE) == CAN_Msg_46) ||  \
                                ((VALUE) == CAN_Msg_47) ||  \
                                ((VALUE) == CAN_Msg_48) ||  \
                                ((VALUE) == CAN_Msg_49) ||  \
                                ((VALUE) == CAN_Msg_50) ||  \
                                ((VALUE) == CAN_Msg_51) ||  \
                                ((VALUE) == CAN_Msg_52) ||  \
                                ((VALUE) == CAN_Msg_53) ||  \
                                ((VALUE) == CAN_Msg_54) ||  \
                                ((VALUE) == CAN_Msg_55) ||  \
                                ((VALUE) == CAN_Msg_56) ||  \
                                ((VALUE) == CAN_Msg_57) ||  \
                                ((VALUE) == CAN_Msg_58) ||  \
                                ((VALUE) == CAN_Msg_59) ||  \
                                ((VALUE) == CAN_Msg_60) ||  \
                                ((VALUE) == CAN_Msg_61) ||  \
                                ((VALUE) == CAN_Msg_62) ||  \
                                ((VALUE) == CAN_Msg_63) ||  \
                                ((VALUE) == CAN_Msg_64) ||  \
                                ((VALUE) == CAN_Msg_65) ||  \
                                ((VALUE) == CAN_Msg_66) ||  \
                                ((VALUE) == CAN_Msg_67) ||  \
                                ((VALUE) == CAN_Msg_68) ||  \
                                ((VALUE) == CAN_Msg_69) ||  \
                                ((VALUE) == CAN_Msg_70) ||  \
                                ((VALUE) == CAN_Msg_71) ||  \
                                ((VALUE) == CAN_Msg_72) ||  \
                                ((VALUE) == CAN_Msg_73) ||  \
                                ((VALUE) == CAN_Msg_74) ||  \
                                ((VALUE) == CAN_Msg_75) ||  \
                                ((VALUE) == CAN_Msg_76) ||  \
                                ((VALUE) == CAN_Msg_77) ||  \
                                ((VALUE) == CAN_Msg_78) ||  \
                                ((VALUE) == CAN_Msg_79) ||  \
                                ((VALUE) == CAN_Msg_80) ||  \
                                ((VALUE) == CAN_Msg_81) ||  \
                                ((VALUE) == CAN_Msg_82) ||  \
                                ((VALUE) == CAN_Msg_83) ||  \
                                ((VALUE) == CAN_Msg_84) ||  \
                                ((VALUE) == CAN_Msg_85) ||  \
                                ((VALUE) == CAN_Msg_86) ||  \
                                ((VALUE) == CAN_Msg_87) ||  \
                                ((VALUE) == CAN_Msg_88) ||  \
                                ((VALUE) == CAN_Msg_89) ||  \
                                ((VALUE) == CAN_Msg_90) ||  \
                                ((VALUE) == CAN_Msg_91) ||  \
                                ((VALUE) == CAN_Msg_92) ||  \
                                ((VALUE) == CAN_Msg_93) ||  \
                                ((VALUE) == CAN_Msg_94) ||  \
                                ((VALUE) == CAN_Msg_95) ||  \
                                ((VALUE) == CAN_Msg_96) ||  \
                                ((VALUE) == CAN_Msg_97) ||  \
                                ((VALUE) == CAN_Msg_98) ||  \
                                ((VALUE) == CAN_Msg_99) ||  \
                                ((VALUE) == CAN_Msg_100) ||  \
                                ((VALUE) == CAN_Msg_101) ||  \
                                ((VALUE) == CAN_Msg_102) ||  \
                                ((VALUE) == CAN_Msg_103) ||  \
                                ((VALUE) == CAN_Msg_104) ||  \
                                ((VALUE) == CAN_Msg_105) ||  \
                                ((VALUE) == CAN_Msg_106) ||  \
                                ((VALUE) == CAN_Msg_107) ||  \
                                ((VALUE) == CAN_Msg_108) ||  \
                                ((VALUE) == CAN_Msg_109) ||  \
                                ((VALUE) == CAN_Msg_110) ||  \
                                ((VALUE) == CAN_Msg_111) ||  \
                                ((VALUE) == CAN_Msg_112) ||  \
                                ((VALUE) == CAN_Msg_113) ||  \
                                ((VALUE) == CAN_Msg_114) ||  \
                                ((VALUE) == CAN_Msg_115) ||  \
                                ((VALUE) == CAN_Msg_116) ||  \
                                ((VALUE) == CAN_Msg_117) ||  \
                                ((VALUE) == CAN_Msg_118) ||  \
                                ((VALUE) == CAN_Msg_119) ||  \
                                ((VALUE) == CAN_Msg_120) ||  \
                                ((VALUE) == CAN_Msg_121) ||  \
                                ((VALUE) == CAN_Msg_122) ||  \
                                ((VALUE) == CAN_Msg_123) ||  \
                                ((VALUE) == CAN_Msg_124) ||  \
                                ((VALUE) == CAN_Msg_125) ||  \
                                ((VALUE) == CAN_Msg_126) ||  \
                                ((VALUE) == CAN_Msg_127))

/**
  * @}
  */

/** @defgroup CAN_INTLINE_Define Линии прерывания Can
  * @{
  */

#define CAN_INTLINE_0 0x0000UL           /*!< Линия прерывания 0 */
#define CAN_INTLINE_1 0x0001UL           /*!< Линия прерывания 1 */
#define CAN_INTLINE_2 0x0002UL           /*!< Линия прерывания 2 */
#define CAN_INTLINE_3 0x0003UL           /*!< Линия прерывания 3 */
#define CAN_INTLINE_4 0x0004UL           /*!< Линия прерывания 4 */
#define CAN_INTLINE_5 0x0005UL           /*!< Линия прерывания 5 */
#define CAN_INTLINE_6 0x0006UL           /*!< Линия прерывания 6 */
#define CAN_INTLINE_7 0x0007UL           /*!< Линия прерывания 7 */
#define CAN_INTLINE_8 0x0008UL           /*!< Линия прерывания 8 */
#define CAN_INTLINE_9 0x0009UL           /*!< Линия прерывания 9 */
#define CAN_INTLINE_10 0x000AUL          /*!< Линия прерывания 10 */
#define CAN_INTLINE_11 0x000BUL          /*!< Линия прерывания 11 */
#define CAN_INTLINE_12 0x000CUL          /*!< Линия прерывания 12 */
#define CAN_INTLINE_13 0x000DUL          /*!< Линия прерывания 13 */
#define CAN_INTLINE_14 0x000EUL          /*!< Линия прерывания 14 */
#define CAN_INTLINE_15 0x000FUL          /*!< Линия прерывания 15 */


#define IS_GET_CAN_INTLINE(VALUE) (((VALUE) == CAN_INTLINE_0) ||  \
                                   ((VALUE) == CAN_INTLINE_1) ||  \
                                   ((VALUE) == CAN_INTLINE_2) ||  \
                                   ((VALUE) == CAN_INTLINE_3) ||  \
                                   ((VALUE) == CAN_INTLINE_4) ||  \
                                   ((VALUE) == CAN_INTLINE_5) ||  \
                                   ((VALUE) == CAN_INTLINE_6) ||  \
                                   ((VALUE) == CAN_INTLINE_7) ||  \
                                   ((VALUE) == CAN_INTLINE_8) ||  \
                                   ((VALUE) == CAN_INTLINE_9) ||  \
                                   ((VALUE) == CAN_INTLINE_10) || \
                                   ((VALUE) == CAN_INTLINE_11) || \
                                   ((VALUE) == CAN_INTLINE_12) || \
                                   ((VALUE) == CAN_INTLINE_13) || \
                                   ((VALUE) == CAN_INTLINE_14) || \
								   ((VALUE) == CAN_INTLINE_15))

/**
  * @}
  */

/** @defgroup CAN_ITNodeSource_Define Источники прерываний узла CAN
  * @{
  */

#define CAN_ITNodeSource_TxRxEnd 	CAN_Node_NCR_TRIE_Msk    	/*!< Прерывание от узла по окончании передачи/приема */
#define CAN_ITNodeSource_LastErrorCode CAN_Node_NCR_LECIE_Msk   /*!< Прерывание от узла при обнаружении кода последней ошибки */
#define CAN_ITNodeSource_Alert 		CAN_Node_NCR_ALIE_Msk      	/*!< Прерывание ALERT от узла */
#define CAN_ITNodeSource_All (CAN_Node_NCR_TRIE_Msk |  \
							  CAN_Node_NCR_LECIE_Msk | \
							  CAN_Node_NCR_ALIE_Msk) /*!< Все источники выбраны */

#define IS_CAN_ITNodeSource_SOURCE(VALUE) (((VALUE) & ~CAN_ITNodeSource_All) == 0)

/**
  * @}
  */

/** @defgroup CAN_Node_Flag_Define Флаги узла CAN
  * @{
  */

#define CAN_Node_Flag_TxOk CAN_Node_NSR_TXOK_Msk            /*!< Флаг успешной передачи сообщения */
#define CAN_Node_Flag_RxOk CAN_Node_NSR_RXOK_Msk            /*!< Флаг успешного приема сообщения */
#define CAN_Node_Flag_Alert CAN_Node_NSR_ALERT_Msk          /*!< Флаг предупреждения ALERT */
#define CAN_Node_Flag_EWRNlevel CAN_Node_NSR_EWRN_Msk       /*!< Флаг критического количества ошибок */
#define CAN_Node_Flag_BusOff CAN_Node_NSR_BOFF_Msk          /*!< Флаг состояния "отключен от шины" */
#define CAN_Node_Flag_ListError CAN_Node_NSR_LLE_Msk        /*!< Флаг ошибки списка */
#define CAN_Node_Flag_ListNumError CAN_Node_NSR_LOE_Msk     /*!< Флаг ошибки номера списка */

#define IS_CAN_NODE_FLAG(VALUE) (((VALUE) == CAN_Node_Flag_TxOk) ||  \
                                 ((VALUE) == CAN_Node_Flag_RxOk) ||  \
                                 ((VALUE) == CAN_Node_Flag_Alert) ||  \
                                 ((VALUE) == CAN_Node_Flag_EWRNlevel) ||  \
                                 ((VALUE) == CAN_Node_Flag_BusOff) ||  \
                                 ((VALUE) == CAN_Node_Flag_ListError) ||  \
                                 ((VALUE) == CAN_Node_Flag_ListNumError))

/**
  * @}
  */


/** @defgroup CAN_Msg_Flag_Define Флаги объекта сообщения CAN
  * @{
  */

#define CAN_Msg_Flag_RxEnd CANMSG_Msg_MOSTAT_RXPND_Msk     /*!< Флаг окончания приема сообщения */
#define CAN_Msg_Flag_TxEnd CANMSG_Msg_MOSTAT_TXPND_Msk     /*!< Флаг окончания передачи сообщения */
#define CAN_Msg_Flag_RxUpdate CANMSG_Msg_MOSTAT_RXUPD_Msk  /*!< Флаг изменений параметров объекта сообщения */
#define CAN_Msg_Flag_NewData CANMSG_Msg_MOSTAT_NEWDAT_Msk  /*!< Флаг изменения данных объекта сообщения */
#define CAN_Msg_Flag_MsgLost CANMSG_Msg_MOSTAT_MSGLST_Msk  /*!< Флаг потери сообщения */
#define CAN_Msg_Flag_Active CANMSG_Msg_MOSTAT_MSGVAL_Msk   /*!< Флаг активности объекта сообщения */
#define CAN_Msg_Flag_RxTxSel  CANMSG_Msg_MOSTAT_RTSEL_Msk  /*!< Флаг возможности приема/передачи */
#define CAN_Msg_Flag_RxEnable  CANMSG_Msg_MOSTAT_RXEN_Msk  /*!< Флаг разрешения приема сообщения */
#define CAN_Msg_Flag_TxRemoteReqest CANMSG_Msg_MOSTAT_TXRQ_Msk  /*!< Флаг инициации передачи / флаг получения фрейма удаленного запроса */
#define CAN_Msg_Flag_TxEnable0 CANMSG_Msg_MOSTAT_TXEN0_Msk     /*!< Флаг 0 разрешения передачи фрейма */
#define CAN_Msg_Flag_TxEnable1 CANMSG_Msg_MOSTAT_TXEN1_Msk     /*!< Флаг 1 разрешения передачи фрейма */
#define CAN_Msg_Flag_Direction CANMSG_Msg_MOSTAT_DIR_Msk   /*!< Флаг распределения */

#define IS_CAN_MSG_FLAG(VALUE) (((VALUE) == CAN_Msg_Flag_RxEnd) ||  \
                                 ((VALUE) == CAN_Msg_Flag_TxEnd) ||  \
                                 ((VALUE) == CAN_Msg_Flag_RxUpdate) || \
                                 ((VALUE) == CAN_Msg_Flag_NewData) ||  \
                                 ((VALUE) == CAN_Msg_Flag_MsgLost) ||  \
                                 ((VALUE) == CAN_Msg_Flag_Active) ||  \
                                 ((VALUE) == CAN_Msg_Flag_RxTxSel) ||  \
                                 ((VALUE) == CAN_Msg_Flag_RxEnable) ||  \
                                 ((VALUE) == CAN_Msg_Flag_TxRemoteReqest) ||  \
                                 ((VALUE) == CAN_Msg_Flag_TxEnable0) ||  \
                                 ((VALUE) == CAN_Msg_Flag_TxEnable1) ||  \
                                 ((VALUE) == CAN_Msg_Flag_Direction))

/**
  * @}
  */


/** @defgroup CAN_ITMsgSource_Define Источники прерываний объектов сообщений CAN
  * @{
  */

#define CAN_ITMsgSource_TxEnd 	CANMSG_Msg_MOFCR_TXIE_Msk    	/*!< Прерывание от объектов сообщений по окончании передачи */
#define CAN_ITMsgSource_RxEnd 	CANMSG_Msg_MOFCR_RXIE_Msk    	/*!< Прерывание от объектов сообщений по окончании приема */
#define CAN_ITMsgSource_FIFOFull 	CANMSG_Msg_MOFCR_OVIE_Msk    	/*!< Прерывание от объектов сообщений по заполнению FIFO объекта сообщения */
#define CAN_ITMsgSource_All (CANMSG_Msg_MOFCR_TXIE_Msk |  \
							 CANMSG_Msg_MOFCR_RXIE_Msk | \
							 CANMSG_Msg_MOFCR_OVIE_Msk) /*!< Все источники выбраны */

#define IS_CAN_ITMsgSource_SOURCE(VALUE) (((VALUE) & ~CAN_ITNodeSource_All) == 0)

/**
  * @}
  */

/** @defgroup CAN_Exported_Types Типы
  * @{
  */

#define IS_CAN_FDR_STEP(VALUE) ((VALUE) < 0x400)
#define IS_CAN_MSG_ID(VALUE) ((VALUE) < 0x20000000)
#define IS_CAN_MSG_INTPEND_BITNUM(VALUE) ((VALUE) < 128)

/**
  * @brief  Выбор режима делителя частоты
  */
typedef enum {
    CAN_DivMode_Disable = CAN_FDR_DM_Disable,         /*!< Счетчик делителя частоты выключен */
    CAN_DivMode_Normal =  CAN_FDR_DM_NormalMode,      /*!< Нормальный режим работы */
    CAN_DivMode_FracDiv = CAN_FDR_DM_DividerMode,     /*!< Режим дробного деления */
    CAN_DivMode_FoutDis                               /*!< Синхросигнал FOUT не генерируется */  
} CAN_DivMode_TypeDef;
#define IS_CAN_DIVMODE_BIT(VALUE) (((VALUE) == CAN_DivMode_Disable) || \
                                   ((VALUE) == CAN_DivMode_Normal) ||  \
                                   ((VALUE) == CAN_DivMode_FracDiv) || \
                                   ((VALUE) == CAN_DivMode_FoutDis))

/**
  * @brief  Выбор команды в панели команд
  */
typedef enum {
    CAN_PanelCmd_Disable     = 0,                     /*!< Нет операции. Никаких действий не выполняется */
    CAN_PanelCmd_ListInit    = 1,                     /*!< Инициализация списков */
    CAN_PanelCmd_ListStaticAdd = 2,                     /*!< Статическое занесение объекта сообщения в список */
    CAN_PanelCmd_ListDynAdd  = 3,                     /*!< Динамическое занесение объекта сообщения в список. */
    CAN_PanelCmd_ListMoveUp  = 4,                     /*!< Перемещение по списку вверх */
    CAN_PanelCmd_ListInsertUp = 5,                    /*!< Динамическая вставка в список */
    CAN_PanelCmd_ListMoveDown   = 6,                  /*!< Перемещение по списку вниз */
    CAN_PanelCmd_ListInsertDown = 7                   /*!< Динамическая вставка в список */
} CAN_PanelCmd_TypeDef;
#define IS_GET_CAN_PANELCMD(VALUE) (((VALUE) == CAN_PanCmd_Disable) || \
                                   ((VALUE) == CAN_PanCmd_ListInit) || \
                                   ((VALUE) == CAN_PanCmd_ListStaticAdd) || \
                                   ((VALUE) == CAN_PanCmd_ListDynAdd) || \
                                   ((VALUE) == CAN_PanCmd_ListMoveUp) || \
                                   ((VALUE) == CAN_PanCmd_ListInsertUp) || \
                                   ((VALUE) == CAN_PanCmd_ListMoveDown) || \
                                   ((VALUE) == CAN_PanCmd_ListInsertDown))

/**
  * @brief  Флаги состояния панели команд
  */
typedef enum {
    CAN_PanelCmdState_Busy = CAN_PANCTR_BUSY_Msk,   /*!< Флаг занятости панелей аргументов */
    CAN_PanelCmdState_RBusy = CAN_PANCTR_RBUSY_Msk  /*!< Флаг занятости панелей аргументов */
} CAN_PanelCmdState_TypeDef;
#define IS_GET_CAN_PANELCMDSTATE(VALUE) (((VALUE) == CAN_PanelCmdState_Busy) || \
                                   	   	 ((VALUE) == CAN_PanelCmdState_RBusy))

/**
  * @brief  Флаги состояния узла
  */
typedef enum {
    CAN_NodeState_TXOK = CAN_Node_NSR_TXOK_Msk,        /*!< Флаг успешной передачи сообщения */
    CAN_NodeState_RXOK = CAN_Node_NSR_RXOK_Msk,        /*!< Флаг успешного приема сообщения */
    CAN_NodeState_ALERT = CAN_Node_NSR_ALERT_Msk,      /*!< Флаг предупреждения ALERT */
    CAN_NodeState_EWRN  = CAN_Node_NSR_EWRN_Msk,       /*!< Флаг критического количества ошибок */
    CAN_NodeState_BusOff = CAN_Node_NSR_BOFF_Msk,      /*!< Флаг состояния «отключен от шины» */
    CAN_NodeState_ListError = CAN_Node_NSR_LLE_Msk,    /*!< Флаг ошибки списка */
    CAN_NodeState_ListNumError = CAN_Node_NSR_LOE_Msk  /*!< Флаг ошибки номера списка */
} CAN_NodeState_TypeDef;

#define IS_GET_CAN_NODESTATE(VALUE) (((VALUE) == CAN_NodeState_TXOK) || \
                                   ((VALUE) == CAN_NodeState_RXOK) || \
                                   ((VALUE) == CAN_NodeState_ALERT) || \
                                   ((VALUE) == CAN_NodeState_EWRN) || \
                                   ((VALUE) == CAN_NodeState_BusOff) || \
                                   ((VALUE) == CAN_NodeState_ListError) || \
                                   ((VALUE) == CAN_NodeState_ListNumError))

/**
  * @brief  Коды последней из обнаруженных ошибок работы узла
  */
typedef enum {
    CAN_NodeLastErr_NO = 0,                              /*!< Ошибок нет */
    CAN_NodeLastErr_STUFF = 1,                           /*!< Ошибка стаффинга (STUFF ERROR). */
    CAN_NodeLastErr_FORM = 2,                            /*!< Ошибка формы (FORM ERROR) */
    CAN_NodeLastErr_ACKNOWL = 3,                         /*!< Ошибка подтверждения (ACKNOWLEGMENT ERROR) */
    CAN_NodeLastErr_BIT1 = 4,                            /*!< Разрядная ошибка или ошибка бита 1 (BIT 1 ERROR) */
    CAN_NodeLastErr_BIT0 = 5,                            /*!< Разрядная ошибка или ошибка бита 0 (BIT 0 ERROR) */
    CAN_NodeLastErr_CRC = 6,                             /*!< Ошибка циклического избыточного кода (CRC ERROR) */
    CAN_NodeLastErr_LECWREN = 7                          /*!< Код разрешения аппаратной записи в поле LEC */  
} CAN_NodeLastErr_TypeDef;

#define IS_GET_CAN_NODELASTERROR(VALUE) (((VALUE) == CAN_NodeLastErr_NO) || \
                                   ((VALUE) == CAN_NodeLastErr_STUFF) || \
                                   ((VALUE) == CAN_NodeLastErr_FORM) || \
                                   ((VALUE) == CAN_NodeLastErr_ACKNOWL) || \
                                   ((VALUE) == CAN_NodeLastErr_BIT1) || \
                                   ((VALUE) == CAN_NodeLastErr_BIT0) || \
                                   ((VALUE) == CAN_NodeLastErr_CRC) || \
                                   ((VALUE) == CAN_NodeLastErr_LECWREN))

/**
  * @brief  Количество передаваемых/принимаемых байт в объекте сообщения CAN
  */
typedef enum {
    CAN_MSG_DataLength_0 = 0,                   /*!< Длина данных 0 байт */
    CAN_MSG_DataLength_1 = 1,                   /*!< Длина данных 1 байт */
    CAN_MSG_DataLength_2 = 2,                   /*!< Длина данных 2 байт */
    CAN_MSG_DataLength_3 = 3,                   /*!< Длина данных 3 байт */
    CAN_MSG_DataLength_4 = 4,                   /*!< Длина данных 4 байт */
    CAN_MSG_DataLength_5 = 5,                   /*!< Длина данных 5 байт */
    CAN_MSG_DataLength_6 = 6,                   /*!< Длина данных 6 байт */
    CAN_MSG_DataLength_7 = 7,                   /*!< Длина данных 7 байт */
    CAN_MSG_DataLength_8 = 8,                   /*!< Длина данных 8 байт */  

} CAN_MSG_DataLength_TypeDef;
#define IS_CAN_MSG_DATA_LENGTH(VALUE) (((VALUE) == CAN_MSG_DataLength_0) || \
                                   ((VALUE) == CAN_MSG_DataLength_1) || \
                                   ((VALUE) == CAN_MSG_DataLength_2) || \
                                   ((VALUE) == CAN_MSG_DataLength_3) || \
                                   ((VALUE) == CAN_MSG_DataLength_4) || \
                                   ((VALUE) == CAN_MSG_DataLength_5) || \
                                   ((VALUE) == CAN_MSG_DataLength_6) || \
                                   ((VALUE) == CAN_MSG_DataLength_7) || \
                                   ((VALUE) == CAN_MSG_DataLength_8))

/**
  * @brief  Выбор режима объекта сообщения
  */
typedef enum {
    CAN_MSG_Mode_Standart = 0,                      /*!< Стандартный объект сообщения */
    CAN_MSG_Mode_BaseFifoRx  = 1,                   /*!< Базовый объект приемной структуры FIFO */
    CAN_MSG_Mode_BaseFifoTx = 2,                    /*!< Базовый объект передающей структуры FIFO */
    CAN_MSG_Mode_AddFifoTx = 3,                     /*!< Вспомогательный объект передающей структуры FIFO */
    CAN_MSG_Mode_SrcGate = 4,                       /*!< Объект-источник шлюза */
	CAN_MSG_Mode_RemoteReqest = 5                   /*!< Удаленный запрос */
} CAN_MSG_Mode_TypeDef;
#define IS_CAN_MSG_MODE(VALUE) (((VALUE) == CAN_MSG_Mode_Standart) || \
                                ((VALUE) == CAN_MSG_Mode_BaseFifoRx) || \
                                ((VALUE) == CAN_MSG_Mode_BaseFifoTx) || \
                                ((VALUE) == CAN_MSG_Mode_AddFifoTx) || \
                                ((VALUE) == CAN_MSG_Mode_SrcGate))

/**
  * @brief  Выбор размера идентификатора объекта сообщения
  */
typedef enum {
    CAN_MSG_FrameID_11 = 0,                          /*!< Фреймы со стандартным 11-битным идентификатором */
    CAN_MSG_FrameID_29 = 1                           /*!< Фреймы с расширенным 29-битным идентификатором */
} CAN_MSG_FrameID_TypeDef;
#define IS_CAN_MSG_FRAMEID_BIT(VALUE) (((VALUE) == CAN_MSG_FrameID_11) || \
                                       ((VALUE) == CAN_MSG_FrameID_29))

/**
  * @brief  Выбор класса приоритета объекта сообщения
  */
typedef enum {
    CAN_MSG_Pri_0 = 0,                          /*!< Приоритет сообщения 0 */
    CAN_MSG_Pri_1 = 1,                          /*!< Приоритет сообщения 1 */
    CAN_MSG_Pri_2 = 2,                          /*!< Приоритет сообщения 2 */
    CAN_MSG_Pri_3 = 3                           /*!< Приоритет сообщения 3 */
} CAN_MSG_Pri_TypeDef;
#define IS_CAN_MSG_PRI_BIT(VALUE) (((VALUE) == CAN_MSG_Pri_0) || \
                                   ((VALUE) == CAN_MSG_Pri_1) || \
                                   ((VALUE) == CAN_MSG_Pri_2) || \
                                   ((VALUE) == CAN_MSG_Pri_3))

/**
  * @brief  Выбор напрвления приема/передачи объекта сообщения
  */
typedef enum {
    CAN_MSG_Dir_Rx = 0,                          /*!< Объект приема сообщения данных */
    CAN_MSG_Dir_Tx = 1                           /*!< Объект передачи сообщения данных */
} CAN_MSG_Dir_TypeDef;
#define IS_CAN_MSG_DIR_BIT(VALUE) (((VALUE) == CAN_MSG_Dir_Rx) || \
                                   ((VALUE) == CAN_MSG_Dir_Tx))

/**
  * @brief   Флаги состояния объекта сообщения
  */
typedef enum {
    CAN_MsgState_RxEnd = CANMSG_Msg_MOSTAT_RXPND_Msk,     /*!< Флаг окончания приема */
    CAN_MsgState_TxEnd = CANMSG_Msg_MOSTAT_TXPND_Msk,     /*!< Флаг окончания передачи */
    CAN_MsgState_Update = CANMSG_Msg_MOSTAT_RXUPD_Msk,    /*!< Флаг изменения сообщения */
    CAN_MsgState_NewData  = CANMSG_Msg_MOSTAT_NEWDAT_Msk, /*!< Флаг новых данных */
    CAN_MsgState_Lost = CANMSG_Msg_MOSTAT_MSGLST_Msk,     /*!< Флаг потери сообщения */
    CAN_MsgState_Active = CANMSG_Msg_MOSTAT_MSGVAL_Msk,   /*!< Флаг активности объекта сообщения */
    CAN_MsgState_RxTxEnable = CANMSG_Msg_MOSTAT_RTSEL_Msk, /*!< Флаг возможности приема/передачи */
    CAN_MsgState_RxEnable = CANMSG_Msg_MOSTAT_RXEN_Msk,   /*!< Флаг разрешения приема */
    CAN_MsgState_TxRQ = CANMSG_Msg_MOSTAT_TXRQ_Msk,       /*!< Флаг инициации передачи */
    CAN_MsgState_TxEnable = CANMSG_Msg_MOSTAT_TXEN0_Msk|CANMSG_Msg_MOSTAT_TXEN1_Msk,     /*!< Флаг разрешения передачи фрейма */
    CAN_MsgState_DirRxTx = CANMSG_Msg_MOSTAT_DIR_Msk      /*!< Флаг распределения ообщения: прием, передача */
} CAN_MsgState_TypeDef;
#define IS_CAN_MSG_STATE_BIT(VALUE) (((VALUE) == CAN_MsgState_RxEnd) || \
                                    ((VALUE) == CAN_MsgState_TxEnd) || \
                                    ((VALUE) == CAN_MsgState_Update) || \
                                    ((VALUE) == CAN_MsgState_NewData) || \
                                    ((VALUE) == CAN_MsgState_Lost) || \
                                    ((VALUE) == CAN_MsgState_Active) || \
                                    ((VALUE) == CAN_MsgState_RxTxEnable) || \
                                    ((VALUE) == CAN_MsgState_RxEnable) || \
                                    ((VALUE) == CAN_MsgState_TxRQ) || \
                                    ((VALUE) == CAN_MsgState_TxEnable) || \
                                    ((VALUE) == CAN_MsgState_DirRxTx))

/**
  * @brief  Структура инициализации CAN
  */

typedef struct
{
    CAN_DivMode_TypeDef DivMode;      /*!< Выбор режима делителя частоты */
    uint32_t BaudRate;                /*!< Желаемая скорость передачи данных в бит/с */


    FunctionalState FIFO;             /*!< Разрешение режима FIFO буфера приемника и передатчика */
    FunctionalState Rx;               /*!< Разрешение приема */
    FunctionalState Tx;               /*!< Разрешение передачи */
} CAN_Init_TypeDef;

/**
  * @brief  Структура инициализации узла CAN
  */

typedef struct
{
    CAN_DivMode_TypeDef DivMode;      /*!< Выбор режима делителя частоты */
    uint32_t BaudRate;                /*!< Желаемая скорость передачи данных в бит/с */
    FunctionalState FIFO;             /*!< Разрешение режима FIFO буфера приемника и передатчика */
    FunctionalState Rx;               /*!< Разрешение приема */
    FunctionalState Tx;               /*!< Разрешение передачи */
} CAN_NODE_Init_TypeDef;

/**
  * @brief  Структура инициализации панели команд CAN
  */

typedef struct
{
	CAN_PanelCmd_TypeDef PanelCommand;	/*!< Команда */
    uint8_t Arg1; 						/*!< Аргумент 1 */
    uint8_t Arg2; 						/*!< Аргумент 2 */
} CAN_PANELCMD_Init_TypeDef;

/**
  * @brief  Структура инициализации списка CAN
  */

typedef struct
{
    uint8_t MsgFirst;				/*!< Номер первого объекта сообщения */
    uint8_t MsgLast; 				/*!< Номер последнего объекта сообщения */
} CAN_LIST_Init_TypeDef;
/**
  * @brief  Структура инициализации объекта сообщения CAN
  */

typedef struct
{
    uint32_t MsgID;                   /*!< Идентификатор объекта сообщения */
    CAN_MSG_Dir_TypeDef MsgDir;		  /*!< Направление сообщения */
    CAN_MSG_Mode_TypeDef MsgMode;	  /*!< Режим работы объекта сообщения */
    CAN_MSG_FrameID_TypeDef MsgFrameID;

    FunctionalState FIFO;             /*!< Разрешение режима FIFO буфера приемника и передатчика */
    FunctionalState Rx;               /*!< Разрешение приема */
    FunctionalState Tx;               /*!< Разрешение передачи */
} CAN_MSG_Init_TypeDef;

/**
  * @}
  */

/** @defgroup CAN_Exported_Functions Функции
  * @{
  */

/**
  * @brief   Разрешение работы модуля CAN
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void CAN_Cmd(FunctionalState State)
{
    assert_param(IS_FUNCTIONAL_STATE(State));
    if(State) WRITE_REG(CAN->CLC_bit.DISR, 0);
    else WRITE_REG(CAN->CLC_bit.DISR, 1);
}

/**
  * @brief   Запрос состояния контроллера CAN
  * @retval  Status  Состояние флага.
  */
__STATIC_INLINE FlagStatus CAN_Status()
{
    return (FlagStatus)READ_BIT(CAN->CLC, CAN_CLC_DISS_Msk);
}

/**
  * @brief   Запрос состояния выбранного флага панели команд
  * @param   Flag  Выбор флагов.
  *                Параметр принимает любую совокупность значений CAN_PanelCmdState_x из @ref CAN_PanelCmdState_TypeDef.
  * @retval  Status  Состояние флага. Если выбрано несколько флагов,
  *                  то результат соответсвует логическому ИЛИ их состояний.
  */
__STATIC_INLINE FlagStatus CAN_PANELCMD_FlagStatus(CAN_PanelCmdState_TypeDef Flag)
{
    assert_param(IS_GET_CAN_PANELCMDSTATE(Flag));

    return (FlagStatus)READ_BIT(CAN->PANCTR, Flag);
}

/**
  * @brief   Запрос текущей команды панели команд
  * @retval  CAN_PanelCmd_TypeDef  Команда панели команд
  */
__STATIC_INLINE CAN_PanelCmd_TypeDef CAN_PANELCMD_GetCommand()
{
    return (CAN_PanelCmd_TypeDef)READ_REG(CAN->PANCTR_bit.PANCMD);
}

/**
  * @brief   Установка значения делителя модуля CAN
  * @param   Val    Значение
  * @retval  void
  */
__STATIC_INLINE void CAN_DividerConfig(uint8_t Val)
{
    assert_param(IS_CAN_FDR_STEP(Val));

    WRITE_REG(CAN->FDR_bit.STEP, (0x400 - Val));
}

/**
  * @brief   Выбор режима делителя модуля CAN
  * @param   Val    Значение
  * @retval  void
  */
__STATIC_INLINE void CAN_DividerModeConfig(CAN_DivMode_TypeDef DivMode)
{
    assert_param(IS_CAN_DIVMODE_BIT(DivMode));

    WRITE_REG(CAN->FDR_bit.DM, DivMode);
}

/** @defgroup CAN_Exported_Functions_List Функции настройки списков CAN
  * @{
  */

void CAN_LIST_Init(uint8_t LISTx, CAN_LIST_Init_TypeDef* InitStruct);

/**
  * @}
  */


/** @defgroup CAN_Exported_Functions_Node Функции настройки узла CAN
  * @{
  */

/**
  * @brief   Разрешение работы узла модуля CAN
  * @param   Node   Выбор узла
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void CAN_NodeCmd(uint8_t NODEx, FunctionalState State)
{
    assert_param(IS_GET_CAN_NODE(NODEx));
    assert_param(IS_FUNCTIONAL_STATE(State));
    if(State) WRITE_REG(CAN->Node[NODEx].NCR_bit.CANDIS, 0);
    else WRITE_REG(CAN->Node[NODEx].NCR_bit.CANDIS, 1);
}

/**
  * @brief   Разрешение режима анализа узла модуля CAN
  * @param   Node   Выбор узла
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void CAN_NodeAnalyzeCmd(uint8_t NODEx, FunctionalState State)
{
    assert_param(IS_GET_CAN_NODE(NODEx));
    assert_param(IS_FUNCTIONAL_STATE(State));
    if(State) WRITE_REG(CAN->Node[NODEx].NCR_bit.CALM, 1);
    else WRITE_REG(CAN->Node[NODEx].NCR_bit.CALM, 0);
}

/**
  * @brief   Разрешение изменения конфигурации узла модуля CAN
  * @param   Node   Выбор узла
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void CAN_NodeConfigurationCmd(uint8_t NODEx, FunctionalState State)
{
    assert_param(IS_GET_CAN_NODE(NODEx));
    assert_param(IS_FUNCTIONAL_STATE(State));
    if(State) WRITE_REG(CAN->Node[NODEx].NCR_bit.CCE, 1);
    else WRITE_REG(CAN->Node[NODEx].NCR_bit.CCE, 0);
}

/**
  * @brief   Разрешение инициализации узла модуля CAN
  * @param   Node   Выбор узла
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void CAN_NodeInitCmd(uint8_t NODEx, FunctionalState State)
{
    assert_param(IS_GET_CAN_NODE(NODEx));
    assert_param(IS_FUNCTIONAL_STATE(State));
    if(State) WRITE_REG(CAN->Node[NODEx].NCR_bit.INIT, 1);
    else WRITE_REG(CAN->Node[NODEx].NCR_bit.INIT, 0);
}

/**
  * @brief   Включение режима обратной петли узла модуля CAN
  * @param   Node   Выбор узла
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void CAN_NodeLoopBackCmd(uint8_t NODEx, FunctionalState State)
{
    assert_param(IS_GET_CAN_NODE(NODEx));
    assert_param(IS_FUNCTIONAL_STATE(State));
    if(State) WRITE_REG(CAN->Node[NODEx].NPCR_bit.LBM, 1);
    else WRITE_REG(CAN->Node[NODEx].NPCR_bit.LBM, 0);
}

/**
  * @brief   Включение делителя частоты DIV8 узла модуля CAN
  * @param   Node   Выбор узла
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void CAN_NodeClkDiv8Cmd(uint8_t NODEx, FunctionalState State)
{
    assert_param(IS_GET_CAN_NODE(NODEx));
    assert_param(IS_FUNCTIONAL_STATE(State));
    if(State) WRITE_REG(CAN->Node[NODEx].NBTR_bit.DIV8, 1);
    else WRITE_REG(CAN->Node[NODEx].NBTR_bit.DIV8, 0);
}

/**
  * @brief   Установка значения парметра 1 длительности сегмента узла модуля CAN
  * @param   Node   Выбор узла
  * @param   Val    Значение
  * @retval  void
  */
__STATIC_INLINE void CAN_NodeClkTseg1Config(uint8_t NODEx, uint8_t Val)
{
    assert_param(IS_GET_CAN_NODE(NODEx));

    WRITE_REG(CAN->Node[NODEx].NBTR_bit.TSEG1, Val);
}

/**
  * @brief   Установка значения парметра 2 длительности сегмента узла модуля CAN
  * @param   Node   Выбор узла
  * @param   Val    Значение
  * @retval  void
  */
__STATIC_INLINE void CAN_NodeClkTseg2Config(uint8_t NODEx, uint8_t Val)
{
    assert_param(IS_GET_CAN_NODE(NODEx));

    WRITE_REG(CAN->Node[NODEx].NBTR_bit.TSEG2, Val);
}

/**
  * @brief   Установка значения ширины перехода ресинхронизации узла модуля CAN
  * @param   Node   Выбор узла
  * @param   Val    Значение
  * @retval  void
  */
__STATIC_INLINE void CAN_NodeClkSJWConfig(uint8_t NODEx, uint8_t Val)
{
    assert_param(IS_GET_CAN_NODE(NODEx));

    WRITE_REG(CAN->Node[NODEx].NBTR_bit.SJW, Val);
}

/**
  * @brief   Установка значения предделителя скорости передачи узла модуля CAN
  * @param   Node   Выбор узла
  * @param   Val    Значение
  * @retval  void
  */
__STATIC_INLINE void CAN_NodeClkBRPConfig(uint8_t NODEx, uint8_t Val)
{
    assert_param(IS_GET_CAN_NODE(NODEx));

    WRITE_REG(CAN->Node[NODEx].NBTR_bit.BRP, Val);
}

/**
  * @brief   Установка указателя прерывания при переполнении счетчика фреймов узла модуля CAN
  * @param   Node     Выбор узла
  * @param   IntLine  Номер линии прерывания CAN
  * @retval  void
  */
__STATIC_INLINE void CAN_Node_SetIntPointerFrameCount(uint8_t NODEx, uint32_t IntLine)
{
    assert_param(IS_GET_CAN_NODE(NODEx));
    assert_param(IS_GET_CAN_INTLINE(IntLine));
    WRITE_REG(CAN->Node[NODEx].NIPR_bit.CFCINP, IntLine);
}

/**
  * @brief   Получение указателя прерывания при переполнении счетчика фреймов узла модуля CAN
  * @param   Node Выбор узла
  * @retval  Val  Номер линии прерывания CAN
  */
__STATIC_INLINE uint32_t CAN_Node_GetIntPointerFrameCount(uint8_t NODEx)
{
    assert_param(IS_GET_CAN_NODE(NODEx));

    return READ_REG(CAN->Node[NODEx].NIPR_bit.CFCINP);
}

/**
  * @brief   Установка указателя прерывания по окончании передачи/приема сообщения узла модуля CAN
  * @param   Node     Выбор узла
  * @param   IntLine  Номер линии прерывания CAN
  * @retval  void
  */
__STATIC_INLINE void CAN_Node_SetIntPointerTxRxEnd(uint8_t NODEx, uint32_t IntLine)
{
    assert_param(IS_GET_CAN_NODE(NODEx));
    assert_param(IS_GET_CAN_INTLINE(IntLine));
    WRITE_REG(CAN->Node[NODEx].NIPR_bit.TRINP, IntLine);
}

/**
  * @brief   Получение указателя прерывания по окончании передачи/приема сообщения узла модуля CAN
  * @param   Node Выбор узла
  * @retval  Val  Номер линии прерывания CAN
  */
__STATIC_INLINE uint32_t CAN_Node_GetIntPointerTxRxEnd(uint8_t NODEx)
{
    assert_param(IS_GET_CAN_NODE(NODEx));

    return READ_REG(CAN->Node[NODEx].NIPR_bit.TRINP);
}

/**
  * @brief   Установка указателя прерывания при записи кода последней ошибки узла модуля CAN
  * @param   Node     Выбор узла
  * @param   IntLine  Номер линии прерывания CAN
  * @retval  void
  */
__STATIC_INLINE void CAN_Node_SetIntPointerLastErrorCode(uint8_t NODEx, uint32_t IntLine)
{
    assert_param(IS_GET_CAN_NODE(NODEx));
    assert_param(IS_GET_CAN_INTLINE(IntLine));
    WRITE_REG(CAN->Node[NODEx].NIPR_bit.LECINP, IntLine);
}

/**
  * @brief   Получение указателя прерывания при записи кода последней ошибки узла модуля CAN
  * @param   Node Выбор узла
  * @retval  Val  Номер линии прерывания CAN
  */
__STATIC_INLINE uint32_t CAN_Node_GetIntPointerLastErrorCode(uint8_t NODEx)
{
    assert_param(IS_GET_CAN_NODE(NODEx));

    return READ_REG(CAN->Node[NODEx].NIPR_bit.LECINP);
}

/**
  * @brief   Установка указателя прерывания ALERT узла модуля CAN
  * @param   Node     Выбор узла
  * @param   IntLine  Номер линии прерывания CAN
  * @retval  void
  */
__STATIC_INLINE void CAN_Node_SetIntPointerAlert(uint8_t NODEx, uint32_t IntLine)
{
    assert_param(IS_GET_CAN_NODE(NODEx));
    assert_param(IS_GET_CAN_INTLINE(IntLine));
    WRITE_REG(CAN->Node[NODEx].NIPR_bit.ALINP, IntLine);
}

/**
  * @brief   Получение указателя прерывания ALERT узла модуля CAN
  * @param   Node Выбор узла
  * @retval  Val  Номер линии прерывания CAN
  */
__STATIC_INLINE uint8_t CAN_Node_GetIntPointerAlert(uint8_t NODEx)
{
    assert_param(IS_GET_CAN_NODE(NODEx));

    return READ_REG(CAN->Node[NODEx].NIPR_bit.ALINP);
}

/**
  * @brief   Чтение статуса индикатора инкрементирования при последней ошибке узла модуля CAN
  * @param   Node    Выбор узла
  * @retval  Status  Статус
  */
__STATIC_INLINE uint8_t CAN_Node_LastErrorIncStatus(uint8_t NODEx)
{
    assert_param(IS_GET_CAN_NODE(NODEx));

    return (FlagStatus)READ_BIT(CAN->Node[NODEx].NECNT, CAN_Node_NECNT_LEINC_Msk);
}

/**
  * @brief   Чтение статуса последней ошибки передачи узла модуля CAN
  * @param   Node    Выбор узла
  * @retval  Status  Статус
  */
__STATIC_INLINE uint32_t CAN_Node_LastErrorTxRxStatus(uint8_t NODEx)
{
    assert_param(IS_GET_CAN_NODE(NODEx));

    return (FlagStatus)READ_BIT(CAN->Node[NODEx].NECNT, CAN_Node_NECNT_LETD_Msk);
}

/**
  * @brief   Установка лимита ошибок узла модуля CAN
  * @param   Node Выбор узла
  * @param   Val  Значение
  * @retval  void
  */
__STATIC_INLINE void CAN_Node_SetLimitError(uint8_t NODEx, uint32_t Val)
{
    assert_param(IS_GET_CAN_NODE(NODEx));
    assert_param(IS_GET_CAN_INTLINE(IntLine));
    WRITE_REG(CAN->Node[NODEx].NECNT_bit.EWRNLVL, Val);
}

/**
  * @brief   Получение лимита ошибок узла модуля CAN
  * @param   Node Выбор узла
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t CAN_Node_GetLimitError(uint8_t NODEx)
{
    assert_param(IS_GET_CAN_NODE(NODEx));

    return READ_REG(CAN->Node[NODEx].NECNT_bit.EWRNLVL);
}

/**
  * @brief   Установка счетчика ошибок передачи сообщений узла модуля CAN
  * @param   Node Выбор узла
  * @param   Val  Значение
  * @retval  void
  */
__STATIC_INLINE void CAN_Node_SetCountErrorTx(uint8_t NODEx, uint32_t Val)
{
    assert_param(IS_GET_CAN_NODE(NODEx));

    WRITE_REG(CAN->Node[NODEx].NECNT_bit.TEC, Val);
}

/**
  * @brief   Получение счетчика ошибок передачи сообщений узла модуля CAN
  * @param   Node Выбор узла
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t CAN_Node_GetCountErrorTx(uint8_t NODEx)
{
    assert_param(IS_GET_CAN_NODE(NODEx));

    return READ_REG(CAN->Node[NODEx].NECNT_bit.TEC);
}

/**
  * @brief   Установка счетчика ошибок приема сообщений узла модуля CAN
  * @param   Node Выбор узла
  * @param   Val  Значение
  * @retval  void
  */
__STATIC_INLINE void CAN_Node_SetCountErrorRx(uint8_t NODEx, uint32_t Val)
{
    assert_param(IS_GET_CAN_NODE(NODEx));

    WRITE_REG(CAN->Node[NODEx].NECNT_bit.REC, Val);
}

/**
  * @brief   Получение счетчика ошибок приема сообщений узла модуля CAN
  * @param   Node Выбор узла
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t CAN_Node_GetCountErrorRx(uint8_t NODEx)
{
    assert_param(IS_GET_CAN_NODE(NODEx));

    return READ_REG(CAN->Node[NODEx].NECNT_bit.REC);
}

/**
  * @brief   Установка счетчика сообщений узла модуля CAN
  * @param   Node Выбор узла
  * @param   Val  Значение
  * @retval  void
  */
__STATIC_INLINE void CAN_Node_SetCountMsg(uint8_t NODEx, uint32_t Val)
{
    assert_param(IS_GET_CAN_NODE(NODEx));

    WRITE_REG(CAN->Node[NODEx].NFCR_bit.CFC, Val);
}

/**
  * @brief   Получение счетчика сообщений узла модуля CAN
  * @param   Node Выбор узла
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t CAN_Node_GetCountMsg(uint8_t NODEx)
{
    assert_param(IS_GET_CAN_NODE(NODEx));

    return READ_REG(CAN->Node[NODEx].NFCR_bit.CFC);
}

/**
  * @brief   Чтение статуса переполнения счетчика сообщений узла модуля CAN
  * @param   Node    Выбор узла
  * @retval  Status  Статус
  */
__STATIC_INLINE uint32_t CAN_Node_OverflowCountMsgStatus(uint8_t NODEx)
{
    assert_param(IS_GET_CAN_NODE(NODEx));

    return (FlagStatus)READ_BIT(CAN->Node[NODEx].NECNT, CAN_Node_NECNT_LETD_Msk);
}

/**
  * @brief   Запрос кода последней обнаруженной ошибки
  * @param   Node  		Выбор узла
  * @retval  LastError  Код последней обнаруженной ошибки.
  */
__STATIC_INLINE CAN_NodeLastErr_TypeDef CAN_Node_GetLastErrorCode(uint8_t NODEx)
{
    assert_param(IS_GET_CAN_NODE(NODEx));

    return (CAN_NodeLastErr_TypeDef)READ_REG(CAN->Node[NODEx].NSR_bit.LEC);
}

/**
  * @brief   Маскирование выбранных прерываний узла CAN
  * @param   ITSource  Выбор прерываний.
  *                    Параметр принимает любую совокупность значений CAN_ITNodeSource_x из @ref CAN_ITNodeSource_Define.
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void CAN_Node_ITCmd(uint8_t NODEx, uint32_t ITSource, FunctionalState State)
{
	assert_param(IS_GET_CAN_NODE(NODEx));
    assert_param(IS_CAN_ITNodeSource_SOURCE(ITSource));

    MODIFY_REG(CAN->Node[NODEx].NCR, ITSource, State ? ITSource : 0);
}

/**
  * @}
  */


/** @defgroup CAN_Exported_Functions_Msg Функции настройки объекта сообщения CAN
  * @{
  */
void CAN_MSG_Init(uint8_t MSGx, CAN_MSG_Init_TypeDef* InitStruct);
void CAN_MSG_StartTransmit(uint8_t MSGx);
void CAN_MSG_StartReceive(uint8_t MSGx);

/**
  * @brief   Установка длины данных объекта сообщения модуля CAN
  * @param   MSGx       Выбор объекта сообщения
  * @param   DataLength  Количество байт данных
  * @retval  void
  */
__STATIC_INLINE void CAN_Msg_SetDataLength(uint8_t MSGx, CAN_MSG_DataLength_TypeDef DataLength)
{
    assert_param(IS_GET_CAN_MSG(MSGx));
    assert_param(IS_CAN_MSG_DATA_LENGTH(DataLength));

    WRITE_REG(CANMSG->Msg[MSGx].MOFCR_bit.DLC, (uint32_t)DataLength);
}

/**
  * @brief   Получение длины данных объекта сообщения модуля CAN
  * @param   MSGx Выбор объекта сообщения
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t CAN_Msg_GetDataLength(uint8_t MSGx)
{
    assert_param(IS_GET_CAN_MSG(MSGx));

    return (CAN_MSG_DataLength_TypeDef)READ_REG(CANMSG->Msg[MSGx].MOFCR_bit.DLC);
}

/**
  * @brief   Конфигурация флагов объекта сообщения модуля CAN
  * @param   MSGx Выбор объекта сообщения
  * @param   MsgFlagSet 	Выбор установки флага объекта сообщения
  * @param   MsgFlagReset 	Выбор сброса флага объекта сообщения
  * @retval  void
  */
__STATIC_INLINE void CAN_Msg_FlagConfig(uint8_t MSGx, uint32_t MsgFlagSet, uint32_t MsgFlagReset)
{
    assert_param(IS_GET_CAN_MSG(MSGx));
    assert_param(IS_CAN_MSG_FLAG(MsgFlagSet));
    assert_param(IS_CAN_MSG_FLAG(MsgFlagReset));

   	WRITE_REG(CANMSG->Msg[MSGx].MOCTR,((MsgFlagSet << CANMSG_Msg_MOCTR_SETRXPND_Pos)|MsgFlagReset));
}

/**
  * @brief   Включение  однократной передачи данных объекта сообщения модуля CAN
  * @param   MSGx   Выбор объекта сообщения
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void CAN_Msg_SingleTxCmd(uint8_t MSGx, FunctionalState State)
{
    assert_param(IS_GET_CAN_MSG(MSGx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    if(State) WRITE_REG(CANMSG->Msg[MSGx].MOFCR_bit.STT, 1);
    else WRITE_REG(CANMSG->Msg[MSGx].MOFCR_bit.STT, 0);
}

/**
  * @brief   Включение  однократного приема данных объекта сообщения модуля CAN
  * @param   MSGx   Выбор объекта сообщения
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void CAN_Msg_SingleRxCmd(uint8_t MSGx, FunctionalState State)
{
    assert_param(IS_GET_CAN_MSG(MSGx));
    assert_param(IS_FUNCTIONAL_STATE(State));
    if(State) WRITE_REG(CANMSG->Msg[MSGx].MOFCR_bit.SDT, 1);
    else WRITE_REG(CANMSG->Msg[MSGx].MOFCR_bit.SDT, 0);
}

/**
  * @brief   Включение удаленного мониторинга передачи объекта сообщения модуля CAN
  * @param   MSGx   Выбор объекта сообщения
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void CAN_Msg_RemoteMonitoringCmd(uint8_t MSGx, FunctionalState State)
{
    assert_param(IS_GET_CAN_MSG(MSGx));
    assert_param(IS_FUNCTIONAL_STATE(State));
    if(State) WRITE_REG(CANMSG->Msg[MSGx].MOFCR_bit.RMM, 1);
    else WRITE_REG(CANMSG->Msg[MSGx].MOFCR_bit.RMM, 0);
}

/**
  * @brief   Включение разрешения удаленного запроса объекта сообщения модуля CAN
  * @param   MSGx   Выбор объекта сообщения
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void CAN_Msg_RemoteRequestCmd(uint8_t MSGx, FunctionalState State)
{
    assert_param(IS_GET_CAN_MSG(MSGx));
    assert_param(IS_FUNCTIONAL_STATE(State));
    if(State) WRITE_REG(CANMSG->Msg[MSGx].MOFCR_bit.FRREN, 1);
    else WRITE_REG(CANMSG->Msg[MSGx].MOFCR_bit.FRREN, 0);
}

/**
  * @brief   Настройка режима объекта сообщения CAN
  * @param   MSGx  Выбор объекта сообщения, где x=0...255
  * @param   Mode  Значение выбранного режима
  * @retval  void
  */
__STATIC_INLINE void CAN_Msg_ModeConfig(uint8_t MSGx, CAN_MSG_Mode_TypeDef Mode)
{
    assert_param(IS_GET_CAN_MSG(MSGx));
    assert_param(IS_CAN_MSG_MODE(Mode));

    WRITE_REG(CANMSG->Msg[MSGx].MOFCR_bit.MMC, Mode);
}

/**
  * @brief   Включение расширения идентификатора объекта сообщения CAN
  * @param   MSGx  Выбор объекта сообщения, где x=0...127
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void CAN_Msg_ExtendedIdCmd(uint8_t MSGx, FunctionalState State)
{
    assert_param(IS_GET_CAN_MSG(MSGx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    WRITE_REG(CANMSG->Msg[MSGx].MOAR_bit.IDE, State);
}

/**
  * @brief   Настройка идентификатора объекта сообщения CAN
  * @param   MSGx  Выбор объекта сообщения, где x=0...127
  * @param   ID    Значение выбранного режима
  * @retval  void
  */
__STATIC_INLINE void CAN_Msg_IdConfig(uint8_t MSGx, uint32_t ID)
{
    assert_param(IS_GET_CAN_MSG(MSGx));
    assert_param(IS_CAN_MSG_ID(ID));

    WRITE_REG(CANMSG->Msg[MSGx].MOAR_bit.ID, ID);
}

/**
  * @brief   Настройка направления (прием/передача) объекта сообщения CAN
  * @param   MSGx  Выбор объекта сообщения, где x=0...255
  * @param   Dir   Значение выбранного напрвления
  * @retval  void
  */
__STATIC_INLINE void CAN_Msg_DirConfig(uint8_t MSGx, CAN_MSG_Dir_TypeDef Dir)
{
    assert_param(IS_GET_CAN_MSG(MSGx));
    assert_param(IS_CAN_MSG_DIR_BIT(Dir));

    if(Dir==CAN_MSG_Dir_Tx) WRITE_REG(CANMSG->Msg[MSGx].MOCTR, CANMSG_Msg_MOCTR_SETDIR_Msk);
    else WRITE_REG(CANMSG->Msg[MSGx].MOCTR, CANMSG_Msg_MOCTR_RESDIR_Msk);
}

/**
  * @brief   Включение разрешения передачи объекта сообщения модуля CAN
  * @param   MSGx   Выбор объекта сообщения
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void CAN_Msg_TxEnableCmd(uint8_t MSGx, FunctionalState State)
{
    assert_param(IS_GET_CAN_MSG(MSGx));
    assert_param(IS_FUNCTIONAL_STATE(State));
    if(State) WRITE_REG(CANMSG->Msg[MSGx].MOCTR, (CANMSG_Msg_MOCTR_SETTXEN1_Msk|CANMSG_Msg_MOCTR_SETTXEN0_Msk));
    else WRITE_REG(CANMSG->Msg[MSGx].MOCTR, CANMSG_Msg_MOCTR_RESTXEN0_Msk);
}

/**
  * @brief   Включение инициации передачи объекта сообщения модуля CAN
  * @param   MSGx   Выбор объекта сообщения
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void CAN_Msg_TxInitCmd(uint8_t MSGx, FunctionalState State)
{
    assert_param(IS_GET_CAN_MSG(MSGx));
    assert_param(IS_FUNCTIONAL_STATE(State));
    if(State) WRITE_REG(CANMSG->Msg[MSGx].MOCTR, CANMSG_Msg_MOCTR_SETTXRQ_Msk);
    else WRITE_REG(CANMSG->Msg[MSGx].MOCTR, CANMSG_Msg_MOCTR_RESTXRQ_Msk);
}

/**
  * @brief   Включение разрешения приема объекта сообщения модуля CAN
  * @param   MSGx   Выбор объекта сообщения
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void CAN_Msg_RxEnableCmd(uint8_t MSGx, FunctionalState State)
{
    assert_param(IS_GET_CAN_MSG(MSGx));
    assert_param(IS_FUNCTIONAL_STATE(State));
    if(State) WRITE_REG(CANMSG->Msg[MSGx].MOCTR, CANMSG_Msg_MOCTR_SETRXEN_Msk);
    else WRITE_REG(CANMSG->Msg[MSGx].MOCTR, CANMSG_Msg_MOCTR_RESRXEN_Msk);
}

/**
  * @brief   Включение разрешения приема/передачи объекта сообщения модуля CAN
  * @param   MSGx   Выбор объекта сообщения
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void CAN_Msg_RxTxEnableCmd(uint8_t MSGx, FunctionalState State)
{
    assert_param(IS_GET_CAN_MSG(MSGx));
    assert_param(IS_FUNCTIONAL_STATE(State));
    if(State) WRITE_REG(CANMSG->Msg[MSGx].MOCTR, CANMSG_Msg_MOCTR_SETRTSEL_Msk);
    else WRITE_REG(CANMSG->Msg[MSGx].MOCTR, CANMSG_Msg_MOCTR_RESRTSEL_Msk);
}

/**
  * @brief   Включение активности объекта сообщения модуля CAN
  * @param   MSGx   Выбор объекта сообщения
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void CAN_Msg_EnableCmd(uint8_t MSGx, FunctionalState State)
{
    assert_param(IS_GET_CAN_MSG(MSGx));
    assert_param(IS_FUNCTIONAL_STATE(State));
    if(State) WRITE_REG(CANMSG->Msg[MSGx].MOCTR, CANMSG_Msg_MOCTR_SETMSGVAL_Msk);
    else WRITE_REG(CANMSG->Msg[MSGx].MOCTR, CANMSG_Msg_MOCTR_RESMSGVAL_Msk);
}

/**
  * @brief   Включение новых данных объекта сообщения модуля CAN
  * @param   MSGx   Выбор объекта сообщения
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void CAN_Msg_NewDataCmd(uint8_t MSGx, FunctionalState State)
{
    assert_param(IS_GET_CAN_MSG(MSGx));
    assert_param(IS_FUNCTIONAL_STATE(State));
    if(State) WRITE_REG(CANMSG->Msg[MSGx].MOCTR, CANMSG_Msg_MOCTR_SETNEWDAT_Msk);
    else WRITE_REG(CANMSG->Msg[MSGx].MOCTR, CANMSG_Msg_MOCTR_RESNEWDAT_Msk);
}

/**
  * @brief   Включение окончания передачи объекта сообщения модуля CAN
  * @param   MSGx   Выбор объекта сообщения
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void CAN_Msg_TxEndCmd(uint8_t MSGx, FunctionalState State)
{
    assert_param(IS_GET_CAN_MSG(MSGx));
    assert_param(IS_FUNCTIONAL_STATE(State));
    if(State) WRITE_REG(CANMSG->Msg[MSGx].MOCTR, CANMSG_Msg_MOCTR_SETTXPND_Msk);
    else WRITE_REG(CANMSG->Msg[MSGx].MOCTR, CANMSG_Msg_MOCTR_RESTXPND_Msk);
}

/**
  * @brief   Включение окончания приема объекта сообщения модуля CAN
  * @param   MSGx   Выбор объекта сообщения
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void CAN_Msg_RxEndCmd(uint8_t MSGx, FunctionalState State)
{
    assert_param(IS_GET_CAN_MSG(MSGx));
    assert_param(IS_FUNCTIONAL_STATE(State));
    if(State) WRITE_REG(CANMSG->Msg[MSGx].MOCTR, CANMSG_Msg_MOCTR_SETRXPND_Msk);
    else WRITE_REG(CANMSG->Msg[MSGx].MOCTR, CANMSG_Msg_MOCTR_RESRXPND_Msk);
}

/**
  * @brief   Включение изменений объекта сообщения модуля CAN
  * @param   MSGx   Выбор объекта сообщения
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void CAN_Msg_RxСhangCmd(uint8_t MSGx, FunctionalState State)
{
    assert_param(IS_GET_CAN_MSG(MSGx));
    assert_param(IS_FUNCTIONAL_STATE(State));

    if(State) WRITE_REG(CANMSG->Msg[MSGx].MOCTR, CANMSG_Msg_MOCTR_SETRXUPD_Msk);
    else WRITE_REG(CANMSG->Msg[MSGx].MOCTR, CANMSG_Msg_MOCTR_RESRXUPD_Msk);
}



/**
  * @brief   Установка младшего двойного слова данных объекта сообщения модуля CAN
  * @param   MSGx   Выбор объекта сообщения
  * @param   Val    Значение
  * @retval  void
  */
__STATIC_INLINE void CAN_Msg_SetDataLo(uint8_t MSGx, uint32_t Val)
{
    assert_param(IS_GET_CAN_MSG(MSGx));

    WRITE_REG(CANMSG->Msg[MSGx].MODATAL, Val);
}

/**
  * @brief   Получение младшего двойного слова данных объекта сообщения модуля CAN
  * @param   MSGx Выбор объекта сообщения
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t CAN_Msg_GetDataLo(uint8_t MSGx)
{
    assert_param(IS_GET_CAN_MSG(MSGx));

    return READ_REG(CANMSG->Msg[MSGx].MODATAL);
}

/**
  * @brief   Установка старшего двойного слова данных объекта сообщения модуля CAN
  * @param   MSGx   Выбор объекта сообщения
  * @param   Val    Значение
  * @retval  void
  */
__STATIC_INLINE void CAN_Msg_SetDataHi(uint8_t MSGx, uint32_t Val)
{
    assert_param(IS_GET_CAN_MSG(MSGx));

    WRITE_REG(CANMSG->Msg[MSGx].MODATAH, Val);
}

/**
  * @brief   Получение старшего двойного слова данных объекта сообщения модуля CAN
  * @param   MSGx Выбор объекта сообщения
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t CAN_Msg_GetDataHi(uint8_t MSGx)
{
    assert_param(IS_GET_CAN_MSG(MSGx));

    return READ_REG(CANMSG->Msg[MSGx].MODATAH);
}

/**
  * @brief   Получение номера списка объекта сообщения модуля CAN
  * @param   MSGx Выбор объекта сообщения
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t CAN_Msg_GetList(uint8_t MSGx)
{
    assert_param(IS_GET_CAN_MSG(MSGx));

    return READ_REG(CANMSG->Msg[MSGx].MOSTAT_bit.LIST);
}

/**
  * @brief   Получение указателя следующего объекта сообщения текущего списка модуля CAN
  * @param   MSGx Выбор объекта сообщения
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t CAN_Msg_GetNextMsg(uint8_t MSGx)
{
    assert_param(IS_GET_CAN_MSG(MSGx));

    return READ_REG(CANMSG->Msg[MSGx].MOSTAT_bit.PNEXT);
}

/**
  * @brief   Получение указателя предыдующего объекта сообщения текущего списка модуля CAN
  * @param   MSGx Выбор объекта сообщения
  * @retval  Val  Значение
  */
__STATIC_INLINE uint32_t CAN_Msg_GetPreviousMsg(uint8_t MSGx)
{
    assert_param(IS_GET_CAN_MSG(MSGx));

    return READ_REG(CANMSG->Msg[MSGx].MOSTAT_bit.PPREV);
}

/**
  * @brief   Настройка ждущего сообщения модуля CAN
  * @param   MSGx  Выбор объекта сообщения, где x от 0 до 127
  * @param   BitNum  Номер бита ожидания от 0 до 127
  * @retval  void
  */
__STATIC_INLINE void CAN_Msg_PendingConfig(uint8_t MSGx, uint8_t BitNum)
{
	assert_param(IS_GET_CAN_MSG(MSGx));
    assert_param(IS_CAN_MSG_INTPEND_BITNUM(BitNum));

    WRITE_REG(CANMSG->Msg[MSGx].MOIPR_bit.MPN, BitNum);
}

/**
  * @brief   Запрос состояния ждущего сообщения модуля CAN
  * @param   BitNum  Номер бита ожидания от 0 до 127
  * @retval  Status  Состояние флага.
  */
__STATIC_INLINE FlagStatus CAN_Msg_PendingStatus(uint8_t BitNum)
{
    assert_param(IS_CAN_MSG_INTPEND_BITNUM(BitNum));

    if (CAN->MSPND[BitNum>>5].MSPND & (1 << (BitNum & 0x1F))) return SET;
    else return CLEAR;
}

/**
  * @brief   Очистка ждущего сообщения модуля CAN
  * @param   BitNum  Номер бита ожидания от 0 до 127
  * @retval  void
  */
__STATIC_INLINE void CAN_Msg_PendingClear(uint8_t BitNum)
{
    assert_param(IS_CAN_MSG_INTPEND_BITNUM(BitNum));

    CLEAR_BIT(CAN->MSPND[BitNum>>5].MSPND, (1 << (BitNum & 0x1F)));
}

/**
  * @brief   Запрос состояния выбранного флага
  * @param   MSGx  Выбор объекта сообщения, где x от 0 до 127
  * @param   Flag  Выбор флагов.
  *                Параметр принимает любую совокупность значений CAN_MsgState_x из @ref CAN_MsgState_TypeDef.
  * @retval  Status  Состояние флага. Если выбрано несколько флагов,
  *                  то результат соответсвует логическому ИЛИ их состояний.
  */
__STATIC_INLINE FlagStatus CAN_FlagStatus(uint8_t MSGx, CAN_MsgState_TypeDef Flag)
{
    assert_param(IS_GET_CAN_MSG(MSGx));
    assert_param(IS_CAN_MSG_STATE_BIT(Flag));

    return (FlagStatus)READ_BIT(CANMSG->Msg[MSGx].MOSTAT, Flag);
}

/**
  * @brief   Маскирование выбранных прерываний объекта сообщений CAN
  * @param   MSGx  Выбор объекта сообщения, где x от 0 до 127
  * @param   ITSource  Выбор прерываний.
  *                    Параметр принимает любую совокупность значений CAN_ITNodeSource_x из @ref CAN_ITNodeSource_Define.
  * @param   State  Выбор состояния
  * @retval  void
  */
__STATIC_INLINE void CAN_Msg_ITCmd(uint8_t MSGx, uint32_t ITSource, FunctionalState State)
{
	assert_param(IS_GET_CAN_MSG(MSGx));
    assert_param(IS_CAN_ITMsgSource_SOURCE(ITSource));

    MODIFY_REG(CANMSG->Msg[MSGx].MOFCR, ITSource, State ? ITSource : 0);
}

/**
  * @brief   Установка указателя прерывания по окончании передачи объекта сообщения модуля CAN
  * @param   MSGx  Выбор объекта сообщения, где x от 0 до 127
  * @param   IntLine  Номер линии прерывания CAN
  * @retval  void
  */
__STATIC_INLINE void CAN_Msg_SetIntPointerTxEnd(uint8_t MSGx, uint32_t IntLine)
{
	assert_param(IS_GET_CAN_MSG(MSGx));
    assert_param(IS_GET_CAN_INTLINE(IntLine));

    WRITE_REG(CANMSG->Msg[MSGx].MOIPR_bit.TXINP, IntLine);
}

/**
  * @brief   Установка указателя прерывания по окончании приема объекта сообщения модуля CAN
  * @param   MSGx  Выбор объекта сообщения, где x от 0 до 127
  * @param   IntLine  Номер линии прерывания CAN
  * @retval  void
  */
__STATIC_INLINE void CAN_Msg_SetIntPointerRxEnd(uint8_t MSGx, uint32_t IntLine)
{
	assert_param(IS_GET_CAN_MSG(MSGx));
    assert_param(IS_GET_CAN_INTLINE(IntLine));

    WRITE_REG(CANMSG->Msg[MSGx].MOIPR_bit.RXINP, IntLine);
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

#endif /* __PLIB5T_CAN_H */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2025 NIIET *****END OF FILE****/
