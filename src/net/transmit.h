#ifndef _TRANSMIT_h_
#define _TRANSMIT_h_

#include <common/types.h>

// 广播

/**
* 描述：
*   在广播域上实现广播
* 参数：
*   domain : 广播域
*   buf : 广播内容
*   szie : 内容大小
*   block : 是否阻塞
*   asyn : 是否异步
* 备注：
*   默认阻塞异步
* 返回值：
*   
*/
minic_int_t broadcast(minic_net_domain_t *domain, 
    void *message, minic_size_t size, minic_int_t block, minic_int_t asyn);

/**
* 描述：
*   收听广播域
* 参数：
*   domain : 收听域
*   buf : 内容缓冲区
*   block : 是否阻塞
* 备注：
*   默认阻塞
* 返回值：
*   
*/
minic_int_t listenin(minic_net_domain_t *domain, minic_recvbuf_t *recvbuf, minic_int_t block);

#endif