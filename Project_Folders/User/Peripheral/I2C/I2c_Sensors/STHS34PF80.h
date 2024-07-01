/********************************************************************************
  * @file           : STHS34PF80.h
  * @brief          : Header for STHS34PF80.c file.
  *******************************************************************************/

//------------------ SPECIAL DEFINE ------------------------------------------------------------------------- SPECIAL DEFINE ---------------------------------------------------*/
#ifndef PROJECT_FOLDERS_USER_PERIPHERAL_I2C_SENSORS_STHS34PF80_H_
#define PROJECT_FOLDERS_USER_PERIPHERAL_I2C_SENSORS_STHS34PF80_H_

//------------------ INCLUDE -------------------------------------------------------------------------------- INCLUDE ----------------------------------------------------------*/
	#include "full_ll_include.h"
	#include "project_option.h"

//------------------ DEFINE --------------------------------------------------------------------------------- DEFINE -----------------------------------------------------------*/
	#define	SENSOR_ADDR		0x5A

	/* Address_Register */
	#define	STHS34PF80_LPF1		       0x0C  //Read and Write
	#define	STHS34PF80_LPF2            0x0D  //Read and Write
	#define	STHS34PF80_WHO_AM_I        0x0F  //Read (value = 0xD3)
	#define	STHS34PF80_AVG_TRIM        0x10  //Read and Write
	#define	STHS34PF80_CTRL0           0x17  //Read and Write
	#define	STHS34PF80_SENS_DATA       0x1D  //Read and Write
	#define	STHS34PF80_CTRL1           0x20  //Read and Write
	#define	STHS34PF80_CTRL2           0x21  //Read and Write
	#define	STHS34PF80_CTRL3           0x22  //Read and Write
	#define	STHS34PF80_STATUS          0x23  //Read
	#define	STHS34PF80_FUNC_STATUS     0x25  //Read
	#define	STHS34PF80_TOBJECT_L       0x26  //Read
	#define	STHS34PF80_TOBJECT_H       0x27  //Read
	#define	STHS34PF80_TAMBIENT_L      0x28  //Read
	#define STHS34PF80_TAMBIENT_H      0x29  //Read
	#define	STHS34PF80_TOBJ_COMP_L     0x38  //Read
	#define	STHS34PF80_TOBJ_COMP_H     0x39  //Read
	#define	STHS34PF80_TPRESENCE_L     0x3A  //Read
	#define	STHS34PF80_TPRESENCE_H     0x3B  //Read
	#define	STHS34PF80_TMOTION_L       0x3C  //Read
	#define	STHS34PF80_TMOTION_H       0x3D  //Read
	#define	STHS34PF80_TAMB_SHOCK_L    0x3E  //Read
	#define	STHS34PF80_TAMB_SHOCK_H    0x3F  //Read

//------------------ PROTOTYPE ------------------------------------------------------------------------------ PROTOTYPE --------------------------------------------------------*/
	/* Data_Register */
	typedef struct
		{
			uint8_t	LPF1;					//(Default = 0x04)
			uint8_t	LPF2;					//(Default = 0x22)
			uint8_t	AVG_TRIM;				//(Default = 0x03)
			uint8_t	CTRL0;					//(Default = 0xF1)
			uint8_t	SENS_DATA;				//(Default = 0x00)
			uint8_t	CTRL1;					//(Default = 0x00)
			uint8_t	CTRL2;					//(Default = 0x00)
			uint8_t	CTRL3;					//(Default = 0x00)
		} STHS34PF80_data_reg;

//------------------ PROTOTYPE ------------------------------------------------------------------------------ PROTOTYPE --------------------------------------------------------*/
	void I2C_STHS34PF80_Data_Reg_Init (void);

	void I2C_STHS34PF80_Write (uint8_t addr_reg, uint8_t data);
	void I2C_STHS34PF80_Read  (uint8_t addr_reg);

	/* Function to activate temperature and motion. */
	uint8_t I2C_STHS34PF80_Check_Activ_Tambient_Tobject (void);
	void I2C_STHS34PF80_Enabled_Tambient_Tobject (void);
	void I2C_STHS34PF80_Disable_Tambient_Tobject (void);

	void I2C_STHS34PF80_Read_Tambient (void);
	void Display_Temperature (int16_t value);


//------------------ END SPECIAL DEFINE --------------------------------------------------------------------- END SPECIAL DEFINE -----------------------------------------------*/
#endif /* PROJECT_FOLDERS_USER_PERIPHERAL_I2C_SENSORS_STHS34PF80_H_ */
