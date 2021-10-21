#ifdef TEST

#include "unity.h"

#include "transmission.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_gear_if_high_then_up(void)
{
	int status = OK;
	shift_t Change = getShift(3000,0.15,&status);
	TEST_ASSERT_EQUAL(UP,Change);
	TEST_ASSERT_EQUAL(OK,status);
}

void test_gear_if_low_then_down(void)
{
	int status = OK;
	shift_t Change = getShift(1000,0.5,&status);
	TEST_ASSERT_EQUAL(DOWN,Change);
	TEST_ASSERT_EQUAL(OK,status);
}

void test_gear_if_stable_no_shift(void)
{
	int status = OK;
	shift_t Change = getShift(2000,0,&status);
	TEST_ASSERT_EQUAL(NONE,Change);
	TEST_ASSERT_EQUAL(OK,status);
}

void test_gear_if_high_slope(void)
{
	int status = OK;
	shift_t Change = getShift(3000,0.5,&status);
	TEST_ASSERT_EQUAL(NONE,Change);
	TEST_ASSERT_EQUAL(OK,status);
}

void test_gear_if_high_slope_low_RPM(void)
{
	int status = OK;
	shift_t Change = getShift(1000,0.5,&status);
	TEST_ASSERT_EQUAL(DOWN,Change);
	TEST_ASSERT_EQUAL(OK,status);
}

void test_gear_if_high_slope_too_high_RPM(void)
{
	int status = OK;
	shift_t Change = getShift(5000,0.5,&status);
	TEST_ASSERT_EQUAL(UP,Change);
	TEST_ASSERT_EQUAL(OK,status);
}

void test_gear_if_high_slope_stall_risk(void)
{
	int status = OK;
	shift_t Change = getShift(550,0.5,&status);
	TEST_ASSERT_EQUAL(DOWN,Change);
	TEST_ASSERT_EQUAL(OK,status);
}

void test_gear_if_low_slope_stall_risk(void)
{
	int status = OK;
	shift_t Change = getShift(550,0.0,&status);
	TEST_ASSERT_EQUAL(DOWN,Change);
	TEST_ASSERT_EQUAL(OK,status);
}

void test_slope_sensor_failure_mode_neg_slope(void)
{
	int status = OK;
	shift_t Change = getShift(550,-1.4,&status);
	TEST_ASSERT_EQUAL(ERROR,Change);
	TEST_ASSERT_EQUAL(WARNING,status);
}

void test_slope_sensor_failure_mode_too_large_slope(void)
{
	int status = OK;
	shift_t Change = getShift(550,1.4,&status);
	TEST_ASSERT_EQUAL(ERROR,Change);
	TEST_ASSERT_EQUAL(WARNING,status);
}

void test_slope_sensor_failure_mode_bad_RPM(void)
{
	int status = OK;
	shift_t Change = getShift(-1000,0.25,&status);
	TEST_ASSERT_EQUAL(ERROR,Change);
	TEST_ASSERT_EQUAL(FAILURE,status);
}

#endif // TEST
