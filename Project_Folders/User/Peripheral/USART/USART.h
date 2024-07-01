/********************************************************************************
  * @file           : USART.h
  * @brief          : Header for USART.c.
  *******************************************************************************/

//------------------ SPECIAL DEFINE ------------------------------------------------------------------------- SPECIAL DEFINE ---------------------------------------------------*/
#ifndef PROJECT_FOLDERS_USER_PERIPHERAL_USART_H_
#define PROJECT_FOLDERS_USER_PERIPHERAL_USART_H_

//------------------ INCLUDE -------------------------------------------------------------------------------- INCLUDE ----------------------------------------------------------*/
	/* LL include */
	#include "full_ll_include.h"
	#include "project_option.h"
	#include "GPIO.h"


//------------------ TYPE DEFINE ---------------------------------------------------------------------------- TYPE DEFINE ----------------------------------------------------*/
	typedef enum
	{
		UART_BAUDRATE_NONE    = 0,        //!< That is probably a error.
		UART_BAUDRATE_1200    = 1200,     //!< 1200 bps.
		UART_BAUDRATE_2400    = 2400,     //!< 2400 bps.
		UART_BAUDRATE_4800    = 4800,     //!< 4800 bps.
		UART_BAUDRATE_9600    = 9600,     //!< 9600 bps.
		UART_BAUDRATE_19200   = 19200,    //!< 19200 bps.
		UART_BAUDRATE_38400   = 38400,    //!< 38400 bps.
		UART_BAUDRATE_57600   = 57600,    //!< 57600 bps.
		UART_BAUDRATE_115200  = 115200,   //!< 115200 bps.
		UART_BAUDRATE_230400  = 230400    //!< 230400 bps.
	}UartBaudrate_t;

//------------------ DEFINE ------------------------------------------------------------------------------ DEFINE --------------------------------------------------------*/
	#define DATAWIDTH 					LL_LPUART_DATAWIDTH_8B
	#define PARITY               		LL_LPUART_PARITY_NONE
	#define STOPBITS                	LL_LPUART_STOPBITS_1
	#define BAUDRATE                	UART_BAUDRATE_115200

	/*USART1 TX*/
	#define USART1_TX_GPIO_Port         GPIOB
	#define USART1_TX_Pin               LL_GPIO_PIN_6
	#define USART1_TX_PULL              LL_GPIO_PULL_NO
	#define USART1_TX_OUTPUT            LL_GPIO_OUTPUT_PUSHPULL
	#define USART1_TX_AF                LL_GPIO_AF_7
	#define USART1_TX_PIN_LEVEL         LL_USART_TXPIN_LEVEL_STANDARD

	/* USART1 RX. */
	#define USART1_RX_GPIO_Port         GPIOB
	#define USART1_RX_Pin               LL_GPIO_PIN_7
	#define USART1_RX_PULL              LL_GPIO_PULL_UP
	#define USART1_RX_OUTPUT            LL_GPIO_OUTPUT_PUSHPULL
	#define USART1_RX_AF                LL_GPIO_AF_7
	#define USART1_RX_PIN_LEVEL         LL_USART_RXPIN_LEVEL_STANDARD

	/* USART2 TX. */
	#define USART2_TX_GPIO_Port         GPIOA
	#define USART2_TX_Pin               LL_GPIO_PIN_2
	#define USART2_TX_PULL              LL_GPIO_PULL_NO
	#define USART2_TX_OUTPUT            LL_GPIO_OUTPUT_PUSHPULL
	#define USART2_TX_AF                LL_GPIO_AF_7
	#define USART2_TX_PIN_LEVEL         LL_USART_TXPIN_LEVEL_STANDARD

	/* USART2 RX. */
	#define USART2_RX_GPIO_Port         GPIOA
	#define USART2_RX_Pin               LL_GPIO_PIN_3
	#define USART2_RX_PULL              LL_GPIO_PULL_UP
	#define USART2_RX_OUTPUT            LL_GPIO_OUTPUT_PUSHPULL
	#define USART2_RX_AF                LL_GPIO_AF_7
	#define USART2_RX_PIN_LEVEL         LL_USART_RXPIN_LEVEL_STANDARD

//------------------ PROTOTYPE ------------------------------------------------------------------------------ PROTOTYPE --------------------------------------------------------*/
	void Usart1_Init(void);
	void Usart2_Init(void);
	void Char8B_Usart_Transmit (USART_TypeDef *USARTx ,uint8_t character);
	int __io_putchar(int ch);

//------------------ END SPECIAL DEFINE --------------------------------------------------------------------- END SPECIAL DEFINE -----------------------------------------------*/
#endif /* PROJECT_FOLDERS_USER_PERIPHERAL_USART_H_ */
