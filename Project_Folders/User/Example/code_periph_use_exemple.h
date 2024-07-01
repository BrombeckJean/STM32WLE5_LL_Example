/********************************************************************************
  * @file           : code_periph_use_exemple.h
  * @brief          : Header for code_periph_use_exemple.c file.
  *******************************************************************************/

//------------------ SPECIAL DEFINE ------------------------------------------------------------------------- SPECIAL DEFINE ---------------------------------------------------*/
#ifndef PROJECT_FOLDERS_USER_CODE_PERIPH_USE_EXEMPLE_H_
#define PROJECT_FOLDERS_USER_CODE_PERIPH_USE_EXEMPLE_H_

//------------------ INCLUDE -------------------------------------------------------------------------------- INCLUDE ----------------------------------------------------------*/
	#include "periph_init.h"

//------------------ PROTOTYPE ------------------------------------------------------------------------------ PROTOTYPE --------------------------------------------------------*/
	/*GPIO function*/
	void GPIO_Toggle (GPIO_TypeDef * GPIOX, uint32_t pin);

	/*USART function*/
	void Example_Char_Usart1_Transmit (void);
	void Example_Printf_Usart1_Transmit (void);
	void Example_Char_Usart2_Transmit (void);
	void Example_Printf_Usart2_Transmit (void);
	void Test_I2c (void);
	void Test_RNG (void);

//------------------ END SPECIAL DEFINE --------------------------------------------------------------------- END SPECIAL DEFINE -----------------------------------------------*/
#endif /* PROJECT_FOLDERS_USER_CODE_PERIPH_USE_EXEMPLE_H_ */
