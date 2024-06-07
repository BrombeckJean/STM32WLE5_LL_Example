/********************************************************************************
  * @file           : periph_activation.h
  * @brief          : This header contain the all peripheral activation.
  *******************************************************************************/

//------------------ SPECIAL DEFINE ---------------------------------------------------------------------- SPECIAL DEFINE ------------------------------------------------*/
#ifndef PROJECT_FOLDERS_USER_PERIPHERAL_1_PERIPHERAL_CONF_PERIPH_ACTIVATION_H_
#define PROJECT_FOLDERS_USER_PERIPHERAL_1_PERIPHERAL_CONF_PERIPH_ACTIVATION_H_

//------------------ DEFINE ------------------------------------------------------------------------------ DEFINE --------------------------------------------------------*/
	/*COMMENT OR UNCOMMENT TO USE OR NOT TO USE PERIPHERAL*/
	#define gpio
	//#define usart1
	#define usart2
	//#define i2c
	//#define spi


	#ifdef gpio
	#else
	#warning //don't forget to uncoment the gpio define if you want use it.
	#endif

	#ifdef usart1
	#else
	#warning //don't forget to uncoment the usart1 define if you want use it.
	#endif

	#ifdef usart2
	#else
	#warning //don't forget to uncoment the usart2 define if you want use it.
	#endif

	#ifdef i2c
	#else
	#warning //don't forget to uncoment the i2c define if you want use it.
	#endif

	#ifdef spi
	#else
    #warning //don't forget to uncoment the spi define if you want use it.
	#endif

//------------------ END SPECIAL DEFINE --------------------------------------------------------------------- END SPECIAL DEFINE -----------------------------------------------*/
#endif /* PROJECT_FOLDERS_USER_PERIPHERAL_1_PERIPHERAL_CONF_PERIPH_ACTIVATION_H_ */
