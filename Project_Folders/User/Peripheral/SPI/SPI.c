/********************************************************************************
 * @file           : SPI.c
 * @brief          : Configuration and initialization of SPI.
 ********************************************************************************/

//------------------ INCLUDE -------------------------------------------------------------------------------- INCLUDE --------------------------------------------------------*/
	#include "SPI.h"

//------------------ GLOBAL STATEMENT ----------------------------------------------------------------------- GLOBLAL STATEMENT ----------------------------------------------*/
	extern SUBGHZ_HandleTypeDef hsubghz;
	extern void Error_Handler(void);

	#ifdef debug_SUBGHZ_help
		/* Table to know what was sent to the SPI */
		/* Write Register */
		uint16_t spi_subghz_data_WR[SIZE]={0};
		uint16_t index_WR=0;

		/* Read Register */
		uint16_t spi_subghz_data_RR[SIZE]={0};
		uint16_t index_RR=0;

		/* Set Command */
		uint8_t spi_subghz_data_SC[SIZE]={0};
		uint16_t index_SC=0;

		/* Get Command */
		uint8_t spi_subghz_data_GC[SIZE]={0};
		uint16_t index_GC=0;
	#endif

//------------------ SPI SUBGHZ INIT ------------------------------------------------------------------------ SPI SUBGHZ INIT ------------------------------------------------*/
	/* @brief  Initializing SPI SUBGHZ
	 * @retval None */
	void Spi_Subghz_Init(void)
	{
		#ifdef debug_SUBGHZ_help
			Gpio_Init(SPI_DEBUG_SUBGHZ_NSS_GPIO_Port,  SPI_DEBUG_SUBGHZ_NSS_Pin,  LL_GPIO_MODE_ALTERNATE, SPI_DEBUG_SUBGHZ_NSS_PULL,  LL_GPIO_SPEED_FREQ_HIGH, SPI_DEBUG_SUBGHZ_NSS_OUTPUT,  SPI_DEBUG_SUBGHZ_NSS_AF);
			Gpio_Init(SPI_DEBUG_SUBGHZ_SCK_GPIO_Port,  SPI_DEBUG_SUBGHZ_SCK_Pin,  LL_GPIO_MODE_ALTERNATE, SPI_DEBUG_SUBGHZ_SCK_PULL,  LL_GPIO_SPEED_FREQ_HIGH, SPI_DEBUG_SUBGHZ_SCK_OUTPUT,  SPI_DEBUG_SUBGHZ_SCK_AF);
			Gpio_Init(SPI_DEBUG_SUBGHZ_MISO_GPIO_Port, SPI_DEBUG_SUBGHZ_MISO_Pin, LL_GPIO_MODE_ALTERNATE, SPI_DEBUG_SUBGHZ_MISO_PULL, LL_GPIO_SPEED_FREQ_HIGH, SPI_DEBUG_SUBGHZ_MISO_OUTPUT, SPI_DEBUG_SUBGHZ_MISO_AF);
			Gpio_Init(SPI_DEBUG_SUBGHZ_MOSI_GPIO_Port, SPI_DEBUG_SUBGHZ_MOSI_Pin, LL_GPIO_MODE_ALTERNATE, SPI_DEBUG_SUBGHZ_MOSI_PULL, LL_GPIO_SPEED_FREQ_HIGH, SPI_DEBUG_SUBGHZ_MOSI_OUTPUT, SPI_DEBUG_SUBGHZ_MOSI_AF);
		#endif

		/* Chip select control type */
		LL_PWR_SetSUBGHZSPI_NSSSource(LL_PWR_SUBGHZSPI_NSS_SRC_SW);
		//LL_PWR_SetSUBGHZSPI_NSSSource(LL_PWR_SUBGHZSPI_NSS_SRC_LPTIM3);

		hsubghz.Init.BaudratePrescaler = SUBGHZSPI_BAUDRATEPRESCALER_4;
		if (HAL_SUBGHZ_Init(&hsubghz) != HAL_OK)
		{
			Error_Handler();
		}
	}

//------------------ HAL SUBGHZ MSP INIT -------------------------------------------------------------------- HAL SUBGHZ MSP INIT --------------------------------------------*/
	void HAL_SUBGHZ_MspInit(SUBGHZ_HandleTypeDef* subghzHandle)
	{

	  /* USER CODE BEGIN SUBGHZ_MspInit 0 */

	  /* USER CODE END SUBGHZ_MspInit 0 */
		/* SUBGHZ clock enable */
		__HAL_RCC_SUBGHZSPI_CLK_ENABLE();

		/* SUBGHZ interrupt Init */
		HAL_NVIC_SetPriority(SUBGHZ_Radio_IRQn, 0, 0);
		HAL_NVIC_EnableIRQ(SUBGHZ_Radio_IRQn);
		HAL_NVIC_SetPriority(SUBGHZSPI_IRQn, 0, 0);
		HAL_NVIC_EnableIRQ(SUBGHZSPI_IRQn);
	  /* USER CODE BEGIN SUBGHZ_MspInit 1 */

	  /* USER CODE END SUBGHZ_MspInit 1 */
	}

