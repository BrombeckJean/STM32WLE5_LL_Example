/********************************************************************************
  * @file           : project_option.h
  * @brief          : This header contain all option of the project.
  *******************************************************************************/

//------------------ SPECIAL DEFINE ---------------------------------------------------------------------- SPECIAL DEFINE ------------------------------------------------*/
#ifndef PROJECT_FOLDERS_USER_OPTION_PROJECT_OPTION_H_
#define PROJECT_FOLDERS_USER_OPTION_PROJECT_OPTION_H_

//------------------ INCLUDE -------------------------------------------------------------------------------- INCLUDE ----------------------------------------------------------*/
	#include "full_ll_include.h"

//------------------ DEFINE ------------------------------------------------------------------------------ DEFINE --------------------------------------------------------*/
// COMMENT OR UNCOMMENT THE DEFINE :
	// DEBUG OPTION :
	#define debug_SUBGHZ_help
	//#define clock_freq_know

	// PERIPHERAL :
	/* GPIO */
	//#define gpio

	/* USART */
	//#define usart1
	//#define usart2

	/* I2C */
	//#define i2c

	/* SPI */
	#define spi

	/* RNG */
	//#define rng

//------------------ ACTIVATION CHECK -------------------------------------------------------------------- ACTIVATION CHECK-----------------------------------------------*/
	/* USART */
	#ifdef usart1
		#ifndef gpio
			#define gpio
		#endif
	#endif

	#ifdef usart2
		#ifndef gpio
			#define gpio
		#endif
	#endif

	/* I2C */
	#ifdef i2c
		#ifndef gpio
			#define gpio
		#endif
	#endif

	/* SPI */
	#ifdef spi
		#ifndef gpio
			#define gpio
		#endif
	#else
		#ifdef debug_SUBGHZ_help
			#undef debug_SUBGHZ_help
		#endif
	#endif
//------------------ PROTOTYPE ------------------------------------------------------------------------------ PROTOTYPE --------------------------------------------------------*/
	void Activation_Error(void);

//------------------ END SPECIAL DEFINE --------------------------------------------------------------------- END SPECIAL DEFINE -----------------------------------------*/
#endif /* PROJECT_FOLDERS_USER_OPTION_PROJECT_OPTION_H_ */
