#include <stdbool.h>
#include "minunit.h"
#include "calculation.h"



void test_setup(void) {

}

void test_teardown(void) {
	/* Nothing */
}

MU_TEST(test_check_nagetive_value) {
	bool ret = isPrime(-1);
	mu_check(ret == false);
}
#if 0
MU_TEST(test_check_fail) {
	mu_check(foo != 7);
}

MU_TEST(test_assert) {
	mu_assert(foo == 7, "foo should be 7");
}

MU_TEST(test_assert_fail) {
	mu_assert(foo != 7, "foo should be <> 7");
}

MU_TEST(test_assert_int_eq) {
	mu_assert_int_eq(4, bar);
}

MU_TEST(test_assert_int_eq_fail) {
	mu_assert_int_eq(5, bar);
}

MU_TEST(test_assert_double_eq) {
	mu_assert_double_eq(0.1, dbar);
}

MU_TEST(test_assert_double_eq_fail) {
	mu_assert_double_eq(0.2, dbar);
}

MU_TEST(test_fail) {
	mu_fail("Fail now!");
}

MU_TEST(test_string_eq){
	mu_assert_string_eq("Thisstring", foostring);
}

MU_TEST(test_string_eq_fail){
	mu_assert_string_eq("Thatstring", foostring);
}
#endif

MU_TEST_SUITE(calculation_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(test_check_nagetive_value);
#if 0
	MU_RUN_TEST(test_check);
	MU_RUN_TEST(test_assert);
	MU_RUN_TEST(test_assert_int_eq);
	MU_RUN_TEST(test_assert_double_eq);

	MU_RUN_TEST(test_check_fail);
	MU_RUN_TEST(test_assert_fail);
	MU_RUN_TEST(test_assert_int_eq_fail);
	MU_RUN_TEST(test_assert_double_eq_fail);
	
	MU_RUN_TEST(test_string_eq);
	MU_RUN_TEST(test_string_eq_fail);

	MU_RUN_TEST(test_fail);
#endif
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(calculation_suite);
	MU_REPORT();
	return 0;
}

