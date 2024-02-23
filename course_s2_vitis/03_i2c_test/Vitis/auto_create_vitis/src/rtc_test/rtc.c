#include "rtc.h"
#include "xiicps.h"
#include "xparameters.h"
#include "i2c/PS_i2c.h"


int rtc_read(XIicPs *IicInstance,u16 addr,u8 *read_buf)
{
	*read_buf=i2c_reg8_read(IicInstance,0x68,addr);
	return XST_SUCCESS;
}

int rtc_write(XIicPs *IicInstance,u16 addr,u8 data)
{

	return i2c_reg8_write(IicInstance,0x68,addr,data);
}


