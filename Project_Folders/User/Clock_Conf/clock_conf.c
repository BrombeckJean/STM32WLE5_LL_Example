/********************************************************************************
* @file           : clock_conf.c
* @brief          : clock configuration folder.
*********************************************************************************/

//------------------ INCLUDE -------------------------------------------------------------------------------- INCLUDE --------------------------------------------------------*/
	#include "clock_conf.h"

//------------------ GLOBAL STATEMENT ----------------------------------------------------------------------- GLOBLAL STATEMENT ----------------------------------------------*/
#ifdef clock_freq_know
	/* Clock_Freq table structure
	 * uint32_t MSI_Freq
	 * uint32_t HSI_Freq
	 * uint32_t LSI_Freq
	 * uint32_t HSE_Freq
	 * uint32_t LSE_Freq			*/
	uint32_t Clock_Freq[5] = {0};

	/* PLL output table structure
	 * uint32_t PLLPCLK
	 * uint32_t PLLQCLK
	 * uint32_t PLLRCLK				*/
	uint32_t PLL_output_Freq[3] = {0};

	/* Periph_Clock_Freq table structure
	 * uint32_t PCLK1_Freq
	 * uint32_t PCLK2_Freq
	 * uint32_t HCLK1_Freq
	 * uint32_t HCLK3_Freq			*/
	uint32_t Periph_Clock_Freq[4] = {0};
#endif

