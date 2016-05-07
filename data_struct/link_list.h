#ifndef _LINK_LIST_H_ASDFGHJKLVNBGJHGKJHJK
#define _LINK_LIST_H_ASDFGHJKLVNBGJHGKJHJK

#define DOUBLE_LINK_LIST 0


typedef struct link_list_node{
    void *data;
    struct link_list_node *next;
#if DOUBLE_LINK_LIST
    struct link_list_node *prev;
#endif
}link_list_node_t;

/* Return */
typedef int (*cmp_callback_t)(link_list_node_t *node, void *cmp_data);
typedef int (*print_callback_t)(link_list_node_t *node);

typedef struct link_list_head{
    int size;
    int count;
    cmp_callback_t cb;
    link_list_node_t *current;
    link_list_node_t *node;
}link_list_head_t;


int link_list_init(link_list_head_t *head, int size, cmp_callback_t cb);
int link_list_append(link_list_head_t *head, void *data_from_user);
#if DOUBLE_LINK_LIST
link_list_node_t *link_list_find(link_list_head_t *head, void *cmp_data);
#else
link_list_node_t *link_list_find(link_list_head_t *head, void *cmp_data, link_list_node_t **prev);
#endif
int link_list_delete(link_list_head_t *head, void *cmp_data);
int link_list_show_one(link_list_head_t *head, void *cmp_data, print_callback_t cb);
int link_list_show_all(link_list_head_t *head, print_callback_t cb);

#endif
