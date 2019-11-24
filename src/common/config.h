#ifndef _CONFIG_H_
#define _CONFIG_H_

#define MAX_FILE_LEN    4096
#define MAX_SOCK_LEN    64
#define MAX_ADDR_LEN    128

#include <common/types.h>

// typedef struct baseconfig
// {
//     char log_file[4096];
// } minic_baseconfig_t;

// typedef struct voteconfig
// {
//     minic_baseconfig_t bconfig;
//     char abs_sock[4096];

// } minic_vconfig_t;

typedef struct frinode
{
    char name[MAX_ADDR_LEN];
    minic_char_t using;

    minic_list_t list;
} minic_frinode_t;

typedef struct config
{
    char log_file[MAX_FILE_LEN];
    char abs_sock[MAX_SOCK_LEN];
    minic_int_t port, fri_num;
    minic_frinode_t fris;
} minic_config_t;

minic_int_t addfrinode(minic_frinode_t *frino, minic_frinode_t *listhead);

#endif