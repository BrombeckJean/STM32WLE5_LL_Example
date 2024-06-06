//********************************************************************************
//* @file           : clock_conf.c
//* @brief          : clock configuration folder.
//********************************************************************************

//------------------ INCLUDE -------------------------------------------------------------------------------- INCLUDE --------------------------------------------------------*/
	#include "clock_conf.h"

//------------------ SYSTEM CLOCK CONFIG -------------------------------------------------------------------- SYSTEM CLOCK CONFIG --------------------------------------------*/
	void system_clock_config( void )
	{
		/* declaration */
		//Clock USE
		uint8_t MSI = 0;
		uint8_t HSI = 0;
		uint8_t LSI = 0;
		uint8_t HSE = 1;
		uint8_t LSE = 0;
		uint8_t PLL = 0;
		const bool useRegulatorVoltage2 = true;
		#define Clock_Src  LL_RCC_SYS_CLKSOURCE_HSE


		//flash latency configuration
	    LL_FLASH_SetLatency( LL_FLASH_LATENCY_2 );
	    while( LL_FLASH_GetLatency( ) != LL_FLASH_LATENCY_2 ){};

	    //regulator voltage configuration
		LL_PWR_SetRegulVoltageScaling(useRegulatorVoltage2 ? LL_PWR_REGU_VOLTAGE_SCALE2 : LL_PWR_REGU_VOLTAGE_SCALE1); // latency 1 (1.2V) more MCU FREQ -> more CONSO or 2 (1.0V) less MCU FREQ -> less CONSO .

		//HSE clock configuration and starting
		if (HSE==1)
		{
			if(useRegulatorVoltage2)
			{
				LL_RCC_HSE_EnableDiv2();
			}
			else
			{
				LL_RCC_HSE_DisableDiv2();
			}
			LL_RCC_HSE_EnableTcxo(); // external Quartz TCXO specificity.
			LL_RCC_HSE_Enable();
			while(LL_RCC_HSE_IsReady() == 0);
		}

		//HSI clock configuration and starting
		if (HSI==1)
		{
			LL_RCC_HSI_SetCalibTrimming(64);
			LL_RCC_HSI_Enable();
			while(LL_RCC_HSI_IsReady() == 0);
		}

		//MSI clock configuration and starting
		if (MSI==1)
		{
			LL_RCC_MSI_Enable();
			while(LL_RCC_MSI_IsReady() == 0);
		}

		//LSI clock configuration and starting
		if (LSI==1)
		{
			LL_RCC_LSI_Enable( );
			while( LL_RCC_LSI_IsReady( ) == 0 );
		}

	    //PLL clock configuration and starting
		if (PLL==1)
		{
			LL_RCC_PLL_ConfigDomain_SYS( LL_RCC_PLLSOURCE_HSE, LL_RCC_PLLM_DIV_1, 6, LL_RCC_PLLR_DIV_6);
			LL_RCC_PLL_Enable( );
			LL_RCC_PLL_EnableDomain_SYS();
			while( LL_RCC_PLL_IsReady( ) == 0 );
		}

		//Prescalers configuration
		LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
		LL_RCC_SetAHB3Prescaler(LL_RCC_SYSCLK_DIV_1);
		LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
		LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_1);

	    //set system clock
	    LL_RCC_SetSysClkSource( Clock_Src );
	    if((LL_RCC_GetSysClkSource() >> RCC_CFGR_SWS_Pos) == LL_RCC_SYS_CLKSOURCE_MSI)
	    {
	    	while(1);
	    }
		while((LL_RCC_GetSysClkSource() >> RCC_CFGR_SWS_Pos) != Clock_Src);

	    //set HSI as clock source for wake-up from Stop mode
	    LL_RCC_SetClkAfterWakeFromStop(LL_RCC_STOP_WAKEUPCLOCK_HSI);

	    //enable Backup Domain
	    LL_PWR_EnableBkUpAccess( );
	    while(LL_PWR_IsEnabledBkUpAccess() == 0);

	    // reset of Backup Domain
	    LL_RCC_ForceBackupDomainReset();
	    LL_RCC_ReleaseBackupDomainReset();


	    //enable LSE
		if (LSE==1)
		{
			LL_RCC_LSE_SetDriveCapability(LL_RCC_LSEDRIVE_LOW);
			LL_RCC_LSE_EnablePropagation();
			LL_RCC_LSE_Enable();
			while(LL_RCC_LSE_IsReady() == 0);
		}

	    //LL_RCC_SetRTCClockSource( LL_RCC_RTC_CLKSOURCE_LSE );
	    //LL_RCC_EnableRTC( );

	    //disable unused clocks
	    if (MSI==1)
	    	LL_RCC_MSI_Disable();
	    if (HSI==1)
	    	LL_RCC_HSI_Disable();
	    if (LSI==1)
			LL_RCC_LSI_Disable();
	    if (HSE==1)
	    	LL_RCC_HSE_Disable();
	    if (LSE==1)
	    	LL_RCC_LSE_Disable();
	}

