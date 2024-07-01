/********************************************************************************
  * @file           : periph_init.h
  * @brief          : Header for periph_init.c file.
  *******************************************************************************/

//------------------ SPECIAL DEFINE ------------------------------------------------------------------------- SPECIAL DEFINE ---------------------------------------------------*/
#ifndef PROJECT_FOLDERS_USER_PERIPHERAL_PERIPH_INIT_H_
#define PROJECT_FOLDERS_USER_PERIPHERAL_PERIPH_INIT_H_

//------------------ INCLUDE -------------------------------------------------------------------------------- INCLUDE ----------------------------------------------------------*/
	#include "GPIO.h"
	#include "STHS34PF80.h"
	#include "I2C.h"
	#include "RNG.h"
	#include "SPI.h"
	#include "USART.h"

//------------------ PROTOTYPE ------------------------------------------------------------------------------ PROTOTYPE --------------------------------------------------------*/
void Init_Periph_Use (void);

//------------------ END SPECIAL DEFINE --------------------------------------------------------------------- END SPECIAL DEFINE -----------------------------------------------*/
#endif /* PROJECT_FOLDERS_USER_PERIPHERAL_PERIPH_INIT_H_ */
