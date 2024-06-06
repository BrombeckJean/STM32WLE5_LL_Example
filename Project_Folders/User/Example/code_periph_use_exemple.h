/********************************************************************************
  * @file           : periph_init.h
  * @brief          : Header for periph_init.c file.
  *                   This file contains the common defines of the application.
  *******************************************************************************/

//------------------ SPECIAL DEFINE ------------------------------------------------------------------------- SPECIAL DEFINE ---------------------------------------------------*/
#ifndef PROJECT_FOLDERS_INC_CODE_PERIPH_USE_EXEMPLE_H_
#define PROJECT_FOLDERS_INC_CODE_PERIPH_USE_EXEMPLE_H_

//------------------ INCLUDE -------------------------------------------------------------------------------- INCLUDE ----------------------------------------------------------*/
	#include <periph_init.h>
#include <stdio.h>

//------------------ PROTOTYPE ------------------------------------------------------------------------------ PROTOTYPE --------------------------------------------------------*/
	/*GPIO function*/
	void example_gpioa_pin4_toogle (void);

	/*USART function*/
	void example_char_usart1_transmit (void);
	void example_printf_usart1_transmit (void);
	void example_char_usart2_transmit (void);
	void example_printf_usart2_transmit (void);
	void Test_i2c (void);

//------------------ END SPECIAL DEFINE --------------------------------------------------------------------- END SPECIAL DEFINE -----------------------------------------------*/
#endif /* PROJECT_FOLDERS_INC_CODE_PERIPH_USE_EXEMPLE_H_ */
