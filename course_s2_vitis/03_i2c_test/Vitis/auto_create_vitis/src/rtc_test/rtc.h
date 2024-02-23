#include "xiicps.h"
#include "xparameters.h"
#include "i2c/PS_i2c.h"

int rtc_read(XIicPs *IicInstance,u16 addr,u8 *read_buf) ;
int rtc_write(XIicPs *IicInstance,u16 addr,u8 data) ;
