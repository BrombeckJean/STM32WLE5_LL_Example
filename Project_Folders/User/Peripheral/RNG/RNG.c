/********************************************************************************
 * @file           : RNG.c
 * @brief          : Configuration and initialization of RNG.
 ********************************************************************************/

//------------------ INCLUDE -------------------------------------------------------------------------------- INCLUDE --------------------------------------------------------*/
	#include "RNG.h"

//------------------ RNG INIT ------------------------------------------------------------------------------- RNG INIT -------------------------------------------------------*/
	void RNG_Init (void)
	{
	#ifdef rng
		  LL_RCC_SetRNGClockSource(LL_RCC_RNG_CLKSOURCE_PLL);
		  LL_AHB3_GRP1_EnableClock(LL_AHB3_GRP1_PERIPH_RNG);
		  LL_RNG_Enable(RNG);
	#else
		  Activation_Error();
	#endif
	}

//------------------ GET RNG NUMBER ------------------------------------------------------------------------------- GET RNG NUMBER -------------------------------------------------------*/
	uint32_t Get_RNG_Number (void)
	{
	#ifdef rng
		/* Initialize random numbers generation */
		LL_RNG_Enable(RNG);

		/* Wait for DRDY flag to be raised */
		while (!LL_RNG_IsActiveFlag_DRDY(RNG));

		/* Check if error occurs */
		if (LL_RNG_IsActiveFlag_CECS(RNG) || LL_RNG_IsActiveFlag_SECS(RNG));

		uint32_t data = LL_RNG_ReadRandData32(RNG);

		/* Stop random numbers generation */
		LL_RNG_Disable(RNG);
		return data;
	#else
		return 0;
	#endif
	}
