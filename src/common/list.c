
#include <common/ds.h>

minic_int_t insert_list(minic_list_t *elem, minic_list_t *prev, minic_list_t *next)
{
    if(elem == NULL) {
        return MINIC_OK;
    } else if(prev && next && 
                prev->next == next && next->prev == prev) {
        prev->next = elem;
        elem->prev = prev;
        elem->next = next;
        next->prev = elem;
    } else if(prev == NULL && next && next->prev == NULL) {
        next->prev = elem;
        elem->next = next;
        elem->prev = NULL;
    } else if(next == NULL && prev && prev->next == NULL) {
        prev->next = elem;
        elem->prev = prev;
        elem->next = NULL;
    } else {
        return MINIC_NOMATCH;
    }

    return MINIC_OK;
}