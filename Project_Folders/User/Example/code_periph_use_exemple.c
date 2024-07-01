/********************************************************************************
 * @file           : code_periph_use_exemple.c
 * @brief          : Example of using peripherals.
 * @Warning        : This examples can be use only one by one
 *********************************************************************************/

//------------------ INCLUDE -------------------------------------------------------------------------------- INCLUDE --------------------------------------------------------*/
	#include "code_periph_use_exemple.h"

//€€€€€€€€€€€€€€€€€€ GPIO €€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€ GPIO €€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€*/
//------------------ GPIO TOOGLE ---------------------------------------------------------------------------- GPIO TOOGLE ----------------------------------------------------*/
	/* @brief  Toggle the desired GPIO.
	 * @param1 Periphs This parameter can be a combination of the following values:
	 *			@arg @ref GPIOA
	 *			@arg @ref GPIOB
	 *			@arg @ref GPIOC
	 *			@arg @ref GPIOH
	 * @param2 Periphs This parameter can be a combination of the following values:
	 * @warning GPIOH have only one pin LL_GPIO_PIN_3
	 *			@arg @ref LL_GPIO_PIN_0
	 *			@arg @ref LL_GPIO_PIN_...
	 *          @arg @ref LL_GPIO_PIN_15
	 * @retval None. */
	void GPIO_Toggle (GPIO_TypeDef * GPIOX, uint32_t pin)
	{
	#ifdef gpio
		/*Initialization*/
		Gpio_Init(GPIOX, pin, LL_GPIO_MODE_OUTPUT, GPIO_NOPULL, LL_GPIO_SPEED_FREQ_MEDIUM, LL_GPIO_OUTPUT_PUSHPULL, 0);

		/*LOOP*/
		while (1)
		{
			LL_GPIO_TogglePin(GPIOX, pin);
			HAL_Delay(500);
		}
	#endif
	}


//€€€€€€€€€€€€€€€€€€ USART €€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€ USART €€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€*/
//------------------ EXAMPLE CHAR USART1 TRANSMIT ----------------------------------------------------------- EXAMPLE CHAR USART1 TRANSMIT------------------------------------*/
	/* @brief  This example show you how to transmit an 8-bits character on the USART1.
	 * @retval None. */
	void Example_Char_Usart1_Transmit (void)
	{
	#ifdef usart1
		/*Initialization*/
		Usart1_Init();

		/*LOOP*/
		while (1)
		{
			uint8_t character = 'V';
			Char8B_Usart_Transmit(USART1, character);
			character = ' ';
			Char8B_Usart_Transmit(USART1, character);
			HAL_Delay(100);
		}
	#endif
	}

//------------------ EXAMPLE PRINTF USART1 TRANSMIT --------------------------------------------------------- EXAMPLE PRINTF USART1 TRANSMIT ---------------------------------*/
	/* @brief  This example show you how to transmit a printf function on the USART1.
	 * @retval None. */
	void Example_Printf_Usart1_Transmit (void)
	{
	#ifdef usart1
		/*Initialization*/
		Usart1_Init();

		/*LOOP*/
		while (1)
		{
			printf("Hello Word \n\r");
			HAL_Delay(100);
		}
	#endif
	}

//------------------ EXEMPLE CHAR USART2 TRANSMIT ----------------------------------------------------------- EXEMPLE CHAR USART2 TRANSMIT -----------------------------------*/
	/* @brief  This example show you how to transmit an 8-bits character on the USART2.
	 * @retval None. */
	void Example_Char_Usart2_Transmit (void)
	{
	#ifdef usart2
		/*Initialization*/
		Usart2_Init();

		/*LOOP*/
		while (1)
		{
			uint8_t character = 'V';
			Char8B_Usart_Transmit(USART2, character);
			character = ' ';
			Char8B_Usart_Transmit(USART2, character);
			HAL_Delay(1000);
		}
	#endif
	}

//------------------ EXAMPLE PRINTF USART2 TRANSMIT --------------------------------------------------------- EXAMPLE PRINTF USART2 TRANSMIT ---------------------------------*/
	/* @brief  This example show you how to transmit a printf function on the USART2.
	 * @retval None. */
	void Example_Printf_Usart2_Transmit (void)
	{
	#ifdef usart2
		/*Initialization*/
		Usart2_Init();

		/*LOOP*/
		while (1)
		{
			printf("Hello Word \n\r");
			HAL_Delay(1000);
		}
	#endif
	}

//€€€€€€€€€€€€€€€€€€ I2C €€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€ I2C €€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€*/
//------------------ TEST I2C ------------------------------------------------------------------------------- TEST I2C -------------------------------------------------------*/
		/* @brief   This example show you how to communicate in i2c.
		 * @warning For this example you need the usart, for display the temperature.
		 * @retval  None. */
		void Test_I2c (void)
		{
		#ifdef i2c
			I2C_STHS34PF80_Read_Tambient();
			HAL_Delay(5000);
		#endif
		}

//€€€€€€€€€€€€€€€€€€ I2C €€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€ I2C €€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€*/
//------------------ TEST RNG ------------------------------------------------------------------------------- TEST RNG -------------------------------------------------------*/
		/* @brief   This example show you how to use RNG.
		 * @warning For this example you need the usart, for display the temperature.
		 * @retval  None. */
		void Test_RNG (void)
		{
		#ifdef rng
			uint32_t data = Get_RNG_Number();
			printf("%lu\n\r",data);
			HAL_Delay(2000);
		#endif
		}
