#ifndef _TYPES_H_
#define _TYPES_H_

#define CONTINUE 1
#define FAKE     2
#define REWRITE  4
#define EXIT     8

enum minic_bool_t
{
    FALSE,
    TRUE
};

enum minic_status_t
{
    MINIC_OK,
    MINIC_ZERO,
    MINIC_NOMATCH,
    MINIC_FAIL
};

// 基本类型
typedef int             minic_int_t;
typedef unsigned int    minic_uint_t;
typedef long            minic_lint_t;
typedef char            minic_char_t;
typedef unsigned long   minic_ulint_t;

typedef minic_uint_t    minic_size_t;
typedef minic_int_t     minic_off_t;
typedef minic_ulint_t   minic_raddr_t;

typedef minic_int_t     minic_vid_t;
typedef minic_int_t     minic_pid_t;
typedef minic_int_t     minic_tid_t;

#include <common/ds.h>
// 网络
#include <sys/socket.h>
typedef struct sockaddr_chain
{
    struct sockaddr_in inaddr;
    minic_list_t list;
    
} minic_inaddr_chain_t;

typedef struct broad_domain
{
    minic_inaddr_chain_t chainode;
} minic_net_domain_t;


// 缓冲区
typedef struct memblock
{
    void *base;
    minic_size_t length;
} minic_memblock_t;

typedef struct buffer
{
    minic_size_t size;
    minic_memblock_t bufs[2];
} minic_recvbuf_t;

#endif