//------------------ SYSTICK CONF ---------------------------------------------------------------------------- SYSTICK CONF --------------------------------------------------*/
	void systick_conf (void)
	{
		LL_Init1msTick(GetSystemClockFreq());
		LL_SetSystemCoreClock(GetSystemClockFreq());
		LL_SYSTICK_SetClkSource(LL_SYSTICK_CLKSOURCE_HCLK);
		NVIC_SetPriority(SysTick_IRQn, TICK_INT_PRIORITY);
		LL_SYSTICK_EnableIT();
	}

//------------------ PLL GETFREQDOMAIM SYS ------------------------------------------------------------------- PLL GETFREQDOMAIM SYS -----------------------------------------*/
	uint32_t PLL_GetFreqDomain_SYS(void)
	{
	  uint32_t pllinputfreq;
	  uint32_t pllsource;

	  /* PLL_VCO = (HSE_VALUE or HSI_VALUE or MSI Value/ PLLM) * PLLN
	     SYSCLK = PLL_VCO / PLLR
	  */
	  pllsource = LL_RCC_PLL_GetMainSource();

	  switch (pllsource)
	  {
	    case LL_RCC_PLLSOURCE_MSI:  /* MSI used as PLL clock source */
	      pllinputfreq = __LL_RCC_CALC_MSI_FREQ(LL_RCC_MSI_IsEnabledRangeSelect(), ((LL_RCC_MSI_IsEnabledRangeSelect()  == 1U) ? LL_RCC_MSI_GetRange() : LL_RCC_MSI_GetRangeAfterStandby()));
	      break;

	    case LL_RCC_PLLSOURCE_HSI:  /* HSI used as PLL clock source */
	      pllinputfreq = HSI_VALUE;
	      break;

	    case LL_RCC_PLLSOURCE_HSE:  /* HSE used as PLL clock source */
	      if (LL_RCC_HSE_IsEnabledDiv2() == 1U)
	      {
	        pllinputfreq = HSE_VALUE / 2U;
	      }
	      else
	      {
	        pllinputfreq = HSE_VALUE;
	      }
	      break;


	    default:
	      pllinputfreq = __LL_RCC_CALC_MSI_FREQ(LL_RCC_MSI_IsEnabledRangeSelect(),
	                                            ((LL_RCC_MSI_IsEnabledRangeSelect()  == 1U) ?
	                                             LL_RCC_MSI_GetRange() :
	                                             LL_RCC_MSI_GetRangeAfterStandby()));
	      break;
	  }
	  return __LL_RCC_CALC_PLLCLK_FREQ(pllinputfreq, LL_RCC_PLL_GetDivider(),
	                                   LL_RCC_PLL_GetN(), LL_RCC_PLL_GetR());
	}

//------------------ GETSYSTEMCLOCKFREQ ---------------------------------------------------------------------- GETSYSTEMCLOCKFREQ --------------------------------------------*/
	uint32_t GetSystemClockFreq(void)
	{
	  uint32_t frequency;

	  /* Get SYSCLK source -------------------------------------------------------*/
	  switch (LL_RCC_GetSysClkSource())
	  {
	    case LL_RCC_SYS_CLKSOURCE_STATUS_MSI:  /* MSI used as system clock source */
	      frequency = __LL_RCC_CALC_MSI_FREQ(LL_RCC_MSI_IsEnabledRangeSelect(),
	                                         ((LL_RCC_MSI_IsEnabledRangeSelect()  == 1U) ?
	                                          LL_RCC_MSI_GetRange() :
	                                          LL_RCC_MSI_GetRangeAfterStandby()));
	      break;

	    case LL_RCC_SYS_CLKSOURCE_STATUS_HSI:  /* HSI used as system clock  source */
	      frequency = HSI_VALUE;
	      break;

	    case LL_RCC_SYS_CLKSOURCE_STATUS_HSE:  /* HSE used as system clock  source */
	      if (LL_RCC_HSE_IsEnabledDiv2() == 1U)
	      {
	        frequency = HSE_VALUE / 2U;
	      }
	      else
	      {
	        frequency = HSE_VALUE;
	      }
	      break;


	    case LL_RCC_SYS_CLKSOURCE_STATUS_PLL:  /* PLL used as system clock  source */
	      frequency = PLL_GetFreqDomain_SYS();
	      break;

	    default:
	      frequency = __LL_RCC_CALC_MSI_FREQ(LL_RCC_MSI_IsEnabledRangeSelect(),
	                                         ((LL_RCC_MSI_IsEnabledRangeSelect()  == 1U) ?
	                                          LL_RCC_MSI_GetRange() :
	                                          LL_RCC_MSI_GetRangeAfterStandby()));
	      break;
	  }

	  return frequency;
	}