//------------------ SYSTEM CLOCK CONFIG -------------------------------------------------------------------- SYSTEM CLOCK CONFIG --------------------------------------------*/
	/* @brief  Configure all the clock you want use.
	 * @retval None. */
	void System_Clock_Config( void )
	{
		/* Clock USE */
		uint8_t MSI = 0;
		uint8_t HSI = 0;
		uint8_t LSI = 0; uint8_t prediv_LSI = 0; // if set at 1 divide by 128.
		uint8_t HSE = 1; uint8_t useRegulatorVoltage2 = 1;
		uint8_t LSE = 1;
		uint8_t PLL = 1;

		/* Flash latency configuration. */
	    LL_FLASH_SetLatency( LL_FLASH_LATENCY_2 );
	    while( LL_FLASH_GetLatency( ) != LL_FLASH_LATENCY_2 ){};

	    /* Regulator voltage configuration. */
		LL_PWR_SetRegulVoltageScaling(useRegulatorVoltage2 ? LL_PWR_REGU_VOLTAGE_SCALE2 : LL_PWR_REGU_VOLTAGE_SCALE1);
		// TO KNOW SCALE1 (1.2V) more MCU FREQ -> more CONSO or SCALE2 (1.0V) less MCU FREQ -> less CONSO .

		// MSI clock configuration and starting. ----------------*/
		if (MSI==1)
		{
			LL_RCC_MSI_EnableRangeSelection();
			LL_RCC_MSI_SetRange(LL_RCC_MSIRANGE_11);
			LL_RCC_MSI_SetCalibTrimming(0);

			LL_RCC_MSI_Enable();
			while(LL_RCC_MSI_IsReady() == 0){};

			/*Frequency output of the MSI clock*/
			#ifdef clock_freq_know
				Clock_Freq[0] = __LL_RCC_CALC_MSI_FREQ(LL_RCC_MSI_IsEnabledRangeSelect(), ((LL_RCC_MSI_IsEnabledRangeSelect()  == 1U) ? LL_RCC_MSI_GetRange() : LL_RCC_MSI_GetRangeAfterStandby()));
			#endif
		}

		// HSI clock configuration and starting. ----------------*/
		if (HSI==1)
		{
			LL_RCC_HSI_SetCalibTrimming(64);

			LL_RCC_HSI_Enable();
			while(LL_RCC_HSI_IsReady() == 0){};

			/*Frequency output of the HSI clock*/
			#ifdef clock_freq_know
				Clock_Freq[1] = HSI_VALUE;
			#endif
		}

		// LSI clock configuration and starting. ----------------*/
		if (LSI==1)
		{
			if(prediv_LSI)
			{
				LL_RCC_LSI_SetPrediv(LL_RCC_LSI_PREDIV_128);

				/* Frequency output of the LSI clock with 128 pre-scaler division */
				#ifdef clock_freq_know
					Clock_Freq[2] = LSI_VALUE/128;
				#endif
			}else{
				LL_RCC_LSI_SetPrediv(LL_RCC_LSI_PREDIV_1);

				/* Frequency output of the LSI clock with no 128 pre-scaler division */
				#ifdef clock_freq_know
					Clock_Freq[2] = LSI_VALUE;
				#endif
			}
			LL_RCC_LSI_Enable( );
			while( LL_RCC_LSI_IsReady( ) == 0 );
		}

		// HSE clock configuration and starting. ----------------*/
		if (HSE==1)
		{
			if(useRegulatorVoltage2)
			{
				LL_RCC_HSE_EnableDiv2();

				/* Frequency output of the HSE clock with division by 2 */
				#ifdef clock_freq_know
					Clock_Freq[3] = HSE_VALUE/2;
				#endif
			}else{
				LL_RCC_HSE_DisableDiv2();

				/* Frequency output of the HSE clock with no division by 2 */
				#ifdef clock_freq_know
					Clock_Freq[3] = HSE_VALUE;
				#endif
			}
			LL_RCC_HSE_EnableTcxo(); /* External Quartz TCXO specificity. */
			LL_RCC_HSE_Enable();
			while(LL_RCC_HSE_IsReady() == 0);
		}

	    // PLL clock configuration and starting. ----------------*/
		if (PLL==1)
		{
			#if rng
				LL_RCC_PLL_ConfigDomain_RNG(LL_RCC_PLLSOURCE_HSE, LL_RCC_PLLM_DIV_1, 6, LL_RCC_PLLQ_DIV_2);
				LL_RCC_PLL_EnableDomain_RNG();

				/* Frequency output of the PLLQ */
				#ifdef clock_freq_know
					PLL_output_Freq[1] = Get_Freq_PLL_Q_CLK();
					PLL_output_Freq[0] = Get_Freq_PLL_P_CLK();
				#endif
			#endif
			LL_RCC_PLL_ConfigDomain_SYS( LL_RCC_PLLSOURCE_HSE, LL_RCC_PLLM_DIV_1, 6, LL_RCC_PLLR_DIV_6);
			LL_RCC_PLL_EnableDomain_SYS();
			LL_RCC_PLL_Enable( );
			while( LL_RCC_PLL_IsReady( ) == 0 ){};

			/* Frequency output of the PLLQ */
			#ifdef clock_freq_know
				PLL_output_Freq[2] = PLL_Get_Freq_Domain_SYS();
			#endif
		}

		/* Prescalers configuration. */
		LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
		LL_RCC_SetAHB3Prescaler(LL_RCC_SYSCLK_DIV_1);
		LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
		LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_1);


	    /* Set system clock. */
	    LL_RCC_SetSysClkSource( Clock_Src );
	    if((LL_RCC_GetSysClkSource() >> RCC_CFGR_SWS_Pos) == LL_RCC_SYS_CLKSOURCE_MSI)
	    	{while(1);}
		while((LL_RCC_GetSysClkSource() >> RCC_CFGR_SWS_Pos) != Clock_Src);

	    /* Set HSI as clock source for wake-up from Stop mode. */
	    LL_RCC_SetClkAfterWakeFromStop(LL_RCC_STOP_WAKEUPCLOCK_HSI);

	    /* Enable Backup Domain. */
	    LL_PWR_EnableBkUpAccess( );
	    while(LL_PWR_IsEnabledBkUpAccess() == 0);

	    /* Reset of Backup Domain. */
	    LL_RCC_ForceBackupDomainReset();
	    LL_RCC_ReleaseBackupDomainReset();

		#ifdef clock_freq_know
			Periph_Clock_Freq[2] =  __LL_RCC_CALC_HCLK1_FREQ (Get_System_Clock_Freq(), LL_RCC_GetAHBPrescaler());
			uint32_t HCLK3_freq = __LL_RCC_CALC_HCLK3_FREQ (Get_System_Clock_Freq(), LL_RCC_GetAHB3Prescaler());
			Periph_Clock_Freq[3] = HCLK3_freq;
			Periph_Clock_Freq[0] = __LL_RCC_CALC_PCLK1_FREQ (HCLK3_freq, LL_RCC_GetAHB3Prescaler());
			Periph_Clock_Freq[1] = __LL_RCC_CALC_PCLK2_FREQ (HCLK3_freq, LL_RCC_GetAHB3Prescaler());
		#endif

		// LSE clock configuration and starting. ----------------*/
		if (LSE==1)
		{
			LL_RCC_LSE_SetDriveCapability(LL_RCC_LSEDRIVE_LOW);
			LL_RCC_LSE_EnablePropagation();
			LL_RCC_LSE_Enable();
			while(LL_RCC_LSE_IsReady() == 0){};

			/* Frequency output of the LSE */
			#ifdef clock_freq_know
				Clock_Freq[4] = LSE_VALUE;
			#endif
		}

	    //LL_RCC_SetRTCClockSource( LL_RCC_RTC_CLKSOURCE_LSE );
	    //LL_RCC_EnableRTC( );

	    /* Disable unused clocks. */
	    if (MSI==0)
	    	LL_RCC_MSI_Disable();
	    if (HSI==0)
	    	LL_RCC_HSI_Disable();
	    if (LSI==0)
			LL_RCC_LSI_Disable();
	    if (HSE==0)
	    	LL_RCC_HSE_Disable();
	    if (LSE==0)
	    	LL_RCC_LSE_Disable();
	    if (MSI + HSI + LSI + HSE + LSE == 0)
	    	{Activation_Error();}

	    /*Peripheral clock source*/

	}

