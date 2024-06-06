//********************************************************************************
//* @file           : GPIO.c
//* @brief          : peripherique initialisation folder.
//********************************************************************************

//------------------ INCLUDE -------------------------------------------------------------------------------- INCLUDE --------------------------------------------------------*/
	#include "GPIO.h"

//------------------ GLOBAL STATEMENT ----------------------------------------------------------------------- GLOBLAL STATEMENT ----------------------------------------------*/
	extern LL_GPIO_InitTypeDef  GPIO_InitStruct;
//------------------ GPIO INIT ------------------------------------------------------------------------------ GPIO INIT ------------------------------------------------------*/
	/* @brief  GPIO Initialisation
	 * @default gpio_init(0, LL_GPIO_PIN_0, 0, 0, 0, 0, LL_GPIO_AF_0);
	 * @param1 Periphs This parameter can be a combination of the following values:
	 *			@arg @ref gpioA
	 *			@arg @ref gpioB
	 *			@arg @ref gpioC
	 *			@arg @ref gpioH
	 * @param2 Periphs This parameter can be a combination of the following values:
	 * @warning gpioh have only one pin LL_GPIO_PIN_3
	 *			@arg @ref LL_GPIO_PIN_0
	 *			@arg @ref LL_GPIO_PIN_...
	 *          @arg @ref LL_GPIO_PIN_15
	 *          @arg @ref LL_GPIO_PIN_ALL
	 * @param3 Periphs This parameter can be a combination of the following values:
	 *         	@arg @ref LL_GPIO_MODE_INPUT
	 *         	@arg @ref LL_GPIO_MODE_OUTPUT
	 *         	@arg @ref LL_GPIO_MODE_ALTERNATE
	 *         	@arg @ref LL_GPIO_MODE_ANALOG
	 * @param4 Periphs This parameter can be a combination of the following values:
	 *         	@arg @ref GPIO_NOPULL
	 *         	@arg @ref GPIO_PULLUP
	 *         	@arg @ref GPIO_PULLDOWN
	 * @param5 Periphs This parameter can be a combination of the following values:
	 *         	@arg @ref LL_GPIO_SPEED_FREQ_LOW
	 *         	@arg @ref LL_GPIO_SPEED_FREQ_MEDIUM
	 *         	@arg @ref LL_GPIO_SPEED_FREQ_HIGH
	 *         	@arg @ref LL_GPIO_SPEED_FREQ_VERY_HIGH
	 * @param6 Periphs This parameter can be a combination of the following values:
	 *         	@arg @ref LL_GPIO_OUTPUT_PUSHPULL
	 *         	@arg @ref LL_GPIO_OUTPUT_OPENDRAIN
	 * @param7 Periphs This parameter can be a combination of the following values:
	 *         	@arg @ref LL_GPIO_AF_0
	 *         	@arg @ref LL_GPIO_AF_...
	 *         	@arg @ref LL_GPIO_AF_15
	 * @retval None */
	void Gpio_Init(GPIO_TypeDef * GPIOX, uint32_t pin, uint32_t mode, uint32_t pull, uint32_t speed, uint32_t outputtype, uint32_t alternate)
	{
		#ifdef gpio
			/* gpio structure */
			GPIO_InitStruct.Pin   		= pin;
			GPIO_InitStruct.Mode  		= mode;
			GPIO_InitStruct.Pull  		= pull;
			GPIO_InitStruct.Speed 		= speed;
			GPIO_InitStruct.OutputType 	= outputtype;
			GPIO_InitStruct.Alternate   = alternate;

			if(GPIOX == GPIOA)
			{
				LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOA);
				LL_GPIO_Init(GPIOA, &GPIO_InitStruct);
			}

			if(GPIOX == GPIOB)
			{
				LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOB);
				LL_GPIO_Init(GPIOB, &GPIO_InitStruct);
			}

			if(GPIOX == GPIOC)
			{
				LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOC);
				LL_GPIO_Init(GPIOC, &GPIO_InitStruct);
			}

			if(GPIOX == GPIOH)
			{
				LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOH);
				LL_GPIO_Init(GPIOH, &GPIO_InitStruct);
			}
		#else
		#warning //you need to uncomente the  gpio define in "periph_init.h". If you want to use this function
		#endif
	}
