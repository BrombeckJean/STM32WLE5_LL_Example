/********************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  ******************************************************************************  */

//------------------ SPECIAL DEFINE --------------------------------------------------------------------------- SPECIAL DEFINE -------------------------------------------------*/
	/* Define to prevent recursive inclusion */
	#ifndef PROJECT_FOLDERS_USER_MAIN_H
	#define PROJECT_FOLDERS_USER_MAIN_H

	/* C++ switch */
	#ifdef __cplusplus
	extern "C" {
	#endif

//------------------ INCLUDE ---------------------------------------------------------------------------------- INCLUDE --------------------------------------------------------*/
	#include "clock_conf.h"
	#include "code_periph_use_exemple.h"
	#include "option_bytes.h"

//------------------ PROTOTYPE -------------------------------------------------------------------------------- PROTOTYPE ------------------------------------------------------*/
	void Error_Handler(void);

//------------------ END SPECIAL DEFINE ----------------------------------------------------------------------- END SPECIAL DEFINE ---------------------------------------------*/
	#ifdef __cplusplus
	}
	#endif

	#endif /* PROJECT_FOLDERS_USER_MAIN_H */
