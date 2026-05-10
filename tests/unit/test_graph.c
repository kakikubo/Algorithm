#include "../minunit.h"
#include "../../graph_lib.h"

MU_TEST(test_format_bar_four_stars)
{
    char buf[64];
    format_bar(buf, 0, 4);
    mu_assert_string_eq("a[0]=4|****", buf);
}

MU_TEST(test_format_bar_five_stars)
{
    char buf[64];
    format_bar(buf, 1, 5);
    mu_assert_string_eq("a[1]=5|*****", buf);
}

MU_TEST(test_format_bar_two_stars)
{
    char buf[64];
    format_bar(buf, 2, 2);
    mu_assert_string_eq("a[2]=2|**", buf);
}

MU_TEST(test_format_bar_zero)
{
    char buf[64];
    format_bar(buf, 9, 0);
    mu_assert_string_eq("a[9]=0|", buf);
}

MU_TEST_SUITE(graph_suite)
{
    MU_RUN_TEST(test_format_bar_four_stars);
    MU_RUN_TEST(test_format_bar_five_stars);
    MU_RUN_TEST(test_format_bar_two_stars);
    MU_RUN_TEST(test_format_bar_zero);
}

int main(void)
{
    MU_RUN_SUITE(graph_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
