/********************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************  */

//------------------ SPECIAL DEFINE ------------------------------------------------------------------------- SPECIAL DEFINE -------------------------------------------------*/
	//Define to prevent recursive inclusion
	#ifndef __MAIN_H
	#define __MAIN_H

	//C++ switch
	#ifdef __cplusplus
	extern "C" {
	#endif

//------------------ INCLUDE -------------------------------------------------------------------------------- INCLUDE --------------------------------------------------------*/
	/* outside include project */
	#include <stdint.h>   // C99 types
	#include <stdbool.h>  // bool type
	#include <stdio.h>	  // printf

	/* HAL include */
	#include "stm32wlxx_hal.h"
	#include "stm32wlxx_hal_def.h"

	/* LL include */
	#include "full_ll_include.h"

	/* Project Folders.h */
	#include "clock_conf.h"
	#include <periph_init.h>
	#include "code_periph_use_exemple.h"
	#include "STHS34PF80.h"


//------------------ PROTOTYPE -------------------------------------------------------------------------------- PROTOTYPE --------------------------------------------------------*/
	void Error_Handler(void);

//------------------ END SPECIAL DEFINE ----------------------------------------------------------------------- END SPECIAL DEFINE -----------------------------------------------*/
	#ifdef __cplusplus
	}
	#endif

	#endif /* __MAIN_H */
