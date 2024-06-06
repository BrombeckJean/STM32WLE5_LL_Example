//********************************************************************************
//* @file           : main.c
//* @brief          : main project file.
//********************************************************************************

//------------------ INCLUDE -------------------------------------------------------------------------------- INCLUDE --------------------------------------------------------*/
	#include "main.h"

//------------------ GLOBAL STATEMENT ----------------------------------------------------------------------- GLOBLAL STATEMENT ----------------------------------------------*/
	LL_GPIO_InitTypeDef  GPIO_InitStruct;
	LL_I2C_InitTypeDef 	I2C_InitStruct;

#define ON 	0
#define OFF 1

//------------------ MAIN FUNCTION -------------------------------------------------------------------------- MAIN FUNCTION --------------------------------------------------*/
	int main(void)
	{
		/*Initialisation*/
		system_clock_config();
		systick_conf();
		init_all_periph();

		NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

		while (1)
		{

		}
	}

//------------------ ERROR HANDLER --------------------------------------------------------------------------- ERROR HANDLER -------------------------------------------------*/
	void Error_Handler(void)
	{
		/* User can add his own implementation to report the HAL error return state */
		__disable_irq();
		while (1);
	}
