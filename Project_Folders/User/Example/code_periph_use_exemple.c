//********************************************************************************
//* @file           : code_periph_use_exemple.c
//* @brief          : peripherique initialisation folder.
//* @Warning        : this examples can be use only one by one
//********************************************************************************

//------------------ INCLUDE -------------------------------------------------------------------------------- INCLUDE --------------------------------------------------------*/
	#include "code_periph_use_exemple.h"

//€€€€€€€€€€€€€€€€€€ GPIO €€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€ GPIO €€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€*/
//------------------ EXEMPLE GPIOA PIN4 TOOGLE -------------------------------------------------------------- EXEMPLE GPIOA PIN4 TOOGLE --------------------------------------*/
	// @brief this example configure and on/off an gpio
	void example_gpioa_pin4_toogle (void)
	{
		#ifdef gpio
			/*Initialisation*/
			gpio_init(GPIOA, LL_GPIO_PIN_4, LL_GPIO_MODE_OUTPUT, GPIO_NOPULL, LL_GPIO_SPEED_FREQ_MEDIUM, LL_GPIO_OUTPUT_PUSHPULL, 0);

			/*LOOP*/
			while (1)
			{
				LL_GPIO_TogglePin(GPIOA, LL_GPIO_PIN_4);
				HAL_Delay(500);
			}
		#else
		#warning //you need to uncomente the gpio define in "periph_init.h". If you want to use this function
		#endif
	}


//€€€€€€€€€€€€€€€€€€ USART €€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€ USART €€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€*/
//------------------ EXEMPLE CHAR USART1 TRANSMIT ----------------------------------------------------------- EXEMPLE CHAR USART1 TRANSMIT------------------------------------*/
	// @brief this example show you how to transmit an 8-bits character on the USART1
	void example_char_usart1_transmit (void)
	{
		#ifdef usart1
			/*Initialisation*/
			usart1_init();

			/*LOOP*/
			while (1)
			{
				uint8_t character = 'V';
				char8B_usart_transmit(USART1, character);
				character = ' ';
				char8B_usart_transmit(USART1, character);
				HAL_Delay(100);
			}
		#else
		#warning //you need to uncomente the usart1 define in "periph_init.h". If you want to use this function
		#ifdef gpio
		#else
		#warning //you need to uncomente the gpio define in "periph_init.h". If you want to use this function
		#endif
		#endif
	}

//------------------ EXEMPLE PRINTF USART1 TRANSMIT --------------------------------------------------------- EXEMPLE PRINTF USART1 TRANSMIT ---------------------------------*/
	// @brief this example show you how to transmit a printf function on the USART1
	void exemple_printf_usart1_transmit (void)
	{
		#ifdef usart1
			/*Initialisation*/
			usart1_init();

			/*LOOP*/
			while (1)
			{
				printf("Hello Word \n\r");
				HAL_Delay(100);
			}
		#else
		#warning //you need to uncomente the usart1 define in "periph_init.h". If you want to use this function
		#ifdef gpio
		#else
		#warning //you need to uncomente the gpio define in "periph_init.h". If you want to use this function
		#endif
		#endif
	}

//------------------ EXEMPLE CHAR USART2 TRANSMIT ----------------------------------------------------------- EXEMPLE CHAR USART2 TRANSMIT -----------------------------------*/

	// @brief this example show you how to transmit an 8-bits character on the USART2
	void example_char_usart2_transmit (void)
	{
		#ifdef usart2
			/*Initialisation*/
			usart2_init();

			/*LOOP*/
			while (1)
			{
				uint8_t character = 'V';
				char8B_usart_transmit(USART2, character);
				character = ' ';
				char8B_usart_transmit(USART2, character);
				HAL_Delay(100);
			}
		#else
		#warning //you need to uncomente the usart2 define in "periph_init.h". If you want to use this function
		#ifdef gpio
		#else
		#warning //you need to uncomente the gpio define in "periph_init.h". If you want to use this function
		#endif
		#endif
	}

//------------------ EXEMPLE PRINTF USART2 TRANSMIT --------------------------------------------------------- EXEMPLE PRINTF USART2 TRANSMIT ---------------------------------*/
	// @brief this example show you how to transmit a printf function on the USART2
	void example_printf_usart2_transmit (void)
	{
		#ifdef usart2
			/*Initialisation*/
			usart2_init();

			/*LOOP*/
			while (1)
			{
				printf("Hello Word \n\r");
				HAL_Delay(100);
			}
		#else
		#warning //you need to uncomente the usart2 define in "periph_init.h". If you want to use this function
		#ifdef gpio
		#else
		#warning //you need to uncomente the gpio define in "periph_init.h". If you want to use this function
		#endif
		#endif
	}


//€€€€€€€€€€€€€€€€€€ I2C €€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€ I2C €€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€*/
	//------------------ EXEMPLE PRINTF USART2 TRANSMIT --------------------------------------------------------- EXEMPLE PRINTF USART2 TRANSMIT ---------------------------------*/
		// @brief this example show you how to transmit a printf function on the USART2
		void Test_i2c (void)
		{
			//i2c_read(0b10110100,0x0F);
			i2c_read(0b1011010,0x0F);
			uint8_t data;

			data = LL_I2C_ReceiveData8(I2C1);
			printf("data register = %d \n\r",data);
		}
