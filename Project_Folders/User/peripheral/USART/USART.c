/********************************************************************************
 * @file           : USART.c
 * @brief          : peripherique initialisation folder.
 ********************************************************************************/

//------------------ INCLUDE -------------------------------------------------------------------------------- INCLUDE --------------------------------------------------------*/
	#include "USART.h"

//------------------ USART1 INIT ----------------------------------------------------------------------------- USART1 INIT -----------------------------------------------------*/
	/*@brief Initialising USART1 with configuration in USART.h
	 * @retval None */
	void Usart1_Init(void)
	{
		#ifdef usart1
			/*gpio pin initialisation for USART1 mode*/
				//TX mode
				Gpio_Init(USART1_TX_GPIO_Port, USART1_TX_Pin, LL_GPIO_MODE_ALTERNATE, USART1_TX_PULL, LL_GPIO_SPEED_FREQ_HIGH, USART1_TX_OUTPUT,USART1_TX_AF);

				//RX mode
				Gpio_Init(USART1_RX_GPIO_Port, USART1_RX_Pin, LL_GPIO_MODE_ALTERNATE, USART1_RX_PULL, LL_GPIO_SPEED_FREQ_HIGH, USART1_RX_OUTPUT,USART1_RX_AF);

			//Disable/Reset USART1
			LL_USART_Disable(USART1);

			//clock uart conf
			LL_APB2_GRP1_DisableClock(LL_APB2_GRP1_PERIPH_USART1);
			LL_RCC_SetUSARTClockSource(LL_RCC_USART1_CLKSOURCE_PCLK2);
			LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_USART1);
			uint32_t freqClockUsed = LL_RCC_GetUSARTClockFreq(LL_RCC_USART1_CLKSOURCE);

			//uart conf
			LL_USART_SetTransferDirection(USART1, LL_USART_DIRECTION_TX_RX);
			LL_USART_SetTXPinLevel(USART1, USART1_TX_PIN_LEVEL);
			LL_USART_SetRXPinLevel(USART1, USART1_RX_PIN_LEVEL);
			LL_USART_ConfigCharacter(USART1, DATAWIDTH, PARITY, STOPBITS);

			// Set Baudrate
			uint32_t oversampling = ((BAUDRATE >= freqClockUsed/16) ? LL_USART_OVERSAMPLING_16 : LL_USART_OVERSAMPLING_8);
			LL_USART_SetOverSampling(USART1, oversampling);
			LL_USART_SetBaudRate(USART1, freqClockUsed, LL_USART_PRESCALER_DIV1, oversampling, BAUDRATE);

			LL_USART_Enable(USART1);
		#endif
	}

//------------------ USART2 INIT ----------------------------------------------------------------------------- USART2 INIT -----------------------------------------------------*/
	/*@brief  Initialising USART2 with configuration in USART.h
	 * @retval None */
	void Usart2_Init(void)
	{
		#ifdef usart2
			/*gpio pin initialisation for USART2 mode*/
				//TX mode
				Gpio_Init(USART2_TX_GPIO_Port, USART2_TX_Pin, LL_GPIO_MODE_ALTERNATE, USART2_TX_PULL, LL_GPIO_SPEED_FREQ_HIGH, USART2_TX_OUTPUT,USART2_TX_AF);

				//RX mode
				Gpio_Init(USART2_RX_GPIO_Port, USART2_RX_Pin, LL_GPIO_MODE_ALTERNATE, USART2_RX_PULL, LL_GPIO_SPEED_FREQ_HIGH, USART2_RX_OUTPUT,USART2_RX_AF);

			//Disable/Reset USART2
			LL_USART_Disable(USART2);

			//clock uart conf
			LL_APB1_GRP1_DisableClock(LL_APB1_GRP1_PERIPH_USART2);
			LL_RCC_SetUSARTClockSource(LL_RCC_USART2_CLKSOURCE_PCLK1);
			LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_USART2);
			uint32_t freqClockUsed = LL_RCC_GetUSARTClockFreq(LL_RCC_USART2_CLKSOURCE);

			//uart conf
			LL_USART_SetTransferDirection(USART2, LL_USART_DIRECTION_TX_RX);
			LL_USART_SetTXPinLevel(USART2, USART2_TX_PIN_LEVEL);
			LL_USART_SetRXPinLevel(USART2, USART2_RX_PIN_LEVEL);
			LL_USART_ConfigCharacter(USART2, DATAWIDTH, PARITY, STOPBITS);

			// Set Baudrate
			uint32_t oversampling = ((BAUDRATE >= freqClockUsed/16) ? LL_USART_OVERSAMPLING_16 : LL_USART_OVERSAMPLING_8);
			LL_USART_SetOverSampling(USART2, oversampling);
			LL_USART_SetBaudRate(USART2, freqClockUsed, LL_USART_PRESCALER_DIV1, oversampling, BAUDRATE);

			LL_USART_Enable(USART2);
		#else
			#warning //you need to uncomente the usart2 define in "periph_activation.h". If you want to use this function
		#endif
	}

//------------------ CHAR8B USART TRANSMIT ------------------------------------------------------------------- CHAR8B USART TRANSMIT -------------------------------------------*/
	/* @brief  transmits an 8-bits character on the USART
	 * @param1 Periphs This parameter can be a combination of the following values:
	 *         	@arg @ref LPUART1
	 *         	@arg @ref USART1
	 *         	@arg @ref USART2
	 * @param2 Periphs This parameter can be a combination of the following values:
	 *         	Put the caracter on 8bits you want transmit.
	 * @retval None */
	void Char8B_Usart_Transmit (USART_TypeDef *USARTx ,uint8_t character)
	{
		while (READ_BIT(USARTx->ISR, USART_ISR_TC) == 0);
		LL_USART_TransmitData8(USARTx, character);
	}

//------------------ IO PUTCHAR ------------------------------------------------------------------------------ IO PUTCHAR ----------------------------------------------------*/
	/* printf function redirection */
	/* e.g. write a character to the USART2 and Loop until the end of transmission */
	/* Warning this function can be define in an other folder ("syscalls"), so remove the function*/
	int __io_putchar(int ch)
	{
		#ifdef usart1
		Char8B_Usart_Transmit(USART1,ch);
		#endif

		#ifdef usart2
		Char8B_Usart_Transmit(USART2,ch);
		#endif

		return ch;
	}

