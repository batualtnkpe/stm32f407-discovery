#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

GPIO_InitTypeDef GPIO_InitStruct;							//GPIO Pin Konfig�rasyonlar� ��in Structer Olu�turuldu

void GPIO_Config()											//GPIO Pin Konfig�rasyonlar� ��in Fonksiyon Olu�turuldu
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);	// RCCAHB1_Clock Hatt�na Ba�l� Olan GPIOA Hatt� Aktif Edildi
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);	// RCCAHB1_Clock Hatt�na Ba�l� Olan GPIOD Hatt� Aktif Edildi

	GPIO_InitStruct.GPIO_Mode = 0x00;						// Giri� Modu Se�ildi
	GPIO_InitStruct.GPIO_OType = 0x00;						// Push-Pull Se�ildi
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;					// 0. Pin Aktif Edildi
	GPIO_InitStruct.GPIO_PuPd =	0x02;						// Pull-Down Se�ildi
	GPIO_InitStruct.GPIO_Speed = 0x03;						// 100Mhz H�z Se�ildi

	GPIO_Init(GPIOA, &GPIO_InitStruct);						// Yap�lan Konfig�rasyonlar GPIOA Portuna Atand�

	GPIO_InitStruct.GPIO_Mode = 0x01;						// ��k�� Modu Se�ildi
	GPIO_InitStruct.GPIO_OType = 0x00;						// Push-Pull Se�ildi
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12 |GPIO_Pin_13 |GPIO_Pin_14 |GPIO_Pin_15;		//12-13-14 ve 15. pinler aktif edildi.
	GPIO_InitStruct.GPIO_PuPd =	0x00;						// No-Pull Se�ildi
	GPIO_InitStruct.GPIO_Speed = 0x03;						// 100Mhz H�z Se�ildi

	GPIO_Init(GPIOD, &GPIO_InitStruct);						// Yap�lan Konfig�rasyonlar GPIOD Portuna Atand�

}
void delay(uint32_t time)									// Delay Fonksiyonu(32bit)
{
	while(time--);											// Time de�i�keni 0 olana kadar devam ediyor
}
int main(void)
{
	GPIO_Config();											// GPIO Konfig�rasyon Fonksiyonu �a�r�ld�

  while (1)
  {

	  if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0))			// GPIOA Portunun 0. Pinine Ba�l� Olan Butondan Gelen Veri Bit D�zeyinde Okundu
	  {
		  while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0));	// GPIOA Portunun 0. Pinine Ba�l� Olan Butondan Hala Veri Geliyor mu Kontrol Edildi
		  delay(1680000);									// Delay Fonksiyonu
		  GPIO_ToggleBits(GPIOD, GPIO_Pin_12 |GPIO_Pin_13 |GPIO_Pin_14 |GPIO_Pin_15);	// GPIO ToggleBits Fonksiyonu ile 12-13-14 ve 15. Ledlerin Durumu Bir �ncekinin Tersine D�nderildi
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
