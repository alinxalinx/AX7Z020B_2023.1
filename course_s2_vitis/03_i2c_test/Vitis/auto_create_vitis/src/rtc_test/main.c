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
#include "rtc.h"

#define RTC_SECOND  0x00
#define RTC_MINUTE  0x01
#define RTC_HOUR    0x02
#define RTC_DAY     0x03
#define RTC_DATE    0x04
#define RTC_MONTH   0x05
#define RTC_YEAR    0x06
#define RTC_CTRL    0x07

XIicPs rtc_i2c ;

static u8 Readbuf[7] ;
static u8 Writebuf[7] = {0x18, 0x18, 0x18, 0x02, 0x18, 0x08, 0x23} ; //2023-08-18  18:18:18

unsigned char time[7]; //format: second/minute/hour/date/month/year


int main()
{

	int i;

	unsigned char second_old=0;

	//Initial i2c
	i2c_init(&rtc_i2c, XPAR_PS7_I2C_0_DEVICE_ID ,100000) ;//100KHz

	//Set RTC to 32.768KHz Squart-Wave
	rtc_read(&rtc_i2c, RTC_CTRL, Readbuf) ;
	Readbuf[0] = Readbuf[0] & 0x10 ;
	rtc_write(&rtc_i2c, RTC_CTRL, Readbuf[0] | 0x13) ; //OUT = X RS1 = 1 RS0 = 0 SQWE = 1  32.768KHz

	//Check if RTC stopped
	rtc_read(&rtc_i2c, RTC_SECOND, Readbuf) ;

	while(Readbuf[0] & 0x80){
		rtc_write(&rtc_i2c, RTC_SECOND, Readbuf[0] & 0x7f) ;
		rtc_read(&rtc_i2c, RTC_SECOND, Readbuf) ;
	}


	//Wrtie preset time to RTC register
	for(i = 0 ; i < 7 ; i++){
		rtc_write(&rtc_i2c, i, Writebuf[i]) ;
	}


	while(1){

		//Read time from RTC
		for(i = 0 ; i < 7 ; i++){
			rtc_read(&rtc_i2c, i, Readbuf + i) ;
		}

		second_old = time[0];

		for (i=0;i<7;i++){

			time[i] = Readbuf[i]/16*10+Readbuf[i]%16;//format: second minute hour date month year
		}

		if (second_old!=time[0]){

			printf("current time is:20%d-%d-%d %d:%d:%d\n",time[6],time[5],time[4],time[2],time[1],time[0]);  //convert string

		}
	}

	return 0;
}
