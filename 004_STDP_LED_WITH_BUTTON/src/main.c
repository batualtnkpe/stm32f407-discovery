#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

int count = 0;  //Sayma için bir deðiþken

GPIO_InitTypeDef GPIO_InitStruct; // Konfigürasyonlar için Structer

void GPIO_Config()  //GPIO pin konfigürasyonlarý için gerekli fonksiyon
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE); // GPIOB için AHB1 aktif edildi
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE); // GPIOD için AHB1 aktif edildi

	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_1;  // Kullanýlacak pin tanýmlandý
	GPIO_InitStruct.GPIO_Mode = 0x00;		// Pin modu giriþ olarak seçildi
	GPIO_InitStruct.GPIO_OType = 0x00;  	// Durumu push-pull olarak seçildi
	GPIO_InitStruct.GPIO_PuPd = 0x02;   	// Pull-down seçimi yapýldý
	GPIO_InitStruct.GPIO_Speed = 0x03; 		// Hýz olarak 100Mhz kullanýlýyor.

	GPIO_Init(GPIOB, &GPIO_InitStruct);	// Gerekli konfigürasyonlar GPIOB portuna atandý

	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12 |GPIO_Pin_13 |GPIO_Pin_14 |GPIO_Pin_15;	// Kullanýlacak pinler tanýmlandý
	GPIO_InitStruct.GPIO_Mode = 0x01;		// Pin modu çýkýþ olarak seçildi
	GPIO_InitStruct.GPIO_OType = 0x00;		// Durumu push-pull olarak seçildi
	GPIO_InitStruct.GPIO_PuPd = 0x00;		// No-pull seçimi yapýldý
	GPIO_InitStruct.GPIO_Speed = 0x03;		// Hýz olarak 100Mhz kullanýlýyor.

	GPIO_Init(GPIOD, &GPIO_InitStruct);	// Gerekli konfigürasyonlar GPIOD portuna atandý

}

void delay(uint32_t time) // Delay için fonksiyon oluþturuldu (32bit)
{
	while(time--); // time 0 olana kadar döngü devam ediyor.
}

int main(void)
{

  while (1)
  {
	  if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1)) // Butondan bit düzeyinde okuma yapýldý ve butona basýlýyor mu kontrol edildi.
	  {
		  while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1)); // Butona hala basýlmaya devam mý ediliyor.
		  delay(336000); // 200ms bekle

		  count++; // Sayma deðiþkenini 1 artýr.
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
