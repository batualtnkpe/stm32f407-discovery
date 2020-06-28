#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

int count = 0;  //Sayma i�in bir de�i�ken

GPIO_InitTypeDef GPIO_InitStruct; // Konfig�rasyonlar i�in Structer

void GPIO_Config()  //GPIO pin konfig�rasyonlar� i�in gerekli fonksiyon
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE); // GPIOB i�in AHB1 aktif edildi
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE); // GPIOD i�in AHB1 aktif edildi

	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_1;  // Kullan�lacak pin tan�mland�
	GPIO_InitStruct.GPIO_Mode = 0x00;		// Pin modu giri� olarak se�ildi
	GPIO_InitStruct.GPIO_OType = 0x00;  	// Durumu push-pull olarak se�ildi
	GPIO_InitStruct.GPIO_PuPd = 0x02;   	// Pull-down se�imi yap�ld�
	GPIO_InitStruct.GPIO_Speed = 0x03; 		// H�z olarak 100Mhz kullan�l�yor.

	GPIO_Init(GPIOB, &GPIO_InitStruct);	// Gerekli konfig�rasyonlar GPIOB portuna atand�

	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12 |GPIO_Pin_13 |GPIO_Pin_14 |GPIO_Pin_15;	// Kullan�lacak pinler tan�mland�
	GPIO_InitStruct.GPIO_Mode = 0x01;		// Pin modu ��k�� olarak se�ildi
	GPIO_InitStruct.GPIO_OType = 0x00;		// Durumu push-pull olarak se�ildi
	GPIO_InitStruct.GPIO_PuPd = 0x00;		// No-pull se�imi yap�ld�
	GPIO_InitStruct.GPIO_Speed = 0x03;		// H�z olarak 100Mhz kullan�l�yor.

	GPIO_Init(GPIOD, &GPIO_InitStruct);	// Gerekli konfig�rasyonlar GPIOD portuna atand�

}

void delay(uint32_t time) // Delay i�in fonksiyon olu�turuldu (32bit)
{
	while(time--); // time 0 olana kadar d�ng� devam ediyor.
}

int main(void)
{

  while (1)
  {
	  if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1)) // Butondan bit d�zeyinde okuma yap�ld� ve butona bas�l�yor mu kontrol edildi.
	  {
		  while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1)); // Butona hala bas�lmaya devam m� ediliyor.
		  delay(336000); // 200ms bekle

		  count++; // Sayma de�i�kenini 1 art�r.
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