//------------------ HAL SUBGHZ MSP DEINIT ------------------------------------------------------------------ HAL SUBGHZ MSP DEINIT ------------------------------------------*/
	void HAL_SUBGHZ_MspDeInit(SUBGHZ_HandleTypeDef* subghzHandle)
	{

	  /* USER CODE BEGIN SUBGHZ_MspDeInit 0 */

	  /* USER CODE END SUBGHZ_MspDeInit 0 */
		/* Peripheral clock disable */
		__HAL_RCC_SUBGHZSPI_CLK_DISABLE();

		/* SUBGHZ interrupt Deinit */
		HAL_NVIC_DisableIRQ(SUBGHZ_Radio_IRQn);
		HAL_NVIC_DisableIRQ(SUBGHZSPI_IRQn);
	  /* USER CODE BEGIN SUBGHZ_MspDeInit 1 */

	  /* USER CODE END SUBGHZ_MspDeInit 1 */
	}

//------------------ SPI SUBGHZ SET COMMAND ----------------------------------------------------------------- SPI SUBGHZ SET COMMAND -----------------------------------------*/
	/* @brief  Write command in SUBGHZ by the SPI SUBGHZ
	 * @retval None */
	HAL_StatusTypeDef Spi_SUBGHZ_Set_Command(SUBGHZ_HandleTypeDef *hsubghz_SSSC, SUBGHZ_RadioSetCmd_t Command_SSSC, uint8_t *pBuffer, uint16_t Size_SSSC)
	{
		#ifdef debug_SUBGHZ_help
			uint16_t i;
			spi_subghz_data_SC[index_SC++] = Command_SSSC;
			for (i = 0; i < Size_SSSC; i++)
			{
				spi_subghz_data_SC[i+index_SC] = pBuffer[i];
			}
			index_SC= index_SC + i;
			spi_subghz_data_SC[index_SC++] = 0xf0;
		#endif

		HAL_StatusTypeDef status = HAL_SUBGHZ_ExecSetCmd(hsubghz_SSSC, Command_SSSC, pBuffer, Size_SSSC);

		return status;
	}

//------------------ SPI SUBGHZ GET COMMAND ----------------------------------------------------------------- SPI SUBGHZ GET COMMAND -----------------------------------------*/
	/* @brief Read command in SUBGHZ by the SPI SUBGHZ
	 * @retval None */
	HAL_StatusTypeDef Spi_SUBGHZ_Get_Command(SUBGHZ_HandleTypeDef *hsubghz_SSGC, SUBGHZ_RadioSetCmd_t Command_SSGC, uint8_t *pBuffer, uint16_t Size_SSGC)
	{
		HAL_StatusTypeDef status = HAL_SUBGHZ_ExecGetCmd(hsubghz_SSGC, Command_SSGC, pBuffer, Size_SSGC);

		#ifdef debug_SUBGHZ_help
			uint16_t i;
			spi_subghz_data_GC[index_GC++] = Command_SSGC;
			for (i = 0; i < Size_SSGC; i++)
			{
				spi_subghz_data_GC[i+index_GC] = pBuffer[i];
			}
			index_SC= index_GC + i;
			spi_subghz_data_GC[index_GC++] = 0xf0;
		#endif

		return status;
	}

//------------------ SPI SUBGHZ WRITE REGISTER -------------------------------------------------------------- SPI SUBGHZ WRITE REGISTER --------------------------------------*/
	/* @brief  Write data in SUBGHZ register by the SPI SUBGHZ
	 * @retval None */
	HAL_StatusTypeDef Spi_SUBGHZ_Write_Register(SUBGHZ_HandleTypeDef *hsubghz_SSWR, uint16_t Address_SSWR, uint8_t *pBuffer, uint16_t Size_SSWR)
	{
		#ifdef debug_SUBGHZ_help
			uint16_t i;
			spi_subghz_data_WR[index_WR++] = Address_SSWR;
			for (i = 0; i < Size_SSWR; i++)
			{
			  spi_subghz_data_WR[i+index_WR] = (uint16_t) pBuffer[i];
			}
			index_WR = index_WR+i;
			spi_subghz_data_WR[index_WR++] = 0xf00f;
		#endif

			HAL_StatusTypeDef status = HAL_SUBGHZ_WriteRegisters(hsubghz_SSWR, Address_SSWR, pBuffer, Size_SSWR);
			return status;
	}

//------------------ SPI SUBGHZ READ REGISTER --------------------------------------------------------------- SPI SUBGHZ READ REGISTER ---------------------------------------*/
	/* @brief  Read data in SUBGHZ register by the SPI SUBGHZ
	 * @retval None */
	HAL_StatusTypeDef Spi_SUBGHZ_Read_Register(SUBGHZ_HandleTypeDef *hsubghz_SSRR, uint16_t Address_SSRR, uint8_t *pBuffer, uint16_t Size_SSRR)
	{
		HAL_StatusTypeDef status = HAL_SUBGHZ_ReadRegisters(hsubghz_SSRR, Address_SSRR, pBuffer, Size_SSRR);

		#ifdef debug_SUBGHZ_help
			uint16_t i;
			spi_subghz_data_RR[index_RR++] = Address_SSRR;
			for (i = 0; i < Size_SSRR; i++)
			{
				  spi_subghz_data_RR[i+index_RR] = pBuffer[i];
			} index_RR= index_RR +i;
			spi_subghz_data_RR[index_RR++] = 0xf00f;
		#endif

		return status;
	}

