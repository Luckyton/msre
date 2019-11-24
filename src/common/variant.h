#ifndef _VARIANT_H_
#define _VARIANT_H_

#include <common/types.h>

typedef struct sockfd
{
    int fd;
    minic_list_t list;
} minic_sockfd_t;

// 变体-进程-线程

typedef struct thraed
{
    minic_pid_t tid, vtid;
    minic_int_t lastact;

    minic_list_t frilist;
} minic_thread_t;

typedef struct process
{
    minic_pid_t pid, vpid;
    minic_thread_t threads;
    minic_sockfd_t sockfds;
    
    minic_list_t frilist;
} minic_proc_t;

typedef struct variant
{
    

} minic_variant_t;

#endif