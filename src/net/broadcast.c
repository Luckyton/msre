/**
* broadcast.c
*   该文件实现网络通信
*/

#include <net/transmit.h>

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
    void *message, minic_size_t size, minic_int_t block, minic_int_t asyn)
{
    minic_inaddr_chain_t *pnode;

}