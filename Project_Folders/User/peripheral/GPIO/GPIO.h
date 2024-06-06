/********************************************************************************
  * @file           : GPIO.h
  * @brief          : Header for GPIO.c file.
  *                   This file contains the common defines of the application.
  *******************************************************************************/

//------------------ SPECIAL DEFINE ------------------------------------------------------------------------- SPECIAL DEFINE ---------------------------------------------------*/
#ifndef PROJECT_FOLDERS_USER_PERIPHERAL_GPIO_GPIO_H_
#define PROJECT_FOLDERS_USER_PERIPHERAL_GPIO_GPIO_H_

//------------------ INCLUDE -------------------------------------------------------------------------------- INCLUDE ----------------------------------------------------------*/
	/* LL include */
	#include <periph_activation.h>
	#include "full_ll_include.h"

//------------------ PROTOTYPE ------------------------------------------------------------------------------ PROTOTYPE --------------------------------------------------------*/
	void gpio_init(GPIO_TypeDef * GPIOX, uint32_t pin, uint32_t mode, uint32_t pull, uint32_t speed, uint32_t outputtype, uint32_t alternate);

//------------------ END SPECIAL DEFINE --------------------------------------------------------------------- END SPECIAL DEFINE -----------------------------------------------*/
#endif /* PROJECT_FOLDERS_USER_PERIPHERAL_GPIO_GPIO_H_ */
