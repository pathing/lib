#include <stdio.h>

#include "common.h"

void test_common(void)
{
    int i;
    char **obj1 = NULL;
    char **obj2 = NULL;
    int nums1 = 0;
    int nums2 = 0;
    char test_buf[64] = "We are the world! Hello,explode,hihi";

    printf("--------------------------------------------------------------------\n");
    printf("Test string: %s\n", test_buf);

    printf("Splite by ' '\n");
    split(test_buf, ' ', &obj1, &nums1);
    printf("Splite result:\n");
    for(i = 0; i < nums1; i++){
        printf("%d. %s\n", i+1, obj1[i]);
    }

    printf("--------------------------------------------------------------------\n");
    printf("Test string: %s\n", obj1[4]);
    printf("Splite by ','\n");
    split(obj1[4], ',', &obj2, &nums2);
    printf("Splite result:\n");
    for(i = 0; i < nums2; i++){
        printf("%d. %s\n", i+1, obj2[i]);
    }
    printf("--------------------------------------------------------------------\n");

    split_free(&obj2);
    split_free(&obj1);

}
