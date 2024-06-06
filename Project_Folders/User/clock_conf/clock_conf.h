/********************************************************************************
  * @file           : clock_conf.h
  * @brief          : Header for clock_conf.c file.
  *                   This file contains the common defines of the application.
  *******************************************************************************/

//------------------ SPECIAL DEFINE ------------------------------------------------------------------------- SPECIAL DEFINE ---------------------------------------------------*/
#ifndef PROJECT_FOLDERS_INC_CLOCK_CONF_H_
#define PROJECT_FOLDERS_INC_CLOCK_CONF_H_

//------------------ INCLUDE -------------------------------------------------------------------------------- INCLUDE ----------------------------------------------------------*/
	/* outside include project */
	#include <stdint.h>   // C99 types
	#include <stdbool.h>  // bool type

	/* HAL include */
	#include "stm32wlxx_hal.h"
	#include "stm32wlxx_hal_def.h"

	/* LL include */
	#include "full_ll_include.h"

//------------------ PROTOTYPE ------------------------------------------------------------------------------ PROTOTYPE --------------------------------------------------------*/
	void system_clock_config( void );
	void systick_conf (void);
	uint32_t GetSystemClockFreq(void);
	uint32_t PLL_GetFreqDomain_SYS(void);

//------------------ END SPECIAL DEFINE --------------------------------------------------------------------- END SPECIAL DEFINE -----------------------------------------------*/
#endif /* PROJECT_FOLDERS_INC_CLOCK_CONF_H_ */
