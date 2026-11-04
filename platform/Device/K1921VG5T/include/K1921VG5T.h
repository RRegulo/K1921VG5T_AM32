/*****************************************************************************
 * @file:    K1921VG5T.h
 * @author   NIIET
 * @version: V1.1
 * @date:    30.06.2025
 * @brief:   K1921VG5T header file
 *****************************************************************************
 *
 * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 * TIME. AS A RESULT, NIIET NOT BE HELD LIABLE FOR ANY DIRECT,
 * INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
 * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
 * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 *
 * <h2><center>&copy; COPYRIGHT 2025 NIIET </center></h2>
 *****************************************************************************
 * FILE K1921VG5T.h
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __K1921VG5T_H
#define __K1921VG5T_H

#define __I     volatile const                /*!< defines 'read only' permissions      */
#define __O     volatile                      /*!< defines 'write only' permissions     */
#define __IO    volatile                      /*!< defines 'read / write' permissions   */

#include "stdint.h"

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/
/*                   Plic  Interrupt Number Definition                        */
/******************************************************************************/

typedef enum Plic_IsrVect {
    IsrVect_IRQ_0 = 0x0,
/*-- Device specific Interrupt Numbers ---------------------------------------*/
    IsrVect_IRQ_WDT                       = 1, /* Watchdog timer interrupt */
    IsrVect_IRQ_RCU                       = 2, /* Reset Clock unit interrupt */
    IsrVect_IRQ_RTC                       = 3, /* Real-Time Clock interrupt */
    IsrVect_IRQ_FLASH                     = 4, /* FLASH interrupt */
    IsrVect_IRQ_GPIOA                     = 5, /* GPIO A interrupt */
    IsrVect_IRQ_GPIOB                     = 6, /* GPIO B interrupt */
    IsrVect_IRQ_CAN0                      = 7, /* CAN0 interrupt */
    IsrVect_IRQ_CAN1                      = 8, /* CAN1 interrupt */
    IsrVect_IRQ_CAN2                      = 9, /* CAN2 interrupt */
    IsrVect_IRQ_CAN3                      = 10, /* CAN3 interrupt */
    IsrVect_IRQ_CAN4                      = 11, /* CAN4 interrupt */
    IsrVect_IRQ_CAN5                      = 12, /* CAN5 interrupt */
    IsrVect_IRQ_CAN6                      = 13, /* CAN6 interrupt */
    IsrVect_IRQ_CAN7                      = 14, /* CAN7 interrupt */
    IsrVect_IRQ_CAN8                      = 15, /* CAN8 interrupt */
    IsrVect_IRQ_CAN9                      = 16, /* CAN9 interrupt */
    IsrVect_IRQ_CAN10                     = 17, /* CAN10 interrupt */
    IsrVect_IRQ_CAN11                     = 18, /* CAN11 interrupt */
    IsrVect_IRQ_CAN12                     = 19, /* CAN12 interrupt */
    IsrVect_IRQ_CAN13                     = 20, /* CAN13 interrupt */
    IsrVect_IRQ_CAN14                     = 21, /* CAN14 interrupt */
    IsrVect_IRQ_CAN15                     = 22, /* CAN15 interrupt */
    IsrVect_IRQ_DMA_CH0                   = 23, /* DMA channel 0 interrupt */
    IsrVect_IRQ_DMA_CH1                   = 24, /* DMA channel 1 interrupt */
    IsrVect_IRQ_DMA_CH2                   = 25, /* DMA channel 2 interrupt */
    IsrVect_IRQ_DMA_CH3                   = 26, /* DMA channel 3 interrupt */
    IsrVect_IRQ_DMA_CH4                   = 27, /* DMA channel 4 interrupt */
    IsrVect_IRQ_DMA_CH5                   = 28, /* DMA channel 5 interrupt */
    IsrVect_IRQ_DMA_CH6                   = 29, /* DMA channel 6 interrupt */
    IsrVect_IRQ_DMA_CH7                   = 30, /* DMA channel 7 interrupt */
    IsrVect_IRQ_DMA_CH8                   = 31, /* DMA channel 8 interrupt */
    IsrVect_IRQ_DMA_CH9                   = 32, /* DMA channel 9 interrupt */
    IsrVect_IRQ_DMA_CH10                  = 33, /* DMA channel 10 interrupt */
    IsrVect_IRQ_DMA_CH11                  = 34, /* DMA channel 11 interrupt */
    IsrVect_IRQ_DMA_CH12                  = 35, /* DMA channel 12 interrupt */
    IsrVect_IRQ_DMA_CH13                  = 36, /* DMA channel 13 interrupt */
    IsrVect_IRQ_DMA_CH14                  = 37, /* DMA channel 14 interrupt */
    IsrVect_IRQ_DMA_CH15                  = 38, /* DMA channel 15 interrupt */
    IsrVect_IRQ_CAP0                      = 39, /* Capture unit 0 interrupt */
    IsrVect_IRQ_CAP1                      = 40, /* Capture unit 1 interrupt */
    IsrVect_IRQ_CAP2                      = 41, /* Capture unit 2 interrupt */
    IsrVect_IRQ_TMR0                      = 42, /* Timer 0 combine interrupt */
    IsrVect_IRQ_TMR0_PERIOD               = 43, /* Timer 0 period interrupt */
    IsrVect_IRQ_TMR0_CC0                  = 44, /* Timer 0 CAPCOM 0 interrupt */
    IsrVect_IRQ_TMR0_CC1                  = 45, /* Timer 0 CAPCOM 1 interrupt */
    IsrVect_IRQ_TMR1                      = 46, /* Timer 1 combine interrupt */
    IsrVect_IRQ_TMR1_PERIOD               = 47, /* Timer 1 period interrupt */
    IsrVect_IRQ_TMR1_CC0                  = 48, /* Timer 1 CAPCOM 0 interrupt */
    IsrVect_IRQ_TMR1_CC1                  = 49, /* Timer 1 CAPCOM 1 interrupt */
    IsrVect_IRQ_TMR2                      = 50, /* Timer 2 combine interrupt */
    IsrVect_IRQ_TMR2_PERIOD               = 51, /* Timer 2 period interrupt */
    IsrVect_IRQ_TMR2_CC0                  = 52, /* Timer 2 CAPCOM 0 interrupt */
    IsrVect_IRQ_TMR2_CC1                  = 53, /* Timer 2 CAPCOM 1 interrupt */
    IsrVect_IRQ_TMR3                      = 54, /* Timer 3 combine interrupt */
    IsrVect_IRQ_TMR3_PERIOD               = 55, /* Timer 3 period interrupt */
    IsrVect_IRQ_TMR3_CC0                  = 56, /* Timer 3 CAPCOM 0 interrupt */
    IsrVect_IRQ_TMR3_CC1                  = 57, /* Timer 3 CAPCOM 1 interrupt */
    IsrVect_IRQ_I2C                       = 58, /* I2C interrupt */
    IsrVect_IRQ_QEP                       = 59, /* QEP interrupt */
    IsrVect_IRQ_ADC_SEQ0                  = 60, /* ADC Sequencer 0 interrupt */
    IsrVect_IRQ_ADC_SEQ1                  = 61, /* ADC Sequencer 1 interrupt */
    IsrVect_IRQ_ADC_DC0                   = 62, /* ADC Digital Comparator 0 interrupt */
    IsrVect_IRQ_ADC_DC1                   = 63, /* ADC Digital Comparator 1 interrupt */
    IsrVect_IRQ_ADC_DC2                   = 64, /* ADC Digital Comparator 2 interrupt */
    IsrVect_IRQ_ADC_DC3                   = 65, /* ADC Digital Comparator 3 interrupt */
    IsrVect_IRQ_SPI0                      = 66, /* SPI0 interrupt */
    IsrVect_IRQ_SPI0_RX                   = 67, /* SPI0 Receive interrupt */
    IsrVect_IRQ_SPI0_TX                   = 68, /* SPI0 Transmit interrupt */
    IsrVect_IRQ_SPI0_RO                   = 69, /* SPI0 Receive Overrun interrupt */
    IsrVect_IRQ_SPI0_RT                   = 70, /* SPI0 Receive Timeout interrupt */
    IsrVect_IRQ_SPI1                      = 71, /* SPI1 interrupt */
    IsrVect_IRQ_SPI1_RX                   = 72, /* SPI1 Receive interrupt */
    IsrVect_IRQ_SPI1_TX                   = 73, /* SPI1 Transmit interrupt */
    IsrVect_IRQ_SPI1_RO                   = 74, /* SPI1 Receive Overrun interrupt */
    IsrVect_IRQ_SPI1_RT                   = 75, /* SPI1 Receive Timeout interrupt */
    IsrVect_IRQ_UART0                     = 76, /* UART0 interrupt */
    IsrVect_IRQ_UART0_TD                  = 77, /* UART0 Transmit Done interrupt */
    IsrVect_IRQ_UART0_RX                  = 78, /* UART0 Recieve interrupt */
    IsrVect_IRQ_UART0_TX                  = 79, /* UART0 Transmit interrupt */
    IsrVect_IRQ_UART0_RT                  = 80, /* UART0 Recieve interrupt */
    IsrVect_IRQ_UART0_E                   = 81, /* UART0 Error interrupt */
    IsrVect_IRQ_UART1                     = 82, /* UART1 interrupt */
    IsrVect_IRQ_UART1_TD                  = 83, /* UART1 Transmit Done interrupt */
    IsrVect_IRQ_UART1_RX                  = 84, /* UART1 Recieve interrupt */
    IsrVect_IRQ_UART1_TX                  = 85, /* UART1 Transmit interrupt */
    IsrVect_IRQ_UART1_RT                  = 86, /* UART1 Recieve interrupt */
    IsrVect_IRQ_UART1_E                   = 87, /* UART1 Error interrupt */
    IsrVect_IRQ_PWM0                      = 88, /* PWM0 interrupt */
    IsrVect_IRQ_PWM0_HD                   = 89, /* PWM0 HD interrupt */
    IsrVect_IRQ_PWM0_TZ                   = 90, /* PWM0 TZ interrupt */
    IsrVect_IRQ_PWM1                      = 91, /* PWM1 interrupt */
    IsrVect_IRQ_PWM1_HD                   = 92, /* PWM1 HD interrupt */
    IsrVect_IRQ_PWM1_TZ                   = 93, /* PWM1 TZ interrupt */
    IsrVect_IRQ_PWM2                      = 94, /* PWM2 interrupt */
    IsrVect_IRQ_PWM2_HD                   = 95, /* PWM2 HD interrupt */
    IsrVect_IRQ_PWM2_TZ                   = 96, /* PWM2 TZ interrupt */
    IsrVect_IRQ_RTC_ALARM1                = 97, /* RTC_ALARM1 interrupt */
    IsrVect_IRQ_RTC_ALARM2                = 98, /* RTC_ALARM2 interrupt */
    IsrVect_IRQ_RTC_BAT                   = 99, /* RTC_BAT interrupt */
    IsrVect_IRQ_RTC_POWEROK               = 100, /* RTC_POWEROK interrupt */
    IsrVect_IRQ_                          = 101, /*  */
} Plic_IsrVect_TypeDef;


//#include <system_K1921__MOTOR_S.h>        /* System initialization   			      */

/******************************************************************************/
/*                         System Specific Defenitions                        */
/******************************************************************************/
/*--  System memory ----------------------------------------------------------*/
/*--  Flash size: 512kb (512 pages x 1Kb, UM 9.1), RAM size: 16Kb ------------*/
#define MEM_FLASH_BASE                       0x00000000UL
#define MEM_FLASH_BUS_WIDTH_WORDS            2UL
#define MEM_FLASH_PAGE_SIZE                  1024UL
#define MEM_FLASH_PAGE_SIZE_LOG2             10UL
#define MEM_FLASH_PAGE_TOTAL                 512UL
#define MEM_FLASH_SIZE                       (MEM_FLASH_PAGE_TOTAL*MEM_FLASH_PAGE_SIZE)
/*--  NVR area: 16 pages x 1Kb (UM 9.1), controller access only (NVRON=1) ----*/
#define MEM_FLASH_NVR_PAGE_SIZE              (MEM_FLASH_PAGE_SIZE)
#define MEM_FLASH_NVR_PAGE_SIZE_LOG2         (MEM_FLASH_PAGE_SIZE_LOG2)
#define MEM_FLASH_NVR_PAGE_TOTAL             16UL
#define MEM_FLASH_NVR_SIZE                   (MEM_FLASH_NVR_PAGE_TOTAL*MEM_FLASH_NVR_PAGE_SIZE)
#define MEM_RAM0_BASE                         0x20000000UL
#define MEM_RAM0_SIZE                         0x4000UL

/*--  CFGWORD: System configure word -----------------------------------------*/
/* Last cell of the 16th NVR page (UM 9.1): 0x0007_FFF8 */
#define CFGWORD_BASE                          0x0007FFF8UL

typedef struct {
    uint32_t JTAGEN               : 1;                              /*!< Enable JTAG pins (default 1 - enabled) */
    uint32_t CFGWE                : 1;                              /*!< CFG (NVR) flash region write enable (default 1 - enabled) */
    uint32_t FLASHWE              : 1;                              /*!< Main flash region write enable (default 1 - enabled) */
} CFGWORD_bits;

/* Bit field positions: */
#define CFGWORD_JTAGEN_Pos                    2                      /*!< Enable JTAG pins (default 1 - enabled) */
#define CFGWORD_CFGWE_Pos                     1                      /*!< CFG (NVR) flash region write enable (default 1 - enabled) */
#define CFGWORD_FLASHWE_Pos                   0                      /*!< Main flash region write enable (default 1 - enabled) */

/* Bit field masks: */
#define CFGWORD_JTAGEN_Msk                    0x00000004UL           /*!< Enable JTAG pins (default 1 - enabled) */
#define CFGWORD_CFGWE_Msk                     0x00000002UL           /*!< CFG (NVR) flash region write enable (default 1 - enabled) */
#define CFGWORD_FLASHWE_Msk                   0x00000001UL           /*!< Main flash region write enable (default 1 - enabled) */

/******************************************************************************/
/*                         DMA channel parameters                             */
/******************************************************************************/

/*--  BUFFER_SIZE: DMA channel Size of buffer (Not Block) to transfer --------------------------------*/
typedef struct {
    uint32_t BUFFSIZE             : 16;                              /*!< The operating mode of the DMA cycle */

} _CHANNEL_BUFFER_SIZE_bits;

/* Bit field positions: */
#define DMA_CHANNEL_BUFFER_SIZE_BUFFSIZE_Pos        0                /*!< The operating mode of the DMA cycle */

/* Bit field masks: */
#define DMA_CHANNEL_BUFFER_SIZE_BUFFSIZE_Msk        0x0000FFFFUL     /*!< The operating mode of the DMA cycle */

/*--  BLOCK_SIZE: DMA channel Size of buffer (Block) to transfer --------------------------------*/
typedef struct {
    uint32_t XSIZE             : 8;                               /*!< Block width */
    uint32_t YSIZE             : 8;                               /*!< Number of block lines */
} _CHANNEL_BLOCK_SIZE_bits;

/* Bit field positions: */
#define DMA_CHANNEL_BLOCK_SIZE_XSIZE_Pos        0                 /*!< The operating mode of the DMA cycle */
#define DMA_CHANNEL_BLOCK_SIZE_YSIZE_Pos        8                 /*!< The operating mode of the DMA cycle */

/* Bit field masks: */
#define DMA_CHANNEL_BLOCK_SIZE_XSIZE_Msk        0x000000FFUL      /*!< The operating mode of the DMA cycle */
#define DMA_CHANNEL_BLOCK_SIZE_YSIZE_Msk        0x0000FF00UL      /*!< The operating mode of the DMA cycle */

/*--  CHANNEL_CFG: DMA channel configure --------------------------------*/
typedef struct {
    uint32_t INTEN             : 1;                               /*!< Enable interrupt */
    uint32_t LAST              : 1;                               /*!< Last command in list */
    uint32_t NEXTPTR           : 30;                              /*!< Next command pointer */
} _CHANNEL_CFG_bits;

/* Bit field positions: */
#define DMA_CHANNEL_CFG_INTEN_Pos        0                 /*!< Enable interrupt DMA cycle */
#define DMA_CHANNEL_CFG_LAST_Pos         1                 /*!< Last command in list */
#define DMA_CHANNEL_CFG_NEXTPTR_Pos      2                 /*!< Next pointer DMA cycle */

/* Bit field masks: */
#define DMA_CHANNEL_CFG_INTEN_Msk        0x00000001UL      /*!< The operating mode of the DMA cycle */
#define DMA_CHANNEL_CFG_LAST_Msk         0x00000002UL      /*!< The operating mode of the DMA cycle */
#define DMA_CHANNEL_CFG_NEXTPTR_Msk      0xFFFFFFFCUL      /*!< The operating mode of the DMA cycle */

/*--  DMA channel structure --------------------------------------------------*/
typedef struct
{
    __IO uint32_t SRC_DATA_END_PTR;                                       /*!< Source data end pointer */
    __IO uint32_t DST_DATA_END_PTR;                                       /*!< Destination data end pointer */
    union {
        __IO uint32_t BUFFER_SIZE;                                        /*!< Channel Size of buffer to transfer */
        __IO _CHANNEL_BUFFER_SIZE_bits BUFFER_SIZE_bit;                   /*!< channel Size of buffer to transfer: bit access */
        __IO uint32_t BLOCK_SIZE;                                         /*!< Channel Size of buffer to transfer */
        __IO _CHANNEL_BLOCK_SIZE_bits BLOCK_SIZE_bit;                     /*!< channel Size of buffer to transfer: bit access */
    };
    union {
        __IO uint32_t CHANNEL_CFG;                                        /*!< Channel configure word */
        __IO _CHANNEL_CFG_bits CHANNEL_CFG_bit;                           /*!< channel configure word: bit access */
    };
} DMA_Channel_TypeDef;

#define MEMORY_DMA_REQUESTOR_IDX    0                                       /*!<Default requestor*/
#define SPI0_DMA_REQUESTOR_IDX      1
#define SPI1_DMA_REQUESTOR_IDX      2
#define UART0_DMA_REQUESTOR_IDX     3
#define UART1_DMA_REQUESTOR_IDX     4
#define TMR0_DMA_REQUESTOR_IDX      5
#define TMR1_DMA_REQUESTOR_IDX      6
#define TMR2_DMA_REQUESTOR_IDX      7
#define TMR3_DMA_REQUESTOR_IDX      8
#define ADCSEQ0_DMA_REQUESTOR_IDX   9
#define ADCSEQ1_DMA_REQUESTOR_IDX   10
#define GPIOA_DMA_REQUESTOR_IDX     11
#define GPIOB_DMA_REQUESTOR_IDX     12
#define PWM0_DMA_REQUESTOR_IDX      13
#define PWM1_DMA_REQUESTOR_IDX      14
#define PWM2_DMA_REQUESTOR_IDX      15
#define QEP_DMA_REQUESTOR_IDX       16
#define CAP0_DMA_REQUESTOR_IDX      17
#define CAP1_DMA_REQUESTOR_IDX      18
#define CAP2_DMA_REQUESTOR_IDX      19


/******************************************************************************/
/*                         ADC registers                                      */
/******************************************************************************/

/*--  SEQEN: Enable sequencer register ------------------------------------------------------------------------*/
typedef struct {
  uint32_t SEQEN0                 :1;                                /*!< Enable sequencer 0 */
  uint32_t SEQEN1                 :1;                                /*!< Enable sequencer 1 */
} _ADC_SEQEN_bits;

/* Bit field positions: */
#define ADC_SEQEN_SEQEN0_Pos                  0                      /*!< Enable sequencer 0 */
#define ADC_SEQEN_SEQEN1_Pos                  1                      /*!< Enable sequencer 1 */

/* Bit field masks: */
#define ADC_SEQEN_SEQEN0_Msk                  0x00000001UL           /*!< Enable sequencer 0 */
#define ADC_SEQEN_SEQEN1_Msk                  0x00000002UL           /*!< Enable sequencer 1 */

/*--  SEQSYNC: Sequencer sync register ------------------------------------------------------------------------*/
typedef struct {
  uint32_t SYNC0                  :1;                                /*!< Enable sequencer 0 software sync */
  uint32_t SYNC1                  :1;                                /*!< Enable sequencer 1 software sync */
  uint32_t                        :29;                               /*!< RESERVED */
  uint32_t GSYNC                  :1;                                /*!< Sync all sequencers */
} _ADC_SEQSYNC_bits;

/* Bit field positions: */
#define ADC_SEQSYNC_SYNC0_Pos                 0                      /*!< Enable sequencer 0 software sync */
#define ADC_SEQSYNC_SYNC1_Pos                 1                      /*!< Enable sequencer 1 software sync */
#define ADC_SEQSYNC_GSYNC_Pos                 31                     /*!< Sync all sequencers */

/* Bit field masks: */
#define ADC_SEQSYNC_SYNC0_Msk                 0x00000001UL           /*!< Enable sequencer 0 software sync */
#define ADC_SEQSYNC_SYNC1_Msk                 0x00000002UL           /*!< Enable sequencer 1 software sync */
#define ADC_SEQSYNC_GSYNC_Msk                 0x80000000UL           /*!< Sync all sequencers */

/*--  FSTAT: FIFO overflow status register --------------------------------------------------------------------*/
typedef struct {
  uint32_t OV0                    :1;                                /*!< Sequencer 0 FIFO overflow */
  uint32_t OV1                    :1;                                /*!< Sequencer 1 FIFO overflow */
  uint32_t                        :6;                                /*!< RESERVED */
  uint32_t UN0                    :1;                                /*!< Sequencer 0 FIFO underflow */
  uint32_t UN1                    :1;                                /*!< Sequencer 1 FIFO underflow */
  uint32_t                        :6;                                /*!< RESERVED */
  uint32_t DOV0                   :1;                                /*!< Sequencer 0 FIFO DMA request overflow */
  uint32_t DOV1                   :1;                                /*!< Sequencer 1 FIFO DMA request overflow */
} _ADC_FSTAT_bits;

/* Bit field positions: */
#define ADC_FSTAT_OV0_Pos                     0                      /*!< Sequencer 0 FIFO overflow */
#define ADC_FSTAT_OV1_Pos                     1                      /*!< Sequencer 1 FIFO overflow */
#define ADC_FSTAT_UN0_Pos                     8                      /*!< Sequencer 0 FIFO underflow */
#define ADC_FSTAT_UN1_Pos                     9                      /*!< Sequencer 1 FIFO underflow */
#define ADC_FSTAT_DOV0_Pos                    16                     /*!< Sequencer 0 FIFO DMA request overflow */
#define ADC_FSTAT_DOV1_Pos                    17                     /*!< Sequencer 1 FIFO DMA request overflow */

/* Bit field masks: */
#define ADC_FSTAT_OV0_Msk                     0x00000001UL           /*!< Sequencer 0 FIFO overflow */
#define ADC_FSTAT_OV1_Msk                     0x00000002UL           /*!< Sequencer 1 FIFO overflow */
#define ADC_FSTAT_UN0_Msk                     0x00000100UL           /*!< Sequencer 0 FIFO underflow */
#define ADC_FSTAT_UN1_Msk                     0x00000200UL           /*!< Sequencer 1 FIFO underflow */
#define ADC_FSTAT_DOV0_Msk                    0x00010000UL           /*!< Sequencer 0 FIFO DMA request overflow */
#define ADC_FSTAT_DOV1_Msk                    0x00020000UL           /*!< Sequencer 1 FIFO DMA request overflow */

/*--  BSTAT: Busy status register -----------------------------------------------------------------------------*/
typedef struct {
  uint32_t SEQBUSY0               :1;                                /*!< Sequencer 0 busy */
  uint32_t SEQBUSY1               :1;                                /*!< Sequencer 1 busy */
  uint32_t                        :14;                               /*!< RESERVED */
  uint32_t ADCBUSY                :1;                                /*!< ADC module 0 conversion busy */
} _ADC_BSTAT_bits;

/* Bit field positions: */
#define ADC_BSTAT_SEQBUSY0_Pos                0                      /*!< Sequencer 0 busy */
#define ADC_BSTAT_SEQBUSY1_Pos                1                      /*!< Sequencer 1 busy */
#define ADC_BSTAT_ADCBUSY_Pos                 16                     /*!< ADC module 0 conversion busy */

/* Bit field masks: */
#define ADC_BSTAT_SEQBUSY0_Msk                0x00000001UL           /*!< Sequencer 0 busy */
#define ADC_BSTAT_SEQBUSY1_Msk                0x00000002UL           /*!< Sequencer 1 busy */
#define ADC_BSTAT_ADCBUSY_Msk                 0x00010000UL           /*!< ADC module 0 conversion busy */

/*--  DCTRIG: Digital comparator output trigger status register -----------------------------------------------*/
typedef struct {
  uint32_t TOS0                   :1;                                /*!< DC 0 output trigger status */
  uint32_t TOS1                   :1;                                /*!< DC 1 output trigger status */
  uint32_t TOS2                   :1;                                /*!< DC 2 output trigger status */
  uint32_t TOS3                   :1;                                /*!< DC 3 output trigger status */
} _ADC_DCTRIG_bits;

/* Bit field positions: */
#define ADC_DCTRIG_TOS0_Pos                   0                      /*!< DC 0 output trigger status */
#define ADC_DCTRIG_TOS1_Pos                   1                      /*!< DC 1 output trigger status */
#define ADC_DCTRIG_TOS2_Pos                   2                      /*!< DC 2 output trigger status */
#define ADC_DCTRIG_TOS3_Pos                   3                      /*!< DC 3 output trigger status */

/* Bit field masks: */
#define ADC_DCTRIG_TOS0_Msk                   0x00000001UL           /*!< DC 0 output trigger status */
#define ADC_DCTRIG_TOS1_Msk                   0x00000002UL           /*!< DC 1 output trigger status */
#define ADC_DCTRIG_TOS2_Msk                   0x00000004UL           /*!< DC 2 output trigger status */
#define ADC_DCTRIG_TOS3_Msk                   0x00000008UL           /*!< DC 3 output trigger status */

/*--  DCEV: Digital comparator compare event status register --------------------------------------------------*/
typedef struct {
  uint32_t DCEV0                  :1;                                /*!< Digital compare event 0 */
  uint32_t DCEV1                  :1;                                /*!< Digital compare event 1 */
  uint32_t DCEV2                  :1;                                /*!< Digital compare event 2 */
  uint32_t DCEV3                  :1;                                /*!< Digital compare event 3 */
} _ADC_DCEV_bits;

/* Bit field positions: */
#define ADC_DCEV_DCEV0_Pos                    0                      /*!< Digital compare event 0 */
#define ADC_DCEV_DCEV1_Pos                    1                      /*!< Digital compare event 1 */
#define ADC_DCEV_DCEV2_Pos                    2                      /*!< Digital compare event 2 */
#define ADC_DCEV_DCEV3_Pos                    3                      /*!< Digital compare event 3 */

/* Bit field masks: */
#define ADC_DCEV_DCEV0_Msk                    0x00000001UL           /*!< Digital compare event 0 */
#define ADC_DCEV_DCEV1_Msk                    0x00000002UL           /*!< Digital compare event 1 */
#define ADC_DCEV_DCEV2_Msk                    0x00000004UL           /*!< Digital compare event 2 */
#define ADC_DCEV_DCEV3_Msk                    0x00000008UL           /*!< Digital compare event 3 */

/*--  CICNT: Interrupt counter clear control ------------------------------------------------------------------*/
typedef struct {
  uint32_t ICNT0                  :1;                                /*!< Clear interrupt counter on sequencer 0 start */
  uint32_t ICNT1                  :1;                                /*!< Clear interrupt counter on sequencer 1 start */
} _ADC_CICNT_bits;

/* Bit field positions: */
#define ADC_CICNT_ICNT0_Pos                   0                      /*!< Clear interrupt counter on sequencer 0 start */
#define ADC_CICNT_ICNT1_Pos                   1                      /*!< Clear interrupt counter on sequencer 1 start */

/* Bit field masks: */
#define ADC_CICNT_ICNT0_Msk                   0x00000001UL           /*!< Clear interrupt counter on sequencer 0 start */
#define ADC_CICNT_ICNT1_Msk                   0x00000002UL           /*!< Clear interrupt counter on sequencer 1 start */

/*--  EMUX: Sequencer start event selection register ----------------------------------------------------------*/
typedef struct {
  uint32_t EM0                    :4;                                /*!< Select start event for sequencer 0 */
  uint32_t EM1                    :4;                                /*!< Select start event for sequencer 1 */
} _ADC_EMUX_bits;

/* Bit field positions: */
#define ADC_EMUX_EM0_Pos                      0                      /*!< Select start event for sequencer 0 */
#define ADC_EMUX_EM1_Pos                      4                      /*!< Select start event for sequencer 1 */

/* Bit field masks: */
#define ADC_EMUX_EM0_Msk                      0x0000000FUL           /*!< Select start event for sequencer 0 */
#define ADC_EMUX_EM1_Msk                      0x000000F0UL           /*!< Select start event for sequencer 1 */

/* Bit field enums: */
typedef enum {
  ADC_EMUX_EM0_SwReq                         = 0x0UL,                /*!< software request by GSYNC bit */
  ADC_EMUX_EM0_GPIOA                         = 0x1UL,                /*!< GPIOA request */
  ADC_EMUX_EM0_GPIOB                         = 0x2UL,                /*!< GPIOB request */
  ADC_EMUX_EM0_TMR0                          = 0x3UL,                /*!< Timer 0 request */
  ADC_EMUX_EM0_TMR1                          = 0x4UL,                /*!< Timer 1 request */
  ADC_EMUX_EM0_TMR2                          = 0x5UL,                /*!< Timer 2 request */
  ADC_EMUX_EM0_TMR3                          = 0x6UL,                /*!< Timer 3 request */
  ADC_EMUX_EM0_PWM0A                         = 0x7UL,                /*!< PWM0 chanel A request */
  ADC_EMUX_EM0_PWM0B                         = 0x8UL,                /*!< PWM0 chanel B request */
  ADC_EMUX_EM0_PWM1A                         = 0x9UL,                /*!< PWM1 chanel A request */
  ADC_EMUX_EM0_PWM1B                         = 0xAUL,                /*!< PWM1 chanel B request */
  ADC_EMUX_EM0_PWM2A                         = 0xBUL,                /*!< PWM2 chanel A request */
  ADC_EMUX_EM0_PWM2B                         = 0xCUL,                /*!< PWM2 chanel B request */
  ADC_EMUX_EM0_Cycle                         = 0xFUL,                /*!< Cycle mode */
} ADC_EMUX_EM0_Enum;

typedef enum {
  ADC_EMUX_EM1_SwReq                         = 0x0UL,                /*!< software request by GSYNC bit */
  ADC_EMUX_EM1_GPIOA                         = 0x1UL,                /*!< GPIOA request */
  ADC_EMUX_EM1_GPIOB                         = 0x2UL,                /*!< GPIOB request */
  ADC_EMUX_EM1_TMR0                          = 0x3UL,                /*!< Timer 0 request */
  ADC_EMUX_EM1_TMR1                          = 0x4UL,                /*!< Timer 1 request */
  ADC_EMUX_EM1_TMR2                          = 0x5UL,                /*!< Timer 2 request */
  ADC_EMUX_EM1_TMR3                          = 0x6UL,                /*!< Timer 3 request */
  ADC_EMUX_EM1_PWM0A                         = 0x7UL,                /*!< PWM0 chanel A request */
  ADC_EMUX_EM1_PWM0B                         = 0x8UL,                /*!< PWM0 chanel B request */
  ADC_EMUX_EM1_PWM1A                         = 0x9UL,                /*!< PWM1 chanel A request */
  ADC_EMUX_EM1_PWM1B                         = 0xAUL,                /*!< PWM1 chanel B request */
  ADC_EMUX_EM1_PWM2A                         = 0xBUL,                /*!< PWM2 chanel A request */
  ADC_EMUX_EM1_PWM2B                         = 0xCUL,                /*!< PWM2 chanel B request */
  ADC_EMUX_EM1_Cycle                         = 0xFUL,                /*!< Cycle mode */
} ADC_EMUX_EM1_Enum;

/*--  RIS: Raw interrupt status register ----------------------------------------------------------------------*/
typedef struct {
  uint32_t SEQRIS0                :1;                                /*!< Sequencer 0 raw interrupt status */
  uint32_t SEQRIS1                :1;                                /*!< Sequencer 1 raw interrupt status */
  uint32_t                        :6;                                /*!< RESERVED */
  uint32_t DCRIS0                 :1;                                /*!< Raw interrupt status of Digital Comparator 0 */
  uint32_t DCRIS1                 :1;                                /*!< Raw interrupt status of Digital Comparator 1 */
  uint32_t DCRIS2                 :1;                                /*!< Raw interrupt status of Digital Comparator 2 */
  uint32_t DCRIS3                 :1;                                /*!< Raw interrupt status of Digital Comparator 3 */
} _ADC_RIS_bits;

/* Bit field positions: */
#define ADC_RIS_SEQRIS0_Pos                   0                      /*!< Sequencer 0 raw interrupt status */
#define ADC_RIS_SEQRIS1_Pos                   1                      /*!< Sequencer 1 raw interrupt status */
#define ADC_RIS_DCRIS0_Pos                    8                      /*!< Raw interrupt status of Digital Comparator 0 */
#define ADC_RIS_DCRIS1_Pos                    9                      /*!< Raw interrupt status of Digital Comparator 1 */
#define ADC_RIS_DCRIS2_Pos                    10                     /*!< Raw interrupt status of Digital Comparator 2 */
#define ADC_RIS_DCRIS3_Pos                    11                     /*!< Raw interrupt status of Digital Comparator 3 */

/* Bit field masks: */
#define ADC_RIS_SEQRIS0_Msk                   0x00000001UL           /*!< Sequencer 0 raw interrupt status */
#define ADC_RIS_SEQRIS1_Msk                   0x00000002UL           /*!< Sequencer 1 raw interrupt status */
#define ADC_RIS_DCRIS0_Msk                    0x00000100UL           /*!< Raw interrupt status of Digital Comparator 0 */
#define ADC_RIS_DCRIS1_Msk                    0x00000200UL           /*!< Raw interrupt status of Digital Comparator 1 */
#define ADC_RIS_DCRIS2_Msk                    0x00000400UL           /*!< Raw interrupt status of Digital Comparator 2 */
#define ADC_RIS_DCRIS3_Msk                    0x00000800UL           /*!< Raw interrupt status of Digital Comparator 3 */

/*--  IM: Interrupt mask register -----------------------------------------------------------------------------*/
typedef struct {
  uint32_t SEQIM0                 :1;                                /*!< Sequencer 0 interrupt mask */
  uint32_t SEQIM1                 :1;                                /*!< Sequencer 1 interrupt mask */
  uint32_t                        :6;                                /*!< RESERVED */
  uint32_t DCIM0                  :1;                                /*!< Interrupt mask of Digital Comparator 0 */
  uint32_t DCIM1                  :1;                                /*!< Interrupt mask of Digital Comparator 1 */
  uint32_t DCIM2                  :1;                                /*!< Interrupt mask of Digital Comparator 2 */
  uint32_t DCIM3                  :1;                                /*!< Interrupt mask of Digital Comparator 3 */
} _ADC_IM_bits;

/* Bit field positions: */
#define ADC_IM_SEQIM0_Pos                     0                      /*!< Sequencer 0 interrupt mask */
#define ADC_IM_SEQIM1_Pos                     1                      /*!< Sequencer 1 interrupt mask */
#define ADC_IM_DCIM0_Pos                      8                      /*!< Interrupt mask of Digital Comparator 0 */
#define ADC_IM_DCIM1_Pos                      9                      /*!< Interrupt mask of Digital Comparator 1 */
#define ADC_IM_DCIM2_Pos                      10                     /*!< Interrupt mask of Digital Comparator 2 */
#define ADC_IM_DCIM3_Pos                      11                     /*!< Interrupt mask of Digital Comparator 3 */

/* Bit field masks: */
#define ADC_IM_SEQIM0_Msk                     0x00000001UL           /*!< Sequencer 0 interrupt mask */
#define ADC_IM_SEQIM1_Msk                     0x00000002UL           /*!< Sequencer 1 interrupt mask */
#define ADC_IM_DCIM0_Msk                      0x00000100UL           /*!< Interrupt mask of Digital Comparator 0 */
#define ADC_IM_DCIM1_Msk                      0x00000200UL           /*!< Interrupt mask of Digital Comparator 1 */
#define ADC_IM_DCIM2_Msk                      0x00000400UL           /*!< Interrupt mask of Digital Comparator 2 */
#define ADC_IM_DCIM3_Msk                      0x00000800UL           /*!< Interrupt mask of Digital Comparator 3 */

/*--  MIS: Masked interrupt status and clear register ---------------------------------------------------------*/
typedef struct {
  uint32_t SEQMIS0                :1;                                /*!< Sequencer 0 masked interrupt status */
  uint32_t SEQMIS1                :1;                                /*!< Sequencer 1 masked interrupt status  */
  uint32_t                        :6;                                /*!< RESERVED */
  uint32_t DCMIS0                 :1;                                /*!< DC 0 masked interrupt status  */
  uint32_t DCMIS1                 :1;                                /*!< DC 1 masked interrupt status  */
  uint32_t DCMIS2                 :1;                                /*!< DC 2 masked interrupt status  */
  uint32_t DCMIS3                 :1;                                /*!< DC 3 masked interrupt status  */
} _ADC_MIS_bits;

/* Bit field positions: */
#define ADC_MIS_SEQMIS0_Pos                   0                      /*!< Sequencer 0 masked interrupt status */
#define ADC_MIS_SEQMIS1_Pos                   1                      /*!< Sequencer 1 masked interrupt status  */
#define ADC_MIS_DCMIS0_Pos                    8                      /*!< DC 0 masked interrupt status  */
#define ADC_MIS_DCMIS1_Pos                    9                      /*!< DC 1 masked interrupt status  */
#define ADC_MIS_DCMIS2_Pos                    10                     /*!< DC 2 masked interrupt status  */
#define ADC_MIS_DCMIS3_Pos                    11                     /*!< DC 3 masked interrupt status  */

/* Bit field masks: */
#define ADC_MIS_SEQMIS0_Msk                   0x00000001UL           /*!< Sequencer 0 masked interrupt status */
#define ADC_MIS_SEQMIS1_Msk                   0x00000002UL           /*!< Sequencer 1 masked interrupt status  */
#define ADC_MIS_DCMIS0_Msk                    0x00000100UL           /*!< DC 0 masked interrupt status  */
#define ADC_MIS_DCMIS1_Msk                    0x00000200UL           /*!< DC 1 masked interrupt status  */
#define ADC_MIS_DCMIS2_Msk                    0x00000400UL           /*!< DC 2 masked interrupt status  */
#define ADC_MIS_DCMIS3_Msk                    0x00000800UL           /*!< DC 3 masked interrupt status  */

/*--  IC: Interrupt clear register ----------------------------------------------------------------------------*/
typedef struct {
  uint32_t SEQIC0                 :1;                                /*!< Sequencer 0 interrupt status clear */
  uint32_t SEQIC1                 :1;                                /*!< Sequencer 1 interrupt status clear */
  uint32_t                        :6;                                /*!< RESERVED */
  uint32_t DCIC0                  :1;                                /*!< DC 0 interrupt status clear */
  uint32_t DCIC1                  :1;                                /*!< DC 1 interrupt status clear */
  uint32_t DCIC2                  :1;                                /*!< DC 2 interrupt status clear */
  uint32_t DCIC3                  :1;                                /*!< DC 3 interrupt status clear */
} _ADC_IC_bits;

/* Bit field positions: */
#define ADC_IC_SEQIC0_Pos                     0                      /*!< Sequencer 0 interrupt status clear */
#define ADC_IC_SEQIC1_Pos                     1                      /*!< Sequencer 1 interrupt status clear */
#define ADC_IC_DCIC0_Pos                      8                      /*!< DC 0 interrupt status clear */
#define ADC_IC_DCIC1_Pos                      9                      /*!< DC 1 interrupt status clear */
#define ADC_IC_DCIC2_Pos                      10                     /*!< DC 2 interrupt status clear */
#define ADC_IC_DCIC3_Pos                      11                     /*!< DC 3 interrupt status clear */

/* Bit field masks: */
#define ADC_IC_SEQIC0_Msk                     0x00000001UL           /*!< Sequencer 0 interrupt status clear */
#define ADC_IC_SEQIC1_Msk                     0x00000002UL           /*!< Sequencer 1 interrupt status clear */
#define ADC_IC_DCIC0_Msk                      0x00000100UL           /*!< DC 0 interrupt status clear */
#define ADC_IC_DCIC1_Msk                      0x00000200UL           /*!< DC 1 interrupt status clear */
#define ADC_IC_DCIC2_Msk                      0x00000400UL           /*!< DC 2 interrupt status clear */
#define ADC_IC_DCIC3_Msk                      0x00000800UL           /*!< DC 3 interrupt status clear */

/*-- SEQ: SRQSEL: Sequencer request ADC channels selection register -------------------------------------------*/
typedef struct {
  uint32_t RQ0                    :3;                                /*!< Select ADC channel for request 0 */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t RQ1                    :3;                                /*!< Select ADC channel for request 1 */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t RQ2                    :3;                                /*!< Select ADC channel for request 2 */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t RQ3                    :3;                                /*!< Select ADC channel for request 3 */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t RQ4                    :3;                                /*!< Select ADC channel for request 4 */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t RQ5                    :3;                                /*!< Select ADC channel for request 5 */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t RQ6                    :3;                                /*!< Select ADC channel for request 6 */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t RQ7                    :3;                                /*!< Select ADC channel for request 7 */
} _ADC_SEQ_SRQSEL_bits;

/* Bit field positions: */
#define ADC_SEQ_SRQSEL_RQ0_Pos                0                      /*!< Select ADC channel for request 0 */
#define ADC_SEQ_SRQSEL_RQ1_Pos                4                      /*!< Select ADC channel for request 1 */
#define ADC_SEQ_SRQSEL_RQ2_Pos                8                      /*!< Select ADC channel for request 2 */
#define ADC_SEQ_SRQSEL_RQ3_Pos                12                     /*!< Select ADC channel for request 3 */
#define ADC_SEQ_SRQSEL_RQ4_Pos                16                     /*!< Select ADC channel for request 4 */
#define ADC_SEQ_SRQSEL_RQ5_Pos                20                     /*!< Select ADC channel for request 5 */
#define ADC_SEQ_SRQSEL_RQ6_Pos                24                     /*!< Select ADC channel for request 6 */
#define ADC_SEQ_SRQSEL_RQ7_Pos                28                     /*!< Select ADC channel for request 7 */

/* Bit field masks: */
#define ADC_SEQ_SRQSEL_RQ0_Msk                0x00000007UL           /*!< Select ADC channel for request 0 */
#define ADC_SEQ_SRQSEL_RQ1_Msk                0x00000070UL           /*!< Select ADC channel for request 1 */
#define ADC_SEQ_SRQSEL_RQ2_Msk                0x00000700UL           /*!< Select ADC channel for request 2 */
#define ADC_SEQ_SRQSEL_RQ3_Msk                0x00007000UL           /*!< Select ADC channel for request 3 */
#define ADC_SEQ_SRQSEL_RQ4_Msk                0x00070000UL           /*!< Select ADC channel for request 4 */
#define ADC_SEQ_SRQSEL_RQ5_Msk                0x00700000UL           /*!< Select ADC channel for request 5 */
#define ADC_SEQ_SRQSEL_RQ6_Msk                0x07000000UL           /*!< Select ADC channel for request 6 */
#define ADC_SEQ_SRQSEL_RQ7_Msk                0x70000000UL           /*!< Select ADC channel for request 7 */

/*-- SEQ: SRQCTL: Sequencer request control register ----------------------------------------------------------*/
typedef struct {
  uint32_t RQMAX                  :3;                                /*!< Request queue max depth */
  uint32_t                        :5;                                /*!< RESERVED */
  uint32_t QAVGEN                 :1;                                /*!< Queue avearage (scanning) enable */
  uint32_t QAVGVAL                :3;                                /*!< Queue average value */
} _ADC_SEQ_SRQCTL_bits;

/* Bit field positions: */
#define ADC_SEQ_SRQCTL_RQMAX_Pos              0                      /*!< Request queue max depth */
#define ADC_SEQ_SRQCTL_QAVGEN_Pos             8                      /*!< Queue avearage (scanning) enable */
#define ADC_SEQ_SRQCTL_QAVGVAL_Pos            9                      /*!< Queue average value */

/* Bit field masks: */
#define ADC_SEQ_SRQCTL_RQMAX_Msk              0x00000007UL           /*!< Request queue max depth */
#define ADC_SEQ_SRQCTL_QAVGEN_Msk             0x00000100UL           /*!< Queue avearage (scanning) enable */
#define ADC_SEQ_SRQCTL_QAVGVAL_Msk            0x00000E00UL           /*!< Queue average value */

/* Bit field enums: */
typedef enum {
  ADC_SEQ_SRQCTL_QAVGVAL_Disable             = 0x0UL,                /*!< Average disabled */
  ADC_SEQ_SRQCTL_QAVGVAL_Average2            = 0x1UL,                /*!< Average with 2 measures */
  ADC_SEQ_SRQCTL_QAVGVAL_Average4            = 0x2UL,                /*!< Average with 4 measures */
  ADC_SEQ_SRQCTL_QAVGVAL_Average8            = 0x3UL,                /*!< Average with 8 measures */
  ADC_SEQ_SRQCTL_QAVGVAL_Average16           = 0x4UL,                /*!< Average with 16 measures */
  ADC_SEQ_SRQCTL_QAVGVAL_Average32           = 0x5UL,                /*!< Average with 32 measures */
  ADC_SEQ_SRQCTL_QAVGVAL_Average64           = 0x6UL,                /*!< Average with 64 measures */
} ADC_SEQ_SRQCTL_QAVGVAL_Enum;

/*-- SEQ: SRQSTAT: Sequencer request status register ----------------------------------------------------------*/
typedef struct {
  uint32_t RQPTR                  :3;                                /*!< Pointer to queue current request */
  uint32_t                        :5;                                /*!< RESERVED */
  uint32_t RQBUSY                 :1;                                /*!< Active request status */
} _ADC_SEQ_SRQSTAT_bits;

/* Bit field positions: */
#define ADC_SEQ_SRQSTAT_RQPTR_Pos             0                      /*!< Pointer to queue current request */
#define ADC_SEQ_SRQSTAT_RQBUSY_Pos            8                      /*!< Active request status */

/* Bit field masks: */
#define ADC_SEQ_SRQSTAT_RQPTR_Msk             0x00000007UL           /*!< Pointer to queue current request */
#define ADC_SEQ_SRQSTAT_RQBUSY_Msk            0x00000100UL           /*!< Active request status */

/*-- SEQ: SDMACTL: Sequencer DMA control register -------------------------------------------------------------*/
typedef struct {
  uint32_t DMAEN                  :1;                                /*!< Enable DMA use */
  uint32_t                        :7;                                /*!< RESERVED */
  uint32_t WMARK                  :3;                                /*!< FIFO load threshold for DMA request generation */
} _ADC_SEQ_SDMACTL_bits;

/* Bit field positions: */
#define ADC_SEQ_SDMACTL_DMAEN_Pos             0                      /*!< Enable DMA use */
#define ADC_SEQ_SDMACTL_WMARK_Pos             8                      /*!< FIFO load threshold for DMA request generation */

/* Bit field masks: */
#define ADC_SEQ_SDMACTL_DMAEN_Msk             0x00000001UL           /*!< Enable DMA use */
#define ADC_SEQ_SDMACTL_WMARK_Msk             0x00000700UL           /*!< FIFO load threshold for DMA request generation */

/* Bit field enums: */
typedef enum {
  ADC_SEQ_SDMACTL_WMARK_Level1               = 0x1UL,                /*!< 1 measure for dma request */
  ADC_SEQ_SDMACTL_WMARK_Level2               = 0x2UL,                /*!< 2 measures for dma request */
  ADC_SEQ_SDMACTL_WMARK_Level4               = 0x3UL,                /*!< 4 measures for dma request */
  ADC_SEQ_SDMACTL_WMARK_Level8               = 0x4UL,                /*!< 8 measures for dma request */
  ADC_SEQ_SDMACTL_WMARK_Level16              = 0x5UL,                /*!< 16 measures for dma request */
  ADC_SEQ_SDMACTL_WMARK_Level32              = 0x6UL,                /*!< 32 measures for dma request */
} ADC_SEQ_SDMACTL_WMARK_Enum;

/*-- SEQ: SCCTL: Sequencer ADC interrupt and restart counter control register ---------------------------------*/
typedef struct {
  uint32_t RCNT                   :8;                                /*!< Current number of ADC restarts by sequencer */
  uint32_t RAVGEN                 :1;                                /*!< Average of ADC restarts enable */
  uint32_t                        :7;                                /*!< RESERVED */
  uint32_t ICNT                   :8;                                /*!< Number of ADC restarts for interrupt generation */
} _ADC_SEQ_SCCTL_bits;

/* Bit field positions: */
#define ADC_SEQ_SCCTL_RCNT_Pos                0                      /*!< Current number of ADC restarts by sequencer */
#define ADC_SEQ_SCCTL_RAVGEN_Pos              8                      /*!< Average of ADC restarts enable */
#define ADC_SEQ_SCCTL_ICNT_Pos                16                     /*!< Number of ADC restarts for interrupt generation */

/* Bit field masks: */
#define ADC_SEQ_SCCTL_RCNT_Msk                0x000000FFUL           /*!< Current number of ADC restarts by sequencer */
#define ADC_SEQ_SCCTL_RAVGEN_Msk              0x00000100UL           /*!< Average of ADC restarts enable */
#define ADC_SEQ_SCCTL_ICNT_Msk                0x00FF0000UL           /*!< Number of ADC restarts for interrupt generation */

/*-- SEQ: SCVAL: Sequencer ADC interrupt and restart counter current value register --------------------------------*/
typedef struct {
  uint32_t RCNT                   :8;                                /*!< Current number of ADC restarts by sequencer */
  uint32_t                        :8;                                /*!< RESERVED */
  uint32_t ICNT                   :8;                                /*!< Current number of ADC restarts for interrupt generation */
  uint32_t ICLR                   :1;                                /*!< Clear interrupt counter */
} _ADC_SEQ_SCVAL_bits;

/* Bit field positions: */
#define ADC_SEQ_SCVAL_RCNT_Pos                0                      /*!< Current number of ADC restarts by sequencer */
#define ADC_SEQ_SCVAL_ICNT_Pos                16                     /*!< Current number of ADC restarts for interrupt generation */
#define ADC_SEQ_SCVAL_ICLR_Pos                24                     /*!< Clear interrupt counter */

/* Bit field masks: */
#define ADC_SEQ_SCVAL_RCNT_Msk                0x000000FFUL           /*!< Current number of ADC restarts by sequencer */
#define ADC_SEQ_SCVAL_ICNT_Msk                0x00FF0000UL           /*!< Current number of ADC restarts for interrupt generation */
#define ADC_SEQ_SCVAL_ICLR_Msk                0x01000000UL           /*!< Clear interrupt counter */

/*-- SEQ: SDC: Sequencer digital comparator selection register ------------------------------------------------*/
typedef struct {
  uint32_t DC0                    :1;                                /*!< Enable DC 0 */
  uint32_t DC1                    :1;                                /*!< Enable DC 1 */
  uint32_t DC2                    :1;                                /*!< Enable DC 2 */
  uint32_t DC3                    :1;                                /*!< Enable DC 3 */
} _ADC_SEQ_SDC_bits;

/* Bit field positions: */
#define ADC_SEQ_SDC_DC0_Pos                   0                      /*!< Enable DC 0 */
#define ADC_SEQ_SDC_DC1_Pos                   1                      /*!< Enable DC 1 */
#define ADC_SEQ_SDC_DC2_Pos                   2                      /*!< Enable DC 2 */
#define ADC_SEQ_SDC_DC3_Pos                   3                      /*!< Enable DC 3 */

/* Bit field masks: */
#define ADC_SEQ_SDC_DC0_Msk                   0x00000001UL           /*!< Enable DC 0 */
#define ADC_SEQ_SDC_DC1_Msk                   0x00000002UL           /*!< Enable DC 1 */
#define ADC_SEQ_SDC_DC2_Msk                   0x00000004UL           /*!< Enable DC 2 */
#define ADC_SEQ_SDC_DC3_Msk                   0x00000008UL           /*!< Enable DC 3 */

/*-- SEQ: SRTMR: Sequencer ADC restart timer register ---------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :24;                               /*!< Sequencer ADC restart timer value */
  uint32_t                        :7;                                /*!< RESERVED */
  uint32_t NOWAIT                 :1;                                /*!< Timer update with no waiting the end of current seq task */
} _ADC_SEQ_SRTMR_bits;

/* Bit field positions: */
#define ADC_SEQ_SRTMR_VAL_Pos                 0                      /*!< Sequencer ADC restart timer value */
#define ADC_SEQ_SRTMR_NOWAIT_Pos              31                     /*!< Timer update with no waiting the end of current seq task */

/* Bit field masks: */
#define ADC_SEQ_SRTMR_VAL_Msk                 0x00FFFFFFUL           /*!< Sequencer ADC restart timer value */
#define ADC_SEQ_SRTMR_NOWAIT_Msk              0x80000000UL           /*!< Timer update with no waiting the end of current seq task */

/*-- SEQ: SFLOAD: Sequencer FIFO load status register ---------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :6;                                /*!< Sequencer FIFO current load value */
} _ADC_SEQ_SFLOAD_bits;

/* Bit field positions: */
#define ADC_SEQ_SFLOAD_VAL_Pos                0                      /*!< Sequencer FIFO current load value */

/* Bit field masks: */
#define ADC_SEQ_SFLOAD_VAL_Msk                0x0000003FUL           /*!< Sequencer FIFO current load value */

/*-- SEQ: SFIFO: Sequencer FIFO register ----------------------------------------------------------------------*/
typedef struct {
  uint32_t DATA                   :12;                               /*!< AD conversion value */
} _ADC_SEQ_SFIFO_bits;

/* Bit field positions: */
#define ADC_SEQ_SFIFO_DATA_Pos                0                      /*!< AD conversion value */

/* Bit field masks: */
#define ADC_SEQ_SFIFO_DATA_Msk                0x00000FFFUL           /*!< AD conversion value */

/*-- DC: DCTL: Digital comparator control register ------------------------------------------------------------*/
typedef struct {
  uint32_t CIM                    :2;                                /*!< DC interrupt generation mode */
  uint32_t CIC                    :2;                                /*!< DC interrupt generation compare conditions */
  uint32_t CIE                    :1;                                /*!< Enable DC interrupt generation */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t CTM                    :2;                                /*!< DC output trigger mode */
  uint32_t CTC                    :2;                                /*!< DC output trigger compare conditions */
  uint32_t CTE                    :1;                                /*!< Enable DC output trigger */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t CHNL                   :3;                                /*!< ADC channel selection */
  uint32_t                        :5;                                /*!< RESERVED */
  uint32_t SRC                    :1;                                /*!< Select data source for comparation: ADC module (0) or sequencer(1) */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t HWTCLR                 :1;                                /*!< Hardware output trigger clear */
} _ADC_DC_DCTL_bits;

/* Bit field positions: */
#define ADC_DC_DCTL_CIM_Pos                   0                      /*!< DC interrupt generation mode */
#define ADC_DC_DCTL_CIC_Pos                   2                      /*!< DC interrupt generation compare conditions */
#define ADC_DC_DCTL_CIE_Pos                   4                      /*!< Enable DC interrupt generation */
#define ADC_DC_DCTL_CTM_Pos                   8                      /*!< DC output trigger mode */
#define ADC_DC_DCTL_CTC_Pos                   10                     /*!< DC output trigger compare conditions */
#define ADC_DC_DCTL_CTE_Pos                   12                     /*!< Enable DC output trigger */
#define ADC_DC_DCTL_CHNL_Pos                  16                     /*!< ADC channel selection */
#define ADC_DC_DCTL_SRC_Pos                   24                     /*!< Select data source for comparation: ADC module (0) or sequencer(1) */
#define ADC_DC_DCTL_HWTCLR_Pos                28                     /*!< Hardware output trigger clear */

/* Bit field masks: */
#define ADC_DC_DCTL_CIM_Msk                   0x00000003UL           /*!< DC interrupt generation mode */
#define ADC_DC_DCTL_CIC_Msk                   0x0000000CUL           /*!< DC interrupt generation compare conditions */
#define ADC_DC_DCTL_CIE_Msk                   0x00000010UL           /*!< Enable DC interrupt generation */
#define ADC_DC_DCTL_CTM_Msk                   0x00000300UL           /*!< DC output trigger mode */
#define ADC_DC_DCTL_CTC_Msk                   0x00000C00UL           /*!< DC output trigger compare conditions */
#define ADC_DC_DCTL_CTE_Msk                   0x00001000UL           /*!< Enable DC output trigger */
#define ADC_DC_DCTL_CHNL_Msk                  0x00070000UL           /*!< ADC channel selection */
#define ADC_DC_DCTL_SRC_Msk                   0x01000000UL           /*!< Select data source for comparation: ADC module (0) or sequencer(1) */
#define ADC_DC_DCTL_HWTCLR_Msk                0x10000000UL           /*!< Hardware output trigger clear */

/* Bit field enums: */
typedef enum {
  ADC_DC_DCTL_CIM_Multiple                   = 0x0UL,                /*!< multiple trigger mode */
  ADC_DC_DCTL_CIM_Single                     = 0x1UL,                /*!< single trigger mode */
  ADC_DC_DCTL_CIM_MultipleHyst               = 0x2UL,                /*!< multiple trigger mode with hysteresis */
  ADC_DC_DCTL_CIM_SingleHyst                 = 0x3UL,                /*!< single trigger mode with hysteresis */
} ADC_DC_DCTL_CIM_Enum;

typedef enum {
  ADC_DC_DCTL_CIC_Low                        = 0x0UL,                /*!< result lower or equal COMP0 */
  ADC_DC_DCTL_CIC_Window                     = 0x1UL,                /*!< result between COMP0 and COMP1 or equal any of them */
  ADC_DC_DCTL_CIC_High                       = 0x2UL,                /*!< result higher or equal COMP1 */
} ADC_DC_DCTL_CIC_Enum;

typedef enum {
  ADC_DC_DCTL_CTM_Multiple                   = 0x0UL,                /*!< multiple trigger mode */
  ADC_DC_DCTL_CTM_Single                     = 0x1UL,                /*!< single trigger mode */
  ADC_DC_DCTL_CTM_MultipleHyst               = 0x2UL,                /*!< multiple trigger mode with hysteresis */
  ADC_DC_DCTL_CTM_SingleHyst                 = 0x3UL,                /*!< single trigger mode with hysteresis */
} ADC_DC_DCTL_CTM_Enum;

typedef enum {
  ADC_DC_DCTL_CTC_Low                        = 0x0UL,                /*!< result lower or equal COMP0 */
  ADC_DC_DCTL_CTC_Window                     = 0x1UL,                /*!< result between COMP0 and COMP1 or equal any of them */
  ADC_DC_DCTL_CTC_High                       = 0x2UL,                /*!< result higher or equal COMP1 */
} ADC_DC_DCTL_CTC_Enum;

/*-- DC: DCMP: Digital comparator range register --------------------------------------------------------------*/
typedef struct {
  uint32_t CMPL                   :12;                               /*!< Low threshold compare value */
  uint32_t                        :4;                                /*!< RESERVED */
  uint32_t CMPH                   :12;                               /*!< High threshold compare value */
} _ADC_DC_DCMP_bits;

/* Bit field positions: */
#define ADC_DC_DCMP_CMPL_Pos                  0                      /*!< Low threshold compare value */
#define ADC_DC_DCMP_CMPH_Pos                  16                     /*!< High threshold compare value */

/* Bit field masks: */
#define ADC_DC_DCMP_CMPL_Msk                  0x00000FFFUL           /*!< Low threshold compare value */
#define ADC_DC_DCMP_CMPH_Msk                  0x0FFF0000UL           /*!< High threshold compare value */

/*-- DC: DDATA: Digital comparator last compared data register ------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :12;                               /*!< Value of last compared AD conversion result */
} _ADC_DC_DDATA_bits;

/* Bit field positions: */
#define ADC_DC_DDATA_VAL_Pos                  0                      /*!< Value of last compared AD conversion result */

/* Bit field masks: */
#define ADC_DC_DDATA_VAL_Msk                  0x00000FFFUL           /*!< Value of last compared AD conversion result */

/*--  ACTL: ADC module control register -----------------------------------------------------------------------*/
typedef struct {
  uint32_t ADCEN                  :1;                                /*!< Enable ADC module */
  uint32_t ADCRDY                 :1;                                /*!< ADC ready for conversions */
  uint32_t ADCENLDO               :1;                                /*!< Enable LDO */
  uint32_t ADCSTART               :1;                                /*!<  */
  uint32_t SELRES                 :2;                                /*!< ADC resolution select */
  uint32_t                        :2;                                /*!< RESERVED */
  uint32_t CALEN                  :1;                                /*!<  */
  uint32_t CALLOAD                :1;                                /*!<  */
  uint32_t CALSTART               :1;                                /*!<  */
  uint32_t CALBUSY                :1;                                /*!< Enable ADC internal calibration */
  uint32_t RANGELDO               :1;                                /*!< Start ADC internal calibration */
  uint32_t DISLVL                 :1;                                /*!< ADC internal calibration is in progress */
  uint32_t                        :2;                                /*!< RESERVED */
  uint32_t CALIN                  :7;                                /*!< ADC calibration input value */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t CALOUT                 :7;                                /*!< ADC calibration output value */
} _ADC_ACTL_bits;

/* Bit field positions: */
#define ADC_ACTL_ADCEN_Pos                    0                      /*!< Enable ADC module */
#define ADC_ACTL_ADCRDY_Pos                   1                      /*!< ADC ready for conversions */
#define ADC_ACTL_ADCENLDO_Pos                 2                      /*!< Enable LDO */
#define ADC_ACTL_ADCSTART_Pos                 3                      /*!<  */
#define ADC_ACTL_SELRES_Pos                   4                      /*!< ADC resolution select */
#define ADC_ACTL_CALEN_Pos                    8                      /*!<  */
#define ADC_ACTL_CALLOAD_Pos                  9                      /*!<  */
#define ADC_ACTL_CALSTART_Pos                 10                     /*!<  */
#define ADC_ACTL_CALBUSY_Pos                  11                     /*!< Enable ADC internal calibration */
#define ADC_ACTL_RANGELDO_Pos                 12                     /*!< Start ADC internal calibration */
#define ADC_ACTL_DISLVL_Pos                   13                     /*!< ADC internal calibration is in progress */
#define ADC_ACTL_CALIN_Pos                    16                     /*!< ADC calibration input value */
#define ADC_ACTL_CALOUT_Pos                   24                     /*!< ADC calibration output value */

/* Bit field masks: */
#define ADC_ACTL_ADCEN_Msk                    0x00000001UL           /*!< Enable ADC module */
#define ADC_ACTL_ADCRDY_Msk                   0x00000002UL           /*!< ADC ready for conversions */
#define ADC_ACTL_ADCENLDO_Msk                 0x00000004UL           /*!< Enable LDO */
#define ADC_ACTL_ADCSTART_Msk                 0x00000008UL           /*!<  */
#define ADC_ACTL_SELRES_Msk                   0x00000030UL           /*!< ADC resolution select */
#define ADC_ACTL_CALEN_Msk                    0x00000100UL           /*!<  */
#define ADC_ACTL_CALLOAD_Msk                  0x00000200UL           /*!<  */
#define ADC_ACTL_CALSTART_Msk                 0x00000400UL           /*!<  */
#define ADC_ACTL_CALBUSY_Msk                  0x00000800UL           /*!< Enable ADC internal calibration */
#define ADC_ACTL_RANGELDO_Msk                 0x00001000UL           /*!< Start ADC internal calibration */
#define ADC_ACTL_DISLVL_Msk                   0x00002000UL           /*!< ADC internal calibration is in progress */
#define ADC_ACTL_CALIN_Msk                    0x007F0000UL           /*!< ADC calibration input value */
#define ADC_ACTL_CALOUT_Msk                   0x7F000000UL           /*!< ADC calibration output value */

/* Bit field enums: */
typedef enum {
  ADC_ACTL_SELRES_6bit                       = 0x0UL,                /*!< 6 bit mode */
  ADC_ACTL_SELRES_8bit                       = 0x1UL,                /*!< 8 bit mode */
  ADC_ACTL_SELRES_10bit                      = 0x2UL,                /*!< 10 bit mode */
  ADC_ACTL_SELRES_12bit                      = 0x3UL,                /*!< 12 bit mode */
} ADC_ACTL_SELRES_Enum;

/*--  TACC0: ADC test access register -------------------------------------------------------------------------*/
typedef struct {
  uint32_t SOC                    :1;                                /*!<  */
  uint32_t REARM                  :1;                                /*!<  */
  uint32_t                        :2;                                /*!< RESERVED */
  uint32_t SEL                    :4;                                /*!<  */
  uint32_t SELRES                 :2;                                /*!<  */
  uint32_t RSTADC                 :1;                                /*!<  */
  uint32_t BPCAL                  :1;                                /*!<  */
  uint32_t RSTCAL                 :1;                                /*!<  */
  uint32_t LOADCAL                :1;                                /*!<  */
  uint32_t STARTCAL               :1;                                /*!<  */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t KEY                    :16;                               /*!<             0xFAAC */
} _ADC_TACC0_bits;

/* Bit field positions: */
#define ADC_TACC0_SOC_Pos                     0                      /*!<  */
#define ADC_TACC0_REARM_Pos                   1                      /*!<  */
#define ADC_TACC0_SEL_Pos                     4                      /*!<  */
#define ADC_TACC0_SELRES_Pos                  8                      /*!<  */
#define ADC_TACC0_RSTADC_Pos                  10                     /*!<  */
#define ADC_TACC0_BPCAL_Pos                   11                     /*!<  */
#define ADC_TACC0_RSTCAL_Pos                  12                     /*!<  */
#define ADC_TACC0_LOADCAL_Pos                 13                     /*!<  */
#define ADC_TACC0_STARTCAL_Pos                14                     /*!<  */
#define ADC_TACC0_KEY_Pos                     16                     /*!< 0xFAAC */

/* Bit field masks: */
#define ADC_TACC0_SOC_Msk                     0x00000001UL           /*!<  */
#define ADC_TACC0_REARM_Msk                   0x00000002UL           /*!<  */
#define ADC_TACC0_SEL_Msk                     0x000000F0UL           /*!<  */
#define ADC_TACC0_SELRES_Msk                  0x00000300UL           /*!<  */
#define ADC_TACC0_RSTADC_Msk                  0x00000400UL           /*!<  */
#define ADC_TACC0_BPCAL_Msk                   0x00000800UL           /*!<  */
#define ADC_TACC0_RSTCAL_Msk                  0x00001000UL           /*!<  */
#define ADC_TACC0_LOADCAL_Msk                 0x00002000UL           /*!<  */
#define ADC_TACC0_STARTCAL_Msk                0x00004000UL           /*!<  */
#define ADC_TACC0_KEY_Msk                     0xFFFF0000UL           /*!< 0xFAAC */

/*--  TACC1: ADC test access register -------------------------------------------------------------------------*/
typedef struct {
  uint32_t DATA                   :12;                               /*!<  */
  uint32_t EOC                    :1;                                /*!<  */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t EOCF                   :1;                                /*!<  */
  uint32_t EOCR                   :1;                                /*!<  */
} _ADC_TACC1_bits;

/* Bit field positions: */
#define ADC_TACC1_DATA_Pos                    0                      /*!<  */
#define ADC_TACC1_EOC_Pos                     12                     /*!<  */
#define ADC_TACC1_EOCF_Pos                    16                     /*!<  */
#define ADC_TACC1_EOCR_Pos                    17                     /*!<  */

/* Bit field masks: */
#define ADC_TACC1_DATA_Msk                    0x00000FFFUL           /*!<  */
#define ADC_TACC1_EOC_Msk                     0x00001000UL           /*!<  */
#define ADC_TACC1_EOCF_Msk                    0x00010000UL           /*!<  */
#define ADC_TACC1_EOCR_Msk                    0x00020000UL           /*!<  */

/*--  CHCTL: ADC channel control register ---------------------------------------------------------------------*/
typedef struct {
  uint32_t OFFTRIM                :9;                                /*!< ADC channel offset trimm value */
  uint32_t                        :7;                                /*!< RESERVED */
  uint32_t GAINTRIM               :9;                                /*!< ADC channel gain trimm value */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t PRIORITY               :1;                                /*!< ADC channel priority level */
} _ADC_CHCTL_bits;

/* Bit field positions: */
#define ADC_CHCTL_OFFTRIM_Pos                 0                      /*!< ADC channel offset trimm value */
#define ADC_CHCTL_GAINTRIM_Pos                16                     /*!< ADC channel gain trimm value */
#define ADC_CHCTL_PRIORITY_Pos                28                     /*!< ADC channel priority level */

/* Bit field masks: */
#define ADC_CHCTL_OFFTRIM_Msk                 0x000001FFUL           /*!< ADC channel offset trimm value */
#define ADC_CHCTL_GAINTRIM_Msk                0x01FF0000UL           /*!< ADC channel gain trimm value */
#define ADC_CHCTL_PRIORITY_Msk                0x10000000UL           /*!< ADC channel priority level */

/*--  CHDELAY: ADC channel delay register ---------------------------------------------------------------------*/
typedef struct {
  uint32_t DELAY                  :16;                               /*!< ADC channel delay value */
} _ADC_CHDELAY_bits;

/* Bit field positions: */
#define ADC_CHDELAY_DELAY_Pos                 0                      /*!< ADC channel delay value */

/* Bit field masks: */
#define ADC_CHDELAY_DELAY_Msk                 0x0000FFFFUL           /*!< ADC channel delay value */

//Cluster SEQ:
typedef struct {
  union {
  /*!< Sequencer request ADC channels selection register */
    __IO uint32_t SRQSEL;                                            /*!< SRQSEL : type used for word access */
    __IO _ADC_SEQ_SRQSEL_bits SRQSEL_bit;                            /*!< SRQSEL_bit: structure used for bit access */
  };
    __IO uint32_t Reserved0[5];
  union {
  /*!< Sequencer request control register */
    __IO uint32_t SRQCTL;                                            /*!< SRQCTL : type used for word access */
    __IO _ADC_SEQ_SRQCTL_bits SRQCTL_bit;                            /*!< SRQCTL_bit: structure used for bit access */
  };
  union {
  /*!< Sequencer request status register */
    __IO uint32_t SRQSTAT;                                           /*!< SRQSTAT : type used for word access */
    __IO _ADC_SEQ_SRQSTAT_bits SRQSTAT_bit;                          /*!< SRQSTAT_bit: structure used for bit access */
  };
  union {
  /*!< Sequencer DMA control register */
    __IO uint32_t SDMACTL;                                           /*!< SDMACTL : type used for word access */
    __IO _ADC_SEQ_SDMACTL_bits SDMACTL_bit;                          /*!< SDMACTL_bit: structure used for bit access */
  };
  union {
  /*!< Sequencer ADC interrupt and restart counter control register */
    __IO uint32_t SCCTL;                                             /*!< SCCTL : type used for word access */
    __IO _ADC_SEQ_SCCTL_bits SCCTL_bit;                              /*!< SCCTL_bit: structure used for bit access */
  };
  union {
  /*!< Sequencer ADC interrupt and restart counter current value register */
    __O uint32_t SCVAL;                                              /*!< SCVAL : type used for word access */
    __O _ADC_SEQ_SCVAL_bits SCVAL_bit;                               /*!< SCVAL_bit: structure used for bit access */
  };
  union {
  /*!< Sequencer digital comparator selection register */
    __IO uint32_t SDC;                                               /*!< SDC : type used for word access */
    __IO _ADC_SEQ_SDC_bits SDC_bit;                                  /*!< SDC_bit: structure used for bit access */
  };
  union {
  /*!< Sequencer ADC restart timer register */
    __IO uint32_t SRTMR;                                             /*!< SRTMR : type used for word access */
    __IO _ADC_SEQ_SRTMR_bits SRTMR_bit;                              /*!< SRTMR_bit: structure used for bit access */
  };
  union {
  /*!< Sequencer FIFO load status register */
    __I uint32_t SFLOAD;                                             /*!< SFLOAD : type used for word access */
    __I _ADC_SEQ_SFLOAD_bits SFLOAD_bit;                             /*!< SFLOAD_bit: structure used for bit access */
  };
  union {
  /*!< Sequencer FIFO register */
    __I uint32_t SFIFO;                                              /*!< SFIFO : type used for word access */
    __I _ADC_SEQ_SFIFO_bits SFIFO_bit;                               /*!< SFIFO_bit: structure used for bit access */
  };
} _ADC_SEQ_TypeDef;
//Cluster DC:
typedef struct {
  union {
  /*!< Digital comparator control register */
    __IO uint32_t DCTL;                                              /*!< DCTL : type used for word access */
    __IO _ADC_DC_DCTL_bits DCTL_bit;                                 /*!< DCTL_bit: structure used for bit access */
  };
  union {
  /*!< Digital comparator range register */
    __IO uint32_t DCMP;                                              /*!< DCMP : type used for word access */
    __IO _ADC_DC_DCMP_bits DCMP_bit;                                 /*!< DCMP_bit: structure used for bit access */
  };
  union {
  /*!< Digital comparator last compared data register */
    __I uint32_t DDATA;                                              /*!< DDATA : type used for word access */
    __I _ADC_DC_DDATA_bits DDATA_bit;                                /*!< DDATA_bit: structure used for bit access */
  };
} _ADC_DC_TypeDef;
//Cluster CHCTL:
typedef struct {
  union {
  /*!< ADC channel control register */
    __IO uint32_t CHCTL;                                             /*!< CHCTL : type used for word access */
    __IO _ADC_CHCTL_bits CHCTL_bit;                                  /*!< CHCTL_bit: structure used for bit access */
  };
} _ADC_CHCTL_TypeDef;
//Cluster CHDELAY:
typedef struct {
  union {
  /*!< ADC channel delay register */
    __IO uint32_t CHDELAY;                                           /*!< CHDELAY : type used for word access */
    __IO _ADC_CHDELAY_bits CHDELAY_bit;                              /*!< CHDELAY_bit: structure used for bit access */
  };
} _ADC_CHDELAY_TypeDef;
typedef struct {
  union {                                                               /*!< Enable sequencer register */
    __IO uint32_t SEQEN;                                             /*!< SEQEN    : type used for word access */
    __IO _ADC_SEQEN_bits  SEQEN_bit;                                 /*!< SEQEN_bit: structure used for bit access */
  };
  union {                                                               /*!< Sequencer sync register */
    __IO uint32_t SEQSYNC;                                           /*!< SEQSYNC    : type used for word access */
    __IO _ADC_SEQSYNC_bits  SEQSYNC_bit;                             /*!< SEQSYNC_bit: structure used for bit access */
  };
  union {                                                               /*!< FIFO overflow status register */
    __IO uint32_t FSTAT;                                             /*!< FSTAT    : type used for word access */
    __IO _ADC_FSTAT_bits  FSTAT_bit;                                 /*!< FSTAT_bit: structure used for bit access */
  };
  union {                                                               /*!< Busy status register */
    __I uint32_t BSTAT;                                              /*!< BSTAT    : type used for word access */
    __I _ADC_BSTAT_bits  BSTAT_bit;                                  /*!< BSTAT_bit: structure used for bit access */
  };
  union {                                                               /*!< Digital comparator output trigger status register */
    __O uint32_t DCTRIG;                                             /*!< DCTRIG    : type used for word access */
    __O _ADC_DCTRIG_bits  DCTRIG_bit;                                /*!< DCTRIG_bit: structure used for bit access */
  };
  union {                                                               /*!< Digital comparator compare event status register */
    __O uint32_t DCEV;                                               /*!< DCEV    : type used for word access */
    __O _ADC_DCEV_bits  DCEV_bit;                                    /*!< DCEV_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt counter clear control */
    __IO uint32_t CICNT;                                             /*!< CICNT    : type used for word access */
    __IO _ADC_CICNT_bits  CICNT_bit;                                 /*!< CICNT_bit: structure used for bit access */
  };
  union {                                                               /*!< Sequencer start event selection register */
    __IO uint32_t EMUX;                                              /*!< EMUX    : type used for word access */
    __IO _ADC_EMUX_bits  EMUX_bit;                                   /*!< EMUX_bit: structure used for bit access */
  };
  union {                                                               /*!< Raw interrupt status register */
    __I uint32_t RIS;                                                /*!< RIS    : type used for word access */
    __I _ADC_RIS_bits  RIS_bit;                                      /*!< RIS_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt mask register */
    __IO uint32_t IM;                                                /*!< IM    : type used for word access */
    __IO _ADC_IM_bits  IM_bit;                                       /*!< IM_bit: structure used for bit access */
  };
  union {                                                               /*!< Masked interrupt status and clear register */
    __I uint32_t MIS;                                                /*!< MIS    : type used for word access */
    __I _ADC_MIS_bits  MIS_bit;                                      /*!< MIS_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt clear register */
    __O uint32_t IC;                                                 /*!< IC    : type used for word access */
    __O _ADC_IC_bits  IC_bit;                                        /*!< IC_bit: structure used for bit access */
  };
    __IO uint32_t Reserved0[4];
  _ADC_SEQ_TypeDef SEQ[2];
    __IO uint32_t Reserved1[210];
  _ADC_DC_TypeDef DC[4];
    __IO uint32_t Reserved2[68];
  union {                                                               /*!< ADC module control register */
    __IO uint32_t ACTL;                                              /*!< ACTL    : type used for word access */
    __IO _ADC_ACTL_bits  ACTL_bit;                                   /*!< ACTL_bit: structure used for bit access */
  };
  union {                                                               /*!< ADC test access register */
    __IO uint32_t TACC0;                                             /*!< TACC0    : type used for word access */
    __IO _ADC_TACC0_bits  TACC0_bit;                                 /*!< TACC0_bit: structure used for bit access */
  };
  union {                                                               /*!< ADC test access register */
    __IO uint32_t TACC1;                                             /*!< TACC1    : type used for word access */
    __IO _ADC_TACC1_bits  TACC1_bit;                                 /*!< TACC1_bit: structure used for bit access */
  };
    __IO uint32_t Reserved3[13];
  _ADC_CHCTL_TypeDef CHCTL[5];
    __IO uint32_t Reserved4[59];
  _ADC_CHDELAY_TypeDef CHDELAY[5];
} ADC_TypeDef;


/******************************************************************************/
/*                         CAN registers                                      */
/******************************************************************************/

/*--  CLC: Frequency control register -------------------------------------------------------------------------*/
typedef struct {
  uint32_t DISR                   :1;                                /*!< OFF module CAN */
  uint32_t DISS                   :1;                                /*!< State CAN */
} _CAN_CLC_bits;

/* Bit field positions: */
#define CAN_CLC_DISR_Pos                      0                      /*!< OFF module CAN */
#define CAN_CLC_DISS_Pos                      1                      /*!< State CAN */

/* Bit field masks: */
#define CAN_CLC_DISR_Msk                      0x00000001UL           /*!< OFF module CAN */
#define CAN_CLC_DISS_Msk                      0x00000002UL           /*!< State CAN */

/*--  ID: Identity register -----------------------------------------------------------------------------------*/
typedef struct {
  uint32_t MODREV                 :8;                                /*!< Number of modifications of the CAN */
  uint32_t MODTYPE                :8;                                /*!< Digit capacity CAN */
  uint32_t MODNUM                 :16;                               /*!< Identification number CAN */
} _CAN_ID_bits;

/* Bit field positions: */
#define CAN_ID_MODREV_Pos                     0                      /*!< Number of modifications of the CAN */
#define CAN_ID_MODTYPE_Pos                    8                      /*!< Digit capacity CAN */
#define CAN_ID_MODNUM_Pos                     16                     /*!< Identification number CAN */

/* Bit field masks: */
#define CAN_ID_MODREV_Msk                     0x000000FFUL           /*!< Number of modifications of the CAN */
#define CAN_ID_MODTYPE_Msk                    0x0000FF00UL           /*!< Digit capacity CAN */
#define CAN_ID_MODNUM_Msk                     0xFFFF0000UL           /*!< Identification number CAN */

/*--  FDR: Register divider -----------------------------------------------------------------------------------*/
typedef struct {
  uint32_t STEP                   :10;                               /*!< Step divider */
  uint32_t                        :4;                                /*!< RESERVED */
  uint32_t DM                     :2;                                /*!< Mode setting of the frequency divider */
  uint32_t RESULT                 :10;                               /*!< Count frequency divider */
  uint32_t                        :4;                                /*!< RESERVED */
  uint32_t ENHW                   :1;                                /*!< Control bit synchronization */
  uint32_t DISCLK                 :1;                                /*!< Disable bit internal clock */
} _CAN_FDR_bits;

/* Bit field positions: */
#define CAN_FDR_STEP_Pos                      0                      /*!< Step divider */
#define CAN_FDR_DM_Pos                        14                     /*!< Mode setting of the frequency divider */
#define CAN_FDR_RESULT_Pos                    16                     /*!< Count frequency divider */
#define CAN_FDR_ENHW_Pos                      30                     /*!< Control bit synchronization */
#define CAN_FDR_DISCLK_Pos                    31                     /*!< Disable bit internal clock */

/* Bit field masks: */
#define CAN_FDR_STEP_Msk                      0x000003FFUL           /*!< Step divider */
#define CAN_FDR_DM_Msk                        0x0000C000UL           /*!< Mode setting of the frequency divider */
#define CAN_FDR_RESULT_Msk                    0x03FF0000UL           /*!< Count frequency divider */
#define CAN_FDR_ENHW_Msk                      0x40000000UL           /*!< Control bit synchronization */
#define CAN_FDR_DISCLK_Msk                    0x80000000UL           /*!< Disable bit internal clock */

/* Bit field enums: */
typedef enum {
  CAN_FDR_DM_Disable                         = 0x0UL,                /*!< counter disabled */
  CAN_FDR_DM_NormalMode                      = 0x1UL,                /*!< normal operation mode */
  CAN_FDR_DM_DividerMode                     = 0x2UL,                /*!< divider operation mode */
} CAN_FDR_DM_Enum;

/*--  LIST: Register list0 ------------------------------------------------------------------------------------*/
typedef struct {
  uint32_t BEGIN                  :8;                                /*!< Number of the first message object */
  uint32_t END                    :8;                                /*!< Number of the last message object */
  uint32_t SIZE                   :8;                                /*!< List size */
  uint32_t EMPTY                  :1;                                /*!< Indicate empty list */
} _CAN_LIST_bits;

/* Bit field positions: */
#define CAN_LIST_BEGIN_Pos                    0                      /*!< Number of the first message object */
#define CAN_LIST_END_Pos                      8                      /*!< Number of the last message object */
#define CAN_LIST_SIZE_Pos                     16                     /*!< List size */
#define CAN_LIST_EMPTY_Pos                    24                     /*!< Indicate empty list */

/* Bit field masks: */
#define CAN_LIST_BEGIN_Msk                    0x000000FFUL           /*!< Number of the first message object */
#define CAN_LIST_END_Msk                      0x0000FF00UL           /*!< Number of the last message object */
#define CAN_LIST_SIZE_Msk                     0x00FF0000UL           /*!< List size */
#define CAN_LIST_EMPTY_Msk                    0x01000000UL           /*!< Indicate empty list */

/*--  MSPND: Register waiting interrupts0 ---------------------------------------------------------------------*/
typedef struct {
  uint32_t PND                    :32;                               /*!< Field waiting interrupts */
} _CAN_MSPND_bits;

/* Bit field positions: */
#define CAN_MSPND_PND_Pos                     0                      /*!< Field waiting interrupts */

/* Bit field masks: */
#define CAN_MSPND_PND_Msk                     0xFFFFFFFFUL           /*!< Field waiting interrupts */

/*--  MSID: Register messages index0 --------------------------------------------------------------------------*/
typedef struct {
  uint32_t INDEX                  :6;                                /*!<  */
} _CAN_MSID_bits;

/* Bit field positions: */
#define CAN_MSID_INDEX_Pos                    0                      /*!<  */

/* Bit field masks: */
#define CAN_MSID_INDEX_Msk                    0x0000003FUL           /*!<  */

/*--  MSIMASK: Mask register message index --------------------------------------------------------------------*/
typedef struct {
  uint32_t IM                     :32;                               /*!< Mask for waiting bit messages */
} _CAN_MSIMASK_bits;

/* Bit field positions: */
#define CAN_MSIMASK_IM_Pos                    0                      /*!< Mask for waiting bit messages */

/* Bit field masks: */
#define CAN_MSIMASK_IM_Msk                    0xFFFFFFFFUL           /*!< Mask for waiting bit messages */

/*--  PANCTR: Register command panel --------------------------------------------------------------------------*/
typedef struct {
  uint32_t PANCMD                 :8;                                /*!< Command panel */
  uint32_t BUSY                   :1;                                /*!< Busy flag panels arguments (waiting to be written at the end of the command) */
  uint32_t RBUSY                  :1;                                /*!< Busy flag panels arguments (running the command list, the result of which will be recorded in PANAR1 and PANAR2) */
  uint32_t                        :6;                                /*!< RESERVED */
  uint32_t PANAR1                 :8;                                /*!< Panel argument 8 */
  uint32_t PANAR2                 :8;                                /*!< Panel argument 9 */
} _CAN_PANCTR_bits;

/* Bit field positions: */
#define CAN_PANCTR_PANCMD_Pos                 0                      /*!< Command panel */
#define CAN_PANCTR_BUSY_Pos                   8                      /*!< Busy flag panels arguments (waiting to be written at the end of the command) */
#define CAN_PANCTR_RBUSY_Pos                  9                      /*!< Busy flag panels arguments (running the command list, the result of which will be recorded in PANAR1 and PANAR2) */
#define CAN_PANCTR_PANAR1_Pos                 16                     /*!< Panel argument 8 */
#define CAN_PANCTR_PANAR2_Pos                 24                     /*!< Panel argument 9 */

/* Bit field masks: */
#define CAN_PANCTR_PANCMD_Msk                 0x000000FFUL           /*!< Command panel */
#define CAN_PANCTR_BUSY_Msk                   0x00000100UL           /*!< Busy flag panels arguments (waiting to be written at the end of the command) */
#define CAN_PANCTR_RBUSY_Msk                  0x00000200UL           /*!< Busy flag panels arguments (running the command list, the result of which will be recorded in PANAR1 and PANAR2) */
#define CAN_PANCTR_PANAR1_Msk                 0x00FF0000UL           /*!< Panel argument 8 */
#define CAN_PANCTR_PANAR2_Msk                 0xFF000000UL           /*!< Panel argument 9 */

/*--  MCR:  ---------------------------------------------------------------------------------------------------*/
typedef struct {
  uint32_t                        :12;                               /*!< RESERVED */
  uint32_t MPSEL                  :4;                                /*!< Field task position after waiting message bit transmit / receive messages */
} _CAN_MCR_bits;

/* Bit field positions: */
#define CAN_MCR_MPSEL_Pos                     12                     /*!< Field task position after waiting message bit transmit / receive messages */

/* Bit field masks: */
#define CAN_MCR_MPSEL_Msk                     0x0000F000UL           /*!< Field task position after waiting message bit transmit / receive messages */

/*--  MITR: Interrupt register --------------------------------------------------------------------------------*/
typedef struct {
  uint32_t IT                     :16;                               /*!< Field  generate interrupt */
} _CAN_MITR_bits;

/* Bit field positions: */
#define CAN_MITR_IT_Pos                       0                      /*!< Field  generate interrupt */

/* Bit field masks: */
#define CAN_MITR_IT_Msk                       0x0000FFFFUL           /*!< Field  generate interrupt */

/*-- Node: NCR: Register control node0 ------------------------------------------------------------------------*/
typedef struct {
  uint32_t INIT                   :1;                                /*!< Node initialization */
  uint32_t TRIE                   :1;                                /*!< Interrupt enable bit of the assembly at the end of the transmission / reception */
  uint32_t LECIE                  :1;                                /*!< Interrupt enable bit of the assembly when it detects the last error code */
  uint32_t ALIE                   :1;                                /*!< Enable interrupt ALERT from node */
  uint32_t CANDIS                 :1;                                /*!< Off node */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t CCE                    :1;                                /*!< Permission node configuration changes */
  uint32_t CALM                   :1;                                /*!< Activate the node analysis */
} _CAN_Node_NCR_bits;

/* Bit field positions: */
#define CAN_Node_NCR_INIT_Pos                 0                      /*!< Node initialization */
#define CAN_Node_NCR_TRIE_Pos                 1                      /*!< Interrupt enable bit of the assembly at the end of the transmission / reception */
#define CAN_Node_NCR_LECIE_Pos                2                      /*!< Interrupt enable bit of the assembly when it detects the last error code */
#define CAN_Node_NCR_ALIE_Pos                 3                      /*!< Enable interrupt ALERT from node */
#define CAN_Node_NCR_CANDIS_Pos               4                      /*!< Off node */
#define CAN_Node_NCR_CCE_Pos                  6                      /*!< Permission node configuration changes */
#define CAN_Node_NCR_CALM_Pos                 7                      /*!< Activate the node analysis */

/* Bit field masks: */
#define CAN_Node_NCR_INIT_Msk                 0x00000001UL           /*!< Node initialization */
#define CAN_Node_NCR_TRIE_Msk                 0x00000002UL           /*!< Interrupt enable bit of the assembly at the end of the transmission / reception */
#define CAN_Node_NCR_LECIE_Msk                0x00000004UL           /*!< Interrupt enable bit of the assembly when it detects the last error code */
#define CAN_Node_NCR_ALIE_Msk                 0x00000008UL           /*!< Enable interrupt ALERT from node */
#define CAN_Node_NCR_CANDIS_Msk               0x00000010UL           /*!< Off node */
#define CAN_Node_NCR_CCE_Msk                  0x00000040UL           /*!< Permission node configuration changes */
#define CAN_Node_NCR_CALM_Msk                 0x00000080UL           /*!< Activate the node analysis */

/*-- Node: NSR: Register state node0 --------------------------------------------------------------------------*/
typedef struct {
  uint32_t LEC                    :3;                                /*!< Last error code */
  uint32_t TXOK                   :1;                                /*!< Flag successful message transmission */
  uint32_t RXOK                   :1;                                /*!< Flag successful reception of messages */
  uint32_t ALERT                  :1;                                /*!< Warning flag ALERT */
  uint32_t EWRN                   :1;                                /*!< Flag critical errors */
  uint32_t BOFF                   :1;                                /*!< Status flag 'is disconnected from the bus' */
  uint32_t LLE                    :1;                                /*!< Error flag list */
  uint32_t LOE                    :1;                                /*!< Error Flag Room list */
} _CAN_Node_NSR_bits;

/* Bit field positions: */
#define CAN_Node_NSR_LEC_Pos                  0                      /*!< Last error code */
#define CAN_Node_NSR_TXOK_Pos                 3                      /*!< Flag successful message transmission */
#define CAN_Node_NSR_RXOK_Pos                 4                      /*!< Flag successful reception of messages */
#define CAN_Node_NSR_ALERT_Pos                5                      /*!< Warning flag ALERT */
#define CAN_Node_NSR_EWRN_Pos                 6                      /*!< Flag critical errors */
#define CAN_Node_NSR_BOFF_Pos                 7                      /*!< Status flag 'is disconnected from the bus' */
#define CAN_Node_NSR_LLE_Pos                  8                      /*!< Error flag list */
#define CAN_Node_NSR_LOE_Pos                  9                      /*!< Error Flag Room list */

/* Bit field masks: */
#define CAN_Node_NSR_LEC_Msk                  0x00000007UL           /*!< Last error code */
#define CAN_Node_NSR_TXOK_Msk                 0x00000008UL           /*!< Flag successful message transmission */
#define CAN_Node_NSR_RXOK_Msk                 0x00000010UL           /*!< Flag successful reception of messages */
#define CAN_Node_NSR_ALERT_Msk                0x00000020UL           /*!< Warning flag ALERT */
#define CAN_Node_NSR_EWRN_Msk                 0x00000040UL           /*!< Flag critical errors */
#define CAN_Node_NSR_BOFF_Msk                 0x00000080UL           /*!< Status flag 'is disconnected from the bus' */
#define CAN_Node_NSR_LLE_Msk                  0x00000100UL           /*!< Error flag list */
#define CAN_Node_NSR_LOE_Msk                  0x00000200UL           /*!< Error Flag Room list */

/* Bit field enums: */
typedef enum {
  CAN_Node_NSR_LEC_NoErr                     = 0x0UL,                /*!< no error */
  CAN_Node_NSR_LEC_StuffErr                  = 0x1UL,                /*!< stuff error */
  CAN_Node_NSR_LEC_FormErr                   = 0x2UL,                /*!< form error */
  CAN_Node_NSR_LEC_AckErr                    = 0x3UL,                /*!< acknowlegment error */
  CAN_Node_NSR_LEC_Bit1Err                   = 0x4UL,                /*!< bit 1 error */
  CAN_Node_NSR_LEC_Bit0Err                   = 0x5UL,                /*!< bit 0 error */
  CAN_Node_NSR_LEC_CRCErr                    = 0x6UL,                /*!< CRC error */
  CAN_Node_NSR_LEC_WriteEn                   = 0x7UL,                /*!< enable hardware write */
} CAN_Node_NSR_LEC_Enum;

/*-- Node: NIPR: Interrupt pointer register node0 -------------------------------------------------------------*/
typedef struct {
  uint32_t ALINP                  :4;                                /*!<  */
  uint32_t LECINP                 :4;                                /*!<  */
  uint32_t TRINP                  :4;                                /*!<  */
  uint32_t CFCINP                 :4;                                /*!<  */
} _CAN_Node_NIPR_bits;

/* Bit field positions: */
#define CAN_Node_NIPR_ALINP_Pos               0                      /*!<  */
#define CAN_Node_NIPR_LECINP_Pos              4                      /*!<  */
#define CAN_Node_NIPR_TRINP_Pos               8                      /*!<  */
#define CAN_Node_NIPR_CFCINP_Pos              12                     /*!<  */

/* Bit field masks: */
#define CAN_Node_NIPR_ALINP_Msk               0x0000000FUL           /*!<  */
#define CAN_Node_NIPR_LECINP_Msk              0x000000F0UL           /*!<  */
#define CAN_Node_NIPR_TRINP_Msk               0x00000F00UL           /*!<  */
#define CAN_Node_NIPR_CFCINP_Msk              0x0000F000UL           /*!<  */

/*-- Node: NPCR: Port control register node0 ------------------------------------------------------------------*/
typedef struct {
  uint32_t                        :8;                                /*!< RESERVED */
  uint32_t LBM                    :1;                                /*!< Enable mode Loop-Back */
} _CAN_Node_NPCR_bits;

/* Bit field positions: */
#define CAN_Node_NPCR_LBM_Pos                 8                      /*!< Enable mode Loop-Back */

/* Bit field masks: */
#define CAN_Node_NPCR_LBM_Msk                 0x00000100UL           /*!< Enable mode Loop-Back */

/*-- Node: NBTR: Timing register bits 0 -----------------------------------------------------------------------*/
typedef struct {
  uint32_t BRP                    :6;                                /*!< Prescaler rate */
  uint32_t SJW                    :2;                                /*!< Transition width resynchronization */
  uint32_t TSEG1                  :4;                                /*!< Parameter 1 */
  uint32_t TSEG2                  :3;                                /*!< Parameter 2 */
  uint32_t DIV8                   :1;                                /*!< Frequency divider by 8 */
} _CAN_Node_NBTR_bits;

/* Bit field positions: */
#define CAN_Node_NBTR_BRP_Pos                 0                      /*!< Prescaler rate */
#define CAN_Node_NBTR_SJW_Pos                 6                      /*!< Transition width resynchronization */
#define CAN_Node_NBTR_TSEG1_Pos               8                      /*!< Parameter 1 */
#define CAN_Node_NBTR_TSEG2_Pos               12                     /*!< Parameter 2 */
#define CAN_Node_NBTR_DIV8_Pos                15                     /*!< Frequency divider by 8 */

/* Bit field masks: */
#define CAN_Node_NBTR_BRP_Msk                 0x0000003FUL           /*!< Prescaler rate */
#define CAN_Node_NBTR_SJW_Msk                 0x000000C0UL           /*!< Transition width resynchronization */
#define CAN_Node_NBTR_TSEG1_Msk               0x00000F00UL           /*!< Parameter 1 */
#define CAN_Node_NBTR_TSEG2_Msk               0x00007000UL           /*!< Parameter 2 */
#define CAN_Node_NBTR_DIV8_Msk                0x00008000UL           /*!< Frequency divider by 8 */

/*-- Node: NECNT: Counter error register node0 ----------------------------------------------------------------*/
typedef struct {
  uint32_t REC                    :8;                                /*!< Receive Error Counter field messages */
  uint32_t TEC                    :8;                                /*!< Counter field messaging error */
  uint32_t EWRNLVL                :8;                                /*!< Error limit at which a flag is set in the register EWRN NSR */
  uint32_t LETD                   :1;                                /*!< Flag last transmission errors */
  uint32_t LEINC                  :1;                                /*!< Indicator increment at the last error */
} _CAN_Node_NECNT_bits;

/* Bit field positions: */
#define CAN_Node_NECNT_REC_Pos                0                      /*!< Receive Error Counter field messages */
#define CAN_Node_NECNT_TEC_Pos                8                      /*!< Counter field messaging error */
#define CAN_Node_NECNT_EWRNLVL_Pos            16                     /*!< Error limit at which a flag is set in the register EWRN NSR */
#define CAN_Node_NECNT_LETD_Pos               24                     /*!< Flag last transmission errors */
#define CAN_Node_NECNT_LEINC_Pos              25                     /*!< Indicator increment at the last error */

/* Bit field masks: */
#define CAN_Node_NECNT_REC_Msk                0x000000FFUL           /*!< Receive Error Counter field messages */
#define CAN_Node_NECNT_TEC_Msk                0x0000FF00UL           /*!< Counter field messaging error */
#define CAN_Node_NECNT_EWRNLVL_Msk            0x00FF0000UL           /*!< Error limit at which a flag is set in the register EWRN NSR */
#define CAN_Node_NECNT_LETD_Msk               0x01000000UL           /*!< Flag last transmission errors */
#define CAN_Node_NECNT_LEINC_Msk              0x02000000UL           /*!< Indicator increment at the last error */

/*-- Node: NFCR: Register message counter node0 ---------------------------------------------------------------*/
typedef struct {
  uint32_t CFC                    :16;                               /*!< Field of the message counter  */
  uint32_t CFSEL                  :3;                                /*!< Field parameter setting mode selected message counter */
  uint32_t CFMOD                  :2;                                /*!< Field task mode message counter */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t CFCIE                  :1;                                /*!< Interrupt enable bit of the message counter */
  uint32_t CFCOV                  :1;                                /*!< Counter overflow flag messages */
} _CAN_Node_NFCR_bits;

/* Bit field positions: */
#define CAN_Node_NFCR_CFC_Pos                 0                      /*!< Field of the message counter  */
#define CAN_Node_NFCR_CFSEL_Pos               16                     /*!< Field parameter setting mode selected message counter */
#define CAN_Node_NFCR_CFMOD_Pos               19                     /*!< Field task mode message counter */
#define CAN_Node_NFCR_CFCIE_Pos               22                     /*!< Interrupt enable bit of the message counter */
#define CAN_Node_NFCR_CFCOV_Pos               23                     /*!< Counter overflow flag messages */

/* Bit field masks: */
#define CAN_Node_NFCR_CFC_Msk                 0x0000FFFFUL           /*!< Field of the message counter  */
#define CAN_Node_NFCR_CFSEL_Msk               0x00070000UL           /*!< Field parameter setting mode selected message counter */
#define CAN_Node_NFCR_CFMOD_Msk               0x00180000UL           /*!< Field task mode message counter */
#define CAN_Node_NFCR_CFCIE_Msk               0x00400000UL           /*!< Interrupt enable bit of the message counter */
#define CAN_Node_NFCR_CFCOV_Msk               0x00800000UL           /*!< Counter overflow flag messages */

//Cluster LIST:
typedef struct {
  union {
  /*!< Register list0 */
    __I uint32_t LIST;                                               /*!< LIST : type used for word access */
    __I _CAN_LIST_bits LIST_bit;                                     /*!< LIST_bit: structure used for bit access */
  };
} _CAN_LIST_TypeDef;
//Cluster MSPND:
typedef struct {
  union {
  /*!< Register waiting interrupts0 */
    __IO uint32_t MSPND;                                             /*!< MSPND : type used for word access */
    __IO _CAN_MSPND_bits MSPND_bit;                                  /*!< MSPND_bit: structure used for bit access */
  };
} _CAN_MSPND_TypeDef;
//Cluster MSID:
typedef struct {
  union {
  /*!< Register messages index0 */
    __I uint32_t MSID;                                               /*!< MSID : type used for word access */
    __I _CAN_MSID_bits MSID_bit;                                     /*!< MSID_bit: structure used for bit access */
  };
} _CAN_MSID_TypeDef;
//Cluster Node:
typedef struct {
  union {
  /*!< Register control node0 */
    __IO uint32_t NCR;                                               /*!< NCR : type used for word access */
    __IO _CAN_Node_NCR_bits NCR_bit;                                 /*!< NCR_bit: structure used for bit access */
  };
  union {
  /*!< Register state node0 */
    __IO uint32_t NSR;                                               /*!< NSR : type used for word access */
    __IO _CAN_Node_NSR_bits NSR_bit;                                 /*!< NSR_bit: structure used for bit access */
  };
  union {
  /*!< Interrupt pointer register node0 */
    __IO uint32_t NIPR;                                              /*!< NIPR : type used for word access */
    __IO _CAN_Node_NIPR_bits NIPR_bit;                               /*!< NIPR_bit: structure used for bit access */
  };
  union {
  /*!< Port control register node0 */
    __IO uint32_t NPCR;                                              /*!< NPCR : type used for word access */
    __IO _CAN_Node_NPCR_bits NPCR_bit;                               /*!< NPCR_bit: structure used for bit access */
  };
  union {
  /*!< Timing register bits 0 */
    __IO uint32_t NBTR;                                              /*!< NBTR : type used for word access */
    __IO _CAN_Node_NBTR_bits NBTR_bit;                               /*!< NBTR_bit: structure used for bit access */
  };
  union {
  /*!< Counter error register node0 */
    __IO uint32_t NECNT;                                             /*!< NECNT : type used for word access */
    __IO _CAN_Node_NECNT_bits NECNT_bit;                             /*!< NECNT_bit: structure used for bit access */
  };
  union {
  /*!< Register message counter node0 */
    __IO uint32_t NFCR;                                              /*!< NFCR : type used for word access */
    __IO _CAN_Node_NFCR_bits NFCR_bit;                               /*!< NFCR_bit: structure used for bit access */
  };
    __IO uint32_t Reserved0[57];
} _CAN_Node_TypeDef;
typedef struct {
  union {                                                               /*!< Frequency control register */
    __IO uint32_t CLC;                                               /*!< CLC    : type used for word access */
    __IO _CAN_CLC_bits  CLC_bit;                                     /*!< CLC_bit: structure used for bit access */
  };
    __IO uint32_t Reserved0;
  union {                                                               /*!< Identity register */
    __IO uint32_t ID;                                                /*!< ID    : type used for word access */
    __IO _CAN_ID_bits  ID_bit;                                       /*!< ID_bit: structure used for bit access */
  };
  union {                                                               /*!< Register divider */
    __IO uint32_t FDR;                                               /*!< FDR    : type used for word access */
    __IO _CAN_FDR_bits  FDR_bit;                                     /*!< FDR_bit: structure used for bit access */
  };
    __IO uint32_t Reserved1[60];
  _CAN_LIST_TypeDef LIST[8];
    __IO uint32_t Reserved2[8];
  _CAN_MSPND_TypeDef MSPND[8];
    __IO uint32_t Reserved3[8];
  _CAN_MSID_TypeDef MSID[8];
    __IO uint32_t Reserved4[8];
  union {                                                               /*!< Mask register message index */
    __IO uint32_t MSIMASK;                                           /*!< MSIMASK    : type used for word access */
    __IO _CAN_MSIMASK_bits  MSIMASK_bit;                             /*!< MSIMASK_bit: structure used for bit access */
  };
  union {                                                               /*!< Register command panel */
    __IO uint32_t PANCTR;                                            /*!< PANCTR    : type used for word access */
    __IO _CAN_PANCTR_bits  PANCTR_bit;                               /*!< PANCTR_bit: structure used for bit access */
  };
  union {                                                               /*!<  */
    __IO uint32_t MCR;                                               /*!< MCR    : type used for word access */
    __IO _CAN_MCR_bits  MCR_bit;                                     /*!< MCR_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt register */
    __O uint32_t MITR;                                               /*!< MITR    : type used for word access */
    __O _CAN_MITR_bits  MITR_bit;                                    /*!< MITR_bit: structure used for bit access */
  };
    __IO uint32_t Reserved5[12];
  _CAN_Node_TypeDef Node[2];
} CAN_TypeDef;


/******************************************************************************/
/*                         CANMSG registers                                   */
/******************************************************************************/

/*-- Msg: MOFCR: Register control the operation of the message object 0 ---------------------------------------*/
typedef struct {
  uint32_t MMC                    :4;                                /*!<  */
  uint32_t                        :4;                                /*!< RESERVED */
  uint32_t GDFS                   :1;                                /*!<  */
  uint32_t IDC                    :1;                                /*!<  */
  uint32_t DLCC                   :1;                                /*!<  */
  uint32_t DATC                   :1;                                /*!<  */
  uint32_t                        :4;                                /*!< RESERVED */
  uint32_t RXIE                   :1;                                /*!< Interrupt enable after taking the messages */
  uint32_t TXIE                   :1;                                /*!< Interrupt enable at the end of the message */
  uint32_t OVIE                   :1;                                /*!< Interrupt enable FIFO to fill the message object 0 */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t FRREN                  :1;                                /*!< Enable remote request */
  uint32_t RMM                    :1;                                /*!< Enable remote monitoring of the communication object */
  uint32_t SDT                    :1;                                /*!< Bit single of the message object 0 participation in shipment */
  uint32_t STT                    :1;                                /*!< Bit single data transfer */
  uint32_t DLC                    :4;                                /*!< Data length code */
} _CANMSG_Msg_MOFCR_bits;

/* Bit field positions: */
#define CANMSG_Msg_MOFCR_MMC_Pos              0                      /*!<  */
#define CANMSG_Msg_MOFCR_GDFS_Pos             8                      /*!<  */
#define CANMSG_Msg_MOFCR_IDC_Pos              9                      /*!<  */
#define CANMSG_Msg_MOFCR_DLCC_Pos             10                     /*!<  */
#define CANMSG_Msg_MOFCR_DATC_Pos             11                     /*!<  */
#define CANMSG_Msg_MOFCR_RXIE_Pos             16                     /*!< Interrupt enable after taking the messages */
#define CANMSG_Msg_MOFCR_TXIE_Pos             17                     /*!< Interrupt enable at the end of the message */
#define CANMSG_Msg_MOFCR_OVIE_Pos             18                     /*!< Interrupt enable FIFO to fill the message object 0 */
#define CANMSG_Msg_MOFCR_FRREN_Pos            20                     /*!< Enable remote request */
#define CANMSG_Msg_MOFCR_RMM_Pos              21                     /*!< Enable remote monitoring of the communication object */
#define CANMSG_Msg_MOFCR_SDT_Pos              22                     /*!< Bit single of the message object 0 participation in shipment */
#define CANMSG_Msg_MOFCR_STT_Pos              23                     /*!< Bit single data transfer */
#define CANMSG_Msg_MOFCR_DLC_Pos              24                     /*!< Data length code */

/* Bit field masks: */
#define CANMSG_Msg_MOFCR_MMC_Msk              0x0000000FUL           /*!<  */
#define CANMSG_Msg_MOFCR_GDFS_Msk             0x00000100UL           /*!<  */
#define CANMSG_Msg_MOFCR_IDC_Msk              0x00000200UL           /*!<  */
#define CANMSG_Msg_MOFCR_DLCC_Msk             0x00000400UL           /*!<  */
#define CANMSG_Msg_MOFCR_DATC_Msk             0x00000800UL           /*!<  */
#define CANMSG_Msg_MOFCR_RXIE_Msk             0x00010000UL           /*!< Interrupt enable after taking the messages */
#define CANMSG_Msg_MOFCR_TXIE_Msk             0x00020000UL           /*!< Interrupt enable at the end of the message */
#define CANMSG_Msg_MOFCR_OVIE_Msk             0x00040000UL           /*!< Interrupt enable FIFO to fill the message object 0 */
#define CANMSG_Msg_MOFCR_FRREN_Msk            0x00100000UL           /*!< Enable remote request */
#define CANMSG_Msg_MOFCR_RMM_Msk              0x00200000UL           /*!< Enable remote monitoring of the communication object */
#define CANMSG_Msg_MOFCR_SDT_Msk              0x00400000UL           /*!< Bit single of the message object 0 participation in shipment */
#define CANMSG_Msg_MOFCR_STT_Msk              0x00800000UL           /*!< Bit single data transfer */
#define CANMSG_Msg_MOFCR_DLC_Msk              0x0F000000UL           /*!< Data length code */

/* Bit field enums: */
typedef enum {
  CANMSG_Msg_MOFCR_MMC_MsgObj                = 0x0UL,                /*!< message object */
  CANMSG_Msg_MOFCR_MMC_RXObj                 = 0x1UL,                /*!< receiver FIFO structure object */
  CANMSG_Msg_MOFCR_MMC_TXObj                 = 0x2UL,                /*!< transmitter FIFO structure object */
  CANMSG_Msg_MOFCR_MMC_SlaveTXObj            = 0x3UL,                /*!< transmitter FIFO structure slave object */
  CANMSG_Msg_MOFCR_MMC_SrcObj                = 0x4UL,                /*!< gateway source object */
} CANMSG_Msg_MOFCR_MMC_Enum;

/*-- Msg: MOFGPR: Pointer register FIFO / gateway message object 0 --------------------------------------------*/
typedef struct {
  uint32_t BOT                    :8;                                /*!< FIFO pointer to the lower element */
  uint32_t TOP                    :8;                                /*!< FIFO pointer to the top element  */
  uint32_t CUR                    :8;                                /*!< A pointer to the current object within the FIFO or gateway */
  uint32_t SEL                    :8;                                /*!< Object pointer message */
} _CANMSG_Msg_MOFGPR_bits;

/* Bit field positions: */
#define CANMSG_Msg_MOFGPR_BOT_Pos             0                      /*!< FIFO pointer to the lower element */
#define CANMSG_Msg_MOFGPR_TOP_Pos             8                      /*!< FIFO pointer to the top element  */
#define CANMSG_Msg_MOFGPR_CUR_Pos             16                     /*!< A pointer to the current object within the FIFO or gateway */
#define CANMSG_Msg_MOFGPR_SEL_Pos             24                     /*!< Object pointer message */

/* Bit field masks: */
#define CANMSG_Msg_MOFGPR_BOT_Msk             0x000000FFUL           /*!< FIFO pointer to the lower element */
#define CANMSG_Msg_MOFGPR_TOP_Msk             0x0000FF00UL           /*!< FIFO pointer to the top element  */
#define CANMSG_Msg_MOFGPR_CUR_Msk             0x00FF0000UL           /*!< A pointer to the current object within the FIFO or gateway */
#define CANMSG_Msg_MOFGPR_SEL_Msk             0xFF000000UL           /*!< Object pointer message */

/*-- Msg: MOIPR: Pointer register interrupt message object 0 --------------------------------------------------*/
typedef struct {
  uint32_t RXINP                  :4;                                /*!< Pointer interrupt line to interrupt after receiving */
  uint32_t TXINP                  :4;                                /*!< Pointer interrupt line to interrupt after transfer */
  uint32_t MPN                    :8;                                /*!< Number message waiting bit */
  uint32_t CFCVAL                 :16;                               /*!< Number of frames */
} _CANMSG_Msg_MOIPR_bits;

/* Bit field positions: */
#define CANMSG_Msg_MOIPR_RXINP_Pos            0                      /*!< Pointer interrupt line to interrupt after receiving */
#define CANMSG_Msg_MOIPR_TXINP_Pos            4                      /*!< Pointer interrupt line to interrupt after transfer */
#define CANMSG_Msg_MOIPR_MPN_Pos              8                      /*!< Number message waiting bit */
#define CANMSG_Msg_MOIPR_CFCVAL_Pos           16                     /*!< Number of frames */

/* Bit field masks: */
#define CANMSG_Msg_MOIPR_RXINP_Msk            0x0000000FUL           /*!< Pointer interrupt line to interrupt after receiving */
#define CANMSG_Msg_MOIPR_TXINP_Msk            0x000000F0UL           /*!< Pointer interrupt line to interrupt after transfer */
#define CANMSG_Msg_MOIPR_MPN_Msk              0x0000FF00UL           /*!< Number message waiting bit */
#define CANMSG_Msg_MOIPR_CFCVAL_Msk           0xFFFF0000UL           /*!< Number of frames */

/*-- Msg: MOAMR: Mask register message object 0 ---------------------------------------------------------------*/
typedef struct {
  uint32_t AM                     :29;                               /*!< Mask ID */
  uint32_t MIDE                   :1;                                /*!< Mask bit IDE message */
} _CANMSG_Msg_MOAMR_bits;

/* Bit field positions: */
#define CANMSG_Msg_MOAMR_AM_Pos               0                      /*!< Mask ID */
#define CANMSG_Msg_MOAMR_MIDE_Pos             29                     /*!< Mask bit IDE message */

/* Bit field masks: */
#define CANMSG_Msg_MOAMR_AM_Msk               0x1FFFFFFFUL           /*!< Mask ID */
#define CANMSG_Msg_MOAMR_MIDE_Msk             0x20000000UL           /*!< Mask bit IDE message */

/*-- Msg: MODATAL: Low data registers of the message object 0 -------------------------------------------------*/
typedef struct {
  uint32_t DB0                    :8;                                /*!< Zero byte data */
  uint32_t DB1                    :8;                                /*!< The first data byte */
  uint32_t DB2                    :8;                                /*!< Second data byte */
  uint32_t DB3                    :8;                                /*!< The third data byte */
} _CANMSG_Msg_MODATAL_bits;

/* Bit field positions: */
#define CANMSG_Msg_MODATAL_DB0_Pos            0                      /*!< Zero byte data */
#define CANMSG_Msg_MODATAL_DB1_Pos            8                      /*!< The first data byte */
#define CANMSG_Msg_MODATAL_DB2_Pos            16                     /*!< Second data byte */
#define CANMSG_Msg_MODATAL_DB3_Pos            24                     /*!< The third data byte */

/* Bit field masks: */
#define CANMSG_Msg_MODATAL_DB0_Msk            0x000000FFUL           /*!< Zero byte data */
#define CANMSG_Msg_MODATAL_DB1_Msk            0x0000FF00UL           /*!< The first data byte */
#define CANMSG_Msg_MODATAL_DB2_Msk            0x00FF0000UL           /*!< Second data byte */
#define CANMSG_Msg_MODATAL_DB3_Msk            0xFF000000UL           /*!< The third data byte */

/*-- Msg: MODATAH: High data registers of the message object 0 ------------------------------------------------*/
typedef struct {
  uint32_t DB4                    :8;                                /*!< The fourth data byte */
  uint32_t DB5                    :8;                                /*!< Fifth byte data */
  uint32_t DB6                    :8;                                /*!< Sixth byte data  */
  uint32_t DB7                    :8;                                /*!< Seventh byte of data  */
} _CANMSG_Msg_MODATAH_bits;

/* Bit field positions: */
#define CANMSG_Msg_MODATAH_DB4_Pos            0                      /*!< The fourth data byte */
#define CANMSG_Msg_MODATAH_DB5_Pos            8                      /*!< Fifth byte data */
#define CANMSG_Msg_MODATAH_DB6_Pos            16                     /*!< Sixth byte data  */
#define CANMSG_Msg_MODATAH_DB7_Pos            24                     /*!< Seventh byte of data  */

/* Bit field masks: */
#define CANMSG_Msg_MODATAH_DB4_Msk            0x000000FFUL           /*!< The fourth data byte */
#define CANMSG_Msg_MODATAH_DB5_Msk            0x0000FF00UL           /*!< Fifth byte data */
#define CANMSG_Msg_MODATAH_DB6_Msk            0x00FF0000UL           /*!< Sixth byte data  */
#define CANMSG_Msg_MODATAH_DB7_Msk            0xFF000000UL           /*!< Seventh byte of data  */

/*-- Msg: MOAR: Register arbitration message object 0 ---------------------------------------------------------*/
typedef struct {
  uint32_t ID                     :29;                               /*!< Object ID message 0 */
  uint32_t IDE                    :1;                                /*!< Bit extension identifier of the message object 0 */
  uint32_t PRI                    :2;                                /*!< Priority class */
} _CANMSG_Msg_MOAR_bits;

/* Bit field positions: */
#define CANMSG_Msg_MOAR_ID_Pos                0                      /*!< Object ID message 0 */
#define CANMSG_Msg_MOAR_IDE_Pos               29                     /*!< Bit extension identifier of the message object 0 */
#define CANMSG_Msg_MOAR_PRI_Pos               30                     /*!< Priority class */

/* Bit field masks: */
#define CANMSG_Msg_MOAR_ID_Msk                0x1FFFFFFFUL           /*!< Object ID message 0 */
#define CANMSG_Msg_MOAR_IDE_Msk               0x20000000UL           /*!< Bit extension identifier of the message object 0 */
#define CANMSG_Msg_MOAR_PRI_Msk               0xC0000000UL           /*!< Priority class */

/*-- Msg: MOCTR: Control register Message object 0 ------------------------------------------------------------*/
typedef struct {
  uint32_t RESRXPND               :1;                                /*!< Reset bit RXPND */
  uint32_t RESTXPND               :1;                                /*!< Reset bit TXPND */
  uint32_t RESRXUPD               :1;                                /*!< Reset bit RXUPD */
  uint32_t RESNEWDAT              :1;                                /*!< Reset bit NEWDAT */
  uint32_t RESMSGLST              :1;                                /*!< Reset bit MSGLST */
  uint32_t RESMSGVAL              :1;                                /*!< Reset bit MSGVAL */
  uint32_t RESRTSEL               :1;                                /*!< Reset bit RTSEL */
  uint32_t RESRXEN                :1;                                /*!< Reset bit RXEN */
  uint32_t RESTXRQ                :1;                                /*!< Reset bit TXRQ */
  uint32_t RESTXEN0               :1;                                /*!< Reset bit TXEN0 */
  uint32_t RESTXEN1               :1;                                /*!< Reset bit TXEN1 */
  uint32_t RESDIR                 :1;                                /*!< Reset bit DIR */
  uint32_t                        :4;                                /*!< RESERVED */
  uint32_t SETRXPND               :1;                                /*!< Set bit RXPND */
  uint32_t SETTXPND               :1;                                /*!< Set bit TXPND */
  uint32_t SETRXUPD               :1;                                /*!< Set bit RXUPD */
  uint32_t SETNEWDAT              :1;                                /*!< Set bit NEWDAT */
  uint32_t SETMSGLST              :1;                                /*!< Set bit MSGLST */
  uint32_t SETMSGVAL              :1;                                /*!< Set bit MSGVAL */
  uint32_t SETRTSEL               :1;                                /*!< Set bit RTSEL */
  uint32_t SETRXEN                :1;                                /*!< Set bit RXEN */
  uint32_t SETTXRQ                :1;                                /*!< Set bit TXRQ */
  uint32_t SETTXEN0               :1;                                /*!< Set bit TXEN0 */
  uint32_t SETTXEN1               :1;                                /*!< Set bit TXEN1 */
  uint32_t SETDIR                 :1;                                /*!< Set bit DIR */
} _CANMSG_Msg_MOCTR_bits;

/* Bit field positions: */
#define CANMSG_Msg_MOCTR_RESRXPND_Pos         0                      /*!< Reset bit RXPND */
#define CANMSG_Msg_MOCTR_RESTXPND_Pos         1                      /*!< Reset bit TXPND */
#define CANMSG_Msg_MOCTR_RESRXUPD_Pos         2                      /*!< Reset bit RXUPD */
#define CANMSG_Msg_MOCTR_RESNEWDAT_Pos        3                      /*!< Reset bit NEWDAT */
#define CANMSG_Msg_MOCTR_RESMSGLST_Pos        4                      /*!< Reset bit MSGLST */
#define CANMSG_Msg_MOCTR_RESMSGVAL_Pos        5                      /*!< Reset bit MSGVAL */
#define CANMSG_Msg_MOCTR_RESRTSEL_Pos         6                      /*!< Reset bit RTSEL */
#define CANMSG_Msg_MOCTR_RESRXEN_Pos          7                      /*!< Reset bit RXEN */
#define CANMSG_Msg_MOCTR_RESTXRQ_Pos          8                      /*!< Reset bit TXRQ */
#define CANMSG_Msg_MOCTR_RESTXEN0_Pos         9                      /*!< Reset bit TXEN0 */
#define CANMSG_Msg_MOCTR_RESTXEN1_Pos         10                     /*!< Reset bit TXEN1 */
#define CANMSG_Msg_MOCTR_RESDIR_Pos           11                     /*!< Reset bit DIR */
#define CANMSG_Msg_MOCTR_SETRXPND_Pos         16                     /*!< Set bit RXPND */
#define CANMSG_Msg_MOCTR_SETTXPND_Pos         17                     /*!< Set bit TXPND */
#define CANMSG_Msg_MOCTR_SETRXUPD_Pos         18                     /*!< Set bit RXUPD */
#define CANMSG_Msg_MOCTR_SETNEWDAT_Pos        19                     /*!< Set bit NEWDAT */
#define CANMSG_Msg_MOCTR_SETMSGLST_Pos        20                     /*!< Set bit MSGLST */
#define CANMSG_Msg_MOCTR_SETMSGVAL_Pos        21                     /*!< Set bit MSGVAL */
#define CANMSG_Msg_MOCTR_SETRTSEL_Pos         22                     /*!< Set bit RTSEL */
#define CANMSG_Msg_MOCTR_SETRXEN_Pos          23                     /*!< Set bit RXEN */
#define CANMSG_Msg_MOCTR_SETTXRQ_Pos          24                     /*!< Set bit TXRQ */
#define CANMSG_Msg_MOCTR_SETTXEN0_Pos         25                     /*!< Set bit TXEN0 */
#define CANMSG_Msg_MOCTR_SETTXEN1_Pos         26                     /*!< Set bit TXEN1 */
#define CANMSG_Msg_MOCTR_SETDIR_Pos           27                     /*!< Set bit DIR */

/* Bit field masks: */
#define CANMSG_Msg_MOCTR_RESRXPND_Msk         0x00000001UL           /*!< Reset bit RXPND */
#define CANMSG_Msg_MOCTR_RESTXPND_Msk         0x00000002UL           /*!< Reset bit TXPND */
#define CANMSG_Msg_MOCTR_RESRXUPD_Msk         0x00000004UL           /*!< Reset bit RXUPD */
#define CANMSG_Msg_MOCTR_RESNEWDAT_Msk        0x00000008UL           /*!< Reset bit NEWDAT */
#define CANMSG_Msg_MOCTR_RESMSGLST_Msk        0x00000010UL           /*!< Reset bit MSGLST */
#define CANMSG_Msg_MOCTR_RESMSGVAL_Msk        0x00000020UL           /*!< Reset bit MSGVAL */
#define CANMSG_Msg_MOCTR_RESRTSEL_Msk         0x00000040UL           /*!< Reset bit RTSEL */
#define CANMSG_Msg_MOCTR_RESRXEN_Msk          0x00000080UL           /*!< Reset bit RXEN */
#define CANMSG_Msg_MOCTR_RESTXRQ_Msk          0x00000100UL           /*!< Reset bit TXRQ */
#define CANMSG_Msg_MOCTR_RESTXEN0_Msk         0x00000200UL           /*!< Reset bit TXEN0 */
#define CANMSG_Msg_MOCTR_RESTXEN1_Msk         0x00000400UL           /*!< Reset bit TXEN1 */
#define CANMSG_Msg_MOCTR_RESDIR_Msk           0x00000800UL           /*!< Reset bit DIR */
#define CANMSG_Msg_MOCTR_SETRXPND_Msk         0x00010000UL           /*!< Set bit RXPND */
#define CANMSG_Msg_MOCTR_SETTXPND_Msk         0x00020000UL           /*!< Set bit TXPND */
#define CANMSG_Msg_MOCTR_SETRXUPD_Msk         0x00040000UL           /*!< Set bit RXUPD */
#define CANMSG_Msg_MOCTR_SETNEWDAT_Msk        0x00080000UL           /*!< Set bit NEWDAT */
#define CANMSG_Msg_MOCTR_SETMSGLST_Msk        0x00100000UL           /*!< Set bit MSGLST */
#define CANMSG_Msg_MOCTR_SETMSGVAL_Msk        0x00200000UL           /*!< Set bit MSGVAL */
#define CANMSG_Msg_MOCTR_SETRTSEL_Msk         0x00400000UL           /*!< Set bit RTSEL */
#define CANMSG_Msg_MOCTR_SETRXEN_Msk          0x00800000UL           /*!< Set bit RXEN */
#define CANMSG_Msg_MOCTR_SETTXRQ_Msk          0x01000000UL           /*!< Set bit TXRQ */
#define CANMSG_Msg_MOCTR_SETTXEN0_Msk         0x02000000UL           /*!< Set bit TXEN0 */
#define CANMSG_Msg_MOCTR_SETTXEN1_Msk         0x04000000UL           /*!< Set bit TXEN1 */
#define CANMSG_Msg_MOCTR_SETDIR_Msk           0x08000000UL           /*!< Set bit DIR */

/*-- Msg: MOSTAT: Status register of the message object 0 -----------------------------------------------------*/
typedef struct {
  uint32_t RXPND                  :1;                                /*!< Indicator deadline */
  uint32_t TXPND                  :1;                                /*!< Indicator end of transmission */
  uint32_t RXUPD                  :1;                                /*!< Indicator changes */
  uint32_t NEWDAT                 :1;                                /*!< New data indicator */
  uint32_t MSGLST                 :1;                                /*!< Bit message loss */
  uint32_t MSGVAL                 :1;                                /*!< Activity bit of the message object 0 */
  uint32_t RTSEL                  :1;                                /*!< The indication of transmission / reception */
  uint32_t RXEN                   :1;                                /*!< Bits allow reception */
  uint32_t TXRQ                   :1;                                /*!< Initiate transmission */
  uint32_t TXEN0                  :1;                                /*!< Enable bit transmission frame */
  uint32_t TXEN1                  :1;                                /*!< Enable bit transmission frame */
  uint32_t DIR                    :1;                                /*!< Bit allocation */
  uint32_t LIST                   :4;                                /*!< Number list  the message object 0 */
  uint32_t PPREV                  :8;                                /*!< Pointer to the previous entry */
  uint32_t PNEXT                  :8;                                /*!< Pointer to the next item in the list */
} _CANMSG_Msg_MOSTAT_bits;

/* Bit field positions: */
#define CANMSG_Msg_MOSTAT_RXPND_Pos           0                      /*!< Indicator deadline */
#define CANMSG_Msg_MOSTAT_TXPND_Pos           1                      /*!< Indicator end of transmission */
#define CANMSG_Msg_MOSTAT_RXUPD_Pos           2                      /*!< Indicator changes */
#define CANMSG_Msg_MOSTAT_NEWDAT_Pos          3                      /*!< New data indicator */
#define CANMSG_Msg_MOSTAT_MSGLST_Pos          4                      /*!< Bit message loss */
#define CANMSG_Msg_MOSTAT_MSGVAL_Pos          5                      /*!< Activity bit of the message object 0 */
#define CANMSG_Msg_MOSTAT_RTSEL_Pos           6                      /*!< The indication of transmission / reception */
#define CANMSG_Msg_MOSTAT_RXEN_Pos            7                      /*!< Bits allow reception */
#define CANMSG_Msg_MOSTAT_TXRQ_Pos            8                      /*!< Initiate transmission */
#define CANMSG_Msg_MOSTAT_TXEN0_Pos           9                      /*!< Enable bit transmission frame */
#define CANMSG_Msg_MOSTAT_TXEN1_Pos           10                     /*!< Enable bit transmission frame */
#define CANMSG_Msg_MOSTAT_DIR_Pos             11                     /*!< Bit allocation */
#define CANMSG_Msg_MOSTAT_LIST_Pos            12                     /*!< Number list  the message object 0 */
#define CANMSG_Msg_MOSTAT_PPREV_Pos           16                     /*!< Pointer to the previous entry */
#define CANMSG_Msg_MOSTAT_PNEXT_Pos           24                     /*!< Pointer to the next item in the list */

/* Bit field masks: */
#define CANMSG_Msg_MOSTAT_RXPND_Msk           0x00000001UL           /*!< Indicator deadline */
#define CANMSG_Msg_MOSTAT_TXPND_Msk           0x00000002UL           /*!< Indicator end of transmission */
#define CANMSG_Msg_MOSTAT_RXUPD_Msk           0x00000004UL           /*!< Indicator changes */
#define CANMSG_Msg_MOSTAT_NEWDAT_Msk          0x00000008UL           /*!< New data indicator */
#define CANMSG_Msg_MOSTAT_MSGLST_Msk          0x00000010UL           /*!< Bit message loss */
#define CANMSG_Msg_MOSTAT_MSGVAL_Msk          0x00000020UL           /*!< Activity bit of the message object 0 */
#define CANMSG_Msg_MOSTAT_RTSEL_Msk           0x00000040UL           /*!< The indication of transmission / reception */
#define CANMSG_Msg_MOSTAT_RXEN_Msk            0x00000080UL           /*!< Bits allow reception */
#define CANMSG_Msg_MOSTAT_TXRQ_Msk            0x00000100UL           /*!< Initiate transmission */
#define CANMSG_Msg_MOSTAT_TXEN0_Msk           0x00000200UL           /*!< Enable bit transmission frame */
#define CANMSG_Msg_MOSTAT_TXEN1_Msk           0x00000400UL           /*!< Enable bit transmission frame */
#define CANMSG_Msg_MOSTAT_DIR_Msk             0x00000800UL           /*!< Bit allocation */
#define CANMSG_Msg_MOSTAT_LIST_Msk            0x0000F000UL           /*!< Number list  the message object 0 */
#define CANMSG_Msg_MOSTAT_PPREV_Msk           0x00FF0000UL           /*!< Pointer to the previous entry */
#define CANMSG_Msg_MOSTAT_PNEXT_Msk           0xFF000000UL           /*!< Pointer to the next item in the list */

//Cluster Msg:
typedef struct {
  union {
  /*!< Register control the operation of the message object 0 */
    __IO uint32_t MOFCR;                                             /*!< MOFCR : type used for word access */
    __IO _CANMSG_Msg_MOFCR_bits MOFCR_bit;                           /*!< MOFCR_bit: structure used for bit access */
  };
  union {
  /*!< Pointer register FIFO / gateway message object 0 */
    __IO uint32_t MOFGPR;                                            /*!< MOFGPR : type used for word access */
    __IO _CANMSG_Msg_MOFGPR_bits MOFGPR_bit;                         /*!< MOFGPR_bit: structure used for bit access */
  };
  union {
  /*!< Pointer register interrupt message object 0 */
    __IO uint32_t MOIPR;                                             /*!< MOIPR : type used for word access */
    __IO _CANMSG_Msg_MOIPR_bits MOIPR_bit;                           /*!< MOIPR_bit: structure used for bit access */
  };
  union {
  /*!< Mask register message object 0 */
    __IO uint32_t MOAMR;                                             /*!< MOAMR : type used for word access */
    __IO _CANMSG_Msg_MOAMR_bits MOAMR_bit;                           /*!< MOAMR_bit: structure used for bit access */
  };
  union {
  /*!< Low data registers of the message object 0 */
    __IO uint32_t MODATAL;                                           /*!< MODATAL : type used for word access */
    __IO _CANMSG_Msg_MODATAL_bits MODATAL_bit;                       /*!< MODATAL_bit: structure used for bit access */
  };
  union {
  /*!< High data registers of the message object 0 */
    __IO uint32_t MODATAH;                                           /*!< MODATAH : type used for word access */
    __IO _CANMSG_Msg_MODATAH_bits MODATAH_bit;                       /*!< MODATAH_bit: structure used for bit access */
  };
  union {
  /*!< Register arbitration message object 0 */
    __IO uint32_t MOAR;                                              /*!< MOAR : type used for word access */
    __IO _CANMSG_Msg_MOAR_bits MOAR_bit;                             /*!< MOAR_bit: structure used for bit access */
  };
  union {
      union {
                                                                     /*!< Control register Message object 0 */
        __O uint32_t MOCTR;                                           /*!< MOCTR : type used for word access */
        __O _CANMSG_Msg_MOCTR_bits MOCTR_bit;                        /*!< MOCTR_bit: structure used for bit access */
      };
      union {
                                                                     /*!< Status register of the message object 0 */
        __I uint32_t MOSTAT;                                           /*!< MOSTAT : type used for word access */
        __I _CANMSG_Msg_MOSTAT_bits MOSTAT_bit;                      /*!< MOSTAT_bit: structure used for bit access */
      };
  };
} _CANMSG_Msg_TypeDef;
typedef struct {
  _CANMSG_Msg_TypeDef Msg[256];
} CANMSG_TypeDef;


/******************************************************************************/
/*                         CAP registers                                      */
/******************************************************************************/

/*--  TSCTR: Counter register ---------------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!< Counter value */
} _CAP_TSCTR_bits;

/* Bit field positions: */
#define CAP_TSCTR_VAL_Pos                     0                      /*!< Counter value */

/* Bit field masks: */
#define CAP_TSCTR_VAL_Msk                     0xFFFFFFFFUL           /*!< Counter value */

/*--  CTRPHS: Counter Phase Sync register ---------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!<  */
} _CAP_CTRPHS_bits;

/* Bit field positions: */
#define CAP_CTRPHS_VAL_Pos                    0                      /*!<  */

/* Bit field masks: */
#define CAP_CTRPHS_VAL_Msk                    0xFFFFFFFFUL           /*!<  */

/*--  CAPREG0: Capture register 0 -----------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!< Capture 0 value */
} _CAP_CAPREG0_bits;

/* Bit field positions: */
#define CAP_CAPREG0_VAL_Pos                   0                      /*!< Capture 0 value */

/* Bit field masks: */
#define CAP_CAPREG0_VAL_Msk                   0xFFFFFFFFUL           /*!< Capture 0 value */

/*--  PRD: Period register ------------------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!< Period value in APWM mode */
} _CAP_PRD_bits;

/* Bit field positions: */
#define CAP_PRD_VAL_Pos                       0                      /*!< Period value in APWM mode */

/* Bit field masks: */
#define CAP_PRD_VAL_Msk                       0xFFFFFFFFUL           /*!< Period value in APWM mode */

/*--  CAPREG1: Capture register 1 -----------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!< Capture 1 value */
} _CAP_CAPREG1_bits;

/* Bit field positions: */
#define CAP_CAPREG1_VAL_Pos                   0                      /*!< Capture 1 value */

/* Bit field masks: */
#define CAP_CAPREG1_VAL_Msk                   0xFFFFFFFFUL           /*!< Capture 1 value */

/*--  CMP: Compare register -----------------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!< Compare value in APWM mode */
} _CAP_CMP_bits;

/* Bit field positions: */
#define CAP_CMP_VAL_Pos                       0                      /*!< Compare value in APWM mode */

/* Bit field masks: */
#define CAP_CMP_VAL_Msk                       0xFFFFFFFFUL           /*!< Compare value in APWM mode */

/*--  CAPREG2: Capture register 2 -----------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!< Capture 2 value */
} _CAP_CAPREG2_bits;

/* Bit field positions: */
#define CAP_CAPREG2_VAL_Pos                   0                      /*!< Capture 2 value */

/* Bit field masks: */
#define CAP_CAPREG2_VAL_Msk                   0xFFFFFFFFUL           /*!< Capture 2 value */

/*--  PRDSHDW: Period shadow register -------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!< Period shadow value in APWM mode */
} _CAP_PRDSHDW_bits;

/* Bit field positions: */
#define CAP_PRDSHDW_VAL_Pos                   0                      /*!< Period shadow value in APWM mode */

/* Bit field masks: */
#define CAP_PRDSHDW_VAL_Msk                   0xFFFFFFFFUL           /*!< Period shadow value in APWM mode */

/*--  CAPREG3: Capture register 3 -----------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!< Capture 3 value */
} _CAP_CAPREG3_bits;

/* Bit field positions: */
#define CAP_CAPREG3_VAL_Pos                   0                      /*!< Capture 3 value */

/* Bit field masks: */
#define CAP_CAPREG3_VAL_Msk                   0xFFFFFFFFUL           /*!< Capture 3 value */

/*--  CMPSHDW: Compare shadow register ------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!< Compare shadow value in APWM mode */
} _CAP_CMPSHDW_bits;

/* Bit field positions: */
#define CAP_CMPSHDW_VAL_Pos                   0                      /*!< Compare shadow value in APWM mode */

/* Bit field masks: */
#define CAP_CMPSHDW_VAL_Msk                   0xFFFFFFFFUL           /*!< Compare shadow value in APWM mode */

/*--  ECCTL0: Capture control  register 0 ---------------------------------------------------------------------*/
typedef struct {
  uint32_t CAP0POL                :1;                                /*!< Polarity select for capture 0 */
  uint32_t CTRRST0                :1;                                /*!< Reset counter after event 0 */
  uint32_t CAP1POL                :1;                                /*!< Polarity select for capture 1 */
  uint32_t CTRRST1                :1;                                /*!< Reset counter after event 1 */
  uint32_t CAP2POL                :1;                                /*!< Polarity select for capture 2 */
  uint32_t CTRRST2                :1;                                /*!< Reset counter after event 2 */
  uint32_t CAP3POL                :1;                                /*!< Polarity select for capture 3 */
  uint32_t CTRRST3                :1;                                /*!< Reset counter after event 3 */
  uint32_t CAPLDEN                :1;                                /*!< enable capture */
  uint32_t PRESCALE               :5;                                /*!< Prescaler value */
  uint32_t FREESOFT               :2;                                /*!< Emulation mode control */
} _CAP_ECCTL0_bits;

/* Bit field positions: */
#define CAP_ECCTL0_CAP0POL_Pos                0                      /*!< Polarity select for capture 0 */
#define CAP_ECCTL0_CTRRST0_Pos                1                      /*!< Reset counter after event 0 */
#define CAP_ECCTL0_CAP1POL_Pos                2                      /*!< Polarity select for capture 1 */
#define CAP_ECCTL0_CTRRST1_Pos                3                      /*!< Reset counter after event 1 */
#define CAP_ECCTL0_CAP2POL_Pos                4                      /*!< Polarity select for capture 2 */
#define CAP_ECCTL0_CTRRST2_Pos                5                      /*!< Reset counter after event 2 */
#define CAP_ECCTL0_CAP3POL_Pos                6                      /*!< Polarity select for capture 3 */
#define CAP_ECCTL0_CTRRST3_Pos                7                      /*!< Reset counter after event 3 */
#define CAP_ECCTL0_CAPLDEN_Pos                8                      /*!< enable capture */
#define CAP_ECCTL0_PRESCALE_Pos               9                      /*!< Prescaler value */
#define CAP_ECCTL0_FREESOFT_Pos               14                     /*!< Emulation mode control */

/* Bit field masks: */
#define CAP_ECCTL0_CAP0POL_Msk                0x00000001UL           /*!< Polarity select for capture 0 */
#define CAP_ECCTL0_CTRRST0_Msk                0x00000002UL           /*!< Reset counter after event 0 */
#define CAP_ECCTL0_CAP1POL_Msk                0x00000004UL           /*!< Polarity select for capture 1 */
#define CAP_ECCTL0_CTRRST1_Msk                0x00000008UL           /*!< Reset counter after event 1 */
#define CAP_ECCTL0_CAP2POL_Msk                0x00000010UL           /*!< Polarity select for capture 2 */
#define CAP_ECCTL0_CTRRST2_Msk                0x00000020UL           /*!< Reset counter after event 2 */
#define CAP_ECCTL0_CAP3POL_Msk                0x00000040UL           /*!< Polarity select for capture 3 */
#define CAP_ECCTL0_CTRRST3_Msk                0x00000080UL           /*!< Reset counter after event 3 */
#define CAP_ECCTL0_CAPLDEN_Msk                0x00000100UL           /*!< enable capture */
#define CAP_ECCTL0_PRESCALE_Msk               0x00003E00UL           /*!< Prescaler value */
#define CAP_ECCTL0_FREESOFT_Msk               0x0000C000UL           /*!< Emulation mode control */

/* Bit field enums: */
typedef enum {
  CAP_ECCTL0_FREESOFT_Stop                   = 0x0UL,                /*!< stop timer immedeatelly */
  CAP_ECCTL0_FREESOFT_StopAtZero             = 0x1UL,                /*!< stop timer when reach zero */
  CAP_ECCTL0_FREESOFT_Free                   = 0x2UL,                /*!< normal work */
} CAP_ECCTL0_FREESOFT_Enum;

/*--  ECCTL1: Capture control register 1 ----------------------------------------------------------------------*/
typedef struct {
  uint32_t CONTOST                :1;                                /*!< Capture mode */
  uint32_t STOPWRAP               :2;                                /*!< Stop compare value */
  uint32_t REARM                  :1;                                /*!< Reset and enable controller, capture reg load */
  uint32_t TSCTRSTOP              :1;                                /*!< Enable Timer */
  uint32_t SYNCIEN                :1;                                /*!< Sync in enable */
  uint32_t SYNCOSEL               :2;                                /*!< SYNCO source selection */
  uint32_t SWSYNC                 :1;                                /*!< Software timers sync */
  uint32_t CAPAPWM                :1;                                /*!< Capture mode or APWM mode */
  uint32_t APWMPOL                :1;                                /*!< High/low level APWM */
} _CAP_ECCTL1_bits;

/* Bit field positions: */
#define CAP_ECCTL1_CONTOST_Pos                0                      /*!< Capture mode */
#define CAP_ECCTL1_STOPWRAP_Pos               1                      /*!< Stop compare value */
#define CAP_ECCTL1_REARM_Pos                  3                      /*!< Reset and enable controller, capture reg load */
#define CAP_ECCTL1_TSCTRSTOP_Pos              4                      /*!< Enable Timer */
#define CAP_ECCTL1_SYNCIEN_Pos                5                      /*!< Sync in enable */
#define CAP_ECCTL1_SYNCOSEL_Pos               6                      /*!< SYNCO source selection */
#define CAP_ECCTL1_SWSYNC_Pos                 8                      /*!< Software timers sync */
#define CAP_ECCTL1_CAPAPWM_Pos                9                      /*!< Capture mode or APWM mode */
#define CAP_ECCTL1_APWMPOL_Pos                10                     /*!< High/low level APWM */

/* Bit field masks: */
#define CAP_ECCTL1_CONTOST_Msk                0x00000001UL           /*!< Capture mode */
#define CAP_ECCTL1_STOPWRAP_Msk               0x00000006UL           /*!< Stop compare value */
#define CAP_ECCTL1_REARM_Msk                  0x00000008UL           /*!< Reset and enable controller, capture reg load */
#define CAP_ECCTL1_TSCTRSTOP_Msk              0x00000010UL           /*!< Enable Timer */
#define CAP_ECCTL1_SYNCIEN_Msk                0x00000020UL           /*!< Sync in enable */
#define CAP_ECCTL1_SYNCOSEL_Msk               0x000000C0UL           /*!< SYNCO source selection */
#define CAP_ECCTL1_SWSYNC_Msk                 0x00000100UL           /*!< Software timers sync */
#define CAP_ECCTL1_CAPAPWM_Msk                0x00000200UL           /*!< Capture mode or APWM mode */
#define CAP_ECCTL1_APWMPOL_Msk                0x00000400UL           /*!< High/low level APWM */

/* Bit field enums: */
typedef enum {
  CAP_ECCTL1_SYNCOSEL_Bypass                 = 0x0UL,                /*!< sync in connected with sync out */
  CAP_ECCTL1_SYNCOSEL_CTREqPrd               = 0x1UL,                /*!< sync out generated when CTR = PRD */
  CAP_ECCTL1_SYNCOSEL_Disable                = 0x2UL,                /*!< sync out generate disabled */
} CAP_ECCTL1_SYNCOSEL_Enum;

/*--  ECEINT: Interrupt mask register -------------------------------------------------------------------------*/
typedef struct {
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t CEVT0                  :1;                                /*!< enable int CEVT0 */
  uint32_t CEVT1                  :1;                                /*!< enable int CEVT1 */
  uint32_t CEVT2                  :1;                                /*!< enable int CEVT2 */
  uint32_t CEVT3                  :1;                                /*!< enable int CEVT3 */
  uint32_t CTROVF                 :1;                                /*!< enable int CTR_OVF */
  uint32_t CTRPRD                 :1;                                /*!< enable int CTR=PRD */
  uint32_t CTRCMP                 :1;                                /*!< enable int CTR=CMP */
} _CAP_ECEINT_bits;

/* Bit field positions: */
#define CAP_ECEINT_CEVT0_Pos                  1                      /*!< enable int CEVT0 */
#define CAP_ECEINT_CEVT1_Pos                  2                      /*!< enable int CEVT1 */
#define CAP_ECEINT_CEVT2_Pos                  3                      /*!< enable int CEVT2 */
#define CAP_ECEINT_CEVT3_Pos                  4                      /*!< enable int CEVT3 */
#define CAP_ECEINT_CTROVF_Pos                 5                      /*!< enable int CTR_OVF */
#define CAP_ECEINT_CTRPRD_Pos                 6                      /*!< enable int CTR=PRD */
#define CAP_ECEINT_CTRCMP_Pos                 7                      /*!< enable int CTR=CMP */

/* Bit field masks: */
#define CAP_ECEINT_CEVT0_Msk                  0x00000002UL           /*!< enable int CEVT0 */
#define CAP_ECEINT_CEVT1_Msk                  0x00000004UL           /*!< enable int CEVT1 */
#define CAP_ECEINT_CEVT2_Msk                  0x00000008UL           /*!< enable int CEVT2 */
#define CAP_ECEINT_CEVT3_Msk                  0x00000010UL           /*!< enable int CEVT3 */
#define CAP_ECEINT_CTROVF_Msk                 0x00000020UL           /*!< enable int CTR_OVF */
#define CAP_ECEINT_CTRPRD_Msk                 0x00000040UL           /*!< enable int CTR=PRD */
#define CAP_ECEINT_CTRCMP_Msk                 0x00000080UL           /*!< enable int CTR=CMP */

/*--  ECFLG: Interrupt status register ------------------------------------------------------------------------*/
typedef struct {
  uint32_t INT                    :1;                                /*!< indicate global interrupt */
  uint32_t CEVT0                  :1;                                /*!< Hap interrupt CEVT0 */
  uint32_t CEVT1                  :1;                                /*!< Hap interrupt CEVT1 */
  uint32_t CEVT2                  :1;                                /*!< Hap interrupt CEVT2 */
  uint32_t CEVT3                  :1;                                /*!< Hap interrupt CEVT3 */
  uint32_t CTROVF                 :1;                                /*!< Hap interrupt CTROVF */
  uint32_t CTRPRD                 :1;                                /*!< Hap interrupt CTR=PRD */
  uint32_t CTRCMP                 :1;                                /*!< Hap interrupt CTR=CMP */
} _CAP_ECFLG_bits;

/* Bit field positions: */
#define CAP_ECFLG_INT_Pos                     0                      /*!< indicate global interrupt */
#define CAP_ECFLG_CEVT0_Pos                   1                      /*!< Hap interrupt CEVT0 */
#define CAP_ECFLG_CEVT1_Pos                   2                      /*!< Hap interrupt CEVT1 */
#define CAP_ECFLG_CEVT2_Pos                   3                      /*!< Hap interrupt CEVT2 */
#define CAP_ECFLG_CEVT3_Pos                   4                      /*!< Hap interrupt CEVT3 */
#define CAP_ECFLG_CTROVF_Pos                  5                      /*!< Hap interrupt CTROVF */
#define CAP_ECFLG_CTRPRD_Pos                  6                      /*!< Hap interrupt CTR=PRD */
#define CAP_ECFLG_CTRCMP_Pos                  7                      /*!< Hap interrupt CTR=CMP */

/* Bit field masks: */
#define CAP_ECFLG_INT_Msk                     0x00000001UL           /*!< indicate global interrupt */
#define CAP_ECFLG_CEVT0_Msk                   0x00000002UL           /*!< Hap interrupt CEVT0 */
#define CAP_ECFLG_CEVT1_Msk                   0x00000004UL           /*!< Hap interrupt CEVT1 */
#define CAP_ECFLG_CEVT2_Msk                   0x00000008UL           /*!< Hap interrupt CEVT2 */
#define CAP_ECFLG_CEVT3_Msk                   0x00000010UL           /*!< Hap interrupt CEVT3 */
#define CAP_ECFLG_CTROVF_Msk                  0x00000020UL           /*!< Hap interrupt CTROVF */
#define CAP_ECFLG_CTRPRD_Msk                  0x00000040UL           /*!< Hap interrupt CTR=PRD */
#define CAP_ECFLG_CTRCMP_Msk                  0x00000080UL           /*!< Hap interrupt CTR=CMP */

/*--  ECCLR: Clear interrupt register -------------------------------------------------------------------------*/
typedef struct {
  uint32_t INT                    :1;                                /*!< reset global interrupt */
  uint32_t CEVT0                  :1;                                /*!< reset intstatus */
  uint32_t CEVT1                  :1;                                /*!< reset intstatus */
  uint32_t CEVT2                  :1;                                /*!< reset intstatus */
  uint32_t CEVT3                  :1;                                /*!< reset intstatus */
  uint32_t CTROVF                 :1;                                /*!< reset intstatus */
  uint32_t CTRPRD                 :1;                                /*!< reset intstatus */
  uint32_t CTRCMP                 :1;                                /*!< reset intstatus */
} _CAP_ECCLR_bits;

/* Bit field positions: */
#define CAP_ECCLR_INT_Pos                     0                      /*!< reset global interrupt */
#define CAP_ECCLR_CEVT0_Pos                   1                      /*!< reset intstatus */
#define CAP_ECCLR_CEVT1_Pos                   2                      /*!< reset intstatus */
#define CAP_ECCLR_CEVT2_Pos                   3                      /*!< reset intstatus */
#define CAP_ECCLR_CEVT3_Pos                   4                      /*!< reset intstatus */
#define CAP_ECCLR_CTROVF_Pos                  5                      /*!< reset intstatus */
#define CAP_ECCLR_CTRPRD_Pos                  6                      /*!< reset intstatus */
#define CAP_ECCLR_CTRCMP_Pos                  7                      /*!< reset intstatus */

/* Bit field masks: */
#define CAP_ECCLR_INT_Msk                     0x00000001UL           /*!< reset global interrupt */
#define CAP_ECCLR_CEVT0_Msk                   0x00000002UL           /*!< reset intstatus */
#define CAP_ECCLR_CEVT1_Msk                   0x00000004UL           /*!< reset intstatus */
#define CAP_ECCLR_CEVT2_Msk                   0x00000008UL           /*!< reset intstatus */
#define CAP_ECCLR_CEVT3_Msk                   0x00000010UL           /*!< reset intstatus */
#define CAP_ECCLR_CTROVF_Msk                  0x00000020UL           /*!< reset intstatus */
#define CAP_ECCLR_CTRPRD_Msk                  0x00000040UL           /*!< reset intstatus */
#define CAP_ECCLR_CTRCMP_Msk                  0x00000080UL           /*!< reset intstatus */

/*--  ECFRC: Force interrupt register -------------------------------------------------------------------------*/
typedef struct {
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t CEVT0                  :1;                                /*!< gen test interrupt */
  uint32_t CEVT1                  :1;                                /*!< gen test interrupt */
  uint32_t CEVT2                  :1;                                /*!< gen test interrupt */
  uint32_t CEVT3                  :1;                                /*!< gen test interrupt */
  uint32_t CTROVF                 :1;                                /*!< gen test interrupt */
  uint32_t CTRPRD                 :1;                                /*!< gen test interrupt */
  uint32_t CTRCMP                 :1;                                /*!< gen test interrupt */
} _CAP_ECFRC_bits;

/* Bit field positions: */
#define CAP_ECFRC_CEVT0_Pos                   1                      /*!< gen test interrupt */
#define CAP_ECFRC_CEVT1_Pos                   2                      /*!< gen test interrupt */
#define CAP_ECFRC_CEVT2_Pos                   3                      /*!< gen test interrupt */
#define CAP_ECFRC_CEVT3_Pos                   4                      /*!< gen test interrupt */
#define CAP_ECFRC_CTROVF_Pos                  5                      /*!< gen test interrupt */
#define CAP_ECFRC_CTRPRD_Pos                  6                      /*!< gen test interrupt */
#define CAP_ECFRC_CTRCMP_Pos                  7                      /*!< gen test interrupt */

/* Bit field masks: */
#define CAP_ECFRC_CEVT0_Msk                   0x00000002UL           /*!< gen test interrupt */
#define CAP_ECFRC_CEVT1_Msk                   0x00000004UL           /*!< gen test interrupt */
#define CAP_ECFRC_CEVT2_Msk                   0x00000008UL           /*!< gen test interrupt */
#define CAP_ECFRC_CEVT3_Msk                   0x00000010UL           /*!< gen test interrupt */
#define CAP_ECFRC_CTROVF_Msk                  0x00000020UL           /*!< gen test interrupt */
#define CAP_ECFRC_CTRPRD_Msk                  0x00000040UL           /*!< gen test interrupt */
#define CAP_ECFRC_CTRCMP_Msk                  0x00000080UL           /*!< gen test interrupt */

/*--  PEINT: Active interrupt status register -----------------------------------------------------------------*/
typedef struct {
  uint32_t PEINT                  :1;                                /*!< active interrupt flag */
} _CAP_PEINT_bits;

/* Bit field positions: */
#define CAP_PEINT_PEINT_Pos                   0                      /*!< active interrupt flag */

/* Bit field masks: */
#define CAP_PEINT_PEINT_Msk                   0x00000001UL           /*!< active interrupt flag */

/*--  DMATXREQ: DMA TX request mask register ------------------------------------------------------------------*/
typedef struct {
  uint32_t FRC                    :1;                                /*!< Send DMA software request */
  uint32_t CEVT0                  :1;                                /*!< Send DMA request when CEVT0 */
  uint32_t CEVT1                  :1;                                /*!< Send DMA request when CEVT1 */
  uint32_t CEVT2                  :1;                                /*!< Send DMA request when CEVT2 */
  uint32_t CEVT3                  :1;                                /*!< Send DMA request when CEVT3 */
  uint32_t CTROVF                 :1;                                /*!< Send DMA request when CTROVF */
  uint32_t CTRPRD                 :1;                                /*!< Send DMA request when CTR=PRD */
  uint32_t CTRCMP                 :1;                                /*!< Send DMA request when CTR=CMP */
} _CAP_DMATXREQ_bits;

/* Bit field positions: */
#define CAP_DMATXREQ_FRC_Pos                  0                      /*!< Send DMA software request */
#define CAP_DMATXREQ_CEVT0_Pos                1                      /*!< Send DMA request when CEVT0 */
#define CAP_DMATXREQ_CEVT1_Pos                2                      /*!< Send DMA request when CEVT1 */
#define CAP_DMATXREQ_CEVT2_Pos                3                      /*!< Send DMA request when CEVT2 */
#define CAP_DMATXREQ_CEVT3_Pos                4                      /*!< Send DMA request when CEVT3 */
#define CAP_DMATXREQ_CTROVF_Pos               5                      /*!< Send DMA request when CTROVF */
#define CAP_DMATXREQ_CTRPRD_Pos               6                      /*!< Send DMA request when CTR=PRD */
#define CAP_DMATXREQ_CTRCMP_Pos               7                      /*!< Send DMA request when CTR=CMP */

/* Bit field masks: */
#define CAP_DMATXREQ_FRC_Msk                  0x00000001UL           /*!< Send DMA software request */
#define CAP_DMATXREQ_CEVT0_Msk                0x00000002UL           /*!< Send DMA request when CEVT0 */
#define CAP_DMATXREQ_CEVT1_Msk                0x00000004UL           /*!< Send DMA request when CEVT1 */
#define CAP_DMATXREQ_CEVT2_Msk                0x00000008UL           /*!< Send DMA request when CEVT2 */
#define CAP_DMATXREQ_CEVT3_Msk                0x00000010UL           /*!< Send DMA request when CEVT3 */
#define CAP_DMATXREQ_CTROVF_Msk               0x00000020UL           /*!< Send DMA request when CTROVF */
#define CAP_DMATXREQ_CTRPRD_Msk               0x00000040UL           /*!< Send DMA request when CTR=PRD */
#define CAP_DMATXREQ_CTRCMP_Msk               0x00000080UL           /*!< Send DMA request when CTR=CMP */

/*--  DMARXREQ: DMA RX request mask register ------------------------------------------------------------------*/
typedef struct {
  uint32_t FRC                    :1;                                /*!< Send DMA software request */
  uint32_t CEVT0                  :1;                                /*!< Send DMA request when CEVT0 */
  uint32_t CEVT1                  :1;                                /*!< Send DMA request when CEVT1 */
  uint32_t CEVT2                  :1;                                /*!< Send DMA request when CEVT2 */
  uint32_t CEVT3                  :1;                                /*!< Send DMA request when CEVT3 */
  uint32_t CTROVF                 :1;                                /*!< Send DMA request when CTROVF */
  uint32_t CTRPRD                 :1;                                /*!< Send DMA request when CTR=PRD */
  uint32_t CTRCMP                 :1;                                /*!< Send DMA request when CTR=CMP */
} _CAP_DMARXREQ_bits;

/* Bit field positions: */
#define CAP_DMARXREQ_FRC_Pos                  0                      /*!< Send DMA software request */
#define CAP_DMARXREQ_CEVT0_Pos                1                      /*!< Send DMA request when CEVT0 */
#define CAP_DMARXREQ_CEVT1_Pos                2                      /*!< Send DMA request when CEVT1 */
#define CAP_DMARXREQ_CEVT2_Pos                3                      /*!< Send DMA request when CEVT2 */
#define CAP_DMARXREQ_CEVT3_Pos                4                      /*!< Send DMA request when CEVT3 */
#define CAP_DMARXREQ_CTROVF_Pos               5                      /*!< Send DMA request when CTROVF */
#define CAP_DMARXREQ_CTRPRD_Pos               6                      /*!< Send DMA request when CTR=PRD */
#define CAP_DMARXREQ_CTRCMP_Pos               7                      /*!< Send DMA request when CTR=CMP */

/* Bit field masks: */
#define CAP_DMARXREQ_FRC_Msk                  0x00000001UL           /*!< Send DMA software request */
#define CAP_DMARXREQ_CEVT0_Msk                0x00000002UL           /*!< Send DMA request when CEVT0 */
#define CAP_DMARXREQ_CEVT1_Msk                0x00000004UL           /*!< Send DMA request when CEVT1 */
#define CAP_DMARXREQ_CEVT2_Msk                0x00000008UL           /*!< Send DMA request when CEVT2 */
#define CAP_DMARXREQ_CEVT3_Msk                0x00000010UL           /*!< Send DMA request when CEVT3 */
#define CAP_DMARXREQ_CTROVF_Msk               0x00000020UL           /*!< Send DMA request when CTROVF */
#define CAP_DMARXREQ_CTRPRD_Msk               0x00000040UL           /*!< Send DMA request when CTR=PRD */
#define CAP_DMARXREQ_CTRCMP_Msk               0x00000080UL           /*!< Send DMA request when CTR=CMP */

typedef struct {
  union {                                                               /*!< Counter register */
    __IO uint32_t TSCTR;                                             /*!< TSCTR    : type used for word access */
    __IO _CAP_TSCTR_bits  TSCTR_bit;                                 /*!< TSCTR_bit: structure used for bit access */
  };
  union {                                                               /*!< Counter Phase Sync register */
    __IO uint32_t CTRPHS;                                            /*!< CTRPHS    : type used for word access */
    __IO _CAP_CTRPHS_bits  CTRPHS_bit;                               /*!< CTRPHS_bit: structure used for bit access */
  };
  union {
    union {                                                               /*!< Capture register 0 */
      __IO uint32_t CAPREG0;                                           /*!< CAPREG0    : type used for word access */
      __IO _CAP_CAPREG0_bits  CAPREG0_bit;                           /*!< CAPREG0_bit: structure used for bit access */
    };
    struct {
      union {                                                               /*!< Period register */
        __IO uint32_t PRD;                                           /*!< PRD    : type used for word access */
        __IO _CAP_PRD_bits  PRD_bit;                                 /*!< PRD_bit: structure used for bit access */
      };
    };
  };
  union {
    union {                                                               /*!< Capture register 1 */
      __IO uint32_t CAPREG1;                                           /*!< CAPREG1    : type used for word access */
      __IO _CAP_CAPREG1_bits  CAPREG1_bit;                           /*!< CAPREG1_bit: structure used for bit access */
    };
    struct {
      union {                                                               /*!< Compare register */
        __IO uint32_t CMP;                                           /*!< CMP    : type used for word access */
        __IO _CAP_CMP_bits  CMP_bit;                                 /*!< CMP_bit: structure used for bit access */
      };
    };
  };
  union {
    union {                                                               /*!< Capture register 2 */
      __IO uint32_t CAPREG2;                                           /*!< CAPREG2    : type used for word access */
      __IO _CAP_CAPREG2_bits  CAPREG2_bit;                           /*!< CAPREG2_bit: structure used for bit access */
    };
    struct {
      union {                                                               /*!< Period shadow register */
        __IO uint32_t PRDSHDW;                                           /*!< PRDSHDW    : type used for word access */
        __IO _CAP_PRDSHDW_bits  PRDSHDW_bit;                         /*!< PRDSHDW_bit: structure used for bit access */
      };
    };
  };
  union {
    union {                                                               /*!< Capture register 3 */
      __IO uint32_t CAPREG3;                                           /*!< CAPREG3    : type used for word access */
      __IO _CAP_CAPREG3_bits  CAPREG3_bit;                           /*!< CAPREG3_bit: structure used for bit access */
    };
    struct {
      union {                                                               /*!< Compare shadow register */
        __IO uint32_t CMPSHDW;                                           /*!< CMPSHDW    : type used for word access */
        __IO _CAP_CMPSHDW_bits  CMPSHDW_bit;                         /*!< CMPSHDW_bit: structure used for bit access */
      };
    };
  };
    __IO uint32_t Reserved0[4];
  union {                                                               /*!< Capture control  register 0 */
    __IO uint32_t ECCTL0;                                            /*!< ECCTL0    : type used for word access */
    __IO _CAP_ECCTL0_bits  ECCTL0_bit;                               /*!< ECCTL0_bit: structure used for bit access */
  };
  union {                                                               /*!< Capture control register 1 */
    __IO uint32_t ECCTL1;                                            /*!< ECCTL1    : type used for word access */
    __IO _CAP_ECCTL1_bits  ECCTL1_bit;                               /*!< ECCTL1_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt mask register */
    __IO uint32_t ECEINT;                                            /*!< ECEINT    : type used for word access */
    __IO _CAP_ECEINT_bits  ECEINT_bit;                               /*!< ECEINT_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt status register */
    __IO uint32_t ECFLG;                                             /*!< ECFLG    : type used for word access */
    __IO _CAP_ECFLG_bits  ECFLG_bit;                                 /*!< ECFLG_bit: structure used for bit access */
  };
  union {                                                               /*!< Clear interrupt register */
    __IO uint32_t ECCLR;                                             /*!< ECCLR    : type used for word access */
    __IO _CAP_ECCLR_bits  ECCLR_bit;                                 /*!< ECCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Force interrupt register */
    __IO uint32_t ECFRC;                                             /*!< ECFRC    : type used for word access */
    __IO _CAP_ECFRC_bits  ECFRC_bit;                                 /*!< ECFRC_bit: structure used for bit access */
  };
  union {                                                               /*!< Active interrupt status register */
    __IO uint32_t PEINT;                                             /*!< PEINT    : type used for word access */
    __IO _CAP_PEINT_bits  PEINT_bit;                                 /*!< PEINT_bit: structure used for bit access */
  };
  union {                                                               /*!< DMA TX request mask register */
    __IO uint32_t DMATXREQ;                                           /*!< DMATXREQ    : type used for word access */
    __IO _CAP_DMATXREQ_bits  DMATXREQ_bit;                           /*!< DMATXREQ_bit: structure used for bit access */
  };
  union {                                                               /*!< DMA RX request mask register */
    __IO uint32_t DMARXREQ;                                           /*!< DMARXREQ    : type used for word access */
    __IO _CAP_DMARXREQ_bits  DMARXREQ_bit;                           /*!< DMARXREQ_bit: structure used for bit access */
  };
} CAP_TypeDef;


/******************************************************************************/
/*                         DMA registers                                      */
/******************************************************************************/

/*-- CH: SRC_PTR: Command register 0 (source pointer) ---------------------------------------------------------*/
typedef struct {
  uint32_t RD_ADDR                :32;                               /*!< Start address of read buffer */
} _DMA_CH_SRC_PTR_bits;

/* Bit field positions: */
#define DMA_CH_SRC_PTR_RD_ADDR_Pos            0                      /*!< Start address of read buffer */

/* Bit field masks: */
#define DMA_CH_SRC_PTR_RD_ADDR_Msk            0xFFFFFFFFUL           /*!< Start address of read buffer */

/*-- CH: DST_PTR: Command register 1 (destination pointer) ----------------------------------------------------*/
typedef struct {
  uint32_t WR_ADDR                :32;                               /*!< Start address of write buffer */
} _DMA_CH_DST_PTR_bits;

/* Bit field positions: */
#define DMA_CH_DST_PTR_WR_ADDR_Pos            0                      /*!< Start address of write buffer */

/* Bit field masks: */
#define DMA_CH_DST_PTR_WR_ADDR_Msk            0xFFFFFFFFUL           /*!< Start address of write buffer */

/*-- CH: NDTL: Command register 2 (number of data to transfer, linear mode) -----------------------------------*/
typedef struct {
  uint32_t BUFFER_SIZE            :10;                               /*!< Size of buffer to transfer */
} _DMA_CH_NDTL_bits;

/* Bit field positions: */
#define DMA_CH_NDTL_BUFFER_SIZE_Pos           0                      /*!< Size of buffer to transfer */

/* Bit field masks: */
#define DMA_CH_NDTL_BUFFER_SIZE_Msk           0x000003FFUL           /*!< Size of buffer to transfer */

/*-- CH: NDTB: Command register 2 (number of data to transfer, block mode) - Not Implemented --------------------------------*/
typedef struct {
  uint32_t X_SIZE                 :8;                                /*!< Number of block lines  - Not Implemented */
  uint32_t Y_SIZE                 :2;                                /*!< Number of block lines  - Not Implemented */
} _DMA_CH_NDTB_bits;

/* Bit field positions: */
#define DMA_CH_NDTB_X_SIZE_Pos                0                      /*!< Number of block lines  - Not Implemented */
#define DMA_CH_NDTB_Y_SIZE_Pos                8                      /*!< Number of block lines  - Not Implemented */

/* Bit field masks: */
#define DMA_CH_NDTB_X_SIZE_Msk                0x000000FFUL           /*!< Number of block lines  - Not Implemented */
#define DMA_CH_NDTB_Y_SIZE_Msk                0x00000300UL           /*!< Number of block lines  - Not Implemented */

/*-- CH: CONFIG: Command register 3 (config) ------------------------------------------------------------------*/
typedef struct {
  uint32_t CMD_SET_INT            :1;                                /*!< Set interrupt after the entire buffer has been transferred */
  uint32_t CMD_LAST               :1;                                /*!< This is a last DMA command */
  uint32_t NEXT_ADDR              :30;                               /*!< Address of next command */
} _DMA_CH_CONFIG_bits;

/* Bit field positions: */
#define DMA_CH_CONFIG_CMD_SET_INT_Pos         0                      /*!< Set interrupt after the entire buffer has been transferred */
#define DMA_CH_CONFIG_CMD_LAST_Pos            1                      /*!< This is a last DMA command */
#define DMA_CH_CONFIG_NEXT_ADDR_Pos           2                      /*!< Address of next command */

/* Bit field masks: */
#define DMA_CH_CONFIG_CMD_SET_INT_Msk         0x00000001UL           /*!< Set interrupt after the entire buffer has been transferred */
#define DMA_CH_CONFIG_CMD_LAST_Msk            0x00000002UL           /*!< This is a last DMA command */
#define DMA_CH_CONFIG_NEXT_ADDR_Msk           0xFFFFFFFCUL           /*!< Address of next command */

/*-- CH: STATIC0: Static register 0 ---------------------------------------------------------------------------*/
typedef struct {
  uint32_t RD_BURST_MAX           :7;                                /*!< Maximum number of bytes of an AXI read burst */
  uint32_t                        :9;                                /*!< RESERVED */
  uint32_t RD_TOKENS              :6;                                /*!< Number of AXI read commands to issue before the channel releases the AXI command bus */
  uint32_t                        :2;                                /*!< RESERVED */
  uint32_t RD_OUTS_MAX            :4;                                /*!< Number of maximum outstanding AXI read commands */
  uint32_t                        :2;                                /*!< RESERVED */
  uint32_t RD_OUTSTCFG            :1;                                /*!< Channel cfg: Use AXI read command when FIFO is full - Not implemented */
  uint32_t RD_INCR                :1;                                /*!< Increment next burst address */
} _DMA_CH_STATIC0_bits;

/* Bit field positions: */
#define DMA_CH_STATIC0_RD_BURST_MAX_Pos       0                      /*!< Maximum number of bytes of an AXI read burst */
#define DMA_CH_STATIC0_RD_TOKENS_Pos          16                     /*!< Number of AXI read commands to issue before the channel releases the AXI command bus */
#define DMA_CH_STATIC0_RD_OUTS_MAX_Pos        24                     /*!< Number of maximum outstanding AXI read commands */
#define DMA_CH_STATIC0_RD_OUTSTCFG_Pos        30                     /*!< Channel cfg: Use AXI read command when FIFO is full - Not implemented */
#define DMA_CH_STATIC0_RD_INCR_Pos            31                     /*!< Increment next burst address */

/* Bit field masks: */
#define DMA_CH_STATIC0_RD_BURST_MAX_Msk       0x0000007FUL           /*!< Maximum number of bytes of an AXI read burst */
#define DMA_CH_STATIC0_RD_TOKENS_Msk          0x003F0000UL           /*!< Number of AXI read commands to issue before the channel releases the AXI command bus */
#define DMA_CH_STATIC0_RD_OUTS_MAX_Msk        0x0F000000UL           /*!< Number of maximum outstanding AXI read commands */
#define DMA_CH_STATIC0_RD_OUTSTCFG_Msk        0x40000000UL           /*!< Channel cfg: Use AXI read command when FIFO is full - Not implemented */
#define DMA_CH_STATIC0_RD_INCR_Msk            0x80000000UL           /*!< Increment next burst address */

/*-- CH: STATIC1: Static register 1 ---------------------------------------------------------------------------*/
typedef struct {
  uint32_t WR_BURST_MAX           :7;                                /*!< Maximum number of bytes of an AXI write burst */
  uint32_t                        :9;                                /*!< RESERVED */
  uint32_t WR_TOKENS              :6;                                /*!< Number of AXI write commands to issue before the channel releases the AXI command bus */
  uint32_t                        :2;                                /*!< RESERVED */
  uint32_t WR_OUTS_MAX            :4;                                /*!< Number of maximum outstanding AXI write commands */
  uint32_t                        :2;                                /*!< RESERVED */
  uint32_t WR_OUTSTCFG            :1;                                /*!< Channel cfg: Use AXI write command when FIFO is full - Not implemented */
  uint32_t WR_INCR                :1;                                /*!< Increment next burst address */
} _DMA_CH_STATIC1_bits;

/* Bit field positions: */
#define DMA_CH_STATIC1_WR_BURST_MAX_Pos       0                      /*!< Maximum number of bytes of an AXI write burst */
#define DMA_CH_STATIC1_WR_TOKENS_Pos          16                     /*!< Number of AXI write commands to issue before the channel releases the AXI command bus */
#define DMA_CH_STATIC1_WR_OUTS_MAX_Pos        24                     /*!< Number of maximum outstanding AXI write commands */
#define DMA_CH_STATIC1_WR_OUTSTCFG_Pos        30                     /*!< Channel cfg: Use AXI write command when FIFO is full - Not implemented */
#define DMA_CH_STATIC1_WR_INCR_Pos            31                     /*!< Increment next burst address */

/* Bit field masks: */
#define DMA_CH_STATIC1_WR_BURST_MAX_Msk       0x0000007FUL           /*!< Maximum number of bytes of an AXI write burst */
#define DMA_CH_STATIC1_WR_TOKENS_Msk          0x003F0000UL           /*!< Number of AXI write commands to issue before the channel releases the AXI command bus */
#define DMA_CH_STATIC1_WR_OUTS_MAX_Msk        0x0F000000UL           /*!< Number of maximum outstanding AXI write commands */
#define DMA_CH_STATIC1_WR_OUTSTCFG_Msk        0x40000000UL           /*!< Channel cfg: Use AXI write command when FIFO is full - Not implemented */
#define DMA_CH_STATIC1_WR_INCR_Msk            0x80000000UL           /*!< Increment next burst address */

/*-- CH: STATIC2: Static register 2 ---------------------------------------------------------------------------*/
typedef struct {
  uint32_t FRAME_WIDTH            :12;                               /*!< Frame width for block mode - Not Implemented */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t BLOCK                  :1;                                /*!< Work in block mode - Not Implemented */
  uint32_t JOINT                  :1;                                /*!< Channel works in joint mode */
  uint32_t RETRY                  :1;                                /*!< If set the channel will automatically retry transfer if overflow or underflow occurs - Not implemented */
  uint32_t                        :10;                               /*!< RESERVED */
  uint32_t END_SWAP               :2;                                /*!< Endiannes byte swapping */
} _DMA_CH_STATIC2_bits;

/* Bit field positions: */
#define DMA_CH_STATIC2_FRAME_WIDTH_Pos        0                      /*!< Frame width for block mode - Not Implemented */
#define DMA_CH_STATIC2_BLOCK_Pos              15                     /*!< Work in block mode - Not Implemented */
#define DMA_CH_STATIC2_JOINT_Pos              16                     /*!< Channel works in joint mode */
#define DMA_CH_STATIC2_RETRY_Pos              17                     /*!< If set the channel will automatically retry transfer if overflow or underflow occurs - Not implemented */
#define DMA_CH_STATIC2_END_SWAP_Pos           28                     /*!< Endiannes byte swapping */

/* Bit field masks: */
#define DMA_CH_STATIC2_FRAME_WIDTH_Msk        0x00000FFFUL           /*!< Frame width for block mode - Not Implemented */
#define DMA_CH_STATIC2_BLOCK_Msk              0x00008000UL           /*!< Work in block mode - Not Implemented */
#define DMA_CH_STATIC2_JOINT_Msk              0x00010000UL           /*!< Channel works in joint mode */
#define DMA_CH_STATIC2_RETRY_Msk              0x00020000UL           /*!< If set the channel will automatically retry transfer if overflow or underflow occurs - Not implemented */
#define DMA_CH_STATIC2_END_SWAP_Msk           0x30000000UL           /*!< Endiannes byte swapping */

/* Bit field enums: */
typedef enum {
  DMA_CH_STATIC2_END_SWAP_NO_SWAP            = 0x0UL,                /*!< No swapping */
  DMA_CH_STATIC2_END_SWAP_SWAP_WITHIN16bits   = 0x1UL,               /*!< Swap bytes within 16 bits */
  DMA_CH_STATIC2_END_SWAP_SWAP_WITHIN32bits   = 0x2UL,               /*!< Swap bytes within 32 bits */
  DMA_CH_STATIC2_END_SWAP_RESERVED           = 0x3UL,                /*!< Reserved */
} DMA_CH_STATIC2_END_SWAP_Enum;

/*-- CH: STATIC3: Static register 3 ---------------------------------------------------------------------------*/
typedef struct {
  uint32_t RD_WAIT_LIM            :12;                               /*!< Maximum number of cycles to wait after a channel is released and before its starts read command */
  uint32_t                        :4;                                /*!< RESERVED */
  uint32_t WR_WAIT_LIM            :12;                               /*!< Maximum number of cycles to wait after a channel is released and before its starts write command */
} _DMA_CH_STATIC3_bits;

/* Bit field positions: */
#define DMA_CH_STATIC3_RD_WAIT_LIM_Pos        0                      /*!< Maximum number of cycles to wait after a channel is released and before its starts read command */
#define DMA_CH_STATIC3_WR_WAIT_LIM_Pos        16                     /*!< Maximum number of cycles to wait after a channel is released and before its starts write command */

/* Bit field masks: */
#define DMA_CH_STATIC3_RD_WAIT_LIM_Msk        0x00000FFFUL           /*!< Maximum number of cycles to wait after a channel is released and before its starts read command */
#define DMA_CH_STATIC3_WR_WAIT_LIM_Msk        0x0FFF0000UL           /*!< Maximum number of cycles to wait after a channel is released and before its starts write command */

/*-- CH: STATIC4: Static register 4 ---------------------------------------------------------------------------*/
typedef struct {
  uint32_t RD_PER_NUM             :5;                                /*!< Number of peripheral to read from */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t RD_PER_DELAY           :3;                                /*!< Peripheral latency for AXI read operation (must be set more than 1 for work with perepherals) */
  uint32_t                        :4;                                /*!< RESERVED */
  uint32_t RD_PER_BLOCK           :1;                                /*!< Peripheral control works in block mode */
  uint32_t WR_PER_NUM             :5;                                /*!< Number of peripheral to write from */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t WR_PER_DELAY           :3;                                /*!< Peripheral latency for AXI write operation (must be set more than 1 for work with perepherals) */
  uint32_t                        :4;                                /*!< RESERVED */
  uint32_t WR_PER_BLOCK           :1;                                /*!< Peripheral control works in block mode */
} _DMA_CH_STATIC4_bits;

/* Bit field positions: */
#define DMA_CH_STATIC4_RD_PER_NUM_Pos         0                      /*!< Number of peripheral to read from */
#define DMA_CH_STATIC4_RD_PER_DELAY_Pos       8                      /*!< Peripheral latency for AXI read operation (must be set more than 1 for work with perepherals) */
#define DMA_CH_STATIC4_RD_PER_BLOCK_Pos       15                     /*!< Peripheral control works in block mode */
#define DMA_CH_STATIC4_WR_PER_NUM_Pos         16                     /*!< Number of peripheral to write from */
#define DMA_CH_STATIC4_WR_PER_DELAY_Pos       24                     /*!< Peripheral latency for AXI write operation (must be set more than 1 for work with perepherals) */
#define DMA_CH_STATIC4_WR_PER_BLOCK_Pos       31                     /*!< Peripheral control works in block mode */

/* Bit field masks: */
#define DMA_CH_STATIC4_RD_PER_NUM_Msk         0x0000001FUL           /*!< Number of peripheral to read from */
#define DMA_CH_STATIC4_RD_PER_DELAY_Msk       0x00000700UL           /*!< Peripheral latency for AXI read operation (must be set more than 1 for work with perepherals) */
#define DMA_CH_STATIC4_RD_PER_BLOCK_Msk       0x00008000UL           /*!< Peripheral control works in block mode */
#define DMA_CH_STATIC4_WR_PER_NUM_Msk         0x001F0000UL           /*!< Number of peripheral to write from */
#define DMA_CH_STATIC4_WR_PER_DELAY_Msk       0x07000000UL           /*!< Peripheral latency for AXI write operation (must be set more than 1 for work with perepherals) */
#define DMA_CH_STATIC4_WR_PER_BLOCK_Msk       0x80000000UL           /*!< Peripheral control works in block mode */

/*-- CH: RESTRICT: Channels restrictions status register ------------------------------------------------------*/
typedef struct {
  uint32_t RD_ALLOWFIFO           :1;                                /*!< Read start address does not restrict burst size */
  uint32_t WR_ALLOWFIFO           :1;                                /*!< Write start address does not restrict burst size */
  uint32_t ALLOW_FIFO             :1;                                /*!< Burst size can equal data buffer size */
  uint32_t ALLOW_FBURST           :1;                                /*!< Maximum bursts of 16 strobes can be used */
  uint32_t ALLOW_JBURST           :1;                                /*!< Joint bursts are currently active */
  uint32_t RD_OUTSTAND            :1;                                /*!< Read outstanding is currently active */
  uint32_t WR_OUTSTAND            :1;                                /*!< Write outstanding is currently active */
  uint32_t NONALIGN               :1;                                /*!< Block configuration is not aligned */
  uint32_t SIMPLE_STAT            :1;                                /*!< Configuration is aligned and perepherals are not used */
} _DMA_CH_RESTRICT_bits;

/* Bit field positions: */
#define DMA_CH_RESTRICT_RD_ALLOWFIFO_Pos       0                     /*!< Read start address does not restrict burst size */
#define DMA_CH_RESTRICT_WR_ALLOWFIFO_Pos       1                     /*!< Write start address does not restrict burst size */
#define DMA_CH_RESTRICT_ALLOW_FIFO_Pos        2                      /*!< Burst size can equal data buffer size */
#define DMA_CH_RESTRICT_ALLOW_FBURST_Pos       3                     /*!< Maximum bursts of 16 strobes can be used */
#define DMA_CH_RESTRICT_ALLOW_JBURST_Pos       4                     /*!< Joint bursts are currently active */
#define DMA_CH_RESTRICT_RD_OUTSTAND_Pos       5                      /*!< Read outstanding is currently active */
#define DMA_CH_RESTRICT_WR_OUTSTAND_Pos       6                      /*!< Write outstanding is currently active */
#define DMA_CH_RESTRICT_NONALIGN_Pos          7                      /*!< Block configuration is not aligned */
#define DMA_CH_RESTRICT_SIMPLE_STAT_Pos       8                      /*!< Configuration is aligned and perepherals are not used */

/* Bit field masks: */
#define DMA_CH_RESTRICT_RD_ALLOWFIFO_Msk       0x00000001UL          /*!< Read start address does not restrict burst size */
#define DMA_CH_RESTRICT_WR_ALLOWFIFO_Msk       0x00000002UL          /*!< Write start address does not restrict burst size */
#define DMA_CH_RESTRICT_ALLOW_FIFO_Msk        0x00000004UL           /*!< Burst size can equal data buffer size */
#define DMA_CH_RESTRICT_ALLOW_FBURST_Msk       0x00000008UL          /*!< Maximum bursts of 16 strobes can be used */
#define DMA_CH_RESTRICT_ALLOW_JBURST_Msk       0x00000010UL          /*!< Joint bursts are currently active */
#define DMA_CH_RESTRICT_RD_OUTSTAND_Msk       0x00000020UL           /*!< Read outstanding is currently active */
#define DMA_CH_RESTRICT_WR_OUTSTAND_Msk       0x00000040UL           /*!< Write outstanding is currently active */
#define DMA_CH_RESTRICT_NONALIGN_Msk          0x00000080UL           /*!< Block configuration is not aligned */
#define DMA_CH_RESTRICT_SIMPLE_STAT_Msk       0x00000100UL           /*!< Configuration is aligned and perepherals are not used */

/*-- CH: RDOFFSET: Channels read offset status register -------------------------------------------------------*/
typedef struct {
  uint32_t RD_OFFSET              :16;                               /*!< Offset from the beginning of the buffer */
} _DMA_CH_RDOFFSET_bits;

/* Bit field positions: */
#define DMA_CH_RDOFFSET_RD_OFFSET_Pos         0                      /*!< Offset from the beginning of the buffer */

/* Bit field masks: */
#define DMA_CH_RDOFFSET_RD_OFFSET_Msk         0x0000FFFFUL           /*!< Offset from the beginning of the buffer */

/*-- CH: WROFFSET: Channels write offset status register ------------------------------------------------------*/
typedef struct {
  uint32_t WR_OFFSET              :16;                               /*!< Offset from the beginning of the buffer */
} _DMA_CH_WROFFSET_bits;

/* Bit field positions: */
#define DMA_CH_WROFFSET_WR_OFFSET_Pos         0                      /*!< Offset from the beginning of the buffer */

/* Bit field masks: */
#define DMA_CH_WROFFSET_WR_OFFSET_Msk         0x0000FFFFUL           /*!< Offset from the beginning of the buffer */

/*-- CH: FIFOSTAT: FIFO fullness status register --------------------------------------------------------------*/
typedef struct {
  uint32_t RD_GAP                 :6;                                /*!< Remaining space for channels FIFO for read data */
  uint32_t                        :10;                               /*!< RESERVED */
  uint32_t WR_FULLNESS            :6;                                /*!< Occupied space in channels FIFO by write data */
} _DMA_CH_FIFOSTAT_bits;

/* Bit field positions: */
#define DMA_CH_FIFOSTAT_RD_GAP_Pos            0                      /*!< Remaining space for channels FIFO for read data */
#define DMA_CH_FIFOSTAT_WR_FULLNESS_Pos       16                     /*!< Occupied space in channels FIFO by write data */

/* Bit field masks: */
#define DMA_CH_FIFOSTAT_RD_GAP_Msk            0x0000003FUL           /*!< Remaining space for channels FIFO for read data */
#define DMA_CH_FIFOSTAT_WR_FULLNESS_Msk       0x003F0000UL           /*!< Occupied space in channels FIFO by write data */

/*-- CH: CMD_OUTS: Outstanding commands status register -------------------------------------------------------*/
typedef struct {
  uint32_t RD_CMD_OUTS            :4;                                /*!< Number of channels pending AXI read commands */
  uint32_t                        :4;                                /*!< RESERVED */
  uint32_t WR_CMD_OUTS            :4;                                /*!< Number of channels pending AXI write commands */
} _DMA_CH_CMD_OUTS_bits;

/* Bit field positions: */
#define DMA_CH_CMD_OUTS_RD_CMD_OUTS_Pos       0                      /*!< Number of channels pending AXI read commands */
#define DMA_CH_CMD_OUTS_WR_CMD_OUTS_Pos       8                      /*!< Number of channels pending AXI write commands */

/* Bit field masks: */
#define DMA_CH_CMD_OUTS_RD_CMD_OUTS_Msk       0x0000000FUL           /*!< Number of channels pending AXI read commands */
#define DMA_CH_CMD_OUTS_WR_CMD_OUTS_Msk       0x00000F00UL           /*!< Number of channels pending AXI write commands */

/*-- CH: CH_ACTIVE: Channel active register -------------------------------------------------------------------*/
typedef struct {
  uint32_t CH_ACTIVE              :1;                                /*!< Channel is currently active */
} _DMA_CH_CH_ACTIVE_bits;

/* Bit field positions: */
#define DMA_CH_CH_ACTIVE_CH_ACTIVE_Pos        0                      /*!< Channel is currently active */

/* Bit field masks: */
#define DMA_CH_CH_ACTIVE_CH_ACTIVE_Msk        0x00000001UL           /*!< Channel is currently active */

/*-- CH: CH_START: Channel start register ---------------------------------------------------------------------*/
typedef struct {
  uint32_t CH_START               :1;                                /*!< Start channel */
} _DMA_CH_CH_START_bits;

/* Bit field positions: */
#define DMA_CH_CH_START_CH_START_Pos          0                      /*!< Start channel */

/* Bit field masks: */
#define DMA_CH_CH_START_CH_START_Msk          0x00000001UL           /*!< Start channel */

/*-- CH: CH_STATUS: Channel status register -------------------------------------------------------------------*/
typedef struct {
  uint32_t CH_RD_ACTIVE           :1;                                /*!< Read on AXI bus is performed */
  uint32_t CH_WR_ACTIVE           :1;                                /*!< Write on AXI bus is performed */
} _DMA_CH_CH_STATUS_bits;

/* Bit field positions: */
#define DMA_CH_CH_STATUS_CH_RD_ACTIVE_Pos       0                    /*!< Read on AXI bus is performed */
#define DMA_CH_CH_STATUS_CH_WR_ACTIVE_Pos       1                    /*!< Write on AXI bus is performed */

/* Bit field masks: */
#define DMA_CH_CH_STATUS_CH_RD_ACTIVE_Msk       0x00000001UL         /*!< Read on AXI bus is performed */
#define DMA_CH_CH_STATUS_CH_WR_ACTIVE_Msk       0x00000002UL         /*!< Write on AXI bus is performed */

/*-- CH: COUNT: Buffer counter status register ----------------------------------------------------------------*/
typedef struct {
  uint32_t BUFF_COUNT             :12;                               /*!< Number of buffers transferred by channel since started */
  uint32_t                        :4;                                /*!< RESERVED */
  uint32_t INT_COUNT              :5;                                /*!< Number of unserviced end interrupts */
} _DMA_CH_COUNT_bits;

/* Bit field positions: */
#define DMA_CH_COUNT_BUFF_COUNT_Pos           0                      /*!< Number of buffers transferred by channel since started */
#define DMA_CH_COUNT_INT_COUNT_Pos            16                     /*!< Number of unserviced end interrupts */

/* Bit field masks: */
#define DMA_CH_COUNT_BUFF_COUNT_Msk           0x00000FFFUL           /*!< Number of buffers transferred by channel since started */
#define DMA_CH_COUNT_INT_COUNT_Msk            0x001F0000UL           /*!< Number of unserviced end interrupts */

/*-- CH: INT_RAWSTAT: Interrupt raw status register -----------------------------------------------------------*/
typedef struct {
  uint32_t CH_END                 :1;                                /*!< Channel end interrupt */
  uint32_t RD_SLVERR              :1;                                /*!< A read issued by this channel caused an AXI read slave decode error */
  uint32_t WR_SLVERR              :1;                                /*!< A write issued by this channel caused an AXI write slave decode error */
  uint32_t RD_DECERR              :1;                                /*!< A read issued by this channel caused an AXI read decode error */
  uint32_t WR_DECERR              :1;                                /*!< A write issued by this channel caused an AXI write decode error */
  uint32_t OVERFLOW               :1;                                /*!< Data FIFO has been overflowed */
  uint32_t UNDERFLOW              :1;                                /*!< Data FIFO has been underflowed */
  uint32_t TIMEOUT_R              :1;                                /*!< A read issued by this channel caused a timeout on AXI read data bus */
  uint32_t TIMEOUT_AR             :1;                                /*!< A read issued by this channel caused a timeout on AXI read command  bus */
  uint32_t TIMEOUT_B              :1;                                /*!< A write issued by this channel caused a timeout on AXI write response bus */
  uint32_t TIMEOUT_W              :1;                                /*!< A write issued by this channel caused a timeout on AXI write data bus */
  uint32_t TIMEOUT_AW             :1;                                /*!< A write issued by this channel caused a timeout on AXI write command bus */
  uint32_t WDT_TIMEOUT            :1;                                /*!< Channel is active but did not start a burst for 2048 cycles */
} _DMA_CH_INT_RAWSTAT_bits;

/* Bit field positions: */
#define DMA_CH_INT_RAWSTAT_CH_END_Pos         0                      /*!< Channel end interrupt */
#define DMA_CH_INT_RAWSTAT_RD_SLVERR_Pos       1                     /*!< A read issued by this channel caused an AXI read slave decode error */
#define DMA_CH_INT_RAWSTAT_WR_SLVERR_Pos       2                     /*!< A write issued by this channel caused an AXI write slave decode error */
#define DMA_CH_INT_RAWSTAT_RD_DECERR_Pos       3                     /*!< A read issued by this channel caused an AXI read decode error */
#define DMA_CH_INT_RAWSTAT_WR_DECERR_Pos       4                     /*!< A write issued by this channel caused an AXI write decode error */
#define DMA_CH_INT_RAWSTAT_OVERFLOW_Pos       5                      /*!< Data FIFO has been overflowed */
#define DMA_CH_INT_RAWSTAT_UNDERFLOW_Pos       6                     /*!< Data FIFO has been underflowed */
#define DMA_CH_INT_RAWSTAT_TIMEOUT_R_Pos       7                     /*!< A read issued by this channel caused a timeout on AXI read data bus */
#define DMA_CH_INT_RAWSTAT_TIMEOUT_AR_Pos       8                    /*!< A read issued by this channel caused a timeout on AXI read command  bus */
#define DMA_CH_INT_RAWSTAT_TIMEOUT_B_Pos       9                     /*!< A write issued by this channel caused a timeout on AXI write response bus */
#define DMA_CH_INT_RAWSTAT_TIMEOUT_W_Pos       10                    /*!< A write issued by this channel caused a timeout on AXI write data bus */
#define DMA_CH_INT_RAWSTAT_TIMEOUT_AW_Pos       11                   /*!< A write issued by this channel caused a timeout on AXI write command bus */
#define DMA_CH_INT_RAWSTAT_WDT_TIMEOUT_Pos       12                  /*!< Channel is active but did not start a burst for 2048 cycles */

/* Bit field masks: */
#define DMA_CH_INT_RAWSTAT_CH_END_Msk         0x00000001UL           /*!< Channel end interrupt */
#define DMA_CH_INT_RAWSTAT_RD_SLVERR_Msk       0x00000002UL          /*!< A read issued by this channel caused an AXI read slave decode error */
#define DMA_CH_INT_RAWSTAT_WR_SLVERR_Msk       0x00000004UL          /*!< A write issued by this channel caused an AXI write slave decode error */
#define DMA_CH_INT_RAWSTAT_RD_DECERR_Msk       0x00000008UL          /*!< A read issued by this channel caused an AXI read decode error */
#define DMA_CH_INT_RAWSTAT_WR_DECERR_Msk       0x00000010UL          /*!< A write issued by this channel caused an AXI write decode error */
#define DMA_CH_INT_RAWSTAT_OVERFLOW_Msk       0x00000020UL           /*!< Data FIFO has been overflowed */
#define DMA_CH_INT_RAWSTAT_UNDERFLOW_Msk       0x00000040UL          /*!< Data FIFO has been underflowed */
#define DMA_CH_INT_RAWSTAT_TIMEOUT_R_Msk       0x00000080UL          /*!< A read issued by this channel caused a timeout on AXI read data bus */
#define DMA_CH_INT_RAWSTAT_TIMEOUT_AR_Msk       0x00000100UL         /*!< A read issued by this channel caused a timeout on AXI read command  bus */
#define DMA_CH_INT_RAWSTAT_TIMEOUT_B_Msk       0x00000200UL          /*!< A write issued by this channel caused a timeout on AXI write response bus */
#define DMA_CH_INT_RAWSTAT_TIMEOUT_W_Msk       0x00000400UL          /*!< A write issued by this channel caused a timeout on AXI write data bus */
#define DMA_CH_INT_RAWSTAT_TIMEOUT_AW_Msk       0x00000800UL         /*!< A write issued by this channel caused a timeout on AXI write command bus */
#define DMA_CH_INT_RAWSTAT_WDT_TIMEOUT_Msk       0x00001000UL         /*!< Channel is active but did not start a burst for 2048 cycles */

/*-- CH: INT_CLEAR: Interrupt clear register ------------------------------------------------------------------*/
typedef struct {
  uint32_t CH_END                 :1;                                /*!< Channel end interrupt */
  uint32_t RD_SLVERR              :1;                                /*!< A read issued by this channel caused an AXI read slave decode error */
  uint32_t WR_SLVERR              :1;                                /*!< A write issued by this channel caused an AXI write slave decode error */
  uint32_t RD_DECERR              :1;                                /*!< A read issued by this channel caused an AXI read decode error */
  uint32_t WR_DECERR              :1;                                /*!< A write issued by this channel caused an AXI write decode error */
  uint32_t OVERFLOW               :1;                                /*!< Data FIFO has been overflowed */
  uint32_t UNDERFLOW              :1;                                /*!< Data FIFO has been underflowed */
  uint32_t TIMEOUT_R              :1;                                /*!< A read issued by this channel caused a timeout on AXI read data bus */
  uint32_t TIMEOUT_AR             :1;                                /*!< A read issued by this channel caused a timeout on AXI read command  bus */
  uint32_t TIMEOUT_B              :1;                                /*!< A write issued by this channel caused a timeout on AXI write response bus */
  uint32_t TIMEOUT_W              :1;                                /*!< A write issued by this channel caused a timeout on AXI write data bus */
  uint32_t TIMEOUT_AW             :1;                                /*!< A write issued by this channel caused a timeout on AXI write command bus */
  uint32_t WDT_TIMEOUT            :1;                                /*!< Channel is active but did not start a burst for 2048 cycles */
} _DMA_CH_INT_CLEAR_bits;

/* Bit field positions: */
#define DMA_CH_INT_CLEAR_CH_END_Pos           0                      /*!< Channel end interrupt */
#define DMA_CH_INT_CLEAR_RD_SLVERR_Pos        1                      /*!< A read issued by this channel caused an AXI read slave decode error */
#define DMA_CH_INT_CLEAR_WR_SLVERR_Pos        2                      /*!< A write issued by this channel caused an AXI write slave decode error */
#define DMA_CH_INT_CLEAR_RD_DECERR_Pos        3                      /*!< A read issued by this channel caused an AXI read decode error */
#define DMA_CH_INT_CLEAR_WR_DECERR_Pos        4                      /*!< A write issued by this channel caused an AXI write decode error */
#define DMA_CH_INT_CLEAR_OVERFLOW_Pos         5                      /*!< Data FIFO has been overflowed */
#define DMA_CH_INT_CLEAR_UNDERFLOW_Pos        6                      /*!< Data FIFO has been underflowed */
#define DMA_CH_INT_CLEAR_TIMEOUT_R_Pos        7                      /*!< A read issued by this channel caused a timeout on AXI read data bus */
#define DMA_CH_INT_CLEAR_TIMEOUT_AR_Pos       8                      /*!< A read issued by this channel caused a timeout on AXI read command  bus */
#define DMA_CH_INT_CLEAR_TIMEOUT_B_Pos        9                      /*!< A write issued by this channel caused a timeout on AXI write response bus */
#define DMA_CH_INT_CLEAR_TIMEOUT_W_Pos        10                     /*!< A write issued by this channel caused a timeout on AXI write data bus */
#define DMA_CH_INT_CLEAR_TIMEOUT_AW_Pos       11                     /*!< A write issued by this channel caused a timeout on AXI write command bus */
#define DMA_CH_INT_CLEAR_WDT_TIMEOUT_Pos       12                    /*!< Channel is active but did not start a burst for 2048 cycles */

/* Bit field masks: */
#define DMA_CH_INT_CLEAR_CH_END_Msk           0x00000001UL           /*!< Channel end interrupt */
#define DMA_CH_INT_CLEAR_RD_SLVERR_Msk        0x00000002UL           /*!< A read issued by this channel caused an AXI read slave decode error */
#define DMA_CH_INT_CLEAR_WR_SLVERR_Msk        0x00000004UL           /*!< A write issued by this channel caused an AXI write slave decode error */
#define DMA_CH_INT_CLEAR_RD_DECERR_Msk        0x00000008UL           /*!< A read issued by this channel caused an AXI read decode error */
#define DMA_CH_INT_CLEAR_WR_DECERR_Msk        0x00000010UL           /*!< A write issued by this channel caused an AXI write decode error */
#define DMA_CH_INT_CLEAR_OVERFLOW_Msk         0x00000020UL           /*!< Data FIFO has been overflowed */
#define DMA_CH_INT_CLEAR_UNDERFLOW_Msk        0x00000040UL           /*!< Data FIFO has been underflowed */
#define DMA_CH_INT_CLEAR_TIMEOUT_R_Msk        0x00000080UL           /*!< A read issued by this channel caused a timeout on AXI read data bus */
#define DMA_CH_INT_CLEAR_TIMEOUT_AR_Msk       0x00000100UL           /*!< A read issued by this channel caused a timeout on AXI read command  bus */
#define DMA_CH_INT_CLEAR_TIMEOUT_B_Msk        0x00000200UL           /*!< A write issued by this channel caused a timeout on AXI write response bus */
#define DMA_CH_INT_CLEAR_TIMEOUT_W_Msk        0x00000400UL           /*!< A write issued by this channel caused a timeout on AXI write data bus */
#define DMA_CH_INT_CLEAR_TIMEOUT_AW_Msk       0x00000800UL           /*!< A write issued by this channel caused a timeout on AXI write command bus */
#define DMA_CH_INT_CLEAR_WDT_TIMEOUT_Msk       0x00001000UL          /*!< Channel is active but did not start a burst for 2048 cycles */

/*-- CH: INT_ENABLE: Interrupt enable register ----------------------------------------------------------------*/
typedef struct {
  uint32_t CH_END                 :1;                                /*!< Channel end interrupt */
  uint32_t RD_SLVERR              :1;                                /*!< A read issued by this channel caused an AXI read slave decode error */
  uint32_t WR_SLVERR              :1;                                /*!< A write issued by this channel caused an AXI write slave decode error */
  uint32_t RD_DECERR              :1;                                /*!< A read issued by this channel caused an AXI read decode error */
  uint32_t WR_DECERR              :1;                                /*!< A write issued by this channel caused an AXI write decode error */
  uint32_t OVERFLOW               :1;                                /*!< Data FIFO has been overflowed */
  uint32_t UNDERFLOW              :1;                                /*!< Data FIFO has been underflowed */
  uint32_t TIMEOUT_R              :1;                                /*!< A read issued by this channel caused a timeout on AXI read data bus */
  uint32_t TIMEOUT_AR             :1;                                /*!< A read issued by this channel caused a timeout on AXI read command  bus */
  uint32_t TIMEOUT_B              :1;                                /*!< A write issued by this channel caused a timeout on AXI write response bus */
  uint32_t TIMEOUT_W              :1;                                /*!< A write issued by this channel caused a timeout on AXI write data bus */
  uint32_t TIMEOUT_AW             :1;                                /*!< A write issued by this channel caused a timeout on AXI write command bus */
  uint32_t WDT_TIMEOUT            :1;                                /*!< Channel is active but did not start a burst for 2048 cycles */
} _DMA_CH_INT_ENABLE_bits;

/* Bit field positions: */
#define DMA_CH_INT_ENABLE_CH_END_Pos          0                      /*!< Channel end interrupt */
#define DMA_CH_INT_ENABLE_RD_SLVERR_Pos       1                      /*!< A read issued by this channel caused an AXI read slave decode error */
#define DMA_CH_INT_ENABLE_WR_SLVERR_Pos       2                      /*!< A write issued by this channel caused an AXI write slave decode error */
#define DMA_CH_INT_ENABLE_RD_DECERR_Pos       3                      /*!< A read issued by this channel caused an AXI read decode error */
#define DMA_CH_INT_ENABLE_WR_DECERR_Pos       4                      /*!< A write issued by this channel caused an AXI write decode error */
#define DMA_CH_INT_ENABLE_OVERFLOW_Pos        5                      /*!< Data FIFO has been overflowed */
#define DMA_CH_INT_ENABLE_UNDERFLOW_Pos       6                      /*!< Data FIFO has been underflowed */
#define DMA_CH_INT_ENABLE_TIMEOUT_R_Pos       7                      /*!< A read issued by this channel caused a timeout on AXI read data bus */
#define DMA_CH_INT_ENABLE_TIMEOUT_AR_Pos       8                     /*!< A read issued by this channel caused a timeout on AXI read command  bus */
#define DMA_CH_INT_ENABLE_TIMEOUT_B_Pos       9                      /*!< A write issued by this channel caused a timeout on AXI write response bus */
#define DMA_CH_INT_ENABLE_TIMEOUT_W_Pos       10                     /*!< A write issued by this channel caused a timeout on AXI write data bus */
#define DMA_CH_INT_ENABLE_TIMEOUT_AW_Pos       11                    /*!< A write issued by this channel caused a timeout on AXI write command bus */
#define DMA_CH_INT_ENABLE_WDT_TIMEOUT_Pos       12                   /*!< Channel is active but did not start a burst for 2048 cycles */

/* Bit field masks: */
#define DMA_CH_INT_ENABLE_CH_END_Msk          0x00000001UL           /*!< Channel end interrupt */
#define DMA_CH_INT_ENABLE_RD_SLVERR_Msk       0x00000002UL           /*!< A read issued by this channel caused an AXI read slave decode error */
#define DMA_CH_INT_ENABLE_WR_SLVERR_Msk       0x00000004UL           /*!< A write issued by this channel caused an AXI write slave decode error */
#define DMA_CH_INT_ENABLE_RD_DECERR_Msk       0x00000008UL           /*!< A read issued by this channel caused an AXI read decode error */
#define DMA_CH_INT_ENABLE_WR_DECERR_Msk       0x00000010UL           /*!< A write issued by this channel caused an AXI write decode error */
#define DMA_CH_INT_ENABLE_OVERFLOW_Msk        0x00000020UL           /*!< Data FIFO has been overflowed */
#define DMA_CH_INT_ENABLE_UNDERFLOW_Msk       0x00000040UL           /*!< Data FIFO has been underflowed */
#define DMA_CH_INT_ENABLE_TIMEOUT_R_Msk       0x00000080UL           /*!< A read issued by this channel caused a timeout on AXI read data bus */
#define DMA_CH_INT_ENABLE_TIMEOUT_AR_Msk       0x00000100UL          /*!< A read issued by this channel caused a timeout on AXI read command  bus */
#define DMA_CH_INT_ENABLE_TIMEOUT_B_Msk       0x00000200UL           /*!< A write issued by this channel caused a timeout on AXI write response bus */
#define DMA_CH_INT_ENABLE_TIMEOUT_W_Msk       0x00000400UL           /*!< A write issued by this channel caused a timeout on AXI write data bus */
#define DMA_CH_INT_ENABLE_TIMEOUT_AW_Msk       0x00000800UL          /*!< A write issued by this channel caused a timeout on AXI write command bus */
#define DMA_CH_INT_ENABLE_WDT_TIMEOUT_Msk       0x00001000UL         /*!< Channel is active but did not start a burst for 2048 cycles */

/*-- CH: INT_STATUS: Interrupt status -------------------------------------------------------------------------*/
typedef struct {
  uint32_t CH_END                 :1;                                /*!< Channel end interrupt */
  uint32_t RD_SLVERR              :1;                                /*!< A read issued by this channel caused an AXI read slave decode error */
  uint32_t WR_SLVERR              :1;                                /*!< A write issued by this channel caused an AXI write slave decode error */
  uint32_t RD_DECERR              :1;                                /*!< A read issued by this channel caused an AXI read decode error */
  uint32_t WR_DECERR              :1;                                /*!< A write issued by this channel caused an AXI write decode error */
  uint32_t OVERFLOW               :1;                                /*!< Data FIFO has been overflowed */
  uint32_t UNDERFLOW              :1;                                /*!< Data FIFO has been underflowed */
  uint32_t TIMEOUT_R              :1;                                /*!< A read issued by this channel caused a timeout on AXI read data bus */
  uint32_t TIMEOUT_AR             :1;                                /*!< A read issued by this channel caused a timeout on AXI read command  bus */
  uint32_t TIMEOUT_B              :1;                                /*!< A write issued by this channel caused a timeout on AXI write response bus */
  uint32_t TIMEOUT_W              :1;                                /*!< A write issued by this channel caused a timeout on AXI write data bus */
  uint32_t TIMEOUT_AW             :1;                                /*!< A write issued by this channel caused a timeout on AXI write command bus */
  uint32_t WDT_TIMEOUT            :1;                                /*!< Channel is active but did not start a burst for 2048 cycles */
} _DMA_CH_INT_STATUS_bits;

/* Bit field positions: */
#define DMA_CH_INT_STATUS_CH_END_Pos          0                      /*!< Channel end interrupt */
#define DMA_CH_INT_STATUS_RD_SLVERR_Pos       1                      /*!< A read issued by this channel caused an AXI read slave decode error */
#define DMA_CH_INT_STATUS_WR_SLVERR_Pos       2                      /*!< A write issued by this channel caused an AXI write slave decode error */
#define DMA_CH_INT_STATUS_RD_DECERR_Pos       3                      /*!< A read issued by this channel caused an AXI read decode error */
#define DMA_CH_INT_STATUS_WR_DECERR_Pos       4                      /*!< A write issued by this channel caused an AXI write decode error */
#define DMA_CH_INT_STATUS_OVERFLOW_Pos        5                      /*!< Data FIFO has been overflowed */
#define DMA_CH_INT_STATUS_UNDERFLOW_Pos       6                      /*!< Data FIFO has been underflowed */
#define DMA_CH_INT_STATUS_TIMEOUT_R_Pos       7                      /*!< A read issued by this channel caused a timeout on AXI read data bus */
#define DMA_CH_INT_STATUS_TIMEOUT_AR_Pos       8                     /*!< A read issued by this channel caused a timeout on AXI read command  bus */
#define DMA_CH_INT_STATUS_TIMEOUT_B_Pos       9                      /*!< A write issued by this channel caused a timeout on AXI write response bus */
#define DMA_CH_INT_STATUS_TIMEOUT_W_Pos       10                     /*!< A write issued by this channel caused a timeout on AXI write data bus */
#define DMA_CH_INT_STATUS_TIMEOUT_AW_Pos       11                    /*!< A write issued by this channel caused a timeout on AXI write command bus */
#define DMA_CH_INT_STATUS_WDT_TIMEOUT_Pos       12                   /*!< Channel is active but did not start a burst for 2048 cycles */

/* Bit field masks: */
#define DMA_CH_INT_STATUS_CH_END_Msk          0x00000001UL           /*!< Channel end interrupt */
#define DMA_CH_INT_STATUS_RD_SLVERR_Msk       0x00000002UL           /*!< A read issued by this channel caused an AXI read slave decode error */
#define DMA_CH_INT_STATUS_WR_SLVERR_Msk       0x00000004UL           /*!< A write issued by this channel caused an AXI write slave decode error */
#define DMA_CH_INT_STATUS_RD_DECERR_Msk       0x00000008UL           /*!< A read issued by this channel caused an AXI read decode error */
#define DMA_CH_INT_STATUS_WR_DECERR_Msk       0x00000010UL           /*!< A write issued by this channel caused an AXI write decode error */
#define DMA_CH_INT_STATUS_OVERFLOW_Msk        0x00000020UL           /*!< Data FIFO has been overflowed */
#define DMA_CH_INT_STATUS_UNDERFLOW_Msk       0x00000040UL           /*!< Data FIFO has been underflowed */
#define DMA_CH_INT_STATUS_TIMEOUT_R_Msk       0x00000080UL           /*!< A read issued by this channel caused a timeout on AXI read data bus */
#define DMA_CH_INT_STATUS_TIMEOUT_AR_Msk       0x00000100UL          /*!< A read issued by this channel caused a timeout on AXI read command  bus */
#define DMA_CH_INT_STATUS_TIMEOUT_B_Msk       0x00000200UL           /*!< A write issued by this channel caused a timeout on AXI write response bus */
#define DMA_CH_INT_STATUS_TIMEOUT_W_Msk       0x00000400UL           /*!< A write issued by this channel caused a timeout on AXI write data bus */
#define DMA_CH_INT_STATUS_TIMEOUT_AW_Msk       0x00000800UL          /*!< A write issued by this channel caused a timeout on AXI write command bus */
#define DMA_CH_INT_STATUS_WDT_TIMEOUT_Msk       0x00001000UL         /*!< Channel is active but did not start a burst for 2048 cycles */

/*-- CH: ERR_STOP: Channel error stop condition register ------------------------------------------------------*/
typedef struct {
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t RD_SLVERR              :1;                                /*!< If set, stop read and write transactions when this condition occurs */
  uint32_t WR_SLVERR              :1;                                /*!< If set, stop read and write transactions when this condition occurs */
  uint32_t RD_DECERR              :1;                                /*!< If set, stop read and write transactions when this condition occurs */
  uint32_t WR_DECERR              :1;                                /*!< If set, stop read and write transactions when this condition occurs */
  uint32_t OVERFLOW               :1;                                /*!< If set, stop read and write transactions when this condition occurs */
  uint32_t UNDERFLOW              :1;                                /*!< If set, stop read and write transactions when this condition occurs */
  uint32_t TIMEOUT_R              :1;                                /*!< If set, stop read and write transactions when this condition occurs */
  uint32_t TIMEOUT_AR             :1;                                /*!< If set, stop read and write transactions when this condition occurs */
  uint32_t TIMEOUT_B              :1;                                /*!< If set, stop read and write transactions when this condition occurs */
  uint32_t TIMEOUT_W              :1;                                /*!< If set, stop read and write transactions when this condition occurs */
  uint32_t TIMEOUT_AW             :1;                                /*!< If set, stop read and write transactions when this condition occurs */
  uint32_t WDT_TIMEOUT            :1;                                /*!< If set, stop read and write transactions when this condition occurs */
} _DMA_CH_ERR_STOP_bits;

/* Bit field positions: */
#define DMA_CH_ERR_STOP_RD_SLVERR_Pos         1                      /*!< If set, stop read and write transactions when this condition occurs */
#define DMA_CH_ERR_STOP_WR_SLVERR_Pos         2                      /*!< If set, stop read and write transactions when this condition occurs */
#define DMA_CH_ERR_STOP_RD_DECERR_Pos         3                      /*!< If set, stop read and write transactions when this condition occurs */
#define DMA_CH_ERR_STOP_WR_DECERR_Pos         4                      /*!< If set, stop read and write transactions when this condition occurs */
#define DMA_CH_ERR_STOP_OVERFLOW_Pos          5                      /*!< If set, stop read and write transactions when this condition occurs */
#define DMA_CH_ERR_STOP_UNDERFLOW_Pos         6                      /*!< If set, stop read and write transactions when this condition occurs */
#define DMA_CH_ERR_STOP_TIMEOUT_R_Pos         7                      /*!< If set, stop read and write transactions when this condition occurs */
#define DMA_CH_ERR_STOP_TIMEOUT_AR_Pos        8                      /*!< If set, stop read and write transactions when this condition occurs */
#define DMA_CH_ERR_STOP_TIMEOUT_B_Pos         9                      /*!< If set, stop read and write transactions when this condition occurs */
#define DMA_CH_ERR_STOP_TIMEOUT_W_Pos         10                     /*!< If set, stop read and write transactions when this condition occurs */
#define DMA_CH_ERR_STOP_TIMEOUT_AW_Pos        11                     /*!< If set, stop read and write transactions when this condition occurs */
#define DMA_CH_ERR_STOP_WDT_TIMEOUT_Pos       12                     /*!< If set, stop read and write transactions when this condition occurs */

/* Bit field masks: */
#define DMA_CH_ERR_STOP_RD_SLVERR_Msk         0x00000002UL           /*!< If set, stop read and write transactions when this condition occurs */
#define DMA_CH_ERR_STOP_WR_SLVERR_Msk         0x00000004UL           /*!< If set, stop read and write transactions when this condition occurs */
#define DMA_CH_ERR_STOP_RD_DECERR_Msk         0x00000008UL           /*!< If set, stop read and write transactions when this condition occurs */
#define DMA_CH_ERR_STOP_WR_DECERR_Msk         0x00000010UL           /*!< If set, stop read and write transactions when this condition occurs */
#define DMA_CH_ERR_STOP_OVERFLOW_Msk          0x00000020UL           /*!< If set, stop read and write transactions when this condition occurs */
#define DMA_CH_ERR_STOP_UNDERFLOW_Msk         0x00000040UL           /*!< If set, stop read and write transactions when this condition occurs */
#define DMA_CH_ERR_STOP_TIMEOUT_R_Msk         0x00000080UL           /*!< If set, stop read and write transactions when this condition occurs */
#define DMA_CH_ERR_STOP_TIMEOUT_AR_Msk        0x00000100UL           /*!< If set, stop read and write transactions when this condition occurs */
#define DMA_CH_ERR_STOP_TIMEOUT_B_Msk         0x00000200UL           /*!< If set, stop read and write transactions when this condition occurs */
#define DMA_CH_ERR_STOP_TIMEOUT_W_Msk         0x00000400UL           /*!< If set, stop read and write transactions when this condition occurs */
#define DMA_CH_ERR_STOP_TIMEOUT_AW_Msk        0x00000800UL           /*!< If set, stop read and write transactions when this condition occurs */
#define DMA_CH_ERR_STOP_WDT_TIMEOUT_Msk       0x00001000UL           /*!< If set, stop read and write transactions when this condition occurs */

/*-- CH: ERR_RD_ADDR: Erroneous read transaction address register ---------------------------------------------*/
typedef struct {
  uint32_t ERR_ADDR               :32;                               /*!< First encountered erroneous address in read transaction */
} _DMA_CH_ERR_RD_ADDR_bits;

/* Bit field positions: */
#define DMA_CH_ERR_RD_ADDR_ERR_ADDR_Pos       0                      /*!< First encountered erroneous address in read transaction */

/* Bit field masks: */
#define DMA_CH_ERR_RD_ADDR_ERR_ADDR_Msk       0xFFFFFFFFUL           /*!< First encountered erroneous address in read transaction */

/*-- CH: ERR_WR_ADDR: Erroneous write transaction address register --------------------------------------------*/
typedef struct {
  uint32_t ERR_ADDR               :32;                               /*!< First encountered erroneous address in write transaction */
} _DMA_CH_ERR_WR_ADDR_bits;

/* Bit field positions: */
#define DMA_CH_ERR_WR_ADDR_ERR_ADDR_Pos       0                      /*!< First encountered erroneous address in write transaction */

/* Bit field masks: */
#define DMA_CH_ERR_WR_ADDR_ERR_ADDR_Msk       0xFFFFFFFFUL           /*!< First encountered erroneous address in write transaction */

/*--  CH_INTSTAT: DMA Core Interrupt status register ----------------------------------------------------------*/
typedef struct {
  uint32_t CH0                    :1;                                /*!< Interrupt caused by Channel 0 */
  uint32_t CH1                    :1;                                /*!< Interrupt caused by Channel 1 */
  uint32_t CH2                    :1;                                /*!< Interrupt caused by Channel 2 */
  uint32_t CH3                    :1;                                /*!< Interrupt caused by Channel 3 */
  uint32_t CH4                    :1;                                /*!< Interrupt caused by Channel 4 */
  uint32_t CH5                    :1;                                /*!< Interrupt caused by Channel 5 */
  uint32_t CH6                    :1;                                /*!< Interrupt caused by Channel 6 */
  uint32_t CH7                    :1;                                /*!< Interrupt caused by Channel 7 */
  uint32_t CH8                    :1;                                /*!< Interrupt caused by Channel 8 */
  uint32_t CH9                    :1;                                /*!< Interrupt caused by Channel 9 */
  uint32_t CH10                   :1;                                /*!< Interrupt caused by Channel 10 */
  uint32_t CH11                   :1;                                /*!< Interrupt caused by Channel 11 */
  uint32_t CH12                   :1;                                /*!< Interrupt caused by Channel 12 */
  uint32_t CH13                   :1;                                /*!< Interrupt caused by Channel 13 */
  uint32_t CH14                   :1;                                /*!< Interrupt caused by Channel 14 */
  uint32_t CH15                   :1;                                /*!< Interrupt caused by Channel 15 */
} _DMA_CH_INTSTAT_bits;

/* Bit field positions: */
#define DMA_CH_INTSTAT_CH0_Pos                0                      /*!< Interrupt caused by Channel 0 */
#define DMA_CH_INTSTAT_CH1_Pos                1                      /*!< Interrupt caused by Channel 1 */
#define DMA_CH_INTSTAT_CH2_Pos                2                      /*!< Interrupt caused by Channel 2 */
#define DMA_CH_INTSTAT_CH3_Pos                3                      /*!< Interrupt caused by Channel 3 */
#define DMA_CH_INTSTAT_CH4_Pos                4                      /*!< Interrupt caused by Channel 4 */
#define DMA_CH_INTSTAT_CH5_Pos                5                      /*!< Interrupt caused by Channel 5 */
#define DMA_CH_INTSTAT_CH6_Pos                6                      /*!< Interrupt caused by Channel 6 */
#define DMA_CH_INTSTAT_CH7_Pos                7                      /*!< Interrupt caused by Channel 7 */
#define DMA_CH_INTSTAT_CH8_Pos                8                      /*!< Interrupt caused by Channel 8 */
#define DMA_CH_INTSTAT_CH9_Pos                9                      /*!< Interrupt caused by Channel 9 */
#define DMA_CH_INTSTAT_CH10_Pos               10                     /*!< Interrupt caused by Channel 10 */
#define DMA_CH_INTSTAT_CH11_Pos               11                     /*!< Interrupt caused by Channel 11 */
#define DMA_CH_INTSTAT_CH12_Pos               12                     /*!< Interrupt caused by Channel 12 */
#define DMA_CH_INTSTAT_CH13_Pos               13                     /*!< Interrupt caused by Channel 13 */
#define DMA_CH_INTSTAT_CH14_Pos               14                     /*!< Interrupt caused by Channel 14 */
#define DMA_CH_INTSTAT_CH15_Pos               15                     /*!< Interrupt caused by Channel 15 */

/* Bit field masks: */
#define DMA_CH_INTSTAT_CH0_Msk                0x00000001UL           /*!< Interrupt caused by Channel 0 */
#define DMA_CH_INTSTAT_CH1_Msk                0x00000002UL           /*!< Interrupt caused by Channel 1 */
#define DMA_CH_INTSTAT_CH2_Msk                0x00000004UL           /*!< Interrupt caused by Channel 2 */
#define DMA_CH_INTSTAT_CH3_Msk                0x00000008UL           /*!< Interrupt caused by Channel 3 */
#define DMA_CH_INTSTAT_CH4_Msk                0x00000010UL           /*!< Interrupt caused by Channel 4 */
#define DMA_CH_INTSTAT_CH5_Msk                0x00000020UL           /*!< Interrupt caused by Channel 5 */
#define DMA_CH_INTSTAT_CH6_Msk                0x00000040UL           /*!< Interrupt caused by Channel 6 */
#define DMA_CH_INTSTAT_CH7_Msk                0x00000080UL           /*!< Interrupt caused by Channel 7 */
#define DMA_CH_INTSTAT_CH8_Msk                0x00000100UL           /*!< Interrupt caused by Channel 8 */
#define DMA_CH_INTSTAT_CH9_Msk                0x00000200UL           /*!< Interrupt caused by Channel 9 */
#define DMA_CH_INTSTAT_CH10_Msk               0x00000400UL           /*!< Interrupt caused by Channel 10 */
#define DMA_CH_INTSTAT_CH11_Msk               0x00000800UL           /*!< Interrupt caused by Channel 11 */
#define DMA_CH_INTSTAT_CH12_Msk               0x00001000UL           /*!< Interrupt caused by Channel 12 */
#define DMA_CH_INTSTAT_CH13_Msk               0x00002000UL           /*!< Interrupt caused by Channel 13 */
#define DMA_CH_INTSTAT_CH14_Msk               0x00004000UL           /*!< Interrupt caused by Channel 14 */
#define DMA_CH_INTSTAT_CH15_Msk               0x00008000UL           /*!< Interrupt caused by Channel 15 */

/*--  CONTROL: DMA Core Control register ----------------------------------------------------------------------*/
typedef struct {
  uint32_t JOINT_MODE             :1;                                /*!< Joint mode select */
} _DMA_CONTROL_bits;

/* Bit field positions: */
#define DMA_CONTROL_JOINT_MODE_Pos            0                      /*!< Joint mode select */

/* Bit field masks: */
#define DMA_CONTROL_JOINT_MODE_Msk            0x00000001UL           /*!< Joint mode select */

/*--  RD_PRIORITY: DMA Core read priority channels ------------------------------------------------------------*/
typedef struct {
  uint32_t CH0                    :1;                                /*!< Set the priority of channel 0 */
  uint32_t CH1                    :1;                                /*!< Set the priority of channel 1 */
  uint32_t CH2                    :1;                                /*!< Set the priority of channel 2 */
  uint32_t CH3                    :1;                                /*!< Set the priority of channel 3 */
  uint32_t CH4                    :1;                                /*!< Set the priority of channel 4 */
  uint32_t CH5                    :1;                                /*!< Set the priority of channel 5 */
  uint32_t CH6                    :1;                                /*!< Set the priority of channel 6 */
  uint32_t CH7                    :1;                                /*!< Set the priority of channel 7 */
  uint32_t CH8                    :1;                                /*!< Set the priority of channel 8 */
  uint32_t CH9                    :1;                                /*!< Set the priority of channel 9 */
  uint32_t CH10                   :1;                                /*!< Set the priority of channel 10 */
  uint32_t CH11                   :1;                                /*!< Set the priority of channel 11 */
  uint32_t CH12                   :1;                                /*!< Set the priority of channel 12 */
  uint32_t CH13                   :1;                                /*!< Set the priority of channel 13 */
  uint32_t CH14                   :1;                                /*!< Set the priority of channel 14 */
  uint32_t CH15                   :1;                                /*!< Set the priority of channel 15 */
} _DMA_RD_PRIORITY_bits;

/* Bit field positions: */
#define DMA_RD_PRIORITY_CH0_Pos               0                      /*!< Set the priority of channel 0 */
#define DMA_RD_PRIORITY_CH1_Pos               1                      /*!< Set the priority of channel 1 */
#define DMA_RD_PRIORITY_CH2_Pos               2                      /*!< Set the priority of channel 2 */
#define DMA_RD_PRIORITY_CH3_Pos               3                      /*!< Set the priority of channel 3 */
#define DMA_RD_PRIORITY_CH4_Pos               4                      /*!< Set the priority of channel 4 */
#define DMA_RD_PRIORITY_CH5_Pos               5                      /*!< Set the priority of channel 5 */
#define DMA_RD_PRIORITY_CH6_Pos               6                      /*!< Set the priority of channel 6 */
#define DMA_RD_PRIORITY_CH7_Pos               7                      /*!< Set the priority of channel 7 */
#define DMA_RD_PRIORITY_CH8_Pos               8                      /*!< Set the priority of channel 8 */
#define DMA_RD_PRIORITY_CH9_Pos               9                      /*!< Set the priority of channel 9 */
#define DMA_RD_PRIORITY_CH10_Pos              10                     /*!< Set the priority of channel 10 */
#define DMA_RD_PRIORITY_CH11_Pos              11                     /*!< Set the priority of channel 11 */
#define DMA_RD_PRIORITY_CH12_Pos              12                     /*!< Set the priority of channel 12 */
#define DMA_RD_PRIORITY_CH13_Pos              13                     /*!< Set the priority of channel 13 */
#define DMA_RD_PRIORITY_CH14_Pos              14                     /*!< Set the priority of channel 14 */
#define DMA_RD_PRIORITY_CH15_Pos              15                     /*!< Set the priority of channel 15 */

/* Bit field masks: */
#define DMA_RD_PRIORITY_CH0_Msk               0x00000001UL           /*!< Set the priority of channel 0 */
#define DMA_RD_PRIORITY_CH1_Msk               0x00000002UL           /*!< Set the priority of channel 1 */
#define DMA_RD_PRIORITY_CH2_Msk               0x00000004UL           /*!< Set the priority of channel 2 */
#define DMA_RD_PRIORITY_CH3_Msk               0x00000008UL           /*!< Set the priority of channel 3 */
#define DMA_RD_PRIORITY_CH4_Msk               0x00000010UL           /*!< Set the priority of channel 4 */
#define DMA_RD_PRIORITY_CH5_Msk               0x00000020UL           /*!< Set the priority of channel 5 */
#define DMA_RD_PRIORITY_CH6_Msk               0x00000040UL           /*!< Set the priority of channel 6 */
#define DMA_RD_PRIORITY_CH7_Msk               0x00000080UL           /*!< Set the priority of channel 7 */
#define DMA_RD_PRIORITY_CH8_Msk               0x00000100UL           /*!< Set the priority of channel 8 */
#define DMA_RD_PRIORITY_CH9_Msk               0x00000200UL           /*!< Set the priority of channel 9 */
#define DMA_RD_PRIORITY_CH10_Msk              0x00000400UL           /*!< Set the priority of channel 10 */
#define DMA_RD_PRIORITY_CH11_Msk              0x00000800UL           /*!< Set the priority of channel 11 */
#define DMA_RD_PRIORITY_CH12_Msk              0x00001000UL           /*!< Set the priority of channel 12 */
#define DMA_RD_PRIORITY_CH13_Msk              0x00002000UL           /*!< Set the priority of channel 13 */
#define DMA_RD_PRIORITY_CH14_Msk              0x00004000UL           /*!< Set the priority of channel 14 */
#define DMA_RD_PRIORITY_CH15_Msk              0x00008000UL           /*!< Set the priority of channel 15 */

/*--  WR_PRIORITY: DMA Core write priority channels -----------------------------------------------------------*/
typedef struct {
  uint32_t CH0                    :1;                                /*!< Set the priority of channel 0 */
  uint32_t CH1                    :1;                                /*!< Set the priority of channel 1 */
  uint32_t CH2                    :1;                                /*!< Set the priority of channel 2 */
  uint32_t CH3                    :1;                                /*!< Set the priority of channel 3 */
  uint32_t CH4                    :1;                                /*!< Set the priority of channel 4 */
  uint32_t CH5                    :1;                                /*!< Set the priority of channel 5 */
  uint32_t CH6                    :1;                                /*!< Set the priority of channel 6 */
  uint32_t CH7                    :1;                                /*!< Set the priority of channel 7 */
  uint32_t CH8                    :1;                                /*!< Set the priority of channel 8 */
  uint32_t CH9                    :1;                                /*!< Set the priority of channel 9 */
  uint32_t CH10                   :1;                                /*!< Set the priority of channel 10 */
  uint32_t CH11                   :1;                                /*!< Set the priority of channel 11 */
  uint32_t CH12                   :1;                                /*!< Set the priority of channel 12 */
  uint32_t CH13                   :1;                                /*!< Set the priority of channel 13 */
  uint32_t CH14                   :1;                                /*!< Set the priority of channel 14 */
  uint32_t CH15                   :1;                                /*!< Set the priority of channel 15 */
} _DMA_WR_PRIORITY_bits;

/* Bit field positions: */
#define DMA_WR_PRIORITY_CH0_Pos               0                      /*!< Set the priority of channel 0 */
#define DMA_WR_PRIORITY_CH1_Pos               1                      /*!< Set the priority of channel 1 */
#define DMA_WR_PRIORITY_CH2_Pos               2                      /*!< Set the priority of channel 2 */
#define DMA_WR_PRIORITY_CH3_Pos               3                      /*!< Set the priority of channel 3 */
#define DMA_WR_PRIORITY_CH4_Pos               4                      /*!< Set the priority of channel 4 */
#define DMA_WR_PRIORITY_CH5_Pos               5                      /*!< Set the priority of channel 5 */
#define DMA_WR_PRIORITY_CH6_Pos               6                      /*!< Set the priority of channel 6 */
#define DMA_WR_PRIORITY_CH7_Pos               7                      /*!< Set the priority of channel 7 */
#define DMA_WR_PRIORITY_CH8_Pos               8                      /*!< Set the priority of channel 8 */
#define DMA_WR_PRIORITY_CH9_Pos               9                      /*!< Set the priority of channel 9 */
#define DMA_WR_PRIORITY_CH10_Pos              10                     /*!< Set the priority of channel 10 */
#define DMA_WR_PRIORITY_CH11_Pos              11                     /*!< Set the priority of channel 11 */
#define DMA_WR_PRIORITY_CH12_Pos              12                     /*!< Set the priority of channel 12 */
#define DMA_WR_PRIORITY_CH13_Pos              13                     /*!< Set the priority of channel 13 */
#define DMA_WR_PRIORITY_CH14_Pos              14                     /*!< Set the priority of channel 14 */
#define DMA_WR_PRIORITY_CH15_Pos              15                     /*!< Set the priority of channel 15 */

/* Bit field masks: */
#define DMA_WR_PRIORITY_CH0_Msk               0x00000001UL           /*!< Set the priority of channel 0 */
#define DMA_WR_PRIORITY_CH1_Msk               0x00000002UL           /*!< Set the priority of channel 1 */
#define DMA_WR_PRIORITY_CH2_Msk               0x00000004UL           /*!< Set the priority of channel 2 */
#define DMA_WR_PRIORITY_CH3_Msk               0x00000008UL           /*!< Set the priority of channel 3 */
#define DMA_WR_PRIORITY_CH4_Msk               0x00000010UL           /*!< Set the priority of channel 4 */
#define DMA_WR_PRIORITY_CH5_Msk               0x00000020UL           /*!< Set the priority of channel 5 */
#define DMA_WR_PRIORITY_CH6_Msk               0x00000040UL           /*!< Set the priority of channel 6 */
#define DMA_WR_PRIORITY_CH7_Msk               0x00000080UL           /*!< Set the priority of channel 7 */
#define DMA_WR_PRIORITY_CH8_Msk               0x00000100UL           /*!< Set the priority of channel 8 */
#define DMA_WR_PRIORITY_CH9_Msk               0x00000200UL           /*!< Set the priority of channel 9 */
#define DMA_WR_PRIORITY_CH10_Msk              0x00000400UL           /*!< Set the priority of channel 10 */
#define DMA_WR_PRIORITY_CH11_Msk              0x00000800UL           /*!< Set the priority of channel 11 */
#define DMA_WR_PRIORITY_CH12_Msk              0x00001000UL           /*!< Set the priority of channel 12 */
#define DMA_WR_PRIORITY_CH13_Msk              0x00002000UL           /*!< Set the priority of channel 13 */
#define DMA_WR_PRIORITY_CH14_Msk              0x00004000UL           /*!< Set the priority of channel 14 */
#define DMA_WR_PRIORITY_CH15_Msk              0x00008000UL           /*!< Set the priority of channel 15 */

/*--  CH_START: DMA channel start register --------------------------------------------------------------------*/
typedef struct {
  uint32_t CH0                    :1;                                /*!< Start Channel 0 */
  uint32_t CH1                    :1;                                /*!< Start Channel 1 */
  uint32_t CH2                    :1;                                /*!< Start Channel 2 */
  uint32_t CH3                    :1;                                /*!< Start Channel 3 */
  uint32_t CH4                    :1;                                /*!< Start Channel 4 */
  uint32_t CH5                    :1;                                /*!< Start Channel 5 */
  uint32_t CH6                    :1;                                /*!< Start Channel 6 */
  uint32_t CH7                    :1;                                /*!< Start Channel 7 */
  uint32_t CH8                    :1;                                /*!< Start Channel 8 */
  uint32_t CH9                    :1;                                /*!< Start Channel 9 */
  uint32_t CH10                   :1;                                /*!< Start Channel 10 */
  uint32_t CH11                   :1;                                /*!< Start Channel 11 */
  uint32_t CH12                   :1;                                /*!< Start Channel 12 */
  uint32_t CH13                   :1;                                /*!< Start Channel 13 */
  uint32_t CH14                   :1;                                /*!< Start Channel 14 */
  uint32_t CH15                   :1;                                /*!< Start Channel 15 */
} _DMA_CH_START_bits;

/* Bit field positions: */
#define DMA_CH_START_CH0_Pos                  0                      /*!< Start Channel 0 */
#define DMA_CH_START_CH1_Pos                  1                      /*!< Start Channel 1 */
#define DMA_CH_START_CH2_Pos                  2                      /*!< Start Channel 2 */
#define DMA_CH_START_CH3_Pos                  3                      /*!< Start Channel 3 */
#define DMA_CH_START_CH4_Pos                  4                      /*!< Start Channel 4 */
#define DMA_CH_START_CH5_Pos                  5                      /*!< Start Channel 5 */
#define DMA_CH_START_CH6_Pos                  6                      /*!< Start Channel 6 */
#define DMA_CH_START_CH7_Pos                  7                      /*!< Start Channel 7 */
#define DMA_CH_START_CH8_Pos                  8                      /*!< Start Channel 8 */
#define DMA_CH_START_CH9_Pos                  9                      /*!< Start Channel 9 */
#define DMA_CH_START_CH10_Pos                 10                     /*!< Start Channel 10 */
#define DMA_CH_START_CH11_Pos                 11                     /*!< Start Channel 11 */
#define DMA_CH_START_CH12_Pos                 12                     /*!< Start Channel 12 */
#define DMA_CH_START_CH13_Pos                 13                     /*!< Start Channel 13 */
#define DMA_CH_START_CH14_Pos                 14                     /*!< Start Channel 14 */
#define DMA_CH_START_CH15_Pos                 15                     /*!< Start Channel 15 */

/* Bit field masks: */
#define DMA_CH_START_CH0_Msk                  0x00000001UL           /*!< Start Channel 0 */
#define DMA_CH_START_CH1_Msk                  0x00000002UL           /*!< Start Channel 1 */
#define DMA_CH_START_CH2_Msk                  0x00000004UL           /*!< Start Channel 2 */
#define DMA_CH_START_CH3_Msk                  0x00000008UL           /*!< Start Channel 3 */
#define DMA_CH_START_CH4_Msk                  0x00000010UL           /*!< Start Channel 4 */
#define DMA_CH_START_CH5_Msk                  0x00000020UL           /*!< Start Channel 5 */
#define DMA_CH_START_CH6_Msk                  0x00000040UL           /*!< Start Channel 6 */
#define DMA_CH_START_CH7_Msk                  0x00000080UL           /*!< Start Channel 7 */
#define DMA_CH_START_CH8_Msk                  0x00000100UL           /*!< Start Channel 8 */
#define DMA_CH_START_CH9_Msk                  0x00000200UL           /*!< Start Channel 9 */
#define DMA_CH_START_CH10_Msk                 0x00000400UL           /*!< Start Channel 10 */
#define DMA_CH_START_CH11_Msk                 0x00000800UL           /*!< Start Channel 11 */
#define DMA_CH_START_CH12_Msk                 0x00001000UL           /*!< Start Channel 12 */
#define DMA_CH_START_CH13_Msk                 0x00002000UL           /*!< Start Channel 13 */
#define DMA_CH_START_CH14_Msk                 0x00004000UL           /*!< Start Channel 14 */
#define DMA_CH_START_CH15_Msk                 0x00008000UL           /*!< Start Channel 15 */

/*--  CH_ENABLE: DMA channel enable register ------------------------------------------------------------------*/
typedef struct {
  uint32_t CH0                    :1;                                /*!< Enable Channel 0 */
  uint32_t CH1                    :1;                                /*!< Enable Channel 1 */
  uint32_t CH2                    :1;                                /*!< Enable Channel 2 */
  uint32_t CH3                    :1;                                /*!< Enable Channel 3 */
  uint32_t CH4                    :1;                                /*!< Enable Channel 4 */
  uint32_t CH5                    :1;                                /*!< Enable Channel 5 */
  uint32_t CH6                    :1;                                /*!< Enable Channel 6 */
  uint32_t CH7                    :1;                                /*!< Enable Channel 7 */
  uint32_t CH8                    :1;                                /*!< Enable Channel 8 */
  uint32_t CH9                    :1;                                /*!< Enable Channel 9 */
  uint32_t CH10                   :1;                                /*!< Enable Channel 10 */
  uint32_t CH11                   :1;                                /*!< Enable Channel 11 */
  uint32_t CH12                   :1;                                /*!< Enable Channel 12 */
  uint32_t CH13                   :1;                                /*!< Enable Channel 13 */
  uint32_t CH14                   :1;                                /*!< Enable Channel 14 */
  uint32_t CH15                   :1;                                /*!< Enable Channel 15 */
} _DMA_CH_ENABLE_bits;

/* Bit field positions: */
#define DMA_CH_ENABLE_CH0_Pos                 0                      /*!< Enable Channel 0 */
#define DMA_CH_ENABLE_CH1_Pos                 1                      /*!< Enable Channel 1 */
#define DMA_CH_ENABLE_CH2_Pos                 2                      /*!< Enable Channel 2 */
#define DMA_CH_ENABLE_CH3_Pos                 3                      /*!< Enable Channel 3 */
#define DMA_CH_ENABLE_CH4_Pos                 4                      /*!< Enable Channel 4 */
#define DMA_CH_ENABLE_CH5_Pos                 5                      /*!< Enable Channel 5 */
#define DMA_CH_ENABLE_CH6_Pos                 6                      /*!< Enable Channel 6 */
#define DMA_CH_ENABLE_CH7_Pos                 7                      /*!< Enable Channel 7 */
#define DMA_CH_ENABLE_CH8_Pos                 8                      /*!< Enable Channel 8 */
#define DMA_CH_ENABLE_CH9_Pos                 9                      /*!< Enable Channel 9 */
#define DMA_CH_ENABLE_CH10_Pos                10                     /*!< Enable Channel 10 */
#define DMA_CH_ENABLE_CH11_Pos                11                     /*!< Enable Channel 11 */
#define DMA_CH_ENABLE_CH12_Pos                12                     /*!< Enable Channel 12 */
#define DMA_CH_ENABLE_CH13_Pos                13                     /*!< Enable Channel 13 */
#define DMA_CH_ENABLE_CH14_Pos                14                     /*!< Enable Channel 14 */
#define DMA_CH_ENABLE_CH15_Pos                15                     /*!< Enable Channel 15 */

/* Bit field masks: */
#define DMA_CH_ENABLE_CH0_Msk                 0x00000001UL           /*!< Enable Channel 0 */
#define DMA_CH_ENABLE_CH1_Msk                 0x00000002UL           /*!< Enable Channel 1 */
#define DMA_CH_ENABLE_CH2_Msk                 0x00000004UL           /*!< Enable Channel 2 */
#define DMA_CH_ENABLE_CH3_Msk                 0x00000008UL           /*!< Enable Channel 3 */
#define DMA_CH_ENABLE_CH4_Msk                 0x00000010UL           /*!< Enable Channel 4 */
#define DMA_CH_ENABLE_CH5_Msk                 0x00000020UL           /*!< Enable Channel 5 */
#define DMA_CH_ENABLE_CH6_Msk                 0x00000040UL           /*!< Enable Channel 6 */
#define DMA_CH_ENABLE_CH7_Msk                 0x00000080UL           /*!< Enable Channel 7 */
#define DMA_CH_ENABLE_CH8_Msk                 0x00000100UL           /*!< Enable Channel 8 */
#define DMA_CH_ENABLE_CH9_Msk                 0x00000200UL           /*!< Enable Channel 9 */
#define DMA_CH_ENABLE_CH10_Msk                0x00000400UL           /*!< Enable Channel 10 */
#define DMA_CH_ENABLE_CH11_Msk                0x00000800UL           /*!< Enable Channel 11 */
#define DMA_CH_ENABLE_CH12_Msk                0x00001000UL           /*!< Enable Channel 12 */
#define DMA_CH_ENABLE_CH13_Msk                0x00002000UL           /*!< Enable Channel 13 */
#define DMA_CH_ENABLE_CH14_Msk                0x00004000UL           /*!< Enable Channel 14 */
#define DMA_CH_ENABLE_CH15_Msk                0x00008000UL           /*!< Enable Channel 15 */

/*--  IDLE: Idle indication register --------------------------------------------------------------------------*/
typedef struct {
  uint32_t IDLE                   :1;                                /*!< IDLE Status */
} _DMA_IDLE_bits;

/* Bit field positions: */
#define DMA_IDLE_IDLE_Pos                     0                      /*!< IDLE Status */

/* Bit field masks: */
#define DMA_IDLE_IDLE_Msk                     0x00000001UL           /*!< IDLE Status */

/*--  PER_RX0_CTRL: Direct control of peripheral RX request (register 0) --------------------------------------*/
typedef struct {
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t RXREQ                  :19;                               /*!<  */
} _DMA_PER_RX0_CTRL_bits;

/* Bit field positions: */
#define DMA_PER_RX0_CTRL_RXREQ_Pos            1                      /*!<  */

/* Bit field masks: */
#define DMA_PER_RX0_CTRL_RXREQ_Msk            0x000FFFFEUL           /*!<  */

/*--  PER_TX0_CTRL: Direct control of peripheral TX request (register 0) --------------------------------------*/
typedef struct {
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t TXREQ                  :19;                               /*!<  */
} _DMA_PER_TX0_CTRL_bits;

/* Bit field positions: */
#define DMA_PER_TX0_CTRL_TXREQ_Pos            1                      /*!<  */

/* Bit field masks: */
#define DMA_PER_TX0_CTRL_TXREQ_Msk            0x000FFFFEUL           /*!<  */

//Cluster CH:
typedef struct {
  union {
  /*!< Command register 0 (source pointer) */
    __IO uint32_t SRC_PTR;                                           /*!< SRC_PTR : type used for word access */
    __IO _DMA_CH_SRC_PTR_bits SRC_PTR_bit;                           /*!< SRC_PTR_bit: structure used for bit access */
  };
  union {
  /*!< Command register 1 (destination pointer) */
    __IO uint32_t DST_PTR;                                           /*!< DST_PTR : type used for word access */
    __IO _DMA_CH_DST_PTR_bits DST_PTR_bit;                           /*!< DST_PTR_bit: structure used for bit access */
  };
  union {
      union {
                                                                     /*!< Command register 2 (number of data to transfer, linear mode) */
        __IO uint32_t NDTL;                                           /*!< NDTL : type used for word access */
        __IO _DMA_CH_NDTL_bits NDTL_bit;                             /*!< NDTL_bit: structure used for bit access */
      };
      union {
                                                                     /*!< Command register 2 (number of data to transfer, block mode) - Not Implemented */
        __I uint32_t NDTB;                                           /*!< NDTB : type used for word access */
        __I _DMA_CH_NDTB_bits NDTB_bit;                              /*!< NDTB_bit: structure used for bit access */
      };
  };
  union {
  /*!< Command register 3 (config) */
    __IO uint32_t CONFIG;                                            /*!< CONFIG : type used for word access */
    __IO _DMA_CH_CONFIG_bits CONFIG_bit;                             /*!< CONFIG_bit: structure used for bit access */
  };
  union {
  /*!< Static register 0 */
    __IO uint32_t STATIC0;                                           /*!< STATIC0 : type used for word access */
    __IO _DMA_CH_STATIC0_bits STATIC0_bit;                           /*!< STATIC0_bit: structure used for bit access */
  };
  union {
  /*!< Static register 1 */
    __IO uint32_t STATIC1;                                           /*!< STATIC1 : type used for word access */
    __IO _DMA_CH_STATIC1_bits STATIC1_bit;                           /*!< STATIC1_bit: structure used for bit access */
  };
  union {
  /*!< Static register 2 */
    __IO uint32_t STATIC2;                                           /*!< STATIC2 : type used for word access */
    __IO _DMA_CH_STATIC2_bits STATIC2_bit;                           /*!< STATIC2_bit: structure used for bit access */
  };
  union {
  /*!< Static register 3 */
    __IO uint32_t STATIC3;                                           /*!< STATIC3 : type used for word access */
    __IO _DMA_CH_STATIC3_bits STATIC3_bit;                           /*!< STATIC3_bit: structure used for bit access */
  };
  union {
  /*!< Static register 4 */
    __IO uint32_t STATIC4;                                           /*!< STATIC4 : type used for word access */
    __IO _DMA_CH_STATIC4_bits STATIC4_bit;                           /*!< STATIC4_bit: structure used for bit access */
  };
  union {
  /*!< Channels restrictions status register */
    __I uint32_t RESTRICT;                                           /*!< RESTRICT : type used for word access */
    __I _DMA_CH_RESTRICT_bits RESTRICT_bit;                          /*!< RESTRICT_bit: structure used for bit access */
  };
  union {
  /*!< Channels read offset status register */
    __I uint32_t RDOFFSET;                                           /*!< RDOFFSET : type used for word access */
    __I _DMA_CH_RDOFFSET_bits RDOFFSET_bit;                          /*!< RDOFFSET_bit: structure used for bit access */
  };
  union {
  /*!< Channels write offset status register */
    __I uint32_t WROFFSET;                                           /*!< WROFFSET : type used for word access */
    __I _DMA_CH_WROFFSET_bits WROFFSET_bit;                          /*!< WROFFSET_bit: structure used for bit access */
  };
  union {
  /*!< FIFO fullness status register */
    __I uint32_t FIFOSTAT;                                           /*!< FIFOSTAT : type used for word access */
    __I _DMA_CH_FIFOSTAT_bits FIFOSTAT_bit;                          /*!< FIFOSTAT_bit: structure used for bit access */
  };
  union {
  /*!< Outstanding commands status register */
    __I uint32_t CMD_OUTS;                                           /*!< CMD_OUTS : type used for word access */
    __I _DMA_CH_CMD_OUTS_bits CMD_OUTS_bit;                          /*!< CMD_OUTS_bit: structure used for bit access */
  };
    __IO uint32_t Reserved0[2];
  union {
  /*!< Channel active register */
    __IO uint32_t CH_ACTIVE;                                           /*!< CH_ACTIVE : type used for word access */
    __IO _DMA_CH_CH_ACTIVE_bits CH_ACTIVE_bit;                       /*!< CH_ACTIVE_bit: structure used for bit access */
  };
  union {
  /*!< Channel start register */
    __O uint32_t CH_START;                                           /*!< CH_START : type used for word access */
    __O _DMA_CH_CH_START_bits CH_START_bit;                          /*!< CH_START_bit: structure used for bit access */
  };
  union {
  /*!< Channel status register */
    __I uint32_t CH_STATUS;                                           /*!< CH_STATUS : type used for word access */
    __I _DMA_CH_CH_STATUS_bits CH_STATUS_bit;                        /*!< CH_STATUS_bit: structure used for bit access */
  };
  union {
  /*!< Buffer counter status register */
    __I uint32_t COUNT;                                              /*!< COUNT : type used for word access */
    __I _DMA_CH_COUNT_bits COUNT_bit;                                /*!< COUNT_bit: structure used for bit access */
  };
  union {
  /*!< Interrupt raw status register */
    __IO uint32_t INT_RAWSTAT;                                           /*!< INT_RAWSTAT : type used for word access */
    __IO _DMA_CH_INT_RAWSTAT_bits INT_RAWSTAT_bit;                   /*!< INT_RAWSTAT_bit: structure used for bit access */
  };
  union {
  /*!< Interrupt clear register */
    __O uint32_t INT_CLEAR;                                           /*!< INT_CLEAR : type used for word access */
    __O _DMA_CH_INT_CLEAR_bits INT_CLEAR_bit;                        /*!< INT_CLEAR_bit: structure used for bit access */
  };
  union {
  /*!< Interrupt enable register */
    __IO uint32_t INT_ENABLE;                                           /*!< INT_ENABLE : type used for word access */
    __IO _DMA_CH_INT_ENABLE_bits INT_ENABLE_bit;                     /*!< INT_ENABLE_bit: structure used for bit access */
  };
  union {
  /*!< Interrupt status */
    __I uint32_t INT_STATUS;                                           /*!< INT_STATUS : type used for word access */
    __I _DMA_CH_INT_STATUS_bits INT_STATUS_bit;                      /*!< INT_STATUS_bit: structure used for bit access */
  };
  union {
  /*!< Channel error stop condition register */
    __IO uint32_t ERR_STOP;                                           /*!< ERR_STOP : type used for word access */
    __IO _DMA_CH_ERR_STOP_bits ERR_STOP_bit;                         /*!< ERR_STOP_bit: structure used for bit access */
  };
  union {
  /*!< Erroneous read transaction address register */
    __I uint32_t ERR_RD_ADDR;                                           /*!< ERR_RD_ADDR : type used for word access */
    __I _DMA_CH_ERR_RD_ADDR_bits ERR_RD_ADDR_bit;                    /*!< ERR_RD_ADDR_bit: structure used for bit access */
  };
  union {
  /*!< Erroneous write transaction address register */
    __I uint32_t ERR_WR_ADDR;                                           /*!< ERR_WR_ADDR : type used for word access */
    __I _DMA_CH_ERR_WR_ADDR_bits ERR_WR_ADDR_bit;                    /*!< ERR_WR_ADDR_bit: structure used for bit access */
  };
    __IO uint32_t Reserved1[5];
} _DMA_CH_TypeDef;
typedef struct {
  _DMA_CH_TypeDef CH[16];
    __IO uint32_t Reserved0[512];
  union {                                                               /*!< DMA Core Interrupt status register */
    __I uint32_t CH_INTSTAT;                                           /*!< CH_INTSTAT    : type used for word access */
    __I _DMA_CH_INTSTAT_bits  CH_INTSTAT_bit;                        /*!< CH_INTSTAT_bit: structure used for bit access */
  };
  union {                                                               /*!< DMA Core Control register */
    __IO uint32_t CONTROL;                                           /*!< CONTROL    : type used for word access */
    __IO _DMA_CONTROL_bits  CONTROL_bit;                             /*!< CONTROL_bit: structure used for bit access */
  };
  union {                                                               /*!< DMA Core read priority channels */
    __IO uint32_t RD_PRIORITY;                                           /*!< RD_PRIORITY    : type used for word access */
    __IO _DMA_RD_PRIORITY_bits  RD_PRIORITY_bit;                     /*!< RD_PRIORITY_bit: structure used for bit access */
  };
  union {                                                               /*!< DMA Core write priority channels */
    __IO uint32_t WR_PRIORITY;                                           /*!< WR_PRIORITY    : type used for word access */
    __IO _DMA_WR_PRIORITY_bits  WR_PRIORITY_bit;                     /*!< WR_PRIORITY_bit: structure used for bit access */
  };
  union {                                                               /*!< DMA channel start register */
    __O uint32_t CH_START;                                           /*!< CH_START    : type used for word access */
    __O _DMA_CH_START_bits  CH_START_bit;                            /*!< CH_START_bit: structure used for bit access */
  };
  union {                                                               /*!< DMA channel enable register */
    __IO uint32_t CH_ENABLE;                                           /*!< CH_ENABLE    : type used for word access */
    __IO _DMA_CH_ENABLE_bits  CH_ENABLE_bit;                         /*!< CH_ENABLE_bit: structure used for bit access */
  };
  union {                                                               /*!< Idle indication register */
    __I uint32_t IDLE;                                               /*!< IDLE    : type used for word access */
    __I _DMA_IDLE_bits  IDLE_bit;                                    /*!< IDLE_bit: structure used for bit access */
  };
    __IO uint32_t Reserved1;
  union {                                                               /*!< Direct control of peripheral RX request (register 0) */
    __IO uint32_t PER_RX0_CTRL;                                           /*!< PER_RX0_CTRL    : type used for word access */
    __IO _DMA_PER_RX0_CTRL_bits  PER_RX0_CTRL_bit;                   /*!< PER_RX0_CTRL_bit: structure used for bit access */
  };
  union {                                                               /*!< Direct control of peripheral TX request (register 0) */
    __IO uint32_t PER_TX0_CTRL;                                           /*!< PER_TX0_CTRL    : type used for word access */
    __IO _DMA_PER_TX0_CTRL_bits  PER_TX0_CTRL_bit;                   /*!< PER_TX0_CTRL_bit: structure used for bit access */
  };
} DMA_TypeDef;


/******************************************************************************/
/*                         FLASH registers                                    */
/******************************************************************************/

/*--  ADDR: Address Register ----------------------------------------------------------------------------------*/
/* Per UM (ADDR register): ADDRESS[18:0], byte address, 8-byte aligned
 * (bits 2-0 ignored); bits 31-19 reserved. */
typedef struct {
  uint32_t ADDRESS                :19;                               /*!< Address value (8-byte aligned) */
} _FLASH_ADDR_bits;

/* Bit field positions: */
#define FLASH_ADDR_ADDRESS_Pos                0                      /*!< Address value (8-byte aligned) */

/* Bit field masks: */
#define FLASH_ADDR_ADDRESS_Msk                0x0007FFFFUL           /*!< Address value (8-byte aligned) */

/*--  DATA: Data Register -------------------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!< Data register value for flash operations */
} _FLASH_DATA_bits;

/* Bit field positions: */
#define FLASH_DATA_VAL_Pos                    0                      /*!< Data register value for flash operations */

/* Bit field masks: */
#define FLASH_DATA_VAL_Msk                    0xFFFFFFFFUL           /*!< Data register value for flash operations */

/*--  CMD: Command Register -----------------------------------------------------------------------------------*/
typedef struct {
  uint32_t RD                     :1;                                /*!< Read enable command */
  uint32_t WR                     :1;                                /*!< Write enable command */
  uint32_t ERSEC                  :1;                                /*!< Erase sector enable command */
  uint32_t ALLSEC                 :1;                                /*!< Select all sectors for erase */
  uint32_t DPD                    :1;                                /*!< Enter/Exit power down mode */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t NVRON                  :1;                                /*!< NVR access bit */
  uint32_t                        :7;                                /*!< RESERVED */
  uint32_t KEY                    :16;                               /*!< Magic Key for flash access "C0DE" */
} _FLASH_CMD_bits;

/* Bit field positions: */
#define FLASH_CMD_RD_Pos                      0                      /*!< Read enable command */
#define FLASH_CMD_WR_Pos                      1                      /*!< Write enable command */
#define FLASH_CMD_ERSEC_Pos                   2                      /*!< Erase sector enable command */
#define FLASH_CMD_ALLSEC_Pos                  3                      /*!< Select all sectors for erase */
#define FLASH_CMD_DPD_Pos                     4                      /*!< Enter/Exit power down mode */
#define FLASH_CMD_NVRON_Pos                   8                      /*!< NVR access bit */
#define FLASH_CMD_KEY_Pos                     16                     /*!< Magic Key for flash access "C0DE" */

/* Bit field masks: */
#define FLASH_CMD_RD_Msk                      0x00000001UL           /*!< Read enable command */
#define FLASH_CMD_WR_Msk                      0x00000002UL           /*!< Write enable command */
#define FLASH_CMD_ERSEC_Msk                   0x00000004UL           /*!< Erase sector enable command */
#define FLASH_CMD_ALLSEC_Msk                  0x00000008UL           /*!< Select all sectors for erase */
#define FLASH_CMD_DPD_Msk                     0x00000010UL           /*!< Enter/Exit power down mode */
#define FLASH_CMD_NVRON_Msk                   0x00000100UL           /*!< NVR access bit */
#define FLASH_CMD_KEY_Msk                     0xFFFF0000UL           /*!< Magic Key for flash access "C0DE" */

/* Bit field enums: */
typedef enum {
  FLASH_CMD_KEY_Access                       = 0xC0DEUL,             /*!< magic Key for flash access */
} FLASH_CMD_KEY_Enum;

/*--  STAT: Status Register -----------------------------------------------------------------------------------*/
typedef struct {
  uint32_t BUSY                   :1;                                /*!< Busy status bit when command is processing */
  uint32_t IRQF                   :1;                                /*!< IRQ Flag set when command done. Set by hardware only if IRQEN bit is set. */
  uint32_t                        :2;                                /*!< RESERVED */
  uint32_t DPD                    :1;                                /*!< Flash IP in powerdown mode */
} _FLASH_STAT_bits;

/* Bit field positions: */
#define FLASH_STAT_BUSY_Pos                   0                      /*!< Busy status bit when command is processing */
#define FLASH_STAT_IRQF_Pos                   1                      /*!< IRQ Flag set when command done. Set by hardware only if IRQEN bit is set. */
#define FLASH_STAT_DPD_Pos                    4                      /*!< Flash IP in powerdown mode */

/* Bit field masks: */
#define FLASH_STAT_BUSY_Msk                   0x00000001UL           /*!< Busy status bit when command is processing */
#define FLASH_STAT_IRQF_Msk                   0x00000002UL           /*!< IRQ Flag set when command done. Set by hardware only if IRQEN bit is set. */
#define FLASH_STAT_DPD_Msk                    0x00000010UL           /*!< Flash IP in powerdown mode */

/*--  CTRL: Control Register ----------------------------------------------------------------------------------*/
typedef struct {
  uint32_t FBEN                   :1;                                /*!< Fetch buffer Enable */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t IRQEN                  :1;                                /*!< Command Interrupt enable bit */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t CFLUSH                 :1;                                /*!< Flush internal buffer */
  uint32_t                        :7;                                /*!< RESERVED */
  uint32_t LAT                    :4;                                /*!< Flash latency */
} _FLASH_CTRL_bits;

/* Bit field positions: */
#define FLASH_CTRL_FBEN_Pos                   0                      /*!< Fetch buffer Enable */
#define FLASH_CTRL_IRQEN_Pos                  4                      /*!< Command Interrupt enable bit */
#define FLASH_CTRL_CFLUSH_Pos                 8                      /*!< Flush internal buffer */
#define FLASH_CTRL_LAT_Pos                    16                     /*!< Flash latency */

/* Bit field masks: */
#define FLASH_CTRL_FBEN_Msk                   0x00000001UL           /*!< Fetch buffer Enable */
#define FLASH_CTRL_IRQEN_Msk                  0x00000010UL           /*!< Command Interrupt enable bit */
#define FLASH_CTRL_CFLUSH_Msk                 0x00000100UL           /*!< Flush internal buffer */
#define FLASH_CTRL_LAT_Msk                    0x000F0000UL           /*!< Flash latency */

/*--  FTCETR: Flash Timing Control register (Erase time) ------------------------------------------------------*/
typedef struct {
  uint32_t TSCE                   :32;                               /*!< Erase time value in cycles */
} _FLASH_FTCETR_bits;

/* Bit field positions: */
#define FLASH_FTCETR_TSCE_Pos                 0                      /*!< Erase time value in cycles */

/* Bit field masks: */
#define FLASH_FTCETR_TSCE_Msk                 0xFFFFFFFFUL           /*!< Erase time value in cycles */

/*--  FTCPRT: Flash Timing Control register (Program time) ----------------------------------------------------*/
typedef struct {
  uint32_t TPGS                   :8;                                /*!< Web to PROG2 high time value in cycles */
  uint32_t TPREPROG               :8;                                /*!< Pre-program time value in cycles */
  uint32_t TPREPGS                :8;                                /*!< PREPG to PROG2 time value in cycles */
  uint32_t TPROG                  :8;                                /*!< Program time value in cycles */
} _FLASH_FTCPRT_bits;

/* Bit field positions: */
#define FLASH_FTCPRT_TPGS_Pos                 0                      /*!< Web to PROG2 high time value in cycles */
#define FLASH_FTCPRT_TPREPROG_Pos             8                      /*!< Pre-program time value in cycles */
#define FLASH_FTCPRT_TPREPGS_Pos              16                     /*!< PREPG to PROG2 time value in cycles */
#define FLASH_FTCPRT_TPROG_Pos                24                     /*!< Program time value in cycles */

/* Bit field masks: */
#define FLASH_FTCPRT_TPGS_Msk                 0x000000FFUL           /*!< Web to PROG2 high time value in cycles */
#define FLASH_FTCPRT_TPREPROG_Msk             0x0000FF00UL           /*!< Pre-program time value in cycles */
#define FLASH_FTCPRT_TPREPGS_Msk              0x00FF0000UL           /*!< PREPG to PROG2 time value in cycles */
#define FLASH_FTCPRT_TPROG_Msk                0xFF000000UL           /*!< Program time value in cycles */

/*--  FTCERTR: Flash Timing Control register (Erase Recovery time) --------------------------------------------*/
typedef struct {
  uint32_t TRCVSECT               :16;                               /*!< Sector erase recovery time value in cycles */
  uint32_t TRCVCHIP               :16;                               /*!< Chip erase recovery time value in cycles */
} _FLASH_FTCERTR_bits;

/* Bit field positions: */
#define FLASH_FTCERTR_TRCVSECT_Pos            0                      /*!< Sector erase recovery time value in cycles */
#define FLASH_FTCERTR_TRCVCHIP_Pos            16                     /*!< Chip erase recovery time value in cycles */

/* Bit field masks: */
#define FLASH_FTCERTR_TRCVSECT_Msk            0x0000FFFFUL           /*!< Sector erase recovery time value in cycles */
#define FLASH_FTCERTR_TRCVCHIP_Msk            0xFFFF0000UL           /*!< Chip erase recovery time value in cycles */

/*--  FTCPRTR: Flash Timing Control register (Program Recovery time) ------------------------------------------*/
typedef struct {
  uint32_t TRCVPROG               :8;                                /*!< Program recovery time value in cycles */
} _FLASH_FTCPRTR_bits;

/* Bit field positions: */
#define FLASH_FTCPRTR_TRCVPROG_Pos            0                      /*!< Program recovery time value in cycles */

/* Bit field masks: */
#define FLASH_FTCPRTR_TRCVPROG_Msk            0x000000FFUL           /*!< Program recovery time value in cycles */

//Cluster DATA:
typedef struct {
  union {
  /*!< Data Register */
    __IO uint32_t DATA;                                              /*!< DATA : type used for word access */
    __IO _FLASH_DATA_bits DATA_bit;                                  /*!< DATA_bit: structure used for bit access */
  };
} _FLASH_DATA_TypeDef;
typedef struct {
  union {                                                               /*!< Address Register */
    __IO uint32_t ADDR;                                              /*!< ADDR    : type used for word access */
    __IO _FLASH_ADDR_bits  ADDR_bit;                                 /*!< ADDR_bit: structure used for bit access */
  };
    __IO uint32_t Reserved0[3];
  _FLASH_DATA_TypeDef DATA[2];
    __IO uint32_t Reserved1[10];
  union {                                                               /*!< Command Register */
    __IO uint32_t CMD;                                               /*!< CMD    : type used for word access */
    __IO _FLASH_CMD_bits  CMD_bit;                                   /*!< CMD_bit: structure used for bit access */
  };
  union {                                                               /*!< Status Register */
    __IO uint32_t STAT;                                              /*!< STAT    : type used for word access */
    __IO _FLASH_STAT_bits  STAT_bit;                                 /*!< STAT_bit: structure used for bit access */
  };
  union {                                                               /*!< Control Register */
    __IO uint32_t CTRL;                                              /*!< CTRL    : type used for word access */
    __IO _FLASH_CTRL_bits  CTRL_bit;                                 /*!< CTRL_bit: structure used for bit access */
  };
    __IO uint32_t Reserved2[45];
  union {                                                               /*!< Flash Timing Control register (Erase time) */
    __IO uint32_t FTCETR;                                            /*!< FTCETR    : type used for word access */
    __IO _FLASH_FTCETR_bits  FTCETR_bit;                             /*!< FTCETR_bit: structure used for bit access */
  };
  union {                                                               /*!< Flash Timing Control register (Program time) */
    __IO uint32_t FTCPRT;                                            /*!< FTCPRT    : type used for word access */
    __IO _FLASH_FTCPRT_bits  FTCPRT_bit;                             /*!< FTCPRT_bit: structure used for bit access */
  };
  union {                                                               /*!< Flash Timing Control register (Erase Recovery time) */
    __IO uint32_t FTCERTR;                                           /*!< FTCERTR    : type used for word access */
    __IO _FLASH_FTCERTR_bits  FTCERTR_bit;                           /*!< FTCERTR_bit: structure used for bit access */
  };
  union {                                                               /*!< Flash Timing Control register (Program Recovery time) */
    __IO uint32_t FTCPRTR;                                           /*!< FTCPRTR    : type used for word access */
    __IO _FLASH_FTCPRTR_bits  FTCPRTR_bit;                           /*!< FTCPRTR_bit: structure used for bit access */
  };
} FLASH_TypeDef;


/******************************************************************************/
/*                         GPIO registers                                     */
/******************************************************************************/

/*--  DATA: Data Input register -------------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :16;                               /*!< Data input */
} _GPIO_DATA_bits;

/* Bit field positions: */
#define GPIO_DATA_VAL_Pos                     0                      /*!< Data input */

/* Bit field masks: */
#define GPIO_DATA_VAL_Msk                     0x0000FFFFUL           /*!< Data input */

/*--  DATAOUT: Data output register ---------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :16;                               /*!< Data output */
} _GPIO_DATAOUT_bits;

/* Bit field positions: */
#define GPIO_DATAOUT_VAL_Pos                  0                      /*!< Data output */

/* Bit field masks: */
#define GPIO_DATAOUT_VAL_Msk                  0x0000FFFFUL           /*!< Data output */

/*--  DATAOUTSET: Data output set bits register ---------------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< Data output set bit 0 */
  uint32_t PIN1                   :1;                                /*!< Data output set bit 1 */
  uint32_t PIN2                   :1;                                /*!< Data output set bit 2 */
  uint32_t PIN3                   :1;                                /*!< Data output set bit 3 */
  uint32_t PIN4                   :1;                                /*!< Data output set bit 4 */
  uint32_t PIN5                   :1;                                /*!< Data output set bit 5 */
  uint32_t PIN6                   :1;                                /*!< Data output set bit 6 */
  uint32_t PIN7                   :1;                                /*!< Data output set bit 7 */
  uint32_t PIN8                   :1;                                /*!< Data output set bit 8 */
  uint32_t PIN9                   :1;                                /*!< Data output set bit 9 */
  uint32_t PIN10                  :1;                                /*!< Data output set bit 10 */
  uint32_t PIN11                  :1;                                /*!< Data output set bit 11 */
  uint32_t PIN12                  :1;                                /*!< Data output set bit 12 */
  uint32_t PIN13                  :1;                                /*!< Data output set bit 13 */
  uint32_t PIN14                  :1;                                /*!< Data output set bit 14 */
  uint32_t PIN15                  :1;                                /*!< Data output set bit 15 */
} _GPIO_DATAOUTSET_bits;

/* Bit field positions: */
#define GPIO_DATAOUTSET_PIN0_Pos              0                      /*!< Data output set bit 0 */
#define GPIO_DATAOUTSET_PIN1_Pos              1                      /*!< Data output set bit 1 */
#define GPIO_DATAOUTSET_PIN2_Pos              2                      /*!< Data output set bit 2 */
#define GPIO_DATAOUTSET_PIN3_Pos              3                      /*!< Data output set bit 3 */
#define GPIO_DATAOUTSET_PIN4_Pos              4                      /*!< Data output set bit 4 */
#define GPIO_DATAOUTSET_PIN5_Pos              5                      /*!< Data output set bit 5 */
#define GPIO_DATAOUTSET_PIN6_Pos              6                      /*!< Data output set bit 6 */
#define GPIO_DATAOUTSET_PIN7_Pos              7                      /*!< Data output set bit 7 */
#define GPIO_DATAOUTSET_PIN8_Pos              8                      /*!< Data output set bit 8 */
#define GPIO_DATAOUTSET_PIN9_Pos              9                      /*!< Data output set bit 9 */
#define GPIO_DATAOUTSET_PIN10_Pos             10                     /*!< Data output set bit 10 */
#define GPIO_DATAOUTSET_PIN11_Pos             11                     /*!< Data output set bit 11 */
#define GPIO_DATAOUTSET_PIN12_Pos             12                     /*!< Data output set bit 12 */
#define GPIO_DATAOUTSET_PIN13_Pos             13                     /*!< Data output set bit 13 */
#define GPIO_DATAOUTSET_PIN14_Pos             14                     /*!< Data output set bit 14 */
#define GPIO_DATAOUTSET_PIN15_Pos             15                     /*!< Data output set bit 15 */

/* Bit field masks: */
#define GPIO_DATAOUTSET_PIN0_Msk              0x00000001UL           /*!< Data output set bit 0 */
#define GPIO_DATAOUTSET_PIN1_Msk              0x00000002UL           /*!< Data output set bit 1 */
#define GPIO_DATAOUTSET_PIN2_Msk              0x00000004UL           /*!< Data output set bit 2 */
#define GPIO_DATAOUTSET_PIN3_Msk              0x00000008UL           /*!< Data output set bit 3 */
#define GPIO_DATAOUTSET_PIN4_Msk              0x00000010UL           /*!< Data output set bit 4 */
#define GPIO_DATAOUTSET_PIN5_Msk              0x00000020UL           /*!< Data output set bit 5 */
#define GPIO_DATAOUTSET_PIN6_Msk              0x00000040UL           /*!< Data output set bit 6 */
#define GPIO_DATAOUTSET_PIN7_Msk              0x00000080UL           /*!< Data output set bit 7 */
#define GPIO_DATAOUTSET_PIN8_Msk              0x00000100UL           /*!< Data output set bit 8 */
#define GPIO_DATAOUTSET_PIN9_Msk              0x00000200UL           /*!< Data output set bit 9 */
#define GPIO_DATAOUTSET_PIN10_Msk             0x00000400UL           /*!< Data output set bit 10 */
#define GPIO_DATAOUTSET_PIN11_Msk             0x00000800UL           /*!< Data output set bit 11 */
#define GPIO_DATAOUTSET_PIN12_Msk             0x00001000UL           /*!< Data output set bit 12 */
#define GPIO_DATAOUTSET_PIN13_Msk             0x00002000UL           /*!< Data output set bit 13 */
#define GPIO_DATAOUTSET_PIN14_Msk             0x00004000UL           /*!< Data output set bit 14 */
#define GPIO_DATAOUTSET_PIN15_Msk             0x00008000UL           /*!< Data output set bit 15 */

/*--  DATAOUTCLR: Data output clear bits register -------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :16;                               /*!< Data output clear */
} _GPIO_DATAOUTCLR_bits;

/* Bit field positions: */
#define GPIO_DATAOUTCLR_VAL_Pos               0                      /*!< Data output clear */

/* Bit field masks: */
#define GPIO_DATAOUTCLR_VAL_Msk               0x0000FFFFUL           /*!< Data output clear */

/*--  DATAOUTTGL: Data output toggle bits register ------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :16;                               /*!< Data output toggle */
} _GPIO_DATAOUTTGL_bits;

/* Bit field positions: */
#define GPIO_DATAOUTTGL_VAL_Pos               0                      /*!< Data output toggle */

/* Bit field masks: */
#define GPIO_DATAOUTTGL_VAL_Msk               0x0000FFFFUL           /*!< Data output toggle */

/*--  PULLMODE: Select pull mode register ---------------------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< Select pull mode for pin 0 */
  uint32_t PIN1                   :1;                                /*!< Select pull mode for pin 1 */
  uint32_t PIN2                   :1;                                /*!< Select pull mode for pin 2 */
  uint32_t PIN3                   :1;                                /*!< Select pull mode for pin 3 */
  uint32_t PIN4                   :1;                                /*!< Select pull mode for pin 4 */
  uint32_t PIN5                   :1;                                /*!< Select pull mode for pin 5 */
  uint32_t PIN6                   :1;                                /*!< Select pull mode for pin 6 */
  uint32_t PIN7                   :1;                                /*!< Select pull mode for pin 7 */
  uint32_t PIN8                   :1;                                /*!< Select pull mode for pin 8 */
  uint32_t PIN9                   :1;                                /*!< Select pull mode for pin 9 */
  uint32_t PIN10                  :1;                                /*!< Select pull mode for pin 10 */
  uint32_t PIN11                  :1;                                /*!< Select pull mode for pin 11 */
  uint32_t PIN12                  :1;                                /*!< Select pull mode for pin 12 */
  uint32_t PIN13                  :1;                                /*!< Select pull mode for pin 13 */
  uint32_t PIN14                  :1;                                /*!< Select pull mode for pin 14 */
  uint32_t PIN15                  :1;                                /*!< Select pull mode for pin 15 */
  uint32_t                        :16;                               /*!< RESERVED (UM A.5 / SVD: 1 bit per pin) */
} _GPIO_PULLMODE_bits;

/* Bit field positions: */
#define GPIO_PULLMODE_PIN0_Pos                0                      /*!< Select pull mode for pin 0 */
#define GPIO_PULLMODE_PIN1_Pos                1                      /*!< Select pull mode for pin 1 */
#define GPIO_PULLMODE_PIN2_Pos                2                      /*!< Select pull mode for pin 2 */
#define GPIO_PULLMODE_PIN3_Pos                3                      /*!< Select pull mode for pin 3 */
#define GPIO_PULLMODE_PIN4_Pos                4                      /*!< Select pull mode for pin 4 */
#define GPIO_PULLMODE_PIN5_Pos                5                     /*!< Select pull mode for pin 5 */
#define GPIO_PULLMODE_PIN6_Pos                6                     /*!< Select pull mode for pin 6 */
#define GPIO_PULLMODE_PIN7_Pos                7                     /*!< Select pull mode for pin 7 */
#define GPIO_PULLMODE_PIN8_Pos                8                     /*!< Select pull mode for pin 8 */
#define GPIO_PULLMODE_PIN9_Pos                9                     /*!< Select pull mode for pin 9 */
#define GPIO_PULLMODE_PIN10_Pos               10                     /*!< Select pull mode for pin 10 */
#define GPIO_PULLMODE_PIN11_Pos               11                     /*!< Select pull mode for pin 11 */
#define GPIO_PULLMODE_PIN12_Pos               12                     /*!< Select pull mode for pin 12 */
#define GPIO_PULLMODE_PIN13_Pos               13                     /*!< Select pull mode for pin 13 */
#define GPIO_PULLMODE_PIN14_Pos               14                     /*!< Select pull mode for pin 14 */
#define GPIO_PULLMODE_PIN15_Pos               15                     /*!< Select pull mode for pin 15 */

/* Bit field masks: */
#define GPIO_PULLMODE_PIN0_Msk                0x00000001UL           /*!< Select pull mode for pin 0 */
#define GPIO_PULLMODE_PIN1_Msk                0x00000002UL           /*!< Select pull mode for pin 1 */
#define GPIO_PULLMODE_PIN2_Msk                0x00000004UL           /*!< Select pull mode for pin 2 */
#define GPIO_PULLMODE_PIN3_Msk                0x00000008UL           /*!< Select pull mode for pin 3 */
#define GPIO_PULLMODE_PIN4_Msk                0x00000010UL           /*!< Select pull mode for pin 4 */
#define GPIO_PULLMODE_PIN5_Msk                0x00000020UL           /*!< Select pull mode for pin 5 */
#define GPIO_PULLMODE_PIN6_Msk                0x00000040UL           /*!< Select pull mode for pin 6 */
#define GPIO_PULLMODE_PIN7_Msk                0x00000080UL           /*!< Select pull mode for pin 7 */
#define GPIO_PULLMODE_PIN8_Msk                0x00000100UL           /*!< Select pull mode for pin 8 */
#define GPIO_PULLMODE_PIN9_Msk                0x00000200UL           /*!< Select pull mode for pin 9 */
#define GPIO_PULLMODE_PIN10_Msk               0x00000400UL           /*!< Select pull mode for pin 10 */
#define GPIO_PULLMODE_PIN11_Msk               0x00000800UL           /*!< Select pull mode for pin 11 */
#define GPIO_PULLMODE_PIN12_Msk               0x00001000UL           /*!< Select pull mode for pin 12 */
#define GPIO_PULLMODE_PIN13_Msk               0x00002000UL           /*!< Select pull mode for pin 13 */
#define GPIO_PULLMODE_PIN14_Msk               0x00004000UL           /*!< Select pull mode for pin 14 */
#define GPIO_PULLMODE_PIN15_Msk               0x00008000UL           /*!< Select pull mode for pin 15 */

/* Bit field enums: */
typedef enum {
  GPIO_PULLMODE_PIN0_Disable                 = 0x0UL,                /*!< Pull disabled */
  GPIO_PULLMODE_PIN0_PU                      = 0x1UL,                /*!< Pull-up */
} GPIO_PULLMODE_PIN0_Enum;

typedef enum {
  GPIO_PULLMODE_PIN1_Disable                 = 0x0UL,                /*!< Pull disabled */
  GPIO_PULLMODE_PIN1_PU                      = 0x1UL,                /*!< Pull-up */
} GPIO_PULLMODE_PIN1_Enum;

typedef enum {
  GPIO_PULLMODE_PIN2_Disable                 = 0x0UL,                /*!< Pull disabled */
  GPIO_PULLMODE_PIN2_PU                      = 0x1UL,                /*!< Pull-up */
} GPIO_PULLMODE_PIN2_Enum;

typedef enum {
  GPIO_PULLMODE_PIN3_Disable                 = 0x0UL,                /*!< Pull disabled */
  GPIO_PULLMODE_PIN3_PU                      = 0x1UL,                /*!< Pull-up */
} GPIO_PULLMODE_PIN3_Enum;

typedef enum {
  GPIO_PULLMODE_PIN4_Disable                 = 0x0UL,                /*!< Pull disabled */
  GPIO_PULLMODE_PIN4_PU                      = 0x1UL,                /*!< Pull-up */
} GPIO_PULLMODE_PIN4_Enum;

typedef enum {
  GPIO_PULLMODE_PIN5_Disable                 = 0x0UL,                /*!< Pull disabled */
  GPIO_PULLMODE_PIN5_PU                      = 0x1UL,                /*!< Pull-up */
} GPIO_PULLMODE_PIN5_Enum;

typedef enum {
  GPIO_PULLMODE_PIN6_Disable                 = 0x0UL,                /*!< Pull disabled */
  GPIO_PULLMODE_PIN6_PU                      = 0x1UL,                /*!< Pull-up */
} GPIO_PULLMODE_PIN6_Enum;

typedef enum {
  GPIO_PULLMODE_PIN7_Disable                 = 0x0UL,                /*!< Pull disabled */
  GPIO_PULLMODE_PIN7_PU                      = 0x1UL,                /*!< Pull-up */
} GPIO_PULLMODE_PIN7_Enum;

typedef enum {
  GPIO_PULLMODE_PIN8_Disable                 = 0x0UL,                /*!< Pull disabled */
  GPIO_PULLMODE_PIN8_PU                      = 0x1UL,                /*!< Pull-up */
} GPIO_PULLMODE_PIN8_Enum;

typedef enum {
  GPIO_PULLMODE_PIN9_Disable                 = 0x0UL,                /*!< Pull disabled */
  GPIO_PULLMODE_PIN9_PU                      = 0x1UL,                /*!< Pull-up */
} GPIO_PULLMODE_PIN9_Enum;

typedef enum {
  GPIO_PULLMODE_PIN10_Disable                = 0x0UL,                /*!< Pull disabled */
  GPIO_PULLMODE_PIN10_PU                     = 0x1UL,                /*!< Pull-up */
} GPIO_PULLMODE_PIN10_Enum;

typedef enum {
  GPIO_PULLMODE_PIN11_Disable                = 0x0UL,                /*!< Pull disabled */
  GPIO_PULLMODE_PIN11_PU                     = 0x1UL,                /*!< Pull-up */
} GPIO_PULLMODE_PIN11_Enum;

typedef enum {
  GPIO_PULLMODE_PIN12_Disable                = 0x0UL,                /*!< Pull disabled */
  GPIO_PULLMODE_PIN12_PU                     = 0x1UL,                /*!< Pull-up */
} GPIO_PULLMODE_PIN12_Enum;

typedef enum {
  GPIO_PULLMODE_PIN13_Disable                = 0x0UL,                /*!< Pull disabled */
  GPIO_PULLMODE_PIN13_PU                     = 0x1UL,                /*!< Pull-up */
} GPIO_PULLMODE_PIN13_Enum;

typedef enum {
  GPIO_PULLMODE_PIN14_Disable                = 0x0UL,                /*!< Pull disabled */
  GPIO_PULLMODE_PIN14_PU                     = 0x1UL,                /*!< Pull-up */
} GPIO_PULLMODE_PIN14_Enum;

typedef enum {
  GPIO_PULLMODE_PIN15_Disable                = 0x0UL,                /*!< Pull disabled */
  GPIO_PULLMODE_PIN15_PU                     = 0x1UL,                /*!< Pull-up */
} GPIO_PULLMODE_PIN15_Enum;

/*--  OUTMODE: Select output mode register --------------------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :2;                                /*!< Select output mode for pin 0 */
  uint32_t PIN1                   :2;                                /*!< Select output mode for pin 1 */
  uint32_t PIN2                   :2;                                /*!< Select output mode for pin 2 */
  uint32_t PIN3                   :2;                                /*!< Select output mode for pin 3 */
  uint32_t PIN4                   :2;                                /*!< Select output mode for pin 4 */
  uint32_t PIN5                   :2;                                /*!< Select output mode for pin 5 */
  uint32_t PIN6                   :2;                                /*!< Select output mode for pin 6 */
  uint32_t PIN7                   :2;                                /*!< Select output mode for pin 7 */
  uint32_t PIN8                   :2;                                /*!< Select output mode for pin 8 */
  uint32_t PIN9                   :2;                                /*!< Select output mode for pin 9 */
  uint32_t PIN10                  :2;                                /*!< Select output mode for pin 10 */
  uint32_t PIN11                  :2;                                /*!< Select output mode for pin 11 */
  uint32_t PIN12                  :2;                                /*!< Select output mode for pin 12 */
  uint32_t PIN13                  :2;                                /*!< Select output mode for pin 13 */
  uint32_t PIN14                  :2;                                /*!< Select output mode for pin 14 */
  uint32_t PIN15                  :2;                                /*!< Select output mode for pin 15 */
} _GPIO_OUTMODE_bits;

/* Bit field positions: */
#define GPIO_OUTMODE_PIN0_Pos                 0                      /*!< Select output mode for pin 0 */
#define GPIO_OUTMODE_PIN1_Pos                 2                      /*!< Select output mode for pin 1 */
#define GPIO_OUTMODE_PIN2_Pos                 4                      /*!< Select output mode for pin 2 */
#define GPIO_OUTMODE_PIN3_Pos                 6                      /*!< Select output mode for pin 3 */
#define GPIO_OUTMODE_PIN4_Pos                 8                      /*!< Select output mode for pin 4 */
#define GPIO_OUTMODE_PIN5_Pos                 10                     /*!< Select output mode for pin 5 */
#define GPIO_OUTMODE_PIN6_Pos                 12                     /*!< Select output mode for pin 6 */
#define GPIO_OUTMODE_PIN7_Pos                 14                     /*!< Select output mode for pin 7 */
#define GPIO_OUTMODE_PIN8_Pos                 16                     /*!< Select output mode for pin 8 */
#define GPIO_OUTMODE_PIN9_Pos                 18                     /*!< Select output mode for pin 9 */
#define GPIO_OUTMODE_PIN10_Pos                20                     /*!< Select output mode for pin 10 */
#define GPIO_OUTMODE_PIN11_Pos                22                     /*!< Select output mode for pin 11 */
#define GPIO_OUTMODE_PIN12_Pos                24                     /*!< Select output mode for pin 12 */
#define GPIO_OUTMODE_PIN13_Pos                26                     /*!< Select output mode for pin 13 */
#define GPIO_OUTMODE_PIN14_Pos                28                     /*!< Select output mode for pin 14 */
#define GPIO_OUTMODE_PIN15_Pos                30                     /*!< Select output mode for pin 15 */

/* Bit field masks: */
#define GPIO_OUTMODE_PIN0_Msk                 0x00000003UL           /*!< Select output mode for pin 0 */
#define GPIO_OUTMODE_PIN1_Msk                 0x0000000CUL           /*!< Select output mode for pin 1 */
#define GPIO_OUTMODE_PIN2_Msk                 0x00000030UL           /*!< Select output mode for pin 2 */
#define GPIO_OUTMODE_PIN3_Msk                 0x000000C0UL           /*!< Select output mode for pin 3 */
#define GPIO_OUTMODE_PIN4_Msk                 0x00000300UL           /*!< Select output mode for pin 4 */
#define GPIO_OUTMODE_PIN5_Msk                 0x00000C00UL           /*!< Select output mode for pin 5 */
#define GPIO_OUTMODE_PIN6_Msk                 0x00003000UL           /*!< Select output mode for pin 6 */
#define GPIO_OUTMODE_PIN7_Msk                 0x0000C000UL           /*!< Select output mode for pin 7 */
#define GPIO_OUTMODE_PIN8_Msk                 0x00030000UL           /*!< Select output mode for pin 8 */
#define GPIO_OUTMODE_PIN9_Msk                 0x000C0000UL           /*!< Select output mode for pin 9 */
#define GPIO_OUTMODE_PIN10_Msk                0x00300000UL           /*!< Select output mode for pin 10 */
#define GPIO_OUTMODE_PIN11_Msk                0x00C00000UL           /*!< Select output mode for pin 11 */
#define GPIO_OUTMODE_PIN12_Msk                0x03000000UL           /*!< Select output mode for pin 12 */
#define GPIO_OUTMODE_PIN13_Msk                0x0C000000UL           /*!< Select output mode for pin 13 */
#define GPIO_OUTMODE_PIN14_Msk                0x30000000UL           /*!< Select output mode for pin 14 */
#define GPIO_OUTMODE_PIN15_Msk                0xC0000000UL           /*!< Select output mode for pin 15 */

/* Bit field enums: */
typedef enum {
  GPIO_OUTMODE_PIN0_PP                       = 0x0UL,                /*!< Push-pull output */
  GPIO_OUTMODE_PIN0_OD                       = 0x1UL,                /*!< Open drain output */
  GPIO_OUTMODE_PIN0_OS                       = 0x2UL,                /*!< Open source output */
} GPIO_OUTMODE_PIN0_Enum;

typedef enum {
  GPIO_OUTMODE_PIN1_PP                       = 0x0UL,                /*!< Push-pull output */
  GPIO_OUTMODE_PIN1_OD                       = 0x1UL,                /*!< Open drain output */
  GPIO_OUTMODE_PIN1_OS                       = 0x2UL,                /*!< Open source output */
} GPIO_OUTMODE_PIN1_Enum;

typedef enum {
  GPIO_OUTMODE_PIN2_PP                       = 0x0UL,                /*!< Push-pull output */
  GPIO_OUTMODE_PIN2_OD                       = 0x1UL,                /*!< Open drain output */
  GPIO_OUTMODE_PIN2_OS                       = 0x2UL,                /*!< Open source output */
} GPIO_OUTMODE_PIN2_Enum;

typedef enum {
  GPIO_OUTMODE_PIN3_PP                       = 0x0UL,                /*!< Push-pull output */
  GPIO_OUTMODE_PIN3_OD                       = 0x1UL,                /*!< Open drain output */
  GPIO_OUTMODE_PIN3_OS                       = 0x2UL,                /*!< Open source output */
} GPIO_OUTMODE_PIN3_Enum;

typedef enum {
  GPIO_OUTMODE_PIN4_PP                       = 0x0UL,                /*!< Push-pull output */
  GPIO_OUTMODE_PIN4_OD                       = 0x1UL,                /*!< Open drain output */
  GPIO_OUTMODE_PIN4_OS                       = 0x2UL,                /*!< Open source output */
} GPIO_OUTMODE_PIN4_Enum;

typedef enum {
  GPIO_OUTMODE_PIN5_PP                       = 0x0UL,                /*!< Push-pull output */
  GPIO_OUTMODE_PIN5_OD                       = 0x1UL,                /*!< Open drain output */
  GPIO_OUTMODE_PIN5_OS                       = 0x2UL,                /*!< Open source output */
} GPIO_OUTMODE_PIN5_Enum;

typedef enum {
  GPIO_OUTMODE_PIN6_PP                       = 0x0UL,                /*!< Push-pull output */
  GPIO_OUTMODE_PIN6_OD                       = 0x1UL,                /*!< Open drain output */
  GPIO_OUTMODE_PIN6_OS                       = 0x2UL,                /*!< Open source output */
} GPIO_OUTMODE_PIN6_Enum;

typedef enum {
  GPIO_OUTMODE_PIN7_PP                       = 0x0UL,                /*!< Push-pull output */
  GPIO_OUTMODE_PIN7_OD                       = 0x1UL,                /*!< Open drain output */
  GPIO_OUTMODE_PIN7_OS                       = 0x2UL,                /*!< Open source output */
} GPIO_OUTMODE_PIN7_Enum;

typedef enum {
  GPIO_OUTMODE_PIN8_PP                       = 0x0UL,                /*!< Push-pull output */
  GPIO_OUTMODE_PIN8_OD                       = 0x1UL,                /*!< Open drain output */
  GPIO_OUTMODE_PIN8_OS                       = 0x2UL,                /*!< Open source output */
} GPIO_OUTMODE_PIN8_Enum;

typedef enum {
  GPIO_OUTMODE_PIN9_PP                       = 0x0UL,                /*!< Push-pull output */
  GPIO_OUTMODE_PIN9_OD                       = 0x1UL,                /*!< Open drain output */
  GPIO_OUTMODE_PIN9_OS                       = 0x2UL,                /*!< Open source output */
} GPIO_OUTMODE_PIN9_Enum;

typedef enum {
  GPIO_OUTMODE_PIN10_PP                      = 0x0UL,                /*!< Push-pull output */
  GPIO_OUTMODE_PIN10_OD                      = 0x1UL,                /*!< Open drain output */
  GPIO_OUTMODE_PIN10_OS                      = 0x2UL,                /*!< Open source output */
} GPIO_OUTMODE_PIN10_Enum;

typedef enum {
  GPIO_OUTMODE_PIN11_PP                      = 0x0UL,                /*!< Push-pull output */
  GPIO_OUTMODE_PIN11_OD                      = 0x1UL,                /*!< Open drain output */
  GPIO_OUTMODE_PIN11_OS                      = 0x2UL,                /*!< Open source output */
} GPIO_OUTMODE_PIN11_Enum;

typedef enum {
  GPIO_OUTMODE_PIN12_PP                      = 0x0UL,                /*!< Push-pull output */
  GPIO_OUTMODE_PIN12_OD                      = 0x1UL,                /*!< Open drain output */
  GPIO_OUTMODE_PIN12_OS                      = 0x2UL,                /*!< Open source output */
} GPIO_OUTMODE_PIN12_Enum;

typedef enum {
  GPIO_OUTMODE_PIN13_PP                      = 0x0UL,                /*!< Push-pull output */
  GPIO_OUTMODE_PIN13_OD                      = 0x1UL,                /*!< Open drain output */
  GPIO_OUTMODE_PIN13_OS                      = 0x2UL,                /*!< Open source output */
} GPIO_OUTMODE_PIN13_Enum;

typedef enum {
  GPIO_OUTMODE_PIN14_PP                      = 0x0UL,                /*!< Push-pull output */
  GPIO_OUTMODE_PIN14_OD                      = 0x1UL,                /*!< Open drain output */
  GPIO_OUTMODE_PIN14_OS                      = 0x2UL,                /*!< Open source output */
} GPIO_OUTMODE_PIN14_Enum;

typedef enum {
  GPIO_OUTMODE_PIN15_PP                      = 0x0UL,                /*!< Push-pull output */
  GPIO_OUTMODE_PIN15_OD                      = 0x1UL,                /*!< Open drain output */
  GPIO_OUTMODE_PIN15_OS                      = 0x2UL,                /*!< Open source output */
} GPIO_OUTMODE_PIN15_Enum;

/*--  OUTENSET: Output enable register ------------------------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< Output enable for pin 0 */
  uint32_t PIN1                   :1;                                /*!< Output enable for pin 1 */
  uint32_t PIN2                   :1;                                /*!< Output enable for pin 2 */
  uint32_t PIN3                   :1;                                /*!< Output enable for pin 3 */
  uint32_t PIN4                   :1;                                /*!< Output enable for pin 4 */
  uint32_t PIN5                   :1;                                /*!< Output enable for pin 5 */
  uint32_t PIN6                   :1;                                /*!< Output enable for pin 6 */
  uint32_t PIN7                   :1;                                /*!< Output enable for pin 7 */
  uint32_t PIN8                   :1;                                /*!< Output enable for pin 8 */
  uint32_t PIN9                   :1;                                /*!< Output enable for pin 9 */
  uint32_t PIN10                  :1;                                /*!< Output enable for pin 10 */
  uint32_t PIN11                  :1;                                /*!< Output enable for pin 11 */
  uint32_t PIN12                  :1;                                /*!< Output enable for pin 12 */
  uint32_t PIN13                  :1;                                /*!< Output enable for pin 13 */
  uint32_t PIN14                  :1;                                /*!< Output enable for pin 14 */
  uint32_t PIN15                  :1;                                /*!< Output enable for pin 15 */
} _GPIO_OUTENSET_bits;

/* Bit field positions: */
#define GPIO_OUTENSET_PIN0_Pos                0                      /*!< Output enable for pin 0 */
#define GPIO_OUTENSET_PIN1_Pos                1                      /*!< Output enable for pin 1 */
#define GPIO_OUTENSET_PIN2_Pos                2                      /*!< Output enable for pin 2 */
#define GPIO_OUTENSET_PIN3_Pos                3                      /*!< Output enable for pin 3 */
#define GPIO_OUTENSET_PIN4_Pos                4                      /*!< Output enable for pin 4 */
#define GPIO_OUTENSET_PIN5_Pos                5                      /*!< Output enable for pin 5 */
#define GPIO_OUTENSET_PIN6_Pos                6                      /*!< Output enable for pin 6 */
#define GPIO_OUTENSET_PIN7_Pos                7                      /*!< Output enable for pin 7 */
#define GPIO_OUTENSET_PIN8_Pos                8                      /*!< Output enable for pin 8 */
#define GPIO_OUTENSET_PIN9_Pos                9                      /*!< Output enable for pin 9 */
#define GPIO_OUTENSET_PIN10_Pos               10                     /*!< Output enable for pin 10 */
#define GPIO_OUTENSET_PIN11_Pos               11                     /*!< Output enable for pin 11 */
#define GPIO_OUTENSET_PIN12_Pos               12                     /*!< Output enable for pin 12 */
#define GPIO_OUTENSET_PIN13_Pos               13                     /*!< Output enable for pin 13 */
#define GPIO_OUTENSET_PIN14_Pos               14                     /*!< Output enable for pin 14 */
#define GPIO_OUTENSET_PIN15_Pos               15                     /*!< Output enable for pin 15 */

/* Bit field masks: */
#define GPIO_OUTENSET_PIN0_Msk                0x00000001UL           /*!< Output enable for pin 0 */
#define GPIO_OUTENSET_PIN1_Msk                0x00000002UL           /*!< Output enable for pin 1 */
#define GPIO_OUTENSET_PIN2_Msk                0x00000004UL           /*!< Output enable for pin 2 */
#define GPIO_OUTENSET_PIN3_Msk                0x00000008UL           /*!< Output enable for pin 3 */
#define GPIO_OUTENSET_PIN4_Msk                0x00000010UL           /*!< Output enable for pin 4 */
#define GPIO_OUTENSET_PIN5_Msk                0x00000020UL           /*!< Output enable for pin 5 */
#define GPIO_OUTENSET_PIN6_Msk                0x00000040UL           /*!< Output enable for pin 6 */
#define GPIO_OUTENSET_PIN7_Msk                0x00000080UL           /*!< Output enable for pin 7 */
#define GPIO_OUTENSET_PIN8_Msk                0x00000100UL           /*!< Output enable for pin 8 */
#define GPIO_OUTENSET_PIN9_Msk                0x00000200UL           /*!< Output enable for pin 9 */
#define GPIO_OUTENSET_PIN10_Msk               0x00000400UL           /*!< Output enable for pin 10 */
#define GPIO_OUTENSET_PIN11_Msk               0x00000800UL           /*!< Output enable for pin 11 */
#define GPIO_OUTENSET_PIN12_Msk               0x00001000UL           /*!< Output enable for pin 12 */
#define GPIO_OUTENSET_PIN13_Msk               0x00002000UL           /*!< Output enable for pin 13 */
#define GPIO_OUTENSET_PIN14_Msk               0x00004000UL           /*!< Output enable for pin 14 */
#define GPIO_OUTENSET_PIN15_Msk               0x00008000UL           /*!< Output enable for pin 15 */

/*--  OUTENCLR: Output disable register -----------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :16;                               /*!< Output disable */
} _GPIO_OUTENCLR_bits;

/* Bit field positions: */
#define GPIO_OUTENCLR_VAL_Pos                 0                      /*!< Output disable */

/* Bit field masks: */
#define GPIO_OUTENCLR_VAL_Msk                 0x0000FFFFUL           /*!< Output disable */

/*--  ALTFUNCSET: Alternative function enable register --------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< Alternative function enable for pin 0 */
  uint32_t PIN1                   :1;                                /*!< Alternative function enable for pin 1 */
  uint32_t PIN2                   :1;                                /*!< Alternative function enable for pin 2 */
  uint32_t PIN3                   :1;                                /*!< Alternative function enable for pin 3 */
  uint32_t PIN4                   :1;                                /*!< Alternative function enable for pin 4 */
  uint32_t PIN5                   :1;                                /*!< Alternative function enable for pin 5 */
  uint32_t PIN6                   :1;                                /*!< Alternative function enable for pin 6 */
  uint32_t PIN7                   :1;                                /*!< Alternative function enable for pin 7 */
  uint32_t PIN8                   :1;                                /*!< Alternative function enable for pin 8 */
  uint32_t PIN9                   :1;                                /*!< Alternative function enable for pin 9 */
  uint32_t PIN10                  :1;                                /*!< Alternative function enable for pin 10 */
  uint32_t PIN11                  :1;                                /*!< Alternative function enable for pin 11 */
  uint32_t PIN12                  :1;                                /*!< Alternative function enable for pin 12 */
  uint32_t PIN13                  :1;                                /*!< Alternative function enable for pin 13 */
  uint32_t PIN14                  :1;                                /*!< Alternative function enable for pin 14 */
  uint32_t PIN15                  :1;                                /*!< Alternative function enable for pin 15 */
} _GPIO_ALTFUNCSET_bits;

/* Bit field positions: */
#define GPIO_ALTFUNCSET_PIN0_Pos              0                      /*!< Alternative function enable for pin 0 */
#define GPIO_ALTFUNCSET_PIN1_Pos              1                      /*!< Alternative function enable for pin 1 */
#define GPIO_ALTFUNCSET_PIN2_Pos              2                      /*!< Alternative function enable for pin 2 */
#define GPIO_ALTFUNCSET_PIN3_Pos              3                      /*!< Alternative function enable for pin 3 */
#define GPIO_ALTFUNCSET_PIN4_Pos              4                      /*!< Alternative function enable for pin 4 */
#define GPIO_ALTFUNCSET_PIN5_Pos              5                      /*!< Alternative function enable for pin 5 */
#define GPIO_ALTFUNCSET_PIN6_Pos              6                      /*!< Alternative function enable for pin 6 */
#define GPIO_ALTFUNCSET_PIN7_Pos              7                      /*!< Alternative function enable for pin 7 */
#define GPIO_ALTFUNCSET_PIN8_Pos              8                      /*!< Alternative function enable for pin 8 */
#define GPIO_ALTFUNCSET_PIN9_Pos              9                      /*!< Alternative function enable for pin 9 */
#define GPIO_ALTFUNCSET_PIN10_Pos             10                     /*!< Alternative function enable for pin 10 */
#define GPIO_ALTFUNCSET_PIN11_Pos             11                     /*!< Alternative function enable for pin 11 */
#define GPIO_ALTFUNCSET_PIN12_Pos             12                     /*!< Alternative function enable for pin 12 */
#define GPIO_ALTFUNCSET_PIN13_Pos             13                     /*!< Alternative function enable for pin 13 */
#define GPIO_ALTFUNCSET_PIN14_Pos             14                     /*!< Alternative function enable for pin 14 */
#define GPIO_ALTFUNCSET_PIN15_Pos             15                     /*!< Alternative function enable for pin 15 */

/* Bit field masks: */
#define GPIO_ALTFUNCSET_PIN0_Msk              0x00000001UL           /*!< Alternative function enable for pin 0 */
#define GPIO_ALTFUNCSET_PIN1_Msk              0x00000002UL           /*!< Alternative function enable for pin 1 */
#define GPIO_ALTFUNCSET_PIN2_Msk              0x00000004UL           /*!< Alternative function enable for pin 2 */
#define GPIO_ALTFUNCSET_PIN3_Msk              0x00000008UL           /*!< Alternative function enable for pin 3 */
#define GPIO_ALTFUNCSET_PIN4_Msk              0x00000010UL           /*!< Alternative function enable for pin 4 */
#define GPIO_ALTFUNCSET_PIN5_Msk              0x00000020UL           /*!< Alternative function enable for pin 5 */
#define GPIO_ALTFUNCSET_PIN6_Msk              0x00000040UL           /*!< Alternative function enable for pin 6 */
#define GPIO_ALTFUNCSET_PIN7_Msk              0x00000080UL           /*!< Alternative function enable for pin 7 */
#define GPIO_ALTFUNCSET_PIN8_Msk              0x00000100UL           /*!< Alternative function enable for pin 8 */
#define GPIO_ALTFUNCSET_PIN9_Msk              0x00000200UL           /*!< Alternative function enable for pin 9 */
#define GPIO_ALTFUNCSET_PIN10_Msk             0x00000400UL           /*!< Alternative function enable for pin 10 */
#define GPIO_ALTFUNCSET_PIN11_Msk             0x00000800UL           /*!< Alternative function enable for pin 11 */
#define GPIO_ALTFUNCSET_PIN12_Msk             0x00001000UL           /*!< Alternative function enable for pin 12 */
#define GPIO_ALTFUNCSET_PIN13_Msk             0x00002000UL           /*!< Alternative function enable for pin 13 */
#define GPIO_ALTFUNCSET_PIN14_Msk             0x00004000UL           /*!< Alternative function enable for pin 14 */
#define GPIO_ALTFUNCSET_PIN15_Msk             0x00008000UL           /*!< Alternative function enable for pin 15 */

/*--  ALTFUNCCLR: Alternative function disable register -------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :16;                               /*!< Alternative function disable */
} _GPIO_ALTFUNCCLR_bits;

/* Bit field positions: */
#define GPIO_ALTFUNCCLR_VAL_Pos               0                      /*!< Alternative function disable */

/* Bit field masks: */
#define GPIO_ALTFUNCCLR_VAL_Msk               0x0000FFFFUL           /*!< Alternative function disable */

/*--  ALTFUNCNUM: Alternative function number register --------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :2;                                /*!< Select altfunc number for pin 0 */
  uint32_t PIN1                   :2;                                /*!< Select altfunc number for pin 1 */
  uint32_t PIN2                   :2;                                /*!< Select altfunc number for pin 2 */
  uint32_t PIN3                   :2;                                /*!< Select altfunc number for pin 3 */
  uint32_t PIN4                   :2;                                /*!< Select altfunc number for pin 4 */
  uint32_t PIN5                   :2;                                /*!< Select altfunc number for pin 5 */
  uint32_t PIN6                   :2;                                /*!< Select altfunc number for pin 6 */
  uint32_t PIN7                   :2;                                /*!< Select altfunc number for pin 7 */
  uint32_t PIN8                   :2;                                /*!< Select altfunc number for pin 8 */
  uint32_t PIN9                   :2;                                /*!< Select altfunc number for pin 9 */
  uint32_t PIN10                  :2;                                /*!< Select altfunc number for pin 10 */
  uint32_t PIN11                  :2;                                /*!< Select altfunc number for pin 11 */
  uint32_t PIN12                  :2;                                /*!< Select altfunc number for pin 12 */
  uint32_t PIN13                  :2;                                /*!< Select altfunc number for pin 13 */
  uint32_t PIN14                  :2;                                /*!< Select altfunc number for pin 14 */
  uint32_t PIN15                  :2;                                /*!< Select altfunc number for pin 15 */
} _GPIO_ALTFUNCNUM_bits;

/* Bit field positions: */
#define GPIO_ALTFUNCNUM_PIN0_Pos              0                      /*!< Select altfunc number for pin 0 */
#define GPIO_ALTFUNCNUM_PIN1_Pos              2                      /*!< Select altfunc number for pin 1 */
#define GPIO_ALTFUNCNUM_PIN2_Pos              4                      /*!< Select altfunc number for pin 2 */
#define GPIO_ALTFUNCNUM_PIN3_Pos              6                      /*!< Select altfunc number for pin 3 */
#define GPIO_ALTFUNCNUM_PIN4_Pos              8                      /*!< Select altfunc number for pin 4 */
#define GPIO_ALTFUNCNUM_PIN5_Pos              10                     /*!< Select altfunc number for pin 5 */
#define GPIO_ALTFUNCNUM_PIN6_Pos              12                     /*!< Select altfunc number for pin 6 */
#define GPIO_ALTFUNCNUM_PIN7_Pos              14                     /*!< Select altfunc number for pin 7 */
#define GPIO_ALTFUNCNUM_PIN8_Pos              16                     /*!< Select altfunc number for pin 8 */
#define GPIO_ALTFUNCNUM_PIN9_Pos              18                     /*!< Select altfunc number for pin 9 */
#define GPIO_ALTFUNCNUM_PIN10_Pos             20                     /*!< Select altfunc number for pin 10 */
#define GPIO_ALTFUNCNUM_PIN11_Pos             22                     /*!< Select altfunc number for pin 11 */
#define GPIO_ALTFUNCNUM_PIN12_Pos             24                     /*!< Select altfunc number for pin 12 */
#define GPIO_ALTFUNCNUM_PIN13_Pos             26                     /*!< Select altfunc number for pin 13 */
#define GPIO_ALTFUNCNUM_PIN14_Pos             28                     /*!< Select altfunc number for pin 14 */
#define GPIO_ALTFUNCNUM_PIN15_Pos             30                     /*!< Select altfunc number for pin 15 */

/* Bit field masks: */
#define GPIO_ALTFUNCNUM_PIN0_Msk              0x00000003UL           /*!< Select altfunc number for pin 0 */
#define GPIO_ALTFUNCNUM_PIN1_Msk              0x0000000CUL           /*!< Select altfunc number for pin 1 */
#define GPIO_ALTFUNCNUM_PIN2_Msk              0x00000030UL           /*!< Select altfunc number for pin 2 */
#define GPIO_ALTFUNCNUM_PIN3_Msk              0x000000C0UL           /*!< Select altfunc number for pin 3 */
#define GPIO_ALTFUNCNUM_PIN4_Msk              0x00000300UL           /*!< Select altfunc number for pin 4 */
#define GPIO_ALTFUNCNUM_PIN5_Msk              0x00000C00UL           /*!< Select altfunc number for pin 5 */
#define GPIO_ALTFUNCNUM_PIN6_Msk              0x00003000UL           /*!< Select altfunc number for pin 6 */
#define GPIO_ALTFUNCNUM_PIN7_Msk              0x0000C000UL           /*!< Select altfunc number for pin 7 */
#define GPIO_ALTFUNCNUM_PIN8_Msk              0x00030000UL           /*!< Select altfunc number for pin 8 */
#define GPIO_ALTFUNCNUM_PIN9_Msk              0x000C0000UL           /*!< Select altfunc number for pin 9 */
#define GPIO_ALTFUNCNUM_PIN10_Msk             0x00300000UL           /*!< Select altfunc number for pin 10 */
#define GPIO_ALTFUNCNUM_PIN11_Msk             0x00C00000UL           /*!< Select altfunc number for pin 11 */
#define GPIO_ALTFUNCNUM_PIN12_Msk             0x03000000UL           /*!< Select altfunc number for pin 12 */
#define GPIO_ALTFUNCNUM_PIN13_Msk             0x0C000000UL           /*!< Select altfunc number for pin 13 */
#define GPIO_ALTFUNCNUM_PIN14_Msk             0x30000000UL           /*!< Select altfunc number for pin 14 */
#define GPIO_ALTFUNCNUM_PIN15_Msk             0xC0000000UL           /*!< Select altfunc number for pin 15 */

/* Bit field enums: */
typedef enum {
  GPIO_ALTFUNCNUM_PIN0_Disable               = 0x0UL,                /*!< Altfunc disabled */
  GPIO_ALTFUNCNUM_PIN0_AF1                   = 0x1UL,                /*!< Altfunc 1 enable */
  GPIO_ALTFUNCNUM_PIN0_AF2                   = 0x2UL,                /*!< Altfunc 2 enable */
  GPIO_ALTFUNCNUM_PIN0_AF3                   = 0x3UL,                /*!< Altfunc 3 enable */
} GPIO_ALTFUNCNUM_PIN0_Enum;

typedef enum {
  GPIO_ALTFUNCNUM_PIN1_Disable               = 0x0UL,                /*!< Altfunc disabled */
  GPIO_ALTFUNCNUM_PIN1_AF1                   = 0x1UL,                /*!< Altfunc 1 enable */
  GPIO_ALTFUNCNUM_PIN1_AF2                   = 0x2UL,                /*!< Altfunc 2 enable */
  GPIO_ALTFUNCNUM_PIN1_AF3                   = 0x3UL,                /*!< Altfunc 3 enable */
} GPIO_ALTFUNCNUM_PIN1_Enum;

typedef enum {
  GPIO_ALTFUNCNUM_PIN2_Disable               = 0x0UL,                /*!< Altfunc disabled */
  GPIO_ALTFUNCNUM_PIN2_AF1                   = 0x1UL,                /*!< Altfunc 1 enable */
  GPIO_ALTFUNCNUM_PIN2_AF2                   = 0x2UL,                /*!< Altfunc 2 enable */
  GPIO_ALTFUNCNUM_PIN2_AF3                   = 0x3UL,                /*!< Altfunc 3 enable */
} GPIO_ALTFUNCNUM_PIN2_Enum;

typedef enum {
  GPIO_ALTFUNCNUM_PIN3_Disable               = 0x0UL,                /*!< Altfunc disabled */
  GPIO_ALTFUNCNUM_PIN3_AF1                   = 0x1UL,                /*!< Altfunc 1 enable */
  GPIO_ALTFUNCNUM_PIN3_AF2                   = 0x2UL,                /*!< Altfunc 2 enable */
  GPIO_ALTFUNCNUM_PIN3_AF3                   = 0x3UL,                /*!< Altfunc 3 enable */
} GPIO_ALTFUNCNUM_PIN3_Enum;

typedef enum {
  GPIO_ALTFUNCNUM_PIN4_Disable               = 0x0UL,                /*!< Altfunc disabled */
  GPIO_ALTFUNCNUM_PIN4_AF1                   = 0x1UL,                /*!< Altfunc 1 enable */
  GPIO_ALTFUNCNUM_PIN4_AF2                   = 0x2UL,                /*!< Altfunc 2 enable */
  GPIO_ALTFUNCNUM_PIN4_AF3                   = 0x3UL,                /*!< Altfunc 3 enable */
} GPIO_ALTFUNCNUM_PIN4_Enum;

typedef enum {
  GPIO_ALTFUNCNUM_PIN5_Disable               = 0x0UL,                /*!< Altfunc disabled */
  GPIO_ALTFUNCNUM_PIN5_AF1                   = 0x1UL,                /*!< Altfunc 1 enable */
  GPIO_ALTFUNCNUM_PIN5_AF2                   = 0x2UL,                /*!< Altfunc 2 enable */
  GPIO_ALTFUNCNUM_PIN5_AF3                   = 0x3UL,                /*!< Altfunc 3 enable */
} GPIO_ALTFUNCNUM_PIN5_Enum;

typedef enum {
  GPIO_ALTFUNCNUM_PIN6_Disable               = 0x0UL,                /*!< Altfunc disabled */
  GPIO_ALTFUNCNUM_PIN6_AF1                   = 0x1UL,                /*!< Altfunc 1 enable */
  GPIO_ALTFUNCNUM_PIN6_AF2                   = 0x2UL,                /*!< Altfunc 2 enable */
  GPIO_ALTFUNCNUM_PIN6_AF3                   = 0x3UL,                /*!< Altfunc 3 enable */
} GPIO_ALTFUNCNUM_PIN6_Enum;

typedef enum {
  GPIO_ALTFUNCNUM_PIN7_Disable               = 0x0UL,                /*!< Altfunc disabled */
  GPIO_ALTFUNCNUM_PIN7_AF1                   = 0x1UL,                /*!< Altfunc 1 enable */
  GPIO_ALTFUNCNUM_PIN7_AF2                   = 0x2UL,                /*!< Altfunc 2 enable */
  GPIO_ALTFUNCNUM_PIN7_AF3                   = 0x3UL,                /*!< Altfunc 3 enable */
} GPIO_ALTFUNCNUM_PIN7_Enum;

typedef enum {
  GPIO_ALTFUNCNUM_PIN8_Disable               = 0x0UL,                /*!< Altfunc disabled */
  GPIO_ALTFUNCNUM_PIN8_AF1                   = 0x1UL,                /*!< Altfunc 1 enable */
  GPIO_ALTFUNCNUM_PIN8_AF2                   = 0x2UL,                /*!< Altfunc 2 enable */
  GPIO_ALTFUNCNUM_PIN8_AF3                   = 0x3UL,                /*!< Altfunc 3 enable */
} GPIO_ALTFUNCNUM_PIN8_Enum;

typedef enum {
  GPIO_ALTFUNCNUM_PIN9_Disable               = 0x0UL,                /*!< Altfunc disabled */
  GPIO_ALTFUNCNUM_PIN9_AF1                   = 0x1UL,                /*!< Altfunc 1 enable */
  GPIO_ALTFUNCNUM_PIN9_AF2                   = 0x2UL,                /*!< Altfunc 2 enable */
  GPIO_ALTFUNCNUM_PIN9_AF3                   = 0x3UL,                /*!< Altfunc 3 enable */
} GPIO_ALTFUNCNUM_PIN9_Enum;

typedef enum {
  GPIO_ALTFUNCNUM_PIN10_Disable              = 0x0UL,                /*!< Altfunc disabled */
  GPIO_ALTFUNCNUM_PIN10_AF1                  = 0x1UL,                /*!< Altfunc 1 enable */
  GPIO_ALTFUNCNUM_PIN10_AF2                  = 0x2UL,                /*!< Altfunc 2 enable */
  GPIO_ALTFUNCNUM_PIN10_AF3                  = 0x3UL,                /*!< Altfunc 3 enable */
} GPIO_ALTFUNCNUM_PIN10_Enum;

typedef enum {
  GPIO_ALTFUNCNUM_PIN11_Disable              = 0x0UL,                /*!< Altfunc disabled */
  GPIO_ALTFUNCNUM_PIN11_AF1                  = 0x1UL,                /*!< Altfunc 1 enable */
  GPIO_ALTFUNCNUM_PIN11_AF2                  = 0x2UL,                /*!< Altfunc 2 enable */
  GPIO_ALTFUNCNUM_PIN11_AF3                  = 0x3UL,                /*!< Altfunc 3 enable */
} GPIO_ALTFUNCNUM_PIN11_Enum;

typedef enum {
  GPIO_ALTFUNCNUM_PIN12_Disable              = 0x0UL,                /*!< Altfunc disabled */
  GPIO_ALTFUNCNUM_PIN12_AF1                  = 0x1UL,                /*!< Altfunc 1 enable */
  GPIO_ALTFUNCNUM_PIN12_AF2                  = 0x2UL,                /*!< Altfunc 2 enable */
  GPIO_ALTFUNCNUM_PIN12_AF3                  = 0x3UL,                /*!< Altfunc 3 enable */
} GPIO_ALTFUNCNUM_PIN12_Enum;

typedef enum {
  GPIO_ALTFUNCNUM_PIN13_Disable              = 0x0UL,                /*!< Altfunc disabled */
  GPIO_ALTFUNCNUM_PIN13_AF1                  = 0x1UL,                /*!< Altfunc 1 enable */
  GPIO_ALTFUNCNUM_PIN13_AF2                  = 0x2UL,                /*!< Altfunc 2 enable */
  GPIO_ALTFUNCNUM_PIN13_AF3                  = 0x3UL,                /*!< Altfunc 3 enable */
} GPIO_ALTFUNCNUM_PIN13_Enum;

typedef enum {
  GPIO_ALTFUNCNUM_PIN14_Disable              = 0x0UL,                /*!< Altfunc disabled */
  GPIO_ALTFUNCNUM_PIN14_AF1                  = 0x1UL,                /*!< Altfunc 1 enable */
  GPIO_ALTFUNCNUM_PIN14_AF2                  = 0x2UL,                /*!< Altfunc 2 enable */
  GPIO_ALTFUNCNUM_PIN14_AF3                  = 0x3UL,                /*!< Altfunc 3 enable */
} GPIO_ALTFUNCNUM_PIN14_Enum;

typedef enum {
  GPIO_ALTFUNCNUM_PIN15_Disable              = 0x0UL,                /*!< Altfunc disabled */
  GPIO_ALTFUNCNUM_PIN15_AF1                  = 0x1UL,                /*!< Altfunc 1 enable */
  GPIO_ALTFUNCNUM_PIN15_AF2                  = 0x2UL,                /*!< Altfunc 2 enable */
  GPIO_ALTFUNCNUM_PIN15_AF3                  = 0x3UL,                /*!< Altfunc 3 enable */
} GPIO_ALTFUNCNUM_PIN15_Enum;

/*--  SYNCSET: Additional double flip-flop syncronization enable register -------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< Additional double flip-flop syncronization buffer enable for pin 0 */
  uint32_t PIN1                   :1;                                /*!< Additional double flip-flop syncronization buffer enable for pin 1 */
  uint32_t PIN2                   :1;                                /*!< Additional double flip-flop syncronization buffer enable for pin 2 */
  uint32_t PIN3                   :1;                                /*!< Additional double flip-flop syncronization buffer enable for pin 3 */
  uint32_t PIN4                   :1;                                /*!< Additional double flip-flop syncronization buffer enable for pin 4 */
  uint32_t PIN5                   :1;                                /*!< Additional double flip-flop syncronization buffer enable for pin 5 */
  uint32_t PIN6                   :1;                                /*!< Additional double flip-flop syncronization buffer enable for pin 6 */
  uint32_t PIN7                   :1;                                /*!< Additional double flip-flop syncronization buffer enable for pin 7 */
  uint32_t PIN8                   :1;                                /*!< Additional double flip-flop syncronization buffer enable for pin 8 */
  uint32_t PIN9                   :1;                                /*!< Additional double flip-flop syncronization buffer enable for pin 9 */
  uint32_t PIN10                  :1;                                /*!< Additional double flip-flop syncronization buffer enable for pin 10 */
  uint32_t PIN11                  :1;                                /*!< Additional double flip-flop syncronization buffer enable for pin 11 */
  uint32_t PIN12                  :1;                                /*!< Additional double flip-flop syncronization buffer enable for pin 12 */
  uint32_t PIN13                  :1;                                /*!< Additional double flip-flop syncronization buffer enable for pin 13 */
  uint32_t PIN14                  :1;                                /*!< Additional double flip-flop syncronization buffer enable for pin 14 */
  uint32_t PIN15                  :1;                                /*!< Additional double flip-flop syncronization buffer enable for pin 15 */
} _GPIO_SYNCSET_bits;

/* Bit field positions: */
#define GPIO_SYNCSET_PIN0_Pos                 0                      /*!< Additional double flip-flop syncronization buffer enable for pin 0 */
#define GPIO_SYNCSET_PIN1_Pos                 1                      /*!< Additional double flip-flop syncronization buffer enable for pin 1 */
#define GPIO_SYNCSET_PIN2_Pos                 2                      /*!< Additional double flip-flop syncronization buffer enable for pin 2 */
#define GPIO_SYNCSET_PIN3_Pos                 3                      /*!< Additional double flip-flop syncronization buffer enable for pin 3 */
#define GPIO_SYNCSET_PIN4_Pos                 4                      /*!< Additional double flip-flop syncronization buffer enable for pin 4 */
#define GPIO_SYNCSET_PIN5_Pos                 5                      /*!< Additional double flip-flop syncronization buffer enable for pin 5 */
#define GPIO_SYNCSET_PIN6_Pos                 6                      /*!< Additional double flip-flop syncronization buffer enable for pin 6 */
#define GPIO_SYNCSET_PIN7_Pos                 7                      /*!< Additional double flip-flop syncronization buffer enable for pin 7 */
#define GPIO_SYNCSET_PIN8_Pos                 8                      /*!< Additional double flip-flop syncronization buffer enable for pin 8 */
#define GPIO_SYNCSET_PIN9_Pos                 9                      /*!< Additional double flip-flop syncronization buffer enable for pin 9 */
#define GPIO_SYNCSET_PIN10_Pos                10                     /*!< Additional double flip-flop syncronization buffer enable for pin 10 */
#define GPIO_SYNCSET_PIN11_Pos                11                     /*!< Additional double flip-flop syncronization buffer enable for pin 11 */
#define GPIO_SYNCSET_PIN12_Pos                12                     /*!< Additional double flip-flop syncronization buffer enable for pin 12 */
#define GPIO_SYNCSET_PIN13_Pos                13                     /*!< Additional double flip-flop syncronization buffer enable for pin 13 */
#define GPIO_SYNCSET_PIN14_Pos                14                     /*!< Additional double flip-flop syncronization buffer enable for pin 14 */
#define GPIO_SYNCSET_PIN15_Pos                15                     /*!< Additional double flip-flop syncronization buffer enable for pin 15 */

/* Bit field masks: */
#define GPIO_SYNCSET_PIN0_Msk                 0x00000001UL           /*!< Additional double flip-flop syncronization buffer enable for pin 0 */
#define GPIO_SYNCSET_PIN1_Msk                 0x00000002UL           /*!< Additional double flip-flop syncronization buffer enable for pin 1 */
#define GPIO_SYNCSET_PIN2_Msk                 0x00000004UL           /*!< Additional double flip-flop syncronization buffer enable for pin 2 */
#define GPIO_SYNCSET_PIN3_Msk                 0x00000008UL           /*!< Additional double flip-flop syncronization buffer enable for pin 3 */
#define GPIO_SYNCSET_PIN4_Msk                 0x00000010UL           /*!< Additional double flip-flop syncronization buffer enable for pin 4 */
#define GPIO_SYNCSET_PIN5_Msk                 0x00000020UL           /*!< Additional double flip-flop syncronization buffer enable for pin 5 */
#define GPIO_SYNCSET_PIN6_Msk                 0x00000040UL           /*!< Additional double flip-flop syncronization buffer enable for pin 6 */
#define GPIO_SYNCSET_PIN7_Msk                 0x00000080UL           /*!< Additional double flip-flop syncronization buffer enable for pin 7 */
#define GPIO_SYNCSET_PIN8_Msk                 0x00000100UL           /*!< Additional double flip-flop syncronization buffer enable for pin 8 */
#define GPIO_SYNCSET_PIN9_Msk                 0x00000200UL           /*!< Additional double flip-flop syncronization buffer enable for pin 9 */
#define GPIO_SYNCSET_PIN10_Msk                0x00000400UL           /*!< Additional double flip-flop syncronization buffer enable for pin 10 */
#define GPIO_SYNCSET_PIN11_Msk                0x00000800UL           /*!< Additional double flip-flop syncronization buffer enable for pin 11 */
#define GPIO_SYNCSET_PIN12_Msk                0x00001000UL           /*!< Additional double flip-flop syncronization buffer enable for pin 12 */
#define GPIO_SYNCSET_PIN13_Msk                0x00002000UL           /*!< Additional double flip-flop syncronization buffer enable for pin 13 */
#define GPIO_SYNCSET_PIN14_Msk                0x00004000UL           /*!< Additional double flip-flop syncronization buffer enable for pin 14 */
#define GPIO_SYNCSET_PIN15_Msk                0x00008000UL           /*!< Additional double flip-flop syncronization buffer enable for pin 15 */

/*--  SYNCCLR: Additional double flip-flop syncronization disable register ------------------------------------*/
typedef struct {
  uint32_t VAL                    :16;                               /*!< Additional double flip-flop syncronization disable */
} _GPIO_SYNCCLR_bits;

/* Bit field positions: */
#define GPIO_SYNCCLR_VAL_Pos                  0                      /*!< Additional double flip-flop syncronization disable */

/* Bit field masks: */
#define GPIO_SYNCCLR_VAL_Msk                  0x0000FFFFUL           /*!< Additional double flip-flop syncronization disable */

/*--  QUALSET: Qualifier enable register ----------------------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< Qualifier enable for pin 0 */
  uint32_t PIN1                   :1;                                /*!< Qualifier enable for pin 1 */
  uint32_t PIN2                   :1;                                /*!< Qualifier enable for pin 2 */
  uint32_t PIN3                   :1;                                /*!< Qualifier enable for pin 3 */
  uint32_t PIN4                   :1;                                /*!< Qualifier enable for pin 4 */
  uint32_t PIN5                   :1;                                /*!< Qualifier enable for pin 5 */
  uint32_t PIN6                   :1;                                /*!< Qualifier enable for pin 6 */
  uint32_t PIN7                   :1;                                /*!< Qualifier enable for pin 7 */
  uint32_t PIN8                   :1;                                /*!< Qualifier enable for pin 8 */
  uint32_t PIN9                   :1;                                /*!< Qualifier enable for pin 9 */
  uint32_t PIN10                  :1;                                /*!< Qualifier enable for pin 10 */
  uint32_t PIN11                  :1;                                /*!< Qualifier enable for pin 11 */
  uint32_t PIN12                  :1;                                /*!< Qualifier enable for pin 12 */
  uint32_t PIN13                  :1;                                /*!< Qualifier enable for pin 13 */
  uint32_t PIN14                  :1;                                /*!< Qualifier enable for pin 14 */
  uint32_t PIN15                  :1;                                /*!< Qualifier enable for pin 15 */
} _GPIO_QUALSET_bits;

/* Bit field positions: */
#define GPIO_QUALSET_PIN0_Pos                 0                      /*!< Qualifier enable for pin 0 */
#define GPIO_QUALSET_PIN1_Pos                 1                      /*!< Qualifier enable for pin 1 */
#define GPIO_QUALSET_PIN2_Pos                 2                      /*!< Qualifier enable for pin 2 */
#define GPIO_QUALSET_PIN3_Pos                 3                      /*!< Qualifier enable for pin 3 */
#define GPIO_QUALSET_PIN4_Pos                 4                      /*!< Qualifier enable for pin 4 */
#define GPIO_QUALSET_PIN5_Pos                 5                      /*!< Qualifier enable for pin 5 */
#define GPIO_QUALSET_PIN6_Pos                 6                      /*!< Qualifier enable for pin 6 */
#define GPIO_QUALSET_PIN7_Pos                 7                      /*!< Qualifier enable for pin 7 */
#define GPIO_QUALSET_PIN8_Pos                 8                      /*!< Qualifier enable for pin 8 */
#define GPIO_QUALSET_PIN9_Pos                 9                      /*!< Qualifier enable for pin 9 */
#define GPIO_QUALSET_PIN10_Pos                10                     /*!< Qualifier enable for pin 10 */
#define GPIO_QUALSET_PIN11_Pos                11                     /*!< Qualifier enable for pin 11 */
#define GPIO_QUALSET_PIN12_Pos                12                     /*!< Qualifier enable for pin 12 */
#define GPIO_QUALSET_PIN13_Pos                13                     /*!< Qualifier enable for pin 13 */
#define GPIO_QUALSET_PIN14_Pos                14                     /*!< Qualifier enable for pin 14 */
#define GPIO_QUALSET_PIN15_Pos                15                     /*!< Qualifier enable for pin 15 */

/* Bit field masks: */
#define GPIO_QUALSET_PIN0_Msk                 0x00000001UL           /*!< Qualifier enable for pin 0 */
#define GPIO_QUALSET_PIN1_Msk                 0x00000002UL           /*!< Qualifier enable for pin 1 */
#define GPIO_QUALSET_PIN2_Msk                 0x00000004UL           /*!< Qualifier enable for pin 2 */
#define GPIO_QUALSET_PIN3_Msk                 0x00000008UL           /*!< Qualifier enable for pin 3 */
#define GPIO_QUALSET_PIN4_Msk                 0x00000010UL           /*!< Qualifier enable for pin 4 */
#define GPIO_QUALSET_PIN5_Msk                 0x00000020UL           /*!< Qualifier enable for pin 5 */
#define GPIO_QUALSET_PIN6_Msk                 0x00000040UL           /*!< Qualifier enable for pin 6 */
#define GPIO_QUALSET_PIN7_Msk                 0x00000080UL           /*!< Qualifier enable for pin 7 */
#define GPIO_QUALSET_PIN8_Msk                 0x00000100UL           /*!< Qualifier enable for pin 8 */
#define GPIO_QUALSET_PIN9_Msk                 0x00000200UL           /*!< Qualifier enable for pin 9 */
#define GPIO_QUALSET_PIN10_Msk                0x00000400UL           /*!< Qualifier enable for pin 10 */
#define GPIO_QUALSET_PIN11_Msk                0x00000800UL           /*!< Qualifier enable for pin 11 */
#define GPIO_QUALSET_PIN12_Msk                0x00001000UL           /*!< Qualifier enable for pin 12 */
#define GPIO_QUALSET_PIN13_Msk                0x00002000UL           /*!< Qualifier enable for pin 13 */
#define GPIO_QUALSET_PIN14_Msk                0x00004000UL           /*!< Qualifier enable for pin 14 */
#define GPIO_QUALSET_PIN15_Msk                0x00008000UL           /*!< Qualifier enable for pin 15 */

/*--  QUALCLR: Qualifier disable register ---------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :16;                               /*!< Qualifier disable */
} _GPIO_QUALCLR_bits;

/* Bit field positions: */
#define GPIO_QUALCLR_VAL_Pos                  0                      /*!< Qualifier disable */

/* Bit field masks: */
#define GPIO_QUALCLR_VAL_Msk                  0x0000FFFFUL           /*!< Qualifier disable */

/*--  QUALMODESET: Qualifier mode set register ----------------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< Qualifier mode set for pin 0 */
  uint32_t PIN1                   :1;                                /*!< Qualifier mode set for pin 1 */
  uint32_t PIN2                   :1;                                /*!< Qualifier mode set for pin 2 */
  uint32_t PIN3                   :1;                                /*!< Qualifier mode set for pin 3 */
  uint32_t PIN4                   :1;                                /*!< Qualifier mode set for pin 4 */
  uint32_t PIN5                   :1;                                /*!< Qualifier mode set for pin 5 */
  uint32_t PIN6                   :1;                                /*!< Qualifier mode set for pin 6 */
  uint32_t PIN7                   :1;                                /*!< Qualifier mode set for pin 7 */
  uint32_t PIN8                   :1;                                /*!< Qualifier mode set for pin 8 */
  uint32_t PIN9                   :1;                                /*!< Qualifier mode set for pin 9 */
  uint32_t PIN10                  :1;                                /*!< Qualifier mode set for pin 10 */
  uint32_t PIN11                  :1;                                /*!< Qualifier mode set for pin 11 */
  uint32_t PIN12                  :1;                                /*!< Qualifier mode set for pin 12 */
  uint32_t PIN13                  :1;                                /*!< Qualifier mode set for pin 13 */
  uint32_t PIN14                  :1;                                /*!< Qualifier mode set for pin 14 */
  uint32_t PIN15                  :1;                                /*!< Qualifier mode set for pin 15 */
} _GPIO_QUALMODESET_bits;

/* Bit field positions: */
#define GPIO_QUALMODESET_PIN0_Pos             0                      /*!< Qualifier mode set for pin 0 */
#define GPIO_QUALMODESET_PIN1_Pos             1                      /*!< Qualifier mode set for pin 1 */
#define GPIO_QUALMODESET_PIN2_Pos             2                      /*!< Qualifier mode set for pin 2 */
#define GPIO_QUALMODESET_PIN3_Pos             3                      /*!< Qualifier mode set for pin 3 */
#define GPIO_QUALMODESET_PIN4_Pos             4                      /*!< Qualifier mode set for pin 4 */
#define GPIO_QUALMODESET_PIN5_Pos             5                      /*!< Qualifier mode set for pin 5 */
#define GPIO_QUALMODESET_PIN6_Pos             6                      /*!< Qualifier mode set for pin 6 */
#define GPIO_QUALMODESET_PIN7_Pos             7                      /*!< Qualifier mode set for pin 7 */
#define GPIO_QUALMODESET_PIN8_Pos             8                      /*!< Qualifier mode set for pin 8 */
#define GPIO_QUALMODESET_PIN9_Pos             9                      /*!< Qualifier mode set for pin 9 */
#define GPIO_QUALMODESET_PIN10_Pos            10                     /*!< Qualifier mode set for pin 10 */
#define GPIO_QUALMODESET_PIN11_Pos            11                     /*!< Qualifier mode set for pin 11 */
#define GPIO_QUALMODESET_PIN12_Pos            12                     /*!< Qualifier mode set for pin 12 */
#define GPIO_QUALMODESET_PIN13_Pos            13                     /*!< Qualifier mode set for pin 13 */
#define GPIO_QUALMODESET_PIN14_Pos            14                     /*!< Qualifier mode set for pin 14 */
#define GPIO_QUALMODESET_PIN15_Pos            15                     /*!< Qualifier mode set for pin 15 */

/* Bit field masks: */
#define GPIO_QUALMODESET_PIN0_Msk             0x00000001UL           /*!< Qualifier mode set for pin 0 */
#define GPIO_QUALMODESET_PIN1_Msk             0x00000002UL           /*!< Qualifier mode set for pin 1 */
#define GPIO_QUALMODESET_PIN2_Msk             0x00000004UL           /*!< Qualifier mode set for pin 2 */
#define GPIO_QUALMODESET_PIN3_Msk             0x00000008UL           /*!< Qualifier mode set for pin 3 */
#define GPIO_QUALMODESET_PIN4_Msk             0x00000010UL           /*!< Qualifier mode set for pin 4 */
#define GPIO_QUALMODESET_PIN5_Msk             0x00000020UL           /*!< Qualifier mode set for pin 5 */
#define GPIO_QUALMODESET_PIN6_Msk             0x00000040UL           /*!< Qualifier mode set for pin 6 */
#define GPIO_QUALMODESET_PIN7_Msk             0x00000080UL           /*!< Qualifier mode set for pin 7 */
#define GPIO_QUALMODESET_PIN8_Msk             0x00000100UL           /*!< Qualifier mode set for pin 8 */
#define GPIO_QUALMODESET_PIN9_Msk             0x00000200UL           /*!< Qualifier mode set for pin 9 */
#define GPIO_QUALMODESET_PIN10_Msk            0x00000400UL           /*!< Qualifier mode set for pin 10 */
#define GPIO_QUALMODESET_PIN11_Msk            0x00000800UL           /*!< Qualifier mode set for pin 11 */
#define GPIO_QUALMODESET_PIN12_Msk            0x00001000UL           /*!< Qualifier mode set for pin 12 */
#define GPIO_QUALMODESET_PIN13_Msk            0x00002000UL           /*!< Qualifier mode set for pin 13 */
#define GPIO_QUALMODESET_PIN14_Msk            0x00004000UL           /*!< Qualifier mode set for pin 14 */
#define GPIO_QUALMODESET_PIN15_Msk            0x00008000UL           /*!< Qualifier mode set for pin 15 */

/*--  QUALMODECLR: Qualifier mode clear register --------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :16;                               /*!< Qualifier mode clear */
} _GPIO_QUALMODECLR_bits;

/* Bit field positions: */
#define GPIO_QUALMODECLR_VAL_Pos              0                      /*!< Qualifier mode clear */

/* Bit field masks: */
#define GPIO_QUALMODECLR_VAL_Msk              0x0000FFFFUL           /*!< Qualifier mode clear */

/*--  QUALSAMPLE: Qualifier sample period register ------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :20;                               /*!< Qualifier sample period */
} _GPIO_QUALSAMPLE_bits;

/* Bit field positions: */
#define GPIO_QUALSAMPLE_VAL_Pos               0                      /*!< Qualifier sample period */

/* Bit field masks: */
#define GPIO_QUALSAMPLE_VAL_Msk               0x000FFFFFUL           /*!< Qualifier sample period */

/*--  INTENSET: Interrupt enable register ---------------------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< Interrupt enable for pin 0 */
  uint32_t PIN1                   :1;                                /*!< Interrupt enable for pin 1 */
  uint32_t PIN2                   :1;                                /*!< Interrupt enable for pin 2 */
  uint32_t PIN3                   :1;                                /*!< Interrupt enable for pin 3 */
  uint32_t PIN4                   :1;                                /*!< Interrupt enable for pin 4 */
  uint32_t PIN5                   :1;                                /*!< Interrupt enable for pin 5 */
  uint32_t PIN6                   :1;                                /*!< Interrupt enable for pin 6 */
  uint32_t PIN7                   :1;                                /*!< Interrupt enable for pin 7 */
  uint32_t PIN8                   :1;                                /*!< Interrupt enable for pin 8 */
  uint32_t PIN9                   :1;                                /*!< Interrupt enable for pin 9 */
  uint32_t PIN10                  :1;                                /*!< Interrupt enable for pin 10 */
  uint32_t PIN11                  :1;                                /*!< Interrupt enable for pin 11 */
  uint32_t PIN12                  :1;                                /*!< Interrupt enable for pin 12 */
  uint32_t PIN13                  :1;                                /*!< Interrupt enable for pin 13 */
  uint32_t PIN14                  :1;                                /*!< Interrupt enable for pin 14 */
  uint32_t PIN15                  :1;                                /*!< Interrupt enable for pin 15 */
} _GPIO_INTENSET_bits;

/* Bit field positions: */
#define GPIO_INTENSET_PIN0_Pos                0                      /*!< Interrupt enable for pin 0 */
#define GPIO_INTENSET_PIN1_Pos                1                      /*!< Interrupt enable for pin 1 */
#define GPIO_INTENSET_PIN2_Pos                2                      /*!< Interrupt enable for pin 2 */
#define GPIO_INTENSET_PIN3_Pos                3                      /*!< Interrupt enable for pin 3 */
#define GPIO_INTENSET_PIN4_Pos                4                      /*!< Interrupt enable for pin 4 */
#define GPIO_INTENSET_PIN5_Pos                5                      /*!< Interrupt enable for pin 5 */
#define GPIO_INTENSET_PIN6_Pos                6                      /*!< Interrupt enable for pin 6 */
#define GPIO_INTENSET_PIN7_Pos                7                      /*!< Interrupt enable for pin 7 */
#define GPIO_INTENSET_PIN8_Pos                8                      /*!< Interrupt enable for pin 8 */
#define GPIO_INTENSET_PIN9_Pos                9                      /*!< Interrupt enable for pin 9 */
#define GPIO_INTENSET_PIN10_Pos               10                     /*!< Interrupt enable for pin 10 */
#define GPIO_INTENSET_PIN11_Pos               11                     /*!< Interrupt enable for pin 11 */
#define GPIO_INTENSET_PIN12_Pos               12                     /*!< Interrupt enable for pin 12 */
#define GPIO_INTENSET_PIN13_Pos               13                     /*!< Interrupt enable for pin 13 */
#define GPIO_INTENSET_PIN14_Pos               14                     /*!< Interrupt enable for pin 14 */
#define GPIO_INTENSET_PIN15_Pos               15                     /*!< Interrupt enable for pin 15 */

/* Bit field masks: */
#define GPIO_INTENSET_PIN0_Msk                0x00000001UL           /*!< Interrupt enable for pin 0 */
#define GPIO_INTENSET_PIN1_Msk                0x00000002UL           /*!< Interrupt enable for pin 1 */
#define GPIO_INTENSET_PIN2_Msk                0x00000004UL           /*!< Interrupt enable for pin 2 */
#define GPIO_INTENSET_PIN3_Msk                0x00000008UL           /*!< Interrupt enable for pin 3 */
#define GPIO_INTENSET_PIN4_Msk                0x00000010UL           /*!< Interrupt enable for pin 4 */
#define GPIO_INTENSET_PIN5_Msk                0x00000020UL           /*!< Interrupt enable for pin 5 */
#define GPIO_INTENSET_PIN6_Msk                0x00000040UL           /*!< Interrupt enable for pin 6 */
#define GPIO_INTENSET_PIN7_Msk                0x00000080UL           /*!< Interrupt enable for pin 7 */
#define GPIO_INTENSET_PIN8_Msk                0x00000100UL           /*!< Interrupt enable for pin 8 */
#define GPIO_INTENSET_PIN9_Msk                0x00000200UL           /*!< Interrupt enable for pin 9 */
#define GPIO_INTENSET_PIN10_Msk               0x00000400UL           /*!< Interrupt enable for pin 10 */
#define GPIO_INTENSET_PIN11_Msk               0x00000800UL           /*!< Interrupt enable for pin 11 */
#define GPIO_INTENSET_PIN12_Msk               0x00001000UL           /*!< Interrupt enable for pin 12 */
#define GPIO_INTENSET_PIN13_Msk               0x00002000UL           /*!< Interrupt enable for pin 13 */
#define GPIO_INTENSET_PIN14_Msk               0x00004000UL           /*!< Interrupt enable for pin 14 */
#define GPIO_INTENSET_PIN15_Msk               0x00008000UL           /*!< Interrupt enable for pin 15 */

/*--  INTENCLR: Interrupt disable register --------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :16;                               /*!< Interrupt disable */
} _GPIO_INTENCLR_bits;

/* Bit field positions: */
#define GPIO_INTENCLR_VAL_Pos                 0                      /*!< Interrupt disable */

/* Bit field masks: */
#define GPIO_INTENCLR_VAL_Msk                 0x0000FFFFUL           /*!< Interrupt disable */

/*--  INTTYPESET: Interrupt type set register -----------------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< Interrupt type set for pin 0 */
  uint32_t PIN1                   :1;                                /*!< Interrupt type set for pin 1 */
  uint32_t PIN2                   :1;                                /*!< Interrupt type set for pin 2 */
  uint32_t PIN3                   :1;                                /*!< Interrupt type set for pin 3 */
  uint32_t PIN4                   :1;                                /*!< Interrupt type set for pin 4 */
  uint32_t PIN5                   :1;                                /*!< Interrupt type set for pin 5 */
  uint32_t PIN6                   :1;                                /*!< Interrupt type set for pin 6 */
  uint32_t PIN7                   :1;                                /*!< Interrupt type set for pin 7 */
  uint32_t PIN8                   :1;                                /*!< Interrupt type set for pin 8 */
  uint32_t PIN9                   :1;                                /*!< Interrupt type set for pin 9 */
  uint32_t PIN10                  :1;                                /*!< Interrupt type set for pin 10 */
  uint32_t PIN11                  :1;                                /*!< Interrupt type set for pin 11 */
  uint32_t PIN12                  :1;                                /*!< Interrupt type set for pin 12 */
  uint32_t PIN13                  :1;                                /*!< Interrupt type set for pin 13 */
  uint32_t PIN14                  :1;                                /*!< Interrupt type set for pin 14 */
  uint32_t PIN15                  :1;                                /*!< Interrupt type set for pin 15 */
} _GPIO_INTTYPESET_bits;

/* Bit field positions: */
#define GPIO_INTTYPESET_PIN0_Pos              0                      /*!< Interrupt type set for pin 0 */
#define GPIO_INTTYPESET_PIN1_Pos              1                      /*!< Interrupt type set for pin 1 */
#define GPIO_INTTYPESET_PIN2_Pos              2                      /*!< Interrupt type set for pin 2 */
#define GPIO_INTTYPESET_PIN3_Pos              3                      /*!< Interrupt type set for pin 3 */
#define GPIO_INTTYPESET_PIN4_Pos              4                      /*!< Interrupt type set for pin 4 */
#define GPIO_INTTYPESET_PIN5_Pos              5                      /*!< Interrupt type set for pin 5 */
#define GPIO_INTTYPESET_PIN6_Pos              6                      /*!< Interrupt type set for pin 6 */
#define GPIO_INTTYPESET_PIN7_Pos              7                      /*!< Interrupt type set for pin 7 */
#define GPIO_INTTYPESET_PIN8_Pos              8                      /*!< Interrupt type set for pin 8 */
#define GPIO_INTTYPESET_PIN9_Pos              9                      /*!< Interrupt type set for pin 9 */
#define GPIO_INTTYPESET_PIN10_Pos             10                     /*!< Interrupt type set for pin 10 */
#define GPIO_INTTYPESET_PIN11_Pos             11                     /*!< Interrupt type set for pin 11 */
#define GPIO_INTTYPESET_PIN12_Pos             12                     /*!< Interrupt type set for pin 12 */
#define GPIO_INTTYPESET_PIN13_Pos             13                     /*!< Interrupt type set for pin 13 */
#define GPIO_INTTYPESET_PIN14_Pos             14                     /*!< Interrupt type set for pin 14 */
#define GPIO_INTTYPESET_PIN15_Pos             15                     /*!< Interrupt type set for pin 15 */

/* Bit field masks: */
#define GPIO_INTTYPESET_PIN0_Msk              0x00000001UL           /*!< Interrupt type set for pin 0 */
#define GPIO_INTTYPESET_PIN1_Msk              0x00000002UL           /*!< Interrupt type set for pin 1 */
#define GPIO_INTTYPESET_PIN2_Msk              0x00000004UL           /*!< Interrupt type set for pin 2 */
#define GPIO_INTTYPESET_PIN3_Msk              0x00000008UL           /*!< Interrupt type set for pin 3 */
#define GPIO_INTTYPESET_PIN4_Msk              0x00000010UL           /*!< Interrupt type set for pin 4 */
#define GPIO_INTTYPESET_PIN5_Msk              0x00000020UL           /*!< Interrupt type set for pin 5 */
#define GPIO_INTTYPESET_PIN6_Msk              0x00000040UL           /*!< Interrupt type set for pin 6 */
#define GPIO_INTTYPESET_PIN7_Msk              0x00000080UL           /*!< Interrupt type set for pin 7 */
#define GPIO_INTTYPESET_PIN8_Msk              0x00000100UL           /*!< Interrupt type set for pin 8 */
#define GPIO_INTTYPESET_PIN9_Msk              0x00000200UL           /*!< Interrupt type set for pin 9 */
#define GPIO_INTTYPESET_PIN10_Msk             0x00000400UL           /*!< Interrupt type set for pin 10 */
#define GPIO_INTTYPESET_PIN11_Msk             0x00000800UL           /*!< Interrupt type set for pin 11 */
#define GPIO_INTTYPESET_PIN12_Msk             0x00001000UL           /*!< Interrupt type set for pin 12 */
#define GPIO_INTTYPESET_PIN13_Msk             0x00002000UL           /*!< Interrupt type set for pin 13 */
#define GPIO_INTTYPESET_PIN14_Msk             0x00004000UL           /*!< Interrupt type set for pin 14 */
#define GPIO_INTTYPESET_PIN15_Msk             0x00008000UL           /*!< Interrupt type set for pin 15 */

/*--  INTTYPECLR: Interrupt type clear register ---------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :16;                               /*!< Interrupt type clear */
} _GPIO_INTTYPECLR_bits;

/* Bit field positions: */
#define GPIO_INTTYPECLR_VAL_Pos               0                      /*!< Interrupt type clear */

/* Bit field masks: */
#define GPIO_INTTYPECLR_VAL_Msk               0x0000FFFFUL           /*!< Interrupt type clear */

/*--  INTPOLSET: Interrupt polarity set register --------------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< Interrupt polarity set for pin 0 */
  uint32_t PIN1                   :1;                                /*!< Interrupt polarity set for pin 1 */
  uint32_t PIN2                   :1;                                /*!< Interrupt polarity set for pin 2 */
  uint32_t PIN3                   :1;                                /*!< Interrupt polarity set for pin 3 */
  uint32_t PIN4                   :1;                                /*!< Interrupt polarity set for pin 4 */
  uint32_t PIN5                   :1;                                /*!< Interrupt polarity set for pin 5 */
  uint32_t PIN6                   :1;                                /*!< Interrupt polarity set for pin 6 */
  uint32_t PIN7                   :1;                                /*!< Interrupt polarity set for pin 7 */
  uint32_t PIN8                   :1;                                /*!< Interrupt polarity set for pin 8 */
  uint32_t PIN9                   :1;                                /*!< Interrupt polarity set for pin 9 */
  uint32_t PIN10                  :1;                                /*!< Interrupt polarity set for pin 10 */
  uint32_t PIN11                  :1;                                /*!< Interrupt polarity set for pin 11 */
  uint32_t PIN12                  :1;                                /*!< Interrupt polarity set for pin 12 */
  uint32_t PIN13                  :1;                                /*!< Interrupt polarity set for pin 13 */
  uint32_t PIN14                  :1;                                /*!< Interrupt polarity set for pin 14 */
  uint32_t PIN15                  :1;                                /*!< Interrupt polarity set for pin 15 */
} _GPIO_INTPOLSET_bits;

/* Bit field positions: */
#define GPIO_INTPOLSET_PIN0_Pos               0                      /*!< Interrupt polarity set for pin 0 */
#define GPIO_INTPOLSET_PIN1_Pos               1                      /*!< Interrupt polarity set for pin 1 */
#define GPIO_INTPOLSET_PIN2_Pos               2                      /*!< Interrupt polarity set for pin 2 */
#define GPIO_INTPOLSET_PIN3_Pos               3                      /*!< Interrupt polarity set for pin 3 */
#define GPIO_INTPOLSET_PIN4_Pos               4                      /*!< Interrupt polarity set for pin 4 */
#define GPIO_INTPOLSET_PIN5_Pos               5                      /*!< Interrupt polarity set for pin 5 */
#define GPIO_INTPOLSET_PIN6_Pos               6                      /*!< Interrupt polarity set for pin 6 */
#define GPIO_INTPOLSET_PIN7_Pos               7                      /*!< Interrupt polarity set for pin 7 */
#define GPIO_INTPOLSET_PIN8_Pos               8                      /*!< Interrupt polarity set for pin 8 */
#define GPIO_INTPOLSET_PIN9_Pos               9                      /*!< Interrupt polarity set for pin 9 */
#define GPIO_INTPOLSET_PIN10_Pos              10                     /*!< Interrupt polarity set for pin 10 */
#define GPIO_INTPOLSET_PIN11_Pos              11                     /*!< Interrupt polarity set for pin 11 */
#define GPIO_INTPOLSET_PIN12_Pos              12                     /*!< Interrupt polarity set for pin 12 */
#define GPIO_INTPOLSET_PIN13_Pos              13                     /*!< Interrupt polarity set for pin 13 */
#define GPIO_INTPOLSET_PIN14_Pos              14                     /*!< Interrupt polarity set for pin 14 */
#define GPIO_INTPOLSET_PIN15_Pos              15                     /*!< Interrupt polarity set for pin 15 */

/* Bit field masks: */
#define GPIO_INTPOLSET_PIN0_Msk               0x00000001UL           /*!< Interrupt polarity set for pin 0 */
#define GPIO_INTPOLSET_PIN1_Msk               0x00000002UL           /*!< Interrupt polarity set for pin 1 */
#define GPIO_INTPOLSET_PIN2_Msk               0x00000004UL           /*!< Interrupt polarity set for pin 2 */
#define GPIO_INTPOLSET_PIN3_Msk               0x00000008UL           /*!< Interrupt polarity set for pin 3 */
#define GPIO_INTPOLSET_PIN4_Msk               0x00000010UL           /*!< Interrupt polarity set for pin 4 */
#define GPIO_INTPOLSET_PIN5_Msk               0x00000020UL           /*!< Interrupt polarity set for pin 5 */
#define GPIO_INTPOLSET_PIN6_Msk               0x00000040UL           /*!< Interrupt polarity set for pin 6 */
#define GPIO_INTPOLSET_PIN7_Msk               0x00000080UL           /*!< Interrupt polarity set for pin 7 */
#define GPIO_INTPOLSET_PIN8_Msk               0x00000100UL           /*!< Interrupt polarity set for pin 8 */
#define GPIO_INTPOLSET_PIN9_Msk               0x00000200UL           /*!< Interrupt polarity set for pin 9 */
#define GPIO_INTPOLSET_PIN10_Msk              0x00000400UL           /*!< Interrupt polarity set for pin 10 */
#define GPIO_INTPOLSET_PIN11_Msk              0x00000800UL           /*!< Interrupt polarity set for pin 11 */
#define GPIO_INTPOLSET_PIN12_Msk              0x00001000UL           /*!< Interrupt polarity set for pin 12 */
#define GPIO_INTPOLSET_PIN13_Msk              0x00002000UL           /*!< Interrupt polarity set for pin 13 */
#define GPIO_INTPOLSET_PIN14_Msk              0x00004000UL           /*!< Interrupt polarity set for pin 14 */
#define GPIO_INTPOLSET_PIN15_Msk              0x00008000UL           /*!< Interrupt polarity set for pin 15 */

/*--  INTPOLCLR: Interrupt polarity clear register ------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :16;                               /*!< Interrupt polarity clear */
} _GPIO_INTPOLCLR_bits;

/* Bit field positions: */
#define GPIO_INTPOLCLR_VAL_Pos                0                      /*!< Interrupt polarity clear */

/* Bit field masks: */
#define GPIO_INTPOLCLR_VAL_Msk                0x0000FFFFUL           /*!< Interrupt polarity clear */

/*--  INTEDGESET: Interrupt every edge set register -----------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< Interrupt every edge set for pin 0 */
  uint32_t PIN1                   :1;                                /*!< Interrupt every edge set for pin 1 */
  uint32_t PIN2                   :1;                                /*!< Interrupt every edge set for pin 2 */
  uint32_t PIN3                   :1;                                /*!< Interrupt every edge set for pin 3 */
  uint32_t PIN4                   :1;                                /*!< Interrupt every edge set for pin 4 */
  uint32_t PIN5                   :1;                                /*!< Interrupt every edge set for pin 5 */
  uint32_t PIN6                   :1;                                /*!< Interrupt every edge set for pin 6 */
  uint32_t PIN7                   :1;                                /*!< Interrupt every edge set for pin 7 */
  uint32_t PIN8                   :1;                                /*!< Interrupt every edge set for pin 8 */
  uint32_t PIN9                   :1;                                /*!< Interrupt every edge set for pin 9 */
  uint32_t PIN10                  :1;                                /*!< Interrupt every edge set for pin 10 */
  uint32_t PIN11                  :1;                                /*!< Interrupt every edge set for pin 11 */
  uint32_t PIN12                  :1;                                /*!< Interrupt every edge set for pin 12 */
  uint32_t PIN13                  :1;                                /*!< Interrupt every edge set for pin 13 */
  uint32_t PIN14                  :1;                                /*!< Interrupt every edge set for pin 14 */
  uint32_t PIN15                  :1;                                /*!< Interrupt every edge set for pin 15 */
} _GPIO_INTEDGESET_bits;

/* Bit field positions: */
#define GPIO_INTEDGESET_PIN0_Pos              0                      /*!< Interrupt every edge set for pin 0 */
#define GPIO_INTEDGESET_PIN1_Pos              1                      /*!< Interrupt every edge set for pin 1 */
#define GPIO_INTEDGESET_PIN2_Pos              2                      /*!< Interrupt every edge set for pin 2 */
#define GPIO_INTEDGESET_PIN3_Pos              3                      /*!< Interrupt every edge set for pin 3 */
#define GPIO_INTEDGESET_PIN4_Pos              4                      /*!< Interrupt every edge set for pin 4 */
#define GPIO_INTEDGESET_PIN5_Pos              5                      /*!< Interrupt every edge set for pin 5 */
#define GPIO_INTEDGESET_PIN6_Pos              6                      /*!< Interrupt every edge set for pin 6 */
#define GPIO_INTEDGESET_PIN7_Pos              7                      /*!< Interrupt every edge set for pin 7 */
#define GPIO_INTEDGESET_PIN8_Pos              8                      /*!< Interrupt every edge set for pin 8 */
#define GPIO_INTEDGESET_PIN9_Pos              9                      /*!< Interrupt every edge set for pin 9 */
#define GPIO_INTEDGESET_PIN10_Pos             10                     /*!< Interrupt every edge set for pin 10 */
#define GPIO_INTEDGESET_PIN11_Pos             11                     /*!< Interrupt every edge set for pin 11 */
#define GPIO_INTEDGESET_PIN12_Pos             12                     /*!< Interrupt every edge set for pin 12 */
#define GPIO_INTEDGESET_PIN13_Pos             13                     /*!< Interrupt every edge set for pin 13 */
#define GPIO_INTEDGESET_PIN14_Pos             14                     /*!< Interrupt every edge set for pin 14 */
#define GPIO_INTEDGESET_PIN15_Pos             15                     /*!< Interrupt every edge set for pin 15 */

/* Bit field masks: */
#define GPIO_INTEDGESET_PIN0_Msk              0x00000001UL           /*!< Interrupt every edge set for pin 0 */
#define GPIO_INTEDGESET_PIN1_Msk              0x00000002UL           /*!< Interrupt every edge set for pin 1 */
#define GPIO_INTEDGESET_PIN2_Msk              0x00000004UL           /*!< Interrupt every edge set for pin 2 */
#define GPIO_INTEDGESET_PIN3_Msk              0x00000008UL           /*!< Interrupt every edge set for pin 3 */
#define GPIO_INTEDGESET_PIN4_Msk              0x00000010UL           /*!< Interrupt every edge set for pin 4 */
#define GPIO_INTEDGESET_PIN5_Msk              0x00000020UL           /*!< Interrupt every edge set for pin 5 */
#define GPIO_INTEDGESET_PIN6_Msk              0x00000040UL           /*!< Interrupt every edge set for pin 6 */
#define GPIO_INTEDGESET_PIN7_Msk              0x00000080UL           /*!< Interrupt every edge set for pin 7 */
#define GPIO_INTEDGESET_PIN8_Msk              0x00000100UL           /*!< Interrupt every edge set for pin 8 */
#define GPIO_INTEDGESET_PIN9_Msk              0x00000200UL           /*!< Interrupt every edge set for pin 9 */
#define GPIO_INTEDGESET_PIN10_Msk             0x00000400UL           /*!< Interrupt every edge set for pin 10 */
#define GPIO_INTEDGESET_PIN11_Msk             0x00000800UL           /*!< Interrupt every edge set for pin 11 */
#define GPIO_INTEDGESET_PIN12_Msk             0x00001000UL           /*!< Interrupt every edge set for pin 12 */
#define GPIO_INTEDGESET_PIN13_Msk             0x00002000UL           /*!< Interrupt every edge set for pin 13 */
#define GPIO_INTEDGESET_PIN14_Msk             0x00004000UL           /*!< Interrupt every edge set for pin 14 */
#define GPIO_INTEDGESET_PIN15_Msk             0x00008000UL           /*!< Interrupt every edge set for pin 15 */

/*--  INTEDGECLR: Interrupt every edge clear register ---------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :16;                               /*!< Interrupt every edge clear */
} _GPIO_INTEDGECLR_bits;

/* Bit field positions: */
#define GPIO_INTEDGECLR_VAL_Pos               0                      /*!< Interrupt every edge clear */

/* Bit field masks: */
#define GPIO_INTEDGECLR_VAL_Msk               0x0000FFFFUL           /*!< Interrupt every edge clear */

/*--  INTSTATUS: Interrupt status -----------------------------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< Interrupt status of pin 0 */
  uint32_t PIN1                   :1;                                /*!< Interrupt status of pin 1 */
  uint32_t PIN2                   :1;                                /*!< Interrupt status of pin 2 */
  uint32_t PIN3                   :1;                                /*!< Interrupt status of pin 3 */
  uint32_t PIN4                   :1;                                /*!< Interrupt status of pin 4 */
  uint32_t PIN5                   :1;                                /*!< Interrupt status of pin 5 */
  uint32_t PIN6                   :1;                                /*!< Interrupt status of pin 6 */
  uint32_t PIN7                   :1;                                /*!< Interrupt status of pin 7 */
  uint32_t PIN8                   :1;                                /*!< Interrupt status of pin 8 */
  uint32_t PIN9                   :1;                                /*!< Interrupt status of pin 9 */
  uint32_t PIN10                  :1;                                /*!< Interrupt status of pin 10 */
  uint32_t PIN11                  :1;                                /*!< Interrupt status of pin 11 */
  uint32_t PIN12                  :1;                                /*!< Interrupt status of pin 12 */
  uint32_t PIN13                  :1;                                /*!< Interrupt status of pin 13 */
  uint32_t PIN14                  :1;                                /*!< Interrupt status of pin 14 */
  uint32_t PIN15                  :1;                                /*!< Interrupt status of pin 15 */
} _GPIO_INTSTATUS_bits;

/* Bit field positions: */
#define GPIO_INTSTATUS_PIN0_Pos               0                      /*!< Interrupt status of pin 0 */
#define GPIO_INTSTATUS_PIN1_Pos               1                      /*!< Interrupt status of pin 1 */
#define GPIO_INTSTATUS_PIN2_Pos               2                      /*!< Interrupt status of pin 2 */
#define GPIO_INTSTATUS_PIN3_Pos               3                      /*!< Interrupt status of pin 3 */
#define GPIO_INTSTATUS_PIN4_Pos               4                      /*!< Interrupt status of pin 4 */
#define GPIO_INTSTATUS_PIN5_Pos               5                      /*!< Interrupt status of pin 5 */
#define GPIO_INTSTATUS_PIN6_Pos               6                      /*!< Interrupt status of pin 6 */
#define GPIO_INTSTATUS_PIN7_Pos               7                      /*!< Interrupt status of pin 7 */
#define GPIO_INTSTATUS_PIN8_Pos               8                      /*!< Interrupt status of pin 8 */
#define GPIO_INTSTATUS_PIN9_Pos               9                      /*!< Interrupt status of pin 9 */
#define GPIO_INTSTATUS_PIN10_Pos              10                     /*!< Interrupt status of pin 10 */
#define GPIO_INTSTATUS_PIN11_Pos              11                     /*!< Interrupt status of pin 11 */
#define GPIO_INTSTATUS_PIN12_Pos              12                     /*!< Interrupt status of pin 12 */
#define GPIO_INTSTATUS_PIN13_Pos              13                     /*!< Interrupt status of pin 13 */
#define GPIO_INTSTATUS_PIN14_Pos              14                     /*!< Interrupt status of pin 14 */
#define GPIO_INTSTATUS_PIN15_Pos              15                     /*!< Interrupt status of pin 15 */

/* Bit field masks: */
#define GPIO_INTSTATUS_PIN0_Msk               0x00000001UL           /*!< Interrupt status of pin 0 */
#define GPIO_INTSTATUS_PIN1_Msk               0x00000002UL           /*!< Interrupt status of pin 1 */
#define GPIO_INTSTATUS_PIN2_Msk               0x00000004UL           /*!< Interrupt status of pin 2 */
#define GPIO_INTSTATUS_PIN3_Msk               0x00000008UL           /*!< Interrupt status of pin 3 */
#define GPIO_INTSTATUS_PIN4_Msk               0x00000010UL           /*!< Interrupt status of pin 4 */
#define GPIO_INTSTATUS_PIN5_Msk               0x00000020UL           /*!< Interrupt status of pin 5 */
#define GPIO_INTSTATUS_PIN6_Msk               0x00000040UL           /*!< Interrupt status of pin 6 */
#define GPIO_INTSTATUS_PIN7_Msk               0x00000080UL           /*!< Interrupt status of pin 7 */
#define GPIO_INTSTATUS_PIN8_Msk               0x00000100UL           /*!< Interrupt status of pin 8 */
#define GPIO_INTSTATUS_PIN9_Msk               0x00000200UL           /*!< Interrupt status of pin 9 */
#define GPIO_INTSTATUS_PIN10_Msk              0x00000400UL           /*!< Interrupt status of pin 10 */
#define GPIO_INTSTATUS_PIN11_Msk              0x00000800UL           /*!< Interrupt status of pin 11 */
#define GPIO_INTSTATUS_PIN12_Msk              0x00001000UL           /*!< Interrupt status of pin 12 */
#define GPIO_INTSTATUS_PIN13_Msk              0x00002000UL           /*!< Interrupt status of pin 13 */
#define GPIO_INTSTATUS_PIN14_Msk              0x00004000UL           /*!< Interrupt status of pin 14 */
#define GPIO_INTSTATUS_PIN15_Msk              0x00008000UL           /*!< Interrupt status of pin 15 */

/*--  DMATXREQSET: DMA request enable register ----------------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< DMA request enable for pin 0 */
  uint32_t PIN1                   :1;                                /*!< DMA request enable for pin 1 */
  uint32_t PIN2                   :1;                                /*!< DMA request enable for pin 2 */
  uint32_t PIN3                   :1;                                /*!< DMA request enable for pin 3 */
  uint32_t PIN4                   :1;                                /*!< DMA request enable for pin 4 */
  uint32_t PIN5                   :1;                                /*!< DMA request enable for pin 5 */
  uint32_t PIN6                   :1;                                /*!< DMA request enable for pin 6 */
  uint32_t PIN7                   :1;                                /*!< DMA request enable for pin 7 */
  uint32_t PIN8                   :1;                                /*!< DMA request enable for pin 8 */
  uint32_t PIN9                   :1;                                /*!< DMA request enable for pin 9 */
  uint32_t PIN10                  :1;                                /*!< DMA request enable for pin 10 */
  uint32_t PIN11                  :1;                                /*!< DMA request enable for pin 11 */
  uint32_t PIN12                  :1;                                /*!< DMA request enable for pin 12 */
  uint32_t PIN13                  :1;                                /*!< DMA request enable for pin 13 */
  uint32_t PIN14                  :1;                                /*!< DMA request enable for pin 14 */
  uint32_t PIN15                  :1;                                /*!< DMA request enable for pin 15 */
} _GPIO_DMATXREQSET_bits;

/* Bit field positions: */
#define GPIO_DMATXREQSET_PIN0_Pos             0                      /*!< DMA request enable for pin 0 */
#define GPIO_DMATXREQSET_PIN1_Pos             1                      /*!< DMA request enable for pin 1 */
#define GPIO_DMATXREQSET_PIN2_Pos             2                      /*!< DMA request enable for pin 2 */
#define GPIO_DMATXREQSET_PIN3_Pos             3                      /*!< DMA request enable for pin 3 */
#define GPIO_DMATXREQSET_PIN4_Pos             4                      /*!< DMA request enable for pin 4 */
#define GPIO_DMATXREQSET_PIN5_Pos             5                      /*!< DMA request enable for pin 5 */
#define GPIO_DMATXREQSET_PIN6_Pos             6                      /*!< DMA request enable for pin 6 */
#define GPIO_DMATXREQSET_PIN7_Pos             7                      /*!< DMA request enable for pin 7 */
#define GPIO_DMATXREQSET_PIN8_Pos             8                      /*!< DMA request enable for pin 8 */
#define GPIO_DMATXREQSET_PIN9_Pos             9                      /*!< DMA request enable for pin 9 */
#define GPIO_DMATXREQSET_PIN10_Pos            10                     /*!< DMA request enable for pin 10 */
#define GPIO_DMATXREQSET_PIN11_Pos            11                     /*!< DMA request enable for pin 11 */
#define GPIO_DMATXREQSET_PIN12_Pos            12                     /*!< DMA request enable for pin 12 */
#define GPIO_DMATXREQSET_PIN13_Pos            13                     /*!< DMA request enable for pin 13 */
#define GPIO_DMATXREQSET_PIN14_Pos            14                     /*!< DMA request enable for pin 14 */
#define GPIO_DMATXREQSET_PIN15_Pos            15                     /*!< DMA request enable for pin 15 */

/* Bit field masks: */
#define GPIO_DMATXREQSET_PIN0_Msk             0x00000001UL           /*!< DMA request enable for pin 0 */
#define GPIO_DMATXREQSET_PIN1_Msk             0x00000002UL           /*!< DMA request enable for pin 1 */
#define GPIO_DMATXREQSET_PIN2_Msk             0x00000004UL           /*!< DMA request enable for pin 2 */
#define GPIO_DMATXREQSET_PIN3_Msk             0x00000008UL           /*!< DMA request enable for pin 3 */
#define GPIO_DMATXREQSET_PIN4_Msk             0x00000010UL           /*!< DMA request enable for pin 4 */
#define GPIO_DMATXREQSET_PIN5_Msk             0x00000020UL           /*!< DMA request enable for pin 5 */
#define GPIO_DMATXREQSET_PIN6_Msk             0x00000040UL           /*!< DMA request enable for pin 6 */
#define GPIO_DMATXREQSET_PIN7_Msk             0x00000080UL           /*!< DMA request enable for pin 7 */
#define GPIO_DMATXREQSET_PIN8_Msk             0x00000100UL           /*!< DMA request enable for pin 8 */
#define GPIO_DMATXREQSET_PIN9_Msk             0x00000200UL           /*!< DMA request enable for pin 9 */
#define GPIO_DMATXREQSET_PIN10_Msk            0x00000400UL           /*!< DMA request enable for pin 10 */
#define GPIO_DMATXREQSET_PIN11_Msk            0x00000800UL           /*!< DMA request enable for pin 11 */
#define GPIO_DMATXREQSET_PIN12_Msk            0x00001000UL           /*!< DMA request enable for pin 12 */
#define GPIO_DMATXREQSET_PIN13_Msk            0x00002000UL           /*!< DMA request enable for pin 13 */
#define GPIO_DMATXREQSET_PIN14_Msk            0x00004000UL           /*!< DMA request enable for pin 14 */
#define GPIO_DMATXREQSET_PIN15_Msk            0x00008000UL           /*!< DMA request enable for pin 15 */

/*--  DMATXREQCLR: DMA request disable register ---------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :16;                               /*!< DMA request disable */
} _GPIO_DMATXREQCLR_bits;

/* Bit field positions: */
#define GPIO_DMATXREQCLR_VAL_Pos              0                      /*!< DMA request disable */

/* Bit field masks: */
#define GPIO_DMATXREQCLR_VAL_Msk              0x0000FFFFUL           /*!< DMA request disable */

/*--  ADCSOCSET: ADC Start Of Conversion enable register ------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< ADC SOC enable for pin 0 */
  uint32_t PIN1                   :1;                                /*!< ADC SOC enable for pin 1 */
  uint32_t PIN2                   :1;                                /*!< ADC SOC enable for pin 2 */
  uint32_t PIN3                   :1;                                /*!< ADC SOC enable for pin 3 */
  uint32_t PIN4                   :1;                                /*!< ADC SOC enable for pin 4 */
  uint32_t PIN5                   :1;                                /*!< ADC SOC enable for pin 5 */
  uint32_t PIN6                   :1;                                /*!< ADC SOC enable for pin 6 */
  uint32_t PIN7                   :1;                                /*!< ADC SOC enable for pin 7 */
  uint32_t PIN8                   :1;                                /*!< ADC SOC enable for pin 8 */
  uint32_t PIN9                   :1;                                /*!< ADC SOC enable for pin 9 */
  uint32_t PIN10                  :1;                                /*!< ADC SOC enable for pin 10 */
  uint32_t PIN11                  :1;                                /*!< ADC SOC enable for pin 11 */
  uint32_t PIN12                  :1;                                /*!< ADC SOC enable for pin 12 */
  uint32_t PIN13                  :1;                                /*!< ADC SOC enable for pin 13 */
  uint32_t PIN14                  :1;                                /*!< ADC SOC enable for pin 14 */
  uint32_t PIN15                  :1;                                /*!< ADC SOC enable for pin 15 */
} _GPIO_ADCSOCSET_bits;

/* Bit field positions: */
#define GPIO_ADCSOCSET_PIN0_Pos               0                      /*!< ADC SOC enable for pin 0 */
#define GPIO_ADCSOCSET_PIN1_Pos               1                      /*!< ADC SOC enable for pin 1 */
#define GPIO_ADCSOCSET_PIN2_Pos               2                      /*!< ADC SOC enable for pin 2 */
#define GPIO_ADCSOCSET_PIN3_Pos               3                      /*!< ADC SOC enable for pin 3 */
#define GPIO_ADCSOCSET_PIN4_Pos               4                      /*!< ADC SOC enable for pin 4 */
#define GPIO_ADCSOCSET_PIN5_Pos               5                      /*!< ADC SOC enable for pin 5 */
#define GPIO_ADCSOCSET_PIN6_Pos               6                      /*!< ADC SOC enable for pin 6 */
#define GPIO_ADCSOCSET_PIN7_Pos               7                      /*!< ADC SOC enable for pin 7 */
#define GPIO_ADCSOCSET_PIN8_Pos               8                      /*!< ADC SOC enable for pin 8 */
#define GPIO_ADCSOCSET_PIN9_Pos               9                      /*!< ADC SOC enable for pin 9 */
#define GPIO_ADCSOCSET_PIN10_Pos              10                     /*!< ADC SOC enable for pin 10 */
#define GPIO_ADCSOCSET_PIN11_Pos              11                     /*!< ADC SOC enable for pin 11 */
#define GPIO_ADCSOCSET_PIN12_Pos              12                     /*!< ADC SOC enable for pin 12 */
#define GPIO_ADCSOCSET_PIN13_Pos              13                     /*!< ADC SOC enable for pin 13 */
#define GPIO_ADCSOCSET_PIN14_Pos              14                     /*!< ADC SOC enable for pin 14 */
#define GPIO_ADCSOCSET_PIN15_Pos              15                     /*!< ADC SOC enable for pin 15 */

/* Bit field masks: */
#define GPIO_ADCSOCSET_PIN0_Msk               0x00000001UL           /*!< ADC SOC enable for pin 0 */
#define GPIO_ADCSOCSET_PIN1_Msk               0x00000002UL           /*!< ADC SOC enable for pin 1 */
#define GPIO_ADCSOCSET_PIN2_Msk               0x00000004UL           /*!< ADC SOC enable for pin 2 */
#define GPIO_ADCSOCSET_PIN3_Msk               0x00000008UL           /*!< ADC SOC enable for pin 3 */
#define GPIO_ADCSOCSET_PIN4_Msk               0x00000010UL           /*!< ADC SOC enable for pin 4 */
#define GPIO_ADCSOCSET_PIN5_Msk               0x00000020UL           /*!< ADC SOC enable for pin 5 */
#define GPIO_ADCSOCSET_PIN6_Msk               0x00000040UL           /*!< ADC SOC enable for pin 6 */
#define GPIO_ADCSOCSET_PIN7_Msk               0x00000080UL           /*!< ADC SOC enable for pin 7 */
#define GPIO_ADCSOCSET_PIN8_Msk               0x00000100UL           /*!< ADC SOC enable for pin 8 */
#define GPIO_ADCSOCSET_PIN9_Msk               0x00000200UL           /*!< ADC SOC enable for pin 9 */
#define GPIO_ADCSOCSET_PIN10_Msk              0x00000400UL           /*!< ADC SOC enable for pin 10 */
#define GPIO_ADCSOCSET_PIN11_Msk              0x00000800UL           /*!< ADC SOC enable for pin 11 */
#define GPIO_ADCSOCSET_PIN12_Msk              0x00001000UL           /*!< ADC SOC enable for pin 12 */
#define GPIO_ADCSOCSET_PIN13_Msk              0x00002000UL           /*!< ADC SOC enable for pin 13 */
#define GPIO_ADCSOCSET_PIN14_Msk              0x00004000UL           /*!< ADC SOC enable for pin 14 */
#define GPIO_ADCSOCSET_PIN15_Msk              0x00008000UL           /*!< ADC SOC enable for pin 15 */

/*--  ADCSOCCLR: ADC Start Of Conversion disable register -----------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :16;                               /*!< ADC SOC disable */
} _GPIO_ADCSOCCLR_bits;

/* Bit field positions: */
#define GPIO_ADCSOCCLR_VAL_Pos                0                      /*!< ADC SOC disable */

/* Bit field masks: */
#define GPIO_ADCSOCCLR_VAL_Msk                0x0000FFFFUL           /*!< ADC SOC disable */

/*--  RXEVSET: Core RXEV request enable register --------------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< RXEV enable for pin 0 */
  uint32_t PIN1                   :1;                                /*!< RXEV enable for pin 1 */
  uint32_t PIN2                   :1;                                /*!< RXEV enable for pin 2 */
  uint32_t PIN3                   :1;                                /*!< RXEV enable for pin 3 */
  uint32_t PIN4                   :1;                                /*!< RXEV enable for pin 4 */
  uint32_t PIN5                   :1;                                /*!< RXEV enable for pin 5 */
  uint32_t PIN6                   :1;                                /*!< RXEV enable for pin 6 */
  uint32_t PIN7                   :1;                                /*!< RXEV enable for pin 7 */
  uint32_t PIN8                   :1;                                /*!< RXEV enable for pin 8 */
  uint32_t PIN9                   :1;                                /*!< RXEV enable for pin 9 */
  uint32_t PIN10                  :1;                                /*!< RXEV enable for pin 10 */
  uint32_t PIN11                  :1;                                /*!< RXEV enable for pin 11 */
  uint32_t PIN12                  :1;                                /*!< RXEV enable for pin 12 */
  uint32_t PIN13                  :1;                                /*!< RXEV enable for pin 13 */
  uint32_t PIN14                  :1;                                /*!< RXEV enable for pin 14 */
  uint32_t PIN15                  :1;                                /*!< RXEV enable for pin 15 */
} _GPIO_RXEVSET_bits;

/* Bit field positions: */
#define GPIO_RXEVSET_PIN0_Pos                 0                      /*!< RXEV enable for pin 0 */
#define GPIO_RXEVSET_PIN1_Pos                 1                      /*!< RXEV enable for pin 1 */
#define GPIO_RXEVSET_PIN2_Pos                 2                      /*!< RXEV enable for pin 2 */
#define GPIO_RXEVSET_PIN3_Pos                 3                      /*!< RXEV enable for pin 3 */
#define GPIO_RXEVSET_PIN4_Pos                 4                      /*!< RXEV enable for pin 4 */
#define GPIO_RXEVSET_PIN5_Pos                 5                      /*!< RXEV enable for pin 5 */
#define GPIO_RXEVSET_PIN6_Pos                 6                      /*!< RXEV enable for pin 6 */
#define GPIO_RXEVSET_PIN7_Pos                 7                      /*!< RXEV enable for pin 7 */
#define GPIO_RXEVSET_PIN8_Pos                 8                      /*!< RXEV enable for pin 8 */
#define GPIO_RXEVSET_PIN9_Pos                 9                      /*!< RXEV enable for pin 9 */
#define GPIO_RXEVSET_PIN10_Pos                10                     /*!< RXEV enable for pin 10 */
#define GPIO_RXEVSET_PIN11_Pos                11                     /*!< RXEV enable for pin 11 */
#define GPIO_RXEVSET_PIN12_Pos                12                     /*!< RXEV enable for pin 12 */
#define GPIO_RXEVSET_PIN13_Pos                13                     /*!< RXEV enable for pin 13 */
#define GPIO_RXEVSET_PIN14_Pos                14                     /*!< RXEV enable for pin 14 */
#define GPIO_RXEVSET_PIN15_Pos                15                     /*!< RXEV enable for pin 15 */

/* Bit field masks: */
#define GPIO_RXEVSET_PIN0_Msk                 0x00000001UL           /*!< RXEV enable for pin 0 */
#define GPIO_RXEVSET_PIN1_Msk                 0x00000002UL           /*!< RXEV enable for pin 1 */
#define GPIO_RXEVSET_PIN2_Msk                 0x00000004UL           /*!< RXEV enable for pin 2 */
#define GPIO_RXEVSET_PIN3_Msk                 0x00000008UL           /*!< RXEV enable for pin 3 */
#define GPIO_RXEVSET_PIN4_Msk                 0x00000010UL           /*!< RXEV enable for pin 4 */
#define GPIO_RXEVSET_PIN5_Msk                 0x00000020UL           /*!< RXEV enable for pin 5 */
#define GPIO_RXEVSET_PIN6_Msk                 0x00000040UL           /*!< RXEV enable for pin 6 */
#define GPIO_RXEVSET_PIN7_Msk                 0x00000080UL           /*!< RXEV enable for pin 7 */
#define GPIO_RXEVSET_PIN8_Msk                 0x00000100UL           /*!< RXEV enable for pin 8 */
#define GPIO_RXEVSET_PIN9_Msk                 0x00000200UL           /*!< RXEV enable for pin 9 */
#define GPIO_RXEVSET_PIN10_Msk                0x00000400UL           /*!< RXEV enable for pin 10 */
#define GPIO_RXEVSET_PIN11_Msk                0x00000800UL           /*!< RXEV enable for pin 11 */
#define GPIO_RXEVSET_PIN12_Msk                0x00001000UL           /*!< RXEV enable for pin 12 */
#define GPIO_RXEVSET_PIN13_Msk                0x00002000UL           /*!< RXEV enable for pin 13 */
#define GPIO_RXEVSET_PIN14_Msk                0x00004000UL           /*!< RXEV enable for pin 14 */
#define GPIO_RXEVSET_PIN15_Msk                0x00008000UL           /*!< RXEV enable for pin 15 */

/*--  RXEVCLR: Core RXEV request disable register -------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :16;                               /*!< RXEV disable */
} _GPIO_RXEVCLR_bits;

/* Bit field positions: */
#define GPIO_RXEVCLR_VAL_Pos                  0                      /*!< RXEV disable */

/* Bit field masks: */
#define GPIO_RXEVCLR_VAL_Msk                  0x0000FFFFUL           /*!< RXEV disable */

/*--  LOCKKEY: Key register to unlock LOCKSET/LOCKCLR registers for write (KEY=0xADEADBEE) --------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!<  Key to unlock LOCKSET/LOCKCLR registers for write (KEY=0xADEADBEE) */
} _GPIO_LOCKKEY_bits;

/* Bit field positions: */
#define GPIO_LOCKKEY_VAL_Pos                  0                      /*!<  Key to unlock LOCKSET/LOCKCLR registers for write (KEY=0xADEADBEE) */

/* Bit field masks: */
#define GPIO_LOCKKEY_VAL_Msk                  0xFFFFFFFFUL           /*!<  Key to unlock LOCKSET/LOCKCLR registers for write (KEY=0xADEADBEE) */

/* Bit field enums: */
typedef enum {
  GPIO_LOCKKEY_VAL_LOCK                      = -286331154,           /*!< 0xEEEEEEEE, key to lock registers */
  GPIO_LOCKKEY_VAL_UNLOCK                    = -1377117202,          /*!< 0xADEADBEE, key to unlock registers */
} GPIO_LOCKKEY_VAL_Enum;

/*--  LOCKSTAT: Write LOCKSET/LOCKCLR enable status register --------------------------------------------------*/
typedef struct {
  uint32_t WREN                   :1;                                /*!< Write LOCKSET/LOCKCLR enable status */
} _GPIO_LOCKSTAT_bits;

/* Bit field positions: */
#define GPIO_LOCKSTAT_WREN_Pos                0                      /*!< Write LOCKSET/LOCKCLR enable status */

/* Bit field masks: */
#define GPIO_LOCKSTAT_WREN_Msk                0x00000001UL           /*!< Write LOCKSET/LOCKCLR enable status */

/*--  LOCKSET: Lock pins configuration enable register --------------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< Lock configuration enable for pin 0 */
  uint32_t PIN1                   :1;                                /*!< Lock configuration enable for pin 1 */
  uint32_t PIN2                   :1;                                /*!< Lock configuration enable for pin 2 */
  uint32_t PIN3                   :1;                                /*!< Lock configuration enable for pin 3 */
  uint32_t PIN4                   :1;                                /*!< Lock configuration enable for pin 4 */
  uint32_t PIN5                   :1;                                /*!< Lock configuration enable for pin 5 */
  uint32_t PIN6                   :1;                                /*!< Lock configuration enable for pin 6 */
  uint32_t PIN7                   :1;                                /*!< Lock configuration enable for pin 7 */
  uint32_t PIN8                   :1;                                /*!< Lock configuration enable for pin 8 */
  uint32_t PIN9                   :1;                                /*!< Lock configuration enable for pin 9 */
  uint32_t PIN10                  :1;                                /*!< Lock configuration enable for pin 10 */
  uint32_t PIN11                  :1;                                /*!< Lock configuration enable for pin 11 */
  uint32_t PIN12                  :1;                                /*!< Lock configuration enable for pin 12 */
  uint32_t PIN13                  :1;                                /*!< Lock configuration enable for pin 13 */
  uint32_t PIN14                  :1;                                /*!< Lock configuration enable for pin 14 */
  uint32_t PIN15                  :1;                                /*!< Lock configuration enable for pin 15 */
} _GPIO_LOCKSET_bits;

/* Bit field positions: */
#define GPIO_LOCKSET_PIN0_Pos                 0                      /*!< Lock configuration enable for pin 0 */
#define GPIO_LOCKSET_PIN1_Pos                 1                      /*!< Lock configuration enable for pin 1 */
#define GPIO_LOCKSET_PIN2_Pos                 2                      /*!< Lock configuration enable for pin 2 */
#define GPIO_LOCKSET_PIN3_Pos                 3                      /*!< Lock configuration enable for pin 3 */
#define GPIO_LOCKSET_PIN4_Pos                 4                      /*!< Lock configuration enable for pin 4 */
#define GPIO_LOCKSET_PIN5_Pos                 5                      /*!< Lock configuration enable for pin 5 */
#define GPIO_LOCKSET_PIN6_Pos                 6                      /*!< Lock configuration enable for pin 6 */
#define GPIO_LOCKSET_PIN7_Pos                 7                      /*!< Lock configuration enable for pin 7 */
#define GPIO_LOCKSET_PIN8_Pos                 8                      /*!< Lock configuration enable for pin 8 */
#define GPIO_LOCKSET_PIN9_Pos                 9                      /*!< Lock configuration enable for pin 9 */
#define GPIO_LOCKSET_PIN10_Pos                10                     /*!< Lock configuration enable for pin 10 */
#define GPIO_LOCKSET_PIN11_Pos                11                     /*!< Lock configuration enable for pin 11 */
#define GPIO_LOCKSET_PIN12_Pos                12                     /*!< Lock configuration enable for pin 12 */
#define GPIO_LOCKSET_PIN13_Pos                13                     /*!< Lock configuration enable for pin 13 */
#define GPIO_LOCKSET_PIN14_Pos                14                     /*!< Lock configuration enable for pin 14 */
#define GPIO_LOCKSET_PIN15_Pos                15                     /*!< Lock configuration enable for pin 15 */

/* Bit field masks: */
#define GPIO_LOCKSET_PIN0_Msk                 0x00000001UL           /*!< Lock configuration enable for pin 0 */
#define GPIO_LOCKSET_PIN1_Msk                 0x00000002UL           /*!< Lock configuration enable for pin 1 */
#define GPIO_LOCKSET_PIN2_Msk                 0x00000004UL           /*!< Lock configuration enable for pin 2 */
#define GPIO_LOCKSET_PIN3_Msk                 0x00000008UL           /*!< Lock configuration enable for pin 3 */
#define GPIO_LOCKSET_PIN4_Msk                 0x00000010UL           /*!< Lock configuration enable for pin 4 */
#define GPIO_LOCKSET_PIN5_Msk                 0x00000020UL           /*!< Lock configuration enable for pin 5 */
#define GPIO_LOCKSET_PIN6_Msk                 0x00000040UL           /*!< Lock configuration enable for pin 6 */
#define GPIO_LOCKSET_PIN7_Msk                 0x00000080UL           /*!< Lock configuration enable for pin 7 */
#define GPIO_LOCKSET_PIN8_Msk                 0x00000100UL           /*!< Lock configuration enable for pin 8 */
#define GPIO_LOCKSET_PIN9_Msk                 0x00000200UL           /*!< Lock configuration enable for pin 9 */
#define GPIO_LOCKSET_PIN10_Msk                0x00000400UL           /*!< Lock configuration enable for pin 10 */
#define GPIO_LOCKSET_PIN11_Msk                0x00000800UL           /*!< Lock configuration enable for pin 11 */
#define GPIO_LOCKSET_PIN12_Msk                0x00001000UL           /*!< Lock configuration enable for pin 12 */
#define GPIO_LOCKSET_PIN13_Msk                0x00002000UL           /*!< Lock configuration enable for pin 13 */
#define GPIO_LOCKSET_PIN14_Msk                0x00004000UL           /*!< Lock configuration enable for pin 14 */
#define GPIO_LOCKSET_PIN15_Msk                0x00008000UL           /*!< Lock configuration enable for pin 15 */

/*--  LOCKCLR: Lock pins configuration disable register -------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :16;                               /*!< Lock configuration disable */
} _GPIO_LOCKCLR_bits;

/* Bit field positions: */
#define GPIO_LOCKCLR_VAL_Pos                  0                      /*!< Lock configuration disable */

/* Bit field masks: */
#define GPIO_LOCKCLR_VAL_Msk                  0x0000FFFFUL           /*!< Lock configuration disable */

/*--  DMARXREQSET: DMA RX request generator enable register ---------------------------------------------------*/
typedef struct {
  uint32_t PIN0                   :1;                                /*!< DMA request enable for pin 0 */
  uint32_t PIN1                   :1;                                /*!< DMA request enable for pin 1 */
  uint32_t PIN2                   :1;                                /*!< DMA request enable for pin 2 */
  uint32_t PIN3                   :1;                                /*!< DMA request enable for pin 3 */
  uint32_t PIN4                   :1;                                /*!< DMA request enable for pin 4 */
  uint32_t PIN5                   :1;                                /*!< DMA request enable for pin 5 */
  uint32_t PIN6                   :1;                                /*!< DMA request enable for pin 6 */
  uint32_t PIN7                   :1;                                /*!< DMA request enable for pin 7 */
  uint32_t PIN8                   :1;                                /*!< DMA request enable for pin 8 */
  uint32_t PIN9                   :1;                                /*!< DMA request enable for pin 9 */
  uint32_t PIN10                  :1;                                /*!< DMA request enable for pin 10 */
  uint32_t PIN11                  :1;                                /*!< DMA request enable for pin 11 */
  uint32_t PIN12                  :1;                                /*!< DMA request enable for pin 12 */
  uint32_t PIN13                  :1;                                /*!< DMA request enable for pin 13 */
  uint32_t PIN14                  :1;                                /*!< DMA request enable for pin 14 */
  uint32_t PIN15                  :1;                                /*!< DMA request enable for pin 15 */
} _GPIO_DMARXREQSET_bits;

/* Bit field positions: */
#define GPIO_DMARXREQSET_PIN0_Pos             0                      /*!< DMA request enable for pin 0 */
#define GPIO_DMARXREQSET_PIN1_Pos             1                      /*!< DMA request enable for pin 1 */
#define GPIO_DMARXREQSET_PIN2_Pos             2                      /*!< DMA request enable for pin 2 */
#define GPIO_DMARXREQSET_PIN3_Pos             3                      /*!< DMA request enable for pin 3 */
#define GPIO_DMARXREQSET_PIN4_Pos             4                      /*!< DMA request enable for pin 4 */
#define GPIO_DMARXREQSET_PIN5_Pos             5                      /*!< DMA request enable for pin 5 */
#define GPIO_DMARXREQSET_PIN6_Pos             6                      /*!< DMA request enable for pin 6 */
#define GPIO_DMARXREQSET_PIN7_Pos             7                      /*!< DMA request enable for pin 7 */
#define GPIO_DMARXREQSET_PIN8_Pos             8                      /*!< DMA request enable for pin 8 */
#define GPIO_DMARXREQSET_PIN9_Pos             9                      /*!< DMA request enable for pin 9 */
#define GPIO_DMARXREQSET_PIN10_Pos            10                     /*!< DMA request enable for pin 10 */
#define GPIO_DMARXREQSET_PIN11_Pos            11                     /*!< DMA request enable for pin 11 */
#define GPIO_DMARXREQSET_PIN12_Pos            12                     /*!< DMA request enable for pin 12 */
#define GPIO_DMARXREQSET_PIN13_Pos            13                     /*!< DMA request enable for pin 13 */
#define GPIO_DMARXREQSET_PIN14_Pos            14                     /*!< DMA request enable for pin 14 */
#define GPIO_DMARXREQSET_PIN15_Pos            15                     /*!< DMA request enable for pin 15 */

/* Bit field masks: */
#define GPIO_DMARXREQSET_PIN0_Msk             0x00000001UL           /*!< DMA request enable for pin 0 */
#define GPIO_DMARXREQSET_PIN1_Msk             0x00000002UL           /*!< DMA request enable for pin 1 */
#define GPIO_DMARXREQSET_PIN2_Msk             0x00000004UL           /*!< DMA request enable for pin 2 */
#define GPIO_DMARXREQSET_PIN3_Msk             0x00000008UL           /*!< DMA request enable for pin 3 */
#define GPIO_DMARXREQSET_PIN4_Msk             0x00000010UL           /*!< DMA request enable for pin 4 */
#define GPIO_DMARXREQSET_PIN5_Msk             0x00000020UL           /*!< DMA request enable for pin 5 */
#define GPIO_DMARXREQSET_PIN6_Msk             0x00000040UL           /*!< DMA request enable for pin 6 */
#define GPIO_DMARXREQSET_PIN7_Msk             0x00000080UL           /*!< DMA request enable for pin 7 */
#define GPIO_DMARXREQSET_PIN8_Msk             0x00000100UL           /*!< DMA request enable for pin 8 */
#define GPIO_DMARXREQSET_PIN9_Msk             0x00000200UL           /*!< DMA request enable for pin 9 */
#define GPIO_DMARXREQSET_PIN10_Msk            0x00000400UL           /*!< DMA request enable for pin 10 */
#define GPIO_DMARXREQSET_PIN11_Msk            0x00000800UL           /*!< DMA request enable for pin 11 */
#define GPIO_DMARXREQSET_PIN12_Msk            0x00001000UL           /*!< DMA request enable for pin 12 */
#define GPIO_DMARXREQSET_PIN13_Msk            0x00002000UL           /*!< DMA request enable for pin 13 */
#define GPIO_DMARXREQSET_PIN14_Msk            0x00004000UL           /*!< DMA request enable for pin 14 */
#define GPIO_DMARXREQSET_PIN15_Msk            0x00008000UL           /*!< DMA request enable for pin 15 */

/*--  DMARXREQCLR: DMA RX request generator disable register --------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :16;                               /*!< DMA request disable */
} _GPIO_DMARXREQCLR_bits;

/* Bit field positions: */
#define GPIO_DMARXREQCLR_VAL_Pos              0                      /*!< DMA request disable */

/* Bit field masks: */
#define GPIO_DMARXREQCLR_VAL_Msk              0x0000FFFFUL           /*!< DMA request disable */

/*--  MASKLB: Mask register low byte of port ------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :8;                                /*!< Mask low byte */
} _GPIO_MASKLB_bits;

/* Bit field positions: */
#define GPIO_MASKLB_VAL_Pos                   0                      /*!< Mask low byte */

/* Bit field masks: */
#define GPIO_MASKLB_VAL_Msk                   0x000000FFUL           /*!< Mask low byte */

/*--  MASKHB: Mask register High byte of port -----------------------------------------------------------------*/
typedef struct {
  uint32_t                        :8;                                /*!< RESERVED */
  uint32_t VAL                    :8;                                /*!< Mask high byte */
} _GPIO_MASKHB_bits;

/* Bit field positions: */
#define GPIO_MASKHB_VAL_Pos                   8                      /*!< Mask high byte */

/* Bit field masks: */
#define GPIO_MASKHB_VAL_Msk                   0x0000FF00UL           /*!< Mask high byte */

//Cluster MASKLB:
typedef struct {
  union { 
  /*!< Mask register low byte of port */
    __IO uint32_t MASKLB;                                            /*!< MASKLB : type used for word access */
    __IO _GPIO_MASKLB_bits MASKLB_bit;                               /*!< MASKLB_bit: structure used for bit access */
  };
} _GPIO_MASKLB_TypeDef;
//Cluster MASKHB:
typedef struct {
  union { 
  /*!< Mask register High byte of port */
    __IO uint32_t MASKHB;                                            /*!< MASKHB : type used for word access */
    __IO _GPIO_MASKHB_bits MASKHB_bit;                               /*!< MASKHB_bit: structure used for bit access */
  };
} _GPIO_MASKHB_TypeDef;
typedef struct {
  union {                                                               /*!< Data Input register */
    __I uint32_t DATA;                                               /*!< DATA    : type used for word access */
    __I _GPIO_DATA_bits  DATA_bit;                                   /*!< DATA_bit: structure used for bit access */
  };
  union {                                                               /*!< Data output register */
    __IO uint32_t DATAOUT;                                           /*!< DATAOUT    : type used for word access */
    __IO _GPIO_DATAOUT_bits  DATAOUT_bit;                            /*!< DATAOUT_bit: structure used for bit access */
  };
  union {                                                               /*!< Data output set bits register */
    __O uint32_t DATAOUTSET;                                           /*!< DATAOUTSET    : type used for word access */
    __O _GPIO_DATAOUTSET_bits  DATAOUTSET_bit;                       /*!< DATAOUTSET_bit: structure used for bit access */
  };
  union {                                                               /*!< Data output clear bits register */
    __O uint32_t DATAOUTCLR;                                           /*!< DATAOUTCLR    : type used for word access */
    __O _GPIO_DATAOUTCLR_bits  DATAOUTCLR_bit;                       /*!< DATAOUTCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Data output toggle bits register */
    __O uint32_t DATAOUTTGL;                                           /*!< DATAOUTTGL    : type used for word access */
    __O _GPIO_DATAOUTTGL_bits  DATAOUTTGL_bit;                       /*!< DATAOUTTGL_bit: structure used for bit access */
  };
    __IO uint32_t Reserved0[3];
  union {                                                               /*!< Select pull mode register */
    __IO uint32_t PULLMODE;                                           /*!< PULLMODE    : type used for word access */
    __IO _GPIO_PULLMODE_bits  PULLMODE_bit;                          /*!< PULLMODE_bit: structure used for bit access */
  };
  union {                                                               /*!< Select output mode register */
    __IO uint32_t OUTMODE;                                           /*!< OUTMODE    : type used for word access */
    __IO _GPIO_OUTMODE_bits  OUTMODE_bit;                            /*!< OUTMODE_bit: structure used for bit access */
  };
    __IO uint32_t Reserved1;
  union {                                                               /*!< Output enable register */
    __IO uint32_t OUTENSET;                                           /*!< OUTENSET    : type used for word access */
    __IO _GPIO_OUTENSET_bits  OUTENSET_bit;                          /*!< OUTENSET_bit: structure used for bit access */
  };
  union {                                                               /*!< Output disable register */
    __O uint32_t OUTENCLR;                                           /*!< OUTENCLR    : type used for word access */
    __O _GPIO_OUTENCLR_bits  OUTENCLR_bit;                           /*!< OUTENCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Alternative function enable register */
    __IO uint32_t ALTFUNCSET;                                           /*!< ALTFUNCSET    : type used for word access */
    __IO _GPIO_ALTFUNCSET_bits  ALTFUNCSET_bit;                      /*!< ALTFUNCSET_bit: structure used for bit access */
  };
  union {                                                               /*!< Alternative function disable register */
    __O uint32_t ALTFUNCCLR;                                           /*!< ALTFUNCCLR    : type used for word access */
    __O _GPIO_ALTFUNCCLR_bits  ALTFUNCCLR_bit;                       /*!< ALTFUNCCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Alternative function number register */
    __IO uint32_t ALTFUNCNUM;                                           /*!< ALTFUNCNUM    : type used for word access */
    __IO _GPIO_ALTFUNCNUM_bits  ALTFUNCNUM_bit;                      /*!< ALTFUNCNUM_bit: structure used for bit access */
  };
    __IO uint32_t Reserved2;
  union {                                                               /*!< Additional double flip-flop syncronization enable register */
    __IO uint32_t SYNCSET;                                           /*!< SYNCSET    : type used for word access */
    __IO _GPIO_SYNCSET_bits  SYNCSET_bit;                            /*!< SYNCSET_bit: structure used for bit access */
  };
  union {                                                               /*!< Additional double flip-flop syncronization disable register */
    __O uint32_t SYNCCLR;                                            /*!< SYNCCLR    : type used for word access */
    __O _GPIO_SYNCCLR_bits  SYNCCLR_bit;                             /*!< SYNCCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Qualifier enable register */
    __IO uint32_t QUALSET;                                           /*!< QUALSET    : type used for word access */
    __IO _GPIO_QUALSET_bits  QUALSET_bit;                            /*!< QUALSET_bit: structure used for bit access */
  };
  union {                                                               /*!< Qualifier disable register */
    __O uint32_t QUALCLR;                                            /*!< QUALCLR    : type used for word access */
    __O _GPIO_QUALCLR_bits  QUALCLR_bit;                             /*!< QUALCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Qualifier mode set register */
    __IO uint32_t QUALMODESET;                                           /*!< QUALMODESET    : type used for word access */
    __IO _GPIO_QUALMODESET_bits  QUALMODESET_bit;                    /*!< QUALMODESET_bit: structure used for bit access */
  };
  union {                                                               /*!< Qualifier mode clear register */
    __O uint32_t QUALMODECLR;                                           /*!< QUALMODECLR    : type used for word access */
    __O _GPIO_QUALMODECLR_bits  QUALMODECLR_bit;                     /*!< QUALMODECLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Qualifier sample period register */
    __IO uint32_t QUALSAMPLE;                                           /*!< QUALSAMPLE    : type used for word access */
    __IO _GPIO_QUALSAMPLE_bits  QUALSAMPLE_bit;                      /*!< QUALSAMPLE_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt enable register */
    __IO uint32_t INTENSET;                                           /*!< INTENSET    : type used for word access */
    __IO _GPIO_INTENSET_bits  INTENSET_bit;                          /*!< INTENSET_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt disable register */
    __O uint32_t INTENCLR;                                           /*!< INTENCLR    : type used for word access */
    __O _GPIO_INTENCLR_bits  INTENCLR_bit;                           /*!< INTENCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt type set register */
    __IO uint32_t INTTYPESET;                                           /*!< INTTYPESET    : type used for word access */
    __IO _GPIO_INTTYPESET_bits  INTTYPESET_bit;                      /*!< INTTYPESET_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt type clear register */
    __O uint32_t INTTYPECLR;                                           /*!< INTTYPECLR    : type used for word access */
    __O _GPIO_INTTYPECLR_bits  INTTYPECLR_bit;                       /*!< INTTYPECLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt polarity set register */
    __IO uint32_t INTPOLSET;                                           /*!< INTPOLSET    : type used for word access */
    __IO _GPIO_INTPOLSET_bits  INTPOLSET_bit;                        /*!< INTPOLSET_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt polarity clear register */
    __O uint32_t INTPOLCLR;                                           /*!< INTPOLCLR    : type used for word access */
    __O _GPIO_INTPOLCLR_bits  INTPOLCLR_bit;                         /*!< INTPOLCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt every edge set register */
    __IO uint32_t INTEDGESET;                                           /*!< INTEDGESET    : type used for word access */
    __IO _GPIO_INTEDGESET_bits  INTEDGESET_bit;                      /*!< INTEDGESET_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt every edge clear register */
    __O uint32_t INTEDGECLR;                                           /*!< INTEDGECLR    : type used for word access */
    __O _GPIO_INTEDGECLR_bits  INTEDGECLR_bit;                       /*!< INTEDGECLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt status */
    __IO uint32_t INTSTATUS;                                           /*!< INTSTATUS    : type used for word access */
    __IO _GPIO_INTSTATUS_bits  INTSTATUS_bit;                        /*!< INTSTATUS_bit: structure used for bit access */
  };
  union {                                                               /*!< DMA request enable register */
    __IO uint32_t DMATXREQSET;                                           /*!< DMATXREQSET    : type used for word access */
    __IO _GPIO_DMATXREQSET_bits  DMATXREQSET_bit;                    /*!< DMATXREQSET_bit: structure used for bit access */
  };
  union {                                                               /*!< DMA request disable register */
    __O uint32_t DMATXREQCLR;                                           /*!< DMATXREQCLR    : type used for word access */
    __O _GPIO_DMATXREQCLR_bits  DMATXREQCLR_bit;                     /*!< DMATXREQCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< ADC Start Of Conversion enable register */
    __IO uint32_t ADCSOCSET;                                           /*!< ADCSOCSET    : type used for word access */
    __IO _GPIO_ADCSOCSET_bits  ADCSOCSET_bit;                        /*!< ADCSOCSET_bit: structure used for bit access */
  };
  union {                                                               /*!< ADC Start Of Conversion disable register */
    __O uint32_t ADCSOCCLR;                                           /*!< ADCSOCCLR    : type used for word access */
    __O _GPIO_ADCSOCCLR_bits  ADCSOCCLR_bit;                         /*!< ADCSOCCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Core RXEV request enable register */
    __IO uint32_t RXEVSET;                                           /*!< RXEVSET    : type used for word access */
    __IO _GPIO_RXEVSET_bits  RXEVSET_bit;                            /*!< RXEVSET_bit: structure used for bit access */
  };
  union {                                                               /*!< Core RXEV request disable register */
    __O uint32_t RXEVCLR;                                            /*!< RXEVCLR    : type used for word access */
    __O _GPIO_RXEVCLR_bits  RXEVCLR_bit;                             /*!< RXEVCLR_bit: structure used for bit access */
  };
  union {
    union {                                                               /*!< Key register to unlock LOCKSET/LOCKCLR registers for write (KEY=0xADEADBEE) */
      __O uint32_t LOCKKEY;                                           /*!< LOCKKEY    : type used for word access */
      __O _GPIO_LOCKKEY_bits  LOCKKEY_bit;                           /*!< LOCKKEY_bit: structure used for bit access */
    };
    struct {
      union {                                                               /*!< Write LOCKSET/LOCKCLR enable status register */
        __I uint32_t LOCKSTAT;                                           /*!< LOCKSTAT    : type used for word access */
        __I _GPIO_LOCKSTAT_bits  LOCKSTAT_bit;                       /*!< LOCKSTAT_bit: structure used for bit access */
      };
    };
  };
  union {                                                               /*!< Lock pins configuration enable register */
    __IO uint32_t LOCKSET;                                           /*!< LOCKSET    : type used for word access */
    __IO _GPIO_LOCKSET_bits  LOCKSET_bit;                            /*!< LOCKSET_bit: structure used for bit access */
  };
  union {                                                               /*!< Lock pins configuration disable register */
    __O uint32_t LOCKCLR;                                            /*!< LOCKCLR    : type used for word access */
    __O _GPIO_LOCKCLR_bits  LOCKCLR_bit;                             /*!< LOCKCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< DMA RX request generator enable register */
    __IO uint32_t DMARXREQSET;                                           /*!< DMARXREQSET    : type used for word access */
    __IO _GPIO_DMARXREQSET_bits  DMARXREQSET_bit;                    /*!< DMARXREQSET_bit: structure used for bit access */
  };
  union {                                                               /*!< DMA RX request generator disable register */
    __O uint32_t DMARXREQCLR;                                           /*!< DMARXREQCLR    : type used for word access */
    __O _GPIO_DMARXREQCLR_bits  DMARXREQCLR_bit;                     /*!< DMARXREQCLR_bit: structure used for bit access */
  };
    __IO uint32_t Reserved3[212];
  _GPIO_MASKLB_TypeDef MASKLB[256];
  _GPIO_MASKHB_TypeDef MASKHB[256];
} GPIO_TypeDef;


/******************************************************************************/
/*                         I2C registers                                      */
/******************************************************************************/

/*--  SDA: Data register --------------------------------------------------------------------------------------*/
typedef struct {
  uint32_t DATA                   :8;                                /*!< Data field */
} _I2C_SDA_bits;

/* Bit field positions: */
#define I2C_SDA_DATA_Pos                      0                      /*!< Data field */

/* Bit field masks: */
#define I2C_SDA_DATA_Msk                      0x000000FFUL           /*!< Data field */

/*--  ST: Status register -------------------------------------------------------------------------------------*/
typedef struct {
  uint32_t MODE                   :6;                                /*!< Status code */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t INT                    :1;                                /*!< Interrupt flag */
} _I2C_ST_bits;

/* Bit field positions: */
#define I2C_ST_MODE_Pos                       0                      /*!< Status code */
#define I2C_ST_INT_Pos                        7                      /*!< Interrupt flag */

/* Bit field masks: */
#define I2C_ST_MODE_Msk                       0x0000003FUL           /*!< Status code */
#define I2C_ST_INT_Msk                        0x00000080UL           /*!< Interrupt flag */

/* Bit field enums: */
typedef enum {
  I2C_ST_MODE_IDLE                           = 0x0UL,                /*!< General - Idle, no valid status information available */
  I2C_ST_MODE_STDONE                         = 0x1UL,                /*!< FS master - Start condition generated */
  I2C_ST_MODE_RSDONE                         = 0x2UL,                /*!< FS master - Repeated start condition generated */
  I2C_ST_MODE_IDLARL                         = 0x3UL,                /*!< FS master - Arbitration lost, unaddressed slave mode entered */
  I2C_ST_MODE_MTADPA                         = 0x4UL,                /*!< FS master transmit - Slave address sent, positive ACK */
  I2C_ST_MODE_MTADNA                         = 0x5UL,                /*!< FS master transmit - Slave address sent, negative ACK */
  I2C_ST_MODE_MTDAPA                         = 0x6UL,                /*!< FS master transmit - Data byte sent, positive ACK */
  I2C_ST_MODE_MTDANA                         = 0x7UL,                /*!< FS master transmit - Data byte sent, negative ACK */
  I2C_ST_MODE_MRADPA                         = 0x8UL,                /*!< FS master receive - Slave addres sent, positive ACK */
  I2C_ST_MODE_MRADNA                         = 0x9UL,                /*!< FS master receive - Slave addres sent, negative ACK */
  I2C_ST_MODE_MRDAPA                         = 0xAUL,                /*!< FS master receive - Data byte received, positive ACK */
  I2C_ST_MODE_MRDANA                         = 0xBUL,                /*!< FS master receive - Data byte received, negative ACK */
  I2C_ST_MODE_MTMCER                         = 0xCUL,                /*!< FS master - Mastercode transmitted, error detected (positive ACK) */
  I2C_ST_MODE_SRADPA                         = 0x10UL,               /*!< FS slave receive - Slave address received, positive ACK */
  I2C_ST_MODE_SRAAPA                         = 0x11UL,               /*!< FS slave receive - Slave address received after arbitration loss, positive ACK */
  I2C_ST_MODE_SRDAPA                         = 0x12UL,               /*!< FS slave receive - Data byte received, positive ACK */
  I2C_ST_MODE_SRDANA                         = 0x13UL,               /*!< FS slave receive - Data byte received, negative ACK */
  I2C_ST_MODE_STADPA                         = 0x14UL,               /*!< FS slave transmit - Slave address received, positive ACK */
  I2C_ST_MODE_STAAPA                         = 0x15UL,               /*!< FS slave transmit - Slave address received, negative ACK */
  I2C_ST_MODE_STDAPA                         = 0x16UL,               /*!< FS slave transmit - Data byte sent, positive ACK */
  I2C_ST_MODE_STDANA                         = 0x17UL,               /*!< FS slave transmit - Data byte sent, negative ACK */
  I2C_ST_MODE_SATADP                         = 0x18UL,               /*!< FS slave transmit alert response - Alert response address received, positive ACK */
  I2C_ST_MODE_SATAAP                         = 0x19UL,               /*!< FS slave transmit alert response - Alert response address received after arbitration loss, positive ACK */
  I2C_ST_MODE_SATDAP                         = 0x1AUL,               /*!< FS slave transmit alert response - Alert response data byte sent, positive ACK */
  I2C_ST_MODE_SATDAN                         = 0x1BUL,               /*!< FS slave transmit alert response - Alert response data byte sent, negative ACK */
  I2C_ST_MODE_SSTOP                          = 0x1CUL,               /*!< FS slave - Slave mode stop condition detected */
  I2C_ST_MODE_SGADPA                         = 0x1DUL,               /*!< FS slave - Global call address received, positive ACK */
  I2C_ST_MODE_SDAAPA                         = 0x1EUL,               /*!< FS slave - Global call address received after arbitration loss, positive ACK */
  I2C_ST_MODE_BERROR                         = 0x1FUL,               /*!< General - Bus error detected (invalid start or stop condition */
  I2C_ST_MODE_HMTMCOK                        = 0x21UL,               /*!< HS master - Master code transmitted OK - switched to HS mode */
  I2C_ST_MODE_HRSDONE                        = 0x22UL,               /*!< HS master - Repeated start condition generated */
  I2C_ST_MODE_HIDLARL                        = 0x23UL,               /*!< HS master - Arbitration lost, HS unaddressed slave mode entered */
  I2C_ST_MODE_HMTADPA                        = 0x24UL,               /*!< HS master transmit - Slave address sent, positive ACK */
  I2C_ST_MODE_HMTADNA                        = 0x25UL,               /*!< HS master transmit - Slave address sent, negative ACK */
  I2C_ST_MODE_HMTDAPA                        = 0x26UL,               /*!< HS master transmit - Data byte sent, positive ACK */
  I2C_ST_MODE_HMTDANA                        = 0x27UL,               /*!< HS master transmit - Data byte sent, negative ACK */
  I2C_ST_MODE_HMRADPA                        = 0x28UL,               /*!< HS master receive - Slave address sent, positive ACK */
  I2C_ST_MODE_HMRADNA                        = 0x29UL,               /*!< HS master receive - Slave address sent, negative ACK */
  I2C_ST_MODE_HMRDAPA                        = 0x2AUL,               /*!< HS master receive - Data byte received, positive ACK */
  I2C_ST_MODE_HMRDANA                        = 0x2BUL,               /*!< HS master receive - Data byte received, negative ACK */
  I2C_ST_MODE_HSRADPA                        = 0x30UL,               /*!< HS slave receive - Slave address received, positive ACK */
  I2C_ST_MODE_HSRDAPA                        = 0x32UL,               /*!< HS slave receive - Data byte received, positive ACK */
  I2C_ST_MODE_HSRDANA                        = 0x33UL,               /*!< HS slave receive - Data byte received, negative ACK */
  I2C_ST_MODE_HSTADPA                        = 0x34UL,               /*!< HS slave transmit - Slave address received, positive ACK */
  I2C_ST_MODE_HSTDAPA                        = 0x36UL,               /*!< HS slave transmit - Data byte sent, positive ACK */
  I2C_ST_MODE_HSTDANA                        = 0x37UL,               /*!< HS slave transmit - Data byte sent, negative ACK */
} I2C_ST_MODE_Enum;

/*--  CST: Status and control register ------------------------------------------------------------------------*/
typedef struct {
  uint32_t BB                     :1;                                /*!< Flag employment bus */
  uint32_t TOCDIV                 :2;                                /*!< Coeff. div */
  uint32_t TOERR                  :1;                                /*!< Flag error simple bus */
  uint32_t TSDA                   :1;                                /*!< Bit test SDA */
  uint32_t TGSCL                  :1;                                /*!< Bit switch SCL */
  uint32_t PECNEXT                :1;                                /*!< Bit control transmit CRC */
  uint32_t PECFAULT               :1;                                /*!< Error flag */
} _I2C_CST_bits;

/* Bit field positions: */
#define I2C_CST_BB_Pos                        0                      /*!< Flag employment bus */
#define I2C_CST_TOCDIV_Pos                    1                      /*!< Coeff. div */
#define I2C_CST_TOERR_Pos                     3                      /*!< Flag error simple bus */
#define I2C_CST_TSDA_Pos                      4                      /*!< Bit test SDA */
#define I2C_CST_TGSCL_Pos                     5                      /*!< Bit switch SCL */
#define I2C_CST_PECNEXT_Pos                   6                      /*!< Bit control transmit CRC */
#define I2C_CST_PECFAULT_Pos                  7                      /*!< Error flag */

/* Bit field masks: */
#define I2C_CST_BB_Msk                        0x00000001UL           /*!< Flag employment bus */
#define I2C_CST_TOCDIV_Msk                    0x00000006UL           /*!< Coeff. div */
#define I2C_CST_TOERR_Msk                     0x00000008UL           /*!< Flag error simple bus */
#define I2C_CST_TSDA_Msk                      0x00000010UL           /*!< Bit test SDA */
#define I2C_CST_TGSCL_Msk                     0x00000020UL           /*!< Bit switch SCL */
#define I2C_CST_PECNEXT_Msk                   0x00000040UL           /*!< Bit control transmit CRC */
#define I2C_CST_PECFAULT_Msk                  0x00000080UL           /*!< Error flag */

/* Bit field enums: */
typedef enum {
  I2C_CST_TOCDIV_Disable                     = 0x0UL,                /*!< disable clock */
  I2C_CST_TOCDIV_Div4                        = 0x1UL,                /*!< clock divided by 4 */
  I2C_CST_TOCDIV_Div8                        = 0x2UL,                /*!< clock divided by 8 */
  I2C_CST_TOCDIV_Div16                       = 0x3UL,                /*!< clock divided by 16 */
} I2C_CST_TOCDIV_Enum;

/*--  CTL0: Control register 0 --------------------------------------------------------------------------------*/
typedef struct {
  uint32_t START                  :1;                                /*!< Start bit */
  uint32_t STOP                   :1;                                /*!< Stop bit */
  uint32_t INTEN                  :1;                                /*!< Interrupt enable bit */
  uint32_t UNADDR                 :1;                                /*!< Unaddress mode, slave response to any address */
  uint32_t ACK                    :1;                                /*!< Acknowledgment bit reception */
  uint32_t GCMEN                  :1;                                /*!< Control bit part a response to the general call address */
  uint32_t SMBARE                 :1;                                /*!< Control bit part a response to the response address */
  uint32_t CLRST                  :1;                                /*!< Bit reset flag interrupt */
} _I2C_CTL0_bits;

/* Bit field positions: */
#define I2C_CTL0_START_Pos                    0                      /*!< Start bit */
#define I2C_CTL0_STOP_Pos                     1                      /*!< Stop bit */
#define I2C_CTL0_INTEN_Pos                    2                      /*!< Interrupt enable bit */
#define I2C_CTL0_UNADDR_Pos                   3                      /*!< Unaddress mode, slave response to any address */
#define I2C_CTL0_ACK_Pos                      4                      /*!< Acknowledgment bit reception */
#define I2C_CTL0_GCMEN_Pos                    5                      /*!< Control bit part a response to the general call address */
#define I2C_CTL0_SMBARE_Pos                   6                      /*!< Control bit part a response to the response address */
#define I2C_CTL0_CLRST_Pos                    7                      /*!< Bit reset flag interrupt */

/* Bit field masks: */
#define I2C_CTL0_START_Msk                    0x00000001UL           /*!< Start bit */
#define I2C_CTL0_STOP_Msk                     0x00000002UL           /*!< Stop bit */
#define I2C_CTL0_INTEN_Msk                    0x00000004UL           /*!< Interrupt enable bit */
#define I2C_CTL0_UNADDR_Msk                   0x00000008UL           /*!< Unaddress mode, slave response to any address */
#define I2C_CTL0_ACK_Msk                      0x00000010UL           /*!< Acknowledgment bit reception */
#define I2C_CTL0_GCMEN_Msk                    0x00000020UL           /*!< Control bit part a response to the general call address */
#define I2C_CTL0_SMBARE_Msk                   0x00000040UL           /*!< Control bit part a response to the response address */
#define I2C_CTL0_CLRST_Msk                    0x00000080UL           /*!< Bit reset flag interrupt */

/*--  ADDR: Register own address ------------------------------------------------------------------------------*/
typedef struct {
  uint32_t ADDR                   :7;                                /*!< Own 7-bit address */
  uint32_t SAEN                   :1;                                /*!< Enable bit address recognition */
} _I2C_ADDR_bits;

/* Bit field positions: */
#define I2C_ADDR_ADDR_Pos                     0                      /*!< Own 7-bit address */
#define I2C_ADDR_SAEN_Pos                     7                      /*!< Enable bit address recognition */

/* Bit field masks: */
#define I2C_ADDR_ADDR_Msk                     0x0000007FUL           /*!< Own 7-bit address */
#define I2C_ADDR_SAEN_Msk                     0x00000080UL           /*!< Enable bit address recognition */

/*--  CTL1: Control register 1 --------------------------------------------------------------------------------*/
typedef struct {
  uint32_t ENABLE                 :1;                                /*!< Enable I2C */
  uint32_t SCLFRQ                 :7;                                /*!< Field frequency selection signal at pin SCL in master mode (bits [6:0]) */
} _I2C_CTL1_bits;

/* Bit field positions: */
#define I2C_CTL1_ENABLE_Pos                   0                      /*!< Enable I2C */
#define I2C_CTL1_SCLFRQ_Pos                   1                      /*!< Field frequency selection signal at pin SCL in master mode (bits [6:0]) */

/* Bit field masks: */
#define I2C_CTL1_ENABLE_Msk                   0x00000001UL           /*!< Enable I2C */
#define I2C_CTL1_SCLFRQ_Msk                   0x000000FEUL           /*!< Field frequency selection signal at pin SCL in master mode (bits [6:0]) */

/*--  TOPR: Prescaler load register ---------------------------------------------------------------------------*/
typedef struct {
  uint32_t SMBTOPR                :8;                                /*!< Prescaler reload value field */
} _I2C_TOPR_bits;

/* Bit field positions: */
#define I2C_TOPR_SMBTOPR_Pos                  0                      /*!< Prescaler reload value field */

/* Bit field masks: */
#define I2C_TOPR_SMBTOPR_Msk                  0x000000FFUL           /*!< Prescaler reload value field */

/*--  CTL2: Control register 2 --------------------------------------------------------------------------------*/
typedef struct {
  uint32_t S10ADR                 :3;                                /*!< Upper bits of 10-bit slave address */
  uint32_t S10EN                  :1;                                /*!< Bit enabled 10-bit addressing slave */
  uint32_t HSDIV                  :4;                                /*!< Field frequency selection signal at pin SCL in HS master mode (bits [3:0]) */
} _I2C_CTL2_bits;

/* Bit field positions: */
#define I2C_CTL2_S10ADR_Pos                   0                      /*!< Upper bits of 10-bit slave address */
#define I2C_CTL2_S10EN_Pos                    3                      /*!< Bit enabled 10-bit addressing slave */
#define I2C_CTL2_HSDIV_Pos                    4                      /*!< Field frequency selection signal at pin SCL in HS master mode (bits [3:0]) */

/* Bit field masks: */
#define I2C_CTL2_S10ADR_Msk                   0x00000007UL           /*!< Upper bits of 10-bit slave address */
#define I2C_CTL2_S10EN_Msk                    0x00000008UL           /*!< Bit enabled 10-bit addressing slave */
#define I2C_CTL2_HSDIV_Msk                    0x000000F0UL           /*!< Field frequency selection signal at pin SCL in HS master mode (bits [3:0]) */

/*--  CTL3: Control register 3 --------------------------------------------------------------------------------*/
typedef struct {
  uint32_t SCLFRQ                 :8;                                /*!< Field frequency selection signal at pin SCL in master mode (bits [14:7]) */
} _I2C_CTL3_bits;

/* Bit field positions: */
#define I2C_CTL3_SCLFRQ_Pos                   0                      /*!< Field frequency selection signal at pin SCL in master mode (bits [14:7]) */

/* Bit field masks: */
#define I2C_CTL3_SCLFRQ_Msk                   0x000000FFUL           /*!< Field frequency selection signal at pin SCL in master mode (bits [14:7]) */

/*--  CTL4: Control Register 4 --------------------------------------------------------------------------------*/
typedef struct {
  uint32_t HSDIV                  :8;                                /*!< Field frequency selection signal at pin SCL in HS master mode (bits [11:4]) */
} _I2C_CTL4_bits;

/* Bit field positions: */
#define I2C_CTL4_HSDIV_Pos                    0                      /*!< Field frequency selection signal at pin SCL in HS master mode (bits [11:4]) */

/* Bit field masks: */
#define I2C_CTL4_HSDIV_Msk                    0x000000FFUL           /*!< Field frequency selection signal at pin SCL in HS master mode (bits [11:4]) */

/*--  EADDR: Extended address Register ------------------------------------------------------------------------*/
typedef struct {
  uint32_t ADDR                   :10;                               /*!< Additional adress */
  uint32_t                        :5;                                /*!< RESERVED */
  uint32_t SAEN                   :1;                                /*!< Enable bit address recognition */
} _I2C_EADDR_bits;

/* Bit field positions: */
#define I2C_EADDR_ADDR_Pos                    0                      /*!< Additional adress */
#define I2C_EADDR_SAEN_Pos                    15                     /*!< Enable bit address recognition */

/* Bit field masks: */
#define I2C_EADDR_ADDR_Msk                    0x000003FFUL           /*!< Additional adress */
#define I2C_EADDR_SAEN_Msk                    0x00008000UL           /*!< Enable bit address recognition */

//Cluster EADDR:
typedef struct {
  union {
  /*!< Extended address Register */
    __IO uint32_t EADDR;                                             /*!< EADDR : type used for word access */
    __IO _I2C_EADDR_bits EADDR_bit;                                  /*!< EADDR_bit: structure used for bit access */
  };
} _I2C_EADDR_TypeDef;
typedef struct {
  union {                                                               /*!< Data register */
    __IO uint32_t SDA;                                               /*!< SDA    : type used for word access */
    __IO _I2C_SDA_bits  SDA_bit;                                     /*!< SDA_bit: structure used for bit access */
  };
  union {                                                               /*!< Status register */
    __I uint32_t ST;                                                 /*!< ST    : type used for word access */
    __I _I2C_ST_bits  ST_bit;                                        /*!< ST_bit: structure used for bit access */
  };
  union {                                                               /*!< Status and control register */
    __IO uint32_t CST;                                               /*!< CST    : type used for word access */
    __IO _I2C_CST_bits  CST_bit;                                     /*!< CST_bit: structure used for bit access */
  };
  union {                                                               /*!< Control register 0 */
    __IO uint32_t CTL0;                                              /*!< CTL0    : type used for word access */
    __IO _I2C_CTL0_bits  CTL0_bit;                                   /*!< CTL0_bit: structure used for bit access */
  };
  union {                                                               /*!< Register own address */
    __IO uint32_t ADDR;                                              /*!< ADDR    : type used for word access */
    __IO _I2C_ADDR_bits  ADDR_bit;                                   /*!< ADDR_bit: structure used for bit access */
  };
  union {                                                               /*!< Control register 1 */
    __IO uint32_t CTL1;                                              /*!< CTL1    : type used for word access */
    __IO _I2C_CTL1_bits  CTL1_bit;                                   /*!< CTL1_bit: structure used for bit access */
  };
  union {                                                               /*!< Prescaler load register */
    __IO uint32_t TOPR;                                              /*!< TOPR    : type used for word access */
    __IO _I2C_TOPR_bits  TOPR_bit;                                   /*!< TOPR_bit: structure used for bit access */
  };
  union {                                                               /*!< Control register 2 */
    __IO uint32_t CTL2;                                              /*!< CTL2    : type used for word access */
    __IO _I2C_CTL2_bits  CTL2_bit;                                   /*!< CTL2_bit: structure used for bit access */
  };
  union {                                                               /*!< Control register 3 */
    __IO uint32_t CTL3;                                              /*!< CTL3    : type used for word access */
    __IO _I2C_CTL3_bits  CTL3_bit;                                   /*!< CTL3_bit: structure used for bit access */
  };
  union {                                                               /*!< Control Register 4 */
    __IO uint32_t CTL4;                                              /*!< CTL4    : type used for word access */
    __IO _I2C_CTL4_bits  CTL4_bit;                                   /*!< CTL4_bit: structure used for bit access */
  };
  _I2C_EADDR_TypeDef EADDR[8];
} I2C_TypeDef;


/******************************************************************************/
/*                         PWM registers                                      */
/******************************************************************************/

/*--  TBCTL: Time-Base Control Register -----------------------------------------------------------------------*/
typedef struct {
  uint32_t CTRMODE                :2;                                /*!< Counter mode */
  uint32_t PHSEN                  :1;                                /*!< Counter register load from phase register enable */
  uint32_t PRDLD                  :1;                                /*!< Active period register load from shadow register select */
  uint32_t SYNCOSEL               :2;                                /*!< Synchronization Output Select. These bits select the source of the PWM_SYNCO signal. */
  uint32_t SWFSYNC                :1;                                /*!< Software forced synchronization pulse */
  uint32_t HSPCLKDIV              :3;                                /*!< High speed time-base clock prescale bits */
  uint32_t CLKDIV                 :3;                                /*!< Time-base clock prescale bits */
  uint32_t PHSDIR                 :1;                                /*!< Phase direction bit */
  uint32_t FREESOFT               :2;                                /*!< Emulation mode bits - select the behavior of the time-base counter during emulation events */
  uint32_t SHDWGLOB               :1;                                /*!< Global enabe for all shadow loads */
} _PWM_TBCTL_bits;

/* Bit field positions: */
#define PWM_TBCTL_CTRMODE_Pos                 0                      /*!< Counter mode */
#define PWM_TBCTL_PHSEN_Pos                   2                      /*!< Counter register load from phase register enable */
#define PWM_TBCTL_PRDLD_Pos                   3                      /*!< Active period register load from shadow register select */
#define PWM_TBCTL_SYNCOSEL_Pos                4                      /*!< Synchronization Output Select. These bits select the source of the PWM_SYNCO signal. */
#define PWM_TBCTL_SWFSYNC_Pos                 6                      /*!< Software forced synchronization pulse */
#define PWM_TBCTL_HSPCLKDIV_Pos               7                      /*!< High speed time-base clock prescale bits */
#define PWM_TBCTL_CLKDIV_Pos                  10                     /*!< Time-base clock prescale bits */
#define PWM_TBCTL_PHSDIR_Pos                  13                     /*!< Phase direction bit */
#define PWM_TBCTL_FREESOFT_Pos                14                     /*!< Emulation mode bits - select the behavior of the time-base counter during emulation events */
#define PWM_TBCTL_SHDWGLOB_Pos                16                     /*!< Global enabe for all shadow loads */

/* Bit field masks: */
#define PWM_TBCTL_CTRMODE_Msk                 0x00000003UL           /*!< Counter mode */
#define PWM_TBCTL_PHSEN_Msk                   0x00000004UL           /*!< Counter register load from phase register enable */
#define PWM_TBCTL_PRDLD_Msk                   0x00000008UL           /*!< Active period register load from shadow register select */
#define PWM_TBCTL_SYNCOSEL_Msk                0x00000030UL           /*!< Synchronization Output Select. These bits select the source of the PWM_SYNCO signal. */
#define PWM_TBCTL_SWFSYNC_Msk                 0x00000040UL           /*!< Software forced synchronization pulse */
#define PWM_TBCTL_HSPCLKDIV_Msk               0x00000380UL           /*!< High speed time-base clock prescale bits */
#define PWM_TBCTL_CLKDIV_Msk                  0x00001C00UL           /*!< Time-base clock prescale bits */
#define PWM_TBCTL_PHSDIR_Msk                  0x00002000UL           /*!< Phase direction bit */
#define PWM_TBCTL_FREESOFT_Msk                0x0000C000UL           /*!< Emulation mode bits - select the behavior of the time-base counter during emulation events */
#define PWM_TBCTL_SHDWGLOB_Msk                0x00010000UL           /*!< Global enabe for all shadow loads */

/* Bit field enums: */
typedef enum {
  PWM_TBCTL_CTRMODE_Up                       = 0x0UL,                /*!< count direction up */
  PWM_TBCTL_CTRMODE_Down                     = 0x1UL,                /*!< count direction down */
  PWM_TBCTL_CTRMODE_UpDown                   = 0x2UL,                /*!< count direction up-down */
  PWM_TBCTL_CTRMODE_Stop                     = 0x3UL,                /*!< counter stopped */
} PWM_TBCTL_CTRMODE_Enum;

typedef enum {
  PWM_TBCTL_SYNCOSEL_SYNCI                   = 0x0UL,                /*!< PWM_SYNCI is source for PWM_SYNCO */
  PWM_TBCTL_SYNCOSEL_CTREqZero               = 0x1UL,                /*!< CTR = 0000h is source for PWM_SYNCO */
  PWM_TBCTL_SYNCOSEL_CTREqCMPB               = 0x2UL,                /*!< CTR = CMPB is source for PWM_SYNCO */
  PWM_TBCTL_SYNCOSEL_Disable                 = 0x3UL,                /*!< PWM_SYNCO generation disabled */
} PWM_TBCTL_SYNCOSEL_Enum;

typedef enum {
  PWM_TBCTL_HSPCLKDIV_Div1                   = 0x0UL,                /*!< clock not divided */
  PWM_TBCTL_HSPCLKDIV_Div2                   = 0x1UL,                /*!< clock divided by 2 */
  PWM_TBCTL_HSPCLKDIV_Div4                   = 0x2UL,                /*!< clock divided by 4 */
  PWM_TBCTL_HSPCLKDIV_Div6                   = 0x3UL,                /*!< clock divided by 6 */
  PWM_TBCTL_HSPCLKDIV_Div8                   = 0x4UL,                /*!< clock divided by 8 */
  PWM_TBCTL_HSPCLKDIV_Div10                  = 0x5UL,                /*!< clock divided by 10 */
  PWM_TBCTL_HSPCLKDIV_Div12                  = 0x6UL,                /*!< clock divided by 12 */
  PWM_TBCTL_HSPCLKDIV_Div14                  = 0x7UL,                /*!< clock divided by 14 */
} PWM_TBCTL_HSPCLKDIV_Enum;

typedef enum {
  PWM_TBCTL_CLKDIV_Div1                      = 0x0UL,                /*!< clock not divided */
  PWM_TBCTL_CLKDIV_Div2                      = 0x1UL,                /*!< clock divided by 2 */
  PWM_TBCTL_CLKDIV_Div4                      = 0x2UL,                /*!< clock divided by 4 */
  PWM_TBCTL_CLKDIV_Div8                      = 0x3UL,                /*!< clock divided by 8 */
  PWM_TBCTL_CLKDIV_Div16                     = 0x4UL,                /*!< clock divided by 16 */
  PWM_TBCTL_CLKDIV_Div32                     = 0x5UL,                /*!< clock divided by 32 */
  PWM_TBCTL_CLKDIV_Div64                     = 0x6UL,                /*!< clock divided by 64 */
  PWM_TBCTL_CLKDIV_Div128                    = 0x7UL,                /*!< clock divided by 128 */
} PWM_TBCTL_CLKDIV_Enum;

typedef enum {
  PWM_TBCTL_FREESOFT_StopAtTBCLK             = 0x0UL,                /*!< stop timer at next TBCLK tact */
  PWM_TBCTL_FREESOFT_StopAtPeriod            = 0x1UL,                /*!< stop timer when period ends */
  PWM_TBCTL_FREESOFT_FreeRun                 = 0x2UL,                /*!< free run mode */
} PWM_TBCTL_FREESOFT_Enum;

/*--  TBSTS: Time-Base Status Register ------------------------------------------------------------------------*/
typedef struct {
  uint32_t CTRDIR                 :1;                                /*!< Time-Base counter direction status bit */
  uint32_t SYNCI                  :1;                                /*!< Input synchronization latched status bit */
  uint32_t CTRMAX                 :1;                                /*!< Time-Base counter max latched status bit */
} _PWM_TBSTS_bits;

/* Bit field positions: */
#define PWM_TBSTS_CTRDIR_Pos                  0                      /*!< Time-Base counter direction status bit */
#define PWM_TBSTS_SYNCI_Pos                   1                      /*!< Input synchronization latched status bit */
#define PWM_TBSTS_CTRMAX_Pos                  2                      /*!< Time-Base counter max latched status bit */

/* Bit field masks: */
#define PWM_TBSTS_CTRDIR_Msk                  0x00000001UL           /*!< Time-Base counter direction status bit */
#define PWM_TBSTS_SYNCI_Msk                   0x00000002UL           /*!< Input synchronization latched status bit */
#define PWM_TBSTS_CTRMAX_Msk                  0x00000004UL           /*!< Time-Base counter max latched status bit */

/*--  TBPHS: Time-Base Phase Register -------------------------------------------------------------------------*/
typedef struct {
  uint32_t                        :8;                                /*!< RESERVED */
  uint32_t TBPHSHR                :8;                                /*!< Time-base counter phase in High-Resolution mode */
  uint32_t TBPHS                  :16;                               /*!< Time-base counter phase */
} _PWM_TBPHS_bits;

/* Bit field positions: */
#define PWM_TBPHS_TBPHSHR_Pos                 8                      /*!< Time-base counter phase in High-Resolution mode */
#define PWM_TBPHS_TBPHS_Pos                   16                     /*!< Time-base counter phase */

/* Bit field masks: */
#define PWM_TBPHS_TBPHSHR_Msk                 0x0000FF00UL           /*!< Time-base counter phase in High-Resolution mode */
#define PWM_TBPHS_TBPHS_Msk                   0xFFFF0000UL           /*!< Time-base counter phase */

/*--  TBCTR: Time-Base Counter Register -----------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :16;                               /*!< Current time-base counter value */
} _PWM_TBCTR_bits;

/* Bit field positions: */
#define PWM_TBCTR_VAL_Pos                     0                      /*!< Current time-base counter value */

/* Bit field masks: */
#define PWM_TBCTR_VAL_Msk                     0x0000FFFFUL           /*!< Current time-base counter value */

/*--  TBPRD: Time-Base Period Register ------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :16;                               /*!< Period of the time-base counter */
} _PWM_TBPRD_bits;

/* Bit field positions: */
#define PWM_TBPRD_VAL_Pos                     0                      /*!< Period of the time-base counter */

/* Bit field masks: */
#define PWM_TBPRD_VAL_Msk                     0x0000FFFFUL           /*!< Period of the time-base counter */

/*--  CMPCTL: Counter-Compare Control Register ----------------------------------------------------------------*/
typedef struct {
  uint32_t LOADAMODE              :2;                                /*!< Active CMPA load from shadow select mode */
  uint32_t LOADBMODE              :2;                                /*!< Active CMPB load from shadow select mode */
  uint32_t SHDWAMODE              :1;                                /*!< CMPA register operating mode */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t SHDWBMODE              :1;                                /*!< CMPB register operating mode */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t SHDWAFULL              :1;                                /*!< CMPA shadow register full status flag */
  uint32_t SHDWBFULL              :1;                                /*!< CMPB shadow register full status flag */
} _PWM_CMPCTL_bits;

/* Bit field positions: */
#define PWM_CMPCTL_LOADAMODE_Pos              0                      /*!< Active CMPA load from shadow select mode */
#define PWM_CMPCTL_LOADBMODE_Pos              2                      /*!< Active CMPB load from shadow select mode */
#define PWM_CMPCTL_SHDWAMODE_Pos              4                      /*!< CMPA register operating mode */
#define PWM_CMPCTL_SHDWBMODE_Pos              6                      /*!< CMPB register operating mode */
#define PWM_CMPCTL_SHDWAFULL_Pos              8                      /*!< CMPA shadow register full status flag */
#define PWM_CMPCTL_SHDWBFULL_Pos              9                      /*!< CMPB shadow register full status flag */

/* Bit field masks: */
#define PWM_CMPCTL_LOADAMODE_Msk              0x00000003UL           /*!< Active CMPA load from shadow select mode */
#define PWM_CMPCTL_LOADBMODE_Msk              0x0000000CUL           /*!< Active CMPB load from shadow select mode */
#define PWM_CMPCTL_SHDWAMODE_Msk              0x00000010UL           /*!< CMPA register operating mode */
#define PWM_CMPCTL_SHDWBMODE_Msk              0x00000040UL           /*!< CMPB register operating mode */
#define PWM_CMPCTL_SHDWAFULL_Msk              0x00000100UL           /*!< CMPA shadow register full status flag */
#define PWM_CMPCTL_SHDWBFULL_Msk              0x00000200UL           /*!< CMPB shadow register full status flag */

/* Bit field enums: */
typedef enum {
  PWM_CMPCTL_LOADAMODE_CTREqZero             = 0x0UL,                /*!< shadow load for CMPx (x=A,B) when CTR = 0 */
  PWM_CMPCTL_LOADAMODE_CTREqPRD              = 0x1UL,                /*!< shadow load for CMPx (x=A,B) when CTR = PRD */
  PWM_CMPCTL_LOADAMODE_CTREqZeroPRD          = 0x2UL,                /*!< shadow load for CMPx (x=A,B) when CTR = 0 or CTR = PRD */
  PWM_CMPCTL_LOADAMODE_Disable               = 0x3UL,                /*!< shadow load for CMPx (x=A,B) disabled */
} PWM_CMPCTL_LOADAMODE_Enum;

typedef enum {
  PWM_CMPCTL_LOADBMODE_CTREqZero             = 0x0UL,                /*!< shadow load for CMPx (x=A,B) when CTR = 0 */
  PWM_CMPCTL_LOADBMODE_CTREqPRD              = 0x1UL,                /*!< shadow load for CMPx (x=A,B) when CTR = PRD */
  PWM_CMPCTL_LOADBMODE_CTREqZeroPRD          = 0x2UL,                /*!< shadow load for CMPx (x=A,B) when CTR = 0 or CTR = PRD */
  PWM_CMPCTL_LOADBMODE_Disable               = 0x3UL,                /*!< shadow load for CMPx (x=A,B) disabled */
} PWM_CMPCTL_LOADBMODE_Enum;

/*--  CMPA: Counter-Compare A Register ------------------------------------------------------------------------*/
typedef struct {
  uint32_t                        :8;                                /*!< RESERVED */
  uint32_t CMPAHR                 :8;                                /*!< The value compared to the time-base counter (TBCTR) in High-Resolution mode */
  uint32_t CMPA                   :16;                               /*!< The value compared to the time-base counter (TBCTR) */
} _PWM_CMPA_bits;

/* Bit field positions: */
#define PWM_CMPA_CMPAHR_Pos                   8                      /*!< The value compared to the time-base counter (TBCTR) in High-Resolution mode */
#define PWM_CMPA_CMPA_Pos                     16                     /*!< The value compared to the time-base counter (TBCTR) */

/* Bit field masks: */
#define PWM_CMPA_CMPAHR_Msk                   0x0000FF00UL           /*!< The value compared to the time-base counter (TBCTR) in High-Resolution mode */
#define PWM_CMPA_CMPA_Msk                     0xFFFF0000UL           /*!< The value compared to the time-base counter (TBCTR) */

/*--  CMPB: Counter-Compare B Register ------------------------------------------------------------------------*/
typedef struct {
  uint32_t                        :16;                               /*!< RESERVED */
  uint32_t CMPB                   :16;                               /*!< The value compared to the time-base counter (TBCTR) */
} _PWM_CMPB_bits;

/* Bit field positions: */
#define PWM_CMPB_CMPB_Pos                     16                     /*!< The value compared to the time-base counter (TBCTR) */

/* Bit field masks: */
#define PWM_CMPB_CMPB_Msk                     0xFFFF0000UL           /*!< The value compared to the time-base counter (TBCTR) */

/*--  AQCTLA: Action-Qualifier Output A Control Register ------------------------------------------------------*/
typedef struct {
  uint32_t ZRO                    :2;                                /*!< Action when counter equals zero */
  uint32_t PRD                    :2;                                /*!< Action when the counter equals the period */
  uint32_t CAU                    :2;                                /*!< Action when the counter equals the active CMPA register and the counter is incrementing */
  uint32_t CAD                    :2;                                /*!< Action when the counter equals the active CMPA register and the counter is decrementing */
  uint32_t CBU                    :2;                                /*!< Action when the counter equals the active CMPB register and the counter is incrementing */
  uint32_t CBD                    :2;                                /*!< Action when the time-base counter equals the active CMPB register and the counter is decrementing
 */
} _PWM_AQCTLA_bits;

/* Bit field positions: */
#define PWM_AQCTLA_ZRO_Pos                    0                      /*!< Action when counter equals zero */
#define PWM_AQCTLA_PRD_Pos                    2                      /*!< Action when the counter equals the period */
#define PWM_AQCTLA_CAU_Pos                    4                      /*!< Action when the counter equals the active CMPA register and the counter is incrementing */
#define PWM_AQCTLA_CAD_Pos                    6                      /*!< Action when the counter equals the active CMPA register and the counter is decrementing */
#define PWM_AQCTLA_CBU_Pos                    8                      /*!< Action when the counter equals the active CMPB register and the counter is incrementing */
#define PWM_AQCTLA_CBD_Pos                    10                     /*!< Action when the time-base counter equals the active CMPB register and the counter is decrementing
 */

/* Bit field masks: */
#define PWM_AQCTLA_ZRO_Msk                    0x00000003UL           /*!< Action when counter equals zero */
#define PWM_AQCTLA_PRD_Msk                    0x0000000CUL           /*!< Action when the counter equals the period */
#define PWM_AQCTLA_CAU_Msk                    0x00000030UL           /*!< Action when the counter equals the active CMPA register and the counter is incrementing */
#define PWM_AQCTLA_CAD_Msk                    0x000000C0UL           /*!< Action when the counter equals the active CMPA register and the counter is decrementing */
#define PWM_AQCTLA_CBU_Msk                    0x00000300UL           /*!< Action when the counter equals the active CMPB register and the counter is incrementing */
#define PWM_AQCTLA_CBD_Msk                    0x00000C00UL           /*!< Action when the time-base counter equals the active CMPB register and the counter is decrementing
 */

/* Bit field enums: */
typedef enum {
  PWM_AQCTLA_ZRO_NoAction                    = 0x0UL,                /*!< no action */
  PWM_AQCTLA_ZRO_Clear                       = 0x1UL,                /*!< clear PWMA/PWMB */
  PWM_AQCTLA_ZRO_Set                         = 0x2UL,                /*!< set PWMA/PWMB */
  PWM_AQCTLA_ZRO_Toggle                      = 0x3UL,                /*!< inverse PWMA/PWMB */
} PWM_AQCTLA_ZRO_Enum;

typedef enum {
  PWM_AQCTLA_PRD_NoAction                    = 0x0UL,                /*!< no action */
  PWM_AQCTLA_PRD_Clear                       = 0x1UL,                /*!< clear PWMA/PWMB */
  PWM_AQCTLA_PRD_Set                         = 0x2UL,                /*!< set PWMA/PWMB */
  PWM_AQCTLA_PRD_Toggle                      = 0x3UL,                /*!< inverse PWMA/PWMB */
} PWM_AQCTLA_PRD_Enum;

typedef enum {
  PWM_AQCTLA_CAU_NoAction                    = 0x0UL,                /*!< no action */
  PWM_AQCTLA_CAU_Clear                       = 0x1UL,                /*!< clear PWMA/PWMB */
  PWM_AQCTLA_CAU_Set                         = 0x2UL,                /*!< set PWMA/PWMB */
  PWM_AQCTLA_CAU_Toggle                      = 0x3UL,                /*!< inverse PWMA/PWMB */
} PWM_AQCTLA_CAU_Enum;

typedef enum {
  PWM_AQCTLA_CAD_NoAction                    = 0x0UL,                /*!< no action */
  PWM_AQCTLA_CAD_Clear                       = 0x1UL,                /*!< clear PWMA/PWMB */
  PWM_AQCTLA_CAD_Set                         = 0x2UL,                /*!< set PWMA/PWMB */
  PWM_AQCTLA_CAD_Toggle                      = 0x3UL,                /*!< inverse PWMA/PWMB */
} PWM_AQCTLA_CAD_Enum;

typedef enum {
  PWM_AQCTLA_CBU_NoAction                    = 0x0UL,                /*!< no action */
  PWM_AQCTLA_CBU_Clear                       = 0x1UL,                /*!< clear PWMA/PWMB */
  PWM_AQCTLA_CBU_Set                         = 0x2UL,                /*!< set PWMA/PWMB */
  PWM_AQCTLA_CBU_Toggle                      = 0x3UL,                /*!< inverse PWMA/PWMB */
} PWM_AQCTLA_CBU_Enum;

typedef enum {
  PWM_AQCTLA_CBD_NoAction                    = 0x0UL,                /*!< no action */
  PWM_AQCTLA_CBD_Clear                       = 0x1UL,                /*!< clear PWMA/PWMB */
  PWM_AQCTLA_CBD_Set                         = 0x2UL,                /*!< set PWMA/PWMB */
  PWM_AQCTLA_CBD_Toggle                      = 0x3UL,                /*!< inverse PWMA/PWMB */
} PWM_AQCTLA_CBD_Enum;

/*--  AQCTLB: Action-Qualifier Output B Control Register ------------------------------------------------------*/
typedef struct {
  uint32_t ZRO                    :2;                                /*!< Action when counter equals zero */
  uint32_t PRD                    :2;                                /*!< Action when the counter equals the period */
  uint32_t CAU                    :2;                                /*!< Action when the counter equals the active CMPA register and the counter is incrementing */
  uint32_t CAD                    :2;                                /*!< Action when the counter equals the active CMPA register and the counter is decrementing */
  uint32_t CBU                    :2;                                /*!< Action when the counter equals the active CMPB register and the counter is incrementing */
  uint32_t CBD                    :2;                                /*!< Action when the time-base counter equals the active CMPB register and the counter is decrementing
 */
} _PWM_AQCTLB_bits;

/* Bit field positions: */
#define PWM_AQCTLB_ZRO_Pos                    0                      /*!< Action when counter equals zero */
#define PWM_AQCTLB_PRD_Pos                    2                      /*!< Action when the counter equals the period */
#define PWM_AQCTLB_CAU_Pos                    4                      /*!< Action when the counter equals the active CMPA register and the counter is incrementing */
#define PWM_AQCTLB_CAD_Pos                    6                      /*!< Action when the counter equals the active CMPA register and the counter is decrementing */
#define PWM_AQCTLB_CBU_Pos                    8                      /*!< Action when the counter equals the active CMPB register and the counter is incrementing */
#define PWM_AQCTLB_CBD_Pos                    10                     /*!< Action when the time-base counter equals the active CMPB register and the counter is decrementing
 */

/* Bit field masks: */
#define PWM_AQCTLB_ZRO_Msk                    0x00000003UL           /*!< Action when counter equals zero */
#define PWM_AQCTLB_PRD_Msk                    0x0000000CUL           /*!< Action when the counter equals the period */
#define PWM_AQCTLB_CAU_Msk                    0x00000030UL           /*!< Action when the counter equals the active CMPA register and the counter is incrementing */
#define PWM_AQCTLB_CAD_Msk                    0x000000C0UL           /*!< Action when the counter equals the active CMPA register and the counter is decrementing */
#define PWM_AQCTLB_CBU_Msk                    0x00000300UL           /*!< Action when the counter equals the active CMPB register and the counter is incrementing */
#define PWM_AQCTLB_CBD_Msk                    0x00000C00UL           /*!< Action when the time-base counter equals the active CMPB register and the counter is decrementing
 */

/* Bit field enums: */
typedef enum {
  PWM_AQCTLB_ZRO_NoAction                    = 0x0UL,                /*!< no action */
  PWM_AQCTLB_ZRO_Clear                       = 0x1UL,                /*!< clear PWMA/PWMB */
  PWM_AQCTLB_ZRO_Set                         = 0x2UL,                /*!< set PWMA/PWMB */
  PWM_AQCTLB_ZRO_Toggle                      = 0x3UL,                /*!< inverse PWMA/PWMB */
} PWM_AQCTLB_ZRO_Enum;

typedef enum {
  PWM_AQCTLB_PRD_NoAction                    = 0x0UL,                /*!< no action */
  PWM_AQCTLB_PRD_Clear                       = 0x1UL,                /*!< clear PWMA/PWMB */
  PWM_AQCTLB_PRD_Set                         = 0x2UL,                /*!< set PWMA/PWMB */
  PWM_AQCTLB_PRD_Toggle                      = 0x3UL,                /*!< inverse PWMA/PWMB */
} PWM_AQCTLB_PRD_Enum;

typedef enum {
  PWM_AQCTLB_CAU_NoAction                    = 0x0UL,                /*!< no action */
  PWM_AQCTLB_CAU_Clear                       = 0x1UL,                /*!< clear PWMA/PWMB */
  PWM_AQCTLB_CAU_Set                         = 0x2UL,                /*!< set PWMA/PWMB */
  PWM_AQCTLB_CAU_Toggle                      = 0x3UL,                /*!< inverse PWMA/PWMB */
} PWM_AQCTLB_CAU_Enum;

typedef enum {
  PWM_AQCTLB_CAD_NoAction                    = 0x0UL,                /*!< no action */
  PWM_AQCTLB_CAD_Clear                       = 0x1UL,                /*!< clear PWMA/PWMB */
  PWM_AQCTLB_CAD_Set                         = 0x2UL,                /*!< set PWMA/PWMB */
  PWM_AQCTLB_CAD_Toggle                      = 0x3UL,                /*!< inverse PWMA/PWMB */
} PWM_AQCTLB_CAD_Enum;

typedef enum {
  PWM_AQCTLB_CBU_NoAction                    = 0x0UL,                /*!< no action */
  PWM_AQCTLB_CBU_Clear                       = 0x1UL,                /*!< clear PWMA/PWMB */
  PWM_AQCTLB_CBU_Set                         = 0x2UL,                /*!< set PWMA/PWMB */
  PWM_AQCTLB_CBU_Toggle                      = 0x3UL,                /*!< inverse PWMA/PWMB */
} PWM_AQCTLB_CBU_Enum;

typedef enum {
  PWM_AQCTLB_CBD_NoAction                    = 0x0UL,                /*!< no action */
  PWM_AQCTLB_CBD_Clear                       = 0x1UL,                /*!< clear PWMA/PWMB */
  PWM_AQCTLB_CBD_Set                         = 0x2UL,                /*!< set PWMA/PWMB */
  PWM_AQCTLB_CBD_Toggle                      = 0x3UL,                /*!< inverse PWMA/PWMB */
} PWM_AQCTLB_CBD_Enum;

/*--  AQSFRC: Action-Qualifier Software Force Register --------------------------------------------------------*/
typedef struct {
  uint32_t ACTSFA                 :2;                                /*!< Action when one-time software force A is invoked */
  uint32_t OTSFA                  :1;                                /*!< One-time software forced event on output A */
  uint32_t ACTSFB                 :2;                                /*!< Action when one-time software force B is invoked */
  uint32_t OTSFB                  :1;                                /*!< One-time software forced event on output B */
  uint32_t RLDCSF                 :2;                                /*!< AQCSFRC active register reload from shadow options */
} _PWM_AQSFRC_bits;

/* Bit field positions: */
#define PWM_AQSFRC_ACTSFA_Pos                 0                      /*!< Action when one-time software force A is invoked */
#define PWM_AQSFRC_OTSFA_Pos                  2                      /*!< One-time software forced event on output A */
#define PWM_AQSFRC_ACTSFB_Pos                 3                      /*!< Action when one-time software force B is invoked */
#define PWM_AQSFRC_OTSFB_Pos                  5                      /*!< One-time software forced event on output B */
#define PWM_AQSFRC_RLDCSF_Pos                 6                      /*!< AQCSFRC active register reload from shadow options */

/* Bit field masks: */
#define PWM_AQSFRC_ACTSFA_Msk                 0x00000003UL           /*!< Action when one-time software force A is invoked */
#define PWM_AQSFRC_OTSFA_Msk                  0x00000004UL           /*!< One-time software forced event on output A */
#define PWM_AQSFRC_ACTSFB_Msk                 0x00000018UL           /*!< Action when one-time software force B is invoked */
#define PWM_AQSFRC_OTSFB_Msk                  0x00000020UL           /*!< One-time software forced event on output B */
#define PWM_AQSFRC_RLDCSF_Msk                 0x000000C0UL           /*!< AQCSFRC active register reload from shadow options */

/* Bit field enums: */
typedef enum {
  PWM_AQSFRC_ACTSFA_NoAction                 = 0x0UL,                /*!< no action */
  PWM_AQSFRC_ACTSFA_Clear                    = 0x1UL,                /*!< clear PWMA/PWMB */
  PWM_AQSFRC_ACTSFA_Set                      = 0x2UL,                /*!< set PWMA/PWMB */
  PWM_AQSFRC_ACTSFA_Toggle                   = 0x3UL,                /*!< inverse PWMA/PWMB */
} PWM_AQSFRC_ACTSFA_Enum;

typedef enum {
  PWM_AQSFRC_ACTSFB_NoAction                 = 0x0UL,                /*!< no action */
  PWM_AQSFRC_ACTSFB_Clear                    = 0x1UL,                /*!< clear PWMA/PWMB */
  PWM_AQSFRC_ACTSFB_Set                      = 0x2UL,                /*!< set PWMA/PWMB */
  PWM_AQSFRC_ACTSFB_Toggle                   = 0x3UL,                /*!< inverse PWMA/PWMB */
} PWM_AQSFRC_ACTSFB_Enum;

typedef enum {
  PWM_AQSFRC_RLDCSF_CTREqZero                = 0x0UL,                /*!< load when CTR = 0 */
  PWM_AQSFRC_RLDCSF_CTREqPRD                 = 0x1UL,                /*!< load when CTR = PRD */
  PWM_AQSFRC_RLDCSF_CTREqZeroPRD             = 0x2UL,                /*!< load when CTR = 0 or CTR = PRD */
  PWM_AQSFRC_RLDCSF_NoShadow                 = 0x3UL,                /*!< load immediatelly */
} PWM_AQSFRC_RLDCSF_Enum;

/*--  AQCSFRC: Action-Qualifier Continuous Software Force Register --------------------------------------------*/
typedef struct {
  uint32_t CSFA                   :2;                                /*!< Continuous software force on output A */
  uint32_t CSFB                   :2;                                /*!< Continuous software force on output B */
} _PWM_AQCSFRC_bits;

/* Bit field positions: */
#define PWM_AQCSFRC_CSFA_Pos                  0                      /*!< Continuous software force on output A */
#define PWM_AQCSFRC_CSFB_Pos                  2                      /*!< Continuous software force on output B */

/* Bit field masks: */
#define PWM_AQCSFRC_CSFA_Msk                  0x00000003UL           /*!< Continuous software force on output A */
#define PWM_AQCSFRC_CSFB_Msk                  0x0000000CUL           /*!< Continuous software force on output B */

/* Bit field enums: */
typedef enum {
  PWM_AQCSFRC_CSFA_NoAction                  = 0x0UL,                /*!< no action */
  PWM_AQCSFRC_CSFA_Clear                     = 0x1UL,                /*!< clear PWMA/PWMB */
  PWM_AQCSFRC_CSFA_Set                       = 0x2UL,                /*!< set PWMA/PWMB */
} PWM_AQCSFRC_CSFA_Enum;

typedef enum {
  PWM_AQCSFRC_CSFB_NoAction                  = 0x0UL,                /*!< no action */
  PWM_AQCSFRC_CSFB_Clear                     = 0x1UL,                /*!< clear PWMA/PWMB */
  PWM_AQCSFRC_CSFB_Set                       = 0x2UL,                /*!< set PWMA/PWMB */
} PWM_AQCSFRC_CSFB_Enum;

/*--  DBCTL: Dead-Band Generator Control Register -------------------------------------------------------------*/
typedef struct {
  uint32_t OUTMODE                :2;                                /*!< Dead-band output mode control */
  uint32_t POLSEL                 :2;                                /*!< Polarity select control */
  uint32_t INMODE                 :2;                                /*!< Dead band input mode control */
} _PWM_DBCTL_bits;

/* Bit field positions: */
#define PWM_DBCTL_OUTMODE_Pos                 0                      /*!< Dead-band output mode control */
#define PWM_DBCTL_POLSEL_Pos                  2                      /*!< Polarity select control */
#define PWM_DBCTL_INMODE_Pos                  4                      /*!< Dead band input mode control */

/* Bit field masks: */
#define PWM_DBCTL_OUTMODE_Msk                 0x00000003UL           /*!< Dead-band output mode control */
#define PWM_DBCTL_POLSEL_Msk                  0x0000000CUL           /*!< Polarity select control */
#define PWM_DBCTL_INMODE_Msk                  0x00000030UL           /*!< Dead band input mode control */

/* Bit field enums: */
typedef enum {
  PWM_DBCTL_OUTMODE_NoSpec                   = 0x0UL,                /*!< edge for deadtime is no specified */
  PWM_DBCTL_OUTMODE_BNeg                     = 0x1UL,                /*!< deadtime on PWMB negedge */
  PWM_DBCTL_OUTMODE_APos                     = 0x2UL,                /*!< deadtime on PWMA posedge */
  PWM_DBCTL_OUTMODE_Apos_BNeg                = 0x3UL,                /*!< deadtime on PWMA posedge and PWMB negedge */
} PWM_DBCTL_OUTMODE_Enum;

typedef enum {
  PWM_DBCTL_POLSEL_InvDisable                = 0x0UL,                /*!< inverse disabled */
  PWM_DBCTL_POLSEL_InvA                      = 0x1UL,                /*!< inverse on PWMA */
  PWM_DBCTL_POLSEL_InvB                      = 0x2UL,                /*!< inverse on PWMB */
  PWM_DBCTL_POLSEL_InvAB                     = 0x3UL,                /*!< inverse on PWMA and PWMB */
} PWM_DBCTL_POLSEL_Enum;

typedef enum {
  PWM_DBCTL_INMODE_APosNeg                   = 0x0UL,                /*!< PWMA is used for posedge and negedge control */
  PWM_DBCTL_INMODE_ANeg_BPos                 = 0x1UL,                /*!< PWMA is used for negedge and PWMB is used for posedge control */
  PWM_DBCTL_INMODE_APos_BNeg                 = 0x2UL,                /*!< PWMA is used for posedge and PWMB is used for negedge control */
  PWM_DBCTL_INMODE_BPosNeg                   = 0x3UL,                /*!< PWMB is used for posedge and negedge control */
} PWM_DBCTL_INMODE_Enum;

/*--  DBRED: Dead-Band Generator Rising Edge Delay Register ---------------------------------------------------*/
typedef struct {
  uint32_t DEL                    :10;                               /*!< Rising edge delay count */
} _PWM_DBRED_bits;

/* Bit field positions: */
#define PWM_DBRED_DEL_Pos                     0                      /*!< Rising edge delay count */

/* Bit field masks: */
#define PWM_DBRED_DEL_Msk                     0x000003FFUL           /*!< Rising edge delay count */

/*--  DBFED: Dead-Band Generator Falling Edge Delay Register --------------------------------------------------*/
typedef struct {
  uint32_t DEL                    :10;                               /*!< Falling edge delay count */
} _PWM_DBFED_bits;

/* Bit field positions: */
#define PWM_DBFED_DEL_Pos                     0                      /*!< Falling edge delay count */

/* Bit field masks: */
#define PWM_DBFED_DEL_Msk                     0x000003FFUL           /*!< Falling edge delay count */

/*--  TZSEL: Trip-Zone Select Register ------------------------------------------------------------------------*/
typedef struct {
  uint32_t CBC0                   :1;                                /*!< Cycle-by-Cycle  trip-zone 0 enable
 */
  uint32_t CBC1                   :1;                                /*!< Cycle-by-Cycle  trip-zone 1 enable
 */
  uint32_t CBC2                   :1;                                /*!< Cycle-by-Cycle  trip-zone 2 enable
 */
  uint32_t CBC3                   :1;                                /*!< Cycle-by-Cycle  trip-zone 3 enable
 */
  uint32_t CBC4                   :1;                                /*!< Cycle-by-Cycle  trip-zone 4 enable
 */
  uint32_t CBC5                   :1;                                /*!< Cycle-by-Cycle  trip-zone 5 enable
 */
  uint32_t                        :2;                                /*!< RESERVED */
  uint32_t OST0                   :1;                                /*!< One-Shot trip-zone 0 enable */
  uint32_t OST1                   :1;                                /*!< One-Shot trip-zone 1 enable */
  uint32_t OST2                   :1;                                /*!< One-Shot trip-zone 2 enable */
  uint32_t OST3                   :1;                                /*!< One-Shot trip-zone 3 enable */
  uint32_t OST4                   :1;                                /*!< One-Shot trip-zone 4 enable */
  uint32_t OST5                   :1;                                /*!< One-Shot trip-zone 5 enable */
} _PWM_TZSEL_bits;

/* Bit field positions: */
#define PWM_TZSEL_CBC0_Pos                    0                      /*!< Cycle-by-Cycle  trip-zone 0 enable
 */
#define PWM_TZSEL_CBC1_Pos                    1                      /*!< Cycle-by-Cycle  trip-zone 1 enable
 */
#define PWM_TZSEL_CBC2_Pos                    2                      /*!< Cycle-by-Cycle  trip-zone 2 enable
 */
#define PWM_TZSEL_CBC3_Pos                    3                      /*!< Cycle-by-Cycle  trip-zone 3 enable
 */
#define PWM_TZSEL_CBC4_Pos                    4                      /*!< Cycle-by-Cycle  trip-zone 4 enable
 */
#define PWM_TZSEL_CBC5_Pos                    5                      /*!< Cycle-by-Cycle  trip-zone 5 enable
 */
#define PWM_TZSEL_OST0_Pos                    8                      /*!< One-Shot trip-zone 0 enable */
#define PWM_TZSEL_OST1_Pos                    9                      /*!< One-Shot trip-zone 1 enable */
#define PWM_TZSEL_OST2_Pos                    10                     /*!< One-Shot trip-zone 2 enable */
#define PWM_TZSEL_OST3_Pos                    11                     /*!< One-Shot trip-zone 3 enable */
#define PWM_TZSEL_OST4_Pos                    12                     /*!< One-Shot trip-zone 4 enable */
#define PWM_TZSEL_OST5_Pos                    13                     /*!< One-Shot trip-zone 5 enable */

/* Bit field masks: */
#define PWM_TZSEL_CBC0_Msk                    0x00000001UL           /*!< Cycle-by-Cycle  trip-zone 0 enable
 */
#define PWM_TZSEL_CBC1_Msk                    0x00000002UL           /*!< Cycle-by-Cycle  trip-zone 1 enable
 */
#define PWM_TZSEL_CBC2_Msk                    0x00000004UL           /*!< Cycle-by-Cycle  trip-zone 2 enable
 */
#define PWM_TZSEL_CBC3_Msk                    0x00000008UL           /*!< Cycle-by-Cycle  trip-zone 3 enable
 */
#define PWM_TZSEL_CBC4_Msk                    0x00000010UL           /*!< Cycle-by-Cycle  trip-zone 4 enable
 */
#define PWM_TZSEL_CBC5_Msk                    0x00000020UL           /*!< Cycle-by-Cycle  trip-zone 5 enable
 */
#define PWM_TZSEL_OST0_Msk                    0x00000100UL           /*!< One-Shot trip-zone 0 enable */
#define PWM_TZSEL_OST1_Msk                    0x00000200UL           /*!< One-Shot trip-zone 1 enable */
#define PWM_TZSEL_OST2_Msk                    0x00000400UL           /*!< One-Shot trip-zone 2 enable */
#define PWM_TZSEL_OST3_Msk                    0x00000800UL           /*!< One-Shot trip-zone 3 enable */
#define PWM_TZSEL_OST4_Msk                    0x00001000UL           /*!< One-Shot trip-zone 4 enable */
#define PWM_TZSEL_OST5_Msk                    0x00002000UL           /*!< One-Shot trip-zone 5 enable */

/*--  TZCTL: Trip-Zone Control Register -----------------------------------------------------------------------*/
typedef struct {
  uint32_t TZA                    :2;                                /*!< When a trip event occurs the following action is taken on output A */
  uint32_t TZB                    :2;                                /*!< When a trip event occurs the following action is taken on output B */
} _PWM_TZCTL_bits;

/* Bit field positions: */
#define PWM_TZCTL_TZA_Pos                     0                      /*!< When a trip event occurs the following action is taken on output A */
#define PWM_TZCTL_TZB_Pos                     2                      /*!< When a trip event occurs the following action is taken on output B */

/* Bit field masks: */
#define PWM_TZCTL_TZA_Msk                     0x00000003UL           /*!< When a trip event occurs the following action is taken on output A */
#define PWM_TZCTL_TZB_Msk                     0x0000000CUL           /*!< When a trip event occurs the following action is taken on output B */

/* Bit field enums: */
typedef enum {
  PWM_TZCTL_TZA_Z                            = 0x0UL,                /*!< PWMA/PWMB go to Z on failture */
  PWM_TZCTL_TZA_Set                          = 0x1UL,                /*!< PWMA/PWMB go to 1 on failture */
  PWM_TZCTL_TZA_Clear                        = 0x2UL,                /*!< PWMA/PWMB go to 0 on failture */
  PWM_TZCTL_TZA_NoAction                     = 0x3UL,                /*!< no action on failture */
} PWM_TZCTL_TZA_Enum;

typedef enum {
  PWM_TZCTL_TZB_Z                            = 0x0UL,                /*!< PWMA/PWMB go to Z on failture */
  PWM_TZCTL_TZB_Set                          = 0x1UL,                /*!< PWMA/PWMB go to 1 on failture */
  PWM_TZCTL_TZB_Clear                        = 0x2UL,                /*!< PWMA/PWMB go to 0 on failture */
  PWM_TZCTL_TZB_NoAction                     = 0x3UL,                /*!< no action on failture */
} PWM_TZCTL_TZB_Enum;

/*--  TZEINT: Trip-Zone Enable Interrupt Register -------------------------------------------------------------*/
typedef struct {
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t CBC                    :1;                                /*!< Trip-zone Cycle-by-Cycle interrupt enable */
  uint32_t OST                    :1;                                /*!< Trip-zone One-Shot interrupt enable */
} _PWM_TZEINT_bits;

/* Bit field positions: */
#define PWM_TZEINT_CBC_Pos                    1                      /*!< Trip-zone Cycle-by-Cycle interrupt enable */
#define PWM_TZEINT_OST_Pos                    2                      /*!< Trip-zone One-Shot interrupt enable */

/* Bit field masks: */
#define PWM_TZEINT_CBC_Msk                    0x00000002UL           /*!< Trip-zone Cycle-by-Cycle interrupt enable */
#define PWM_TZEINT_OST_Msk                    0x00000004UL           /*!< Trip-zone One-Shot interrupt enable */

/*--  TZFLG: Trip-Zone Flag Register --------------------------------------------------------------------------*/
typedef struct {
  uint32_t INT                    :1;                                /*!< Latched trip interrupt status flag */
  uint32_t CBC                    :1;                                /*!< Latched status flag for Cycle-By-Cycle trip event */
  uint32_t OST                    :1;                                /*!< Latched status flag for a One-Shot trip event */
} _PWM_TZFLG_bits;

/* Bit field positions: */
#define PWM_TZFLG_INT_Pos                     0                      /*!< Latched trip interrupt status flag */
#define PWM_TZFLG_CBC_Pos                     1                      /*!< Latched status flag for Cycle-By-Cycle trip event */
#define PWM_TZFLG_OST_Pos                     2                      /*!< Latched status flag for a One-Shot trip event */

/* Bit field masks: */
#define PWM_TZFLG_INT_Msk                     0x00000001UL           /*!< Latched trip interrupt status flag */
#define PWM_TZFLG_CBC_Msk                     0x00000002UL           /*!< Latched status flag for Cycle-By-Cycle trip event */
#define PWM_TZFLG_OST_Msk                     0x00000004UL           /*!< Latched status flag for a One-Shot trip event */

/*--  TZCLR: Trip-Zone Clear Register -------------------------------------------------------------------------*/
typedef struct {
  uint32_t INT                    :1;                                /*!< Clear trip-zone interrupt flag */
  uint32_t CBC                    :1;                                /*!< Clear flag for Cycle-By-Cycle trip latch
 */
  uint32_t OST                    :1;                                /*!< Clear flag for One-Shot trip latch */
} _PWM_TZCLR_bits;

/* Bit field positions: */
#define PWM_TZCLR_INT_Pos                     0                      /*!< Clear trip-zone interrupt flag */
#define PWM_TZCLR_CBC_Pos                     1                      /*!< Clear flag for Cycle-By-Cycle trip latch
 */
#define PWM_TZCLR_OST_Pos                     2                      /*!< Clear flag for One-Shot trip latch */

/* Bit field masks: */
#define PWM_TZCLR_INT_Msk                     0x00000001UL           /*!< Clear trip-zone interrupt flag */
#define PWM_TZCLR_CBC_Msk                     0x00000002UL           /*!< Clear flag for Cycle-By-Cycle trip latch
 */
#define PWM_TZCLR_OST_Msk                     0x00000004UL           /*!< Clear flag for One-Shot trip latch */

/*--  TZFRC: Trip-Zone Force Register -------------------------------------------------------------------------*/
typedef struct {
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t CBC                    :1;                                /*!< Force a Cycle-by-Cycle trip event via software */
  uint32_t OST                    :1;                                /*!< Force a One-Shot trip event via software */
} _PWM_TZFRC_bits;

/* Bit field positions: */
#define PWM_TZFRC_CBC_Pos                     1                      /*!< Force a Cycle-by-Cycle trip event via software */
#define PWM_TZFRC_OST_Pos                     2                      /*!< Force a One-Shot trip event via software */

/* Bit field masks: */
#define PWM_TZFRC_CBC_Msk                     0x00000002UL           /*!< Force a Cycle-by-Cycle trip event via software */
#define PWM_TZFRC_OST_Msk                     0x00000004UL           /*!< Force a One-Shot trip event via software */

/*--  ETSEL: Event-Trigger Selection Register -----------------------------------------------------------------*/
typedef struct {
  uint32_t INTSEL                 :3;                                /*!< PWM_INT interrupt selection options */
  uint32_t INTEN                  :1;                                /*!< Enable PWM_INT interrupt generation */
  uint32_t                        :4;                                /*!< RESERVED */
  uint32_t SOCASEL                :3;                                /*!< PWM_SOCA selection Options */
  uint32_t SOCAEN                 :1;                                /*!< Enable the ADC start of conversion A PWM_SOCA pulse */
  uint32_t SOCBSEL                :3;                                /*!< PWM_SOCB selection Options */
  uint32_t SOCBEN                 :1;                                /*!< Enable the ADC start of conversion B PWM_SOCB pulse */
  uint32_t DRQASEL                :3;                                /*!< PWM A DMA request event selection */
  uint32_t DRQAEN                 :1;                                /*!< Enable the DMA request from PWM A */
  uint32_t DRQBSEL                :3;                                /*!< PWM B DMA request event selection */
  uint32_t DRQBEN                 :1;                                /*!< Enable the DMA request from PWM B */
} _PWM_ETSEL_bits;

/* Bit field positions: */
#define PWM_ETSEL_INTSEL_Pos                  0                      /*!< PWM_INT interrupt selection options */
#define PWM_ETSEL_INTEN_Pos                   3                      /*!< Enable PWM_INT interrupt generation */
#define PWM_ETSEL_SOCASEL_Pos                 8                      /*!< PWM_SOCA selection Options */
#define PWM_ETSEL_SOCAEN_Pos                  11                     /*!< Enable the ADC start of conversion A PWM_SOCA pulse */
#define PWM_ETSEL_SOCBSEL_Pos                 12                     /*!< PWM_SOCB selection Options */
#define PWM_ETSEL_SOCBEN_Pos                  15                     /*!< Enable the ADC start of conversion B PWM_SOCB pulse */
#define PWM_ETSEL_DRQASEL_Pos                 16                     /*!< PWM A DMA request event selection */
#define PWM_ETSEL_DRQAEN_Pos                  19                     /*!< Enable the DMA request from PWM A */
#define PWM_ETSEL_DRQBSEL_Pos                 20                     /*!< PWM B DMA request event selection */
#define PWM_ETSEL_DRQBEN_Pos                  23                     /*!< Enable the DMA request from PWM B */

/* Bit field masks: */
#define PWM_ETSEL_INTSEL_Msk                  0x00000007UL           /*!< PWM_INT interrupt selection options */
#define PWM_ETSEL_INTEN_Msk                   0x00000008UL           /*!< Enable PWM_INT interrupt generation */
#define PWM_ETSEL_SOCASEL_Msk                 0x00000700UL           /*!< PWM_SOCA selection Options */
#define PWM_ETSEL_SOCAEN_Msk                  0x00000800UL           /*!< Enable the ADC start of conversion A PWM_SOCA pulse */
#define PWM_ETSEL_SOCBSEL_Msk                 0x00007000UL           /*!< PWM_SOCB selection Options */
#define PWM_ETSEL_SOCBEN_Msk                  0x00008000UL           /*!< Enable the ADC start of conversion B PWM_SOCB pulse */
#define PWM_ETSEL_DRQASEL_Msk                 0x00070000UL           /*!< PWM A DMA request event selection */
#define PWM_ETSEL_DRQAEN_Msk                  0x00080000UL           /*!< Enable the DMA request from PWM A */
#define PWM_ETSEL_DRQBSEL_Msk                 0x00700000UL           /*!< PWM B DMA request event selection */
#define PWM_ETSEL_DRQBEN_Msk                  0x00800000UL           /*!< Enable the DMA request from PWM B */

/* Bit field enums: */
typedef enum {
  PWM_ETSEL_INTSEL_CTREqCMPA                 = 0x0UL,                /*!< generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPA */
  PWM_ETSEL_INTSEL_CTREqZero                 = 0x1UL,                /*!< generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = 0 */
  PWM_ETSEL_INTSEL_CTREqPRD                  = 0x2UL,                /*!< generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = PRD */
  PWM_ETSEL_INTSEL_CTREqCMPB                 = 0x3UL,                /*!< generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPB */
  PWM_ETSEL_INTSEL_CTREqCMPA_OnUp            = 0x4UL,                /*!< generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPA when count up */
  PWM_ETSEL_INTSEL_CTREqCMPA_OnDown          = 0x5UL,                /*!< generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPA when count down */
  PWM_ETSEL_INTSEL_CTREqCMPB_OnUp            = 0x6UL,                /*!< generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPB when count up */
  PWM_ETSEL_INTSEL_CTREqCMPB_OnDown          = 0x7UL,                /*!< generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPB when count down */
} PWM_ETSEL_INTSEL_Enum;

typedef enum {
  PWM_ETSEL_SOCASEL_CTREqCMPA                = 0x0UL,                /*!< generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPA */
  PWM_ETSEL_SOCASEL_CTREqZero                = 0x1UL,                /*!< generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = 0 */
  PWM_ETSEL_SOCASEL_CTREqPRD                 = 0x2UL,                /*!< generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = PRD */
  PWM_ETSEL_SOCASEL_CTREqCMPB                = 0x3UL,                /*!< generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPB */
  PWM_ETSEL_SOCASEL_CTREqCMPA_OnUp           = 0x4UL,                /*!< generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPA when count up */
  PWM_ETSEL_SOCASEL_CTREqCMPA_OnDown         = 0x5UL,                /*!< generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPA when count down */
  PWM_ETSEL_SOCASEL_CTREqCMPB_OnUp           = 0x6UL,                /*!< generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPB when count up */
  PWM_ETSEL_SOCASEL_CTREqCMPB_OnDown         = 0x7UL,                /*!< generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPB when count down */
} PWM_ETSEL_SOCASEL_Enum;

typedef enum {
  PWM_ETSEL_SOCBSEL_CTREqCMPA                = 0x0UL,                /*!< generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPA */
  PWM_ETSEL_SOCBSEL_CTREqZero                = 0x1UL,                /*!< generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = 0 */
  PWM_ETSEL_SOCBSEL_CTREqPRD                 = 0x2UL,                /*!< generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = PRD */
  PWM_ETSEL_SOCBSEL_CTREqCMPB                = 0x3UL,                /*!< generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPB */
  PWM_ETSEL_SOCBSEL_CTREqCMPA_OnUp           = 0x4UL,                /*!< generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPA when count up */
  PWM_ETSEL_SOCBSEL_CTREqCMPA_OnDown         = 0x5UL,                /*!< generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPA when count down */
  PWM_ETSEL_SOCBSEL_CTREqCMPB_OnUp           = 0x6UL,                /*!< generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPB when count up */
  PWM_ETSEL_SOCBSEL_CTREqCMPB_OnDown         = 0x7UL,                /*!< generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPB when count down */
} PWM_ETSEL_SOCBSEL_Enum;

typedef enum {
  PWM_ETSEL_DRQASEL_CTREqCMPA                = 0x0UL,                /*!< generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPA */
  PWM_ETSEL_DRQASEL_CTREqZero                = 0x1UL,                /*!< generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = 0 */
  PWM_ETSEL_DRQASEL_CTREqPRD                 = 0x2UL,                /*!< generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = PRD */
  PWM_ETSEL_DRQASEL_CTREqCMPB                = 0x3UL,                /*!< generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPB */
  PWM_ETSEL_DRQASEL_CTREqCMPA_OnUp           = 0x4UL,                /*!< generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPA when count up */
  PWM_ETSEL_DRQASEL_CTREqCMPA_OnDown         = 0x5UL,                /*!< generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPA when count down */
  PWM_ETSEL_DRQASEL_CTREqCMPB_OnUp           = 0x6UL,                /*!< generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPB when count up */
  PWM_ETSEL_DRQASEL_CTREqCMPB_OnDown         = 0x7UL,                /*!< generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPB when count down */
} PWM_ETSEL_DRQASEL_Enum;

typedef enum {
  PWM_ETSEL_DRQBSEL_CTREqCMPA                = 0x0UL,                /*!< generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPA */
  PWM_ETSEL_DRQBSEL_CTREqZero                = 0x1UL,                /*!< generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = 0 */
  PWM_ETSEL_DRQBSEL_CTREqPRD                 = 0x2UL,                /*!< generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = PRD */
  PWM_ETSEL_DRQBSEL_CTREqCMPB                = 0x3UL,                /*!< generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPB */
  PWM_ETSEL_DRQBSEL_CTREqCMPA_OnUp           = 0x4UL,                /*!< generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPA when count up */
  PWM_ETSEL_DRQBSEL_CTREqCMPA_OnDown         = 0x5UL,                /*!< generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPA when count down */
  PWM_ETSEL_DRQBSEL_CTREqCMPB_OnUp           = 0x6UL,                /*!< generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPB when count up */
  PWM_ETSEL_DRQBSEL_CTREqCMPB_OnDown         = 0x7UL,                /*!< generate PWM_SOCA/PWM_SOCB/PWN_INT impulse on CTR = CMPB when count down */
} PWM_ETSEL_DRQBSEL_Enum;

/*--  ETPS: Event-Trigger Prescale Register -------------------------------------------------------------------*/
typedef struct {
  uint32_t INTPRD                 :2;                                /*!< PWM interrupt (PWM_INT) period select */
  uint32_t INTCNT                 :2;                                /*!< PWM interrupt event (PWM_INT) counter register */
  uint32_t                        :4;                                /*!< RESERVED */
  uint32_t SOCAPRD                :2;                                /*!< PWM ADC Start-of-Conversion A event (PWM_SOCA) period select */
  uint32_t SOCACNT                :2;                                /*!< PWM ADC Start-of-Conversion A event (PWM_SOCA) counter register */
  uint32_t SOCBPRD                :2;                                /*!< PWM ADC Start-of-Conversion B event (PWM_SOCB) period select */
  uint32_t SOCBCNT                :2;                                /*!< PWM ADC Start-of-Conversion B event (PWM_SOCB) counter register */
  uint32_t DRQAPRD                :2;                                /*!< PWM DMA request A period select */
  uint32_t DRQACNT                :2;                                /*!< PWM DMA request event A counter */
  uint32_t DRQBPRD                :2;                                /*!< PWM DMA request B period select */
  uint32_t DRQBCNT                :2;                                /*!< PWM DMA request event B counter */
} _PWM_ETPS_bits;

/* Bit field positions: */
#define PWM_ETPS_INTPRD_Pos                   0                      /*!< PWM interrupt (PWM_INT) period select */
#define PWM_ETPS_INTCNT_Pos                   2                      /*!< PWM interrupt event (PWM_INT) counter register */
#define PWM_ETPS_SOCAPRD_Pos                  8                      /*!< PWM ADC Start-of-Conversion A event (PWM_SOCA) period select */
#define PWM_ETPS_SOCACNT_Pos                  10                     /*!< PWM ADC Start-of-Conversion A event (PWM_SOCA) counter register */
#define PWM_ETPS_SOCBPRD_Pos                  12                     /*!< PWM ADC Start-of-Conversion B event (PWM_SOCB) period select */
#define PWM_ETPS_SOCBCNT_Pos                  14                     /*!< PWM ADC Start-of-Conversion B event (PWM_SOCB) counter register */
#define PWM_ETPS_DRQAPRD_Pos                  16                     /*!< PWM DMA request A period select */
#define PWM_ETPS_DRQACNT_Pos                  18                     /*!< PWM DMA request event A counter */
#define PWM_ETPS_DRQBPRD_Pos                  20                     /*!< PWM DMA request B period select */
#define PWM_ETPS_DRQBCNT_Pos                  22                     /*!< PWM DMA request event B counter */

/* Bit field masks: */
#define PWM_ETPS_INTPRD_Msk                   0x00000003UL           /*!< PWM interrupt (PWM_INT) period select */
#define PWM_ETPS_INTCNT_Msk                   0x0000000CUL           /*!< PWM interrupt event (PWM_INT) counter register */
#define PWM_ETPS_SOCAPRD_Msk                  0x00000300UL           /*!< PWM ADC Start-of-Conversion A event (PWM_SOCA) period select */
#define PWM_ETPS_SOCACNT_Msk                  0x00000C00UL           /*!< PWM ADC Start-of-Conversion A event (PWM_SOCA) counter register */
#define PWM_ETPS_SOCBPRD_Msk                  0x00003000UL           /*!< PWM ADC Start-of-Conversion B event (PWM_SOCB) period select */
#define PWM_ETPS_SOCBCNT_Msk                  0x0000C000UL           /*!< PWM ADC Start-of-Conversion B event (PWM_SOCB) counter register */
#define PWM_ETPS_DRQAPRD_Msk                  0x00030000UL           /*!< PWM DMA request A period select */
#define PWM_ETPS_DRQACNT_Msk                  0x000C0000UL           /*!< PWM DMA request event A counter */
#define PWM_ETPS_DRQBPRD_Msk                  0x00300000UL           /*!< PWM DMA request B period select */
#define PWM_ETPS_DRQBCNT_Msk                  0x00C00000UL           /*!< PWM DMA request event B counter */

/*--  ETFLG: Event-Trigger Flag Register ----------------------------------------------------------------------*/
typedef struct {
  uint32_t INT                    :1;                                /*!< Latched PWM Interrupt (PWM_INT) status flag */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t SOCA                   :1;                                /*!< Latched PWM ADC Start-of-Conversion A (PWM_SOCA) status flag */
  uint32_t SOCB                   :1;                                /*!< Latched PWM ADC Start-of-Conversion B (PWM_SOCB) status flag */
  uint32_t DRQA                   :1;                                /*!< Latched PWM DMA request A status flag */
  uint32_t DRQB                   :1;                                /*!< Latched PWM DMA request B status flag */
} _PWM_ETFLG_bits;

/* Bit field positions: */
#define PWM_ETFLG_INT_Pos                     0                      /*!< Latched PWM Interrupt (PWM_INT) status flag */
#define PWM_ETFLG_SOCA_Pos                    2                      /*!< Latched PWM ADC Start-of-Conversion A (PWM_SOCA) status flag */
#define PWM_ETFLG_SOCB_Pos                    3                      /*!< Latched PWM ADC Start-of-Conversion B (PWM_SOCB) status flag */
#define PWM_ETFLG_DRQA_Pos                    4                      /*!< Latched PWM DMA request A status flag */
#define PWM_ETFLG_DRQB_Pos                    5                      /*!< Latched PWM DMA request B status flag */

/* Bit field masks: */
#define PWM_ETFLG_INT_Msk                     0x00000001UL           /*!< Latched PWM Interrupt (PWM_INT) status flag */
#define PWM_ETFLG_SOCA_Msk                    0x00000004UL           /*!< Latched PWM ADC Start-of-Conversion A (PWM_SOCA) status flag */
#define PWM_ETFLG_SOCB_Msk                    0x00000008UL           /*!< Latched PWM ADC Start-of-Conversion B (PWM_SOCB) status flag */
#define PWM_ETFLG_DRQA_Msk                    0x00000010UL           /*!< Latched PWM DMA request A status flag */
#define PWM_ETFLG_DRQB_Msk                    0x00000020UL           /*!< Latched PWM DMA request B status flag */

/*--  ETCLR: Event-Trigger Clear Register ---------------------------------------------------------------------*/
typedef struct {
  uint32_t INT                    :1;                                /*!< Latched PWM Interrupt (PWM_INT) flag clear bit */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t SOCA                   :1;                                /*!< Latched PWM ADC Start-of-Conversion A (PWM_SOCA) flag clear bit */
  uint32_t SOCB                   :1;                                /*!< Latched PWM ADC Start-of-Conversion B (PWM_SOCB) flag clear bit */
  uint32_t DRQA                   :1;                                /*!< Latched PWM DMA request A flag clear bit */
  uint32_t DRQB                   :1;                                /*!< Latched PWM DMA request B flag clear bit */
} _PWM_ETCLR_bits;

/* Bit field positions: */
#define PWM_ETCLR_INT_Pos                     0                      /*!< Latched PWM Interrupt (PWM_INT) flag clear bit */
#define PWM_ETCLR_SOCA_Pos                    2                      /*!< Latched PWM ADC Start-of-Conversion A (PWM_SOCA) flag clear bit */
#define PWM_ETCLR_SOCB_Pos                    3                      /*!< Latched PWM ADC Start-of-Conversion B (PWM_SOCB) flag clear bit */
#define PWM_ETCLR_DRQA_Pos                    4                      /*!< Latched PWM DMA request A flag clear bit */
#define PWM_ETCLR_DRQB_Pos                    5                      /*!< Latched PWM DMA request B flag clear bit */

/* Bit field masks: */
#define PWM_ETCLR_INT_Msk                     0x00000001UL           /*!< Latched PWM Interrupt (PWM_INT) flag clear bit */
#define PWM_ETCLR_SOCA_Msk                    0x00000004UL           /*!< Latched PWM ADC Start-of-Conversion A (PWM_SOCA) flag clear bit */
#define PWM_ETCLR_SOCB_Msk                    0x00000008UL           /*!< Latched PWM ADC Start-of-Conversion B (PWM_SOCB) flag clear bit */
#define PWM_ETCLR_DRQA_Msk                    0x00000010UL           /*!< Latched PWM DMA request A flag clear bit */
#define PWM_ETCLR_DRQB_Msk                    0x00000020UL           /*!< Latched PWM DMA request B flag clear bit */

/*--  ETFRC: Event-Trigger Force Register ---------------------------------------------------------------------*/
typedef struct {
  uint32_t INT                    :1;                                /*!< PWM_INT force bit. */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t SOCA                   :1;                                /*!< PWM_SOCA force bit */
  uint32_t SOCB                   :1;                                /*!< PWM_SOCB force bit */
  uint32_t DRQA                   :1;                                /*!< PWM DMA request A force bit */
  uint32_t DRQB                   :1;                                /*!< PWM DMA request B force bit */
} _PWM_ETFRC_bits;

/* Bit field positions: */
#define PWM_ETFRC_INT_Pos                     0                      /*!< PWM_INT force bit. */
#define PWM_ETFRC_SOCA_Pos                    2                      /*!< PWM_SOCA force bit */
#define PWM_ETFRC_SOCB_Pos                    3                      /*!< PWM_SOCB force bit */
#define PWM_ETFRC_DRQA_Pos                    4                      /*!< PWM DMA request A force bit */
#define PWM_ETFRC_DRQB_Pos                    5                      /*!< PWM DMA request B force bit */

/* Bit field masks: */
#define PWM_ETFRC_INT_Msk                     0x00000001UL           /*!< PWM_INT force bit. */
#define PWM_ETFRC_SOCA_Msk                    0x00000004UL           /*!< PWM_SOCA force bit */
#define PWM_ETFRC_SOCB_Msk                    0x00000008UL           /*!< PWM_SOCB force bit */
#define PWM_ETFRC_DRQA_Msk                    0x00000010UL           /*!< PWM DMA request A force bit */
#define PWM_ETFRC_DRQB_Msk                    0x00000020UL           /*!< PWM DMA request B force bit */

/*--  PCCTL: PWM-Chopper Control Register ---------------------------------------------------------------------*/
typedef struct {
  uint32_t CHPEN                  :1;                                /*!< PWM-chopping enable */
  uint32_t OSTWTH                 :4;                                /*!< One-Shot pulse width */
  uint32_t CHPFREQ                :3;                                /*!< Chopping clock frequency */
  uint32_t CHPDUTY                :3;                                /*!< Chopping clock duty cycle */
} _PWM_PCCTL_bits;

/* Bit field positions: */
#define PWM_PCCTL_CHPEN_Pos                   0                      /*!< PWM-chopping enable */
#define PWM_PCCTL_OSTWTH_Pos                  1                      /*!< One-Shot pulse width */
#define PWM_PCCTL_CHPFREQ_Pos                 5                      /*!< Chopping clock frequency */
#define PWM_PCCTL_CHPDUTY_Pos                 8                      /*!< Chopping clock duty cycle */

/* Bit field masks: */
#define PWM_PCCTL_CHPEN_Msk                   0x00000001UL           /*!< PWM-chopping enable */
#define PWM_PCCTL_OSTWTH_Msk                  0x0000001EUL           /*!< One-Shot pulse width */
#define PWM_PCCTL_CHPFREQ_Msk                 0x000000E0UL           /*!< Chopping clock frequency */
#define PWM_PCCTL_CHPDUTY_Msk                 0x00000700UL           /*!< Chopping clock duty cycle */

/* Bit field enums: */
typedef enum {
  PWM_PCCTL_CHPFREQ_Div1                     = 0x0UL,                /*!< sync frequency divide by 1 */
  PWM_PCCTL_CHPFREQ_Div2                     = 0x1UL,                /*!< sync frequency divide by 2 */
  PWM_PCCTL_CHPFREQ_Div3                     = 0x2UL,                /*!< sync frequency divide by 3 */
  PWM_PCCTL_CHPFREQ_Div4                     = 0x3UL,                /*!< sync frequency divide by 4 */
  PWM_PCCTL_CHPFREQ_Div5                     = 0x4UL,                /*!< sync frequency divide by 5 */
  PWM_PCCTL_CHPFREQ_Div6                     = 0x5UL,                /*!< sync frequency divide by 6 */
  PWM_PCCTL_CHPFREQ_Div7                     = 0x6UL,                /*!< sync frequency divide by 7 */
  PWM_PCCTL_CHPFREQ_Div8                     = 0x7UL,                /*!< sync frequency divide by 8 */
} PWM_PCCTL_CHPFREQ_Enum;

typedef enum {
  PWM_PCCTL_CHPDUTY_Duty_1_8                 = 0x0UL,                /*!< duty 1/8 */
  PWM_PCCTL_CHPDUTY_Duty_2_8                 = 0x1UL,                /*!< duty 2/8 */
  PWM_PCCTL_CHPDUTY_Duty_3_8                 = 0x2UL,                /*!< duty 3/8 */
  PWM_PCCTL_CHPDUTY_Duty_4_8                 = 0x3UL,                /*!< duty 4/8 */
  PWM_PCCTL_CHPDUTY_Duty_5_8                 = 0x4UL,                /*!< duty 5/8 */
  PWM_PCCTL_CHPDUTY_Duty_6_8                 = 0x5UL,                /*!< duty 6/8 */
  PWM_PCCTL_CHPDUTY_Duty_7_8                 = 0x6UL,                /*!< duty 7/8 */
} PWM_PCCTL_CHPDUTY_Enum;

/*--  HRCTL: High-Resolution Control Register -----------------------------------------------------------------*/
typedef struct {
  uint32_t EDGMODEA               :2;                                /*!< Edge selecting for delay on chanel A */
  uint32_t CTLMODEA               :1;                                /*!< Register specifies the delay select on chanel A */
  uint32_t HRLOAD                 :1;                                /*!< CMPAHR register shadow load mode */
  uint32_t EDGMODEB               :2;                                /*!< Edge selecting for delay on chanel B */
  uint32_t CTLMODEB               :1;                                /*!< Register specifies the delay select on chanel B */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t DELAYCALA              :2;                                /*!< Delay calibration flags of chanel A */
  uint32_t DELAYCALB              :2;                                /*!< Delay calibration flags of chanel B */
} _PWM_HRCTL_bits;

/* Bit field positions: */
#define PWM_HRCTL_EDGMODEA_Pos                0                      /*!< Edge selecting for delay on chanel A */
#define PWM_HRCTL_CTLMODEA_Pos                2                      /*!< Register specifies the delay select on chanel A */
#define PWM_HRCTL_HRLOAD_Pos                  3                      /*!< CMPAHR register shadow load mode */
#define PWM_HRCTL_EDGMODEB_Pos                4                      /*!< Edge selecting for delay on chanel B */
#define PWM_HRCTL_CTLMODEB_Pos                6                      /*!< Register specifies the delay select on chanel B */
#define PWM_HRCTL_DELAYCALA_Pos               8                      /*!< Delay calibration flags of chanel A */
#define PWM_HRCTL_DELAYCALB_Pos               10                     /*!< Delay calibration flags of chanel B */

/* Bit field masks: */
#define PWM_HRCTL_EDGMODEA_Msk                0x00000003UL           /*!< Edge selecting for delay on chanel A */
#define PWM_HRCTL_CTLMODEA_Msk                0x00000004UL           /*!< Register specifies the delay select on chanel A */
#define PWM_HRCTL_HRLOAD_Msk                  0x00000008UL           /*!< CMPAHR register shadow load mode */
#define PWM_HRCTL_EDGMODEB_Msk                0x00000030UL           /*!< Edge selecting for delay on chanel B */
#define PWM_HRCTL_CTLMODEB_Msk                0x00000040UL           /*!< Register specifies the delay select on chanel B */
#define PWM_HRCTL_DELAYCALA_Msk               0x00000300UL           /*!< Delay calibration flags of chanel A */
#define PWM_HRCTL_DELAYCALB_Msk               0x00000C00UL           /*!< Delay calibration flags of chanel B */

/* Bit field enums: */
typedef enum {
  PWM_HRCTL_EDGMODEA_PosEdge                 = 0x1UL,                /*!< posedge will be delayed */
  PWM_HRCTL_EDGMODEA_NegEdge                 = 0x2UL,                /*!< negedge will be delayed */
  PWM_HRCTL_EDGMODEA_BothEdge                = 0x3UL,                /*!< posedge and negedge will be delayed */
} PWM_HRCTL_EDGMODEA_Enum;

typedef enum {
  PWM_HRCTL_CTLMODEA_CMPAHR                  = 0x0UL,                /*!< delay source in CMPA reg */
  PWM_HRCTL_CTLMODEA_TBPHSHR                 = 0x1UL,                /*!< delay source in TBPHS reg */
} PWM_HRCTL_CTLMODEA_Enum;

typedef enum {
  PWM_HRCTL_HRLOAD_CTREqZero                 = 0x0UL,                /*!< load when CTR = 0 */
  PWM_HRCTL_HRLOAD_CTREqPRD                  = 0x1UL,                /*!< load when CTR = PRD */
} PWM_HRCTL_HRLOAD_Enum;

typedef enum {
  PWM_HRCTL_EDGMODEB_PosEdge                 = 0x1UL,                /*!< posedge will be delayed */
  PWM_HRCTL_EDGMODEB_NegEdge                 = 0x2UL,                /*!< negedge will be delayed */
  PWM_HRCTL_EDGMODEB_BothEdge                = 0x3UL,                /*!< posedge and negedge will be delayed */
} PWM_HRCTL_EDGMODEB_Enum;

typedef enum {
  PWM_HRCTL_CTLMODEB_CMPAHR                  = 0x0UL,                /*!< delay source in CMPA reg */
  PWM_HRCTL_CTLMODEB_TBPHSHR                 = 0x1UL,                /*!< delay source in TBPHS reg */
} PWM_HRCTL_CTLMODEB_Enum;

/*--  FWDTH: Filter Width select Register ---------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :8;                                /*!< Pulse filter width selection */
} _PWM_FWDTH_bits;

/* Bit field positions: */
#define PWM_FWDTH_VAL_Pos                     0                      /*!< Pulse filter width selection */

/* Bit field masks: */
#define PWM_FWDTH_VAL_Msk                     0x000000FFUL           /*!< Pulse filter width selection */

/*--  HDSEL: Hold Detector event Select Register --------------------------------------------------------------*/
typedef struct {
  uint32_t ADCDC0                 :1;                                /*!< Hold detector event by ADC Digital Comparator 0 enable */
  uint32_t ADCDC1                 :1;                                /*!< Hold detector event by ADC Digital Comparator 1 enable */
  uint32_t ADCDC2                 :1;                                /*!< Hold detector event by ADC Digital Comparator 2 enable */
  uint32_t ADCDC3                 :1;                                /*!< Hold detector event by ADC Digital Comparator 3 enable */
} _PWM_HDSEL_bits;

/* Bit field positions: */
#define PWM_HDSEL_ADCDC0_Pos                  0                      /*!< Hold detector event by ADC Digital Comparator 0 enable */
#define PWM_HDSEL_ADCDC1_Pos                  1                      /*!< Hold detector event by ADC Digital Comparator 1 enable */
#define PWM_HDSEL_ADCDC2_Pos                  2                      /*!< Hold detector event by ADC Digital Comparator 2 enable */
#define PWM_HDSEL_ADCDC3_Pos                  3                      /*!< Hold detector event by ADC Digital Comparator 3 enable */

/* Bit field masks: */
#define PWM_HDSEL_ADCDC0_Msk                  0x00000001UL           /*!< Hold detector event by ADC Digital Comparator 0 enable */
#define PWM_HDSEL_ADCDC1_Msk                  0x00000002UL           /*!< Hold detector event by ADC Digital Comparator 1 enable */
#define PWM_HDSEL_ADCDC2_Msk                  0x00000004UL           /*!< Hold detector event by ADC Digital Comparator 2 enable */
#define PWM_HDSEL_ADCDC3_Msk                  0x00000008UL           /*!< Hold detector event by ADC Digital Comparator 3 enable */

/*--  HDCTL: Hold Detector Control register -------------------------------------------------------------------*/
typedef struct {
  uint32_t HDA                    :2;                                /*!< Action when hold detection A is invoked */
  uint32_t HDB                    :2;                                /*!< Action when hold detection B is invoked */
  uint32_t                        :4;                                /*!< RESERVED */
  uint32_t CBC                    :1;                                /*!< Cycle-by-Cycle hold detector enable */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t OST                    :1;                                /*!< One-Shot hold detector enable */
} _PWM_HDCTL_bits;

/* Bit field positions: */
#define PWM_HDCTL_HDA_Pos                     0                      /*!< Action when hold detection A is invoked */
#define PWM_HDCTL_HDB_Pos                     2                      /*!< Action when hold detection B is invoked */
#define PWM_HDCTL_CBC_Pos                     8                      /*!< Cycle-by-Cycle hold detector enable */
#define PWM_HDCTL_OST_Pos                     12                     /*!< One-Shot hold detector enable */

/* Bit field masks: */
#define PWM_HDCTL_HDA_Msk                     0x00000003UL           /*!< Action when hold detection A is invoked */
#define PWM_HDCTL_HDB_Msk                     0x0000000CUL           /*!< Action when hold detection B is invoked */
#define PWM_HDCTL_CBC_Msk                     0x00000100UL           /*!< Cycle-by-Cycle hold detector enable */
#define PWM_HDCTL_OST_Msk                     0x00001000UL           /*!< One-Shot hold detector enable */

/* Bit field enums: */
typedef enum {
  PWM_HDCTL_HDA_Set                          = 0x1UL,                /*!< PWMA/PWMB go to 1 on failture */
  PWM_HDCTL_HDA_Clear                        = 0x2UL,                /*!< PWMA/PWMB go to 0 on failture */
  PWM_HDCTL_HDA_NoAction                     = 0x3UL,                /*!< no action on failture */
} PWM_HDCTL_HDA_Enum;

typedef enum {
  PWM_HDCTL_HDB_Set                          = 0x1UL,                /*!< PWMA/PWMB go to 1 on failture */
  PWM_HDCTL_HDB_Clear                        = 0x2UL,                /*!< PWMA/PWMB go to 0 on failture */
  PWM_HDCTL_HDB_NoAction                     = 0x3UL,                /*!< no action on failture */
} PWM_HDCTL_HDB_Enum;

/*--  HDEINT: Hold Detector Enable Interrupt Register ---------------------------------------------------------*/
typedef struct {
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t CBC                    :1;                                /*!< Hold detector Cycle-by-Cycle interrupt enable */
  uint32_t OST                    :1;                                /*!< Hold detector One-Shot interrupt enable */
} _PWM_HDEINT_bits;

/* Bit field positions: */
#define PWM_HDEINT_CBC_Pos                    1                      /*!< Hold detector Cycle-by-Cycle interrupt enable */
#define PWM_HDEINT_OST_Pos                    2                      /*!< Hold detector One-Shot interrupt enable */

/* Bit field masks: */
#define PWM_HDEINT_CBC_Msk                    0x00000002UL           /*!< Hold detector Cycle-by-Cycle interrupt enable */
#define PWM_HDEINT_OST_Msk                    0x00000004UL           /*!< Hold detector One-Shot interrupt enable */

/*--  HDFLG: Hold Detector Flag Register ----------------------------------------------------------------------*/
typedef struct {
  uint32_t INT                    :1;                                /*!< Latched hold detector interrupt status flag */
  uint32_t CBC                    :1;                                /*!< Latched status flag for hold detector Cycle-by-Cycle event */
  uint32_t OST                    :1;                                /*!< Latched status flag for hold detector One-Shot event */
} _PWM_HDFLG_bits;

/* Bit field positions: */
#define PWM_HDFLG_INT_Pos                     0                      /*!< Latched hold detector interrupt status flag */
#define PWM_HDFLG_CBC_Pos                     1                      /*!< Latched status flag for hold detector Cycle-by-Cycle event */
#define PWM_HDFLG_OST_Pos                     2                      /*!< Latched status flag for hold detector One-Shot event */

/* Bit field masks: */
#define PWM_HDFLG_INT_Msk                     0x00000001UL           /*!< Latched hold detector interrupt status flag */
#define PWM_HDFLG_CBC_Msk                     0x00000002UL           /*!< Latched status flag for hold detector Cycle-by-Cycle event */
#define PWM_HDFLG_OST_Msk                     0x00000004UL           /*!< Latched status flag for hold detector One-Shot event */

/*--  HDCLR: Register clear HD flag ---------------------------------------------------------------------------*/
typedef struct {
  uint32_t INT                    :1;                                /*!< Clear hold detector interrupt flag */
  uint32_t CBC                    :1;                                /*!< Clear flag for Cycle-By-Cycle hold detector latch
 */
  uint32_t OST                    :1;                                /*!< Clear flag for One-Shot hold detector latch */
} _PWM_HDCLR_bits;

/* Bit field positions: */
#define PWM_HDCLR_INT_Pos                     0                      /*!< Clear hold detector interrupt flag */
#define PWM_HDCLR_CBC_Pos                     1                      /*!< Clear flag for Cycle-By-Cycle hold detector latch
 */
#define PWM_HDCLR_OST_Pos                     2                      /*!< Clear flag for One-Shot hold detector latch */

/* Bit field masks: */
#define PWM_HDCLR_INT_Msk                     0x00000001UL           /*!< Clear hold detector interrupt flag */
#define PWM_HDCLR_CBC_Msk                     0x00000002UL           /*!< Clear flag for Cycle-By-Cycle hold detector latch
 */
#define PWM_HDCLR_OST_Msk                     0x00000004UL           /*!< Clear flag for One-Shot hold detector latch */

/*--  HDFRC: Hold Detector Force Register ---------------------------------------------------------------------*/
typedef struct {
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t CBC                    :1;                                /*!< Force a Cycle-by-Cycle hold detector event via software */
  uint32_t OST                    :1;                                /*!< Force a One-Shot hold detector event via software */
} _PWM_HDFRC_bits;

/* Bit field positions: */
#define PWM_HDFRC_CBC_Pos                     1                      /*!< Force a Cycle-by-Cycle hold detector event via software */
#define PWM_HDFRC_OST_Pos                     2                      /*!< Force a One-Shot hold detector event via software */

/* Bit field masks: */
#define PWM_HDFRC_CBC_Msk                     0x00000002UL           /*!< Force a Cycle-by-Cycle hold detector event via software */
#define PWM_HDFRC_OST_Msk                     0x00000004UL           /*!< Force a One-Shot hold detector event via software */

/*--  HDINTCLR: Hold Detector Interrupt pending Clear Register ------------------------------------------------*/
typedef struct {
  uint32_t INT                    :1;                                /*!< Clear HD interrupt pending */
} _PWM_HDINTCLR_bits;

/* Bit field positions: */
#define PWM_HDINTCLR_INT_Pos                  0                      /*!< Clear HD interrupt pending */

/* Bit field masks: */
#define PWM_HDINTCLR_INT_Msk                  0x00000001UL           /*!< Clear HD interrupt pending */

/*--  TZINTCLR: Trip-Zone Interrupt pending Clear Register ----------------------------------------------------*/
typedef struct {
  uint32_t INT                    :1;                                /*!< Clear TZ interrupt pending */
} _PWM_TZINTCLR_bits;

/* Bit field positions: */
#define PWM_TZINTCLR_INT_Pos                  0                      /*!< Clear TZ interrupt pending */

/* Bit field masks: */
#define PWM_TZINTCLR_INT_Msk                  0x00000001UL           /*!< Clear TZ interrupt pending */

/*--  INTCLR: PWM Interrupt pending Clear Register ------------------------------------------------------------*/
typedef struct {
  uint32_t INT                    :1;                                /*!< Clear interrupt pending */
} _PWM_INTCLR_bits;

/* Bit field positions: */
#define PWM_INTCLR_INT_Pos                    0                      /*!< Clear interrupt pending */

/* Bit field masks: */
#define PWM_INTCLR_INT_Msk                    0x00000001UL           /*!< Clear interrupt pending */

typedef struct {
  union {                                                               /*!< Time-Base Control Register */
    __IO uint32_t TBCTL;                                             /*!< TBCTL    : type used for word access */
    __IO _PWM_TBCTL_bits  TBCTL_bit;                                 /*!< TBCTL_bit: structure used for bit access */
  };
  union {                                                               /*!< Time-Base Status Register */
    __IO uint32_t TBSTS;                                             /*!< TBSTS    : type used for word access */
    __IO _PWM_TBSTS_bits  TBSTS_bit;                                 /*!< TBSTS_bit: structure used for bit access */
  };
  union {                                                               /*!< Time-Base Phase Register */
    __IO uint32_t TBPHS;                                             /*!< TBPHS    : type used for word access */
    __IO _PWM_TBPHS_bits  TBPHS_bit;                                 /*!< TBPHS_bit: structure used for bit access */
  };
  union {                                                               /*!< Time-Base Counter Register */
    __IO uint32_t TBCTR;                                             /*!< TBCTR    : type used for word access */
    __IO _PWM_TBCTR_bits  TBCTR_bit;                                 /*!< TBCTR_bit: structure used for bit access */
  };
  union {                                                               /*!< Time-Base Period Register */
    __IO uint32_t TBPRD;                                             /*!< TBPRD    : type used for word access */
    __IO _PWM_TBPRD_bits  TBPRD_bit;                                 /*!< TBPRD_bit: structure used for bit access */
  };
  union {                                                               /*!< Counter-Compare Control Register */
    __IO uint32_t CMPCTL;                                            /*!< CMPCTL    : type used for word access */
    __IO _PWM_CMPCTL_bits  CMPCTL_bit;                               /*!< CMPCTL_bit: structure used for bit access */
  };
  union {                                                               /*!< Counter-Compare A Register */
    __IO uint32_t CMPA;                                              /*!< CMPA    : type used for word access */
    __IO _PWM_CMPA_bits  CMPA_bit;                                   /*!< CMPA_bit: structure used for bit access */
  };
  union {                                                               /*!< Counter-Compare B Register */
    __IO uint32_t CMPB;                                              /*!< CMPB    : type used for word access */
    __IO _PWM_CMPB_bits  CMPB_bit;                                   /*!< CMPB_bit: structure used for bit access */
  };
  union {                                                               /*!< Action-Qualifier Output A Control Register */
    __IO uint32_t AQCTLA;                                            /*!< AQCTLA    : type used for word access */
    __IO _PWM_AQCTLA_bits  AQCTLA_bit;                               /*!< AQCTLA_bit: structure used for bit access */
  };
  union {                                                               /*!< Action-Qualifier Output B Control Register */
    __IO uint32_t AQCTLB;                                            /*!< AQCTLB    : type used for word access */
    __IO _PWM_AQCTLB_bits  AQCTLB_bit;                               /*!< AQCTLB_bit: structure used for bit access */
  };
  union {                                                               /*!< Action-Qualifier Software Force Register */
    __IO uint32_t AQSFRC;                                            /*!< AQSFRC    : type used for word access */
    __IO _PWM_AQSFRC_bits  AQSFRC_bit;                               /*!< AQSFRC_bit: structure used for bit access */
  };
  union {                                                               /*!< Action-Qualifier Continuous Software Force Register */
    __IO uint32_t AQCSFRC;                                           /*!< AQCSFRC    : type used for word access */
    __IO _PWM_AQCSFRC_bits  AQCSFRC_bit;                             /*!< AQCSFRC_bit: structure used for bit access */
  };
  union {                                                               /*!< Dead-Band Generator Control Register */
    __IO uint32_t DBCTL;                                             /*!< DBCTL    : type used for word access */
    __IO _PWM_DBCTL_bits  DBCTL_bit;                                 /*!< DBCTL_bit: structure used for bit access */
  };
  union {                                                               /*!< Dead-Band Generator Rising Edge Delay Register */
    __IO uint32_t DBRED;                                             /*!< DBRED    : type used for word access */
    __IO _PWM_DBRED_bits  DBRED_bit;                                 /*!< DBRED_bit: structure used for bit access */
  };
  union {                                                               /*!< Dead-Band Generator Falling Edge Delay Register */
    __IO uint32_t DBFED;                                             /*!< DBFED    : type used for word access */
    __IO _PWM_DBFED_bits  DBFED_bit;                                 /*!< DBFED_bit: structure used for bit access */
  };
  union {                                                               /*!< Trip-Zone Select Register */
    __IO uint32_t TZSEL;                                             /*!< TZSEL    : type used for word access */
    __IO _PWM_TZSEL_bits  TZSEL_bit;                                 /*!< TZSEL_bit: structure used for bit access */
  };
  union {                                                               /*!< Trip-Zone Control Register */
    __IO uint32_t TZCTL;                                             /*!< TZCTL    : type used for word access */
    __IO _PWM_TZCTL_bits  TZCTL_bit;                                 /*!< TZCTL_bit: structure used for bit access */
  };
  union {                                                               /*!< Trip-Zone Enable Interrupt Register */
    __IO uint32_t TZEINT;                                            /*!< TZEINT    : type used for word access */
    __IO _PWM_TZEINT_bits  TZEINT_bit;                               /*!< TZEINT_bit: structure used for bit access */
  };
  union {                                                               /*!< Trip-Zone Flag Register */
    __I uint32_t TZFLG;                                              /*!< TZFLG    : type used for word access */
    __I _PWM_TZFLG_bits  TZFLG_bit;                                  /*!< TZFLG_bit: structure used for bit access */
  };
  union {                                                               /*!< Trip-Zone Clear Register */
    __O uint32_t TZCLR;                                              /*!< TZCLR    : type used for word access */
    __O _PWM_TZCLR_bits  TZCLR_bit;                                  /*!< TZCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Trip-Zone Force Register */
    __O uint32_t TZFRC;                                              /*!< TZFRC    : type used for word access */
    __O _PWM_TZFRC_bits  TZFRC_bit;                                  /*!< TZFRC_bit: structure used for bit access */
  };
  union {                                                               /*!< Event-Trigger Selection Register */
    __IO uint32_t ETSEL;                                             /*!< ETSEL    : type used for word access */
    __IO _PWM_ETSEL_bits  ETSEL_bit;                                 /*!< ETSEL_bit: structure used for bit access */
  };
  union {                                                               /*!< Event-Trigger Prescale Register */
    __IO uint32_t ETPS;                                              /*!< ETPS    : type used for word access */
    __IO _PWM_ETPS_bits  ETPS_bit;                                   /*!< ETPS_bit: structure used for bit access */
  };
  union {                                                               /*!< Event-Trigger Flag Register */
    __I uint32_t ETFLG;                                              /*!< ETFLG    : type used for word access */
    __I _PWM_ETFLG_bits  ETFLG_bit;                                  /*!< ETFLG_bit: structure used for bit access */
  };
  union {                                                               /*!< Event-Trigger Clear Register */
    __O uint32_t ETCLR;                                              /*!< ETCLR    : type used for word access */
    __O _PWM_ETCLR_bits  ETCLR_bit;                                  /*!< ETCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Event-Trigger Force Register */
    __O uint32_t ETFRC;                                              /*!< ETFRC    : type used for word access */
    __O _PWM_ETFRC_bits  ETFRC_bit;                                  /*!< ETFRC_bit: structure used for bit access */
  };
  union {                                                               /*!< PWM-Chopper Control Register */
    __IO uint32_t PCCTL;                                             /*!< PCCTL    : type used for word access */
    __IO _PWM_PCCTL_bits  PCCTL_bit;                                 /*!< PCCTL_bit: structure used for bit access */
  };
  union {                                                               /*!< High-Resolution Control Register */
    __IO uint32_t HRCTL;                                             /*!< HRCTL    : type used for word access */
    __IO _PWM_HRCTL_bits  HRCTL_bit;                                 /*!< HRCTL_bit: structure used for bit access */
  };
  union {                                                               /*!< Filter Width select Register */
    __IO uint32_t FWDTH;                                             /*!< FWDTH    : type used for word access */
    __IO _PWM_FWDTH_bits  FWDTH_bit;                                 /*!< FWDTH_bit: structure used for bit access */
  };
  union {                                                               /*!< Hold Detector event Select Register */
    __IO uint32_t HDSEL;                                             /*!< HDSEL    : type used for word access */
    __IO _PWM_HDSEL_bits  HDSEL_bit;                                 /*!< HDSEL_bit: structure used for bit access */
  };
    __IO uint32_t Reserved0;
  union {                                                               /*!< Hold Detector Control register */
    __IO uint32_t HDCTL;                                             /*!< HDCTL    : type used for word access */
    __IO _PWM_HDCTL_bits  HDCTL_bit;                                 /*!< HDCTL_bit: structure used for bit access */
  };
  union {                                                               /*!< Hold Detector Enable Interrupt Register */
    __IO uint32_t HDEINT;                                            /*!< HDEINT    : type used for word access */
    __IO _PWM_HDEINT_bits  HDEINT_bit;                               /*!< HDEINT_bit: structure used for bit access */
  };
  union {                                                               /*!< Hold Detector Flag Register */
    __I uint32_t HDFLG;                                              /*!< HDFLG    : type used for word access */
    __I _PWM_HDFLG_bits  HDFLG_bit;                                  /*!< HDFLG_bit: structure used for bit access */
  };
  union {                                                               /*!< Register clear HD flag */
    __O uint32_t HDCLR;                                              /*!< HDCLR    : type used for word access */
    __O _PWM_HDCLR_bits  HDCLR_bit;                                  /*!< HDCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Hold Detector Force Register */
    __O uint32_t HDFRC;                                              /*!< HDFRC    : type used for word access */
    __O _PWM_HDFRC_bits  HDFRC_bit;                                  /*!< HDFRC_bit: structure used for bit access */
  };
  union {                                                               /*!< Hold Detector Interrupt pending Clear Register */
    __O uint32_t HDINTCLR;                                           /*!< HDINTCLR    : type used for word access */
    __O _PWM_HDINTCLR_bits  HDINTCLR_bit;                            /*!< HDINTCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Trip-Zone Interrupt pending Clear Register */
    __O uint32_t TZINTCLR;                                           /*!< TZINTCLR    : type used for word access */
    __O _PWM_TZINTCLR_bits  TZINTCLR_bit;                            /*!< TZINTCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< PWM Interrupt pending Clear Register */
    __O uint32_t INTCLR;                                             /*!< INTCLR    : type used for word access */
    __O _PWM_INTCLR_bits  INTCLR_bit;                                /*!< INTCLR_bit: structure used for bit access */
  };
} PWM_TypeDef;


/******************************************************************************/
/*                         QEP registers                                      */
/******************************************************************************/

/*--  QPOSCNT: Position Counter register ----------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!<  */
} _QEP_QPOSCNT_bits;

/* Bit field positions: */
#define QEP_QPOSCNT_VAL_Pos                   0                      /*!<  */

/* Bit field masks: */
#define QEP_QPOSCNT_VAL_Msk                   0xFFFFFFFFUL           /*!<  */

/*--  QPOSINIT: Position Counter Initialization register ------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!<  */
} _QEP_QPOSINIT_bits;

/* Bit field positions: */
#define QEP_QPOSINIT_VAL_Pos                  0                      /*!<  */

/* Bit field masks: */
#define QEP_QPOSINIT_VAL_Msk                  0xFFFFFFFFUL           /*!<  */

/*--  QPOSMAX: Maximum Position Count register ----------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!<  */
} _QEP_QPOSMAX_bits;

/* Bit field positions: */
#define QEP_QPOSMAX_VAL_Pos                   0                      /*!<  */

/* Bit field masks: */
#define QEP_QPOSMAX_VAL_Msk                   0xFFFFFFFFUL           /*!<  */

/*--  QPOSCMP: Position-compare register ----------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!<  */
} _QEP_QPOSCMP_bits;

/* Bit field positions: */
#define QEP_QPOSCMP_VAL_Pos                   0                      /*!<  */

/* Bit field masks: */
#define QEP_QPOSCMP_VAL_Msk                   0xFFFFFFFFUL           /*!<  */

/*--  QPOSILAT: Index Position Latch register -----------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!<  */
} _QEP_QPOSILAT_bits;

/* Bit field positions: */
#define QEP_QPOSILAT_VAL_Pos                  0                      /*!<  */

/* Bit field masks: */
#define QEP_QPOSILAT_VAL_Msk                  0xFFFFFFFFUL           /*!<  */

/*--  QPOSSLAT: Strobe Position Latch register ----------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!<  */
} _QEP_QPOSSLAT_bits;

/* Bit field positions: */
#define QEP_QPOSSLAT_VAL_Pos                  0                      /*!<  */

/* Bit field masks: */
#define QEP_QPOSSLAT_VAL_Msk                  0xFFFFFFFFUL           /*!<  */

/*--  QPOSLAT: Position Counter Latch register ----------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!<  */
} _QEP_QPOSLAT_bits;

/* Bit field positions: */
#define QEP_QPOSLAT_VAL_Pos                   0                      /*!<  */

/* Bit field masks: */
#define QEP_QPOSLAT_VAL_Msk                   0xFFFFFFFFUL           /*!<  */

/*--  QUTMR: Unit Timer register ------------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!<  */
} _QEP_QUTMR_bits;

/* Bit field positions: */
#define QEP_QUTMR_VAL_Pos                     0                      /*!<  */

/* Bit field masks: */
#define QEP_QUTMR_VAL_Msk                     0xFFFFFFFFUL           /*!<  */

/*--  QUPRD: Unit Period register -----------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!<  */
} _QEP_QUPRD_bits;

/* Bit field positions: */
#define QEP_QUPRD_VAL_Pos                     0                      /*!<  */

/* Bit field masks: */
#define QEP_QUPRD_VAL_Msk                     0xFFFFFFFFUL           /*!<  */

/*--  QWDTMR: Watchdog Timer register -------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!<  */
} _QEP_QWDTMR_bits;

/* Bit field positions: */
#define QEP_QWDTMR_VAL_Pos                    0                      /*!<  */

/* Bit field masks: */
#define QEP_QWDTMR_VAL_Msk                    0xFFFFFFFFUL           /*!<  */

/*--  QWDPRD: Watchdog Period register ------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!<  */
} _QEP_QWDPRD_bits;

/* Bit field positions: */
#define QEP_QWDPRD_VAL_Pos                    0                      /*!<  */

/* Bit field masks: */
#define QEP_QWDPRD_VAL_Msk                    0xFFFFFFFFUL           /*!<  */

/*--  QDECCTL: Decoder Control register -----------------------------------------------------------------------*/
typedef struct {
  uint32_t                        :5;                                /*!< RESERVED */
  uint32_t QSP                    :1;                                /*!< QEPS input polarity */
  uint32_t QIP                    :1;                                /*!< QEPI input polarity */
  uint32_t QBP                    :1;                                /*!< QEPB input polarity */
  uint32_t QAP                    :1;                                /*!< QEPA input polarity */
  uint32_t IGATE                  :1;                                /*!< Index pulse gating option */
  uint32_t SWAP                   :1;                                /*!< Swap quadrature clock inputs */
  uint32_t XCR                    :1;                                /*!< External clock rate */
  uint32_t SPSEL                  :1;                                /*!< Sync output pin selection */
  uint32_t SOEN                   :1;                                /*!< Sync output-enable */
  uint32_t QSRC                   :2;                                /*!< Position-counter source selection */
} _QEP_QDECCTL_bits;

/* Bit field positions: */
#define QEP_QDECCTL_QSP_Pos                   5                      /*!< QEPS input polarity */
#define QEP_QDECCTL_QIP_Pos                   6                      /*!< QEPI input polarity */
#define QEP_QDECCTL_QBP_Pos                   7                      /*!< QEPB input polarity */
#define QEP_QDECCTL_QAP_Pos                   8                      /*!< QEPA input polarity */
#define QEP_QDECCTL_IGATE_Pos                 9                      /*!< Index pulse gating option */
#define QEP_QDECCTL_SWAP_Pos                  10                     /*!< Swap quadrature clock inputs */
#define QEP_QDECCTL_XCR_Pos                   11                     /*!< External clock rate */
#define QEP_QDECCTL_SPSEL_Pos                 12                     /*!< Sync output pin selection */
#define QEP_QDECCTL_SOEN_Pos                  13                     /*!< Sync output-enable */
#define QEP_QDECCTL_QSRC_Pos                  14                     /*!< Position-counter source selection */

/* Bit field masks: */
#define QEP_QDECCTL_QSP_Msk                   0x00000020UL           /*!< QEPS input polarity */
#define QEP_QDECCTL_QIP_Msk                   0x00000040UL           /*!< QEPI input polarity */
#define QEP_QDECCTL_QBP_Msk                   0x00000080UL           /*!< QEPB input polarity */
#define QEP_QDECCTL_QAP_Msk                   0x00000100UL           /*!< QEPA input polarity */
#define QEP_QDECCTL_IGATE_Msk                 0x00000200UL           /*!< Index pulse gating option */
#define QEP_QDECCTL_SWAP_Msk                  0x00000400UL           /*!< Swap quadrature clock inputs */
#define QEP_QDECCTL_XCR_Msk                   0x00000800UL           /*!< External clock rate */
#define QEP_QDECCTL_SPSEL_Msk                 0x00001000UL           /*!< Sync output pin selection */
#define QEP_QDECCTL_SOEN_Msk                  0x00002000UL           /*!< Sync output-enable */
#define QEP_QDECCTL_QSRC_Msk                  0x0000C000UL           /*!< Position-counter source selection */

/* Bit field enums: */
typedef enum {
  QEP_QDECCTL_QSRC_Quad                      = 0x0UL,                /*!< quadrature mode */
  QEP_QDECCTL_QSRC_CountDir                  = 0x1UL,                /*!< count/direction mode */
  QEP_QDECCTL_QSRC_Up                        = 0x2UL,                /*!< count up */
  QEP_QDECCTL_QSRC_Down                      = 0x3UL,                /*!< count down */
} QEP_QDECCTL_QSRC_Enum;

/*--  QEPCTL: Control register --------------------------------------------------------------------------------*/
typedef struct {
  uint32_t WDE                    :1;                                /*!< QEP watchdog enable */
  uint32_t UTE                    :1;                                /*!< QEP unit timer enable */
  uint32_t QCLM                   :1;                                /*!< QEP capture latch mode */
  uint32_t QPEN                   :1;                                /*!< Quadrature position counter enable/software reset */
  uint32_t IEL                    :2;                                /*!< Index event latch of position counter (software index marker) */
  uint32_t SEL                    :1;                                /*!< Strobe event latch of position counter */
  uint32_t SWI                    :1;                                /*!< Software initialization of position counter */
  uint32_t IEI                    :2;                                /*!< Index event initialization of position counter */
  uint32_t SEI                    :2;                                /*!< Strobe event initialization of position counter */
  uint32_t PCRM                   :2;                                /*!< Position counter reset mode */
  uint32_t FREESOFT               :2;                                /*!< Emulation Control Bits */
} _QEP_QEPCTL_bits;

/* Bit field positions: */
#define QEP_QEPCTL_WDE_Pos                    0                      /*!< QEP watchdog enable */
#define QEP_QEPCTL_UTE_Pos                    1                      /*!< QEP unit timer enable */
#define QEP_QEPCTL_QCLM_Pos                   2                      /*!< QEP capture latch mode */
#define QEP_QEPCTL_QPEN_Pos                   3                      /*!< Quadrature position counter enable/software reset */
#define QEP_QEPCTL_IEL_Pos                    4                      /*!< Index event latch of position counter (software index marker) */
#define QEP_QEPCTL_SEL_Pos                    6                      /*!< Strobe event latch of position counter */
#define QEP_QEPCTL_SWI_Pos                    7                      /*!< Software initialization of position counter */
#define QEP_QEPCTL_IEI_Pos                    8                      /*!< Index event initialization of position counter */
#define QEP_QEPCTL_SEI_Pos                    10                     /*!< Strobe event initialization of position counter */
#define QEP_QEPCTL_PCRM_Pos                   12                     /*!< Position counter reset mode */
#define QEP_QEPCTL_FREESOFT_Pos               14                     /*!< Emulation Control Bits */

/* Bit field masks: */
#define QEP_QEPCTL_WDE_Msk                    0x00000001UL           /*!< QEP watchdog enable */
#define QEP_QEPCTL_UTE_Msk                    0x00000002UL           /*!< QEP unit timer enable */
#define QEP_QEPCTL_QCLM_Msk                   0x00000004UL           /*!< QEP capture latch mode */
#define QEP_QEPCTL_QPEN_Msk                   0x00000008UL           /*!< Quadrature position counter enable/software reset */
#define QEP_QEPCTL_IEL_Msk                    0x00000030UL           /*!< Index event latch of position counter (software index marker) */
#define QEP_QEPCTL_SEL_Msk                    0x00000040UL           /*!< Strobe event latch of position counter */
#define QEP_QEPCTL_SWI_Msk                    0x00000080UL           /*!< Software initialization of position counter */
#define QEP_QEPCTL_IEI_Msk                    0x00000300UL           /*!< Index event initialization of position counter */
#define QEP_QEPCTL_SEI_Msk                    0x00000C00UL           /*!< Strobe event initialization of position counter */
#define QEP_QEPCTL_PCRM_Msk                   0x00003000UL           /*!< Position counter reset mode */
#define QEP_QEPCTL_FREESOFT_Msk               0x0000C000UL           /*!< Emulation Control Bits */

/* Bit field enums: */
typedef enum {
  QEP_QEPCTL_IEL_NoLatch                     = 0x0UL,                /*!< no position counter latch */
  QEP_QEPCTL_IEL_IndPos                      = 0x1UL,                /*!< latch on index signal posedge */
  QEP_QEPCTL_IEL_IndNeg                      = 0x2UL,                /*!< latch on index signal negedge */
  QEP_QEPCTL_IEL_IndMark                     = 0x3UL,                /*!< latch on index marker */
} QEP_QEPCTL_IEL_Enum;

typedef enum {
  QEP_QEPCTL_IEI_NoInit                      = 0x0UL,                /*!< no initialization */
  QEP_QEPCTL_IEI_QEPIPos                     = 0x2UL,                /*!< init on posedge QEPI */
  QEP_QEPCTL_IEI_QEPINeg                     = 0x3UL,                /*!< init on negedge QEPI */
} QEP_QEPCTL_IEI_Enum;

typedef enum {
  QEP_QEPCTL_SEI_NoInit                      = 0x0UL,                /*!< no initialization */
  QEP_QEPCTL_SEI_QEPSPos                     = 0x2UL,                /*!< init on posedge QEPI */
  QEP_QEPCTL_SEI_QEPSDir                     = 0x3UL,                /*!< init depends on direction - on posedge if direction is up, on negedge if direction is down */
} QEP_QEPCTL_SEI_Enum;

typedef enum {
  QEP_QEPCTL_PCRM_Ind                        = 0x0UL,                /*!< reset on index */
  QEP_QEPCTL_PCRM_PosMax                     = 0x1UL,                /*!< reset on max position count */
  QEP_QEPCTL_PCRM_FirstInd                   = 0x2UL,                /*!< reset on the first index */
  QEP_QEPCTL_PCRM_Time                       = 0x3UL,                /*!< reset on time counter */
} QEP_QEPCTL_PCRM_Enum;

typedef enum {
  QEP_QEPCTL_FREESOFT_Stop                   = 0x0UL,                /*!< counters are blocked */
  QEP_QEPCTL_FREESOFT_StopAtOvf              = 0x1UL,                /*!< stop after overflow */
  QEP_QEPCTL_FREESOFT_Free                   = 0x2UL,                /*!< no count stop in debug mode */
} QEP_QEPCTL_FREESOFT_Enum;

/*--  QCAPCTL: Capture Control register -----------------------------------------------------------------------*/
typedef struct {
  uint32_t UPPS                   :4;                                /*!< Unit position event prescaler */
  uint32_t CCPS                   :3;                                /*!< QEP capture timer clock prescaler */
  uint32_t SELEVENT               :1;                                /*!< Reset timer control */
  uint32_t                        :7;                                /*!< RESERVED */
  uint32_t CEN                    :1;                                /*!< Enable eQEP capture */
  uint32_t EPSLD                  :1;                                /*!< Enhanced prescalers load */
} _QEP_QCAPCTL_bits;

/* Bit field positions: */
#define QEP_QCAPCTL_UPPS_Pos                  0                      /*!< Unit position event prescaler */
#define QEP_QCAPCTL_CCPS_Pos                  4                      /*!< QEP capture timer clock prescaler */
#define QEP_QCAPCTL_SELEVENT_Pos              7                      /*!< Reset timer control */
#define QEP_QCAPCTL_CEN_Pos                   15                     /*!< Enable eQEP capture */
#define QEP_QCAPCTL_EPSLD_Pos                 16                     /*!< Enhanced prescalers load */

/* Bit field masks: */
#define QEP_QCAPCTL_UPPS_Msk                  0x0000000FUL           /*!< Unit position event prescaler */
#define QEP_QCAPCTL_CCPS_Msk                  0x00000070UL           /*!< QEP capture timer clock prescaler */
#define QEP_QCAPCTL_SELEVENT_Msk              0x00000080UL           /*!< Reset timer control */
#define QEP_QCAPCTL_CEN_Msk                   0x00008000UL           /*!< Enable eQEP capture */
#define QEP_QCAPCTL_EPSLD_Msk                 0x00010000UL           /*!< Enhanced prescalers load */

/* Bit field enums: */
typedef enum {
  QEP_QCAPCTL_UPPS_Disable                   = 0x0UL,                /*!< quad signal not divided */
  QEP_QCAPCTL_UPPS_Div2                      = 0x1UL,                /*!< quad signal divided by 2 */
  QEP_QCAPCTL_UPPS_Div4                      = 0x2UL,                /*!< quad signal divided by 4 */
  QEP_QCAPCTL_UPPS_Div8                      = 0x3UL,                /*!< quad signal divided by 8 */
  QEP_QCAPCTL_UPPS_Div16                     = 0x4UL,                /*!< quad signal divided by 16 */
  QEP_QCAPCTL_UPPS_Div32                     = 0x5UL,                /*!< quad signal divided by 32 */
  QEP_QCAPCTL_UPPS_Div64                     = 0x6UL,                /*!< quad signal divided by 64 */
  QEP_QCAPCTL_UPPS_Div128                    = 0x7UL,                /*!< quad signal divided by 128 */
  QEP_QCAPCTL_UPPS_Div256                    = 0x8UL,                /*!< quad signal divided by 256 */
  QEP_QCAPCTL_UPPS_Div512                    = 0x9UL,                /*!< quad signal divided by 512 */
  QEP_QCAPCTL_UPPS_Div1024                   = 0xAUL,                /*!< quad signal divided by 1024 */
  QEP_QCAPCTL_UPPS_Div2048                   = 0xBUL,                /*!< quad signal divided by 2048 */
} QEP_QCAPCTL_UPPS_Enum;

typedef enum {
  QEP_QCAPCTL_CCPS_Disable                   = 0x0UL,                /*!< no divider */
  QEP_QCAPCTL_CCPS_Div2                      = 0x1UL,                /*!< sysclk divided by 2 */
  QEP_QCAPCTL_CCPS_Div4                      = 0x2UL,                /*!< sysclk divided by 4 */
  QEP_QCAPCTL_CCPS_Div8                      = 0x3UL,                /*!< sysclk divided by 8 */
  QEP_QCAPCTL_CCPS_Div16                     = 0x4UL,                /*!< sysclk divided by 16 */
  QEP_QCAPCTL_CCPS_Div32                     = 0x5UL,                /*!< sysclk divided by 32 */
  QEP_QCAPCTL_CCPS_Div64                     = 0x6UL,                /*!< sysclk divided by 64 */
  QEP_QCAPCTL_CCPS_Div128                    = 0x7UL,                /*!< sysclk divided by 128 */
} QEP_QCAPCTL_CCPS_Enum;

/*--  QPOSCTL: Position-compare Control register --------------------------------------------------------------*/
typedef struct {
  uint32_t PCSPW                  :12;                               /*!< Select-position-compare sync output pulse width */
  uint32_t PCE                    :1;                                /*!< Position-compare enable/disable */
  uint32_t PCPOL                  :1;                                /*!< Polarity of sync output */
  uint32_t PCLOAD                 :1;                                /*!< Position-compare shadow load mode */
  uint32_t PCSHDW                 :1;                                /*!< Position-compare shadow enable */
} _QEP_QPOSCTL_bits;

/* Bit field positions: */
#define QEP_QPOSCTL_PCSPW_Pos                 0                      /*!< Select-position-compare sync output pulse width */
#define QEP_QPOSCTL_PCE_Pos                   12                     /*!< Position-compare enable/disable */
#define QEP_QPOSCTL_PCPOL_Pos                 13                     /*!< Polarity of sync output */
#define QEP_QPOSCTL_PCLOAD_Pos                14                     /*!< Position-compare shadow load mode */
#define QEP_QPOSCTL_PCSHDW_Pos                15                     /*!< Position-compare shadow enable */

/* Bit field masks: */
#define QEP_QPOSCTL_PCSPW_Msk                 0x00000FFFUL           /*!< Select-position-compare sync output pulse width */
#define QEP_QPOSCTL_PCE_Msk                   0x00001000UL           /*!< Position-compare enable/disable */
#define QEP_QPOSCTL_PCPOL_Msk                 0x00002000UL           /*!< Polarity of sync output */
#define QEP_QPOSCTL_PCLOAD_Msk                0x00004000UL           /*!< Position-compare shadow load mode */
#define QEP_QPOSCTL_PCSHDW_Msk                0x00008000UL           /*!< Position-compare shadow enable */

/*--  QEINT: Interrupt Enable register ------------------------------------------------------------------------*/
typedef struct {
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t PCE                    :1;                                /*!< Position counter error interrupt enable */
  uint32_t QPE                    :1;                                /*!< Quadrature phase error interrupt enable */
  uint32_t QDC                    :1;                                /*!< Quadrature direction change interrupt enable */
  uint32_t WTO                    :1;                                /*!< Watchdog time out interrupt enable */
  uint32_t PCU                    :1;                                /*!< Position counter underflow interrupt enable */
  uint32_t PCO                    :1;                                /*!< Position counter overflow interrupt enable */
  uint32_t PCR                    :1;                                /*!< Position-compare ready interrupt enable */
  uint32_t PCM                    :1;                                /*!< Position-compare match interrupt enable */
  uint32_t SEL                    :1;                                /*!< Strobe event latch interrupt enable */
  uint32_t IEL                    :1;                                /*!< Index event latch interrupt enable */
  uint32_t UTO                    :1;                                /*!< Unit time out interrupt enable */
} _QEP_QEINT_bits;

/* Bit field positions: */
#define QEP_QEINT_PCE_Pos                     1                      /*!< Position counter error interrupt enable */
#define QEP_QEINT_QPE_Pos                     2                      /*!< Quadrature phase error interrupt enable */
#define QEP_QEINT_QDC_Pos                     3                      /*!< Quadrature direction change interrupt enable */
#define QEP_QEINT_WTO_Pos                     4                      /*!< Watchdog time out interrupt enable */
#define QEP_QEINT_PCU_Pos                     5                      /*!< Position counter underflow interrupt enable */
#define QEP_QEINT_PCO_Pos                     6                      /*!< Position counter overflow interrupt enable */
#define QEP_QEINT_PCR_Pos                     7                      /*!< Position-compare ready interrupt enable */
#define QEP_QEINT_PCM_Pos                     8                      /*!< Position-compare match interrupt enable */
#define QEP_QEINT_SEL_Pos                     9                      /*!< Strobe event latch interrupt enable */
#define QEP_QEINT_IEL_Pos                     10                     /*!< Index event latch interrupt enable */
#define QEP_QEINT_UTO_Pos                     11                     /*!< Unit time out interrupt enable */

/* Bit field masks: */
#define QEP_QEINT_PCE_Msk                     0x00000002UL           /*!< Position counter error interrupt enable */
#define QEP_QEINT_QPE_Msk                     0x00000004UL           /*!< Quadrature phase error interrupt enable */
#define QEP_QEINT_QDC_Msk                     0x00000008UL           /*!< Quadrature direction change interrupt enable */
#define QEP_QEINT_WTO_Msk                     0x00000010UL           /*!< Watchdog time out interrupt enable */
#define QEP_QEINT_PCU_Msk                     0x00000020UL           /*!< Position counter underflow interrupt enable */
#define QEP_QEINT_PCO_Msk                     0x00000040UL           /*!< Position counter overflow interrupt enable */
#define QEP_QEINT_PCR_Msk                     0x00000080UL           /*!< Position-compare ready interrupt enable */
#define QEP_QEINT_PCM_Msk                     0x00000100UL           /*!< Position-compare match interrupt enable */
#define QEP_QEINT_SEL_Msk                     0x00000200UL           /*!< Strobe event latch interrupt enable */
#define QEP_QEINT_IEL_Msk                     0x00000400UL           /*!< Index event latch interrupt enable */
#define QEP_QEINT_UTO_Msk                     0x00000800UL           /*!< Unit time out interrupt enable */

/*--  QFLG: Interrupt Flag register ---------------------------------------------------------------------------*/
typedef struct {
  uint32_t INT                    :1;                                /*!< Global interrupt status flag */
  uint32_t PCE                    :1;                                /*!< Position counter error interrupt flag */
  uint32_t QPE                    :1;                                /*!< Quadrature phase error interrupt flag */
  uint32_t QDC                    :1;                                /*!< Quadrature direction change interrupt flag */
  uint32_t WTO                    :1;                                /*!< Watchdog timeout interrupt flag */
  uint32_t PCU                    :1;                                /*!< Position counter underflow interrupt flag */
  uint32_t PCO                    :1;                                /*!< Position counter overflow interrupt flag */
  uint32_t PCR                    :1;                                /*!< Position-compare ready interrupt flag */
  uint32_t PCM                    :1;                                /*!< QEP compare match event interrupt flag */
  uint32_t SEL                    :1;                                /*!< Strobe event latch interrupt flag
 */
  uint32_t IEL                    :1;                                /*!< Index event latch interrupt flag */
  uint32_t UTO                    :1;                                /*!< Unit time out interrupt flag */
  uint32_t                        :4;                                /*!< RESERVED */
  uint32_t QFLGLAT                :12;                               /*!< Latches QFLG[11:0] on every QPOSCNT read */
} _QEP_QFLG_bits;

/* Bit field positions: */
#define QEP_QFLG_INT_Pos                      0                      /*!< Global interrupt status flag */
#define QEP_QFLG_PCE_Pos                      1                      /*!< Position counter error interrupt flag */
#define QEP_QFLG_QPE_Pos                      2                      /*!< Quadrature phase error interrupt flag */
#define QEP_QFLG_QDC_Pos                      3                      /*!< Quadrature direction change interrupt flag */
#define QEP_QFLG_WTO_Pos                      4                      /*!< Watchdog timeout interrupt flag */
#define QEP_QFLG_PCU_Pos                      5                      /*!< Position counter underflow interrupt flag */
#define QEP_QFLG_PCO_Pos                      6                      /*!< Position counter overflow interrupt flag */
#define QEP_QFLG_PCR_Pos                      7                      /*!< Position-compare ready interrupt flag */
#define QEP_QFLG_PCM_Pos                      8                      /*!< QEP compare match event interrupt flag */
#define QEP_QFLG_SEL_Pos                      9                      /*!< Strobe event latch interrupt flag
 */
#define QEP_QFLG_IEL_Pos                      10                     /*!< Index event latch interrupt flag */
#define QEP_QFLG_UTO_Pos                      11                     /*!< Unit time out interrupt flag */
#define QEP_QFLG_QFLGLAT_Pos                  16                     /*!< Latches QFLG[11:0] on every QPOSCNT read */

/* Bit field masks: */
#define QEP_QFLG_INT_Msk                      0x00000001UL           /*!< Global interrupt status flag */
#define QEP_QFLG_PCE_Msk                      0x00000002UL           /*!< Position counter error interrupt flag */
#define QEP_QFLG_QPE_Msk                      0x00000004UL           /*!< Quadrature phase error interrupt flag */
#define QEP_QFLG_QDC_Msk                      0x00000008UL           /*!< Quadrature direction change interrupt flag */
#define QEP_QFLG_WTO_Msk                      0x00000010UL           /*!< Watchdog timeout interrupt flag */
#define QEP_QFLG_PCU_Msk                      0x00000020UL           /*!< Position counter underflow interrupt flag */
#define QEP_QFLG_PCO_Msk                      0x00000040UL           /*!< Position counter overflow interrupt flag */
#define QEP_QFLG_PCR_Msk                      0x00000080UL           /*!< Position-compare ready interrupt flag */
#define QEP_QFLG_PCM_Msk                      0x00000100UL           /*!< QEP compare match event interrupt flag */
#define QEP_QFLG_SEL_Msk                      0x00000200UL           /*!< Strobe event latch interrupt flag
 */
#define QEP_QFLG_IEL_Msk                      0x00000400UL           /*!< Index event latch interrupt flag */
#define QEP_QFLG_UTO_Msk                      0x00000800UL           /*!< Unit time out interrupt flag */
#define QEP_QFLG_QFLGLAT_Msk                  0x0FFF0000UL           /*!< Latches QFLG[11:0] on every QPOSCNT read */

/*--  QCLR: Interrupt Clear register --------------------------------------------------------------------------*/
typedef struct {
  uint32_t INT                    :1;                                /*!< Global interrupt clear flag */
  uint32_t PCE                    :1;                                /*!< Clear position counter error interrupt flag */
  uint32_t QPE                    :1;                                /*!< Clear quadrature phase error interrupt flag */
  uint32_t QDC                    :1;                                /*!< Clear quadrature direction change interrupt flag */
  uint32_t WTO                    :1;                                /*!< Clear watchdog timeout interrupt flag */
  uint32_t PCU                    :1;                                /*!< Clear position counter underflow interrupt flag */
  uint32_t PCO                    :1;                                /*!< Clear position counter overflow interrupt flag */
  uint32_t PCR                    :1;                                /*!< Clear position-compare ready interrupt flag */
  uint32_t PCM                    :1;                                /*!< Clear eQEP compare match event interrupt flag */
  uint32_t SEL                    :1;                                /*!< Clear strobe event latch interrupt flag */
  uint32_t IEL                    :1;                                /*!< Clear index event latch interrupt flag */
  uint32_t UTO                    :1;                                /*!< Clear unit time out interrupt flag */
} _QEP_QCLR_bits;

/* Bit field positions: */
#define QEP_QCLR_INT_Pos                      0                      /*!< Global interrupt clear flag */
#define QEP_QCLR_PCE_Pos                      1                      /*!< Clear position counter error interrupt flag */
#define QEP_QCLR_QPE_Pos                      2                      /*!< Clear quadrature phase error interrupt flag */
#define QEP_QCLR_QDC_Pos                      3                      /*!< Clear quadrature direction change interrupt flag */
#define QEP_QCLR_WTO_Pos                      4                      /*!< Clear watchdog timeout interrupt flag */
#define QEP_QCLR_PCU_Pos                      5                      /*!< Clear position counter underflow interrupt flag */
#define QEP_QCLR_PCO_Pos                      6                      /*!< Clear position counter overflow interrupt flag */
#define QEP_QCLR_PCR_Pos                      7                      /*!< Clear position-compare ready interrupt flag */
#define QEP_QCLR_PCM_Pos                      8                      /*!< Clear eQEP compare match event interrupt flag */
#define QEP_QCLR_SEL_Pos                      9                      /*!< Clear strobe event latch interrupt flag */
#define QEP_QCLR_IEL_Pos                      10                     /*!< Clear index event latch interrupt flag */
#define QEP_QCLR_UTO_Pos                      11                     /*!< Clear unit time out interrupt flag */

/* Bit field masks: */
#define QEP_QCLR_INT_Msk                      0x00000001UL           /*!< Global interrupt clear flag */
#define QEP_QCLR_PCE_Msk                      0x00000002UL           /*!< Clear position counter error interrupt flag */
#define QEP_QCLR_QPE_Msk                      0x00000004UL           /*!< Clear quadrature phase error interrupt flag */
#define QEP_QCLR_QDC_Msk                      0x00000008UL           /*!< Clear quadrature direction change interrupt flag */
#define QEP_QCLR_WTO_Msk                      0x00000010UL           /*!< Clear watchdog timeout interrupt flag */
#define QEP_QCLR_PCU_Msk                      0x00000020UL           /*!< Clear position counter underflow interrupt flag */
#define QEP_QCLR_PCO_Msk                      0x00000040UL           /*!< Clear position counter overflow interrupt flag */
#define QEP_QCLR_PCR_Msk                      0x00000080UL           /*!< Clear position-compare ready interrupt flag */
#define QEP_QCLR_PCM_Msk                      0x00000100UL           /*!< Clear eQEP compare match event interrupt flag */
#define QEP_QCLR_SEL_Msk                      0x00000200UL           /*!< Clear strobe event latch interrupt flag */
#define QEP_QCLR_IEL_Msk                      0x00000400UL           /*!< Clear index event latch interrupt flag */
#define QEP_QCLR_UTO_Msk                      0x00000800UL           /*!< Clear unit time out interrupt flag */

/*--  QFRC: Interrupt Force register --------------------------------------------------------------------------*/
typedef struct {
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t PCE                    :1;                                /*!< Force position counter error interrupt */
  uint32_t QPE                    :1;                                /*!< Force quadrature phase error interrupt */
  uint32_t QDC                    :1;                                /*!< Force quadrature direction change interrupt */
  uint32_t WTO                    :1;                                /*!< Force watchdog time out interrupt */
  uint32_t PCU                    :1;                                /*!< Force position counter underflow interrupt */
  uint32_t PCO                    :1;                                /*!< Force position counter overflow interrupt */
  uint32_t PCR                    :1;                                /*!< Force position-compare ready interrupt */
  uint32_t PCM                    :1;                                /*!< Force position-compare match interrupt */
  uint32_t SEL                    :1;                                /*!< Force strobe event latch interrupt */
  uint32_t IEL                    :1;                                /*!< Force index event latch interrupt */
  uint32_t UTO                    :1;                                /*!< Force unit time out interrupt */
} _QEP_QFRC_bits;

/* Bit field positions: */
#define QEP_QFRC_PCE_Pos                      1                      /*!< Force position counter error interrupt */
#define QEP_QFRC_QPE_Pos                      2                      /*!< Force quadrature phase error interrupt */
#define QEP_QFRC_QDC_Pos                      3                      /*!< Force quadrature direction change interrupt */
#define QEP_QFRC_WTO_Pos                      4                      /*!< Force watchdog time out interrupt */
#define QEP_QFRC_PCU_Pos                      5                      /*!< Force position counter underflow interrupt */
#define QEP_QFRC_PCO_Pos                      6                      /*!< Force position counter overflow interrupt */
#define QEP_QFRC_PCR_Pos                      7                      /*!< Force position-compare ready interrupt */
#define QEP_QFRC_PCM_Pos                      8                      /*!< Force position-compare match interrupt */
#define QEP_QFRC_SEL_Pos                      9                      /*!< Force strobe event latch interrupt */
#define QEP_QFRC_IEL_Pos                      10                     /*!< Force index event latch interrupt */
#define QEP_QFRC_UTO_Pos                      11                     /*!< Force unit time out interrupt */

/* Bit field masks: */
#define QEP_QFRC_PCE_Msk                      0x00000002UL           /*!< Force position counter error interrupt */
#define QEP_QFRC_QPE_Msk                      0x00000004UL           /*!< Force quadrature phase error interrupt */
#define QEP_QFRC_QDC_Msk                      0x00000008UL           /*!< Force quadrature direction change interrupt */
#define QEP_QFRC_WTO_Msk                      0x00000010UL           /*!< Force watchdog time out interrupt */
#define QEP_QFRC_PCU_Msk                      0x00000020UL           /*!< Force position counter underflow interrupt */
#define QEP_QFRC_PCO_Msk                      0x00000040UL           /*!< Force position counter overflow interrupt */
#define QEP_QFRC_PCR_Msk                      0x00000080UL           /*!< Force position-compare ready interrupt */
#define QEP_QFRC_PCM_Msk                      0x00000100UL           /*!< Force position-compare match interrupt */
#define QEP_QFRC_SEL_Msk                      0x00000200UL           /*!< Force strobe event latch interrupt */
#define QEP_QFRC_IEL_Msk                      0x00000400UL           /*!< Force index event latch interrupt */
#define QEP_QFRC_UTO_Msk                      0x00000800UL           /*!< Force unit time out interrupt */

/*--  QEPSTS: Status register ---------------------------------------------------------------------------------*/
typedef struct {
  uint32_t PCEF                   :1;                                /*!< Position counter error flag */
  uint32_t FIMF                   :1;                                /*!< First index marker flag */
  uint32_t CDEF                   :1;                                /*!< Capture direction error flag */
  uint32_t COEF                   :1;                                /*!< Capture overflow error flag */
  uint32_t QDLF                   :1;                                /*!< QEP direction latch flag */
  uint32_t QDF                    :1;                                /*!< Quadrature direction flag */
  uint32_t FIDF                   :1;                                /*!< Direction on the first index marker */
  uint32_t UPEVNT                 :1;                                /*!< Unit position event flag */
  uint32_t DCF                    :1;                                /*!< Direction change flag */
} _QEP_QEPSTS_bits;

/* Bit field positions: */
#define QEP_QEPSTS_PCEF_Pos                   0                      /*!< Position counter error flag */
#define QEP_QEPSTS_FIMF_Pos                   1                      /*!< First index marker flag */
#define QEP_QEPSTS_CDEF_Pos                   2                      /*!< Capture direction error flag */
#define QEP_QEPSTS_COEF_Pos                   3                      /*!< Capture overflow error flag */
#define QEP_QEPSTS_QDLF_Pos                   4                      /*!< QEP direction latch flag */
#define QEP_QEPSTS_QDF_Pos                    5                      /*!< Quadrature direction flag */
#define QEP_QEPSTS_FIDF_Pos                   6                      /*!< Direction on the first index marker */
#define QEP_QEPSTS_UPEVNT_Pos                 7                      /*!< Unit position event flag */
#define QEP_QEPSTS_DCF_Pos                    8                      /*!< Direction change flag */

/* Bit field masks: */
#define QEP_QEPSTS_PCEF_Msk                   0x00000001UL           /*!< Position counter error flag */
#define QEP_QEPSTS_FIMF_Msk                   0x00000002UL           /*!< First index marker flag */
#define QEP_QEPSTS_CDEF_Msk                   0x00000004UL           /*!< Capture direction error flag */
#define QEP_QEPSTS_COEF_Msk                   0x00000008UL           /*!< Capture overflow error flag */
#define QEP_QEPSTS_QDLF_Msk                   0x00000010UL           /*!< QEP direction latch flag */
#define QEP_QEPSTS_QDF_Msk                    0x00000020UL           /*!< Quadrature direction flag */
#define QEP_QEPSTS_FIDF_Msk                   0x00000040UL           /*!< Direction on the first index marker */
#define QEP_QEPSTS_UPEVNT_Msk                 0x00000080UL           /*!< Unit position event flag */
#define QEP_QEPSTS_DCF_Msk                    0x00000100UL           /*!< Direction change flag */

/*--  QCTMR: Capture Timer register ---------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!<  */
} _QEP_QCTMR_bits;

/* Bit field positions: */
#define QEP_QCTMR_VAL_Pos                     0                      /*!<  */

/* Bit field masks: */
#define QEP_QCTMR_VAL_Msk                     0xFFFFFFFFUL           /*!<  */

/*--  QCPRD: Capture Period register --------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!<  */
} _QEP_QCPRD_bits;

/* Bit field positions: */
#define QEP_QCPRD_VAL_Pos                     0                      /*!<  */

/* Bit field masks: */
#define QEP_QCPRD_VAL_Msk                     0xFFFFFFFFUL           /*!<  */

/*--  QCTMRLAT: Capture Timer Latch register ------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!<  */
} _QEP_QCTMRLAT_bits;

/* Bit field positions: */
#define QEP_QCTMRLAT_VAL_Pos                  0                      /*!<  */

/* Bit field masks: */
#define QEP_QCTMRLAT_VAL_Msk                  0xFFFFFFFFUL           /*!<  */

/*--  QCPRDLAT: Capture Period Latch register -----------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!<  */
} _QEP_QCPRDLAT_bits;

/* Bit field positions: */
#define QEP_QCPRDLAT_VAL_Pos                  0                      /*!<  */

/* Bit field masks: */
#define QEP_QCPRDLAT_VAL_Msk                  0xFFFFFFFFUL           /*!<  */

/*--  DMAREQ: DMA request register ----------------------------------------------------------------------------*/
typedef struct {
  uint32_t DMATXEN                :1;                                /*!< DMA TX request generation enable */
  uint32_t DMARXEN                :1;                                /*!< DMA RX request generation enable */
} _QEP_DMAREQ_bits;

/* Bit field positions: */
#define QEP_DMAREQ_DMATXEN_Pos                0                      /*!< DMA TX request generation enable */
#define QEP_DMAREQ_DMARXEN_Pos                1                      /*!< DMA RX request generation enable */

/* Bit field masks: */
#define QEP_DMAREQ_DMATXEN_Msk                0x00000001UL           /*!< DMA TX request generation enable */
#define QEP_DMAREQ_DMARXEN_Msk                0x00000002UL           /*!< DMA RX request generation enable */

/*--  INTCLR: Clear active interrupt register -----------------------------------------------------------------*/
typedef struct {
  uint32_t INT                    :1;                                /*!< Active interrupt by read, write 1 to clear interrupt */
} _QEP_INTCLR_bits;

/* Bit field positions: */
#define QEP_INTCLR_INT_Pos                    0                      /*!< Active interrupt by read, write 1 to clear interrupt */

/* Bit field masks: */
#define QEP_INTCLR_INT_Msk                    0x00000001UL           /*!< Active interrupt by read, write 1 to clear interrupt */

typedef struct {
  union {                                                               /*!< Position Counter register */
    __IO uint32_t QPOSCNT;                                           /*!< QPOSCNT    : type used for word access */
    __IO _QEP_QPOSCNT_bits  QPOSCNT_bit;                             /*!< QPOSCNT_bit: structure used for bit access */
  };
  union {                                                               /*!< Position Counter Initialization register */
    __IO uint32_t QPOSINIT;                                           /*!< QPOSINIT    : type used for word access */
    __IO _QEP_QPOSINIT_bits  QPOSINIT_bit;                           /*!< QPOSINIT_bit: structure used for bit access */
  };
  union {                                                               /*!< Maximum Position Count register */
    __IO uint32_t QPOSMAX;                                           /*!< QPOSMAX    : type used for word access */
    __IO _QEP_QPOSMAX_bits  QPOSMAX_bit;                             /*!< QPOSMAX_bit: structure used for bit access */
  };
  union {                                                               /*!< Position-compare register */
    __IO uint32_t QPOSCMP;                                           /*!< QPOSCMP    : type used for word access */
    __IO _QEP_QPOSCMP_bits  QPOSCMP_bit;                             /*!< QPOSCMP_bit: structure used for bit access */
  };
  union {                                                               /*!< Index Position Latch register */
    __I uint32_t QPOSILAT;                                           /*!< QPOSILAT    : type used for word access */
    __I _QEP_QPOSILAT_bits  QPOSILAT_bit;                            /*!< QPOSILAT_bit: structure used for bit access */
  };
  union {                                                               /*!< Strobe Position Latch register */
    __I uint32_t QPOSSLAT;                                           /*!< QPOSSLAT    : type used for word access */
    __I _QEP_QPOSSLAT_bits  QPOSSLAT_bit;                            /*!< QPOSSLAT_bit: structure used for bit access */
  };
  union {                                                               /*!< Position Counter Latch register */
    __I uint32_t QPOSLAT;                                            /*!< QPOSLAT    : type used for word access */
    __I _QEP_QPOSLAT_bits  QPOSLAT_bit;                              /*!< QPOSLAT_bit: structure used for bit access */
  };
  union {                                                               /*!< Unit Timer register */
    __IO uint32_t QUTMR;                                             /*!< QUTMR    : type used for word access */
    __IO _QEP_QUTMR_bits  QUTMR_bit;                                 /*!< QUTMR_bit: structure used for bit access */
  };
  union {                                                               /*!< Unit Period register */
    __IO uint32_t QUPRD;                                             /*!< QUPRD    : type used for word access */
    __IO _QEP_QUPRD_bits  QUPRD_bit;                                 /*!< QUPRD_bit: structure used for bit access */
  };
  union {                                                               /*!< Watchdog Timer register */
    __IO uint32_t QWDTMR;                                            /*!< QWDTMR    : type used for word access */
    __IO _QEP_QWDTMR_bits  QWDTMR_bit;                               /*!< QWDTMR_bit: structure used for bit access */
  };
  union {                                                               /*!< Watchdog Period register */
    __IO uint32_t QWDPRD;                                            /*!< QWDPRD    : type used for word access */
    __IO _QEP_QWDPRD_bits  QWDPRD_bit;                               /*!< QWDPRD_bit: structure used for bit access */
  };
  union {                                                               /*!< Decoder Control register */
    __IO uint32_t QDECCTL;                                           /*!< QDECCTL    : type used for word access */
    __IO _QEP_QDECCTL_bits  QDECCTL_bit;                             /*!< QDECCTL_bit: structure used for bit access */
  };
  union {                                                               /*!< Control register */
    __IO uint32_t QEPCTL;                                            /*!< QEPCTL    : type used for word access */
    __IO _QEP_QEPCTL_bits  QEPCTL_bit;                               /*!< QEPCTL_bit: structure used for bit access */
  };
  union {                                                               /*!< Capture Control register */
    __IO uint32_t QCAPCTL;                                           /*!< QCAPCTL    : type used for word access */
    __IO _QEP_QCAPCTL_bits  QCAPCTL_bit;                             /*!< QCAPCTL_bit: structure used for bit access */
  };
  union {                                                               /*!< Position-compare Control register */
    __IO uint32_t QPOSCTL;                                           /*!< QPOSCTL    : type used for word access */
    __IO _QEP_QPOSCTL_bits  QPOSCTL_bit;                             /*!< QPOSCTL_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt Enable register */
    __IO uint32_t QEINT;                                             /*!< QEINT    : type used for word access */
    __IO _QEP_QEINT_bits  QEINT_bit;                                 /*!< QEINT_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt Flag register */
    __I uint32_t QFLG;                                               /*!< QFLG    : type used for word access */
    __I _QEP_QFLG_bits  QFLG_bit;                                    /*!< QFLG_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt Clear register */
    __O uint32_t QCLR;                                               /*!< QCLR    : type used for word access */
    __O _QEP_QCLR_bits  QCLR_bit;                                    /*!< QCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt Force register */
    __O uint32_t QFRC;                                               /*!< QFRC    : type used for word access */
    __O _QEP_QFRC_bits  QFRC_bit;                                    /*!< QFRC_bit: structure used for bit access */
  };
  union {                                                               /*!< Status register */
    __IO uint32_t QEPSTS;                                            /*!< QEPSTS    : type used for word access */
    __IO _QEP_QEPSTS_bits  QEPSTS_bit;                               /*!< QEPSTS_bit: structure used for bit access */
  };
  union {                                                               /*!< Capture Timer register */
    __IO uint32_t QCTMR;                                             /*!< QCTMR    : type used for word access */
    __IO _QEP_QCTMR_bits  QCTMR_bit;                                 /*!< QCTMR_bit: structure used for bit access */
  };
  union {                                                               /*!< Capture Period register */
    __IO uint32_t QCPRD;                                             /*!< QCPRD    : type used for word access */
    __IO _QEP_QCPRD_bits  QCPRD_bit;                                 /*!< QCPRD_bit: structure used for bit access */
  };
  union {                                                               /*!< Capture Timer Latch register */
    __I uint32_t QCTMRLAT;                                           /*!< QCTMRLAT    : type used for word access */
    __I _QEP_QCTMRLAT_bits  QCTMRLAT_bit;                            /*!< QCTMRLAT_bit: structure used for bit access */
  };
  union {                                                               /*!< Capture Period Latch register */
    __I uint32_t QCPRDLAT;                                           /*!< QCPRDLAT    : type used for word access */
    __I _QEP_QCPRDLAT_bits  QCPRDLAT_bit;                            /*!< QCPRDLAT_bit: structure used for bit access */
  };
  union {                                                               /*!< DMA request register */
    __IO uint32_t DMAREQ;                                            /*!< DMAREQ    : type used for word access */
    __IO _QEP_DMAREQ_bits  DMAREQ_bit;                               /*!< DMAREQ_bit: structure used for bit access */
  };
    __IO uint32_t Reserved0[3];
  union {                                                               /*!< Clear active interrupt register */
    __IO uint32_t INTCLR;                                            /*!< INTCLR    : type used for word access */
    __IO _QEP_INTCLR_bits  INTCLR_bit;                               /*!< INTCLR_bit: structure used for bit access */
  };
} QEP_TypeDef;


/******************************************************************************/
/*                         RCU registers                                      */
/******************************************************************************/

/*--  CGCFGAHB: Clockgate AHB configuration register ----------------------------------------------------------*/
typedef struct {
  uint32_t GPIOAEN                :1;                                /*!< Enable clock GPIOA */
  uint32_t GPIOBEN                :1;                                /*!< Enable clock GPIOB */
  uint32_t CANEN                  :1;                                /*!< Enable clock CAN */
  uint32_t ADCEN                  :1;                                /*!< Enable clock ADC */
} _RCU_CGCFGAHB_bits;

/* Bit field positions: */
#define RCU_CGCFGAHB_GPIOAEN_Pos              0                      /*!< Enable clock GPIOA */
#define RCU_CGCFGAHB_GPIOBEN_Pos              1                      /*!< Enable clock GPIOB */
#define RCU_CGCFGAHB_CANEN_Pos                2                      /*!< Enable clock CAN */
#define RCU_CGCFGAHB_ADCEN_Pos                3                      /*!< Enable clock ADC */

/* Bit field masks: */
#define RCU_CGCFGAHB_GPIOAEN_Msk              0x00000001UL           /*!< Enable clock GPIOA */
#define RCU_CGCFGAHB_GPIOBEN_Msk              0x00000002UL           /*!< Enable clock GPIOB */
#define RCU_CGCFGAHB_CANEN_Msk                0x00000004UL           /*!< Enable clock CAN */
#define RCU_CGCFGAHB_ADCEN_Msk                0x00000008UL           /*!< Enable clock ADC */

/*--  CGCFGAPB: Clockgate APB configuration register ----------------------------------------------------------*/
typedef struct {
  uint32_t DMAEN                  :1;                                /*!< Enable clock WDT */
  uint32_t RTCEN                  :1;                                /*!< Enable clock I2C */
  uint32_t WDTEN                  :1;                                /*!< Enable clock TMR1 */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t CAP0EN                 :1;                                /*!< Enable clock TMR2 */
  uint32_t CAP1EN                 :1;                                /*!< Enable clock TRNG */
  uint32_t CAP2EN                 :1;                                /*!< Enable clock I2C */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t TMR0EN                 :1;                                /*!< Enable clock TMR0 */
  uint32_t TMR1EN                 :1;                                /*!< Enable clock TMR1 */
  uint32_t TMR2EN                 :1;                                /*!< Enable clock TMR2 */
  uint32_t TMR3EN                 :1;                                /*!< Enable clock TMR3 */
  uint32_t SPI0EN                 :1;                                /*!< Enable clock SPI0 */
  uint32_t SPI1EN                 :1;                                /*!< Enable clock SPI1 */
  uint32_t                        :2;                                /*!< RESERVED */
  uint32_t UART0EN                :1;                                /*!< Enable clock UART0 */
  uint32_t UART1EN                :1;                                /*!< Enable clock UART1 */
  uint32_t                        :2;                                /*!< RESERVED */
  uint32_t PWM0EN                 :1;                                /*!< Enable clock PWM0 */
  uint32_t PWM1EN                 :1;                                /*!< Enable clock PWM1 */
  uint32_t PWM2EN                 :1;                                /*!< Enable clock PWM2 */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t I2CEN                  :1;                                /*!< Enable clock I2C */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t QEPEN                  :1;                                /*!< Enable clock QEP */
} _RCU_CGCFGAPB_bits;

/* Bit field positions: */
#define RCU_CGCFGAPB_DMAEN_Pos                0                      /*!< Enable clock WDT */
#define RCU_CGCFGAPB_RTCEN_Pos                1                      /*!< Enable clock I2C */
#define RCU_CGCFGAPB_WDTEN_Pos                2                      /*!< Enable clock TMR1 */
#define RCU_CGCFGAPB_CAP0EN_Pos               4                      /*!< Enable clock TMR2 */
#define RCU_CGCFGAPB_CAP1EN_Pos               5                      /*!< Enable clock TRNG */
#define RCU_CGCFGAPB_CAP2EN_Pos               6                      /*!< Enable clock I2C */
#define RCU_CGCFGAPB_TMR0EN_Pos               8                      /*!< Enable clock TMR0 */
#define RCU_CGCFGAPB_TMR1EN_Pos               9                      /*!< Enable clock TMR1 */
#define RCU_CGCFGAPB_TMR2EN_Pos               10                     /*!< Enable clock TMR2 */
#define RCU_CGCFGAPB_TMR3EN_Pos               11                     /*!< Enable clock TMR3 */
#define RCU_CGCFGAPB_SPI0EN_Pos               12                     /*!< Enable clock SPI0 */
#define RCU_CGCFGAPB_SPI1EN_Pos               13                     /*!< Enable clock SPI1 */
#define RCU_CGCFGAPB_UART0EN_Pos              16                     /*!< Enable clock UART0 */
#define RCU_CGCFGAPB_UART1EN_Pos              17                     /*!< Enable clock UART1 */
#define RCU_CGCFGAPB_PWM0EN_Pos               20                     /*!< Enable clock PWM0 */
#define RCU_CGCFGAPB_PWM1EN_Pos               21                     /*!< Enable clock PWM1 */
#define RCU_CGCFGAPB_PWM2EN_Pos               22                     /*!< Enable clock PWM2 */
#define RCU_CGCFGAPB_I2CEN_Pos                24                     /*!< Enable clock I2C */
#define RCU_CGCFGAPB_QEPEN_Pos                26                     /*!< Enable clock QEP */

/* Bit field masks: */
#define RCU_CGCFGAPB_DMAEN_Msk                0x00000001UL           /*!< Enable clock WDT */
#define RCU_CGCFGAPB_RTCEN_Msk                0x00000002UL           /*!< Enable clock I2C */
#define RCU_CGCFGAPB_WDTEN_Msk                0x00000004UL           /*!< Enable clock TMR1 */
#define RCU_CGCFGAPB_CAP0EN_Msk               0x00000010UL           /*!< Enable clock TMR2 */
#define RCU_CGCFGAPB_CAP1EN_Msk               0x00000020UL           /*!< Enable clock TRNG */
#define RCU_CGCFGAPB_CAP2EN_Msk               0x00000040UL           /*!< Enable clock I2C */
#define RCU_CGCFGAPB_TMR0EN_Msk               0x00000100UL           /*!< Enable clock TMR0 */
#define RCU_CGCFGAPB_TMR1EN_Msk               0x00000200UL           /*!< Enable clock TMR1 */
#define RCU_CGCFGAPB_TMR2EN_Msk               0x00000400UL           /*!< Enable clock TMR2 */
#define RCU_CGCFGAPB_TMR3EN_Msk               0x00000800UL           /*!< Enable clock TMR3 */
#define RCU_CGCFGAPB_SPI0EN_Msk               0x00001000UL           /*!< Enable clock SPI0 */
#define RCU_CGCFGAPB_SPI1EN_Msk               0x00002000UL           /*!< Enable clock SPI1 */
#define RCU_CGCFGAPB_UART0EN_Msk              0x00010000UL           /*!< Enable clock UART0 */
#define RCU_CGCFGAPB_UART1EN_Msk              0x00020000UL           /*!< Enable clock UART1 */
#define RCU_CGCFGAPB_PWM0EN_Msk               0x00100000UL           /*!< Enable clock PWM0 */
#define RCU_CGCFGAPB_PWM1EN_Msk               0x00200000UL           /*!< Enable clock PWM1 */
#define RCU_CGCFGAPB_PWM2EN_Msk               0x00400000UL           /*!< Enable clock PWM2 */
#define RCU_CGCFGAPB_I2CEN_Msk                0x01000000UL           /*!< Enable clock I2C */
#define RCU_CGCFGAPB_QEPEN_Msk                0x04000000UL           /*!< Enable clock QEP */

/*--  RSTDISAHB: Reset disable AHB configuration register -----------------------------------------------------*/
typedef struct {
  uint32_t GPIOAEN                :1;                                /*!< Disable reset GPIOA */
  uint32_t GPIOBEN                :1;                                /*!< Disable reset GPIOB */
  uint32_t CANEN                  :1;                                /*!< Disable reset CAN */
  uint32_t ADCEN                  :1;                                /*!< Disable reset ADC */
} _RCU_RSTDISAHB_bits;

/* Bit field positions: */
#define RCU_RSTDISAHB_GPIOAEN_Pos             0                      /*!< Disable reset GPIOA */
#define RCU_RSTDISAHB_GPIOBEN_Pos             1                      /*!< Disable reset GPIOB */
#define RCU_RSTDISAHB_CANEN_Pos               2                      /*!< Disable reset CAN */
#define RCU_RSTDISAHB_ADCEN_Pos               3                      /*!< Disable reset ADC */

/* Bit field masks: */
#define RCU_RSTDISAHB_GPIOAEN_Msk             0x00000001UL           /*!< Disable reset GPIOA */
#define RCU_RSTDISAHB_GPIOBEN_Msk             0x00000002UL           /*!< Disable reset GPIOB */
#define RCU_RSTDISAHB_CANEN_Msk               0x00000004UL           /*!< Disable reset CAN */
#define RCU_RSTDISAHB_ADCEN_Msk               0x00000008UL           /*!< Disable reset ADC */

/*--  RSTDISAPB: Reset disable APB register -------------------------------------------------------------------*/
typedef struct {
  uint32_t DMAEN                  :1;                                /*!< Disable reset WDT */
  uint32_t RTCEN                  :1;                                /*!< Disable reset I2C */
  uint32_t WDTEN                  :1;                                /*!< Disable reset TMR1 */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t CAP0EN                 :1;                                /*!< Disable reset TMR2 */
  uint32_t CAP1EN                 :1;                                /*!< Disable reset TRNG */
  uint32_t CAP2EN                 :1;                                /*!< Disable reset I2C */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t TMR0EN                 :1;                                /*!< Disable reset TMR0 */
  uint32_t TMR1EN                 :1;                                /*!< Disable reset TMR1 */
  uint32_t TMR2EN                 :1;                                /*!< Disable reset TMR2 */
  uint32_t TMR3EN                 :1;                                /*!< Disable reset TMR3 */
  uint32_t SPI0EN                 :1;                                /*!< Disable reset SPI0 */
  uint32_t SPI1EN                 :1;                                /*!< Disable reset SPI1 */
  uint32_t                        :2;                                /*!< RESERVED */
  uint32_t UART0EN                :1;                                /*!< Disable reset UART0 */
  uint32_t UART1EN                :1;                                /*!< Disable reset UART1 */
  uint32_t                        :2;                                /*!< RESERVED */
  uint32_t PWM0EN                 :1;                                /*!< Disable reset PWM0 */
  uint32_t PWM1EN                 :1;                                /*!< Disable reset PWM1 */
  uint32_t PWM2EN                 :1;                                /*!< Disable reset PWM2 */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t I2CEN                  :1;                                /*!< Disable reset I2C */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t QEPEN                  :1;                                /*!< Disable reset QEP */
} _RCU_RSTDISAPB_bits;

/* Bit field positions: */
#define RCU_RSTDISAPB_DMAEN_Pos               0                      /*!< Disable reset WDT */
#define RCU_RSTDISAPB_RTCEN_Pos               1                      /*!< Disable reset I2C */
#define RCU_RSTDISAPB_WDTEN_Pos               2                      /*!< Disable reset TMR1 */
#define RCU_RSTDISAPB_CAP0EN_Pos              4                      /*!< Disable reset TMR2 */
#define RCU_RSTDISAPB_CAP1EN_Pos              5                      /*!< Disable reset TRNG */
#define RCU_RSTDISAPB_CAP2EN_Pos              6                      /*!< Disable reset I2C */
#define RCU_RSTDISAPB_TMR0EN_Pos              8                      /*!< Disable reset TMR0 */
#define RCU_RSTDISAPB_TMR1EN_Pos              9                      /*!< Disable reset TMR1 */
#define RCU_RSTDISAPB_TMR2EN_Pos              10                     /*!< Disable reset TMR2 */
#define RCU_RSTDISAPB_TMR3EN_Pos              11                     /*!< Disable reset TMR3 */
#define RCU_RSTDISAPB_SPI0EN_Pos              12                     /*!< Disable reset SPI0 */
#define RCU_RSTDISAPB_SPI1EN_Pos              13                     /*!< Disable reset SPI1 */
#define RCU_RSTDISAPB_UART0EN_Pos             16                     /*!< Disable reset UART0 */
#define RCU_RSTDISAPB_UART1EN_Pos             17                     /*!< Disable reset UART1 */
#define RCU_RSTDISAPB_PWM0EN_Pos              20                     /*!< Disable reset PWM0 */
#define RCU_RSTDISAPB_PWM1EN_Pos              21                     /*!< Disable reset PWM1 */
#define RCU_RSTDISAPB_PWM2EN_Pos              22                     /*!< Disable reset PWM2 */
#define RCU_RSTDISAPB_I2CEN_Pos               24                     /*!< Disable reset I2C */
#define RCU_RSTDISAPB_QEPEN_Pos               26                     /*!< Disable reset QEP */

/* Bit field masks: */
#define RCU_RSTDISAPB_DMAEN_Msk               0x00000001UL           /*!< Disable reset WDT */
#define RCU_RSTDISAPB_RTCEN_Msk               0x00000002UL           /*!< Disable reset I2C */
#define RCU_RSTDISAPB_WDTEN_Msk               0x00000004UL           /*!< Disable reset TMR1 */
#define RCU_RSTDISAPB_CAP0EN_Msk              0x00000010UL           /*!< Disable reset TMR2 */
#define RCU_RSTDISAPB_CAP1EN_Msk              0x00000020UL           /*!< Disable reset TRNG */
#define RCU_RSTDISAPB_CAP2EN_Msk              0x00000040UL           /*!< Disable reset I2C */
#define RCU_RSTDISAPB_TMR0EN_Msk              0x00000100UL           /*!< Disable reset TMR0 */
#define RCU_RSTDISAPB_TMR1EN_Msk              0x00000200UL           /*!< Disable reset TMR1 */
#define RCU_RSTDISAPB_TMR2EN_Msk              0x00000400UL           /*!< Disable reset TMR2 */
#define RCU_RSTDISAPB_TMR3EN_Msk              0x00000800UL           /*!< Disable reset TMR3 */
#define RCU_RSTDISAPB_SPI0EN_Msk              0x00001000UL           /*!< Disable reset SPI0 */
#define RCU_RSTDISAPB_SPI1EN_Msk              0x00002000UL           /*!< Disable reset SPI1 */
#define RCU_RSTDISAPB_UART0EN_Msk             0x00010000UL           /*!< Disable reset UART0 */
#define RCU_RSTDISAPB_UART1EN_Msk             0x00020000UL           /*!< Disable reset UART1 */
#define RCU_RSTDISAPB_PWM0EN_Msk              0x00100000UL           /*!< Disable reset PWM0 */
#define RCU_RSTDISAPB_PWM1EN_Msk              0x00200000UL           /*!< Disable reset PWM1 */
#define RCU_RSTDISAPB_PWM2EN_Msk              0x00400000UL           /*!< Disable reset PWM2 */
#define RCU_RSTDISAPB_I2CEN_Msk               0x01000000UL           /*!< Disable reset I2C */
#define RCU_RSTDISAPB_QEPEN_Msk               0x04000000UL           /*!< Disable reset QEP */

/*--  SYSCLKCFG: System clock configuration register ----------------------------------------------------------*/
typedef struct {
  uint32_t SRC                    :2;                                /*!< System clock source */
  uint32_t                        :6;                                /*!< RESERVED */
  uint32_t SECEN                  :1;                                /*!<  */
} _RCU_SYSCLKCFG_bits;

/* Bit field positions: */
#define RCU_SYSCLKCFG_SRC_Pos                 0                      /*!< System clock source */
#define RCU_SYSCLKCFG_SECEN_Pos               8                      /*!<  */

/* Bit field masks: */
#define RCU_SYSCLKCFG_SRC_Msk                 0x00000003UL           /*!< System clock source */
#define RCU_SYSCLKCFG_SECEN_Msk               0x00000100UL           /*!<  */

/* Bit field enums: */
typedef enum {
  RCU_SYSCLKCFG_SRC_HSICLK                   = 0x0UL,                /*!< HSI 4MHz */
  RCU_SYSCLKCFG_SRC_HSECLK                   = 0x1UL,                /*!< HSE(XTALL)  */
  RCU_SYSCLKCFG_SRC_PLLCLK                   = 0x2UL,                /*!< Clock from PLL OUT[0] */
  RCU_SYSCLKCFG_SRC_EXTCLK                   = 0x3UL,                /*!< external CLK from gpio pin */
} RCU_SYSCLKCFG_SRC_Enum;

/*--  SECCNT0: Security counter configuration 0 register ------------------------------------------------------*/
typedef struct {
  uint32_t VAL0                   :16;                               /*!<  */
  uint32_t VAL1                   :16;                               /*!<  */
} _RCU_SECCNT0_bits;

/* Bit field positions: */
#define RCU_SECCNT0_VAL0_Pos                  0                      /*!<  */
#define RCU_SECCNT0_VAL1_Pos                  16                     /*!<  */

/* Bit field masks: */
#define RCU_SECCNT0_VAL0_Msk                  0x0000FFFFUL           /*!<  */
#define RCU_SECCNT0_VAL1_Msk                  0xFFFF0000UL           /*!<  */

/*--  SECCNT1: Security counter configuration 1 register ------------------------------------------------------*/
typedef struct {
  uint32_t VAL2                   :16;                               /*!<  */
  uint32_t VAL3                   :16;                               /*!<  */
} _RCU_SECCNT1_bits;

/* Bit field positions: */
#define RCU_SECCNT1_VAL2_Pos                  0                      /*!<  */
#define RCU_SECCNT1_VAL3_Pos                  16                     /*!<  */

/* Bit field masks: */
#define RCU_SECCNT1_VAL2_Msk                  0x0000FFFFUL           /*!<  */
#define RCU_SECCNT1_VAL3_Msk                  0xFFFF0000UL           /*!<  */

/*--  CLKSTAT: System clock status register -------------------------------------------------------------------*/
typedef struct {
  uint32_t SRC                    :2;                                /*!< REFCLK:0:HSI 1MHz if CPE=0 or HSE(XTALL) if CPE=1;SRCCLK:1:HSE(XTALL) if CPE=0 or HSI 1MHz if CPE=1;PLLCLK:2: Clock from PLL OUT[0];EXTCLK:3: external CLK from gpio pin; */
  uint32_t                        :6;                                /*!< RESERVED */
  uint32_t CLKGOOD0               :1;                                /*!<  */
  uint32_t CLKGOOD1               :1;                                /*!<  */
  uint32_t CLKGOOD2               :1;                                /*!<  */
  uint32_t CLKGOOD3               :1;                                /*!<  */
  uint32_t                        :4;                                /*!< RESERVED */
  uint32_t CLKERR0                :1;                                /*!<  */
  uint32_t CLKERR1                :1;                                /*!<  */
  uint32_t CLKERR2                :1;                                /*!<  */
  uint32_t CLKERR3                :1;                                /*!<  */
} _RCU_CLKSTAT_bits;

/* Bit field positions: */
#define RCU_CLKSTAT_SRC_Pos                   0                      /*!< REFCLK:0:HSI 1MHz if CPE=0 or HSE(XTALL) if CPE=1;SRCCLK:1:HSE(XTALL) if CPE=0 or HSI 1MHz if CPE=1;PLLCLK:2: Clock from PLL OUT[0];EXTCLK:3: external CLK from gpio pin; */
#define RCU_CLKSTAT_CLKGOOD0_Pos              8                      /*!<  */
#define RCU_CLKSTAT_CLKGOOD1_Pos              9                      /*!<  */
#define RCU_CLKSTAT_CLKGOOD2_Pos              10                     /*!<  */
#define RCU_CLKSTAT_CLKGOOD3_Pos              11                     /*!<  */
#define RCU_CLKSTAT_CLKERR0_Pos               16                     /*!<  */
#define RCU_CLKSTAT_CLKERR1_Pos               17                     /*!<  */
#define RCU_CLKSTAT_CLKERR2_Pos               18                     /*!<  */
#define RCU_CLKSTAT_CLKERR3_Pos               19                     /*!<  */

/* Bit field masks: */
#define RCU_CLKSTAT_SRC_Msk                   0x00000003UL           /*!< REFCLK:0:HSI 1MHz if CPE=0 or HSE(XTALL) if CPE=1;SRCCLK:1:HSE(XTALL) if CPE=0 or HSI 1MHz if CPE=1;PLLCLK:2: Clock from PLL OUT[0];EXTCLK:3: external CLK from gpio pin; */
#define RCU_CLKSTAT_CLKGOOD0_Msk              0x00000100UL           /*!<  */
#define RCU_CLKSTAT_CLKGOOD1_Msk              0x00000200UL           /*!<  */
#define RCU_CLKSTAT_CLKGOOD2_Msk              0x00000400UL           /*!<  */
#define RCU_CLKSTAT_CLKGOOD3_Msk              0x00000800UL           /*!<  */
#define RCU_CLKSTAT_CLKERR0_Msk               0x00010000UL           /*!<  */
#define RCU_CLKSTAT_CLKERR1_Msk               0x00020000UL           /*!<  */
#define RCU_CLKSTAT_CLKERR2_Msk               0x00040000UL           /*!<  */
#define RCU_CLKSTAT_CLKERR3_Msk               0x00080000UL           /*!<  */

/* Bit field enums: */
typedef enum {
  RCU_CLKSTAT_SRC_HSICLK                   = 0x0UL,                /*!< HSI 4MHz */
  RCU_CLKSTAT_SRC_HSECLK                   = 0x1UL,                /*!< HSE(XTALL)  */
  RCU_CLKSTAT_SRC_PLLCLK                   = 0x2UL,                /*!< Clock from PLL OUT[0] */
  RCU_CLKSTAT_SRC_EXTCLK                   = 0x3UL,                /*!< external CLK from gpio pin */
} RCU_CLKSTAT_SRC_Enum;

/*--  RSTSYS: System Reset Register ---------------------------------------------------------------------------*/
typedef struct {
  uint32_t RSTEN                  :1;                                /*!< Reset enable */
  uint32_t                        :15;                               /*!< RESERVED */
  uint32_t KEY                    :16;                               /*!< KEY 'A55A' in hexadecimal for unblocking */
} _RCU_RSTSYS_bits;

/* Bit field positions: */
#define RCU_RSTSYS_RSTEN_Pos                  0                      /*!< Reset enable */
#define RCU_RSTSYS_KEY_Pos                    16                     /*!< KEY 'A55A' in hexadecimal for unblocking */

/* Bit field masks: */
#define RCU_RSTSYS_RSTEN_Msk                  0x00000001UL           /*!< Reset enable */
#define RCU_RSTSYS_KEY_Msk                    0xFFFF0000UL           /*!< KEY 'A55A' in hexadecimal for unblocking */

/*--  RSTSTAT: Reset Status Register --------------------------------------------------------------------------*/
typedef struct {
  uint32_t POR                    :1;                                /*!< PowerOn Reset status */
  uint32_t WDOG                   :1;                                /*!< WatchDog Reset status */
  uint32_t SYSRST                 :1;                                /*!< System Reset Status */
  uint32_t BOR                    :1;                                /*!< BOR Reset status */
} _RCU_RSTSTAT_bits;

/* Bit field positions: */
#define RCU_RSTSTAT_POR_Pos                   0                      /*!< PowerOn Reset status */
#define RCU_RSTSTAT_WDOG_Pos                  1                      /*!< WatchDog Reset status */
#define RCU_RSTSTAT_SYSRST_Pos                2                      /*!< System Reset Status */
#define RCU_RSTSTAT_BOR_Pos                   3                      /*!< BOR Reset status */

/* Bit field masks: */
#define RCU_RSTSTAT_POR_Msk                   0x00000001UL           /*!< PowerOn Reset status */
#define RCU_RSTSTAT_WDOG_Msk                  0x00000002UL           /*!< WatchDog Reset status */
#define RCU_RSTSTAT_SYSRST_Msk                0x00000004UL           /*!< System Reset Status */
#define RCU_RSTSTAT_BOR_Msk                   0x00000008UL           /*!< BOR Reset status */

/*--  PLLCFG: PLL Configuration Register ----------------------------------------------------------------------*/
typedef struct {
  uint32_t PD                     :1;                                /*!< Powerdown enable */
  uint32_t BYPASS                 :1;                                /*!< Bypass enable */
  uint32_t FOUTEN                 :1;                                /*!< Fout enable */
  uint32_t CLKSEL                 :1;                                /*!< 0:HSE:external xi_hse input; 1:EXTCLK: external clock input */
  uint32_t SP                     :1;                                /*!< Song-Park mode */
  uint32_t ST                     :3;                                /*!< Sggma-delta modulator mode */
  uint32_t CP                     :4;                                /*!< Output current of current switch */
  uint32_t PFD                    :2;                                /*!< Mode of current switch */
  uint32_t LPF                    :2;                                /*!< Loop filter band */
  uint32_t VCOMODE                :4;                                /*!< Subband selection signal */
  uint32_t VCOMA                  :1;                                /*!< Ajust amplitude of GUN */
  uint32_t VCOMF                  :1;                                /*!< Ajust lower range of GUN */
  uint32_t DLDMODE                :1;                                /*!< Frequency detector delay */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t DT                     :2;                                /*!< fractional noise randomization mode */
  uint32_t                        :2;                                /*!< RESERVED */
  uint32_t MXEN                   :1;                                /*!< Test mux enable */
  uint32_t MX                     :3;                                /*!< Test mux signal select */
} _RCU_PLLCFG_bits;

/* Bit field positions: */
#define RCU_PLLCFG_PD_Pos                     0                      /*!< Powerdown enable */
#define RCU_PLLCFG_BYPASS_Pos                 1                      /*!< Bypass enable */
#define RCU_PLLCFG_FOUTEN_Pos                 2                      /*!< Fout enable */
#define RCU_PLLCFG_CLKSEL_Pos                 3                      /*!< 0:HSE:external xi_hse input; 1:EXTCLK: external clock input */
#define RCU_PLLCFG_SP_Pos                     4                      /*!< Song-Park mode */
#define RCU_PLLCFG_ST_Pos                     5                      /*!< Sggma-delta modulator mode */
#define RCU_PLLCFG_CP_Pos                     8                      /*!< Output current of current switch */
#define RCU_PLLCFG_PFD_Pos                    12                     /*!< Mode of current switch */
#define RCU_PLLCFG_LPF_Pos                    14                     /*!< Loop filter band */
#define RCU_PLLCFG_VCOMODE_Pos                16                     /*!< Subband selection signal */
#define RCU_PLLCFG_VCOMA_Pos                  20                     /*!< Ajust amplitude of GUN */
#define RCU_PLLCFG_VCOMF_Pos                  21                     /*!< Ajust lower range of GUN */
#define RCU_PLLCFG_DLDMODE_Pos                22                     /*!< Frequency detector delay */
#define RCU_PLLCFG_DT_Pos                     24                     /*!< fractional noise randomization mode */
#define RCU_PLLCFG_MXEN_Pos                   28                     /*!< Test mux enable */
#define RCU_PLLCFG_MX_Pos                     29                     /*!< Test mux signal select */

/* Bit field masks: */
#define RCU_PLLCFG_PD_Msk                     0x00000001UL           /*!< Powerdown enable */
#define RCU_PLLCFG_BYPASS_Msk                 0x00000002UL           /*!< Bypass enable */
#define RCU_PLLCFG_FOUTEN_Msk                 0x00000004UL           /*!< Fout enable */
#define RCU_PLLCFG_CLKSEL_Msk                 0x00000008UL           /*!< 0:HSE:external xi_hse input; 1:EXTCLK: external clock input */
#define RCU_PLLCFG_SP_Msk                     0x00000010UL           /*!< Song-Park mode */
#define RCU_PLLCFG_ST_Msk                     0x000000E0UL           /*!< Sggma-delta modulator mode */
#define RCU_PLLCFG_CP_Msk                     0x00000F00UL           /*!< Output current of current switch */
#define RCU_PLLCFG_PFD_Msk                    0x00003000UL           /*!< Mode of current switch */
#define RCU_PLLCFG_LPF_Msk                    0x0000C000UL           /*!< Loop filter band */
#define RCU_PLLCFG_VCOMODE_Msk                0x000F0000UL           /*!< Subband selection signal */
#define RCU_PLLCFG_VCOMA_Msk                  0x00100000UL           /*!< Ajust amplitude of GUN */
#define RCU_PLLCFG_VCOMF_Msk                  0x00200000UL           /*!< Ajust lower range of GUN */
#define RCU_PLLCFG_DLDMODE_Msk                0x00400000UL           /*!< Frequency detector delay */
#define RCU_PLLCFG_DT_Msk                     0x03000000UL           /*!< fractional noise randomization mode */
#define RCU_PLLCFG_MXEN_Msk                   0x10000000UL           /*!< Test mux enable */
#define RCU_PLLCFG_MX_Msk                     0xE0000000UL           /*!< Test mux signal select */

/*--  PLLDIV: PLL DIV Configuration Register ------------------------------------------------------------------*/
typedef struct {
  uint32_t DIV1A                  :3;                                /*!< Divider 1A */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t DIV1B                  :6;                                /*!< Divider 1B */
  uint32_t                        :2;                                /*!< RESERVED */
  uint32_t PREDIV                 :2;                                /*!< Predivisor coefficient */
  uint32_t NNCLR                  :1;                                /*!< N-divider enable */
  uint32_t RNCLR                  :1;                                /*!< R-divider enable */
  uint32_t RDIV                   :6;                                /*!< R-divider coefficient */
  uint32_t                        :2;                                /*!< RESERVED */
  uint32_t NDIV                   :8;                                /*!< Integer part of divider */
} _RCU_PLLDIV_bits;

/* Bit field positions: */
#define RCU_PLLDIV_DIV1A_Pos                  0                      /*!< Divider 1A */
#define RCU_PLLDIV_DIV1B_Pos                  4                      /*!< Divider 1B */
#define RCU_PLLDIV_PREDIV_Pos                 12                     /*!< Predivisor coefficient */
#define RCU_PLLDIV_NNCLR_Pos                  14                     /*!< N-divider enable */
#define RCU_PLLDIV_RNCLR_Pos                  15                     /*!< R-divider enable */
#define RCU_PLLDIV_RDIV_Pos                   16                     /*!< R-divider coefficient */
#define RCU_PLLDIV_NDIV_Pos                   24                     /*!< Integer part of divider */

/* Bit field masks: */
#define RCU_PLLDIV_DIV1A_Msk                  0x00000007UL           /*!< Divider 1A */
#define RCU_PLLDIV_DIV1B_Msk                  0x000003F0UL           /*!< Divider 1B */
#define RCU_PLLDIV_PREDIV_Msk                 0x00003000UL           /*!< Predivisor coefficient */
#define RCU_PLLDIV_NNCLR_Msk                  0x00004000UL           /*!< N-divider enable */
#define RCU_PLLDIV_RNCLR_Msk                  0x00008000UL           /*!< R-divider enable */
#define RCU_PLLDIV_RDIV_Msk                   0x003F0000UL           /*!< R-divider coefficient */
#define RCU_PLLDIV_NDIV_Msk                   0xFF000000UL           /*!< Integer part of divider */

/*--  PLLFRAC: PLL FRAC Configuration Register ----------------------------------------------------------------*/
typedef struct {
  uint32_t FRAC                   :24;                               /*!< numerator of fractional part */
} _RCU_PLLFRAC_bits;

/* Bit field positions: */
#define RCU_PLLFRAC_FRAC_Pos                  0                      /*!< numerator of fractional part */

/* Bit field masks: */
#define RCU_PLLFRAC_FRAC_Msk                  0x00FFFFFFUL           /*!< numerator of fractional part */

/*--  PLLMOD: PLL MOD Configuration Register ------------------------------------------------------------------*/
typedef struct {
  uint32_t MOD                    :24;                               /*!< denominator of fractional part */
} _RCU_PLLMOD_bits;

/* Bit field positions: */
#define RCU_PLLMOD_MOD_Pos                    0                      /*!< denominator of fractional part */

/* Bit field masks: */
#define RCU_PLLMOD_MOD_Msk                    0x00FFFFFFUL           /*!< denominator of fractional part */

/*--  UARTCFG: UART Clock and Reset Configuration Register ----------------------------------------------------*/
typedef struct {
  uint32_t CLKEN                  :1;                                /*!< Clock enable */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t RSTDIS                 :1;                                /*!< Reset disable */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t CLKSEL                 :2;                                /*!< Clock source select */
  uint32_t                        :2;                                /*!< RESERVED */
  uint32_t DIVEN                  :1;                                /*!< Enable divider */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t DIVN                   :6;                                /*!< Divider coefficient */
} _RCU_UARTCFG_bits;

/* Bit field positions: */
#define RCU_UARTCFG_CLKEN_Pos                 0                      /*!< Clock enable */
#define RCU_UARTCFG_RSTDIS_Pos                4                      /*!< Reset disable */
#define RCU_UARTCFG_CLKSEL_Pos                8                      /*!< Clock source select */
#define RCU_UARTCFG_DIVEN_Pos                 12                     /*!< Enable divider */
#define RCU_UARTCFG_DIVN_Pos                  16                     /*!< Divider coefficient */

/* Bit field masks: */
#define RCU_UARTCFG_CLKEN_Msk                 0x00000001UL           /*!< Clock enable */
#define RCU_UARTCFG_RSTDIS_Msk                0x00000010UL           /*!< Reset disable */
#define RCU_UARTCFG_CLKSEL_Msk                0x00000300UL           /*!< Clock source select */
#define RCU_UARTCFG_DIVEN_Msk                 0x00001000UL           /*!< Enable divider */
#define RCU_UARTCFG_DIVN_Msk                  0x003F0000UL           /*!< Divider coefficient */

/* Bit field enums: */
typedef enum {
  RCU_UARTCFG_CLKSEL_REFCLK                  = 0x0UL,                /*!< HSI 1MHz if CPE=0 or HSE(XTALL) if CPE=1 */
  RCU_UARTCFG_CLKSEL_SRCCLK                  = 0x1UL,                /*!< HSE(XTALL) if CPE=0 or HSI 1MHz if CPE=1 */
  RCU_UARTCFG_CLKSEL_PLLCLK                  = 0x2UL,                /*!< Clock from PLL OUT[0] */
  RCU_UARTCFG_CLKSEL_EXTCLK                  = 0x3UL,                /*!< external CLK from gpio pin */
} RCU_UARTCFG_CLKSEL_Enum;

/*--  SPICFG: SPI Clock and Reset Configuration Register ------------------------------------------------------*/
typedef struct {
  uint32_t CLKEN                  :1;                                /*!< Clock enable */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t RSTDIS                 :1;                                /*!< Reset disable */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t CLKSEL                 :2;                                /*!< Clock source select */
  uint32_t                        :2;                                /*!< RESERVED */
  uint32_t DIVEN                  :1;                                /*!< Enable divider */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t DIVN                   :6;                                /*!< Divider coefficient */
} _RCU_SPICFG_bits;

/* Bit field positions: */
#define RCU_SPICFG_CLKEN_Pos                  0                      /*!< Clock enable */
#define RCU_SPICFG_RSTDIS_Pos                 4                      /*!< Reset disable */
#define RCU_SPICFG_CLKSEL_Pos                 8                      /*!< Clock source select */
#define RCU_SPICFG_DIVEN_Pos                  12                     /*!< Enable divider */
#define RCU_SPICFG_DIVN_Pos                   16                     /*!< Divider coefficient */

/* Bit field masks: */
#define RCU_SPICFG_CLKEN_Msk                  0x00000001UL           /*!< Clock enable */
#define RCU_SPICFG_RSTDIS_Msk                 0x00000010UL           /*!< Reset disable */
#define RCU_SPICFG_CLKSEL_Msk                 0x00000300UL           /*!< Clock source select */
#define RCU_SPICFG_DIVEN_Msk                  0x00001000UL           /*!< Enable divider */
#define RCU_SPICFG_DIVN_Msk                   0x003F0000UL           /*!< Divider coefficient */

/* Bit field enums: */
typedef enum {
  RCU_SPICFG_CLKSEL_HSICLK                   = 0x0UL,                /*!< HSI 4MHz */
  RCU_SPICFG_CLKSEL_HSECLK                   = 0x1UL,                /*!< HSE(XTALL) */
  RCU_SPICFG_CLKSEL_PLLCLK                   = 0x2UL,                /*!< Clock from PLL OUT[0] */
  RCU_SPICFG_CLKSEL_EXTCLK                   = 0x3UL,                /*!< external CLK from gpio pin */
} RCU_SPICFG_CLKSEL_Enum;

/*--  ADCCFG: ADC Clock and Reset Configuration Register ------------------------------------------------------*/
typedef struct {
  uint32_t CLKEN                  :1;                                /*!< Clock enable */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t RSTDIS                 :1;                                /*!< Reset disable */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t CLKSEL                 :2;                                /*!< Clock source select */
  uint32_t                        :2;                                /*!< RESERVED */
  uint32_t DIVEN                  :1;                                /*!< Enable divider */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t DIVN                   :6;                                /*!< Divider coefficient */
} _RCU_ADCCFG_bits;

/* Bit field positions: */
#define RCU_ADCCFG_CLKEN_Pos                  0                      /*!< Clock enable */
#define RCU_ADCCFG_RSTDIS_Pos                 4                      /*!< Reset disable */
#define RCU_ADCCFG_CLKSEL_Pos                 8                      /*!< Clock source select */
#define RCU_ADCCFG_DIVEN_Pos                  12                     /*!< Enable divider */
#define RCU_ADCCFG_DIVN_Pos                   16                     /*!< Divider coefficient */

/* Bit field masks: */
#define RCU_ADCCFG_CLKEN_Msk                  0x00000001UL           /*!< Clock enable */
#define RCU_ADCCFG_RSTDIS_Msk                 0x00000010UL           /*!< Reset disable */
#define RCU_ADCCFG_CLKSEL_Msk                 0x00000300UL           /*!< Clock source select */
#define RCU_ADCCFG_DIVEN_Msk                  0x00001000UL           /*!< Enable divider */
#define RCU_ADCCFG_DIVN_Msk                   0x003F0000UL           /*!< Divider coefficient */

/* Bit field enums: */
typedef enum {
  RCU_ADCCFG_CLKSEL_HSICLK                   = 0x0UL,                /*!< HSI 1MHz  */
  RCU_ADCCFG_CLKSEL_HSECLK                   = 0x1UL,                /*!< HSE(XTALL)  */
  RCU_ADCCFG_CLKSEL_PLLCLK                   = 0x2UL,                /*!< Clock from PLL OUT[0] */
  RCU_ADCCFG_CLKSEL_EXTCLK                   = 0x3UL,                /*!< external CLK from gpio pin */
} RCU_ADCCFG_CLKSEL_Enum;

/*--  WDTCFG: WatchDog Configuration Register -----------------------------------------------------------------*/
typedef struct {
  uint32_t CLKEN                  :1;                                /*!< Clock enable */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t RSTDIS                 :1;                                /*!< Reset disable */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t CLKSEL                 :2;                                /*!< Clock source select */
  uint32_t                        :2;                                /*!< RESERVED */
  uint32_t DIVEN                  :1;                                /*!< Enable divider */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t DIVN                   :6;                                /*!< Divider coefficient */
} _RCU_WDTCFG_bits;

/* Bit field positions: */
#define RCU_WDTCFG_CLKEN_Pos                  0                      /*!< Clock enable */
#define RCU_WDTCFG_RSTDIS_Pos                 4                      /*!< Reset disable */
#define RCU_WDTCFG_CLKSEL_Pos                 8                      /*!< Clock source select */
#define RCU_WDTCFG_DIVEN_Pos                  12                     /*!< Enable divider */
#define RCU_WDTCFG_DIVN_Pos                   16                     /*!< Divider coefficient */

/* Bit field masks: */
#define RCU_WDTCFG_CLKEN_Msk                  0x00000001UL           /*!< Clock enable */
#define RCU_WDTCFG_RSTDIS_Msk                 0x00000010UL           /*!< Reset disable */
#define RCU_WDTCFG_CLKSEL_Msk                 0x00000300UL           /*!< Clock source select */
#define RCU_WDTCFG_DIVEN_Msk                  0x00001000UL           /*!< Enable divider */
#define RCU_WDTCFG_DIVN_Msk                   0x003F0000UL           /*!< Divider coefficient */

/* Bit field enums: */
typedef enum {
  RCU_WDTCFG_CLKSEL_HSICLK                   = 0x0UL,                /*!< HSI 4MHz  */
  RCU_WDTCFG_CLKSEL_HSECLK                   = 0x1UL,                /*!< HSE(XTALL)  */
  RCU_WDTCFG_CLKSEL_PLLCLK                   = 0x2UL,                /*!< Clock from PLL OUT[0] */
  RCU_WDTCFG_CLKSEL_EXTCLK                   = 0x3UL,                /*!< external CLK from gpio pin */
} RCU_WDTCFG_CLKSEL_Enum;

/*--  CLKOUTCFG: Clockout Configuration Register --------------------------------------------------------------*/
typedef struct {
  uint32_t CLKEN                  :1;                                /*!< Clock enable */
  uint32_t                        :7;                                /*!< RESERVED */
  uint32_t CLKSEL                 :2;                                /*!< Clock source select */
  uint32_t                        :2;                                /*!< RESERVED */
  uint32_t DIVEN                  :1;                                /*!< Enable divider */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t DIVN                   :16;                               /*!< Divider coefficient */
} _RCU_CLKOUTCFG_bits;

/* Bit field positions: */
#define RCU_CLKOUTCFG_CLKEN_Pos               0                      /*!< Clock enable */
#define RCU_CLKOUTCFG_CLKSEL_Pos              8                      /*!< Clock source select */
#define RCU_CLKOUTCFG_DIVEN_Pos               12                     /*!< Enable divider */
#define RCU_CLKOUTCFG_DIVN_Pos                16                     /*!< Divider coefficient */

/* Bit field masks: */
#define RCU_CLKOUTCFG_CLKEN_Msk               0x00000001UL           /*!< Clock enable */
#define RCU_CLKOUTCFG_CLKSEL_Msk              0x00000300UL           /*!< Clock source select */
#define RCU_CLKOUTCFG_DIVEN_Msk               0x00001000UL           /*!< Enable divider */
#define RCU_CLKOUTCFG_DIVN_Msk                0xFFFF0000UL           /*!< Divider coefficient */

/* Bit field enums: */
typedef enum {
  RCU_CLKOUTCFG_CLKSEL_HSICLK                = 0x0UL,                /*!< HSI 4MHz */
  RCU_CLKOUTCFG_CLKSEL_HSECLK                = 0x1UL,                /*!< HSE(XTALL) */
  RCU_CLKOUTCFG_CLKSEL_PLLCLK                = 0x2UL,                /*!< Clock from PLL OUT[0] */
  RCU_CLKOUTCFG_CLKSEL_RTCCLK                = 0x3UL,                /*!< RTCCLK */
} RCU_CLKOUTCFG_CLKSEL_Enum;

/*--  FLASHCFG: Flash Configuration Register ------------------------------------------------------------------*/
typedef struct {
  uint32_t CLKEN                  :1;                                /*!< Clock enable */
  uint32_t                        :7;                                /*!< RESERVED */
  uint32_t CLKSEL                 :1;                                /*!< Clock source select */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t DIVEN                  :1;                                /*!< Enable divider */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t DIVN                   :6;                                /*!< Divider coefficient */
} _RCU_FLASHCFG_bits;

/* Bit field positions: */
#define RCU_FLASHCFG_CLKEN_Pos                0                      /*!< Clock enable */
#define RCU_FLASHCFG_CLKSEL_Pos               8                      /*!< Clock source select */
#define RCU_FLASHCFG_DIVEN_Pos                12                     /*!< Enable divider */
#define RCU_FLASHCFG_DIVN_Pos                 16                     /*!< Divider coefficient */

/* Bit field masks: */
#define RCU_FLASHCFG_CLKEN_Msk                0x00000001UL           /*!< Clock enable */
#define RCU_FLASHCFG_CLKSEL_Msk               0x00000100UL           /*!< Clock source select */
#define RCU_FLASHCFG_DIVEN_Msk                0x00001000UL           /*!< Enable divider */
#define RCU_FLASHCFG_DIVN_Msk                 0x003F0000UL           /*!< Divider coefficient */

/* Bit field enums: */
typedef enum {
  RCU_FLASHCFG_CLKSEL_HSI                    = 0x0UL,                /*!< internal RC generator */
  RCU_FLASHCFG_CLKSEL_HSE                    = 0x1UL,                /*!< HSE(XTALL) */
} RCU_FLASHCFG_CLKSEL_Enum;

/*--  RTCCFG: RTC APB clock divider ---------------------------------------------------------------------------*/
typedef struct {
  uint32_t                        :4;                                /*!< RESERVED */
  uint32_t RST                    :1;                                /*!< Reset active High */
  uint32_t                        :7;                                /*!< RESERVED */
  uint32_t DIVEN                  :1;                                /*!< Enable divider */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t DIVN                   :6;                                /*!< Divider coefficient */
} _RCU_RTCCFG_bits;

/* Bit field positions: */
#define RCU_RTCCFG_RST_Pos                    4                      /*!< Reset active High */
#define RCU_RTCCFG_DIVEN_Pos                  12                     /*!< Enable divider */
#define RCU_RTCCFG_DIVN_Pos                   16                     /*!< Divider coefficient */

/* Bit field masks: */
#define RCU_RTCCFG_RST_Msk                    0x00000010UL           /*!< Reset active High */
#define RCU_RTCCFG_DIVEN_Msk                  0x00001000UL           /*!< Enable divider */
#define RCU_RTCCFG_DIVN_Msk                   0x003F0000UL           /*!< Divider coefficient */

/*--  BORCFG: BOR Configuration Register ----------------------------------------------------------------------*/
typedef struct {
  uint32_t EN                     :1;                                /*!< Enable BOR */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t TUNE                   :2;                                /*!< Tune BOR level */
} _RCU_BORCFG_bits;

/* Bit field positions: */
#define RCU_BORCFG_EN_Pos                     0                      /*!< Enable BOR */
#define RCU_BORCFG_TUNE_Pos                   4                      /*!< Tune BOR level */

/* Bit field masks: */
#define RCU_BORCFG_EN_Msk                     0x00000001UL           /*!< Enable BOR */
#define RCU_BORCFG_TUNE_Msk                   0x00000030UL           /*!< Tune BOR level */

/*--  HSECFG: HSE Configuration Register ----------------------------------------------------------------------*/
typedef struct {
  uint32_t EN                     :1;                                /*!< Enable HSE pins */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t DS                     :2;                                /*!< Drive current select pins */
} _RCU_HSECFG_bits;

/* Bit field positions: */
#define RCU_HSECFG_EN_Pos                     0                      /*!< Enable HSE pins */
#define RCU_HSECFG_DS_Pos                     4                      /*!< Drive current select pins */

/* Bit field masks: */
#define RCU_HSECFG_EN_Msk                     0x00000001UL           /*!< Enable HSE pins */
#define RCU_HSECFG_DS_Msk                     0x00000030UL           /*!< Drive current select pins */

/*--  INTEN: Interrupt enable reigster ------------------------------------------------------------------------*/
typedef struct {
  uint32_t PLLLOCK                :1;                                /*!< Enable PLL lock interrupt */
  uint32_t PLLFAIL                :1;                                /*!< Enable PLL fail to lock interrupt */
  uint32_t                        :7;                                /*!< RESERVED */
  uint32_t CLKGOOD1               :1;                                /*!<  */
  uint32_t CLKGOOD2               :1;                                /*!<  */
  uint32_t CLKGOOD3               :1;                                /*!<  */
  uint32_t                        :5;                                /*!< RESERVED */
  uint32_t CLKERR1                :1;                                /*!<  */
  uint32_t CLKERR2                :1;                                /*!<  */
  uint32_t CLKERR3                :1;                                /*!<  */
} _RCU_INTEN_bits;

/* Bit field positions: */
#define RCU_INTEN_PLLLOCK_Pos                 0                      /*!< Enable PLL lock interrupt */
#define RCU_INTEN_PLLFAIL_Pos                 1                      /*!< Enable PLL fail to lock interrupt */
#define RCU_INTEN_CLKGOOD1_Pos                9                      /*!<  */
#define RCU_INTEN_CLKGOOD2_Pos                10                     /*!<  */
#define RCU_INTEN_CLKGOOD3_Pos                11                     /*!<  */
#define RCU_INTEN_CLKERR1_Pos                 17                     /*!<  */
#define RCU_INTEN_CLKERR2_Pos                 18                     /*!<  */
#define RCU_INTEN_CLKERR3_Pos                 19                     /*!<  */

/* Bit field masks: */
#define RCU_INTEN_PLLLOCK_Msk                 0x00000001UL           /*!< Enable PLL lock interrupt */
#define RCU_INTEN_PLLFAIL_Msk                 0x00000002UL           /*!< Enable PLL fail to lock interrupt */
#define RCU_INTEN_CLKGOOD1_Msk                0x00000200UL           /*!<  */
#define RCU_INTEN_CLKGOOD2_Msk                0x00000400UL           /*!<  */
#define RCU_INTEN_CLKGOOD3_Msk                0x00000800UL           /*!<  */
#define RCU_INTEN_CLKERR1_Msk                 0x00020000UL           /*!<  */
#define RCU_INTEN_CLKERR2_Msk                 0x00040000UL           /*!<  */
#define RCU_INTEN_CLKERR3_Msk                 0x00080000UL           /*!<  */

/*--  INTSTAT: Interrupt status register ----------------------------------------------------------------------*/
typedef struct {
  uint32_t PLLLOCK                :1;                                /*!<  */
  uint32_t PLLFAIL                :1;                                /*!<  */
  uint32_t                        :7;                                /*!< RESERVED */
  uint32_t CLKGOOD1               :1;                                /*!<  */
  uint32_t CLKGOOD2               :1;                                /*!<  */
  uint32_t CLKGOOD3               :1;                                /*!<  */
  uint32_t                        :5;                                /*!< RESERVED */
  uint32_t CLKERR1                :1;                                /*!<  */
  uint32_t CLKERR2                :1;                                /*!<  */
  uint32_t CLKERR3                :1;                                /*!<  */
} _RCU_INTSTAT_bits;

/* Bit field positions: */
#define RCU_INTSTAT_PLLLOCK_Pos               0                      /*!<  */
#define RCU_INTSTAT_PLLFAIL_Pos               1                      /*!<  */
#define RCU_INTSTAT_CLKGOOD1_Pos              9                      /*!<  */
#define RCU_INTSTAT_CLKGOOD2_Pos              10                     /*!<  */
#define RCU_INTSTAT_CLKGOOD3_Pos              11                     /*!<  */
#define RCU_INTSTAT_CLKERR1_Pos               17                     /*!<  */
#define RCU_INTSTAT_CLKERR2_Pos               18                     /*!<  */
#define RCU_INTSTAT_CLKERR3_Pos               19                     /*!<  */

/* Bit field masks: */
#define RCU_INTSTAT_PLLLOCK_Msk               0x00000001UL           /*!<  */
#define RCU_INTSTAT_PLLFAIL_Msk               0x00000002UL           /*!<  */
#define RCU_INTSTAT_CLKGOOD1_Msk              0x00000200UL           /*!<  */
#define RCU_INTSTAT_CLKGOOD2_Msk              0x00000400UL           /*!<  */
#define RCU_INTSTAT_CLKGOOD3_Msk              0x00000800UL           /*!<  */
#define RCU_INTSTAT_CLKERR1_Msk               0x00020000UL           /*!<  */
#define RCU_INTSTAT_CLKERR2_Msk               0x00040000UL           /*!<  */
#define RCU_INTSTAT_CLKERR3_Msk               0x00080000UL           /*!<  */

//Cluster UARTCFG:
typedef struct {
  union {
  /*!< UART Clock and Reset Configuration Register */
    __IO uint32_t UARTCFG;                                           /*!< UARTCFG : type used for word access */
    __IO _RCU_UARTCFG_bits UARTCFG_bit;                              /*!< UARTCFG_bit: structure used for bit access */
  };
} _RCU_UARTCFG_TypeDef;
//Cluster SPICFG:
typedef struct {
  union {
  /*!< SPI Clock and Reset Configuration Register */
    __IO uint32_t SPICFG;                                            /*!< SPICFG : type used for word access */
    __IO _RCU_SPICFG_bits SPICFG_bit;                                /*!< SPICFG_bit: structure used for bit access */
  };
} _RCU_SPICFG_TypeDef;
typedef struct {
  union {                                                               /*!< Clockgate AHB configuration register */
    __IO uint32_t CGCFGAHB;                                           /*!< CGCFGAHB    : type used for word access */
    __IO _RCU_CGCFGAHB_bits  CGCFGAHB_bit;                           /*!< CGCFGAHB_bit: structure used for bit access */
  };
    __IO uint32_t Reserved0;
  union {                                                               /*!< Clockgate APB configuration register */
    __IO uint32_t CGCFGAPB;                                           /*!< CGCFGAPB    : type used for word access */
    __IO _RCU_CGCFGAPB_bits  CGCFGAPB_bit;                           /*!< CGCFGAPB_bit: structure used for bit access */
  };
    __IO uint32_t Reserved1;
  union {                                                               /*!< Reset disable AHB configuration register */
    __IO uint32_t RSTDISAHB;                                           /*!< RSTDISAHB    : type used for word access */
    __IO _RCU_RSTDISAHB_bits  RSTDISAHB_bit;                         /*!< RSTDISAHB_bit: structure used for bit access */
  };
    __IO uint32_t Reserved2;
  union {                                                               /*!< Reset disable APB register */
    __IO uint32_t RSTDISAPB;                                           /*!< RSTDISAPB    : type used for word access */
    __IO _RCU_RSTDISAPB_bits  RSTDISAPB_bit;                         /*!< RSTDISAPB_bit: structure used for bit access */
  };
    __IO uint32_t Reserved3;
  union {                                                               /*!< System clock configuration register */
    __IO uint32_t SYSCLKCFG;                                           /*!< SYSCLKCFG    : type used for word access */
    __IO _RCU_SYSCLKCFG_bits  SYSCLKCFG_bit;                         /*!< SYSCLKCFG_bit: structure used for bit access */
  };
  union {                                                               /*!< Security counter configuration 0 register */
    __IO uint32_t SECCNT0;                                           /*!< SECCNT0    : type used for word access */
    __IO _RCU_SECCNT0_bits  SECCNT0_bit;                             /*!< SECCNT0_bit: structure used for bit access */
  };
  union {                                                               /*!< Security counter configuration 1 register */
    __IO uint32_t SECCNT1;                                           /*!< SECCNT1    : type used for word access */
    __IO _RCU_SECCNT1_bits  SECCNT1_bit;                             /*!< SECCNT1_bit: structure used for bit access */
  };
  union {                                                               /*!< System clock status register */
    __I uint32_t CLKSTAT;                                            /*!< CLKSTAT    : type used for word access */
    __I _RCU_CLKSTAT_bits  CLKSTAT_bit;                              /*!< CLKSTAT_bit: structure used for bit access */
  };
  union {                                                               /*!< System Reset Register */
    __O uint32_t RSTSYS;                                             /*!< RSTSYS    : type used for word access */
    __O _RCU_RSTSYS_bits  RSTSYS_bit;                                /*!< RSTSYS_bit: structure used for bit access */
  };
  union {                                                               /*!< Reset Status Register */
    __IO uint32_t RSTSTAT;                                           /*!< RSTSTAT    : type used for word access */
    __IO _RCU_RSTSTAT_bits  RSTSTAT_bit;                             /*!< RSTSTAT_bit: structure used for bit access */
  };
    __IO uint32_t Reserved4[2];
  union {                                                               /*!< PLL Configuration Register */
    __IO uint32_t PLLCFG;                                            /*!< PLLCFG    : type used for word access */
    __IO _RCU_PLLCFG_bits  PLLCFG_bit;                               /*!< PLLCFG_bit: structure used for bit access */
  };
  union {                                                               /*!< PLL DIV Configuration Register */
    __IO uint32_t PLLDIV;                                            /*!< PLLDIV    : type used for word access */
    __IO _RCU_PLLDIV_bits  PLLDIV_bit;                               /*!< PLLDIV_bit: structure used for bit access */
  };
  union {                                                               /*!< PLL FRAC Configuration Register */
    __IO uint32_t PLLFRAC;                                           /*!< PLLFRAC    : type used for word access */
    __IO _RCU_PLLFRAC_bits  PLLFRAC_bit;                             /*!< PLLFRAC_bit: structure used for bit access */
  };
  union {                                                               /*!< PLL MOD Configuration Register */
    __IO uint32_t PLLMOD;                                            /*!< PLLMOD    : type used for word access */
    __IO _RCU_PLLMOD_bits  PLLMOD_bit;                               /*!< PLLMOD_bit: structure used for bit access */
  };
    __IO uint32_t Reserved5[4];
  _RCU_UARTCFG_TypeDef UARTCFG[2];
    __IO uint32_t Reserved6[6];
  _RCU_SPICFG_TypeDef SPICFG[2];
    __IO uint32_t Reserved7[2];
  union {                                                               /*!< ADC Clock and Reset Configuration Register */
    __IO uint32_t ADCCFG;                                            /*!< ADCCFG    : type used for word access */
    __IO _RCU_ADCCFG_bits  ADCCFG_bit;                               /*!< ADCCFG_bit: structure used for bit access */
  };
  union {                                                               /*!< WatchDog Configuration Register */
    __IO uint32_t WDTCFG;                                            /*!< WDTCFG    : type used for word access */
    __IO _RCU_WDTCFG_bits  WDTCFG_bit;                               /*!< WDTCFG_bit: structure used for bit access */
  };
  union {                                                               /*!< Clockout Configuration Register */
    __IO uint32_t CLKOUTCFG;                                           /*!< CLKOUTCFG    : type used for word access */
    __IO _RCU_CLKOUTCFG_bits  CLKOUTCFG_bit;                         /*!< CLKOUTCFG_bit: structure used for bit access */
  };
  union {                                                               /*!< Flash Configuration Register */
    __IO uint32_t FLASHCFG;                                           /*!< FLASHCFG    : type used for word access */
    __IO _RCU_FLASHCFG_bits  FLASHCFG_bit;                           /*!< FLASHCFG_bit: structure used for bit access */
  };
  union {                                                               /*!< RTC APB clock divider */
    __IO uint32_t RTCCFG;                                            /*!< RTCCFG    : type used for word access */
    __IO _RCU_RTCCFG_bits  RTCCFG_bit;                               /*!< RTCCFG_bit: structure used for bit access */
  };
  union {                                                               /*!< BOR Configuration Register */
    __IO uint32_t BORCFG;                                            /*!< BORCFG    : type used for word access */
    __IO _RCU_BORCFG_bits  BORCFG_bit;                               /*!< BORCFG_bit: structure used for bit access */
  };
  union {                                                               /*!< HSE Configuration Register */
    __IO uint32_t HSECFG;                                            /*!< HSECFG    : type used for word access */
    __IO _RCU_HSECFG_bits  HSECFG_bit;                               /*!< HSECFG_bit: structure used for bit access */
  };
    __IO uint32_t Reserved8[5];
  union {                                                               /*!< Interrupt enable reigster */
    __IO uint32_t INTEN;                                             /*!< INTEN    : type used for word access */
    __IO _RCU_INTEN_bits  INTEN_bit;                                 /*!< INTEN_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt status register */
    __O uint32_t INTSTAT;                                            /*!< INTSTAT    : type used for word access */
    __O _RCU_INTSTAT_bits  INTSTAT_bit;                              /*!< INTSTAT_bit: structure used for bit access */
  };
} RCU_TypeDef;


/******************************************************************************/
/*                         RTC registers                                      */
/******************************************************************************/

/*--  TIME: Time register -------------------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!<  */
} _RTC_TIME_bits;

/* Bit field positions: */
#define RTC_TIME_VAL_Pos                      0                      /*!<  */

/* Bit field masks: */
#define RTC_TIME_VAL_Msk                      0xFFFFFFFFUL           /*!<  */

/*--  ALARM1: Alarm 1 register --------------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!<  */
} _RTC_ALARM1_bits;

/* Bit field positions: */
#define RTC_ALARM1_VAL_Pos                    0                      /*!<  */

/* Bit field masks: */
#define RTC_ALARM1_VAL_Msk                    0xFFFFFFFFUL           /*!<  */

/*--  ALARM2: Alarm 2 register --------------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!<  */
} _RTC_ALARM2_bits;

/* Bit field positions: */
#define RTC_ALARM2_VAL_Pos                    0                      /*!<  */

/* Bit field masks: */
#define RTC_ALARM2_VAL_Msk                    0xFFFFFFFFUL           /*!<  */

/*--  CONTROL: Control register -------------------------------------------------------------------------------*/
typedef struct {
  uint32_t A1IE                   :1;                                /*!< ALARM1 = TIME interrupt enable */
  uint32_t A2IE                   :1;                                /*!< ALARM2 = TIME interrupt enable */
  uint32_t BIE                    :1;                                /*!< Switch to battery supply interrupt enable */
  uint32_t NPIE                   :1;                                /*!< Switch to normal power supply interrupt enable */
  uint32_t OIE                    :1;                                /*!< Timer overflow interrupt enable */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t DRC                    :1;                                /*!< Disable RC oscillator */
  uint32_t FCM                    :1;                                /*!< Use 32 kHz clock to time register increment */
} _RTC_CONTROL_bits;

/* Bit field positions: */
#define RTC_CONTROL_A1IE_Pos                  0                      /*!< ALARM1 = TIME interrupt enable */
#define RTC_CONTROL_A2IE_Pos                  1                      /*!< ALARM2 = TIME interrupt enable */
#define RTC_CONTROL_BIE_Pos                   2                      /*!< Switch to battery supply interrupt enable */
#define RTC_CONTROL_NPIE_Pos                  3                      /*!< Switch to normal power supply interrupt enable */
#define RTC_CONTROL_OIE_Pos                   4                      /*!< Timer overflow interrupt enable */
#define RTC_CONTROL_DRC_Pos                   8                      /*!< Disable RC oscillator */
#define RTC_CONTROL_FCM_Pos                   9                      /*!< Use 32 kHz clock to time register increment */

/* Bit field masks: */
#define RTC_CONTROL_A1IE_Msk                  0x00000001UL           /*!< ALARM1 = TIME interrupt enable */
#define RTC_CONTROL_A2IE_Msk                  0x00000002UL           /*!< ALARM2 = TIME interrupt enable */
#define RTC_CONTROL_BIE_Msk                   0x00000004UL           /*!< Switch to battery supply interrupt enable */
#define RTC_CONTROL_NPIE_Msk                  0x00000008UL           /*!< Switch to normal power supply interrupt enable */
#define RTC_CONTROL_OIE_Msk                   0x00000010UL           /*!< Timer overflow interrupt enable */
#define RTC_CONTROL_DRC_Msk                   0x00000100UL           /*!< Disable RC oscillator */
#define RTC_CONTROL_FCM_Msk                   0x00000200UL           /*!< Use 32 kHz clock to time register increment */

/* Bit field enums: */
typedef enum {
  RTC_CONTROL_FCM_NORMAL_MODE                = 0x0UL,                /*!< The time register is incremented each second */
  RTC_CONTROL_FCM_FAST_MODE                  = 0x1UL,                /*!< 32 kHz clock is used to increment the time register */
} RTC_CONTROL_FCM_Enum;

/*--  STATUS: Status register ---------------------------------------------------------------------------------*/
typedef struct {
  uint32_t A1F                    :1;                                /*!< ALARM1 = TIME front was detected */
  uint32_t A2F                    :1;                                /*!< ALARM2 = TIME front was detected */
  uint32_t BF                     :1;                                /*!< Switch to battery supply was detected */
  uint32_t NPF                    :1;                                /*!< Switch to normal power supply was detected */
  uint32_t OF                     :1;                                /*!< Timer overflow was detected */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t OSC_OK                 :1;                                /*!< RC oscillator state is ok */
  uint32_t                        :22;                               /*!< RESERVED */
  uint32_t BU                     :1;                                /*!< Battery supply is used status */
} _RTC_STATUS_bits;

/* Bit field positions: */
#define RTC_STATUS_A1F_Pos                    0                      /*!< ALARM1 = TIME front was detected */
#define RTC_STATUS_A2F_Pos                    1                      /*!< ALARM2 = TIME front was detected */
#define RTC_STATUS_BF_Pos                     2                      /*!< Switch to battery supply was detected */
#define RTC_STATUS_NPF_Pos                    3                      /*!< Switch to normal power supply was detected */
#define RTC_STATUS_OF_Pos                     4                      /*!< Timer overflow was detected */
#define RTC_STATUS_OSC_OK_Pos                 8                      /*!< RC oscillator state is ok */
#define RTC_STATUS_BU_Pos                     31                     /*!< Battery supply is used status */

/* Bit field masks: */
#define RTC_STATUS_A1F_Msk                    0x00000001UL           /*!< ALARM1 = TIME front was detected */
#define RTC_STATUS_A2F_Msk                    0x00000002UL           /*!< ALARM2 = TIME front was detected */
#define RTC_STATUS_BF_Msk                     0x00000004UL           /*!< Switch to battery supply was detected */
#define RTC_STATUS_NPF_Msk                    0x00000008UL           /*!< Switch to normal power supply was detected */
#define RTC_STATUS_OF_Msk                     0x00000010UL           /*!< Timer overflow was detected */
#define RTC_STATUS_OSC_OK_Msk                 0x00000100UL           /*!< RC oscillator state is ok */
#define RTC_STATUS_BU_Msk                     0x80000000UL           /*!< Battery supply is used status */

/*--  TRIM_RC: RC oscillator trim register --------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :7;                                /*!<  */
  uint32_t SIGN                   :1;                                /*!<  */
} _RTC_TRIM_RC_bits;

/* Bit field positions: */
#define RTC_TRIM_RC_VAL_Pos                   0                      /*!<  */
#define RTC_TRIM_RC_SIGN_Pos                  7                      /*!<  */

/* Bit field masks: */
#define RTC_TRIM_RC_VAL_Msk                   0x0000007FUL           /*!<  */
#define RTC_TRIM_RC_SIGN_Msk                  0x00000080UL           /*!<  */

/*--  TRIM_CLK1S: Clock 1s trim register ----------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :10;                               /*!<  */
  uint32_t SIGN                   :1;                                /*!<  */
} _RTC_TRIM_CLK1S_bits;

/* Bit field positions: */
#define RTC_TRIM_CLK1S_VAL_Pos                0                      /*!<  */
#define RTC_TRIM_CLK1S_SIGN_Pos               10                     /*!<  */

/* Bit field masks: */
#define RTC_TRIM_CLK1S_VAL_Msk                0x000003FFUL           /*!<  */
#define RTC_TRIM_CLK1S_SIGN_Msk               0x00000400UL           /*!<  */

/*--  GPR: General purpose register ---------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!<  */
} _RTC_GPR_bits;

/* Bit field positions: */
#define RTC_GPR_VAL_Pos                       0                      /*!<  */

/* Bit field masks: */
#define RTC_GPR_VAL_Msk                       0xFFFFFFFFUL           /*!<  */

//Cluster GPR:
typedef struct {
  union {
  /*!< General purpose register */
    __IO uint32_t GPR;                                               /*!< GPR : type used for word access */
    __IO _RTC_GPR_bits GPR_bit;                                      /*!< GPR_bit: structure used for bit access */
  };
} _RTC_GPR_TypeDef;
typedef struct {
  union {                                                               /*!< Time register */
    __IO uint32_t TIME;                                              /*!< TIME    : type used for word access */
    __IO _RTC_TIME_bits  TIME_bit;                                   /*!< TIME_bit: structure used for bit access */
  };
  union {                                                               /*!< Alarm 1 register */
    __IO uint32_t ALARM1;                                            /*!< ALARM1    : type used for word access */
    __IO _RTC_ALARM1_bits  ALARM1_bit;                               /*!< ALARM1_bit: structure used for bit access */
  };
  union {                                                               /*!< Alarm 2 register */
    __IO uint32_t ALARM2;                                            /*!< ALARM2    : type used for word access */
    __IO _RTC_ALARM2_bits  ALARM2_bit;                               /*!< ALARM2_bit: structure used for bit access */
  };
  union {                                                               /*!< Control register */
    __IO uint32_t CONTROL;                                           /*!< CONTROL    : type used for word access */
    __IO _RTC_CONTROL_bits  CONTROL_bit;                             /*!< CONTROL_bit: structure used for bit access */
  };
  union {                                                               /*!< Status register */
    __IO uint32_t STATUS;                                            /*!< STATUS    : type used for word access */
    __IO _RTC_STATUS_bits  STATUS_bit;                               /*!< STATUS_bit: structure used for bit access */
  };
  union {                                                               /*!< RC oscillator trim register */
    __IO uint32_t TRIM_RC;                                           /*!< TRIM_RC    : type used for word access */
    __IO _RTC_TRIM_RC_bits  TRIM_RC_bit;                             /*!< TRIM_RC_bit: structure used for bit access */
  };
  union {                                                               /*!< Clock 1s trim register */
    __IO uint32_t TRIM_CLK1S;                                           /*!< TRIM_CLK1S    : type used for word access */
    __IO _RTC_TRIM_CLK1S_bits  TRIM_CLK1S_bit;                       /*!< TRIM_CLK1S_bit: structure used for bit access */
  };
    __IO uint32_t Reserved0;
  _RTC_GPR_TypeDef GPR[16];
} RTC_TypeDef;


/******************************************************************************/
/*                         SIU registers                                      */
/******************************************************************************/

/*--  CHIPID: Chip identifier ---------------------------------------------------------------------------------*/
typedef struct {
  uint32_t REV                    :4;                                /*!< Revision number */
  uint32_t ID                     :28;                               /*!< Model ID */
} _SIU_CHIPID_bits;

/* Bit field positions: */
#define SIU_CHIPID_REV_Pos                    0                      /*!< Revision number */
#define SIU_CHIPID_ID_Pos                     4                      /*!< Model ID */

/* Bit field masks: */
#define SIU_CHIPID_REV_Msk                    0x0000000FUL           /*!< Revision number */
#define SIU_CHIPID_ID_Msk                     0xFFFFFFF0UL           /*!< Model ID */

/*--  SERVCTL: Service mode Register --------------------------------------------------------------------------*/
typedef struct {
  uint32_t SERVSTAT               :1;                                /*!< Service mode status */
  uint32_t                        :7;                                /*!< RESERVED */
  uint32_t SERVCMD                :1;                                /*!< Service mode erase comand/status */
} _SIU_SERVCTL_bits;

/* Bit field positions: */
#define SIU_SERVCTL_SERVSTAT_Pos              0                      /*!< Service mode status */
#define SIU_SERVCTL_SERVCMD_Pos               8                      /*!< Service mode erase comand/status */

/* Bit field masks: */
#define SIU_SERVCTL_SERVSTAT_Msk              0x00000001UL           /*!< Service mode status */
#define SIU_SERVCTL_SERVCMD_Msk               0x00000100UL           /*!< Service mode erase comand/status */

/*--  SYNC: Sync PWM/CAP register -----------------------------------------------------------------------------*/
typedef struct {
  uint32_t SWSYNC                 :1;                                /*!< SYNCI pulse software emulation  on PWM0 */
  uint32_t                        :7;                                /*!< RESERVED */
  uint32_t CAPSYNCSEL1            :1;                                /*!< CAP sync scheme control */
  uint32_t CAPSYNCSEL2            :1;                                /*!< CAP sync scheme control */
  uint32_t                        :6;                                /*!< RESERVED */
  uint32_t PWMSYNCSEL1            :1;                                /*!< PWM sync scheme control */
  uint32_t PWMSYNCSEL2            :1;                                /*!< PWM sync scheme control */
} _SIU_SYNC_bits;

/* Bit field positions: */
#define SIU_SYNC_SWSYNC_Pos                   0                      /*!< SYNCI pulse software emulation  on PWM0 */
#define SIU_SYNC_CAPSYNCSEL1_Pos              8                      /*!< CAP sync scheme control */
#define SIU_SYNC_CAPSYNCSEL2_Pos              9                      /*!< CAP sync scheme control */
#define SIU_SYNC_PWMSYNCSEL1_Pos              16                     /*!< PWM sync scheme control */
#define SIU_SYNC_PWMSYNCSEL2_Pos              17                     /*!< PWM sync scheme control */

/* Bit field masks: */
#define SIU_SYNC_SWSYNC_Msk                   0x00000001UL           /*!< SYNCI pulse software emulation  on PWM0 */
#define SIU_SYNC_CAPSYNCSEL1_Msk              0x00000100UL           /*!< CAP sync scheme control */
#define SIU_SYNC_CAPSYNCSEL2_Msk              0x00000200UL           /*!< CAP sync scheme control */
#define SIU_SYNC_PWMSYNCSEL1_Msk              0x00010000UL           /*!< PWM sync scheme control */
#define SIU_SYNC_PWMSYNCSEL2_Msk              0x00020000UL           /*!< PWM sync scheme control */

/*--  CNTEN: PWM/TMR count enable register enable register ----------------------------------------------------*/
typedef struct {
  uint32_t PWM0EN                 :1;                                /*!< Enable count for PWM 0 */
  uint32_t PWM1EN                 :1;                                /*!< Enable count for PWM 1 */
  uint32_t PWM2EN                 :1;                                /*!< Enable count for PWM 2 */
  uint32_t                        :13;                               /*!< RESERVED */
  uint32_t TMR0EN                 :1;                                /*!< Enable count for TMR 0 */
  uint32_t TMR1EN                 :1;                                /*!< Enable count for TMR 1 */
  uint32_t TMR2EN                 :1;                                /*!< Enable count for timer 2 */
  uint32_t TMR3EN                 :1;                                /*!< Enable count for timer 3 */
} _SIU_CNTEN_bits;

/* Bit field positions: */
#define SIU_CNTEN_PWM0EN_Pos                  0                      /*!< Enable count for PWM 0 */
#define SIU_CNTEN_PWM1EN_Pos                  1                      /*!< Enable count for PWM 1 */
#define SIU_CNTEN_PWM2EN_Pos                  2                      /*!< Enable count for PWM 2 */
#define SIU_CNTEN_TMR0EN_Pos                  16                     /*!< Enable count for TMR 0 */
#define SIU_CNTEN_TMR1EN_Pos                  17                     /*!< Enable count for TMR 1 */
#define SIU_CNTEN_TMR2EN_Pos                  18                     /*!< Enable count for timer 2 */
#define SIU_CNTEN_TMR3EN_Pos                  19                     /*!< Enable count for timer 3 */

/* Bit field masks: */
#define SIU_CNTEN_PWM0EN_Msk                  0x00000001UL           /*!< Enable count for PWM 0 */
#define SIU_CNTEN_PWM1EN_Msk                  0x00000002UL           /*!< Enable count for PWM 1 */
#define SIU_CNTEN_PWM2EN_Msk                  0x00000004UL           /*!< Enable count for PWM 2 */
#define SIU_CNTEN_TMR0EN_Msk                  0x00010000UL           /*!< Enable count for TMR 0 */
#define SIU_CNTEN_TMR1EN_Msk                  0x00020000UL           /*!< Enable count for TMR 1 */
#define SIU_CNTEN_TMR2EN_Msk                  0x00040000UL           /*!< Enable count for timer 2 */
#define SIU_CNTEN_TMR3EN_Msk                  0x00080000UL           /*!< Enable count for timer 3 */

/*--  TMRCFG: TMR external clock config -----------------------------------------------------------------------*/
typedef struct {
  uint32_t TMR0CLKMUX             :1;                                /*!< Select ecternal clock source */
  uint32_t TMR1CLKMUX             :1;                                /*!< Select ecternal clock source */
  uint32_t TMR2CLKMUX             :1;                                /*!< Select ecternal clock source */
  uint32_t TMR3CLKMUX             :1;                                /*!< Select ecternal clock source */
} _SIU_TMRCFG_bits;

/* Bit field positions: */
#define SIU_TMRCFG_TMR0CLKMUX_Pos             0                      /*!< Select ecternal clock source */
#define SIU_TMRCFG_TMR1CLKMUX_Pos             1                      /*!< Select ecternal clock source */
#define SIU_TMRCFG_TMR2CLKMUX_Pos             2                      /*!< Select ecternal clock source */
#define SIU_TMRCFG_TMR3CLKMUX_Pos             3                      /*!< Select ecternal clock source */

/* Bit field masks: */
#define SIU_TMRCFG_TMR0CLKMUX_Msk             0x00000001UL           /*!< Select ecternal clock source */
#define SIU_TMRCFG_TMR1CLKMUX_Msk             0x00000002UL           /*!< Select ecternal clock source */
#define SIU_TMRCFG_TMR2CLKMUX_Msk             0x00000004UL           /*!< Select ecternal clock source */
#define SIU_TMRCFG_TMR3CLKMUX_Msk             0x00000008UL           /*!< Select ecternal clock source */

/* Bit field enums: */
typedef enum {
  SIU_TMRCFG_TMR0CLKMUX_EXTPIN               = 0x0UL,                /*!< external controler pin */
  SIU_TMRCFG_TMR0CLKMUX_PRETIMER             = 0x1UL,                /*!< previous timer PWM-output */
} SIU_TMRCFG_TMR0CLKMUX_Enum;

typedef enum {
  SIU_TMRCFG_TMR1CLKMUX_EXTPIN               = 0x0UL,                /*!< external controler pin */
  SIU_TMRCFG_TMR1CLKMUX_PRETIMER             = 0x1UL,                /*!< previous timer PWM-output */
} SIU_TMRCFG_TMR1CLKMUX_Enum;

typedef enum {
  SIU_TMRCFG_TMR2CLKMUX_EXTPIN               = 0x0UL,                /*!< external controler pin */
  SIU_TMRCFG_TMR2CLKMUX_PRETIMER             = 0x1UL,                /*!< previous timer PWM-output */
} SIU_TMRCFG_TMR2CLKMUX_Enum;

typedef enum {
  SIU_TMRCFG_TMR3CLKMUX_EXTPIN               = 0x0UL,                /*!< external controler pin */
  SIU_TMRCFG_TMR3CLKMUX_PRETIMER             = 0x1UL,                /*!< previous timer PWM-output */
} SIU_TMRCFG_TMR3CLKMUX_Enum;

/*--  CAPMUX: CAP input mux control register ------------------------------------------------------------------*/
typedef struct {
  uint32_t CAPINSEL0              :2;                                /*!< Select input source for CAP0 */
  uint32_t CAPINSEL1              :2;                                /*!< Select input source for CAP1 */
  uint32_t CAPINSEL2              :2;                                /*!< Select input source for CAP2 */
} _SIU_CAPMUX_bits;

/* Bit field positions: */
#define SIU_CAPMUX_CAPINSEL0_Pos              0                      /*!< Select input source for CAP0 */
#define SIU_CAPMUX_CAPINSEL1_Pos              2                      /*!< Select input source for CAP1 */
#define SIU_CAPMUX_CAPINSEL2_Pos              4                      /*!< Select input source for CAP2 */

/* Bit field masks: */
#define SIU_CAPMUX_CAPINSEL0_Msk              0x00000003UL           /*!< Select input source for CAP0 */
#define SIU_CAPMUX_CAPINSEL1_Msk              0x0000000CUL           /*!< Select input source for CAP1 */
#define SIU_CAPMUX_CAPINSEL2_Msk              0x00000030UL           /*!< Select input source for CAP2 */

/* Bit field enums: */
typedef enum {
  SIU_CAPMUX_CAPINSEL0_CAP0                  = 0x0UL,                /*!< default CAP0 input */
  SIU_CAPMUX_CAPINSEL0_QEPA                  = 0x1UL,                /*!< QEP A input */
  SIU_CAPMUX_CAPINSEL0_QEPB                  = 0x2UL,                /*!< QEP B input */
  SIU_CAPMUX_CAPINSEL0_QEPI                  = 0x3UL,                /*!< QEP I input */
} SIU_CAPMUX_CAPINSEL0_Enum;

typedef enum {
  SIU_CAPMUX_CAPINSEL1_CAP1                  = 0x0UL,                /*!< default CAP1 input */
  SIU_CAPMUX_CAPINSEL1_QEPA                  = 0x1UL,                /*!< QEP A input */
  SIU_CAPMUX_CAPINSEL1_QEPB                  = 0x2UL,                /*!< QEP B input */
  SIU_CAPMUX_CAPINSEL1_QEPI                  = 0x3UL,                /*!< QEP I input */
} SIU_CAPMUX_CAPINSEL1_Enum;

typedef enum {
  SIU_CAPMUX_CAPINSEL2_CAP2                  = 0x0UL,                /*!< default CAP2 input */
  SIU_CAPMUX_CAPINSEL2_QEPA                  = 0x1UL,                /*!< QEP A input */
  SIU_CAPMUX_CAPINSEL2_QEPB                  = 0x2UL,                /*!< QEP B input */
  SIU_CAPMUX_CAPINSEL2_QEPI                  = 0x3UL,                /*!< QEP I input */
} SIU_CAPMUX_CAPINSEL2_Enum;

/*--  QUALCTL: QEP and ECAP qualifier control register --------------------------------------------------------*/
typedef struct {
  uint32_t CAPEN0                 :1;                                /*!< Enable qualifier for CAP0 */
  uint32_t CAPEN1                 :1;                                /*!< Enable qualifier for CAP1 */
  uint32_t CAPEN2                 :1;                                /*!< Enable qualifier for CAP2 */
  uint32_t                        :5;                                /*!< RESERVED */
  uint32_t CAPMODE0               :1;                                /*!< Select mode of qualifier for CAP0 */
  uint32_t CAPMODE1               :1;                                /*!< Select mode of qualifier for CAP1 */
  uint32_t CAPMODE2               :1;                                /*!< Select mode of qualifier for CAP2 */
  uint32_t                        :5;                                /*!< RESERVED */
  uint32_t QEPEN                  :1;                                /*!< Enable qualifier for QEP0 */
  uint32_t                        :7;                                /*!< RESERVED */
  uint32_t QEPMODE                :1;                                /*!< Select mode of qualifier for QEP0 */
} _SIU_QUALCTL_bits;

/* Bit field positions: */
#define SIU_QUALCTL_CAPEN0_Pos                0                      /*!< Enable qualifier for CAP0 */
#define SIU_QUALCTL_CAPEN1_Pos                1                      /*!< Enable qualifier for CAP1 */
#define SIU_QUALCTL_CAPEN2_Pos                2                      /*!< Enable qualifier for CAP2 */
#define SIU_QUALCTL_CAPMODE0_Pos              8                      /*!< Select mode of qualifier for CAP0 */
#define SIU_QUALCTL_CAPMODE1_Pos              9                      /*!< Select mode of qualifier for CAP1 */
#define SIU_QUALCTL_CAPMODE2_Pos              10                     /*!< Select mode of qualifier for CAP2 */
#define SIU_QUALCTL_QEPEN_Pos                 16                     /*!< Enable qualifier for QEP0 */
#define SIU_QUALCTL_QEPMODE_Pos               24                     /*!< Select mode of qualifier for QEP0 */

/* Bit field masks: */
#define SIU_QUALCTL_CAPEN0_Msk                0x00000001UL           /*!< Enable qualifier for CAP0 */
#define SIU_QUALCTL_CAPEN1_Msk                0x00000002UL           /*!< Enable qualifier for CAP1 */
#define SIU_QUALCTL_CAPEN2_Msk                0x00000004UL           /*!< Enable qualifier for CAP2 */
#define SIU_QUALCTL_CAPMODE0_Msk              0x00000100UL           /*!< Select mode of qualifier for CAP0 */
#define SIU_QUALCTL_CAPMODE1_Msk              0x00000200UL           /*!< Select mode of qualifier for CAP1 */
#define SIU_QUALCTL_CAPMODE2_Msk              0x00000400UL           /*!< Select mode of qualifier for CAP2 */
#define SIU_QUALCTL_QEPEN_Msk                 0x00010000UL           /*!< Enable qualifier for QEP0 */
#define SIU_QUALCTL_QEPMODE_Msk               0x01000000UL           /*!< Select mode of qualifier for QEP0 */

/*--  QUALSAMPLE: QEP and CAP qualifier sample period set register --------------------------------------------*/
typedef struct {
  uint32_t CAPVAL                 :16;                               /*!< Set sample period of qualifer for all CAPs */
  uint32_t QEPVAL                 :16;                               /*!< Set sample period of qualifer for all QEPs */
} _SIU_QUALSAMPLE_bits;

/* Bit field positions: */
#define SIU_QUALSAMPLE_CAPVAL_Pos             0                      /*!< Set sample period of qualifer for all CAPs */
#define SIU_QUALSAMPLE_QEPVAL_Pos             16                     /*!< Set sample period of qualifer for all QEPs */

/* Bit field masks: */
#define SIU_QUALSAMPLE_CAPVAL_Msk             0x0000FFFFUL           /*!< Set sample period of qualifer for all CAPs */
#define SIU_QUALSAMPLE_QEPVAL_Msk             0xFFFF0000UL           /*!< Set sample period of qualifer for all QEPs */

/*--  RCCTRL: RC generator control register -------------------------------------------------------------------*/
typedef struct {
  uint32_t TUNE                   :8;                                /*!< Tune RC generator period */
  uint32_t EN                     :1;                                /*!< Internal oscillator enable */
} _SIU_RCCTRL_bits;

/* Bit field positions: */
#define SIU_RCCTRL_TUNE_Pos                   0                      /*!< Tune RC generator period */
#define SIU_RCCTRL_EN_Pos                     8                      /*!< Internal oscillator enable */

/* Bit field masks: */
#define SIU_RCCTRL_TUNE_Msk                   0x000000FFUL           /*!< Tune RC generator period */
#define SIU_RCCTRL_EN_Msk                     0x00000100UL           /*!< Internal oscillator enable */

/*--  LDOCTRL: LDO control register ---------------------------------------------------------------------------*/
typedef struct {
  uint32_t TUNE                   :4;                                /*!< Tune LDO output voltage */
  uint32_t                        :4;                                /*!< RESERVED */
  uint32_t DISOSC                 :1;                                /*!< Disable 100kHz oscillator */
} _SIU_LDOCTRL_bits;

/* Bit field positions: */
#define SIU_LDOCTRL_TUNE_Pos                  0                      /*!< Tune LDO output voltage */
#define SIU_LDOCTRL_DISOSC_Pos                8                      /*!< Disable 100kHz oscillator */

/* Bit field masks: */
#define SIU_LDOCTRL_TUNE_Msk                  0x0000000FUL           /*!< Tune LDO output voltage */
#define SIU_LDOCTRL_DISOSC_Msk                0x00000100UL           /*!< Disable 100kHz oscillator */

/* Bit field enums: */
typedef enum {
  SIU_LDOCTRL_DISOSC_ENABLEOSC               = 0x0UL,                /*!< Enable 100kHz oscillator */
  SIU_LDOCTRL_DISOSC_DISABLEOSC              = 0x1UL,                /*!< Disable 100kHz oscillator */
} SIU_LDOCTRL_DISOSC_Enum;

/*--  CPESTAT: CPE status register ----------------------------------------------------------------------------*/
typedef struct {
  uint32_t CPE                    :1;                                /*!< CPE status */
} _SIU_CPESTAT_bits;

/* Bit field positions: */
#define SIU_CPESTAT_CPE_Pos                   0                      /*!< CPE status */

/* Bit field masks: */
#define SIU_CPESTAT_CPE_Msk                   0x00000001UL           /*!< CPE status */

/*--  TSENSCTRL: T-sensor control register --------------------------------------------------------------------*/
typedef struct {
  uint32_t DIS                    :1;                                /*!< Disable tsensor */
  uint32_t SCALE                  :1;                                /*!< Sensor type */
} _SIU_TSENSCTRL_bits;

/* Bit field positions: */
#define SIU_TSENSCTRL_DIS_Pos                 0                      /*!< Disable tsensor */
#define SIU_TSENSCTRL_SCALE_Pos               1                      /*!< Sensor type */

/* Bit field masks: */
#define SIU_TSENSCTRL_DIS_Msk                 0x00000001UL           /*!< Disable tsensor */
#define SIU_TSENSCTRL_SCALE_Msk               0x00000002UL           /*!< Sensor type */

/*--  BGPCTRL: Bandgap control register -----------------------------------------------------------------------*/
typedef struct {
  uint32_t TUNE                   :12;                               /*!< Tune bandgap voltage */
  uint32_t                        :4;                                /*!< RESERVED */
  uint32_t EN                     :1;                                /*!< Internal oscillator enable */
} _SIU_BGPCTRL_bits;

/* Bit field positions: */
#define SIU_BGPCTRL_TUNE_Pos                  0                      /*!< Tune bandgap voltage */
#define SIU_BGPCTRL_EN_Pos                    16                     /*!< Internal oscillator enable */

/* Bit field masks: */
#define SIU_BGPCTRL_TUNE_Msk                  0x00000FFFUL           /*!< Tune bandgap voltage */
#define SIU_BGPCTRL_EN_Msk                    0x00010000UL           /*!< Internal oscillator enable */

/*--  BOOTSELSTAT: BOOTSEL status register --------------------------------------------------------------------*/
typedef struct {
  uint32_t BOOTSEL                :1;                                /*!< BOOTSEL status */
} _SIU_BOOTSELSTAT_bits;

/* Bit field positions: */
#define SIU_BOOTSELSTAT_BOOTSEL_Pos           0                      /*!< BOOTSEL status */

/* Bit field masks: */
#define SIU_BOOTSELSTAT_BOOTSEL_Msk           0x00000001UL           /*!< BOOTSEL status */

/*--  RAMCTRL: SRAM control register --------------------------------------------------------------------------*/
typedef struct {
  uint32_t RMEN                   :1;                                /*!< Enable to use Read-Write Margin */
  uint32_t RM                     :2;                                /*!< Read-Write Margin value */
  uint32_t                        :5;                                /*!< RESERVED */
  uint32_t LS0                    :1;                                /*!< Ligth Sleep RAM part 0 (0..16k) */
} _SIU_RAMCTRL_bits;

/* Bit field positions: */
#define SIU_RAMCTRL_RMEN_Pos                  0                      /*!< Enable to use Read-Write Margin */
#define SIU_RAMCTRL_RM_Pos                    1                      /*!< Read-Write Margin value */
#define SIU_RAMCTRL_LS0_Pos                   8                      /*!< Ligth Sleep RAM part 0 (0..16k) */

/* Bit field masks: */
#define SIU_RAMCTRL_RMEN_Msk                  0x00000001UL           /*!< Enable to use Read-Write Margin */
#define SIU_RAMCTRL_RM_Msk                    0x00000006UL           /*!< Read-Write Margin value */
#define SIU_RAMCTRL_LS0_Msk                   0x00000100UL           /*!< Ligth Sleep RAM part 0 (0..16k) */

/*--  TCMCTRL: Core Tightly-Coupled Memory SRAM control -------------------------------------------------------*/
typedef struct {
  uint32_t RMEN                   :1;                                /*!< Enable to use Read-Write Margin */
  uint32_t RM                     :2;                                /*!< Read-Write Margin value */
  uint32_t                        :5;                                /*!< RESERVED */
  uint32_t LS0                    :1;                                /*!< Ligth Sleep TCM RAM part 0 (0..8k) */
  uint32_t LS1                    :1;                                /*!< Ligth Sleep TCM RAM part 1 (8k..16k) */
  uint32_t LS2                    :1;                                /*!< Ligth Sleep TCM RAM part 2 (16..24k) */
  uint32_t LS3                    :1;                                /*!< Ligth Sleep TCM RAM part 3 (24k..32k) */
} _SIU_TCMCTRL_bits;

/* Bit field positions: */
#define SIU_TCMCTRL_RMEN_Pos                  0                      /*!< Enable to use Read-Write Margin */
#define SIU_TCMCTRL_RM_Pos                    1                      /*!< Read-Write Margin value */
#define SIU_TCMCTRL_LS0_Pos                   8                      /*!< Ligth Sleep TCM RAM part 0 (0..8k) */
#define SIU_TCMCTRL_LS1_Pos                   9                      /*!< Ligth Sleep TCM RAM part 1 (8k..16k) */
#define SIU_TCMCTRL_LS2_Pos                   10                     /*!< Ligth Sleep TCM RAM part 2 (16..24k) */
#define SIU_TCMCTRL_LS3_Pos                   11                     /*!< Ligth Sleep TCM RAM part 3 (24k..32k) */

/* Bit field masks: */
#define SIU_TCMCTRL_RMEN_Msk                  0x00000001UL           /*!< Enable to use Read-Write Margin */
#define SIU_TCMCTRL_RM_Msk                    0x00000006UL           /*!< Read-Write Margin value */
#define SIU_TCMCTRL_LS0_Msk                   0x00000100UL           /*!< Ligth Sleep TCM RAM part 0 (0..8k) */
#define SIU_TCMCTRL_LS1_Msk                   0x00000200UL           /*!< Ligth Sleep TCM RAM part 1 (8k..16k) */
#define SIU_TCMCTRL_LS2_Msk                   0x00000400UL           /*!< Ligth Sleep TCM RAM part 2 (16..24k) */
#define SIU_TCMCTRL_LS3_Msk                   0x00000800UL           /*!< Ligth Sleep TCM RAM part 3 (24k..32k) */

/*--  CRAMCTRL: Core Cache SRAM control -----------------------------------------------------------------------*/
typedef struct {
  uint32_t RMEN                   :1;                                /*!< Enable to use Read-Write Margin */
  uint32_t RM                     :2;                                /*!< Read-Write Margin value */
  uint32_t                        :5;                                /*!< RESERVED */
  uint32_t L1ILS                  :1;                                /*!< Ligth Sleep L1 Instruction cache RAM */
  uint32_t L1DLS                  :1;                                /*!< Ligth Sleep L1 Data cache RAM */
} _SIU_CRAMCTRL_bits;

/* Bit field positions: */
#define SIU_CRAMCTRL_RMEN_Pos                 0                      /*!< Enable to use Read-Write Margin */
#define SIU_CRAMCTRL_RM_Pos                   1                      /*!< Read-Write Margin value */
#define SIU_CRAMCTRL_L1ILS_Pos                8                      /*!< Ligth Sleep L1 Instruction cache RAM */
#define SIU_CRAMCTRL_L1DLS_Pos                9                      /*!< Ligth Sleep L1 Data cache RAM */

/* Bit field masks: */
#define SIU_CRAMCTRL_RMEN_Msk                 0x00000001UL           /*!< Enable to use Read-Write Margin */
#define SIU_CRAMCTRL_RM_Msk                   0x00000006UL           /*!< Read-Write Margin value */
#define SIU_CRAMCTRL_L1ILS_Msk                0x00000100UL           /*!< Ligth Sleep L1 Instruction cache RAM */
#define SIU_CRAMCTRL_L1DLS_Msk                0x00000200UL           /*!< Ligth Sleep L1 Data cache RAM */

/*--  CANRAMCTRL: CAN SRAM control ----------------------------------------------------------------------------*/
typedef struct {
  uint32_t RMEN                   :1;                                /*!< Enable to use Read-Write Margin */
  uint32_t RM                     :2;                                /*!< Read-Write Margin value */
  uint32_t                        :5;                                /*!< RESERVED */
  uint32_t LS                     :1;                                /*!< Ligth Sleep CAN RAM */
} _SIU_CANRAMCTRL_bits;

/* Bit field positions: */
#define SIU_CANRAMCTRL_RMEN_Pos               0                      /*!< Enable to use Read-Write Margin */
#define SIU_CANRAMCTRL_RM_Pos                 1                      /*!< Read-Write Margin value */
#define SIU_CANRAMCTRL_LS_Pos                 8                      /*!< Ligth Sleep CAN RAM */

/* Bit field masks: */
#define SIU_CANRAMCTRL_RMEN_Msk               0x00000001UL           /*!< Enable to use Read-Write Margin */
#define SIU_CANRAMCTRL_RM_Msk                 0x00000006UL           /*!< Read-Write Margin value */
#define SIU_CANRAMCTRL_LS_Msk                 0x00000100UL           /*!< Ligth Sleep CAN RAM */

/*--  TMRMUX: TMR ccix input select ---------------------------------------------------------------------------*/
typedef struct {
  uint32_t TMR0CCIA               :4;                                /*!< Select signal for TMR0 CCIA input */
  uint32_t TMR0CCIB               :4;                                /*!< Select signal for TMR0 CCIB input */
  uint32_t TMR1CCIA               :4;                                /*!< Select signal for TMR1 CCIA input */
  uint32_t TMR1CCIB               :4;                                /*!< Select signal for TMR1 CCIB input */
  uint32_t TMR2CCIA               :4;                                /*!< Select signal for TMR2 CCIA input */
  uint32_t TMR2CCIB               :4;                                /*!< Select signal for TMR2 CCIB input */
  uint32_t TMR3CCIA               :4;                                /*!< Select signal for TMR3 CCIA input */
  uint32_t TMR3CCIB               :4;                                /*!< Select signal for TMR3 CCIB input */
} _SIU_TMRMUX_bits;

/* Bit field positions: */
#define SIU_TMRMUX_TMR0CCIA_Pos               0                      /*!< Select signal for TMR0 CCIA input */
#define SIU_TMRMUX_TMR0CCIB_Pos               4                      /*!< Select signal for TMR0 CCIB input */
#define SIU_TMRMUX_TMR1CCIA_Pos               8                      /*!< Select signal for TMR1 CCIA input */
#define SIU_TMRMUX_TMR1CCIB_Pos               12                     /*!< Select signal for TMR1 CCIB input */
#define SIU_TMRMUX_TMR2CCIA_Pos               16                     /*!< Select signal for TMR2 CCIA input */
#define SIU_TMRMUX_TMR2CCIB_Pos               20                     /*!< Select signal for TMR2 CCIB input */
#define SIU_TMRMUX_TMR3CCIA_Pos               24                     /*!< Select signal for TMR3 CCIA input */
#define SIU_TMRMUX_TMR3CCIB_Pos               28                     /*!< Select signal for TMR3 CCIB input */

/* Bit field masks: */
#define SIU_TMRMUX_TMR0CCIA_Msk               0x0000000FUL           /*!< Select signal for TMR0 CCIA input */
#define SIU_TMRMUX_TMR0CCIB_Msk               0x000000F0UL           /*!< Select signal for TMR0 CCIB input */
#define SIU_TMRMUX_TMR1CCIA_Msk               0x00000F00UL           /*!< Select signal for TMR1 CCIA input */
#define SIU_TMRMUX_TMR1CCIB_Msk               0x0000F000UL           /*!< Select signal for TMR1 CCIB input */
#define SIU_TMRMUX_TMR2CCIA_Msk               0x000F0000UL           /*!< Select signal for TMR2 CCIA input */
#define SIU_TMRMUX_TMR2CCIB_Msk               0x00F00000UL           /*!< Select signal for TMR2 CCIB input */
#define SIU_TMRMUX_TMR3CCIA_Msk               0x0F000000UL           /*!< Select signal for TMR3 CCIA input */
#define SIU_TMRMUX_TMR3CCIB_Msk               0xF0000000UL           /*!< Select signal for TMR3 CCIB input */

/* Bit field enums: */
typedef enum {
  SIU_TMRMUX_TMR0CCIA_TMR0                   = 0x0UL,                /*!< External pin TMR0 */
  SIU_TMRMUX_TMR0CCIA_TMR1                   = 0x1UL,                /*!< External pin TMR1 */
  SIU_TMRMUX_TMR0CCIA_TMR2                   = 0x2UL,                /*!< External pin TMR2 */
  SIU_TMRMUX_TMR0CCIA_TMR3                   = 0x3UL,                /*!< External pin TMR3 */
  SIU_TMRMUX_TMR0CCIA_GPIOA                  = 0x4UL,                /*!< GPIOA adc soc impulse */
  SIU_TMRMUX_TMR0CCIA_GPIOB                  = 0x5UL,                /*!< GPIOB adc soc impulse */
  SIU_TMRMUX_TMR0CCIA_PWM0A                  = 0x6UL,                /*!< PWM0 adc soc chanel A impulse */
  SIU_TMRMUX_TMR0CCIA_PWM0B                  = 0x7UL,                /*!< PWM0 adc soc chanel B impulse */
  SIU_TMRMUX_TMR0CCIA_PWM1A                  = 0x8UL,                /*!< PWM1 adc soc chanel A impulse */
  SIU_TMRMUX_TMR0CCIA_PWM1B                  = 0x9UL,                /*!< PWM1 adc soc chanel B impulse */
  SIU_TMRMUX_TMR0CCIA_PWM2A                  = 0xAUL,                /*!< PWM2 adc soc chanel A impulse */
  SIU_TMRMUX_TMR0CCIA_PWM2B                  = 0xBUL,                /*!< PWM2 adc soc chanel B impulse */
} SIU_TMRMUX_TMR0CCIA_Enum;

typedef enum {
  SIU_TMRMUX_TMR0CCIB_TMR0                   = 0x0UL,                /*!< External pin TMR0 */
  SIU_TMRMUX_TMR0CCIB_TMR1                   = 0x1UL,                /*!< External pin TMR1 */
  SIU_TMRMUX_TMR0CCIB_TMR2                   = 0x2UL,                /*!< External pin TMR2 */
  SIU_TMRMUX_TMR0CCIB_TMR3                   = 0x3UL,                /*!< External pin TMR3 */
  SIU_TMRMUX_TMR0CCIB_GPIOA                  = 0x4UL,                /*!< GPIOA adc soc impulse */
  SIU_TMRMUX_TMR0CCIB_GPIOB                  = 0x5UL,                /*!< GPIOB adc soc impulse */
  SIU_TMRMUX_TMR0CCIB_PWM0A                  = 0x6UL,                /*!< PWM0 adc soc chanel A impulse */
  SIU_TMRMUX_TMR0CCIB_PWM0B                  = 0x7UL,                /*!< PWM0 adc soc chanel B impulse */
  SIU_TMRMUX_TMR0CCIB_PWM1A                  = 0x8UL,                /*!< PWM1 adc soc chanel A impulse */
  SIU_TMRMUX_TMR0CCIB_PWM1B                  = 0x9UL,                /*!< PWM1 adc soc chanel B impulse */
  SIU_TMRMUX_TMR0CCIB_PWM2A                  = 0xAUL,                /*!< PWM2 adc soc chanel A impulse */
  SIU_TMRMUX_TMR0CCIB_PWM2B                  = 0xBUL,                /*!< PWM2 adc soc chanel B impulse */
} SIU_TMRMUX_TMR0CCIB_Enum;

typedef enum {
  SIU_TMRMUX_TMR1CCIA_TMR0                   = 0x0UL,                /*!< External pin TMR0 */
  SIU_TMRMUX_TMR1CCIA_TMR1                   = 0x1UL,                /*!< External pin TMR1 */
  SIU_TMRMUX_TMR1CCIA_TMR2                   = 0x2UL,                /*!< External pin TMR2 */
  SIU_TMRMUX_TMR1CCIA_TMR3                   = 0x3UL,                /*!< External pin TMR3 */
  SIU_TMRMUX_TMR1CCIA_GPIOA                  = 0x4UL,                /*!< GPIOA adc soc impulse */
  SIU_TMRMUX_TMR1CCIA_GPIOB                  = 0x5UL,                /*!< GPIOB adc soc impulse */
  SIU_TMRMUX_TMR1CCIA_PWM0A                  = 0x6UL,                /*!< PWM0 adc soc chanel A impulse */
  SIU_TMRMUX_TMR1CCIA_PWM0B                  = 0x7UL,                /*!< PWM0 adc soc chanel B impulse */
  SIU_TMRMUX_TMR1CCIA_PWM1A                  = 0x8UL,                /*!< PWM1 adc soc chanel A impulse */
  SIU_TMRMUX_TMR1CCIA_PWM1B                  = 0x9UL,                /*!< PWM1 adc soc chanel B impulse */
  SIU_TMRMUX_TMR1CCIA_PWM2A                  = 0xAUL,                /*!< PWM2 adc soc chanel A impulse */
  SIU_TMRMUX_TMR1CCIA_PWM2B                  = 0xBUL,                /*!< PWM2 adc soc chanel B impulse */
} SIU_TMRMUX_TMR1CCIA_Enum;

typedef enum {
  SIU_TMRMUX_TMR1CCIB_TMR0                   = 0x0UL,                /*!< External pin TMR0 */
  SIU_TMRMUX_TMR1CCIB_TMR1                   = 0x1UL,                /*!< External pin TMR1 */
  SIU_TMRMUX_TMR1CCIB_TMR2                   = 0x2UL,                /*!< External pin TMR2 */
  SIU_TMRMUX_TMR1CCIB_TMR3                   = 0x3UL,                /*!< External pin TMR3 */
  SIU_TMRMUX_TMR1CCIB_GPIOA                  = 0x4UL,                /*!< GPIOA adc soc impulse */
  SIU_TMRMUX_TMR1CCIB_GPIOB                  = 0x5UL,                /*!< GPIOB adc soc impulse */
  SIU_TMRMUX_TMR1CCIB_PWM0A                  = 0x6UL,                /*!< PWM0 adc soc chanel A impulse */
  SIU_TMRMUX_TMR1CCIB_PWM0B                  = 0x7UL,                /*!< PWM0 adc soc chanel B impulse */
  SIU_TMRMUX_TMR1CCIB_PWM1A                  = 0x8UL,                /*!< PWM1 adc soc chanel A impulse */
  SIU_TMRMUX_TMR1CCIB_PWM1B                  = 0x9UL,                /*!< PWM1 adc soc chanel B impulse */
  SIU_TMRMUX_TMR1CCIB_PWM2A                  = 0xAUL,                /*!< PWM2 adc soc chanel A impulse */
  SIU_TMRMUX_TMR1CCIB_PWM2B                  = 0xBUL,                /*!< PWM2 adc soc chanel B impulse */
} SIU_TMRMUX_TMR1CCIB_Enum;

typedef enum {
  SIU_TMRMUX_TMR2CCIA_TMR0                   = 0x0UL,                /*!< External pin TMR0 */
  SIU_TMRMUX_TMR2CCIA_TMR1                   = 0x1UL,                /*!< External pin TMR1 */
  SIU_TMRMUX_TMR2CCIA_TMR2                   = 0x2UL,                /*!< External pin TMR2 */
  SIU_TMRMUX_TMR2CCIA_TMR3                   = 0x3UL,                /*!< External pin TMR3 */
  SIU_TMRMUX_TMR2CCIA_GPIOA                  = 0x4UL,                /*!< GPIOA adc soc impulse */
  SIU_TMRMUX_TMR2CCIA_GPIOB                  = 0x5UL,                /*!< GPIOB adc soc impulse */
  SIU_TMRMUX_TMR2CCIA_PWM0A                  = 0x6UL,                /*!< PWM0 adc soc chanel A impulse */
  SIU_TMRMUX_TMR2CCIA_PWM0B                  = 0x7UL,                /*!< PWM0 adc soc chanel B impulse */
  SIU_TMRMUX_TMR2CCIA_PWM1A                  = 0x8UL,                /*!< PWM1 adc soc chanel A impulse */
  SIU_TMRMUX_TMR2CCIA_PWM1B                  = 0x9UL,                /*!< PWM1 adc soc chanel B impulse */
  SIU_TMRMUX_TMR2CCIA_PWM2A                  = 0xAUL,                /*!< PWM2 adc soc chanel A impulse */
  SIU_TMRMUX_TMR2CCIA_PWM2B                  = 0xBUL,                /*!< PWM2 adc soc chanel B impulse */
} SIU_TMRMUX_TMR2CCIA_Enum;

typedef enum {
  SIU_TMRMUX_TMR2CCIB_TMR0                   = 0x0UL,                /*!< External pin TMR0 */
  SIU_TMRMUX_TMR2CCIB_TMR1                   = 0x1UL,                /*!< External pin TMR1 */
  SIU_TMRMUX_TMR2CCIB_TMR2                   = 0x2UL,                /*!< External pin TMR2 */
  SIU_TMRMUX_TMR2CCIB_TMR3                   = 0x3UL,                /*!< External pin TMR3 */
  SIU_TMRMUX_TMR2CCIB_GPIOA                  = 0x4UL,                /*!< GPIOA adc soc impulse */
  SIU_TMRMUX_TMR2CCIB_GPIOB                  = 0x5UL,                /*!< GPIOB adc soc impulse */
  SIU_TMRMUX_TMR2CCIB_PWM0A                  = 0x6UL,                /*!< PWM0 adc soc chanel A impulse */
  SIU_TMRMUX_TMR2CCIB_PWM0B                  = 0x7UL,                /*!< PWM0 adc soc chanel B impulse */
  SIU_TMRMUX_TMR2CCIB_PWM1A                  = 0x8UL,                /*!< PWM1 adc soc chanel A impulse */
  SIU_TMRMUX_TMR2CCIB_PWM1B                  = 0x9UL,                /*!< PWM1 adc soc chanel B impulse */
  SIU_TMRMUX_TMR2CCIB_PWM2A                  = 0xAUL,                /*!< PWM2 adc soc chanel A impulse */
  SIU_TMRMUX_TMR2CCIB_PWM2B                  = 0xBUL,                /*!< PWM2 adc soc chanel B impulse */
} SIU_TMRMUX_TMR2CCIB_Enum;

typedef enum {
  SIU_TMRMUX_TMR3CCIA_TMR0                   = 0x0UL,                /*!< External pin TMR0 */
  SIU_TMRMUX_TMR3CCIA_TMR1                   = 0x1UL,                /*!< External pin TMR1 */
  SIU_TMRMUX_TMR3CCIA_TMR2                   = 0x2UL,                /*!< External pin TMR2 */
  SIU_TMRMUX_TMR3CCIA_TMR3                   = 0x3UL,                /*!< External pin TMR3 */
  SIU_TMRMUX_TMR3CCIA_GPIOA                  = 0x4UL,                /*!< GPIOA adc soc impulse */
  SIU_TMRMUX_TMR3CCIA_GPIOB                  = 0x5UL,                /*!< GPIOB adc soc impulse */
  SIU_TMRMUX_TMR3CCIA_PWM0A                  = 0x6UL,                /*!< PWM0 adc soc chanel A impulse */
  SIU_TMRMUX_TMR3CCIA_PWM0B                  = 0x7UL,                /*!< PWM0 adc soc chanel B impulse */
  SIU_TMRMUX_TMR3CCIA_PWM1A                  = 0x8UL,                /*!< PWM1 adc soc chanel A impulse */
  SIU_TMRMUX_TMR3CCIA_PWM1B                  = 0x9UL,                /*!< PWM1 adc soc chanel B impulse */
  SIU_TMRMUX_TMR3CCIA_PWM2A                  = 0xAUL,                /*!< PWM2 adc soc chanel A impulse */
  SIU_TMRMUX_TMR3CCIA_PWM2B                  = 0xBUL,                /*!< PWM2 adc soc chanel B impulse */
} SIU_TMRMUX_TMR3CCIA_Enum;

typedef enum {
  SIU_TMRMUX_TMR3CCIB_TMR0                   = 0x0UL,                /*!< External pin TMR0 */
  SIU_TMRMUX_TMR3CCIB_TMR1                   = 0x1UL,                /*!< External pin TMR1 */
  SIU_TMRMUX_TMR3CCIB_TMR2                   = 0x2UL,                /*!< External pin TMR2 */
  SIU_TMRMUX_TMR3CCIB_TMR3                   = 0x3UL,                /*!< External pin TMR3 */
  SIU_TMRMUX_TMR3CCIB_GPIOA                  = 0x4UL,                /*!< GPIOA adc soc impulse */
  SIU_TMRMUX_TMR3CCIB_GPIOB                  = 0x5UL,                /*!< GPIOB adc soc impulse */
  SIU_TMRMUX_TMR3CCIB_PWM0A                  = 0x6UL,                /*!< PWM0 adc soc chanel A impulse */
  SIU_TMRMUX_TMR3CCIB_PWM0B                  = 0x7UL,                /*!< PWM0 adc soc chanel B impulse */
  SIU_TMRMUX_TMR3CCIB_PWM1A                  = 0x8UL,                /*!< PWM1 adc soc chanel A impulse */
  SIU_TMRMUX_TMR3CCIB_PWM1B                  = 0x9UL,                /*!< PWM1 adc soc chanel B impulse */
  SIU_TMRMUX_TMR3CCIB_PWM2A                  = 0xAUL,                /*!< PWM2 adc soc chanel A impulse */
  SIU_TMRMUX_TMR3CCIB_PWM2B                  = 0xBUL,                /*!< PWM2 adc soc chanel B impulse */
} SIU_TMRMUX_TMR3CCIB_Enum;

typedef struct {
  union {                                                               /*!< Chip identifier */
    __I uint32_t CHIPID;                                             /*!< CHIPID    : type used for word access */
    __I _SIU_CHIPID_bits  CHIPID_bit;                                /*!< CHIPID_bit: structure used for bit access */
  };
  union {                                                               /*!< Service mode Register */
    __IO uint32_t SERVCTL;                                           /*!< SERVCTL    : type used for word access */
    __IO _SIU_SERVCTL_bits  SERVCTL_bit;                             /*!< SERVCTL_bit: structure used for bit access */
  };
  union {                                                               /*!< Sync PWM/CAP register */
    __IO uint32_t SYNC;                                              /*!< SYNC    : type used for word access */
    __IO _SIU_SYNC_bits  SYNC_bit;                                   /*!< SYNC_bit: structure used for bit access */
  };
  union {                                                               /*!< PWM/TMR count enable register enable register */
    __IO uint32_t CNTEN;                                             /*!< CNTEN    : type used for word access */
    __IO _SIU_CNTEN_bits  CNTEN_bit;                                 /*!< CNTEN_bit: structure used for bit access */
  };
  union {                                                               /*!< TMR external clock config */
    __IO uint32_t TMRCFG;                                            /*!< TMRCFG    : type used for word access */
    __IO _SIU_TMRCFG_bits  TMRCFG_bit;                               /*!< TMRCFG_bit: structure used for bit access */
  };
  union {                                                               /*!< CAP input mux control register */
    __IO uint32_t CAPMUX;                                            /*!< CAPMUX    : type used for word access */
    __IO _SIU_CAPMUX_bits  CAPMUX_bit;                               /*!< CAPMUX_bit: structure used for bit access */
  };
  union {                                                               /*!< QEP and ECAP qualifier control register */
    __IO uint32_t QUALCTL;                                           /*!< QUALCTL    : type used for word access */
    __IO _SIU_QUALCTL_bits  QUALCTL_bit;                             /*!< QUALCTL_bit: structure used for bit access */
  };
  union {                                                               /*!< QEP and CAP qualifier sample period set register */
    __IO uint32_t QUALSAMPLE;                                           /*!< QUALSAMPLE    : type used for word access */
    __IO _SIU_QUALSAMPLE_bits  QUALSAMPLE_bit;                       /*!< QUALSAMPLE_bit: structure used for bit access */
  };
  union {                                                               /*!< RC generator control register */
    __IO uint32_t RCCTRL;                                            /*!< RCCTRL    : type used for word access */
    __IO _SIU_RCCTRL_bits  RCCTRL_bit;                               /*!< RCCTRL_bit: structure used for bit access */
  };
  union {                                                               /*!< LDO control register */
    __IO uint32_t LDOCTRL;                                           /*!< LDOCTRL    : type used for word access */
    __IO _SIU_LDOCTRL_bits  LDOCTRL_bit;                             /*!< LDOCTRL_bit: structure used for bit access */
  };
  union {                                                               /*!< CPE status register */
    __I uint32_t CPESTAT;                                            /*!< CPESTAT    : type used for word access */
    __I _SIU_CPESTAT_bits  CPESTAT_bit;                              /*!< CPESTAT_bit: structure used for bit access */
  };
  union {                                                               /*!< T-sensor control register */
    __IO uint32_t TSENSCTRL;                                           /*!< TSENSCTRL    : type used for word access */
    __IO _SIU_TSENSCTRL_bits  TSENSCTRL_bit;                         /*!< TSENSCTRL_bit: structure used for bit access */
  };
  union {                                                               /*!< Bandgap control register */
    __IO uint32_t BGPCTRL;                                           /*!< BGPCTRL    : type used for word access */
    __IO _SIU_BGPCTRL_bits  BGPCTRL_bit;                             /*!< BGPCTRL_bit: structure used for bit access */
  };
  union {                                                               /*!< BOOTSEL status register */
    __I uint32_t BOOTSELSTAT;                                           /*!< BOOTSELSTAT    : type used for word access */
    __I _SIU_BOOTSELSTAT_bits  BOOTSELSTAT_bit;                      /*!< BOOTSELSTAT_bit: structure used for bit access */
  };
    __IO uint32_t Reserved0[2];
  union {                                                               /*!< SRAM control register */
    __IO uint32_t RAMCTRL;                                           /*!< RAMCTRL    : type used for word access */
    __IO _SIU_RAMCTRL_bits  RAMCTRL_bit;                             /*!< RAMCTRL_bit: structure used for bit access */
  };
  union {                                                               /*!< Core Tightly-Coupled Memory SRAM control */
    __IO uint32_t TCMCTRL;                                           /*!< TCMCTRL    : type used for word access */
    __IO _SIU_TCMCTRL_bits  TCMCTRL_bit;                             /*!< TCMCTRL_bit: structure used for bit access */
  };
  union {                                                               /*!< Core Cache SRAM control */
    __IO uint32_t CRAMCTRL;                                           /*!< CRAMCTRL    : type used for word access */
    __IO _SIU_CRAMCTRL_bits  CRAMCTRL_bit;                           /*!< CRAMCTRL_bit: structure used for bit access */
  };
  union {                                                               /*!< CAN SRAM control */
    __IO uint32_t CANRAMCTRL;                                           /*!< CANRAMCTRL    : type used for word access */
    __IO _SIU_CANRAMCTRL_bits  CANRAMCTRL_bit;                       /*!< CANRAMCTRL_bit: structure used for bit access */
  };
  union {                                                               /*!< TMR ccix input select */
    __IO uint32_t TMRMUX;                                            /*!< TMRMUX    : type used for word access */
    __IO _SIU_TMRMUX_bits  TMRMUX_bit;                               /*!< TMRMUX_bit: structure used for bit access */
  };
} SIU_TypeDef;


/******************************************************************************/
/*                         SPI registers                                      */
/******************************************************************************/

/*--  CR: Control register ------------------------------------------------------------------------------------*/
typedef struct {
  uint32_t DSS                    :5;                                /*!< Size of data is (value + 1) bits */
  uint32_t                        :3;                                /*!< RESERVED */
  uint32_t SCR                    :8;                                /*!< Value divider */
  uint32_t FRF                    :2;                                /*!< Select protocol */
  uint32_t SPO                    :1;                                /*!< Polarity SSPCLKOUT */
  uint32_t SPH                    :1;                                /*!< Phase SSPCLKOUT */
  uint32_t LBM                    :1;                                /*!< Test loopback mode */
  uint32_t SSE                    :1;                                /*!< Enable transceiver */
  uint32_t MS                     :1;                                /*!< Select mode */
  uint32_t SOD                    :1;                                /*!< Disable bit data */
  uint32_t RXIFLSEL               :4;                                /*!< Receive interrupt FIFO level select */
  uint32_t TXIFLSEL               :4;                                /*!< Transmit interrupt FIFO level select */
} _SPI_CR_bits;

/* Bit field positions: */
#define SPI_CR_DSS_Pos                        0                      /*!< Size of data is (value + 1) bits */
#define SPI_CR_SCR_Pos                        8                      /*!< Value divider */
#define SPI_CR_FRF_Pos                        16                     /*!< Select protocol */
#define SPI_CR_SPO_Pos                        18                     /*!< Polarity SSPCLKOUT */
#define SPI_CR_SPH_Pos                        19                     /*!< Phase SSPCLKOUT */
#define SPI_CR_LBM_Pos                        20                     /*!< Test loopback mode */
#define SPI_CR_SSE_Pos                        21                     /*!< Enable transceiver */
#define SPI_CR_MS_Pos                         22                     /*!< Select mode */
#define SPI_CR_SOD_Pos                        23                     /*!< Disable bit data */
#define SPI_CR_RXIFLSEL_Pos                   24                     /*!< Receive interrupt FIFO level select */
#define SPI_CR_TXIFLSEL_Pos                   28                     /*!< Transmit interrupt FIFO level select */

/* Bit field masks: */
#define SPI_CR_DSS_Msk                        0x0000001FUL           /*!< Size of data is (value + 1) bits */
#define SPI_CR_SCR_Msk                        0x0000FF00UL           /*!< Value divider */
#define SPI_CR_FRF_Msk                        0x00030000UL           /*!< Select protocol */
#define SPI_CR_SPO_Msk                        0x00040000UL           /*!< Polarity SSPCLKOUT */
#define SPI_CR_SPH_Msk                        0x00080000UL           /*!< Phase SSPCLKOUT */
#define SPI_CR_LBM_Msk                        0x00100000UL           /*!< Test loopback mode */
#define SPI_CR_SSE_Msk                        0x00200000UL           /*!< Enable transceiver */
#define SPI_CR_MS_Msk                         0x00400000UL           /*!< Select mode */
#define SPI_CR_SOD_Msk                        0x00800000UL           /*!< Disable bit data */
#define SPI_CR_RXIFLSEL_Msk                   0x0F000000UL           /*!< Receive interrupt FIFO level select */
#define SPI_CR_TXIFLSEL_Msk                   0xF0000000UL           /*!< Transmit interrupt FIFO level select */

/* Bit field enums: */
typedef enum {
  SPI_CR_DSS_4bit                            = 0x3UL,                /*!< data size 4 bits */
  SPI_CR_DSS_5bit                            = 0x4UL,                /*!< data size 5 bits */
  SPI_CR_DSS_6bit                            = 0x5UL,                /*!< data size 6 bits */
  SPI_CR_DSS_7bit                            = 0x6UL,                /*!< data size 7 bits */
  SPI_CR_DSS_8bit                            = 0x7UL,                /*!< data size 8 bits */
  SPI_CR_DSS_9bit                            = 0x8UL,                /*!< data size 9 bits */
  SPI_CR_DSS_10bit                           = 0x9UL,                /*!< data size 10 bits */
  SPI_CR_DSS_11bit                           = 0xAUL,                /*!< data size 11 bits */
  SPI_CR_DSS_12bit                           = 0xBUL,                /*!< data size 12 bits */
  SPI_CR_DSS_13bit                           = 0xCUL,                /*!< data size 13 bits */
  SPI_CR_DSS_14bit                           = 0xDUL,                /*!< data size 14 bits */
  SPI_CR_DSS_15bit                           = 0xEUL,                /*!< data size 15 bits */
  SPI_CR_DSS_16bit                           = 0xFUL,                /*!< data size 16 bits */
  SPI_CR_DSS_17bit                           = 0x10UL,               /*!< data size 17 bits */
  SPI_CR_DSS_18bit                           = 0x11UL,               /*!< data size 18 bits */
  SPI_CR_DSS_19bit                           = 0x12UL,               /*!< data size 19 bits */
  SPI_CR_DSS_20bit                           = 0x13UL,               /*!< data size 20 bits */
  SPI_CR_DSS_21bit                           = 0x14UL,               /*!< data size 21 bits */
  SPI_CR_DSS_22bit                           = 0x15UL,               /*!< data size 22 bits */
  SPI_CR_DSS_23bit                           = 0x16UL,               /*!< data size 23 bits */
  SPI_CR_DSS_24bit                           = 0x17UL,               /*!< data size 24 bits */
  SPI_CR_DSS_25bit                           = 0x18UL,               /*!< data size 25 bits */
  SPI_CR_DSS_26bit                           = 0x19UL,               /*!< data size 26 bits */
  SPI_CR_DSS_27bit                           = 0x1AUL,               /*!< data size 27 bits */
  SPI_CR_DSS_28bit                           = 0x1BUL,               /*!< data size 28 bits */
  SPI_CR_DSS_29bit                           = 0x1CUL,               /*!< data size 29 bits */
  SPI_CR_DSS_30bit                           = 0x1DUL,               /*!< data size 30 bits */
  SPI_CR_DSS_31bit                           = 0x1EUL,               /*!< data size 31 bits */
  SPI_CR_DSS_32bit                           = 0x1FUL,               /*!< data size 32 bits */
} SPI_CR_DSS_Enum;

typedef enum {
  SPI_CR_FRF_SPI                             = 0x0UL,                /*!< SPI of Motorola */
  SPI_CR_FRF_SSI                             = 0x1UL,                /*!< SSI of Texas Instruments */
  SPI_CR_FRF_Microwire                       = 0x2UL,                /*!< Microwire of National Semiconductor */
} SPI_CR_FRF_Enum;

/*--  DR: Data register ---------------------------------------------------------------------------------------*/
typedef struct {
  uint32_t DATA                   :32;                               /*!<  */
} _SPI_DR_bits;

/* Bit field positions: */
#define SPI_DR_DATA_Pos                       0                      /*!<  */

/* Bit field masks: */
#define SPI_DR_DATA_Msk                       0xFFFFFFFFUL           /*!<  */

/*--  SR: State register --------------------------------------------------------------------------------------*/
typedef struct {
  uint32_t TFE                    :1;                                /*!< FIFO buffer empty flag transmitter */
  uint32_t TNF                    :1;                                /*!< Indicator the transmitter FIFO buffer is not full */
  uint32_t RNE                    :1;                                /*!< Indicate not empty receive buffer */
  uint32_t RFF                    :1;                                /*!< Indicate full receive buffer */
  uint32_t BSY                    :1;                                /*!< Activity flag */
} _SPI_SR_bits;

/* Bit field positions: */
#define SPI_SR_TFE_Pos                        0                      /*!< FIFO buffer empty flag transmitter */
#define SPI_SR_TNF_Pos                        1                      /*!< Indicator the transmitter FIFO buffer is not full */
#define SPI_SR_RNE_Pos                        2                      /*!< Indicate not empty receive buffer */
#define SPI_SR_RFF_Pos                        3                      /*!< Indicate full receive buffer */
#define SPI_SR_BSY_Pos                        4                      /*!< Activity flag */

/* Bit field masks: */
#define SPI_SR_TFE_Msk                        0x00000001UL           /*!< FIFO buffer empty flag transmitter */
#define SPI_SR_TNF_Msk                        0x00000002UL           /*!< Indicator the transmitter FIFO buffer is not full */
#define SPI_SR_RNE_Msk                        0x00000004UL           /*!< Indicate not empty receive buffer */
#define SPI_SR_RFF_Msk                        0x00000008UL           /*!< Indicate full receive buffer */
#define SPI_SR_BSY_Msk                        0x00000010UL           /*!< Activity flag */

/*--  CPSR: Clock division factor register --------------------------------------------------------------------*/
typedef struct {
  uint32_t CPSDVSR                :8;                                /*!< Clock division factor. Bit0 always 0 */
} _SPI_CPSR_bits;

/* Bit field positions: */
#define SPI_CPSR_CPSDVSR_Pos                  0                      /*!< Clock division factor. Bit0 always 0 */

/* Bit field masks: */
#define SPI_CPSR_CPSDVSR_Msk                  0x000000FFUL           /*!< Clock division factor. Bit0 always 0 */

/*--  IMSC: Mask interrupt register ---------------------------------------------------------------------------*/
typedef struct {
  uint32_t RORIM                  :1;                                /*!< Interrupt mask bit SSPRORINTR buffer overflow receiver */
  uint32_t RTIM                   :1;                                /*!< Interrupt mask bit SSPRTINTR timeout receiver */
  uint32_t RXIM                   :1;                                /*!< SSPRXINTR interrupt mask bit to fill 50% or less of the receiver FIFO buffer */
  uint32_t TXIM                   :1;                                /*!< SSPTXINTR interrupt mask bit to fill 50% or less of the FIFO buffer of the transmitter */
} _SPI_IMSC_bits;

/* Bit field positions: */
#define SPI_IMSC_RORIM_Pos                    0                      /*!< Interrupt mask bit SSPRORINTR buffer overflow receiver */
#define SPI_IMSC_RTIM_Pos                     1                      /*!< Interrupt mask bit SSPRTINTR timeout receiver */
#define SPI_IMSC_RXIM_Pos                     2                      /*!< SSPRXINTR interrupt mask bit to fill 50% or less of the receiver FIFO buffer */
#define SPI_IMSC_TXIM_Pos                     3                      /*!< SSPTXINTR interrupt mask bit to fill 50% or less of the FIFO buffer of the transmitter */

/* Bit field masks: */
#define SPI_IMSC_RORIM_Msk                    0x00000001UL           /*!< Interrupt mask bit SSPRORINTR buffer overflow receiver */
#define SPI_IMSC_RTIM_Msk                     0x00000002UL           /*!< Interrupt mask bit SSPRTINTR timeout receiver */
#define SPI_IMSC_RXIM_Msk                     0x00000004UL           /*!< SSPRXINTR interrupt mask bit to fill 50% or less of the receiver FIFO buffer */
#define SPI_IMSC_TXIM_Msk                     0x00000008UL           /*!< SSPTXINTR interrupt mask bit to fill 50% or less of the FIFO buffer of the transmitter */

/*--  RIS: Status register interrupt without mask -------------------------------------------------------------*/
typedef struct {
  uint32_t RORRIS                 :1;                                /*!< Interrupt status before masking SSPRORINTR */
  uint32_t RTRIS                  :1;                                /*!< Interrupt status before masking SSPRTINTR */
  uint32_t RXRIS                  :1;                                /*!< Interrupt status before masking SSPRXINTR */
  uint32_t TXRIS                  :1;                                /*!< Interrupt status before masking SSPTXINTR */
} _SPI_RIS_bits;

/* Bit field positions: */
#define SPI_RIS_RORRIS_Pos                    0                      /*!< Interrupt status before masking SSPRORINTR */
#define SPI_RIS_RTRIS_Pos                     1                      /*!< Interrupt status before masking SSPRTINTR */
#define SPI_RIS_RXRIS_Pos                     2                      /*!< Interrupt status before masking SSPRXINTR */
#define SPI_RIS_TXRIS_Pos                     3                      /*!< Interrupt status before masking SSPTXINTR */

/* Bit field masks: */
#define SPI_RIS_RORRIS_Msk                    0x00000001UL           /*!< Interrupt status before masking SSPRORINTR */
#define SPI_RIS_RTRIS_Msk                     0x00000002UL           /*!< Interrupt status before masking SSPRTINTR */
#define SPI_RIS_RXRIS_Msk                     0x00000004UL           /*!< Interrupt status before masking SSPRXINTR */
#define SPI_RIS_TXRIS_Msk                     0x00000008UL           /*!< Interrupt status before masking SSPTXINTR */

/*--  MIS: Status register interrupt masking account ----------------------------------------------------------*/
typedef struct {
  uint32_t RORMIS                 :1;                                /*!< Masked interrupt status SSPRORINTR */
  uint32_t RTMIS                  :1;                                /*!< Masked interrupt status SSPRTINTR */
  uint32_t RXMIS                  :1;                                /*!< Masked interrupt status SSPRXINTR */
  uint32_t TXMIS                  :1;                                /*!< Masked interrupt status SSPTXINTR */
} _SPI_MIS_bits;

/* Bit field positions: */
#define SPI_MIS_RORMIS_Pos                    0                      /*!< Masked interrupt status SSPRORINTR */
#define SPI_MIS_RTMIS_Pos                     1                      /*!< Masked interrupt status SSPRTINTR */
#define SPI_MIS_RXMIS_Pos                     2                      /*!< Masked interrupt status SSPRXINTR */
#define SPI_MIS_TXMIS_Pos                     3                      /*!< Masked interrupt status SSPTXINTR */

/* Bit field masks: */
#define SPI_MIS_RORMIS_Msk                    0x00000001UL           /*!< Masked interrupt status SSPRORINTR */
#define SPI_MIS_RTMIS_Msk                     0x00000002UL           /*!< Masked interrupt status SSPRTINTR */
#define SPI_MIS_RXMIS_Msk                     0x00000004UL           /*!< Masked interrupt status SSPRXINTR */
#define SPI_MIS_TXMIS_Msk                     0x00000008UL           /*!< Masked interrupt status SSPTXINTR */

/*--  ICR: Register reset interrupt ---------------------------------------------------------------------------*/
typedef struct {
  uint32_t RORIC                  :1;                                /*!< Reset interrupt SSPRORINTR */
  uint32_t RTIC                   :1;                                /*!< Reset interrupt SSPRTINTR */
} _SPI_ICR_bits;

/* Bit field positions: */
#define SPI_ICR_RORIC_Pos                     0                      /*!< Reset interrupt SSPRORINTR */
#define SPI_ICR_RTIC_Pos                      1                      /*!< Reset interrupt SSPRTINTR */

/* Bit field masks: */
#define SPI_ICR_RORIC_Msk                     0x00000001UL           /*!< Reset interrupt SSPRORINTR */
#define SPI_ICR_RTIC_Msk                      0x00000002UL           /*!< Reset interrupt SSPRTINTR */

/*--  DMACR: Control register DMA -----------------------------------------------------------------------------*/
typedef struct {
  uint32_t RXDMAE                 :1;                                /*!< DMA enable bit at reception */
  uint32_t TXDMAE                 :1;                                /*!< DMA enable bit transmission */
  uint32_t DMARXSTOP              :1;                                /*!< Automatic clear DMA RX request generation when channel ends all transactions */
  uint32_t DMATXSTOP              :1;                                /*!< Automatic clear DMA TX request generation when channel ends all transactions */
} _SPI_DMACR_bits;

/* Bit field positions: */
#define SPI_DMACR_RXDMAE_Pos                  0                      /*!< DMA enable bit at reception */
#define SPI_DMACR_TXDMAE_Pos                  1                      /*!< DMA enable bit transmission */
#define SPI_DMACR_DMARXSTOP_Pos               2                      /*!< Automatic clear DMA RX request generation when channel ends all transactions */
#define SPI_DMACR_DMATXSTOP_Pos               3                      /*!< Automatic clear DMA TX request generation when channel ends all transactions */

/* Bit field masks: */
#define SPI_DMACR_RXDMAE_Msk                  0x00000001UL           /*!< DMA enable bit at reception */
#define SPI_DMACR_TXDMAE_Msk                  0x00000002UL           /*!< DMA enable bit transmission */
#define SPI_DMACR_DMARXSTOP_Msk               0x00000004UL           /*!< Automatic clear DMA RX request generation when channel ends all transactions */
#define SPI_DMACR_DMATXSTOP_Msk               0x00000008UL           /*!< Automatic clear DMA TX request generation when channel ends all transactions */

typedef struct {
  union {                                                               /*!< Control register */
    __IO uint32_t CR;                                                /*!< CR    : type used for word access */
    __IO _SPI_CR_bits  CR_bit;                                       /*!< CR_bit: structure used for bit access */
  };
    __IO uint32_t Reserved0;
  union {                                                               /*!< Data register */
    __IO uint32_t DR;                                                /*!< DR    : type used for word access */
    __IO _SPI_DR_bits  DR_bit;                                       /*!< DR_bit: structure used for bit access */
  };
  union {                                                               /*!< State register */
    __I uint32_t SR;                                                 /*!< SR    : type used for word access */
    __I _SPI_SR_bits  SR_bit;                                        /*!< SR_bit: structure used for bit access */
  };
  union {                                                               /*!< Clock division factor register */
    __IO uint32_t CPSR;                                              /*!< CPSR    : type used for word access */
    __IO _SPI_CPSR_bits  CPSR_bit;                                   /*!< CPSR_bit: structure used for bit access */
  };
  union {                                                               /*!< Mask interrupt register */
    __IO uint32_t IMSC;                                              /*!< IMSC    : type used for word access */
    __IO _SPI_IMSC_bits  IMSC_bit;                                   /*!< IMSC_bit: structure used for bit access */
  };
  union {                                                               /*!< Status register interrupt without mask */
    __I uint32_t RIS;                                                /*!< RIS    : type used for word access */
    __I _SPI_RIS_bits  RIS_bit;                                      /*!< RIS_bit: structure used for bit access */
  };
  union {                                                               /*!< Status register interrupt masking account */
    __I uint32_t MIS;                                                /*!< MIS    : type used for word access */
    __I _SPI_MIS_bits  MIS_bit;                                      /*!< MIS_bit: structure used for bit access */
  };
  union {                                                               /*!< Register reset interrupt */
    __O uint32_t ICR;                                                /*!< ICR    : type used for word access */
    __O _SPI_ICR_bits  ICR_bit;                                      /*!< ICR_bit: structure used for bit access */
  };
  union {                                                               /*!< Control register DMA */
    __IO uint32_t DMACR;                                             /*!< DMACR    : type used for word access */
    __IO _SPI_DMACR_bits  DMACR_bit;                                 /*!< DMACR_bit: structure used for bit access */
  };
} SPI_TypeDef;


/******************************************************************************/
/*                         WDT registers                                      */
/******************************************************************************/

/*--  LOAD: Watchdog Load Register ----------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!< Begin value counter */
} _WDT_LOAD_bits;

/* Bit field positions: */
#define WDT_LOAD_VAL_Pos                      0                      /*!< Begin value counter */

/* Bit field masks: */
#define WDT_LOAD_VAL_Msk                      0xFFFFFFFFUL           /*!< Begin value counter */

/*--  VALUE: Watchdog Value Register --------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!< Current value counter */
} _WDT_VALUE_bits;

/* Bit field positions: */
#define WDT_VALUE_VAL_Pos                     0                      /*!< Current value counter */

/* Bit field masks: */
#define WDT_VALUE_VAL_Msk                     0xFFFFFFFFUL           /*!< Current value counter */

/*--  CTRL: Watchdog Control Register -------------------------------------------------------------------------*/
typedef struct {
  uint32_t INTEN                  :1;                                /*!< Enable the interrupt event */
  uint32_t RESEN                  :1;                                /*!< Enable watchdog reset output */
} _WDT_CTRL_bits;

/* Bit field positions: */
#define WDT_CTRL_INTEN_Pos                    0                      /*!< Enable the interrupt event */
#define WDT_CTRL_RESEN_Pos                    1                      /*!< Enable watchdog reset output */

/* Bit field masks: */
#define WDT_CTRL_INTEN_Msk                    0x00000001UL           /*!< Enable the interrupt event */
#define WDT_CTRL_RESEN_Msk                    0x00000002UL           /*!< Enable watchdog reset output */

/*--  INTCLR: Watchdog Clear Interrupt Register ---------------------------------------------------------------*/
typedef struct {
  uint32_t WDTCLR                 :32;                               /*!< Reset interrupt WDT */
} _WDT_INTCLR_bits;

/* Bit field positions: */
#define WDT_INTCLR_WDTCLR_Pos                 0                      /*!< Reset interrupt WDT */

/* Bit field masks: */
#define WDT_INTCLR_WDTCLR_Msk                 0xFFFFFFFFUL           /*!< Reset interrupt WDT */

/*--  RIS: Watchdog Raw Interrupt Status Register -------------------------------------------------------------*/
typedef struct {
  uint32_t RAWWDTINT              :1;                                /*!< Raw interrupt status from the counter */
} _WDT_RIS_bits;

/* Bit field positions: */
#define WDT_RIS_RAWWDTINT_Pos                 0                      /*!< Raw interrupt status from the counter */

/* Bit field masks: */
#define WDT_RIS_RAWWDTINT_Msk                 0x00000001UL           /*!< Raw interrupt status from the counter */

/*--  MIS: Watchdog Interrupt Status Register -----------------------------------------------------------------*/
typedef struct {
  uint32_t WDTINT                 :1;                                /*!< Enabled interrupt status from the counter */
} _WDT_MIS_bits;

/* Bit field positions: */
#define WDT_MIS_WDTINT_Pos                    0                      /*!< Enabled interrupt status from the counter */

/* Bit field masks: */
#define WDT_MIS_WDTINT_Msk                    0x00000001UL           /*!< Enabled interrupt status from the counter */

/*--  LOCK: Watchdog Lock Register ----------------------------------------------------------------------------*/
typedef struct {
  uint32_t REGWRDIS               :1;                                /*!< Disable write to all registers Watchdog */
} _WDT_LOCK_bits;

/* Bit field positions: */
#define WDT_LOCK_REGWRDIS_Pos                 0                      /*!< Disable write to all registers Watchdog */

/* Bit field masks: */
#define WDT_LOCK_REGWRDIS_Msk                 0x00000001UL           /*!< Disable write to all registers Watchdog */

typedef struct {
  union {                                                               /*!< Watchdog Load Register */
    __IO uint32_t LOAD;                                              /*!< LOAD    : type used for word access */
    __IO _WDT_LOAD_bits  LOAD_bit;                                   /*!< LOAD_bit: structure used for bit access */
  };
  union {                                                               /*!< Watchdog Value Register */
    __I uint32_t VALUE;                                              /*!< VALUE    : type used for word access */
    __I _WDT_VALUE_bits  VALUE_bit;                                  /*!< VALUE_bit: structure used for bit access */
  };
  union {                                                               /*!< Watchdog Control Register */
    __IO uint32_t CTRL;                                              /*!< CTRL    : type used for word access */
    __IO _WDT_CTRL_bits  CTRL_bit;                                   /*!< CTRL_bit: structure used for bit access */
  };
  union {                                                               /*!< Watchdog Clear Interrupt Register */
    __O uint32_t INTCLR;                                             /*!< INTCLR    : type used for word access */
    __O _WDT_INTCLR_bits  INTCLR_bit;                                /*!< INTCLR_bit: structure used for bit access */
  };
  union {                                                               /*!< Watchdog Raw Interrupt Status Register */
    __I uint32_t RIS;                                                /*!< RIS    : type used for word access */
    __I _WDT_RIS_bits  RIS_bit;                                      /*!< RIS_bit: structure used for bit access */
  };
  union {                                                               /*!< Watchdog Interrupt Status Register */
    __I uint32_t MIS;                                                /*!< MIS    : type used for word access */
    __I _WDT_MIS_bits  MIS_bit;                                      /*!< MIS_bit: structure used for bit access */
  };
    __IO uint32_t Reserved0[762];
  union {                                                               /*!< Watchdog Lock Register */
    __O uint32_t LOCK;                                               /*!< LOCK    : type used for word access */
    __O _WDT_LOCK_bits  LOCK_bit;                                    /*!< LOCK_bit: structure used for bit access */
  };
} WDT_TypeDef;


/******************************************************************************/
/*                         UART registers                                     */
/******************************************************************************/

/*--  DR: Data Register ---------------------------------------------------------------------------------------*/
typedef struct {
  uint32_t DATA                   :8;                                /*!< Received/Transmitted data character */
  uint32_t FE                     :1;                                /*!< Framing error */
  uint32_t PE                     :1;                                /*!< Parity error */
  uint32_t BE                     :1;                                /*!< Break error */
  uint32_t OE                     :1;                                /*!< Overrun error */
} _UART_DR_bits;

/* Bit field positions: */
#define UART_DR_DATA_Pos                      0                      /*!< Received/Transmitted data character */
#define UART_DR_FE_Pos                        8                      /*!< Framing error */
#define UART_DR_PE_Pos                        9                      /*!< Parity error */
#define UART_DR_BE_Pos                        10                     /*!< Break error */
#define UART_DR_OE_Pos                        11                     /*!< Overrun error */

/* Bit field masks: */
#define UART_DR_DATA_Msk                      0x000000FFUL           /*!< Received/Transmitted data character */
#define UART_DR_FE_Msk                        0x00000100UL           /*!< Framing error */
#define UART_DR_PE_Msk                        0x00000200UL           /*!< Parity error */
#define UART_DR_BE_Msk                        0x00000400UL           /*!< Break error */
#define UART_DR_OE_Msk                        0x00000800UL           /*!< Overrun error */

/*--  RSR: Receive Status Register/Error Clear Register -------------------------------------------------------*/
typedef struct {
  uint32_t FE                     :1;                                /*!< Framing error */
  uint32_t PE                     :1;                                /*!< Parity error */
  uint32_t BE                     :1;                                /*!< Break error */
  uint32_t OE                     :1;                                /*!< Overrun error */
} _UART_RSR_bits;

/* Bit field positions: */
#define UART_RSR_FE_Pos                       0                      /*!< Framing error */
#define UART_RSR_PE_Pos                       1                      /*!< Parity error */
#define UART_RSR_BE_Pos                       2                      /*!< Break error */
#define UART_RSR_OE_Pos                       3                      /*!< Overrun error */

/* Bit field masks: */
#define UART_RSR_FE_Msk                       0x00000001UL           /*!< Framing error */
#define UART_RSR_PE_Msk                       0x00000002UL           /*!< Parity error */
#define UART_RSR_BE_Msk                       0x00000004UL           /*!< Break error */
#define UART_RSR_OE_Msk                       0x00000008UL           /*!< Overrun error */

/*--  FR: Flag Register ---------------------------------------------------------------------------------------*/
typedef struct {
  uint32_t CTS                    :1;                                /*!< Clear to send */
  uint32_t DSR                    :1;                                /*!< Data set ready */
  uint32_t DCD                    :1;                                /*!< Data carrier detect */
  uint32_t BUSY                   :1;                                /*!< UART busy */
  uint32_t RXFE                   :1;                                /*!< Receive FIFO empty */
  uint32_t TXFF                   :1;                                /*!< Transmit FIFO full */
  uint32_t RXFF                   :1;                                /*!< Receive FIFO full */
  uint32_t TXFE                   :1;                                /*!< Transmit FIFO empty */
  uint32_t RI                     :1;                                /*!< Ring indicator */
} _UART_FR_bits;

/* Bit field positions: */
#define UART_FR_CTS_Pos                       0                      /*!< Clear to send */
#define UART_FR_DSR_Pos                       1                      /*!< Data set ready */
#define UART_FR_DCD_Pos                       2                      /*!< Data carrier detect */
#define UART_FR_BUSY_Pos                      3                      /*!< UART busy */
#define UART_FR_RXFE_Pos                      4                      /*!< Receive FIFO empty */
#define UART_FR_TXFF_Pos                      5                      /*!< Transmit FIFO full */
#define UART_FR_RXFF_Pos                      6                      /*!< Receive FIFO full */
#define UART_FR_TXFE_Pos                      7                      /*!< Transmit FIFO empty */
#define UART_FR_RI_Pos                        8                      /*!< Ring indicator */

/* Bit field masks: */
#define UART_FR_CTS_Msk                       0x00000001UL           /*!< Clear to send */
#define UART_FR_DSR_Msk                       0x00000002UL           /*!< Data set ready */
#define UART_FR_DCD_Msk                       0x00000004UL           /*!< Data carrier detect */
#define UART_FR_BUSY_Msk                      0x00000008UL           /*!< UART busy */
#define UART_FR_RXFE_Msk                      0x00000010UL           /*!< Receive FIFO empty */
#define UART_FR_TXFF_Msk                      0x00000020UL           /*!< Transmit FIFO full */
#define UART_FR_RXFF_Msk                      0x00000040UL           /*!< Receive FIFO full */
#define UART_FR_TXFE_Msk                      0x00000080UL           /*!< Transmit FIFO empty */
#define UART_FR_RI_Msk                        0x00000100UL           /*!< Ring indicator */

/*--  ILPR: IrDA Low-Power Counter Register -------------------------------------------------------------------*/
typedef struct {
  uint32_t ILPDVSR                :8;                                /*!< 8-bit low-power divisor value */
} _UART_ILPR_bits;

/* Bit field positions: */
#define UART_ILPR_ILPDVSR_Pos                 0                      /*!< 8-bit low-power divisor value */

/* Bit field masks: */
#define UART_ILPR_ILPDVSR_Msk                 0x000000FFUL           /*!< 8-bit low-power divisor value */

/*--  IBRD: Integer Baud Rate Register ------------------------------------------------------------------------*/
typedef struct {
  uint32_t DIVINT                 :16;                               /*!< The integer baud rate divisor */
} _UART_IBRD_bits;

/* Bit field positions: */
#define UART_IBRD_DIVINT_Pos                  0                      /*!< The integer baud rate divisor */

/* Bit field masks: */
#define UART_IBRD_DIVINT_Msk                  0x0000FFFFUL           /*!< The integer baud rate divisor */

/*--  FBRD: Fractional Baud Rate Register ---------------------------------------------------------------------*/
typedef struct {
  uint32_t DIVFRAC                :6;                                /*!< The fractional baud rate divisor */
} _UART_FBRD_bits;

/* Bit field positions: */
#define UART_FBRD_DIVFRAC_Pos                 0                      /*!< The fractional baud rate divisor */

/* Bit field masks: */
#define UART_FBRD_DIVFRAC_Msk                 0x0000003FUL           /*!< The fractional baud rate divisor */

/*--  LCRH: Line Control Register -----------------------------------------------------------------------------*/
typedef struct {
  uint32_t BRK                    :1;                                /*!< Send break */
  uint32_t PEN                    :1;                                /*!< Parity enable */
  uint32_t EPS                    :1;                                /*!< Even parity select */
  uint32_t STP2                   :1;                                /*!< Two stop bits select */
  uint32_t FEN                    :1;                                /*!< Enable FIFOs */
  uint32_t WLEN                   :2;                                /*!< Word length */
  uint32_t SPS                    :1;                                /*!< Stick parity select */
} _UART_LCRH_bits;

/* Bit field positions: */
#define UART_LCRH_BRK_Pos                     0                      /*!< Send break */
#define UART_LCRH_PEN_Pos                     1                      /*!< Parity enable */
#define UART_LCRH_EPS_Pos                     2                      /*!< Even parity select */
#define UART_LCRH_STP2_Pos                    3                      /*!< Two stop bits select */
#define UART_LCRH_FEN_Pos                     4                      /*!< Enable FIFOs */
#define UART_LCRH_WLEN_Pos                    5                      /*!< Word length */
#define UART_LCRH_SPS_Pos                     7                      /*!< Stick parity select */

/* Bit field masks: */
#define UART_LCRH_BRK_Msk                     0x00000001UL           /*!< Send break */
#define UART_LCRH_PEN_Msk                     0x00000002UL           /*!< Parity enable */
#define UART_LCRH_EPS_Msk                     0x00000004UL           /*!< Even parity select */
#define UART_LCRH_STP2_Msk                    0x00000008UL           /*!< Two stop bits select */
#define UART_LCRH_FEN_Msk                     0x00000010UL           /*!< Enable FIFOs */
#define UART_LCRH_WLEN_Msk                    0x00000060UL           /*!< Word length */
#define UART_LCRH_SPS_Msk                     0x00000080UL           /*!< Stick parity select */

/* Bit field enums: */
typedef enum {
  UART_LCRH_WLEN_5bit                        = 0x0UL,                /*!< 5 bit in informational word */
  UART_LCRH_WLEN_6bit                        = 0x1UL,                /*!< 6 bit in informational word */
  UART_LCRH_WLEN_7bit                        = 0x2UL,                /*!< 7 bit in informational word */
  UART_LCRH_WLEN_8bit                        = 0x3UL,                /*!< 8 bit in informational word */
} UART_LCRH_WLEN_Enum;

/*--  CR: Control Register ------------------------------------------------------------------------------------*/
typedef struct {
  uint32_t UARTEN                 :1;                                /*!< UART enable */
  uint32_t SIREN                  :1;                                /*!< Enable IrDA SIR ENDEC */
  uint32_t SIRLP                  :1;                                /*!< Enable SIR low-power IrDA mode */
  uint32_t                        :4;                                /*!< RESERVED */
  uint32_t LBE                    :1;                                /*!< Loopback enable */
  uint32_t TXE                    :1;                                /*!< Transmit enable */
  uint32_t RXE                    :1;                                /*!< Receive enable */
  uint32_t DTR                    :1;                                /*!< Data transmit ready */
  uint32_t RTS                    :1;                                /*!< Request to send */
  uint32_t                        :2;                                /*!< RESERVED */
  uint32_t RTSEN                  :1;                                /*!< RTS hardware flow control enable */
  uint32_t CTSEN                  :1;                                /*!< CTS hardware flow control enable */
} _UART_CR_bits;

/* Bit field positions: */
#define UART_CR_UARTEN_Pos                    0                      /*!< UART enable */
#define UART_CR_SIREN_Pos                     1                      /*!< Enable IrDA SIR ENDEC */
#define UART_CR_SIRLP_Pos                     2                      /*!< Enable SIR low-power IrDA mode */
#define UART_CR_LBE_Pos                       7                      /*!< Loopback enable */
#define UART_CR_TXE_Pos                       8                      /*!< Transmit enable */
#define UART_CR_RXE_Pos                       9                      /*!< Receive enable */
#define UART_CR_DTR_Pos                       10                     /*!< Data transmit ready */
#define UART_CR_RTS_Pos                       11                     /*!< Request to send */
#define UART_CR_RTSEN_Pos                     14                     /*!< RTS hardware flow control enable */
#define UART_CR_CTSEN_Pos                     15                     /*!< CTS hardware flow control enable */

/* Bit field masks: */
#define UART_CR_UARTEN_Msk                    0x00000001UL           /*!< UART enable */
#define UART_CR_SIREN_Msk                     0x00000002UL           /*!< Enable IrDA SIR ENDEC */
#define UART_CR_SIRLP_Msk                     0x00000004UL           /*!< Enable SIR low-power IrDA mode */
#define UART_CR_LBE_Msk                       0x00000080UL           /*!< Loopback enable */
#define UART_CR_TXE_Msk                       0x00000100UL           /*!< Transmit enable */
#define UART_CR_RXE_Msk                       0x00000200UL           /*!< Receive enable */
#define UART_CR_DTR_Msk                       0x00000400UL           /*!< Data transmit ready */
#define UART_CR_RTS_Msk                       0x00000800UL           /*!< Request to send */
#define UART_CR_RTSEN_Msk                     0x00004000UL           /*!< RTS hardware flow control enable */
#define UART_CR_CTSEN_Msk                     0x00008000UL           /*!< CTS hardware flow control enable */

/*--  IFLS: Interrupt FIFO Level Select Register --------------------------------------------------------------*/
typedef struct {
  uint32_t TXIFLSEL               :6;                                /*!< Transmit interrupt FIFO level select */
  uint32_t RXIFLSEL               :6;                                /*!< Receive interrupt FIFO level select */
} _UART_IFLS_bits;

/* Bit field positions: */
#define UART_IFLS_TXIFLSEL_Pos                0                      /*!< Transmit interrupt FIFO level select */
#define UART_IFLS_RXIFLSEL_Pos                6                      /*!< Receive interrupt FIFO level select */

/* Bit field masks: */
#define UART_IFLS_TXIFLSEL_Msk                0x0000003FUL           /*!< Transmit interrupt FIFO level select */
#define UART_IFLS_RXIFLSEL_Msk                0x00000FC0UL           /*!< Receive interrupt FIFO level select */

/* Bit field enums: */
typedef enum {
  UART_IFLS_TXIFLSEL_LVL18                   = 0x4UL,                /*!< interrupt on 1/8 */
  UART_IFLS_TXIFLSEL_LVL14                   = 0x8UL,                /*!< interrupt on 1/4 */
  UART_IFLS_TXIFLSEL_LVL12                   = 0x10UL,               /*!< interrupt on 1/2 */
  UART_IFLS_TXIFLSEL_LVL34                   = 0x18UL,               /*!< interrupt on 3/4 */
  UART_IFLS_TXIFLSEL_LVL78                   = 0x1CUL,               /*!< interrupt on 7/8 */
  UART_IFLS_TXIFLSEL_LVL88                   = 0x20UL,               /*!< interrupt on full fifo */
} UART_IFLS_TXIFLSEL_Enum;

typedef enum {
  UART_IFLS_RXIFLSEL_LVL18                   = 0x4UL,                /*!< interrupt on 1/8 */
  UART_IFLS_RXIFLSEL_LVL14                   = 0x8UL,                /*!< interrupt on 1/4 */
  UART_IFLS_RXIFLSEL_LVL12                   = 0x10UL,               /*!< interrupt on 1/2 */
  UART_IFLS_RXIFLSEL_LVL34                   = 0x18UL,               /*!< interrupt on 3/4 */
  UART_IFLS_RXIFLSEL_LVL78                   = 0x1CUL,               /*!< interrupt on 7/8 */
  UART_IFLS_RXIFLSEL_LVL88                   = 0x20UL,               /*!< interrupt on full fifo */
} UART_IFLS_RXIFLSEL_Enum;

/*--  IMSC: Interrupt Mask Set/Clear Register -----------------------------------------------------------------*/
typedef struct {
  uint32_t RIMIM                  :1;                                /*!< nUARTRI modem interrupt mask */
  uint32_t CTSMIM                 :1;                                /*!< nUARTCTS modem interrupt mask */
  uint32_t DCDMIM                 :1;                                /*!< nUARTDCD modem interrupt mask */
  uint32_t DSRMIM                 :1;                                /*!< nUARTDSR modem interrupt mask */
  uint32_t RXIM                   :1;                                /*!< Receive interrupt mask */
  uint32_t TXIM                   :1;                                /*!< Transmit interrupt mask */
  uint32_t RTIM                   :1;                                /*!< Receive timeout interrupt mask */
  uint32_t FERIM                  :1;                                /*!< Framing error interrupt mask */
  uint32_t PERIM                  :1;                                /*!< Parity error interrupt mask */
  uint32_t BERIM                  :1;                                /*!< Break error interrupt mask */
  uint32_t OERIM                  :1;                                /*!< Overrun error interrupt mask */
  uint32_t TDIM                   :1;                                /*!< Transmit done interrupt mask */
} _UART_IMSC_bits;

/* Bit field positions: */
#define UART_IMSC_RIMIM_Pos                   0                      /*!< nUARTRI modem interrupt mask */
#define UART_IMSC_CTSMIM_Pos                  1                      /*!< nUARTCTS modem interrupt mask */
#define UART_IMSC_DCDMIM_Pos                  2                      /*!< nUARTDCD modem interrupt mask */
#define UART_IMSC_DSRMIM_Pos                  3                      /*!< nUARTDSR modem interrupt mask */
#define UART_IMSC_RXIM_Pos                    4                      /*!< Receive interrupt mask */
#define UART_IMSC_TXIM_Pos                    5                      /*!< Transmit interrupt mask */
#define UART_IMSC_RTIM_Pos                    6                      /*!< Receive timeout interrupt mask */
#define UART_IMSC_FERIM_Pos                   7                      /*!< Framing error interrupt mask */
#define UART_IMSC_PERIM_Pos                   8                      /*!< Parity error interrupt mask */
#define UART_IMSC_BERIM_Pos                   9                      /*!< Break error interrupt mask */
#define UART_IMSC_OERIM_Pos                   10                     /*!< Overrun error interrupt mask */
#define UART_IMSC_TDIM_Pos                    11                     /*!< Transmit done interrupt mask */

/* Bit field masks: */
#define UART_IMSC_RIMIM_Msk                   0x00000001UL           /*!< nUARTRI modem interrupt mask */
#define UART_IMSC_CTSMIM_Msk                  0x00000002UL           /*!< nUARTCTS modem interrupt mask */
#define UART_IMSC_DCDMIM_Msk                  0x00000004UL           /*!< nUARTDCD modem interrupt mask */
#define UART_IMSC_DSRMIM_Msk                  0x00000008UL           /*!< nUARTDSR modem interrupt mask */
#define UART_IMSC_RXIM_Msk                    0x00000010UL           /*!< Receive interrupt mask */
#define UART_IMSC_TXIM_Msk                    0x00000020UL           /*!< Transmit interrupt mask */
#define UART_IMSC_RTIM_Msk                    0x00000040UL           /*!< Receive timeout interrupt mask */
#define UART_IMSC_FERIM_Msk                   0x00000080UL           /*!< Framing error interrupt mask */
#define UART_IMSC_PERIM_Msk                   0x00000100UL           /*!< Parity error interrupt mask */
#define UART_IMSC_BERIM_Msk                   0x00000200UL           /*!< Break error interrupt mask */
#define UART_IMSC_OERIM_Msk                   0x00000400UL           /*!< Overrun error interrupt mask */
#define UART_IMSC_TDIM_Msk                    0x00000800UL           /*!< Transmit done interrupt mask */

/*--  RIS: Raw Interrupt Status Register ----------------------------------------------------------------------*/
typedef struct {
  uint32_t RIRMIS                 :1;                                /*!< nUARTRI modem interrupt status */
  uint32_t CTSRMIS                :1;                                /*!< nUARTCTS modem interrupt status */
  uint32_t DCDRMIS                :1;                                /*!< nUARTDCD modem interrupt status */
  uint32_t DSRRMIS                :1;                                /*!< nUARTDSR modem interrupt status */
  uint32_t RXRIS                  :1;                                /*!< Receive interrupt status */
  uint32_t TXRIS                  :1;                                /*!< Transmit interrupt status */
  uint32_t RTRIS                  :1;                                /*!< Receive timeout interrupt status */
  uint32_t FERIS                  :1;                                /*!< Framing error interrupt status */
  uint32_t PERIS                  :1;                                /*!< Parity error interrupt status */
  uint32_t BERIS                  :1;                                /*!< Break error interrupt status */
  uint32_t OERIS                  :1;                                /*!< Overrun error interrupt status */
  uint32_t TDRIS                  :1;                                /*!< Transmit done raw interrupt status */
} _UART_RIS_bits;

/* Bit field positions: */
#define UART_RIS_RIRMIS_Pos                   0                      /*!< nUARTRI modem interrupt status */
#define UART_RIS_CTSRMIS_Pos                  1                      /*!< nUARTCTS modem interrupt status */
#define UART_RIS_DCDRMIS_Pos                  2                      /*!< nUARTDCD modem interrupt status */
#define UART_RIS_DSRRMIS_Pos                  3                      /*!< nUARTDSR modem interrupt status */
#define UART_RIS_RXRIS_Pos                    4                      /*!< Receive interrupt status */
#define UART_RIS_TXRIS_Pos                    5                      /*!< Transmit interrupt status */
#define UART_RIS_RTRIS_Pos                    6                      /*!< Receive timeout interrupt status */
#define UART_RIS_FERIS_Pos                    7                      /*!< Framing error interrupt status */
#define UART_RIS_PERIS_Pos                    8                      /*!< Parity error interrupt status */
#define UART_RIS_BERIS_Pos                    9                      /*!< Break error interrupt status */
#define UART_RIS_OERIS_Pos                    10                     /*!< Overrun error interrupt status */
#define UART_RIS_TDRIS_Pos                    11                     /*!< Transmit done raw interrupt status */

/* Bit field masks: */
#define UART_RIS_RIRMIS_Msk                   0x00000001UL           /*!< nUARTRI modem interrupt status */
#define UART_RIS_CTSRMIS_Msk                  0x00000002UL           /*!< nUARTCTS modem interrupt status */
#define UART_RIS_DCDRMIS_Msk                  0x00000004UL           /*!< nUARTDCD modem interrupt status */
#define UART_RIS_DSRRMIS_Msk                  0x00000008UL           /*!< nUARTDSR modem interrupt status */
#define UART_RIS_RXRIS_Msk                    0x00000010UL           /*!< Receive interrupt status */
#define UART_RIS_TXRIS_Msk                    0x00000020UL           /*!< Transmit interrupt status */
#define UART_RIS_RTRIS_Msk                    0x00000040UL           /*!< Receive timeout interrupt status */
#define UART_RIS_FERIS_Msk                    0x00000080UL           /*!< Framing error interrupt status */
#define UART_RIS_PERIS_Msk                    0x00000100UL           /*!< Parity error interrupt status */
#define UART_RIS_BERIS_Msk                    0x00000200UL           /*!< Break error interrupt status */
#define UART_RIS_OERIS_Msk                    0x00000400UL           /*!< Overrun error interrupt status */
#define UART_RIS_TDRIS_Msk                    0x00000800UL           /*!< Transmit done raw interrupt status */

/*--  MIS: Masked Interrupt Status Register -------------------------------------------------------------------*/
typedef struct {
  uint32_t RIMMIS                 :1;                                /*!< nUARTRI modem masked interrupt status */
  uint32_t CTSMMIS                :1;                                /*!< nUARTCTS modem masked interrupt status */
  uint32_t DCDMMIS                :1;                                /*!< nUARTDCD modem masked interrupt status */
  uint32_t DSRMMIS                :1;                                /*!< nUARTDSR modem masked interrupt status */
  uint32_t RXMIS                  :1;                                /*!< Receive masked interrupt status */
  uint32_t TXMIS                  :1;                                /*!< Transmit masked interrupt status */
  uint32_t RTMIS                  :1;                                /*!< Receive timeout masked interrupt status */
  uint32_t FEMIS                  :1;                                /*!< Framing error masked interrupt status */
  uint32_t PEMIS                  :1;                                /*!< Parity error masked interrupt status */
  uint32_t BEMIS                  :1;                                /*!< Break error masked interrupt status */
  uint32_t OEMIS                  :1;                                /*!< Overrun error masked interrupt status */
  uint32_t TDMIS                  :1;                                /*!< Transmit done masked interrupt status */
} _UART_MIS_bits;

/* Bit field positions: */
#define UART_MIS_RIMMIS_Pos                   0                      /*!< nUARTRI modem masked interrupt status */
#define UART_MIS_CTSMMIS_Pos                  1                      /*!< nUARTCTS modem masked interrupt status */
#define UART_MIS_DCDMMIS_Pos                  2                      /*!< nUARTDCD modem masked interrupt status */
#define UART_MIS_DSRMMIS_Pos                  3                      /*!< nUARTDSR modem masked interrupt status */
#define UART_MIS_RXMIS_Pos                    4                      /*!< Receive masked interrupt status */
#define UART_MIS_TXMIS_Pos                    5                      /*!< Transmit masked interrupt status */
#define UART_MIS_RTMIS_Pos                    6                      /*!< Receive timeout masked interrupt status */
#define UART_MIS_FEMIS_Pos                    7                      /*!< Framing error masked interrupt status */
#define UART_MIS_PEMIS_Pos                    8                      /*!< Parity error masked interrupt status */
#define UART_MIS_BEMIS_Pos                    9                      /*!< Break error masked interrupt status */
#define UART_MIS_OEMIS_Pos                    10                     /*!< Overrun error masked interrupt status */
#define UART_MIS_TDMIS_Pos                    11                     /*!< Transmit done masked interrupt status */

/* Bit field masks: */
#define UART_MIS_RIMMIS_Msk                   0x00000001UL           /*!< nUARTRI modem masked interrupt status */
#define UART_MIS_CTSMMIS_Msk                  0x00000002UL           /*!< nUARTCTS modem masked interrupt status */
#define UART_MIS_DCDMMIS_Msk                  0x00000004UL           /*!< nUARTDCD modem masked interrupt status */
#define UART_MIS_DSRMMIS_Msk                  0x00000008UL           /*!< nUARTDSR modem masked interrupt status */
#define UART_MIS_RXMIS_Msk                    0x00000010UL           /*!< Receive masked interrupt status */
#define UART_MIS_TXMIS_Msk                    0x00000020UL           /*!< Transmit masked interrupt status */
#define UART_MIS_RTMIS_Msk                    0x00000040UL           /*!< Receive timeout masked interrupt status */
#define UART_MIS_FEMIS_Msk                    0x00000080UL           /*!< Framing error masked interrupt status */
#define UART_MIS_PEMIS_Msk                    0x00000100UL           /*!< Parity error masked interrupt status */
#define UART_MIS_BEMIS_Msk                    0x00000200UL           /*!< Break error masked interrupt status */
#define UART_MIS_OEMIS_Msk                    0x00000400UL           /*!< Overrun error masked interrupt status */
#define UART_MIS_TDMIS_Msk                    0x00000800UL           /*!< Transmit done masked interrupt status */

/*--  ICR: Interrupt Clear Register ---------------------------------------------------------------------------*/
typedef struct {
  uint32_t RIMIC                  :1;                                /*!< nUARTRI modem interrupt clear */
  uint32_t CTSMIC                 :1;                                /*!< nUARTCTS modem interrupt clear */
  uint32_t DCDMIC                 :1;                                /*!< nUARTDCD modem interrupt clear */
  uint32_t DSRMIC                 :1;                                /*!< nUARTDSR modem interrupt clear */
  uint32_t RXIC                   :1;                                /*!< Receive interrupt clear */
  uint32_t TXIC                   :1;                                /*!< Transmit interrupt clear */
  uint32_t RTIC                   :1;                                /*!< Receive timeout interrupt clear */
  uint32_t FEIC                   :1;                                /*!< Framing error interrupt clear */
  uint32_t PEIC                   :1;                                /*!< Parity error interrupt clear */
  uint32_t BEIC                   :1;                                /*!< Break error interrupt clear */
  uint32_t OEIC                   :1;                                /*!< Overrun error interrupt clear */
  uint32_t TDIC                   :1;                                /*!< Transmit done interrupt clear */
} _UART_ICR_bits;

/* Bit field positions: */
#define UART_ICR_RIMIC_Pos                    0                      /*!< nUARTRI modem interrupt clear */
#define UART_ICR_CTSMIC_Pos                   1                      /*!< nUARTCTS modem interrupt clear */
#define UART_ICR_DCDMIC_Pos                   2                      /*!< nUARTDCD modem interrupt clear */
#define UART_ICR_DSRMIC_Pos                   3                      /*!< nUARTDSR modem interrupt clear */
#define UART_ICR_RXIC_Pos                     4                      /*!< Receive interrupt clear */
#define UART_ICR_TXIC_Pos                     5                      /*!< Transmit interrupt clear */
#define UART_ICR_RTIC_Pos                     6                      /*!< Receive timeout interrupt clear */
#define UART_ICR_FEIC_Pos                     7                      /*!< Framing error interrupt clear */
#define UART_ICR_PEIC_Pos                     8                      /*!< Parity error interrupt clear */
#define UART_ICR_BEIC_Pos                     9                      /*!< Break error interrupt clear */
#define UART_ICR_OEIC_Pos                     10                     /*!< Overrun error interrupt clear */
#define UART_ICR_TDIC_Pos                     11                     /*!< Transmit done interrupt clear */

/* Bit field masks: */
#define UART_ICR_RIMIC_Msk                    0x00000001UL           /*!< nUARTRI modem interrupt clear */
#define UART_ICR_CTSMIC_Msk                   0x00000002UL           /*!< nUARTCTS modem interrupt clear */
#define UART_ICR_DCDMIC_Msk                   0x00000004UL           /*!< nUARTDCD modem interrupt clear */
#define UART_ICR_DSRMIC_Msk                   0x00000008UL           /*!< nUARTDSR modem interrupt clear */
#define UART_ICR_RXIC_Msk                     0x00000010UL           /*!< Receive interrupt clear */
#define UART_ICR_TXIC_Msk                     0x00000020UL           /*!< Transmit interrupt clear */
#define UART_ICR_RTIC_Msk                     0x00000040UL           /*!< Receive timeout interrupt clear */
#define UART_ICR_FEIC_Msk                     0x00000080UL           /*!< Framing error interrupt clear */
#define UART_ICR_PEIC_Msk                     0x00000100UL           /*!< Parity error interrupt clear */
#define UART_ICR_BEIC_Msk                     0x00000200UL           /*!< Break error interrupt clear */
#define UART_ICR_OEIC_Msk                     0x00000400UL           /*!< Overrun error interrupt clear */
#define UART_ICR_TDIC_Msk                     0x00000800UL           /*!< Transmit done interrupt clear */

/*--  DMACR: DMA Control Register -----------------------------------------------------------------------------*/
typedef struct {
  uint32_t RXDMAE                 :1;                                /*!< Receive DMA enable */
  uint32_t TXDMAE                 :1;                                /*!< Transmit DMA enable */
  uint32_t DMAONERR               :1;                                /*!< DMA on error */
  uint32_t DMARXSTOP              :1;                                /*!< Automatic clear DMA RX request generation when channel ends all transactions */
  uint32_t DMATXSTOP              :1;                                /*!< Automatic clear DMA TX request generation when channel ends all transactions */
} _UART_DMACR_bits;

/* Bit field positions: */
#define UART_DMACR_RXDMAE_Pos                 0                      /*!< Receive DMA enable */
#define UART_DMACR_TXDMAE_Pos                 1                      /*!< Transmit DMA enable */
#define UART_DMACR_DMAONERR_Pos               2                      /*!< DMA on error */
#define UART_DMACR_DMARXSTOP_Pos              3                      /*!< Automatic clear DMA RX request generation when channel ends all transactions */
#define UART_DMACR_DMATXSTOP_Pos              4                      /*!< Automatic clear DMA TX request generation when channel ends all transactions */

/* Bit field masks: */
#define UART_DMACR_RXDMAE_Msk                 0x00000001UL           /*!< Receive DMA enable */
#define UART_DMACR_TXDMAE_Msk                 0x00000002UL           /*!< Transmit DMA enable */
#define UART_DMACR_DMAONERR_Msk               0x00000004UL           /*!< DMA on error */
#define UART_DMACR_DMARXSTOP_Msk              0x00000008UL           /*!< Automatic clear DMA RX request generation when channel ends all transactions */
#define UART_DMACR_DMATXSTOP_Msk              0x00000010UL           /*!< Automatic clear DMA TX request generation when channel ends all transactions */

typedef struct {
  union {                                                               /*!< Data Register */
    __IO uint32_t DR;                                                /*!< DR    : type used for word access */
    __IO _UART_DR_bits  DR_bit;                                      /*!< DR_bit: structure used for bit access */
  };
  union {                                                               /*!< Receive Status Register/Error Clear Register */
    __IO uint32_t RSR;                                               /*!< RSR    : type used for word access */
    __IO _UART_RSR_bits  RSR_bit;                                    /*!< RSR_bit: structure used for bit access */
  };
    __IO uint32_t Reserved0[4];
  union {                                                               /*!< Flag Register */
    __I uint32_t FR;                                                 /*!< FR    : type used for word access */
    __I _UART_FR_bits  FR_bit;                                       /*!< FR_bit: structure used for bit access */
  };
    __IO uint32_t Reserved1;
  union {                                                               /*!< IrDA Low-Power Counter Register */
    __IO uint32_t ILPR;                                              /*!< ILPR    : type used for word access */
    __IO _UART_ILPR_bits  ILPR_bit;                                  /*!< ILPR_bit: structure used for bit access */
  };
  union {                                                               /*!< Integer Baud Rate Register */
    __IO uint32_t IBRD;                                              /*!< IBRD    : type used for word access */
    __IO _UART_IBRD_bits  IBRD_bit;                                  /*!< IBRD_bit: structure used for bit access */
  };
  union {                                                               /*!< Fractional Baud Rate Register */
    __IO uint32_t FBRD;                                              /*!< FBRD    : type used for word access */
    __IO _UART_FBRD_bits  FBRD_bit;                                  /*!< FBRD_bit: structure used for bit access */
  };
  union {                                                               /*!< Line Control Register */
    __IO uint32_t LCRH;                                              /*!< LCRH    : type used for word access */
    __IO _UART_LCRH_bits  LCRH_bit;                                  /*!< LCRH_bit: structure used for bit access */
  };
  union {                                                               /*!< Control Register */
    __IO uint32_t CR;                                                /*!< CR    : type used for word access */
    __IO _UART_CR_bits  CR_bit;                                      /*!< CR_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt FIFO Level Select Register */
    __IO uint32_t IFLS;                                              /*!< IFLS    : type used for word access */
    __IO _UART_IFLS_bits  IFLS_bit;                                  /*!< IFLS_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt Mask Set/Clear Register */
    __IO uint32_t IMSC;                                              /*!< IMSC    : type used for word access */
    __IO _UART_IMSC_bits  IMSC_bit;                                  /*!< IMSC_bit: structure used for bit access */
  };
  union {                                                               /*!< Raw Interrupt Status Register */
    __I uint32_t RIS;                                                /*!< RIS    : type used for word access */
    __I _UART_RIS_bits  RIS_bit;                                     /*!< RIS_bit: structure used for bit access */
  };
  union {                                                               /*!< Masked Interrupt Status Register */
    __I uint32_t MIS;                                                /*!< MIS    : type used for word access */
    __I _UART_MIS_bits  MIS_bit;                                     /*!< MIS_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt Clear Register */
    __O uint32_t ICR;                                                /*!< ICR    : type used for word access */
    __O _UART_ICR_bits  ICR_bit;                                     /*!< ICR_bit: structure used for bit access */
  };
  union {                                                               /*!< DMA Control Register */
    __IO uint32_t DMACR;                                             /*!< DMACR    : type used for word access */
    __IO _UART_DMACR_bits  DMACR_bit;                                /*!< DMACR_bit: structure used for bit access */
  };
} UART_TypeDef;


/******************************************************************************/
/*                         TMR registers                                      */
/******************************************************************************/

/*--  CTRL: Timer control register ----------------------------------------------------------------------------*/
typedef struct {
  uint32_t FREESOFT               :2;                                /*!< Emulation mode bits - select the behavior of the time-base counter during emulation events */
  uint32_t CLR                    :1;                                /*!< Timer Clear */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t MODE                   :2;                                /*!< Count mode */
  uint32_t DMATXSTOP              :1;                                /*!< Stop Timer when TX DMA channel ends all transactions */
  uint32_t DMARXSTOP              :1;                                /*!< Stop Timer when RX DMA channel ends all transactions */
  uint32_t CLKSEL                 :1;                                /*!< Clock Source Select */
  uint32_t OUTEN                  :1;                                /*!< CAPCOM0 block output enable */
} _TMR_CTRL_bits;

/* Bit field positions: */
#define TMR_CTRL_FREESOFT_Pos                 0                      /*!< Emulation mode bits - select the behavior of the time-base counter during emulation events */
#define TMR_CTRL_CLR_Pos                      2                      /*!< Timer Clear */
#define TMR_CTRL_MODE_Pos                     4                      /*!< Count mode */
#define TMR_CTRL_DMATXSTOP_Pos                6                      /*!< Stop Timer when TX DMA channel ends all transactions */
#define TMR_CTRL_DMARXSTOP_Pos                7                      /*!< Stop Timer when RX DMA channel ends all transactions */
#define TMR_CTRL_CLKSEL_Pos                   8                      /*!< Clock Source Select */
#define TMR_CTRL_OUTEN_Pos                    9                      /*!< CAPCOM0 block output enable */

/* Bit field masks: */
#define TMR_CTRL_FREESOFT_Msk                 0x00000003UL           /*!< Emulation mode bits - select the behavior of the time-base counter during emulation events */
#define TMR_CTRL_CLR_Msk                      0x00000004UL           /*!< Timer Clear */
#define TMR_CTRL_MODE_Msk                     0x00000030UL           /*!< Count mode */
#define TMR_CTRL_DMATXSTOP_Msk                0x00000040UL           /*!< Stop Timer when TX DMA channel ends all transactions */
#define TMR_CTRL_DMARXSTOP_Msk                0x00000080UL           /*!< Stop Timer when RX DMA channel ends all transactions */
#define TMR_CTRL_CLKSEL_Msk                   0x00000100UL           /*!< Clock Source Select */
#define TMR_CTRL_OUTEN_Msk                    0x00000200UL           /*!< CAPCOM0 block output enable */

/* Bit field enums: */
typedef enum {
  TMR_CTRL_FREESOFT_StopAtCLK                = 0x0UL,                /*!< stop timer at next CLK tact */
  TMR_CTRL_FREESOFT_StopAtOverload           = 0x1UL,                /*!< stop timer when overload */
  TMR_CTRL_FREESOFT_NoStop                   = 0x2UL,                /*!< endless count */
} TMR_CTRL_FREESOFT_Enum;

typedef enum {
  TMR_CTRL_MODE_Stop                         = 0x0UL,                /*!< Timer is Stopped */
  TMR_CTRL_MODE_Up                           = 0x1UL,                /*!< Timer count Up */
  TMR_CTRL_MODE_Multiple                     = 0x2UL,                /*!< Timer count is multiple Up */
  TMR_CTRL_MODE_UpDown                       = 0x3UL,                /*!< Timer count is multiple Up - Down */
} TMR_CTRL_MODE_Enum;

typedef enum {
  TMR_CTRL_CLKSEL_SysClk                     = 0x0UL,                /*!< Select system Clk */
  TMR_CTRL_CLKSEL_ExtClk                     = 0x1UL,                /*!< Select External Clk */
} TMR_CTRL_CLKSEL_Enum;

/*--  COUNT: Current value timer register ---------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!< Current timer value */
} _TMR_COUNT_bits;

/* Bit field positions: */
#define TMR_COUNT_VAL_Pos                     0                      /*!< Current timer value */

/* Bit field masks: */
#define TMR_COUNT_VAL_Msk                     0xFFFFFFFFUL           /*!< Current timer value */

/*--  CLKDIV: Clock divider register --------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!<  */
} _TMR_CLKDIV_bits;

/* Bit field positions: */
#define TMR_CLKDIV_VAL_Pos                    0                      /*!<  */

/* Bit field masks: */
#define TMR_CLKDIV_VAL_Msk                    0xFFFFFFFFUL           /*!<  */

/*--  PERIOD: Timer period register ---------------------------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!<  */
} _TMR_PERIOD_bits;

/* Bit field positions: */
#define TMR_PERIOD_VAL_Pos                    0                      /*!<  */

/* Bit field masks: */
#define TMR_PERIOD_VAL_Msk                    0xFFFFFFFFUL           /*!<  */

/*--  IM: Interrupt mask register -----------------------------------------------------------------------------*/
typedef struct {
  uint32_t TMR                    :1;                                /*!< Timer Interrupt Enable */
  uint32_t CAPCOM0_0              :1;                                /*!< Capcom0 Interrupt Enable */
  uint32_t CAPCOM0_1              :1;                                /*!< Capcom1 Interrupt Enable */
} _TMR_IM_bits;

/* Bit field positions: */
#define TMR_IM_TMR_Pos                        0                      /*!< Timer Interrupt Enable */
#define TMR_IM_CAPCOM0_0_Pos                  1                      /*!< Capcom0 Interrupt Enable */
#define TMR_IM_CAPCOM0_1_Pos                  2                      /*!< Capcom1 Interrupt Enable */

/* Bit field masks: */
#define TMR_IM_TMR_Msk                        0x00000001UL           /*!< Timer Interrupt Enable */
#define TMR_IM_CAPCOM0_0_Msk                  0x00000002UL           /*!< Capcom0 Interrupt Enable */
#define TMR_IM_CAPCOM0_1_Msk                  0x00000004UL           /*!< Capcom1 Interrupt Enable */

/*--  RIS: Raw Interrupt Status register ----------------------------------------------------------------------*/
typedef struct {
  uint32_t TMR                    :1;                                /*!< Timer Interrupt Status */
  uint32_t CAPCOM0_0              :1;                                /*!< Capcom0 Interrupt Status */
  uint32_t CAPCOM0_1              :1;                                /*!< Capcom1 Interrupt Status */
} _TMR_RIS_bits;

/* Bit field positions: */
#define TMR_RIS_TMR_Pos                       0                      /*!< Timer Interrupt Status */
#define TMR_RIS_CAPCOM0_0_Pos                 1                      /*!< Capcom0 Interrupt Status */
#define TMR_RIS_CAPCOM0_1_Pos                 2                      /*!< Capcom1 Interrupt Status */

/* Bit field masks: */
#define TMR_RIS_TMR_Msk                       0x00000001UL           /*!< Timer Interrupt Status */
#define TMR_RIS_CAPCOM0_0_Msk                 0x00000002UL           /*!< Capcom0 Interrupt Status */
#define TMR_RIS_CAPCOM0_1_Msk                 0x00000004UL           /*!< Capcom1 Interrupt Status */

/*--  MIS: Masked Interrupt Status register -------------------------------------------------------------------*/
typedef struct {
  uint32_t TMR                    :1;                                /*!< Timer Interrupt Status */
  uint32_t CAPCOM0_0              :1;                                /*!< Capcom0 Interrupt Status */
  uint32_t CAPCOM0_1              :1;                                /*!< Capcom1 Interrupt Status */
} _TMR_MIS_bits;

/* Bit field positions: */
#define TMR_MIS_TMR_Pos                       0                      /*!< Timer Interrupt Status */
#define TMR_MIS_CAPCOM0_0_Pos                 1                      /*!< Capcom0 Interrupt Status */
#define TMR_MIS_CAPCOM0_1_Pos                 2                      /*!< Capcom1 Interrupt Status */

/* Bit field masks: */
#define TMR_MIS_TMR_Msk                       0x00000001UL           /*!< Timer Interrupt Status */
#define TMR_MIS_CAPCOM0_0_Msk                 0x00000002UL           /*!< Capcom0 Interrupt Status */
#define TMR_MIS_CAPCOM0_1_Msk                 0x00000004UL           /*!< Capcom1 Interrupt Status */

/*--  IC: Clear Interrupt Status register ---------------------------------------------------------------------*/
typedef struct {
  uint32_t TMR                    :1;                                /*!< Timer Interrupt Clear */
  uint32_t CAPCOM0_0              :1;                                /*!< Capcom0 Interrupt Clear */
  uint32_t CAPCOM0_1              :1;                                /*!< Capcom1 Interrupt Clear */
} _TMR_IC_bits;

/* Bit field positions: */
#define TMR_IC_TMR_Pos                        0                      /*!< Timer Interrupt Clear */
#define TMR_IC_CAPCOM0_0_Pos                  1                      /*!< Capcom0 Interrupt Clear */
#define TMR_IC_CAPCOM0_1_Pos                  2                      /*!< Capcom1 Interrupt Clear */

/* Bit field masks: */
#define TMR_IC_TMR_Msk                        0x00000001UL           /*!< Timer Interrupt Clear */
#define TMR_IC_CAPCOM0_0_Msk                  0x00000002UL           /*!< Capcom0 Interrupt Clear */
#define TMR_IC_CAPCOM0_1_Msk                  0x00000004UL           /*!< Capcom1 Interrupt Clear */

/*--  DMA_TXIM: DMA TX request mask register ------------------------------------------------------------------*/
typedef struct {
  uint32_t TMR                    :1;                                /*!< Timer DMA TX Request Enable */
  uint32_t CAPCOM0_0              :1;                                /*!< Capcom0 DMA TX Request Enable */
  uint32_t CAPCOM0_1              :1;                                /*!< Capcom1 DMA TX Request Enable */
} _TMR_DMA_TXIM_bits;

/* Bit field positions: */
#define TMR_DMA_TXIM_TMR_Pos                  0                      /*!< Timer DMA TX Request Enable */
#define TMR_DMA_TXIM_CAPCOM0_0_Pos            1                      /*!< Capcom0 DMA TX Request Enable */
#define TMR_DMA_TXIM_CAPCOM0_1_Pos            2                      /*!< Capcom1 DMA TX Request Enable */

/* Bit field masks: */
#define TMR_DMA_TXIM_TMR_Msk                  0x00000001UL           /*!< Timer DMA TX Request Enable */
#define TMR_DMA_TXIM_CAPCOM0_0_Msk            0x00000002UL           /*!< Capcom0 DMA TX Request Enable */
#define TMR_DMA_TXIM_CAPCOM0_1_Msk            0x00000004UL           /*!< Capcom1 DMA TX Request Enable */

/*--  DMA_RXIM: DMA RX request mask register ------------------------------------------------------------------*/
typedef struct {
  uint32_t TMR                    :1;                                /*!< Timer DMA RX Request Enable */
  uint32_t CAPCOM0_0              :1;                                /*!< Capcom0 DMA RX Request Enable */
  uint32_t CAPCOM0_1              :1;                                /*!< Capcom1 DMA RX Request Enable */
} _TMR_DMA_RXIM_bits;

/* Bit field positions: */
#define TMR_DMA_RXIM_TMR_Pos                  0                      /*!< Timer DMA RX Request Enable */
#define TMR_DMA_RXIM_CAPCOM0_0_Pos            1                      /*!< Capcom0 DMA RX Request Enable */
#define TMR_DMA_RXIM_CAPCOM0_1_Pos            2                      /*!< Capcom1 DMA RX Request Enable */

/* Bit field masks: */
#define TMR_DMA_RXIM_TMR_Msk                  0x00000001UL           /*!< Timer DMA RX Request Enable */
#define TMR_DMA_RXIM_CAPCOM0_0_Msk            0x00000002UL           /*!< Capcom0 DMA RX Request Enable */
#define TMR_DMA_RXIM_CAPCOM0_1_Msk            0x00000004UL           /*!< Capcom1 DMA RX Request Enable */

/*--  EXTEVT_IM: External Event mask register -----------------------------------------------------------------*/
typedef struct {
  uint32_t TMR                    :1;                                /*!< Timer External Event Request Enable */
  uint32_t CAPCOM0_0              :1;                                /*!< Capcom0 External Event Request Enable */
  uint32_t CAPCOM0_1              :1;                                /*!< Capcom1 External Event Request Enable */
} _TMR_EXTEVT_IM_bits;

/* Bit field positions: */
#define TMR_EXTEVT_IM_TMR_Pos                 0                      /*!< Timer External Event Request Enable */
#define TMR_EXTEVT_IM_CAPCOM0_0_Pos           1                      /*!< Capcom0 External Event Request Enable */
#define TMR_EXTEVT_IM_CAPCOM0_1_Pos           2                      /*!< Capcom1 External Event Request Enable */

/* Bit field masks: */
#define TMR_EXTEVT_IM_TMR_Msk                 0x00000001UL           /*!< Timer External Event Request Enable */
#define TMR_EXTEVT_IM_CAPCOM0_0_Msk           0x00000002UL           /*!< Capcom0 External Event Request Enable */
#define TMR_EXTEVT_IM_CAPCOM0_1_Msk           0x00000004UL           /*!< Capcom1 External Event Request Enable */

/*-- CAPCOM: CTRL: Capture / Compare Control register ---------------------------------------------------------*/
typedef struct {
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t OVF                    :1;                                /*!< Capture Overflow */
  uint32_t OUT                    :1;                                /*!< Output */
  uint32_t CCI                    :1;                                /*!< Capture / Compare Input */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t OUTMODE                :3;                                /*!< Output Mode */
  uint32_t CAP                    :1;                                /*!< Capture Mode */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t SCCI                   :1;                                /*!< Synchronized Capture / Compare Input */
  uint32_t                        :1;                                /*!< RESERVED */
  uint32_t CCISEL                 :2;                                /*!< Capture / Compare Input Select */
  uint32_t CAPMODE                :2;                                /*!< Capture Mode */
} _TMR_CAPCOM_CTRL_bits;

/* Bit field positions: */
#define TMR_CAPCOM_CTRL_OVF_Pos               1                      /*!< Capture Overflow */
#define TMR_CAPCOM_CTRL_OUT_Pos               2                      /*!< Output */
#define TMR_CAPCOM_CTRL_CCI_Pos               3                      /*!< Capture / Compare Input */
#define TMR_CAPCOM_CTRL_OUTMODE_Pos           5                      /*!< Output Mode */
#define TMR_CAPCOM_CTRL_CAP_Pos               8                      /*!< Capture Mode */
#define TMR_CAPCOM_CTRL_SCCI_Pos              10                     /*!< Synchronized Capture / Compare Input */
#define TMR_CAPCOM_CTRL_CCISEL_Pos            12                     /*!< Capture / Compare Input Select */
#define TMR_CAPCOM_CTRL_CAPMODE_Pos           14                     /*!< Capture Mode */

/* Bit field masks: */
#define TMR_CAPCOM_CTRL_OVF_Msk               0x00000002UL           /*!< Capture Overflow */
#define TMR_CAPCOM_CTRL_OUT_Msk               0x00000004UL           /*!< Output */
#define TMR_CAPCOM_CTRL_CCI_Msk               0x00000008UL           /*!< Capture / Compare Input */
#define TMR_CAPCOM_CTRL_OUTMODE_Msk           0x000000E0UL           /*!< Output Mode */
#define TMR_CAPCOM_CTRL_CAP_Msk               0x00000100UL           /*!< Capture Mode */
#define TMR_CAPCOM_CTRL_SCCI_Msk              0x00000400UL           /*!< Synchronized Capture / Compare Input */
#define TMR_CAPCOM_CTRL_CCISEL_Msk            0x00003000UL           /*!< Capture / Compare Input Select */
#define TMR_CAPCOM_CTRL_CAPMODE_Msk           0x0000C000UL           /*!< Capture Mode */

/*-- CAPCOM: VAL0: Capture/Compare Value 0 register -----------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!<  */
} _TMR_CAPCOM_VAL0_bits;

/* Bit field positions: */
#define TMR_CAPCOM_VAL0_VAL_Pos               0                      /*!<  */

/* Bit field masks: */
#define TMR_CAPCOM_VAL0_VAL_Msk               0xFFFFFFFFUL           /*!<  */

/*-- CAPCOM: VAL1: Capture/Compare Value 1 register -----------------------------------------------------------*/
typedef struct {
  uint32_t VAL                    :32;                               /*!<  */
} _TMR_CAPCOM_VAL1_bits;

/* Bit field positions: */
#define TMR_CAPCOM_VAL1_VAL_Pos               0                      /*!<  */

/* Bit field masks: */
#define TMR_CAPCOM_VAL1_VAL_Msk               0xFFFFFFFFUL           /*!<  */

//Cluster CAPCOM:
typedef struct {
  union {
  /*!< Capture / Compare Control register */
    __IO uint32_t CTRL;                                              /*!< CTRL : type used for word access */
    __IO _TMR_CAPCOM_CTRL_bits CTRL_bit;                             /*!< CTRL_bit: structure used for bit access */
  };
  union {
  /*!< Capture/Compare Value 0 register */
    __IO uint32_t VAL0;                                              /*!< VAL0 : type used for word access */
    __IO _TMR_CAPCOM_VAL0_bits VAL0_bit;                             /*!< VAL0_bit: structure used for bit access */
  };
  union {
  /*!< Capture/Compare Value 1 register */
    __IO uint32_t VAL1;                                              /*!< VAL1 : type used for word access */
    __IO _TMR_CAPCOM_VAL1_bits VAL1_bit;                             /*!< VAL1_bit: structure used for bit access */
  };
} _TMR_CAPCOM_TypeDef;
typedef struct {
  union {                                                               /*!< Timer control register */
    __IO uint32_t CTRL;                                              /*!< CTRL    : type used for word access */
    __IO _TMR_CTRL_bits  CTRL_bit;                                   /*!< CTRL_bit: structure used for bit access */
  };
  union {                                                               /*!< Current value timer register */
    __IO uint32_t COUNT;                                             /*!< COUNT    : type used for word access */
    __IO _TMR_COUNT_bits  COUNT_bit;                                 /*!< COUNT_bit: structure used for bit access */
  };
  union {                                                               /*!< Clock divider register */
    __IO uint32_t CLKDIV;                                            /*!< CLKDIV    : type used for word access */
    __IO _TMR_CLKDIV_bits  CLKDIV_bit;                               /*!< CLKDIV_bit: structure used for bit access */
  };
  union {                                                               /*!< Timer period register */
    __IO uint32_t PERIOD;                                            /*!< PERIOD    : type used for word access */
    __IO _TMR_PERIOD_bits  PERIOD_bit;                               /*!< PERIOD_bit: structure used for bit access */
  };
  union {                                                               /*!< Interrupt mask register */
    __IO uint32_t IM;                                                /*!< IM    : type used for word access */
    __IO _TMR_IM_bits  IM_bit;                                       /*!< IM_bit: structure used for bit access */
  };
  union {                                                               /*!< Raw Interrupt Status register */
    __I uint32_t RIS;                                                /*!< RIS    : type used for word access */
    __I _TMR_RIS_bits  RIS_bit;                                      /*!< RIS_bit: structure used for bit access */
  };
  union {                                                               /*!< Masked Interrupt Status register */
    __I uint32_t MIS;                                                /*!< MIS    : type used for word access */
    __I _TMR_MIS_bits  MIS_bit;                                      /*!< MIS_bit: structure used for bit access */
  };
  union {                                                               /*!< Clear Interrupt Status register */
    __O uint32_t IC;                                                 /*!< IC    : type used for word access */
    __O _TMR_IC_bits  IC_bit;                                        /*!< IC_bit: structure used for bit access */
  };
  union {                                                               /*!< DMA TX request mask register */
    __IO uint32_t DMA_TXIM;                                           /*!< DMA_TXIM    : type used for word access */
    __IO _TMR_DMA_TXIM_bits  DMA_TXIM_bit;                           /*!< DMA_TXIM_bit: structure used for bit access */
  };
  union {                                                               /*!< DMA RX request mask register */
    __IO uint32_t DMA_RXIM;                                           /*!< DMA_RXIM    : type used for word access */
    __IO _TMR_DMA_RXIM_bits  DMA_RXIM_bit;                           /*!< DMA_RXIM_bit: structure used for bit access */
  };
  union {                                                               /*!< External Event mask register */
    __IO uint32_t EXTEVT_IM;                                           /*!< EXTEVT_IM    : type used for word access */
    __IO _TMR_EXTEVT_IM_bits  EXTEVT_IM_bit;                         /*!< EXTEVT_IM_bit: structure used for bit access */
  };
    __IO uint32_t Reserved0[53];
  _TMR_CAPCOM_TypeDef CAPCOM[2];
} TMR_TypeDef;




/******************************************************************************/
/*                          Peripheral memory map                             */
/******************************************************************************/
#define GPIOA_BASE             (0x40000000UL)
#define GPIOB_BASE             (0x40001000UL)
#define CAN_BASE               (0x40010000UL)
#define CANMSG_BASE            (0x40011000UL)
#define ADC_BASE               (0x40020000UL)
#define DMA_BASE               (0x50000000UL)
#define FLASH_BASE             (0x50002000UL)
#define SIU_BASE               (0x50003000UL)
#define RCU_BASE               (0x50004000UL)
#define RTC_BASE               (0x50005000UL)
#define WDT_BASE               (0x50006000UL)
#define I2C_BASE               (0x50007000UL)
#define QEP_BASE               (0x50008000UL)
#define CAP0_BASE              (0x50009000UL)
#define CAP1_BASE              (0x5000A000UL)
#define CAP2_BASE              (0x5000B000UL)
#define PWM0_BASE              (0x5000C000UL)
#define PWM1_BASE              (0x5000D000UL)
#define PWM2_BASE              (0x5000E000UL)
#define SPI0_BASE              (0x5000F000UL)
#define SPI1_BASE              (0x50010000UL)
#define TMR0_BASE              (0x50011000UL)
#define TMR1_BASE              (0x50012000UL)
#define TMR2_BASE              (0x50013000UL)
#define TMR3_BASE              (0x50014000UL)
#define UART0_BASE             (0x50015000UL)
#define UART1_BASE             (0x50016000UL)

/******************************************************************************/
/*                          Peripheral declaration                            */
/******************************************************************************/
#define GPIOA                ((GPIO_TypeDef                *) GPIOA_BASE)
#define GPIOB                ((GPIO_TypeDef                *) GPIOB_BASE)
#define CAN                  ((CAN_TypeDef                 *) CAN_BASE)
#define CANMSG               ((CANMSG_TypeDef              *) CANMSG_BASE)
#define ADC                  ((ADC_TypeDef                 *) ADC_BASE)
#define DMA                  ((DMA_TypeDef                 *) DMA_BASE)
#define FLASH                ((FLASH_TypeDef               *) FLASH_BASE)
#define SIU                  ((SIU_TypeDef                 *) SIU_BASE)
#define RCU                  ((RCU_TypeDef                 *) RCU_BASE)
#define RTC                  ((RTC_TypeDef                 *) RTC_BASE)
#define WDT                  ((WDT_TypeDef                 *) WDT_BASE)
#define I2C                  ((I2C_TypeDef                 *) I2C_BASE)
#define QEP                  ((QEP_TypeDef                 *) QEP_BASE)
#define CAP0                 ((CAP_TypeDef                 *) CAP0_BASE)
#define CAP1                 ((CAP_TypeDef                 *) CAP1_BASE)
#define CAP2                 ((CAP_TypeDef                 *) CAP2_BASE)
#define PWM0                 ((PWM_TypeDef                 *) PWM0_BASE)
#define PWM1                 ((PWM_TypeDef                 *) PWM1_BASE)
#define PWM2                 ((PWM_TypeDef                 *) PWM2_BASE)
#define SPI0                 ((SPI_TypeDef                 *) SPI0_BASE)
#define SPI1                 ((SPI_TypeDef                 *) SPI1_BASE)
#define TMR0                 ((TMR_TypeDef                 *) TMR0_BASE)
#define TMR1                 ((TMR_TypeDef                 *) TMR1_BASE)
#define TMR2                 ((TMR_TypeDef                 *) TMR2_BASE)
#define TMR3                 ((TMR_TypeDef                 *) TMR3_BASE)
#define UART0                ((UART_TypeDef                *) UART0_BASE)
#define UART1                ((UART_TypeDef                *) UART1_BASE)

/******************************************************************************/
/*                          Peripheral capabilities                           */
/******************************************************************************/
#define GPIO_PRESENT
#define GPIO_TOTAL    2
typedef enum {
  GPIOA_Num,
  GPIOB_Num
} GPIO_Num_TypeDef;

#define CAN_PRESENT
#define CAN_TOTAL     1
typedef enum {
  CAN_Num
} CAN_Num_TypeDef;

#define CANMSG_PRESENT
#define CANMSG_TOTAL  1
typedef enum {
  CANMSG_Num
} CANMSG_Num_TypeDef;

#define ADC_PRESENT
#define ADC_TOTAL     1
typedef enum {
  ADC_Num
} ADC_Num_TypeDef;

#define DMA_PRESENT
#define DMA_TOTAL     1
typedef enum {
  DMA_Num
} DMA_Num_TypeDef;

#define FLASH_PRESENT
#define FLASH_TOTAL   1
typedef enum {
  FLASH_Num
} FLASH_Num_TypeDef;

#define SIU_PRESENT
#define SIU_TOTAL     1
typedef enum {
  SIU_Num
} SIU_Num_TypeDef;

#define RCU_PRESENT
#define RCU_TOTAL     1
typedef enum {
  RCU_Num
} RCU_Num_TypeDef;

#define RTC_PRESENT
#define RTC_TOTAL     1
typedef enum {
  RTC_Num
} RTC_Num_TypeDef;

#define WDT_PRESENT
#define WDT_TOTAL     1
typedef enum {
  WDT_Num
} WDT_Num_TypeDef;

#define I2C_PRESENT
#define I2C_TOTAL     1
typedef enum {
  I2C_Num
} I2C_Num_TypeDef;

#define QEP_PRESENT
#define QEP_TOTAL     1
typedef enum {
  QEP_Num
} QEP_Num_TypeDef;

#define CAP_PRESENT
#define CAP_TOTAL     3
typedef enum {
  CAP0_Num,
  CAP1_Num,
  CAP2_Num
} CAP_Num_TypeDef;

#define PWM_PRESENT
#define PWM_TOTAL     3
typedef enum {
  PWM0_Num,
  PWM1_Num,
  PWM2_Num
} PWM_Num_TypeDef;

#define SPI_PRESENT
#define SPI_TOTAL     2
typedef enum {
  SPI0_Num,
  SPI1_Num
} SPI_Num_TypeDef;

#define TMR_PRESENT
#define TMR_TOTAL     4
typedef enum {
  TMR0_Num,
  TMR1_Num,
  TMR2_Num,
  TMR3_Num
} TMR_Num_TypeDef;

#define UART_PRESENT
#define UART_TOTAL    2
typedef enum {
  UART0_Num,
  UART1_Num
} UART_Num_TypeDef;

/******************************************************************************/
/*                          Peripheral assertions                             */
/******************************************************************************/
#define IS_GPIO_PERIPH(PERIPH)                   (((PERIPH) == GPIOA) || \
                                                  ((PERIPH) == GPIOB))
#define IS_CAN_PERIPH(PERIPH)                    (((PERIPH) == CAN))
#define IS_CANMSG_PERIPH(PERIPH)                 (((PERIPH) == CANMSG))
#define IS_ADC_PERIPH(PERIPH)                    (((PERIPH) == ADC))
#define IS_DMA_PERIPH(PERIPH)                    (((PERIPH) == DMA))
#define IS_FLASH_PERIPH(PERIPH)                  (((PERIPH) == FLASH))
#define IS_SIU_PERIPH(PERIPH)                    (((PERIPH) == SIU))
#define IS_RCU_PERIPH(PERIPH)                    (((PERIPH) == RCU))
#define IS_RTC_PERIPH(PERIPH)                    (((PERIPH) == RTC))
#define IS_WDT_PERIPH(PERIPH)                    (((PERIPH) == WDT))
#define IS_I2C_PERIPH(PERIPH)                    (((PERIPH) == I2C))
#define IS_QEP_PERIPH(PERIPH)                    (((PERIPH) == QEP))
#define IS_CAP_PERIPH(PERIPH)                    (((PERIPH) == CAP0) || \
                                                  ((PERIPH) == CAP1) || \
                                                  ((PERIPH) == CAP2))
#define IS_PWM_PERIPH(PERIPH)                    (((PERIPH) == PWM0) || \
                                                  ((PERIPH) == PWM1) || \
                                                  ((PERIPH) == PWM2))
#define IS_SPI_PERIPH(PERIPH)                    (((PERIPH) == SPI0) || \
                                                  ((PERIPH) == SPI1))
#define IS_TMR_PERIPH(PERIPH)                    (((PERIPH) == TMR0) || \
                                                  ((PERIPH) == TMR1) || \
                                                  ((PERIPH) == TMR2) || \
                                                  ((PERIPH) == TMR3))
#define IS_UART_PERIPH(PERIPH)                   (((PERIPH) == UART0) || \
                                                  ((PERIPH) == UART1))

#ifdef __cplusplus
}
#endif

#endif /* __K1921VG5T_H */

/************************** (C) COPYRIGHT 2025 NIIET ***************************
*
* END OF FILE K1921VG5T.h */
