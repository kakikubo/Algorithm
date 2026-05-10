#include "../minunit.h"
#include "../../average_lib.h"

MU_TEST(test_average_int_basic)
{
    int a[] = {70, 80, 60, 90};
    mu_assert_int_eq(75, average_int(a, 4));
}

MU_TEST(test_average_int_single)
{
    int a[] = {42};
    mu_assert_int_eq(42, average_int(a, 1));
}

MU_TEST(test_average_int_truncates)
{
    int a[] = {1, 2, 2};
    mu_assert_int_eq(1, average_int(a, 3));
}

MU_TEST(test_average_int_zeros)
{
    int a[] = {0, 0, 0};
    mu_assert_int_eq(0, average_int(a, 3));
}

MU_TEST_SUITE(average_suite)
{
    MU_RUN_TEST(test_average_int_basic);
    MU_RUN_TEST(test_average_int_single);
    MU_RUN_TEST(test_average_int_truncates);
    MU_RUN_TEST(test_average_int_zeros);
}

int main(void)
{
    MU_RUN_SUITE(average_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