//------------------ SPI SUBGHZ WRITE BUFFER ---------------------------------------------------------------- SPI SUBGHZ WRITE BUFFER ----------------------------------------*/
	/* @brief  Write data in SUBGHZ buffer by the SPI SUBGHZ
	 * @retval None */
	HAL_StatusTypeDef Spi_SUBGHZ_Write_Buffer(SUBGHZ_HandleTypeDef *hsubghz_SSWB, uint16_t offset_SSWB, uint8_t *pBuffer, uint16_t Size_SSWB)
	{
		#ifdef debug_SUBGHZ_help
			uint16_t i;
			spi_subghz_data_WR[index_WR++] = offset_SSWB;
			for (i = 0; i < Size_SSWB; i++)
			{
			  spi_subghz_data_WR[i+index_WR] = (uint16_t) pBuffer[i];
			}
			index_WR = index_WR+i;
			spi_subghz_data_WR[index_WR++] = 0xf00f;
		#endif

			HAL_StatusTypeDef status = HAL_SUBGHZ_WriteBuffer(hsubghz_SSWB, offset_SSWB, pBuffer, Size_SSWB);
			return status;
	}

//------------------ SPI SUBGHZ READ BUFFER ----------------------------------------------------------------- SPI SUBGHZ READ BUFFER -----------------------------------------*/
	/* @brief  Read data in SUBGHZ buffer by the SPI SUBGHZ
	 * @retval None */
	HAL_StatusTypeDef Spi_SUBGHZ_Read_Buffer(SUBGHZ_HandleTypeDef *hsubghz_SSRB, uint16_t offset_SSRB, uint8_t *pBuffer, uint16_t Size_SSRB)
	{
		HAL_StatusTypeDef status = HAL_SUBGHZ_ReadBuffer(hsubghz_SSRB, offset_SSRB, pBuffer, Size_SSRB);

		#ifdef debug_SUBGHZ_help
			uint16_t i;
			spi_subghz_data_RR[index_RR++] = offset_SSRB;
			for (i = 0; i < Size_SSRR; i++)
			{
				  spi_subghz_data_RR[i+index_RR] = pBuffer[i];
			} index_RR= index_RR +i;
			spi_subghz_data_RR[index_RR++] = 0xf00f;
		#endif

		return status;
	}

//------------------ SUBGHZ SEND LORA MSG ------------------------------------------------------------------- SUBGHZ SEND LORA MSG -------------------------------------------*/
	/* @brief Read command in SUBGHZ by the SPI SUBGHZ
	 * @retval None */
	HAL_StatusTypeDef SUBGHZ_Send_lora_msg(void)
	{
		uint8_t val = 0;
		HAL_StatusTypeDef status = Spi_SUBGHZ_Set_Command(hsubghz, RADIO_SET_STANDBY, &val, 1);

		HAL_StatusTypeDef status = Spi_SUBGHZ_Set_Command(hsubghz, RADIO_SET_RFFREQUENCY, pBuffer, Size);

		HAL_StatusTypeDef status = Spi_SUBGHZ_Set_Command(hsubghz, RADIO_SET_PACONFIG, pBuffer, Size);

		HAL_StatusTypeDef status = Spi_SUBGHZ_Set_Command(hsubghz, RADIO_SET_TXPARAMS, pBuffer, Size);

		HAL_StatusTypeDef status = Spi_SUBGHZ_Set_Command(hsubghz, RADIO_SET_BUFFERBASEADDRESS, pBuffer, Size);
		HAL_StatusTypeDef status = Spi_SUBGHZ_Write_Buffer(hsubghz, offset, pBuffer, Size);

		HAL_StatusTypeDef status = Spi_SUBGHZ_Set_Command(hsubghz, RADIO_SET_MODULATIONPARAMS, pBuffer, Size);

		HAL_StatusTypeDef status = Spi_SUBGHZ_Set_Command(hsubghz, RADIO_SET_PACKETPARAMS, pBuffer, Size);

		HAL_StatusTypeDef status = Spi_SUBGHZ_Set_Command(hsubghz, RADIO_CFG_DIOIRQ, pBuffer, Size);

		HAL_StatusTypeDef status = Spi_SUBGHZ_Write_Register(hsubghz, addr, pBuffer, Size);

		HAL_StatusTypeDef status = Spi_SUBGHZ_Set_Command(hsubghz, RADIO_SET_TX, pBuffer, Size);

		HAL_StatusTypeDef status = Spi_SUBGHZ_Set_Command(hsubghz, RADIO_CLR_IRQSTATUS, pBuffer, Size);

		return status;
	}

