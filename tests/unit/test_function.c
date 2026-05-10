#include "../minunit.h"
#include "../../function_lib.h"

MU_TEST(test_calc_1_to_5)
{
    mu_assert_int_eq(15, calc(1, 5));
}

MU_TEST(test_calc_1_to_10)
{
    mu_assert_int_eq(55, calc(1, 10));
}

MU_TEST(test_calc_same_value)
{
    mu_assert_int_eq(7, calc(7, 7));
}

MU_TEST(test_calc_min_greater_than_max)
{
    mu_assert_int_eq(0, calc(5, 1));
}

MU_TEST_SUITE(function_suite)
{
    MU_RUN_TEST(test_calc_1_to_5);
    MU_RUN_TEST(test_calc_1_to_10);
    MU_RUN_TEST(test_calc_same_value);
    MU_RUN_TEST(test_calc_min_greater_than_max);
}

int main(void)
{
    MU_RUN_SUITE(function_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
