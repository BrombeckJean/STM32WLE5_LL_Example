/********************************************************************************
  * @file           : SPI.h
  * @brief          : Header for SPI.c file.
  *                   This file contains the common defines of the application.
  *******************************************************************************/

//------------------ SPECIAL DEFINE ------------------------------------------------------------------------- SPECIAL DEFINE ---------------------------------------------------*/
#ifndef PROJECT_FOLDERS_USER_PERIPHERAL_SPI_H_
#define PROJECT_FOLDERS_USER_PERIPHERAL_SPI_H_

//------------------ INCLUDE -------------------------------------------------------------------------------- INCLUDE ----------------------------------------------------------*/
	/* LL include */
	#include "full_ll_include.h"
	#include "GPIO.h"
	#include "project_option.h"

//------------------ DEFINE --------------------------------------------------------------------------------- DEFINE -----------------------------------------------------------*/


	#define SIZE 50

	/* SPI DEBUG SUBGHZ NSS */
	#define SPI_DEBUG_SUBGHZ_NSS_GPIO_Port         GPIOA
	#define SPI_DEBUG_SUBGHZ_NSS_Pin               LL_GPIO_PIN_4
	#define SPI_DEBUG_SUBGHZ_NSS_PULL              LL_GPIO_PULL_NO
	#define SPI_DEBUG_SUBGHZ_NSS_OUTPUT            LL_GPIO_OUTPUT_PUSHPULL
	#define SPI_DEBUG_SUBGHZ_NSS_AF                LL_GPIO_AF_13

	/* SPI DEBUG SUBGHZ SCK */
	#define SPI_DEBUG_SUBGHZ_SCK_GPIO_Port         GPIOA
	#define SPI_DEBUG_SUBGHZ_SCK_Pin               LL_GPIO_PIN_5
	#define SPI_DEBUG_SUBGHZ_SCK_PULL              LL_GPIO_PULL_NO
	#define SPI_DEBUG_SUBGHZ_SCK_OUTPUT            LL_GPIO_OUTPUT_PUSHPULL
	#define SPI_DEBUG_SUBGHZ_SCK_AF                LL_GPIO_AF_13

	/* SPI DEBUG SUBGHZ MISO */
	#define SPI_DEBUG_SUBGHZ_MISO_GPIO_Port         GPIOA
	#define SPI_DEBUG_SUBGHZ_MISO_Pin               LL_GPIO_PIN_6
	#define SPI_DEBUG_SUBGHZ_MISO_PULL              LL_GPIO_PULL_NO
	#define SPI_DEBUG_SUBGHZ_MISO_OUTPUT            LL_GPIO_OUTPUT_PUSHPULL
	#define SPI_DEBUG_SUBGHZ_MISO_AF                LL_GPIO_AF_13

	/* SPI DEBUG SUBGHZ MOSI */
	#define SPI_DEBUG_SUBGHZ_MOSI_GPIO_Port         GPIOA
	#define SPI_DEBUG_SUBGHZ_MOSI_Pin               LL_GPIO_PIN_7
	#define SPI_DEBUG_SUBGHZ_MOSI_PULL              LL_GPIO_PULL_NO
	#define SPI_DEBUG_SUBGHZ_MOSI_OUTPUT            LL_GPIO_OUTPUT_PUSHPULL
	#define SPI_DEBUG_SUBGHZ_MOSI_AF                LL_GPIO_AF_13

	/* ANTENNA SW CTRL1 */
	#define ANTENNA_SW_CTRL1_GPIO_Port				GPIOB
	#define ANTENNA_SW_CTRL1_MISO_Pin               LL_GPIO_PIN_12
	#define ANTENNA_SW_CTRL1_MISO_PULL              LL_GPIO_PULL_DOWN
	#define ANTENNA_SW_CTRL1_MISO_OUTPUT            LL_GPIO_OUTPUT_OPENDRAIN
	#define ANTENNA_SW_CTRL1_MISO_AF                LL_GPIO_AF_0

	/* ANTENNA SW CTRL2 */
	#define ANTENNA_SW_CTRL2_MOSI_GPIO_Port         GPIOC
	#define ANTENNA_SW_CTRL2_MOSI_Pin               LL_GPIO_PIN_13
	#define ANTENNA_SW_CTRL2_MOSI_PULL              LL_GPIO_PULL_DOWN
	#define ANTENNA_SW_CTRL2_MOSI_OUTPUT            LL_GPIO_OUTPUT_OPENDRAIN
	#define ANTENNA_SW_CTRL2_MOSI_AF                LL_GPIO_AF_0

//------------------ PROTOTYPE ------------------------------------------------------------------------------ PROTOTYPE --------------------------------------------------------*/
	void Spi_Subghz_Init(void);
	HAL_StatusTypeDef Spi_SUBGHZ_Write_Register(SUBGHZ_HandleTypeDef *hsubghz_SSWR, uint16_t Address_SSWR, uint8_t *pBuffer, uint16_t Size_SSWR);
	HAL_StatusTypeDef Spi_SUBGHZ_Read_Register(SUBGHZ_HandleTypeDef *hsubghz_SSRR, uint16_t Address_SSRR, uint8_t *pBuffer, uint16_t Size_SSRR);
	HAL_StatusTypeDef Spi_SUBGHZ_Set_Command(SUBGHZ_HandleTypeDef *hsubghz_SSSC, SUBGHZ_RadioSetCmd_t Command_SSSC, uint8_t *pBuffer, uint16_t Size_SSSC);
	HAL_StatusTypeDef Spi_SUBGHZ_Get_Command(SUBGHZ_HandleTypeDef *hsubghz_SSGC, SUBGHZ_RadioSetCmd_t Command_SSGC, uint8_t *pBuffer, uint16_t Size_SSGC);

	/*void HAL_SUBGHZ_MspInit(SUBGHZ_HandleTypeDef* subghzHandle);
	void HAL_SUBGHZ_MspDeInit(SUBGHZ_HandleTypeDef* subghzHandle);*/

//------------------ END SPECIAL DEFINE --------------------------------------------------------------------- END SPECIAL DEFINE -----------------------------------------------*/
#endif /* PROJECT_FOLDERS_USER_PERIPHERAL_SPI_H_ */
