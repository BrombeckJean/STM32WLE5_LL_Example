/********************************************************************************
  * @file           : clock_conf.h
  * @brief          : Header for clock_conf.c file.
  *******************************************************************************/

//------------------ SPECIAL DEFINE ------------------------------------------------------------------------- SPECIAL DEFINE ---------------------------------------------------*/
#ifndef PROJECT_FOLDERS_USER_CLOCK_CONF_H_
#define PROJECT_FOLDERS_USER_CLOCK_CONF_H_

//------------------ INCLUDE -------------------------------------------------------------------------------- INCLUDE ----------------------------------------------------------*/
	/* LL include. */
	#include "full_ll_include.h"
	#include "project_option.h"

//------------------ DEFINE --------------------------------------------------------------------------------- DEFINE -----------------------------------------------------------*/
	#define Clock_Src  LL_RCC_SYS_CLKSOURCE_HSE


//------------------ PROTOTYPE ------------------------------------------------------------------------------ PROTOTYPE --------------------------------------------------------*/
	void System_Clock_Config( void );
	void Systick_Conf (void);
	uint32_t Get_System_Clock_Freq(void);
	uint32_t PLL_Get_Freq_Domain_SYS(void);
	uint32_t Get_Freq_PLL_Q_CLK(void);
	uint32_t Get_Freq_PLL_P_CLK(void);
	uint32_t PLL_clock_source (void);

//------------------ END SPECIAL DEFINE --------------------------------------------------------------------- END SPECIAL DEFINE -----------------------------------------------*/
#endif /* PROJECT_FOLDERS_USER_CLOCK_CONF_H_ */
