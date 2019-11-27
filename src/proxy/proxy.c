/**
 * VoteProxy模块
 * proxy.c
 *      工作： 启动表决代理
 *      工作流程：
 *          1. 解析配置文件
 *          2. 创建连接，监听端口
 *          3. 监听到请求后，多线程处理 (加锁)
 */

#include <common/parse.h>
#include <common/config.h>

static minic_config_t jmproxy;
static minic_config_t proxycfg;
static minic_config_t moniproxy;

int main(int argc, char *argv[])
{
    // // 添加代码，记录日志

    if(parseconf("etc/voteproxy.etc", &proxyetc) != MINIC_OK) {
        // 添加代码，解析配置文件失败，启动voteproxy失败。
    }
    
    
    
    return 0;
}