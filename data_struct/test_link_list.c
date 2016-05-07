#include <stdio.h>
#include <string.h>

#include "link_list.h"

typedef struct user_data{
    char name[64];
    int age;
}user_data_t;

link_list_head_t head;

int cmp_cb(link_list_node_t *node, void *cmp_data)
{
    if(strcmp(((user_data_t *)(node->data))->name, (char *)cmp_data) == 0){
        return 1;
    }
    return 0;
}

int print_cb(link_list_node_t *node)
{
    user_data_t *data = (user_data_t *)(node->data);
    printf("%s:%d\n", data->name, data->age);

    return 0;
}

void test_link_list(void)
{
    int i;
    user_data_t data;
    user_data_t data1;

    link_list_init(&head, sizeof(user_data_t), cmp_cb);

    printf("--------------------------------------------------------------------\n");
    printf("None one, show nothing\n");
    link_list_show_all(&head, print_cb);

    strcpy(data.name, "wubo");
    data.age = 25;
    link_list_append(&head, &data);

    printf("--------------------------------------------------------------------\n");
    printf("Append one, show one. expect [%s:%d] result ", data.name, data.age);
    link_list_show_one(&head, data.name, print_cb);
    printf("--------------------------------------------------------------------\n");
    printf("Show all. expect [%s:%d], result ", data.name, data.age);
    link_list_show_all(&head, print_cb);

    strcpy(data1.name, "Pathing");
    data1.age = 18;
    link_list_append(&head, &data1);

    printf("--------------------------------------------------------------------\n");
    printf("Append one, show one. expect [%s:%d], result ", data1.name, data1.age);
    link_list_show_one(&head, data1.name, print_cb);
    printf("--------------------------------------------------------------------\n");
    printf("Show all. expect [%s:%d][%s:%d], result ", data.name, data.age, data1.name, data1.age);
    link_list_show_all(&head, print_cb);

    link_list_delete(&head, data.name);

    printf("--------------------------------------------------------------------\n");
    printf("Delete one, show one. expect [%s:%d], result ", data1.name, data1.age);
    link_list_show_one(&head, data1.name, print_cb);
    printf("--------------------------------------------------------------------\n");
    printf("Show all. expect [%s:%d], result ", data1.name, data1.age);
    link_list_show_all(&head, print_cb);
    printf("--------------------------------------------------------------------\n");

    for(i = 0; i < 10; i++){
        link_list_append(&head, &data1);
    }
    link_list_show_all(&head, print_cb);
    printf("--------------------------------------------------------------------\n");
    
    for(i = 0; i < 10; i++){
        link_list_delete(&head, data1.name);
        link_list_show_all(&head, print_cb);
    printf("--------------------------------------------------------------------\n");
    }
}

