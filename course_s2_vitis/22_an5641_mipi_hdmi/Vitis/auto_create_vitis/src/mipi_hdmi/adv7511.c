#include <stdio.h>
#include <unistd.h>
#include "xil_types.h"
#include "i2c/PS_i2c.h"

u8 adv7511_init_data[][2] =
{
		{0x41, 0x00},  	//set bit 6 to 0 for power-up-power-down
		{0x98, 0x03},	//fixed setting
		{0x9a, 0xe0},	//fixed setting [7:5]-->0b111
		{0x9c, 0x30},	//fixed setting
		{0x9d, 0x61},	//fixed setting, [1:0]-->0b01
		{0xa2, 0xa4},	//fixed setting
		{0xa3, 0xa4},	//fixed setting
		{0xe0, 0xd0},	//fixed setting
		{0xf9, 0x00},	//This should be set to a non-conflicting I2C address (set to 0x00)
		{0x55, 0x12},
		{0x15, 0x00},
		{0x16, 0x00},
		{0xd0, 0x3c},
		{0xaf, 0x04},
		{0x4c, 0x04},
		{0x40, 0x00},
		{0xd6, 0xC0},	//HPD is always high
		{0xff, 0xff}
};

void adv7511_init(XIicPs IicInstance)
{
	for(int i=0;;i++)
	{
		if((adv7511_init_data[i][0] == 0xff) && (adv7511_init_data[i][1] == 0xff))
		{
			break;
		}
		i2c_reg8_write(&IicInstance, 0x72>>1, (unsigned char)adv7511_init_data[i][0], (unsigned char)adv7511_init_data[i][1]);
	}
}



u8 hpd_check(XIicPs IicInstance)
{
	u8 hpd_detect ;

	hpd_detect = i2c_reg8_read(&IicInstance, 0x72>>1, 0x42);
	//xil_printf("HPD register value is 0x%x\r\n", hpd_detect);

	if (hpd_detect & 0x40)
		return 1 ;
	else
		return 0 ;
}
