#include <stdio.h>

#define TEST_LINK_LIST 1
#define TEST_COMMON 1

int main()
{
#if TEST_LINK_LIST
    extern void test_link_list(void);
    test_link_list();
#endif

#if TEST_COMMON
    extern void test_common(void);
    test_common();
#endif

    return 0;
}
