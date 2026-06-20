#ifndef SECURE_NSC_H
#define SECURE_NSC_H

#include <stdint.h>

/* SECURE callback ID enumeration definitions */
typedef enum
{
  SECURE_FAULT_CB_ID = 0x00U,
  GTZC_ERROR_CB_ID   = 0x01U
} SECURE_CallbackIDTypeDef;

void SECURE_RegisterCallback(SECURE_CallbackIDTypeDef CallbackId, void *func);

/* Unified secure signature interface definition */
uint32_t SECURE_SignMessage(uint32_t *pInput, uint32_t *pOutput);

#endif /* SECURE_NSC_H */
