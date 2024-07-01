/********************************************************************************
  * @file           : full_ll_include.h
  *******************************************************************************/

//------------------ SPECIAL DEFINE ------------------------------------------------------------------------- SPECIAL DEFINE ---------------------------------------------------*/
#ifndef PROJECT_FOLDERS_USER_INC_FULL_LL_INCLUDE_H_
#define PROJECT_FOLDERS_USER_INC_FULL_LL_INCLUDE_H_

//------------------ INCLUDE -------------------------------------------------------------------------------- INCLUDE ----------------------------------------------------------*/
	/* outside include project. */
	#include <stdint.h>   /* C99 types	*/
	#include <stdbool.h>  /* bool type	*/
	#include <stdio.h>	  /* printf 	*/
	#include <float.h>

	/* HAL include */
	#include "stm32wlxx_hal.h"
	#include "stm32wlxx_hal_def.h"

	/* LL include. */
	#include "stm32wlxx_ll_adc.h"
	#include "stm32wlxx_ll_bus.h"
	#include "stm32wlxx_ll_comp.h"
	#include "stm32wlxx_ll_cortex.h"
	#include "stm32wlxx_ll_crc.h"
	#include "stm32wlxx_ll_dac.h"
	#include "stm32wlxx_ll_dma.h"
	#include "stm32wlxx_ll_dmamux.h"
	#include "stm32wlxx_ll_exti.h"
	#include "stm32wlxx_ll_gpio.h"
	#include "stm32wlxx_ll_hsem.h"
	#include "stm32wlxx_ll_i2c.h"
	#include "stm32wlxx_ll_ipcc.h"
	#include "stm32wlxx_ll_iwdg.h"
	#include "stm32wlxx_ll_lptim.h"
	#include "stm32wlxx_ll_lpuart.h"
	#include "stm32wlxx_ll_pka.h"
	#include "stm32wlxx_ll_pwr.h"
	#include "stm32wlxx_ll_rcc.h"
	#include "stm32wlxx_ll_rng.h"
	#include "stm32wlxx_ll_rtc.h"
	#include "stm32wlxx_ll_spi.h"
	#include "stm32wlxx_ll_system.h"
	#include "stm32wlxx_ll_tim.h"
	#include "stm32wlxx_ll_usart.h"
	#include "stm32wlxx_ll_utils.h"
	#include "stm32wlxx_ll_wwdg.h"

	/* Cortex M4 lib. */
	#include "core_cm4.h"

//------------------ END SPECIAL DEFINE --------------------------------------------------------------------- END SPECIAL DEFINE -----------------------------------------------*/
#endif /* PROJECT_FOLDERS_USER_INC_FULL_LL_INCLUDE_H_ */
