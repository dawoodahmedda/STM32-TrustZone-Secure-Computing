/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gtzc_s.c
  * @brief   This file provides code for the configuration
  * of the GTZC_S instances.
  ******************************************************************************
  */
/* USER CODE END Header */
#include "gtzc_s.h"

/**
  * @brief  Initializes the Security Controller attributes.
  * @retval None
  */
void MX_GTZC_S_Init(void)
{
  MPCBB_ConfigTypeDef MPCBB_Area_Desc = {0};

  /* Assign RNG engine explicitly to the secure computing domain context execution paths */
  HAL_GTZC_TZSC_ConfigPeriphAttributes(GTZC_PERIPH_RNG, GTZC_TZSC_PERIPH_SEC|GTZC_TZSC_PERIPH_NPRIV);

  /* Configure target memory execution maps boundaries */
  MPCBB_Area_Desc.SecureRWIllegalMode = GTZC_MPCBB_SRWILADIS_ENABLE;
  MPCBB_Area_Desc.InvertSecureState = GTZC_MPCBB_INVSECSTATE_NOT_INVERTED;
  MPCBB_Area_Desc.AttributeConfig.MPCBB_SecConfig_array[0] = 0xFFFFFFFF;
  MPCBB_Area_Desc.AttributeConfig.MPCBB_SecConfig_array[1] = 0xFFFFFFFF;

  HAL_GTZC_MPCBB_ConfigMem(SRAM1_BASE, &MPCBB_Area_Desc);
  HAL_GTZC_MPCBB_ConfigMem(SRAM2_BASE, &MPCBB_Area_Desc);
}
