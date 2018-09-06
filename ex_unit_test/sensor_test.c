#include <stdint.h>
#include "minunit.h"
#include "fff.h"
#include "sensor.h"
#include "platform.h"

DEFINE_FFF_GLOBALS;
FAKE_VOID_FUNC(IO_REG_WR8, uint32_t, uint8_t);
FAKE_VALUE_FUNC(uint8_t, IO_REG_RD8, uint32_t);


void setup(void) {
	RESET_FAKE(IO_REG_WR8);
	RESET_FAKE(IO_REG_RD8);
	FFF_RESET_HISTORY();
}

void teardown(void) {
	/* Nothing */
}

MU_TEST(test_sensor_write_value_to_register) {
	sensor_wr(0x5a);
	mu_check(1 == IO_REG_WR8_fake.call_count);
	mu_check(SENSOR_INPUT_REG == IO_REG_WR8_fake.arg0_val);
	mu_check(0x5a == IO_REG_WR8_fake.arg1_val);
}

MU_TEST(test_sensor_read_value_to_register) {
	IO_REG_RD8_fake.return_val = 0xaa;
	uint8_t ret = sensor_rd();
	mu_check(1 == IO_REG_RD8_fake.call_count);
	mu_check(SENSOR_OUTPUT_REG == IO_REG_RD8_fake.arg0_val);
	mu_check(IO_REG_RD8_fake.return_val == ret);
}

MU_TEST(test_sensor_init_failure) {
	IO_REG_RD8_fake.return_val = 0xff;
	int ret = init_sensor();
	mu_check(1 == IO_REG_RD8_fake.call_count);
	mu_assert(SUCCESS == ret, "Init failed");
}


MU_TEST_SUITE(sensor_test_suite) {
	MU_SUITE_CONFIGURE(&setup, &teardown);

	MU_RUN_TEST(test_sensor_write_value_to_register);
	MU_RUN_TEST(test_sensor_read_value_to_register);
	MU_RUN_TEST(test_sensor_init_failure);
}

int main(int argc, char *argv[]) {
	#ifdef UNIT_TEST
	printf("Do Unit test\n");
	#endif

	MU_RUN_SUITE(sensor_test_suite);
	MU_REPORT();
	return 0;
}

