#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

GPIO_InitTypeDef GPIO_InitStruct;  // Konfigürasyonlar için Structer

void GPIO_CONFIG()	//GPIO pin konfigürasyonlarý için gerekli fonksiyon
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);	// GPIOD için AHB1 aktif edildi

	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15; // Kullanýlacak pinler tanýmlandý
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT; 		 // Pin modu çýkýþ olarak seçildi
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP; 	 // Durumu push-pull olarak seçildi
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;    // No-pull seçimi yapýldý
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;	 // Hýz olarak 100Mhz kullanýlýyor.

	GPIO_Init(GPIOD, &GPIO_InitStruct);				 // Gerekli konfigürasyonlar GPIOD portuna atandý
}

int main(void)
{
	GPIO_CONFIG();  // GPIO_CONFIG fonksiyonu çaðrýldý.
  while (1)
  {
	  GPIO_SetBits(GPIOD, GPIO_Pin_12);	// GPIO_SetBits Fonksiyonu ile pine lojik 1 verildi.
	  GPIO_SetBits(GPIOD, GPIO_Pin_13);	// GPIO_SetBits Fonksiyonu ile pine lojik 1 verildi.
	  GPIO_SetBits(GPIOD, GPIO_Pin_14);	// GPIO_SetBits Fonksiyonu ile pine lojik 1 verildi.
	  GPIO_SetBits(GPIOD, GPIO_Pin_15);	// GPIO_SetBits Fonksiyonu ile pine lojik 1 verildi.

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
