#ifndef _SC_H_
#define _SC_H_

#include <common/types.h>

typedef struct scargs
{
    minic_ulint_t nr;
    minic_ulint_t args[6];
} minic_sc_args_t;

struct syscall_signature {
   unsigned nr;
   unsigned nr_args;
   const char *name;
};

static struct syscall_signature syscall_signatures[] = {
 [0] = { 0, 3, "read" },
 [1] = { 1, 3, "write" },
 [2] = { 2, 3, "open" },
 [3] = { 3, 1, "close" },
 [4] = { 4, 2, "stat" },
 [5] = { 5, 2, "fstat" },
 [6] = { 6, 2, "lstat" },
 [7] = { 7, 3, "poll" },
 [8] = { 8, 3, "lseek" },
 [9] = { 9, 6, "mmap" },
 [10] = { 10, 3, "mprotect" },
 [11] = { 11, 2, "munmap" },
 [12] = { 12, 1, "brk" },
 [13] = { 13, 4, "rt_sigaction" },
 [14] = { 14, 4, "rt_sigprocmask" },
 [15] = { 15, 0, "rt_sigreturn" },
 [16] = { 16, 3, "ioctl" },
 [17] = { 17, 4, "pread64" },
 [18] = { 18, 4, "pwrite64" },
 [19] = { 19, 3, "readv" },
 [20] = { 20, 3, "writev" },
 [21] = { 21, 2, "access" },
 [22] = { 22, 1, "pipe" },
 [23] = { 23, 5, "select" },
 [24] = { 24, 0, "sched_yield" },
 [25] = { 25, 5, "mremap" },
 [26] = { 26, 3, "msync" },
 [27] = { 27, 3, "mincore" },
 [28] = { 28, 3, "madvise" },
 [29] = { 29, 3, "shmget" },
 [30] = { 30, 3, "shmat" },
 [31] = { 31, 3, "shmctl" },
 [32] = { 32, 1, "dup" },
 [33] = { 33, 2, "dup2" },
 [34] = { 34, 0, "pause" },
 [35] = { 35, 2, "nanosleep" },
 [36] = { 36, 2, "getitimer" },
 [37] = { 37, 1, "alarm" },
 [38] = { 38, 3, "setitimer" },
 [39] = { 39, 0, "getpid" },
 [40] = { 40, 4, "sendfile" },
 [41] = { 41, 3, "socket" },
 [42] = { 42, 3, "connect" },
 [43] = { 43, 3, "accept" },
 [44] = { 44, 6, "sendto" },
 [45] = { 45, 6, "recvfrom" },
 [46] = { 46, 3, "sendmsg" },
 [47] = { 47, 3, "recvmsg" },
 [48] = { 48, 2, "shutdown" },
 [49] = { 49, 3, "bind" },
 [50] = { 50, 2, "listen" },
 [51] = { 51, 3, "getsockname" },
 [52] = { 52, 3, "getpeername" },
 [53] = { 53, 4, "socketpair" },
 [54] = { 54, 5, "setsockopt" },
 [55] = { 55, 5, "getsockopt" },
 [56] = { 56, 5, "clone" },
 [57] = { 57, 0, "fork" },
 [58] = { 58, 0, "vfork" },
 [59] = { 59, 3, "execve" },
 [60] = { 60, 1, "exit" },
 [61] = { 61, 4, "wait4" },
 [62] = { 62, 2, "kill" },
 [63] = { 63, 1, "uname" },
 [64] = { 64, 3, "semget" },
 [65] = { 65, 3, "semop" },
 [66] = { 66, 4, "semctl" },
 [67] = { 67, 1, "shmdt" },
 [68] = { 68, 2, "msgget" },
 [69] = { 69, 4, "msgsnd" },
 [70] = { 70, 5, "msgrcv" },
 [71] = { 71, 3, "msgctl" },
 [72] = { 72, 3, "fcntl" },
 [73] = { 73, 2, "flock" },
 [74] = { 74, 1, "fsync" },
 [75] = { 75, 1, "fdatasync" },
 [76] = { 76, 2, "truncate" },
 [77] = { 77, 2, "ftruncate" },
 [78] = { 78, 3, "getdents" },
 [79] = { 79, 2, "getcwd" },
 [80] = { 80, 1, "chdir" },
 [81] = { 81, 1, "fchdir" },
 [82] = { 82, 2, "rename" },
 [83] = { 83, 2, "mkdir" },
 [84] = { 84, 1, "rmdir" },
 [85] = { 85, 2, "creat" },
 [86] = { 86, 2, "link" },
 [87] = { 87, 1, "unlink" },
 [88] = { 88, 2, "symlink" },
 [89] = { 89, 3, "readlink" },
 [90] = { 90, 2, "chmod" },
 [91] = { 91, 2, "fchmod" },
 [92] = { 92, 3, "chown" },
 [93] = { 93, 3, "fchown" },
 [94] = { 94, 3, "lchown" },
 [95] = { 95, 1, "umask" },
 [96] = { 96, 2, "gettimeofday" },
 [97] = { 97, 2, "getrlimit" },
 [98] = { 98, 2, "getrusage" },
 [99] = { 99, 1, "sysinfo" },
 [100] = { 100, 1, "times" },
 [101] = { 101, 4, "ptrace" },
 [102] = { 102, 0, "getuid" },
 [103] = { 103, 3, "syslog" },
 [104] = { 104, 0, "getgid" },
 [105] = { 105, 1, "setuid" },
 [106] = { 106, 1, "setgid" },
 [107] = { 107, 0, "geteuid" },
 [108] = { 108, 0, "getegid" },
 [109] = { 109, 2, "setpgid" },
 [110] = { 110, 0, "getppid" },
 [111] = { 111, 0, "getpgrp" },
 [112] = { 112, 0, "setsid" },
 [113] = { 113, 2, "setreuid" },
 [114] = { 114, 2, "setregid" },
 [115] = { 115, 2, "getgroups" },
 [116] = { 116, 2, "setgroups" },
 [117] = { 117, 3, "setresuid" },
 [118] = { 118, 3, "getresuid" },
 [119] = { 119, 3, "setresgid" },
 [120] = { 120, 3, "getresgid" },
 [121] = { 121, 1, "getpgid" },
 [122] = { 122, 1, "setfsuid" },
 [123] = { 123, 1, "setfsgid" },
 [124] = { 124, 1, "getsid" },
 [125] = { 125, 2, "capget" },
 [126] = { 126, 2, "capset" },
 [127] = { 127, 2, "rt_sigpending" },
 [128] = { 128, 4, "rt_sigtimedwait" },
 [129] = { 129, 3, "rt_sigqueueinfo" },
 [130] = { 130, 2, "rt_sigsuspend" },
 [131] = { 131, 2, "sigaltstack" },
 [132] = { 132, 2, "utime" },
 [133] = { 133, 3, "mknod" },
 [134] = { 134, 1, "uselib" },
 [135] = { 135, 1, "personality" },
 [136] = { 136, 2, "ustat" },
 [137] = { 137, 2, "statfs" },
 [138] = { 138, 2, "fstatfs" },
 [139] = { 139, 3, "sysfs" },
 [140] = { 140, 2, "getpriority" },
 [141] = { 141, 3, "setpriority" },
 [142] = { 142, 2, "sched_setparam" },
 [143] = { 143, 2, "sched_getparam" },
 [144] = { 144, 3, "sched_setscheduler" },
 [145] = { 145, 1, "sched_getscheduler" },
 [146] = { 146, 1, "sched_get_priority_max" },
 [147] = { 147, 1, "sched_get_priority_min" },
 [148] = { 148, 2, "sched_rr_get_interval" },
 [149] = { 149, 2, "mlock" },
 [150] = { 150, 2, "munlock" },
 [151] = { 151, 1, "mlockall" },
 [152] = { 152, 0, "munlockall" },
 [153] = { 153, 0, "vhangup" },
 [154] = { 154, 3, "modify_ldt" },
 [155] = { 155, 2, "pivot_root" },
 [156] = { 156, 1, "_sysctl" },
 [157] = { 157, 5, "prctl" },
 [158] = { 158, 2, "arch_prctl" },
 [159] = { 159, 1, "adjtimex" },
 [160] = { 160, 2, "setrlimit" },
 [161] = { 161, 1, "chroot" },
 [162] = { 162, 0, "sync" },
 [163] = { 163, 1, "acct" },
 [164] = { 164, 2, "settimeofday" },
 [165] = { 165, 5, "mount" },
 [166] = { 166, 2, "umount2" },
 [167] = { 167, 2, "swapon" },
 [168] = { 168, 1, "swapoff" },
 [169] = { 169, 4, "reboot" },
 [170] = { 170, 2, "sethostname" },
 [171] = { 171, 2, "setdomainname" },
 [172] = { 172, 1, "iopl" },
 [173] = { 173, 3, "ioperm" },
 [174] = { 174, 0, "create_module" },
 [175] = { 175, 3, "init_module" },
 [176] = { 176, 2, "delete_module" },
 [177] = { 177, 0, "get_kernel_syms" },
 [178] = { 178, 0, "query_module" },
 [179] = { 179, 4, "quotactl" },
 [180] = { 180, 0, "nfsservctl" },
 [181] = { 181, 0, "getpmsg" },
 [182] = { 182, 0, "putpmsg" },
 [183] = { 183, 0, "afs_syscall" },
 [184] = { 184, 0, "tuxcall" },
 [185] = { 185, 0, "security" },
 [186] = { 186, 0, "gettid" },
 [187] = { 187, 3, "readahead" },
 [188] = { 188, 5, "setxattr" },
 [189] = { 189, 5, "lsetxattr" },
 [190] = { 190, 5, "fsetxattr" },
 [191] = { 191, 4, "getxattr" },
 [192] = { 192, 4, "lgetxattr" },
 [193] = { 193, 4, "fgetxattr" },
 [194] = { 194, 3, "listxattr" },
 [195] = { 195, 3, "llistxattr" },
 [196] = { 196, 3, "flistxattr" },
 [197] = { 197, 2, "removexattr" },
 [198] = { 198, 2, "lremovexattr" },
 [199] = { 199, 2, "fremovexattr" },
 [200] = { 200, 2, "tkill" },
 [201] = { 201, 1, "time" },
 [202] = { 202, 6, "futex" },
 [203] = { 203, 3, "sched_setaffinity" },
 [204] = { 204, 3, "sched_getaffinity" },
 [205] = { 205, 1, "set_thread_area" },
 [206] = { 206, 2, "io_setup" },
 [207] = { 207, 1, "io_destroy" },
 [208] = { 208, 5, "io_getevents" },
 [209] = { 209, 3, "io_submit" },
 [210] = { 210, 3, "io_cancel" },
 [211] = { 211, 1, "get_thread_area" },
 [212] = { 212, 3, "lookup_dcookie" },
 [213] = { 213, 1, "epoll_create" },
 [214] = { 214, 0, "epoll_ctl_old" },
 [215] = { 215, 0, "epoll_wait_old" },
 [216] = { 216, 5, "remap_file_pages" },
 [217] = { 217, 3, "getdents64" },
 [218] = { 218, 1, "set_tid_address" },
 [219] = { 219, 0, "restart_syscall" },
 [220] = { 220, 4, "semtimedop" },
 [221] = { 221, 4, "fadvise64" },
 [222] = { 222, 3, "timer_create" },
 [223] = { 223, 4, "timer_settime" },
 [224] = { 224, 2, "timer_gettime" },
 [225] = { 225, 1, "timer_getoverrun" },
 [226] = { 226, 1, "timer_delete" },
 [227] = { 227, 2, "clock_settime" },
 [228] = { 228, 2, "clock_gettime" },
 [229] = { 229, 2, "clock_getres" },
 [230] = { 230, 4, "clock_nanosleep" },
 [231] = { 231, 1, "exit_group" },
 [232] = { 232, 4, "epoll_wait" },
 [233] = { 233, 4, "epoll_ctl" },
 [234] = { 234, 3, "tgkill" },
 [235] = { 235, 2, "utimes" },
 [236] = { 236, 0, "vserver" },
 [237] = { 237, 6, "mbind" },
 [238] = { 238, 3, "set_mempolicy" },
 [239] = { 239, 5, "get_mempolicy" },
 [240] = { 240, 4, "mq_open" },
 [241] = { 241, 1, "mq_unlink" },
 [242] = { 242, 5, "mq_timedsend" },
 [243] = { 243, 5, "mq_timedreceive" },
 [244] = { 244, 2, "mq_notify" },
 [245] = { 245, 3, "mq_getsetattr" },
 [246] = { 246, 4, "kexec_load" },
 [247] = { 247, 5, "waitid" },
 [248] = { 248, 5, "add_key" },
 [249] = { 249, 4, "request_key" },
 [250] = { 250, 5, "keyctl" },
 [251] = { 251, 3, "ioprio_set" },
 [252] = { 252, 2, "ioprio_get" },
 [253] = { 253, 0, "inotify_init" },
 [254] = { 254, 3, "inotify_add_watch" },
 [255] = { 255, 2, "inotify_rm_watch" },
 [256] = { 256, 4, "migrate_pages" },
 [257] = { 257, 4, "openat" },
 [258] = { 258, 3, "mkdirat" },
 [259] = { 259, 4, "mknodat" },
 [260] = { 260, 5, "fchownat" },
 [261] = { 261, 3, "futimesat" },
 [262] = { 262, 4, "newfstatat" },
 [263] = { 263, 3, "unlinkat" },
 [264] = { 264, 4, "renameat" },
 [265] = { 265, 5, "linkat" },
 [266] = { 266, 3, "symlinkat" },
 [267] = { 267, 4, "readlinkat" },
 [268] = { 268, 3, "fchmodat" },
 [269] = { 269, 3, "faccessat" },
 [270] = { 270, 6, "pselect6" },
 [271] = { 271, 5, "ppoll" },
 [272] = { 272, 1, "unshare" },
 [273] = { 273, 2, "set_robust_list" },
 [274] = { 274, 3, "get_robust_list" },
 [275] = { 275, 6, "splice" },
 [276] = { 276, 4, "tee" },
 [277] = { 277, 4, "sync_file_range" },
 [278] = { 278, 4, "vmsplice" },
 [279] = { 279, 6, "move_pages" },
 [280] = { 280, 4, "utimensat" },
 [281] = { 281, 6, "epoll_pwait" },
 [282] = { 282, 3, "signalfd" },
 [283] = { 283, 2, "timerfd_create" },
 [284] = { 284, 1, "eventfd" },
 [285] = { 285, 4, "fallocate" },
 [286] = { 286, 4, "timerfd_settime" },
 [287] = { 287, 2, "timerfd_gettime" },
 [288] = { 288, 4, "accept4" },
 [289] = { 289, 4, "signalfd4" },
 [290] = { 290, 2, "eventfd2" },
 [291] = { 291, 1, "epoll_create1" },
 [292] = { 292, 3, "dup3" },
 [293] = { 293, 2, "pipe2" },
 [294] = { 294, 1, "inotify_init1" },
 [295] = { 295, 5, "preadv" },
 [296] = { 296, 5, "pwritev" },
 [297] = { 297, 4, "rt_tgsigqueueinfo" },
 [298] = { 298, 5, "perf_event_open" },
 [299] = { 299, 5, "recvmmsg" },
 [300] = { 300, 2, "fanotify_init" },
 [301] = { 301, 5, "fanotify_mark" },
 [302] = { 302, 4, "prlimit64" },
 [303] = { 303, 5, "name_to_handle_at" },
 [304] = { 304, 3, "open_by_handle_at" },
 [305] = { 305, 2, "clock_adjtime" },
 [306] = { 306, 1, "syncfs" },
 [307] = { 307, 4, "sendmmsg" },
 [308] = { 308, 2, "setns" },
 [309] = { 309, 3, "getcpu" },
 [310] = { 310, 6, "process_vm_readv" },
 [311] = { 311, 6, "process_vm_writev" },
 [312] = { 312, 5, "kcmp" },
 [313] = { 313, 3, "finit_module" },
 [314] = { 314, 3, "sched_setattr" },
 [315] = { 315, 4, "sched_getattr" },
 [316] = { 316, 5, "renameat2" },
 [317] = { 317, 3, "seccomp" },
 [318] = { 318, 3, "getrandom" },
 [319] = { 319, 2, "memfd_create" },
 [320] = { 320, 5, "kexec_file_load" },
 [321] = { 321, 3, "bpf" },
 [500] = { 500, 0, "RDTSC" },
};

#endif