/********************************************************************************
 * @file           : option_bytes.h.c
 * @brief          : Configuration and initialization of GPIO.
 ********************************************************************************/

//------------------ INCLUDE -------------------------------------------------------------------------------- INCLUDE --------------------------------------------------------*/
	#include "option_bytes.h"

//------------------ GLOBAL STATEMENT ----------------------------------------------------------------------- GLOBLAL STATEMENT ----------------------------------------------*/
	extern LL_GPIO_InitTypeDef  GPIO_InitStruct;
//------------------ GPIO INIT ------------------------------------------------------------------------------ GPIO INIT ------------------------------------------------------*/
/* Fix the bad option bytes if necessary */
void CheckAndFixOptionBytes(void)
{
	const uint32_t OBUserType =
			OB_USER_BOR_LEV |
			OB_USER_nRST_STOP |
			OB_USER_nRST_STDBY |
			OB_USER_nRST_SHDW |
			OB_USER_IWDG_SW |
			OB_USER_IWDG_STOP |
			OB_USER_IWDG_STDBY |
			OB_USER_WWDG_SW |
			OB_USER_SRAM2_PE |
			OB_USER_SRAM_RST |
			OB_USER_nSWBOOT0 |
			OB_USER_nBOOT0 |
			OB_USER_nBOOT1 |
			OB_USER_BOOT_LOCK;
	const uint32_t OBUserConfig =
			OB_BOR_LEVEL_0 |
			OB_STOP_NORST |
			OB_STANDBY_NORST |
			OB_SHUTDOWN_NORST |
			OB_IWDG_SW |
			OB_IWDG_STOP_FREEZE |
			OB_IWDG_STDBY_FREEZE |
			OB_WWDG_SW |
			OB_SRAM2_PARITY_DISABLE |
			OB_SRAM_RST_NOT_ERASE |
			OB_BOOT0_FROM_PIN |
			OB_BOOT0_SET |
			OB_BOOT1_SET |
			OB_BOOT_LOCK_ENABLE;
	FLASH_OBProgramInitTypeDef OptionsBytesStruct = {0};
	bool needOBReconfig = false;

	HAL_FLASH_Unlock();
	__HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_OPTVERR);
	HAL_FLASH_OB_Unlock();
	HAL_FLASHEx_OBGetConfig(&OptionsBytesStruct);

	/*if(OptionsBytesStruct.SUBGHZSPISecureAccess != OB_SUBGHZSPI_SECURE_ACCESS_DISABLE)
	{
		OptionsBytesStruct.SUBGHZSPISecureAccess = OB_SUBGHZSPI_SECURE_ACCESS_DISABLE;
		needOBReconfig = true;
	}*/
	if(OptionsBytesStruct.UserConfig != OBUserConfig)
	{
		OptionsBytesStruct.UserConfig = OBUserConfig;
		OptionsBytesStruct.UserType = OBUserType;
		needOBReconfig = true;
	}

	if(needOBReconfig)
	{
	    HAL_FLASHEx_OBProgram(&OptionsBytesStruct);
	    HAL_FLASH_OB_Launch();
	}

    HAL_FLASH_OB_Lock();
    HAL_FLASH_Lock();
}
