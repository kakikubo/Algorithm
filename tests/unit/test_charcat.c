#include <string.h>
#include "../minunit.h"
#include "../../charcat_lib.h"

MU_TEST(test_str_concat_book_marks)
{
    char dst[12] = "book";
    str_concat(dst, "marks");
    mu_assert_string_eq("bookmarks", dst);
}

MU_TEST(test_str_concat_into_empty)
{
    char dst[16] = "";
    str_concat(dst, "hello");
    mu_assert_string_eq("hello", dst);
}

MU_TEST(test_str_concat_empty_src)
{
    char dst[16] = "abc";
    str_concat(dst, "");
    mu_assert_string_eq("abc", dst);
}

MU_TEST(test_str_concat_terminator_after_concat)
{
    char dst[16] = "ab";
    str_concat(dst, "cd");
    mu_assert_int_eq('\0', dst[4]);
}

MU_TEST_SUITE(charcat_suite)
{
    MU_RUN_TEST(test_str_concat_book_marks);
    MU_RUN_TEST(test_str_concat_into_empty);
    MU_RUN_TEST(test_str_concat_empty_src);
    MU_RUN_TEST(test_str_concat_terminator_after_concat);
}

int main(void)
{
    MU_RUN_SUITE(charcat_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
