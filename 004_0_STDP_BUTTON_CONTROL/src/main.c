#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

GPIO_InitTypeDef GPIO_InitStruct;							//GPIO Pin Konfigürasyonlarý Ýçin Structer Oluþturuldu

void GPIO_Config()											//GPIO Pin Konfigürasyonlarý Ýçin Fonksiyon Oluþturuldu
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);	// RCCAHB1_Clock Hattýna Baðlý Olan GPIOA Hattý Aktif Edildi
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);	// RCCAHB1_Clock Hattýna Baðlý Olan GPIOD Hattý Aktif Edildi

	GPIO_InitStruct.GPIO_Mode = 0x00;						// Giriþ Modu Seçildi
	GPIO_InitStruct.GPIO_OType = 0x00;						// Push-Pull Seçildi
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;					// 0. Pin Aktif Edildi
	GPIO_InitStruct.GPIO_PuPd =	0x02;						// Pull-Down Seçildi
	GPIO_InitStruct.GPIO_Speed = 0x03;						// 100Mhz Hýz Seçildi

	GPIO_Init(GPIOA, &GPIO_InitStruct);						// Yapýlan Konfigürasyonlar GPIOA Portuna Atandý

	GPIO_InitStruct.GPIO_Mode = 0x01;						// Çýkýþ Modu Seçildi
	GPIO_InitStruct.GPIO_OType = 0x00;						// Push-Pull Seçildi
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12 |GPIO_Pin_13 |GPIO_Pin_14 |GPIO_Pin_15;		//12-13-14 ve 15. pinler aktif edildi.
	GPIO_InitStruct.GPIO_PuPd =	0x00;						// No-Pull Seçildi
	GPIO_InitStruct.GPIO_Speed = 0x03;						// 100Mhz Hýz Seçildi

	GPIO_Init(GPIOD, &GPIO_InitStruct);						// Yapýlan Konfigürasyonlar GPIOD Portuna Atandý

}
void delay(uint32_t time)									// Delay Fonksiyonu(32bit)
{
	while(time--);											// Time deðiþkeni 0 olana kadar devam ediyor
}
int main(void)
{
	GPIO_Config();											// GPIO Konfigürasyon Fonksiyonu Çaðrýldý

  while (1)
  {

	  if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0))			// GPIOA Portunun 0. Pinine Baðlý Olan Butondan Gelen Veri Bit Düzeyinde Okundu
	  {
		  while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0));	// GPIOA Portunun 0. Pinine Baðlý Olan Butondan Hala Veri Geliyor mu Kontrol Edildi
		  delay(1680000);									// Delay Fonksiyonu
		  GPIO_ToggleBits(GPIOD, GPIO_Pin_12 |GPIO_Pin_13 |GPIO_Pin_14 |GPIO_Pin_15);	// GPIO ToggleBits Fonksiyonu ile 12-13-14 ve 15. Ledlerin Durumu Bir Öncekinin Tersine Dönderildi
	  }

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
