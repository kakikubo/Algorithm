#include "../minunit.h"
#include "../../recursive_lib.h"

MU_TEST(test_kaijo_zero)
{
    mu_assert_int_eq(1, kaijo(0));
}

MU_TEST(test_kaijo_one)
{
    mu_assert_int_eq(1, kaijo(1));
}

MU_TEST(test_kaijo_five)
{
    mu_assert_int_eq(120, kaijo(5));
}

MU_TEST(test_kaijo_seven)
{
    mu_assert_int_eq(5040, kaijo(7));
}

MU_TEST_SUITE(recursive_suite)
{
    MU_RUN_TEST(test_kaijo_zero);
    MU_RUN_TEST(test_kaijo_one);
    MU_RUN_TEST(test_kaijo_five);
    MU_RUN_TEST(test_kaijo_seven);
}

int main(void)
{
    MU_RUN_SUITE(recursive_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
