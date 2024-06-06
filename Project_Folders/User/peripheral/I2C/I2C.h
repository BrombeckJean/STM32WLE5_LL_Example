/********************************************************************************
  * @file           : I2C.h
  * @brief          : Header for I2C.c file.
  *******************************************************************************/

//------------------ SPECIAL DEFINE ------------------------------------------------------------------------- SPECIAL DEFINE ---------------------------------------------------*/
#ifndef PROJECT_FOLDERS_USER_PERIPHERAL_I2C_I2C_H_
#define PROJECT_FOLDERS_USER_PERIPHERAL_I2C_I2C_H_

//------------------ INCLUDE -------------------------------------------------------------------------------- INCLUDE ----------------------------------------------------------*/
	/* LL include */
	#include <periph_activation.h>
	#include "full_ll_include.h"
	#include "GPIO.h"

//------------------ DEFINE --------------------------------------------------------------------------------- DEFINE -----------------------------------------------------------*/
	/* I2C SCL */
	#define I2C_SCL_GPIO_Port         GPIOA
	#define I2C_SCL_Pin               LL_GPIO_PIN_9
	#define I2C_SCL_PULL              LL_GPIO_PULL_UP
	#define I2C_SCL_OUTPUT            LL_GPIO_OUTPUT_OPENDRAIN
	#define I2C_SCL_AF                LL_GPIO_AF_4

	/* I2C SDA */
	#define I2C_SDA_GPIO_Port         GPIOA
	#define I2C_SDA_Pin               LL_GPIO_PIN_10
	#define I2C_SDA_PULL              LL_GPIO_PULL_UP
	#define I2C_SDA_OUTPUT            LL_GPIO_OUTPUT_OPENDRAIN
	#define I2C_SDA_AF                LL_GPIO_AF_4

//------------------ PROTOTYPE ------------------------------------------------------------------------------ PROTOTYPE --------------------------------------------------------*/
	void I2c_Init(void);
	void I2c_Write(uint8_t addr, uint8_t register_addr, uint8_t register_data);
	void I2c_Read(uint8_t addr, uint8_t register_addr);
	void I2C1_EV_IRQHandler (void);

//------------------ END SPECIAL DEFINE --------------------------------------------------------------------- END SPECIAL DEFINE -----------------------------------------------*/
#endif /* PROJECT_FOLDERS_USER_PERIPHERAL_I2C_I2C_H_ */
