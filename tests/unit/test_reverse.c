#include "../minunit.h"
#include "../../reverse_lib.h"

MU_TEST(test_reverse_str_dog)
{
    char dst[10];
    reverse_str(dst, "DOG");
    mu_assert_string_eq("GOD", dst);
}

MU_TEST(test_reverse_str_single)
{
    char dst[10];
    reverse_str(dst, "A");
    mu_assert_string_eq("A", dst);
}

MU_TEST(test_reverse_str_empty)
{
    char dst[10];
    reverse_str(dst, "");
    mu_assert_string_eq("", dst);
}

MU_TEST(test_reverse_str_palindrome)
{
    char dst[10];
    reverse_str(dst, "level");
    mu_assert_string_eq("level", dst);
}

MU_TEST_SUITE(reverse_suite)
{
    MU_RUN_TEST(test_reverse_str_dog);
    MU_RUN_TEST(test_reverse_str_single);
    MU_RUN_TEST(test_reverse_str_empty);
    MU_RUN_TEST(test_reverse_str_palindrome);
}

int main(void)
{
    MU_RUN_SUITE(reverse_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
