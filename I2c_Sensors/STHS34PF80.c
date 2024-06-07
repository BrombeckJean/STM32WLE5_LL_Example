/************************************************************************************
* @file           : STHS34PF80.c
* @brief          : Some function to use the STHS34PF80 sensor in I2C.
***********************************************************************************/

//------------------ INCLUDE -------------------------------------------------------------------------------- INCLUDE --------------------------------------------------------*/
	#include "STHS34PF80.h"

//------------------ GLOBAL STATEMENT ----------------------------------------------------------------------- GLOBLAL STATEMENT ----------------------------------------------*/
STHS34PF80_data_reg data_reg;

extern uint8_t I2C_data_Rx;
extern uint8_t I2C_IsActiveFlag_RXNE;

//------------------ I2C STHS34PF80 DATA REG INIT ----------------------------------------------------------- I2C STHS34PF80 DATA REG INIT -----------------------------------*/
	/* @brief  Initializing All STHS34PF80 registers to their default values.
	 * @retval None. */
	void I2C_STHS34PF80_Data_Reg_Init (void)
	{
		data_reg.LPF1		= 0x04;
		data_reg.LPF2		= 0x22;
		data_reg.AVG_TRIM	= 0x03;
		data_reg.CTRL0		= 0xF1;
		data_reg.SENS_DATA	= 0x00;
		data_reg.CTRL1		= 0x00;
		data_reg.CTRL2		= 0x00;
		data_reg.CTRL3		= 0x00;
	}

//------------------ I2C STHS34PF80 WRITE ------------------------------------------------------------------- I2C STHS34PF80 WRITE -------------------------------------------*/
	/* @brief  Writing on I2C for a STHS34PF80 sensor.
	 * @param1 Refer to the Address_register in the STHS34PF80.h file.
	 * @param2 Put the new contents of the registry that you want to modify.
	 * @retval None. */
	void I2C_STHS34PF80_Write (uint8_t addr_reg, uint8_t data)
	{
		while (!LL_I2C_IsActiveFlag_TXE(I2C1));		/* Waiting for release from queue. */
		LL_I2C_TransmitData8(I2C1, addr_reg);
		LL_I2C_HandleTransfer(I2C1, SENSOR_ADDR<<1, LL_I2C_ADDRSLAVE_7BIT, 2, LL_I2C_MODE_AUTOEND, LL_I2C_GENERATE_START_WRITE);
		while (!LL_I2C_IsActiveFlag_TXE(I2C1));		/* Waiting for release from queue. */
		LL_I2C_TransmitData8(I2C1, data);
	}

//------------------ I2C STHS34PF80 READ -------------------------------------------------------------------- I2C STHS34PF80 READ --------------------------------------------*/
	/* @brief  Reading on I2C for a STHS34PF80 sensor.
	 * @param1 Refer to the Address_Register in the STHS34PF80.h file.
	 * @retval None. */
	void I2C_STHS34PF80_Read (uint8_t addr_reg)
	{
		while (!LL_I2C_IsActiveFlag_TXE(I2C1)); 	/* Waiting for release from queue. */
		LL_I2C_TransmitData8(I2C1, addr_reg);
		LL_I2C_HandleTransfer(I2C1, SENSOR_ADDR<<1, LL_I2C_ADDRSLAVE_7BIT, 1, LL_I2C_MODE_AUTOEND, LL_I2C_GENERATE_START_WRITE);
		while (!LL_I2C_IsActiveFlag_TXE(I2C1));		/* Waiting for release from queue. */

		LL_I2C_HandleTransfer(I2C1, SENSOR_ADDR<<1, LL_I2C_ADDRESSING_MODE_7BIT, 1, LL_I2C_MODE_AUTOEND, LL_I2C_GENERATE_RESTART_7BIT_READ);
	}

