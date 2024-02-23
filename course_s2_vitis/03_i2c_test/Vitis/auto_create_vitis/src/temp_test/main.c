/******************************************************************************
 *
 * Copyright (C) 2009 - 2014 Xilinx, Inc.  All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * Use of the Software is limited solely to applications:
 * (a) running on a Xilinx device, or
 * (b) that interact with a Xilinx device through a bus or interconnect.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
 * OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Except as contained in this notice, the name of the Xilinx shall not be used
 * in advertising or otherwise to promote the sale, use or other dealings in
 * this Software without prior written authorization from Xilinx.
 *
 ******************************************************************************/

/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

#include <stdio.h>
#include "xparameters.h"
#include "xil_io.h"
#include "temp.h"
#include "sleep.h"
#include "i2c/PS_i2c.h"


XIicPs rtc_i2c ;

static char Readbuf[2] ;



int main()
{
	//temperature point
	float point ;
	//temperature
	float temp ;

	//Initial i2c
	i2c_init(&rtc_i2c, XPAR_PS7_I2C_0_DEVICE_ID ,100000) ;//100KHz


	while(1){
		//read temperature
		temp_read(&rtc_i2c, Readbuf, 0x48) ;
		//if bit 7 equals to 1, point is 0.5C, or 0
		if (Readbuf[1] & 0x80)
			point = 0.5 ;
		else
			point = 0 ;

		//if bit7 equals to 1, then it is negative value
		if (Readbuf[0] & 0x80){
			temp = (float)(Readbuf[0]-256) + point ;
		}
		else{
			temp = (float)(Readbuf[0]) + point ;
		}

		printf("current temp is:%.1f\t\n",temp);

		sleep(1) ;
	}
	return 0;
}
