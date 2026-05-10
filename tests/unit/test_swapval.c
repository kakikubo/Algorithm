#include "../minunit.h"
#include "../../swapval_lib.h"

MU_TEST(test_swapbyval_does_not_change_caller)
{
    int a = 2, b = 7;
    swapbyval(a, b);
    mu_assert_int_eq(2, a);
    mu_assert_int_eq(7, b);
}

MU_TEST(test_swapbyref_swaps_values)
{
    int a = 2, b = 7;
    swapbyref(&a, &b);
    mu_assert_int_eq(7, a);
    mu_assert_int_eq(2, b);
}

MU_TEST(test_swapbyref_same_value)
{
    int a = 5, b = 5;
    swapbyref(&a, &b);
    mu_assert_int_eq(5, a);
    mu_assert_int_eq(5, b);
}

MU_TEST(test_swapbyref_negative)
{
    int a = -3, b = 9;
    swapbyref(&a, &b);
    mu_assert_int_eq(9, a);
    mu_assert_int_eq(-3, b);
}

MU_TEST_SUITE(swapval_suite)
{
    MU_RUN_TEST(test_swapbyval_does_not_change_caller);
    MU_RUN_TEST(test_swapbyref_swaps_values);
    MU_RUN_TEST(test_swapbyref_same_value);
    MU_RUN_TEST(test_swapbyref_negative);
}

int main(void)
{
    MU_RUN_SUITE(swapval_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
