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

  /* We leave this empty because your hardware Option Bytes and your
     partition_stm32wba55xx.h (SAU) files are already perfectly handling
     the RAM and Flash boundary segregation.

     Since the RNG peripheral executes safely inside the Secure World,
     no extra peripheral unprotect overrides are required here. */
}