//------------------ I2C STHS34PF80 CHECK ACTIV TAMBIENT TOBJECT -------------------------------------------- I2C STHS34PF80 CHECK ACTIV TAMBIENT TOBJECT --------------------*/
	/* @brief  Know the value of bit 5 of register STHS34PF80_CTRL1.
	 * @retval Boolean. */
	uint8_t I2C_STHS34PF80_Check_Activ_Tambient_Tobject (void)
	{
		while (!LL_I2C_IsActiveFlag_TXE(I2C1));		/* Waiting for release from queue. */
		I2C_STHS34PF80_Read(STHS34PF80_CTRL1);
		while (!I2C_IsActiveFlag_RXNE);
		I2C_IsActiveFlag_RXNE = 0;
		return ((READ_BIT(I2C_data_Rx, 16) == (16)) ? 1 : 0);
	}

//------------------ I2C STHS34PF80 ENABLED TAMBIENT TOBJECT ------------------------------------------------ I2C STHS34PF80 ENABLED TAMBIENT TOBJECT ------------------------*/
	/* @brief  Enable the value of bit 5 of register STHS34PF80_CTRL1.
	 * @retval None. */
	void I2C_STHS34PF80_Enabled_Tambient_Tobject (void)
	{
		SET_BIT(data_reg.CTRL1, 18);
		while (!LL_I2C_IsActiveFlag_TXE(I2C1));		/* Waiting for release from queue. */
		I2C_STHS34PF80_Write(STHS34PF80_CTRL1,data_reg.CTRL1);
	}

//------------------ I2C STHS34PF80 DISABLED TAMBIENT TOBJECT ----------------------------------------------- I2C STHS34PF80 DISABLED TAMBIENT TOBJECT -----------------------*/
	/* @brief  Disable the value of bit 5 of register STHS34PF80_CTRL1.
	 * @retval None. */
	void I2C_STHS34PF80_Disable_Tambient_Tobject (void)
	{
		CLEAR_BIT(data_reg.CTRL1, 18);
		while (!LL_I2C_IsActiveFlag_TXE(I2C1));		/* Waiting for release from queue. */
		I2C_STHS34PF80_Write(STHS34PF80_CTRL1,data_reg.CTRL1);
	}

//------------------ I2C STHS34PF80 READ TAMBIENT ----------------------------------------------------------- I2C STHS34PF80 READ TAMBIENT -----------------------------------*/
	/* @brief  Current ambient temperature reading.
	 * @retval None. */
	void I2C_STHS34PF80_Read_Tambient (void)
	{
		uint16_t double_I2C_data_Rx = 0;

		/* Check if temperature and motion are activate on the sensor. */
		if (!I2C_STHS34PF80_Check_Activ_Tambient_Tobject())
		I2C_STHS34PF80_Enabled_Tambient_Tobject();

		/* Read the first byte of the temperature. */
		I2C_STHS34PF80_Read(STHS34PF80_TAMBIENT_L);
		while (!I2C_IsActiveFlag_RXNE);
		I2C_IsActiveFlag_RXNE = 0;
		double_I2C_data_Rx = I2C_data_Rx;

		/* Read the second byte of the temperature. */
		I2C_STHS34PF80_Read(STHS34PF80_TAMBIENT_H);
		while (!I2C_IsActiveFlag_RXNE);
		I2C_IsActiveFlag_RXNE = 0;
		double_I2C_data_Rx = ((uint16_t)I2C_data_Rx)<<8;

		Display_Temperature(double_I2C_data_Rx);
	}

//------------------ DISPLAY TEMPERATURE -------------------------------------------------------------------- DISPLAY TEMPERATURE --------------------------------------------*/
	/* @brief  Transmits an 8-bits character on the USART.
	 * @param1 Periphs This parameter can be a combination of the following values:
	 *         	@arg @ref LPUART1.
	 *         	@arg @ref USART1.
	 *         	@arg @ref USART2.
	 * @retval None. */
	void Display_Temperature (int16_t value)
	{
		float temp = (float) value/100;
		printf("Temperature = %.2f \n\r",temp);
	}
