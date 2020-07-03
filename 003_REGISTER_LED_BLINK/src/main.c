#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

void GPIO_CONFIG() //GPIO Pin Konfigürasyon Fonksiyonu
{
	RCC->AHB1ENR = 0x00000008;   //GPIOD aktif edildi(Register ile)

	GPIOD->MODER = 0x55000000;   //GPIOD çýkýþ modu seçildi(Register ile)
	GPIOD->OTYPER = 0x00000000;  //GPIOD opendrain seçildi(Register ile)
	GPIOD->PUPDR = 0x00000000;   //GPIOD nu-pull seçildi(Register ile)
	GPIOD->OSPEEDR = 0xFF000000; //Hýz olarak 100MHz seçildi(Register ile)

}
void delay(uint32_t time)        // Delay Fonksiyonu(32bit)
{
	while(time--);				 // Time deðiþkeni 0 olana kadar devam ediyor.
}

int main(void)
{
	GPIO_CONFIG();				// GPIO Pin Konfigürasyon Fonksiyonu Çaðrýldý

  while (1)
  {

	  GPIOD->ODR = 0x0000F000;	//GPIO Pinlerine Lojik 1 verildi(Register ile)
	  delay(16800000);			// Delay Fonksiyonu
	  GPIOD->ODR = 0x00000000;  //GPIO Pinlerine Lojik 0 verildi(Register ile)
	  delay(16800000);			// Delay Fonksiyonu
  }
}



void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}


uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
