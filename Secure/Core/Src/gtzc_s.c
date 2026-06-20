/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gtzc_s.c
  * @brief   This file provides code for the configuration
  * of the GTZC_S instances.
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/**
  * @brief GTZC_S Initialization Function
  * @param None
  * @retval None
  */
void MX_GTZC_S_Init(void)
{
  /* --- NATIVE STM32WBA GTZC SECURITY INITIALIZATION --- */

  /* On the STM32WBA, the TZSC function only accepts 2 parameters.
     We explicitly allow the Non-Secure world to access the RNG peripheral registers
     so that the core handles multi-world clock gating without throwing security exceptions. */
  if (HAL_GTZC_TZSC_ConfigPeriphAttributes(GTZC_PERIPH_RNG, GTZC_TZSC_PERIPH_NON_SECURE) != HAL_OK)
  {
    Error_Handler();
  }
}
