//********************************************************************************
//* @file           : I2C.c
//* @brief          : peripherique initialisation folder.
//********************************************************************************

//------------------ INCLUDE -------------------------------------------------------------------------------- INCLUDE --------------------------------------------------------*/
	#include "I2C.h"

//------------------ GLOBAL STATEMENT ----------------------------------------------------------------------- GLOBLAL STATEMENT ----------------------------------------------*/
	uint8_t I2C_data_Rx;
	uint8_t I2C_IsActiveFlag_RXNE;

	extern LL_I2C_InitTypeDef 	I2C_InitStruct;

//------------------ I2C INIT ------------------------------------------------------------------------------- I2C INIT -------------------------------------------------------*/
	/* @brief  Initialising I2C1 with configuration in I2C.h
	 * @retval None */
	void I2c_Init(void)
	{
		#ifdef i2c
		/*TO DO*/
		#ifdef gpio
		#else
			#warning //you need to uncomente the gpio define in "periph_activation.h". If you want to use this function
		#endif

		/*gpio pin initialisation for I2C mode*/
			//I2C SCL Pin
			gpio_init(I2C_SCL_GPIO_Port, I2C_SCL_Pin, LL_GPIO_MODE_ALTERNATE, I2C_SCL_PULL, LL_GPIO_SPEED_FREQ_HIGH, I2C_SCL_OUTPUT, I2C_SCL_AF);

			//I2C SDA Pin
			gpio_init(I2C_SDA_GPIO_Port, I2C_SDA_Pin, LL_GPIO_MODE_ALTERNATE, I2C_SDA_PULL, LL_GPIO_SPEED_FREQ_HIGH, I2C_SDA_OUTPUT, I2C_SDA_AF);

			//Disable/Reset I2C1
			LL_I2C_Disable(I2C1);

			//clock I2C conf
			LL_APB1_GRP1_DisableClock(LL_APB1_GRP1_PERIPH_I2C1);
			LL_RCC_SetI2CClockSource(LL_RCC_I2C1_CLKSOURCE_SYSCLK);
			LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_I2C1);

			I2C_InitStruct.PeripheralMode   = LL_I2C_MODE_I2C;
			I2C_InitStruct.Timing  			= 0x00707CBB; // for 16Mhz
			I2C_InitStruct.AnalogFilter  	= LL_I2C_ANALOGFILTER_ENABLE;
			I2C_InitStruct.DigitalFilter 	= 2;
			I2C_InitStruct.OwnAddress1 		= 180;
			I2C_InitStruct.TypeAcknowledge  = LL_I2C_NACK;
			I2C_InitStruct.OwnAddrSize		= LL_I2C_OWNADDRESS1_7BIT;

			LL_I2C_EnableAutoEndMode(I2C1);
			LL_I2C_DisableOwnAddress2(I2C1);
			LL_I2C_DisableGeneralCall(I2C1);
			LL_I2C_EnableClockStretching(I2C1);
			uint32_t priority = NVIC_GetPriority(I2C1_EV_IRQn);

	        NVIC_SetPriority(I2C1_EV_IRQn, priority);
	        NVIC_EnableIRQ(I2C1_EV_IRQn);
	        LL_I2C_EnableIT_RX(I2C1);

			LL_I2C_Init(I2C1,&I2C_InitStruct);
		#else
			#warning //you need to uncomente the i2c define in "periph_activation.h". If you want to use this function.
		#endif
	}

//------------------ I2C1 EV IRQHANDLER --------------------------------------------------------------------- I2C1 EV IRQHANDLER ---------------------------------------------*/
	/* @brief  All IRQ on I2C1 are redirected here.
	 * @retval None */
	void I2C1_EV_IRQHandler (void)
	{
		//Flag to know if the reception register is empty.
		if (LL_I2C_IsActiveFlag_RXNE(I2C1))
		{
			I2C_IsActiveFlag_RXNE = 1;
			I2C_data_Rx = LL_I2C_ReceiveData8(I2C1);				//read the data register
		}
	}
