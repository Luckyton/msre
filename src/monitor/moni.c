/**
* moni.c
*   本文件实现监控器
*/

// #include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <syscall.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <sys/ptrace.h>

#include <common/sc.h>
#include <common/types.h>

static void varexit(minic_int_t status)
{
    
}

static minic_int_t run(char *argv[])
{
    minic_pid_t son;

    son = fork();
    
    switch (son)
    {
    case -1:
        // 添加代码， 记录日志
        // fork错误，通知jobmanager，本变体终结
        varexit(1);     // fork error状态码
    case 0:
        ptrace(PTRACE_TRACEME, 0, NULL, NULL);
        execv(argv[0], argv);
        break;
    default:
        waitpid(son, NULL, __WALL);
        ptrace(PTRACE_SETOPTIONS, son, NULL, 
            PTRACE_O_TRACECLONE | PTRACE_O_TRACEEXEC | PTRACE_O_TRACEEXIT |
            PTRACE_O_TRACEFORK | PTRACE_O_TRACEVFORK | PTRACE_O_TRACESYSGOOD);
        // 添加代码
        // 添加变体成功, 通知jobmanager，接收变体号
        ptrace(PTRACE_SYSCALL, son, NULL, NULL);
        break;
    }

    return minic_ok;
}

static inline minic_int_t isvote(minic_int_t nr)
{
    switch (nr)
    {
    case __NR_sendfile:
    case __NR_sendto:
    case __NR_sendmmsg:
    case __NR_sendmsg:
        // 网络通信吐数据，需要表决
        return TRUE;
    case __NR_write:
        // 如果是write系统调用，要分情况，看文件描述符是不是套接字描述符
        break;
    default:
        return FALSE;
    }
}

static minic_int_t doaction(minic_tid_t tid, minic_int_t action)
{
    if(action & FAKE) {
        ptrace(PTRACE_POKEUSER, tid, 8 * 15, _NR_getpid);
    }
    if(action & REWRITE) {
        // 添加代码，重写寄存器数据
    }
    if(action & CONTINUE) {
        ptrace(PTRACE_SYSCALL, tid, NULL, NULL);
    }
}

static minic_int_t handle_syscall(minic_pid_t son)
{
    minic_sc_args_t args;
    struct user_regs_struct regs;

    ptrace(PTRACE_GETREGS, son, NULL, &regs);
    args.nr = regs.orig_rax;

    if(isvote((minic_int_t)args.nr)) {
        args.args[0] = regs.rdi;
        args.args[1] = regs.rsi;
        args.args[2] = regs.rdx;
        args.args[3] = regs.r10;
        args.args[4] = regs.r8;
        args.args[5] = regs.r9;

        // minic_int_t action = vote();
        // 根据协商表决结果，完成接下来的操作
        doaction(action);
        
    } else {
        ptrace(PTRACE_SYSCALL, son, NULL, NULL);
    }

    return MINIC_OK;
}

static minic_int_t monitor()
{
    minic_int_t status, sig, event;
    minic_pid_t pid;

    while (TRUE)
    {
        pid = waitpid(-1, &status, __WALL);
        sig = WSTOPSIG(status);
        event = status >> 16;

        if(WIFEXITED(status)) {
            // 添加代码，变体运行结束，通知jobmanager， 记录日志
            break;
        } else if(WIFSTOPPED(status) && (sig == (SIGTRAP | 0x80))) {
            // 捕捉到系统调用, 添加代码，记录日志
            handle_syscall(pid);
        } else if(sig == SIGTRAP && event == PTRACE_EVENT_EXEC) {
            ptrace(PTRACE_SYSCALL, pid, NULL, NULL);
        } else if(sig == SIGTRAP && (event == PTRACE_EVENT_FORK ||
                event == PTRACE_EVEBT_VFORK || event == PTRACE_EVENT_CLONE)) {
            // 添加代码
            // 创建了一个新线/进程
        } else if(WIFSIGNALED(status)) {
            // 添加代码
            // 进程异常结束
        }else {
            ptrace(PTRACE_SYSCALL, pid, NULL, NULL);
        }
    }

    return MINIC_OK;
}

// 信号处理程序，实现为可重入的
static volite void sighandle(int sig)
{
    // 添加信号处理代码

     _exit(0);
}

int main(int argc, char *argv[])
{
    struct sigaction sa;

    // 添加代码，读取配置文件

    // 添加信号处理函数
    sa.handler = sighandle;
    sigempty(&sa.sa_mask);
    sigaction(SIGTERM, &sa, NULL);

    run(argv + 1);
    monitor();

    return 0;
}