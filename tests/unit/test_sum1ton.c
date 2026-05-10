#include "../minunit.h"
#include "../../sum1ton_lib.h"

MU_TEST(test_sum_1_to_n_zero)
{
    mu_assert_int_eq(0, sum_1_to_n(0));
}

MU_TEST(test_sum_1_to_n_one)
{
    mu_assert_int_eq(1, sum_1_to_n(1));
}

MU_TEST(test_sum_1_to_n_five)
{
    mu_assert_int_eq(15, sum_1_to_n(5));
}

MU_TEST(test_sum_1_to_n_ten)
{
    mu_assert_int_eq(55, sum_1_to_n(10));
}

MU_TEST(test_sum_1_to_n_negative)
{
    mu_assert_int_eq(0, sum_1_to_n(-3));
}

MU_TEST_SUITE(sum1ton_suite)
{
    MU_RUN_TEST(test_sum_1_to_n_zero);
    MU_RUN_TEST(test_sum_1_to_n_one);
    MU_RUN_TEST(test_sum_1_to_n_five);
    MU_RUN_TEST(test_sum_1_to_n_ten);
    MU_RUN_TEST(test_sum_1_to_n_negative);
}

int main(void)
{
    MU_RUN_SUITE(sum1ton_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
