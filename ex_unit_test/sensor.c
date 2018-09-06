#include <stdint.h>
#include "platform.h"

/* It's waiter */
void sensor_wr(uint8_t val)
{
	IO_REG_WR8(SENSOR_INPUT_REG, val);
}

uint8_t sensor_rd(void)
{
	return IO_REG_RD8(SENSOR_OUTPUT_REG);
}


/* It's waiter */
int init_sensor(void)
{
	uint8_t sensor_id = IO_REG_RD8(SENSOR_VERSION_REG);
	if (sensor_id == SENSOR_VERSION_NUM) {
		IO_REG_WR8(SENSOR_INIT_REG, 0x1);	//Enable Sensor
		return SUCCESS;
	}
	return FAILURE;
}
