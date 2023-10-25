/*
 ============================================================================
 Name        : assignments-3/3
 Author      : Mohamed Ahmed Mohamed Osman
 Version     :
 Copyright   : Your copyright notice
 Description : Stm32f103c6 LED ON
 ============================================================================
 */

typedef volatile unsigned int vuint32_t;

#define RCC_base 0x40021000
#define GPIOA_base 0x40010800
#define RCC_APB2ENR *((vuint32_t *)(RCC_base + 0x18))
#define GPIOA_CRH *((vuint32_t *)(GPIOA_base + 0X04))
#define GPIOA_ODR *((vuint32_t *)(GPIOA_base + 0X0C))

typedef union
{
	vuint32_t all_field;
	struct
	{
		vuint32_t revesed : 13;
		vuint32_t pin_13 : 1;
	} pin;

} R_ODR_t;

volatile R_ODR_t *R_ODR = (volatile R_ODR_t *)(GPIOA_base + 0x0c);

int main()
{
	RCC_APB2ENR |= 1 << 2;
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;

	while (1)
	{
		R_ODR->pin.pin_13 = 1;
		for(int i = 0 ; i < 5000 ; i++ ) ;
		R_ODR->pin.pin_13 = 0;
		for(int i = 0 ; i < 5000 ; i++ ) ;
	}
}