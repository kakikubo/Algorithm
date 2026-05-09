#include "../minunit.h"
#include "../../calendar_lib.h"

MU_TEST(test_getMonthDays_31days)
{
    mu_assert_int_eq(31, getMonthDays(2024, 1));
    mu_assert_int_eq(31, getMonthDays(2024, 3));
    mu_assert_int_eq(31, getMonthDays(2024, 12));
}

MU_TEST(test_getMonthDays_30days)
{
    mu_assert_int_eq(30, getMonthDays(2024, 4));
    mu_assert_int_eq(30, getMonthDays(2024, 6));
    mu_assert_int_eq(30, getMonthDays(2024, 9));
    mu_assert_int_eq(30, getMonthDays(2024, 11));
}

MU_TEST(test_getMonthDays_february_common_year)
{
    mu_assert_int_eq(28, getMonthDays(2023, 2));
}

MU_TEST(test_getMonthDays_february_leap_div4)
{
    mu_assert_int_eq(29, getMonthDays(2024, 2));
}

MU_TEST(test_getMonthDays_february_div100_not_div400)
{
    mu_assert_int_eq(28, getMonthDays(1900, 2));
}

MU_TEST(test_getMonthDays_february_div400)
{
    mu_assert_int_eq(29, getMonthDays(2000, 2));
}

MU_TEST(test_getMonthDays_invalid_month)
{
    mu_assert_int_eq(0, getMonthDays(2024, 0));
    mu_assert_int_eq(0, getMonthDays(2024, 13));
}

MU_TEST(test_getWeekDay_2024_01_01_monday)
{
    mu_assert_int_eq(1, getWeekDay(2024, 1, 1));
}

MU_TEST(test_getWeekDay_2024_02_01_thursday)
{
    mu_assert_int_eq(4, getWeekDay(2024, 2, 1));
}

MU_TEST(test_getWeekDay_2025_05_01_thursday)
{
    mu_assert_int_eq(4, getWeekDay(2025, 5, 1));
}

MU_TEST_SUITE(calendar_suite)
{
    MU_RUN_TEST(test_getMonthDays_31days);
    MU_RUN_TEST(test_getMonthDays_30days);
    MU_RUN_TEST(test_getMonthDays_february_common_year);
    MU_RUN_TEST(test_getMonthDays_february_leap_div4);
    MU_RUN_TEST(test_getMonthDays_february_div100_not_div400);
    MU_RUN_TEST(test_getMonthDays_february_div400);
    MU_RUN_TEST(test_getMonthDays_invalid_month);
    MU_RUN_TEST(test_getWeekDay_2024_01_01_monday);
    MU_RUN_TEST(test_getWeekDay_2024_02_01_thursday);
    MU_RUN_TEST(test_getWeekDay_2025_05_01_thursday);
}

int main(void)
{
    MU_RUN_SUITE(calendar_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
