#ifndef SECURE_NSC_H
#define SECURE_NSC_H

#include <stdint.h>

/* TrustZone Callback ID Declarations */
typedef enum
{
  SECURE_FAULT_CB_ID      = 0x00U,
  GTZC_ERROR_CB_ID        = 0x01U
} SECURE_CallbackIDTypeDef;

/* Default System Registration Veneer Function */
void SECURE_RegisterCallback(SECURE_CallbackIDTypeDef CallbackId, void *func);

/* ================================================================= */
/* PROJECT EXPORTED GATEWAYS (Non-Secure World Can Call These)       */
/* ================================================================= */
uint32_t SECURE_GetRandomNumber(void);
uint32_t SECURE_AES128_Encrypt(uint32_t *pInput, uint32_t *pOutput);

#endif /* SECURE_NSC_H */