//------------------ SYSTICK CONF ---------------------------------------------------------------------------- SYSTICK CONF --------------------------------------------------*/
	/* @brief  Configure the interrupt tick of the processor.
	 * @retval None. */
	void Systick_Conf (void)
	{
		LL_Init1msTick(Get_System_Clock_Freq());
		LL_SetSystemCoreClock(Get_System_Clock_Freq());
		LL_SYSTICK_SetClkSource(LL_SYSTICK_CLKSOURCE_HCLK);
		NVIC_SetPriority(SysTick_IRQn, TICK_INT_PRIORITY);
		LL_SYSTICK_EnableIT();
		__enable_irq();
	}

//------------------ GET SYSTEM CLOCK FREQ ------------------------------------------------------------------- GET SYSTEM CLOCK FREQ -----------------------------------------*/
	/* @brief  Get the system clock frequency.
	 * @retval Frequency. */
	uint32_t Get_System_Clock_Freq(void)
	{
	  uint32_t frequency;

	  /* Get SYSCLK source. */
	  switch (LL_RCC_GetSysClkSource())
	  {
	    case LL_RCC_SYS_CLKSOURCE_STATUS_MSI:  /* MSI used as system clock source. */
	      frequency = __LL_RCC_CALC_MSI_FREQ(LL_RCC_MSI_IsEnabledRangeSelect(),
	                                         ((LL_RCC_MSI_IsEnabledRangeSelect()  == 1U) ?
	                                          LL_RCC_MSI_GetRange() :
	                                          LL_RCC_MSI_GetRangeAfterStandby()));
	      break;

	    case LL_RCC_SYS_CLKSOURCE_STATUS_HSI:  /* HSI used as system clock  source. */
	      frequency = HSI_VALUE;
	      break;

	    case LL_RCC_SYS_CLKSOURCE_STATUS_HSE:  /* HSE used as system clock  source. */
	      if (LL_RCC_HSE_IsEnabledDiv2() == 1U)
	      {
	        frequency = HSE_VALUE / 2U;
	      }
	      else
	      {
	        frequency = HSE_VALUE;
	      }
	      break;


	    case LL_RCC_SYS_CLKSOURCE_STATUS_PLL:  /* PLL used as system clock  source. */
	      frequency = PLL_Get_Freq_Domain_SYS();
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

//------------------ PLL GET FREQ DOMAIM SYS ----------------------------------------------------------------- PLL GET FREQ DOMAIM SYS ---------------------------------------*/
	/* @brief  Get the frequency obtain at the end of PLL.
	 * @retval PLL frequency. */
	uint32_t PLL_Get_Freq_Domain_SYS(void)
	{
		uint32_t pllinputfreq = PLL_clock_source();

		return __LL_RCC_CALC_PLLCLK_FREQ(pllinputfreq, LL_RCC_PLL_GetDivider(), LL_RCC_PLL_GetN(), LL_RCC_PLL_GetR());
	}


//------------------ PLL GET FREQ DOMAIM SYS ----------------------------------------------------------------- PLL GET FREQ DOMAIM SYS ---------------------------------------*/
	/* @brief  Get the frequency obtain at the end of PLL.
	 * @retval PLL frequency. */
	uint32_t Get_Freq_PLL_Q_CLK(void)
	{
		uint32_t pllinputfreq = PLL_clock_source();

		return __LL_RCC_CALC_PLLCLK_RNG_FREQ (pllinputfreq, LL_RCC_PLL_GetDivider(), LL_RCC_PLL_GetN(), LL_RCC_PLL_GetQ());

	}

//------------------ PLL GET FREQ DOMAIM SYS ----------------------------------------------------------------- PLL GET FREQ DOMAIM SYS ---------------------------------------*/
	/* @brief  Get the frequency obtain at the end of PLL.
	 * @retval PLL frequency. */
	uint32_t Get_Freq_PLL_P_CLK(void)
	{
		uint32_t pllinputfreq = PLL_clock_source();

		return __LL_RCC_CALC_PLLCLK_ADC_FREQ (pllinputfreq, LL_RCC_PLL_GetDivider(), LL_RCC_PLL_GetN(), LL_RCC_PLL_GetP());
	}

//------------------ PLL GET FREQ DOMAIM SYS ----------------------------------------------------------------- PLL GET FREQ DOMAIM SYS ---------------------------------------*/
	/* @brief  Get the frequency input of the PLL.
	 * @retval PLL input frequency. */
	uint32_t PLL_clock_source (void)
	{
		uint32_t pllinputfreq;
		uint32_t pllsource;

		pllsource = LL_RCC_PLL_GetMainSource();

		switch (pllsource)
		{
		case LL_RCC_PLLSOURCE_MSI:  /* MSI used as PLL clock source. */
		  pllinputfreq = __LL_RCC_CALC_MSI_FREQ(LL_RCC_MSI_IsEnabledRangeSelect(), ((LL_RCC_MSI_IsEnabledRangeSelect()  == 1U) ? LL_RCC_MSI_GetRange() : LL_RCC_MSI_GetRangeAfterStandby()));
		  break;

		case LL_RCC_PLLSOURCE_HSI:  /* HSI used as PLL clock source. */
		  pllinputfreq = HSI_VALUE;
		  break;

		case LL_RCC_PLLSOURCE_HSE:  /* HSE used as PLL clock source. */
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

		return pllinputfreq;
	}
