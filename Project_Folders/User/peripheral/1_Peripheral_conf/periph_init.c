
//********************************************************************************
//* @file           : periph_init.c
//* @brief          : peripherique initialisation folder.
//********************************************************************************

//------------------ INCLUDE -------------------------------------------------------------------------------- INCLUDE --------------------------------------------------------*/
	#include "periph_init.h"

//------------------ INIT ALL PERIPH ------------------------------------------------------------------------ INIT ALL PERIPH ------------------------------------------------*/
	void init_all_periph (void)
	{
		#ifdef gpio
			Gpio_Init(0, LL_GPIO_PIN_0, 0, 0, 0, 0, LL_GPIO_AF_0);
		#endif

		#ifdef usart1
			Usart1_Init();
		#endif

		#ifdef usart2
			Usart2_Init();
		#endif

		#ifdef i2c
			I2c_Init();
			I2C_STHS34PF80_Data_Reg_Init();
		#endif
	}
