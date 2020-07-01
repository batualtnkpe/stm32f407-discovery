#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

void CLK_Config() // Clock konfigürasyonlarý için CLK_Config fonksiyonu oluþturuldu.
{
	RCC->CR |= 0x00030000; //HSEON ve HSEONRDY Enable
	while(!(RCC->CR &  0x00020000)); // HSEON Ready Flag wait
	RCC->CR |= 0x00080000; //CSS Enable
	RCC->PLLCFGR |= 0x00400000; //PLL'e HSE seçildi
	RCC->PLLCFGR |= 0x00000004; //PLL M 4 seçildi
	RCC->PLLCFGR |= 0x00005A00; //PLL N 168 seçildi
	RCC->PLLCFGR |= 0x00000000; //PLL P 2 seçildi
	RCC->CFGR |= 0x00000000;	// AHB Prescaler 1 oldu
	RCC->CFGR |= 0x00080000;	// APB2 Prescaler 2 oldu
	RCC->CFGR |= 0x00001400;	// APB1 Prescaler 4 oldu
	RCC->CIR  |= 0x00080000;	// HSERDY Flag Clear
	RCC->CIR  |= 0x00800000;	// CSS Flag Clear

	RCC->AHB1ENR = 0x00000008;  // GPIOA AKTÝF EDÝLDÝ

	GPIOD->MODER = 0x55000000;  // 12 13 14 15. LEDLER ÝÇÝN OUTPUT MOD
	GPIOD->OTYPER = 0x00000000; // PUSH PULL SEÇÝLDÝ
	GPIOD->OSPEEDR = 0xFF000000; //100MHZ Frekans
	GPIOD->PUPDR = 0x00000000;  // NO PULL TANIMLANDI

}
void delay(uint32_t time) //Delay fonksiyonu oluþturuldu(32bit)
{
	while(time--); //Time 0 olana kadar devam ediyor.

}
int main(void)
{
	CLK_Config(); // Clock Fonksiyonu çaðrýldý.
  while (1)
  {
	  GPIOD->ODR = 0x0000F000; //GPIOD 12 13 14 15 ÇIKIÞ AKTÝF
	  delay(16800000);
	  GPIOD->ODR = 0x00000000; //GPIOD 12 13 14 15 ÇIKIÞ PASÝF
	  delay(16800000);
  }
}



void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size)
{
  /* TODO, implement your code here */
  return;
}

uint16_t EVAL_AUDIO_GetSampleCallBack(void)
{
  /* TODO, implement your code here */
  return -1;
}
