/**
  ******************************************************************************
  * @file    stm32wbaxx_hal_gtzc.h
  * @author  MCD Application Team
  * @brief   Header file of GTZC HAL module.
  ******************************************************************************
  */

#ifndef STM32WBAxx_HAL_GTZC_H
#define STM32WBAxx_HAL_GTZC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32wbaxx_hal_def.h"

/** @addtogroup STM32WBAxx_HAL_Driver
  * @{
  */

/** @addtogroup GTZC
  * @{
  */

/* Exported types ------------------------------------------------------------*/
typedef struct
{
  uint32_t MPCBB_SecConfig_array[4];
  uint32_t MPCBB_PrivConfig_array[4];
  uint32_t MPCBB_LockConfig_array[1];
} GTZC_MPCBB_AttributeTypeDef;

typedef struct
{
  uint32_t SecureRWIllegalMode;
  uint32_t InvertSecureState;
  GTZC_MPCBB_AttributeTypeDef AttributeConfig;
} MPCBB_ConfigTypeDef;

/* Exported constants --------------------------------------------------------*/
#define GTZC_MPCBB_SRWILADIS_DISABLE      0x00000000U
#define GTZC_MPCBB_SRWILADIS_ENABLE       GTZC_MPCBB_CR_SRWILADIS_Msk

#define GTZC_MPCBB_INVSECSTATE_NOT_INVERTED 0x00000000U
#define GTZC_MPCBB_INVSECSTATE_INVERTED     GTZC_MPCBB_CR_INVSECSTATE_Msk

#define GTZC_TZSC_PERIPH_NSEC             0x00000001U
#define GTZC_TZSC_PERIPH_SEC              0x00000002U
#define GTZC_TZSC_PERIPH_NPRIV            0x00000004U
#define GTZC_TZSC_PERIPH_PRIV             0x00000008U

/* Exported functions --------------------------------------------------------*/
HAL_StatusTypeDef HAL_GTZC_TZSC_ConfigPeriphAttributes(uint32_t PeripheralId, uint32_t Attributes);
HAL_StatusTypeDef HAL_GTZC_MPCBB_ConfigMem(uint32_t MemBaseAddress, MPCBB_ConfigTypeDef *pMPCBB_Config);

#ifdef __cplusplus
}
#endif

#endif /* STM32WBAxx_HAL_GTZC_H */
