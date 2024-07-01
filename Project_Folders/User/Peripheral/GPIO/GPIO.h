/********************************************************************************
  * @file           : GPIO.h
  * @brief          : Header for GPIO.c file.
  *******************************************************************************/

//------------------ SPECIAL DEFINE ------------------------------------------------------------------------- SPECIAL DEFINE ---------------------------------------------------*/
#ifndef PROJECT_FOLDERS_USER_PERIPHERAL_GPIO_H_
#define PROJECT_FOLDERS_USER_PERIPHERAL_GPIO_H_

//------------------ INCLUDE -------------------------------------------------------------------------------- INCLUDE ----------------------------------------------------------*/
	#include "full_ll_include.h"
	#include "project_option.h"

//------------------ PROTOTYPE ------------------------------------------------------------------------------ PROTOTYPE --------------------------------------------------------*/
	void Gpio_Init(GPIO_TypeDef * GPIOX, uint32_t pin, uint32_t mode, uint32_t pull, uint32_t speed, uint32_t outputtype, uint32_t alternate);

//------------------ END SPECIAL DEFINE --------------------------------------------------------------------- END SPECIAL DEFINE -----------------------------------------------*/
#endif /* PROJECT_FOLDERS_USER_PERIPHERAL_GPIO_H_ */
