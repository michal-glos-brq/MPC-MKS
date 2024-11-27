/*
 * Copyright (c) 2013 - 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017, 2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"

#include "fsl_power.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
uint32_t DWT1, DWT2;
char password_stored[21] = "123456789";
char input[21];
uint32_t status;
uint32_t pswd_len;

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * @brief Main function
 */
int main(void)
{
    char ch;

    /* Init board hardware. */
    /* set BOD VBAT level to 1.65V */
    POWER_SetBodVbatLevel(kPOWER_BodVbatLevel1650mv, kPOWER_BodHystLevel50mv, false);
    /* attach main clock divide to FLEXCOMM0 (debug console) */
    CLOCK_AttachClk(BOARD_DEBUG_UART_CLK_ATTACH);

    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();
#if !defined(DONT_ENABLE_FLASH_PREFETCH)
    /* enable flash prefetch for better performance */
    SYSCON->FMCCR |= SYSCON_FMCCR_PREFEN_MASK;
#endif
    //DWT1 = DWT->CYCCNT;
    //status = function();
    //DWT2 = DWT->CYCCNT;
    //PRINTF("hello world.\r\n");

    while (1)
    {

    	PRINTF("\r\nEnter password");
    	SCANF("%s", input);

    	DWT1 = DWT->CYCCNT;
    	// We add 1 to ensure matching preffix would not pass on its own
    	pswd_len = strlen(password_stored) +1;
    	uint32_t decision_maker = 0;
    	int i = 0;
    	// Ensure the array is declared with the multiplicates of 4 ... otherwise not really safe
    	while (1) {
    		if (i > pswd_len-3) {break;}
    		decision_maker |= *((uint32_t *)(password_stored + i)) ^ *((uint32_t *)(input + i));
    		i+=4;
    	}
    	i = pswd_len - 3;
    	decision_maker |= *((uint32_t *)(password_stored + i)) ^ *((uint32_t *)(input + i));

    	status = decision_maker != (uint32_t)0;
    	DWT2 = DWT->CYCCNT;

    	PRINTF("\r\ninput: %s", input);

    	if (status == 0) {
    		PRINTF("\r\nInput correct");
    	}
    	else {
    		PRINTF("\r\nInput invalid");
    	}

    	PRINTF("Cycles %d.\r\n", DWT2-DWT1);

        //DWT1 = DWT->CYCCNT;

        //ch = GETCHAR();
        //uint32_t ch = 220;
        //PUTCHAR(ch);
        //DWT2 = DWT->CYCCNT;
        //PRINTF("hello world %d.\r\n", DWT2-DWT1);
    }
}
