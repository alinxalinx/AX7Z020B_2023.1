#include "temp.h"



void temp_read(XIicPs *InstancePtr, u8 *rd_data, char IIC_ADDR)
{
	XIicPs_MasterRecvPolled(InstancePtr, rd_data, 2, IIC_ADDR);
	while (XIicPs_BusIsBusy(InstancePtr));
}
