/********************************************************************************
 * @file           : main.c
 * @brief          : main project file.
 *********************************************************************************/

//------------------ INCLUDE -------------------------------------------------------------------------------- INCLUDE --------------------------------------------------------*/
	#include "main.h"

//------------------ GLOBAL STATEMENT ----------------------------------------------------------------------- GLOBLAL STATEMENT ----------------------------------------------*/
	LL_GPIO_InitTypeDef  GPIO_InitStruct;
	LL_I2C_InitTypeDef 	 I2C_InitStruct;
	SUBGHZ_HandleTypeDef hsubghz;

//------------------ MAIN FUNCTION -------------------------------------------------------------------------- MAIN FUNCTION --------------------------------------------------*/
	int main(void)
	{
		/*Initialization*/
		CheckAndFixOptionBytes();
		System_Clock_Config();
		Systick_Conf();
		Init_Periph_Use();

		NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

		while (1)
		{
	    	uint8_t Size = 7;
	    	uint16_t addr = 0x029F;
	    	uint8_t buffers [9] = {0};
	    	uint8_t buffer_data [9] = {0};

	        HAL_SUBGHZ_ReadRegisters (&hsubghz, addr, buffers, Size);
	        buffers[0] = 0x3; buffers[1] = 0x8; buffers[2] = 0xac; buffers[3] = 0x8; buffers[4] = 0x89;
	        buffers[5] = 0x7; buffers[6] = 0x36;
	        Spi_SUBGHZ_Write_Register(&hsubghz, addr, buffers, Size);
	        Spi_SUBGHZ_Read_Register (&hsubghz, addr, buffer_data, Size);

			HAL_Delay(2000);
		}
	}

//------------------ ERROR HANDLER --------------------------------------------------------------------------- ERROR HANDLER -------------------------------------------------*/
	void Error_Handler(void)
	{
		/* User can add his own implementation to report the HAL error return state. */
		__disable_irq();
		while (1);
	}
