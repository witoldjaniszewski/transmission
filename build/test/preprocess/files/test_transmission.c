#include "src/transmission.h"
#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"








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

 UnityAssertEqualNumber((UNITY_INT)((UP)), (UNITY_INT)((Change)), (

((void *)0)

), (UNITY_UINT)(19), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((OK)), (UNITY_INT)((status)), (

((void *)0)

), (UNITY_UINT)(20), UNITY_DISPLAY_STYLE_INT);

}



void test_gear_if_low_then_down(void)

{

 int status = OK;

 shift_t Change = getShift(1000,0.5,&status);

 UnityAssertEqualNumber((UNITY_INT)((DOWN)), (UNITY_INT)((Change)), (

((void *)0)

), (UNITY_UINT)(27), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((OK)), (UNITY_INT)((status)), (

((void *)0)

), (UNITY_UINT)(28), UNITY_DISPLAY_STYLE_INT);

}



void test_gear_if_stable_no_shift(void)

{

 int status = OK;

 shift_t Change = getShift(2000,0,&status);

 UnityAssertEqualNumber((UNITY_INT)((NONE)), (UNITY_INT)((Change)), (

((void *)0)

), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((OK)), (UNITY_INT)((status)), (

((void *)0)

), (UNITY_UINT)(36), UNITY_DISPLAY_STYLE_INT);

}



void test_gear_if_high_slope(void)

{

 int status = OK;

 shift_t Change = getShift(3000,0.5,&status);

 UnityAssertEqualNumber((UNITY_INT)((NONE)), (UNITY_INT)((Change)), (

((void *)0)

), (UNITY_UINT)(43), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((OK)), (UNITY_INT)((status)), (

((void *)0)

), (UNITY_UINT)(44), UNITY_DISPLAY_STYLE_INT);

}



void test_gear_if_high_slope_low_RPM(void)

{

 int status = OK;

 shift_t Change = getShift(1000,0.5,&status);

 UnityAssertEqualNumber((UNITY_INT)((DOWN)), (UNITY_INT)((Change)), (

((void *)0)

), (UNITY_UINT)(51), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((OK)), (UNITY_INT)((status)), (

((void *)0)

), (UNITY_UINT)(52), UNITY_DISPLAY_STYLE_INT);

}



void test_gear_if_high_slope_too_high_RPM(void)

{

 int status = OK;

 shift_t Change = getShift(5000,0.5,&status);

 UnityAssertEqualNumber((UNITY_INT)((UP)), (UNITY_INT)((Change)), (

((void *)0)

), (UNITY_UINT)(59), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((OK)), (UNITY_INT)((status)), (

((void *)0)

), (UNITY_UINT)(60), UNITY_DISPLAY_STYLE_INT);

}



void test_gear_if_high_slope_stall_risk(void)

{

 int status = OK;

 shift_t Change = getShift(550,0.5,&status);

 UnityAssertEqualNumber((UNITY_INT)((DOWN)), (UNITY_INT)((Change)), (

((void *)0)

), (UNITY_UINT)(67), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((OK)), (UNITY_INT)((status)), (

((void *)0)

), (UNITY_UINT)(68), UNITY_DISPLAY_STYLE_INT);

}



void test_gear_if_low_slope_stall_risk(void)

{

 int status = OK;

 shift_t Change = getShift(550,0.0,&status);

 UnityAssertEqualNumber((UNITY_INT)((DOWN)), (UNITY_INT)((Change)), (

((void *)0)

), (UNITY_UINT)(75), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((OK)), (UNITY_INT)((status)), (

((void *)0)

), (UNITY_UINT)(76), UNITY_DISPLAY_STYLE_INT);

}



void test_slope_sensor_failure_mode_neg_slope(void)

{

 int status = OK;

 shift_t Change = getShift(550,-1.4,&status);

 UnityAssertEqualNumber((UNITY_INT)((ERROR)), (UNITY_INT)((Change)), (

((void *)0)

), (UNITY_UINT)(83), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((WARNING)), (UNITY_INT)((status)), (

((void *)0)

), (UNITY_UINT)(84), UNITY_DISPLAY_STYLE_INT);

}



void test_slope_sensor_failure_mode_too_large_slope(void)

{

 int status = OK;

 shift_t Change = getShift(550,1.4,&status);

 UnityAssertEqualNumber((UNITY_INT)((ERROR)), (UNITY_INT)((Change)), (

((void *)0)

), (UNITY_UINT)(91), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((WARNING)), (UNITY_INT)((status)), (

((void *)0)

), (UNITY_UINT)(92), UNITY_DISPLAY_STYLE_INT);

}



void test_slope_sensor_failure_mode_bad_RPM(void)

{

 int status = OK;

 shift_t Change = getShift(-1000,0.25,&status);

 UnityAssertEqualNumber((UNITY_INT)((ERROR)), (UNITY_INT)((Change)), (

((void *)0)

), (UNITY_UINT)(99), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((FAILURE)), (UNITY_INT)((status)), (

((void *)0)

), (UNITY_UINT)(100), UNITY_DISPLAY_STYLE_INT);

}
