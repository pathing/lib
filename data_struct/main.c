#include <stdio.h>

#define TEST_LINK_LIST 1

int main()
{
#if TEST_LINK_LIST
    extern void test_link_list(void);
    test_link_list();
#endif

    return 0;
}
