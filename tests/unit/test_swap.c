#include "../minunit.h"
#include "../../swap_lib.h"

MU_TEST(test_swap_int_basic)
{
    int a = 2, b = 7;
    swap_int(&a, &b);
    mu_assert_int_eq(7, a);
    mu_assert_int_eq(2, b);
}

MU_TEST(test_swap_int_same_value)
{
    int a = 5, b = 5;
    swap_int(&a, &b);
    mu_assert_int_eq(5, a);
    mu_assert_int_eq(5, b);
}

MU_TEST(test_sum_range_1_to_5)
{
    mu_assert_int_eq(15, sum_range(1, 5));
}

MU_TEST(test_sum_range_5_to_10)
{
    mu_assert_int_eq(45, sum_range(5, 10));
}

MU_TEST(test_sum_range_1_to_10)
{
    mu_assert_int_eq(55, sum_range(1, 10));
}

MU_TEST(test_sum_range_same_value)
{
    mu_assert_int_eq(2, sum_range(2, 2));
}

MU_TEST(test_sum_range_swaps_when_min_greater_than_max)
{
    mu_assert_int_eq(45, sum_range(10, 5));
}

MU_TEST_SUITE(swap_suite)
{
    MU_RUN_TEST(test_swap_int_basic);
    MU_RUN_TEST(test_swap_int_same_value);
    MU_RUN_TEST(test_sum_range_1_to_5);
    MU_RUN_TEST(test_sum_range_5_to_10);
    MU_RUN_TEST(test_sum_range_1_to_10);
    MU_RUN_TEST(test_sum_range_same_value);
    MU_RUN_TEST(test_sum_range_swaps_when_min_greater_than_max);
}

int main(void)
{
    MU_RUN_SUITE(swap_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
