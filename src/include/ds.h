#ifndef _DF_H_
#define _DF_H_

#include <common/types.h>

#define list_for_each(pos, head) \
    for(pos = (head)->next; pos != (head); pos = pos->next)

#define list_entry(ptr, type, member) \
    ((type *)((char *)(ptr) - (unsigned long)(&(((type *)0)->member)))

typedef struct listnode
{
    struct listnode *prev, *next;
} minic_list_t;

/**
* 将一个元素插入链表
*/
minic_int_t insert_list(minic_list_t *elem, minic_list_t *prev, minic_list_t *next);

#endif