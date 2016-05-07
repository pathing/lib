#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "link_list.h"

#define LINK_LIST_PRINTF printf

#define LOCK_INIT
#define LOCK
#define UNLOCK

int link_list_init(link_list_head_t *head, int size, cmp_callback_t cb)
{
    link_list_node_t *node = NULL;

    LOCK_INIT;

    LOCK;

    head->size = size;
    head->count = 0;
    head->cb = cb;

    node = (link_list_node_t *)malloc(sizeof(link_list_node_t));
    if(node == NULL){
        LINK_LIST_PRINTF("malloc failed\r\n");
        return -1;
    }
    node->next = NULL;
#if DOUBLE_LINK_LIST
    node->prev = NULL;
#endif
    node->data = NULL;

    head->node = node;
    head->current = node;

    UNLOCK;

    return 0;
}

int link_list_append(link_list_head_t *head, void *data_from_user)
{
    link_list_node_t *node = NULL;
    unsigned char *data = NULL;

    LOCK;

    node = (link_list_node_t *)malloc(sizeof(link_list_node_t));
    if(node == NULL){
        LINK_LIST_PRINTF("Malloc failed\r\n");
        return -1;
    }

    data = (unsigned char *)malloc(head->size);
    if(data == NULL){
        LINK_LIST_PRINTF("Malloc failed\r\n");
        return -1;
    }

    memcpy(data, data_from_user, head->size);

    node->data = (void *)data;
    node->next = NULL;
#if DOUBLE_LINK_LIST
    node->prev = head->current;
#endif

    head->current->next = node;
    head->current = node;
    head->count++;

    UNLOCK;

    return 0;
}

link_list_node_t *link_list_find(link_list_head_t *head, void *cmp_data
#if !DOUBLE_LINK_LIST
    , link_list_node_t **prev
#endif
    )
{
    LOCK;

#if !DOUBLE_LINK_LIST
    link_list_node_t *last = head->node;
#endif
    link_list_node_t *current = head->node->next;

    while(current != NULL){
        if(head->cb(current, cmp_data)){
#if !DOUBLE_LINK_LIST
            if(prev != NULL){
                *prev = last;
            }
#endif
            return current;
        }
        current = current->next;
#if !DOUBLE_LINK_LIST
        last = last->next;
#endif
    }

    UNLOCK;

    return NULL;
}

int link_list_delete(link_list_head_t *head, void *cmp_data)
{
    link_list_node_t *find = NULL;
#if !DOUBLE_LINK_LIST
    link_list_node_t *prev = NULL;

    find = link_list_find(head, cmp_data, &prev);
#else
    find = link_list_find(head, cmp_data);
#endif

    if(find == NULL)
        return 1;

    head->count--;
#if !DOUBLE_LINK_LIST
    prev->next = find->next;
    if(find->next == NULL)
        head->current = prev;
#else
    find->prev->next = find->next;
    if(find->next == NULL)
        head->current = find->prev;
#endif

    free(find->data);
    free(find);

    return 0;
}

int link_list_show_one(link_list_head_t *head, void *cmp_data, print_callback_t cb)
{
    link_list_node_t *find = NULL;
#if !DOUBLE_LINK_LIST
    find = link_list_find(head, cmp_data, NULL);
#else
    find = link_list_find(head, cmp_data);
#endif

    if(find == NULL)
        return 1;

    cb(find);

    return 0;
}

int link_list_show_all(link_list_head_t *head, print_callback_t cb)
{
    link_list_node_t *current = head->node->next;

    while(current != NULL){
        cb(current);

        current = current->next;
    }

    return 0;
}
