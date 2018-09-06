#ifndef _SENSOR_H_
#define _SENSOR_H_

void sensor_wr(uint8_t val);
uint8_t sensor_rd(void);
int init_sensor(void);

#endif