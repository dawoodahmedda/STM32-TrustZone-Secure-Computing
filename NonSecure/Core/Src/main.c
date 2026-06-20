#include "main.h"

/* Reference connection directly linking to the Secure NSC Veneer table */
extern uint32_t SECURE_SignMessage(uint32_t *pInput, uint32_t *pOutput);

/* 128-bit plain message block allocated inside ordinary Non-Secure RAM */
uint32_t LivePlaintext[4]  = {0x84331485, 0x22876120, 0x82533392, 0x37617027};
volatile uint32_t LiveCiphertext[4] = {0, 0, 0, 0};

int main(void)
{
  /* Initialize the Non-Secure Core Hardware Layer */
  HAL_Init();

  while (1)
  {
    /* 1. Pet/Refresh the internal Window Watchdog to completely bypass the hardware trap */
    WRITE_REG(WWDG->CR, 0x7F);

    /* 2. Trigger the secure signature calculation */
    SECURE_SignMessage(LivePlaintext, (uint32_t *)LiveCiphertext);

    /* 3. Keep the pipeline delay small so the watchdog doesn't starve */
    for (volatile uint32_t delay_timer = 0; delay_timer < 500; delay_timer++);
  }
}
