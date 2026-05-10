#include "../minunit.h"
#include "../../arraysearch_lib.h"

MU_TEST(test_count_occurrences_two)
{
    int a[] = {9, 8, 7, 6, 7};
    mu_assert_int_eq(2, count_occurrences(a, 5, 7));
}

MU_TEST(test_count_occurrences_zero)
{
    int a[] = {9, 8, 4, 6, 4};
    mu_assert_int_eq(0, count_occurrences(a, 5, 7));
}

MU_TEST(test_count_occurrences_all_match)
{
    int a[] = {7, 7, 7};
    mu_assert_int_eq(3, count_occurrences(a, 3, 7));
}

MU_TEST(test_count_occurrences_empty)
{
    int a[] = {0};
    mu_assert_int_eq(0, count_occurrences(a, 0, 7));
}

MU_TEST(test_contains_found)
{
    int a[] = {9, 7, 4, 6, 4};
    mu_assert_int_eq(1, contains(a, 5, 7));
}

MU_TEST(test_contains_not_found)
{
    int a[] = {9, 8, 4, 6, 4};
    mu_assert_int_eq(0, contains(a, 5, 7));
}

MU_TEST(test_contains_first_element)
{
    int a[] = {7, 1, 2};
    mu_assert_int_eq(1, contains(a, 3, 7));
}

MU_TEST(test_contains_empty)
{
    int a[] = {0};
    mu_assert_int_eq(0, contains(a, 0, 7));
}

MU_TEST_SUITE(arraysearch_suite)
{
    MU_RUN_TEST(test_count_occurrences_two);
    MU_RUN_TEST(test_count_occurrences_zero);
    MU_RUN_TEST(test_count_occurrences_all_match);
    MU_RUN_TEST(test_count_occurrences_empty);
    MU_RUN_TEST(test_contains_found);
    MU_RUN_TEST(test_contains_not_found);
    MU_RUN_TEST(test_contains_first_element);
    MU_RUN_TEST(test_contains_empty);
}

int main(void)
{
    MU_RUN_SUITE(arraysearch_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
