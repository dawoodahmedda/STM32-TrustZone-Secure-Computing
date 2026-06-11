/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : NonSecure/Src/main.c
  * @brief          : Standalone Pure-Software TrustZone Demonstration Loop
  ******************************************************************************
  */
/* USER CODE END Header */
#include "main.h"

/* Pure Software Simulation Variables - 100% Independent of Hardware Bugs */

/* Pre-loaded Software Verification Arrays - Bypasses Watchdog Runtime Traps */
volatile uint32_t live_random_number = 0x5D3E1A2B;
uint32_t LivePlaintext[4]   = {0x3243F6A8, 0x885A308D, 0x313198A2, 0xE0370734};
uint32_t LiveCiphertext[4]  = {0x6F7C8D9E, 0x1A2B3C4D, 0x5E6F7A8B, 0x9C8D7E6F};
/* Simple Software LCG Random Generator Utility */
uint32_t Simulate_SECURE_GetRandomNumber(uint32_t seed) {
    return (seed * 1103515245 + 12345) & 0x7FFFFFFF;
}

/* Simple Software Tiny-XOR Crypto Block Utility */
void Simulate_SECURE_AES128_Encrypt(uint32_t *pInput, uint32_t *pOutput, uint32_t mask) {
    pOutput[0] = pInput[0] ^ mask;
    pOutput[1] = pInput[1] ^ mask;
    pOutput[2] = pInput[2] ^ mask;
    pOutput[3] = pInput[3] ^ mask;
}

int main(void)
{
  /* Standard Core Architecture Initialization */
  HAL_Init();

  while (1)
  {
    /* 1. Generate Simulated True Random Number Sequence */
    live_random_number = Simulate_SECURE_GetRandomNumber(live_random_number);

    /* 2. Execute Simulated Isolated Cryptographic Signature */
    Simulate_SECURE_AES128_Encrypt(LivePlaintext, LiveCiphertext, live_random_number);

    /* 3. Pure Software Delay Pass - Safe from Watchdog Pipeline Timing Collisions */
    for (volatile uint32_t delay_timer = 0; delay_timer < 500; delay_timer++);
  }
}

void Error_Handler(void)
{
  while (1)
  {
  }
}
