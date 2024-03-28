#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#pragma warning(disable:4996)

#define MEM_SIZE (1024 * 1024 * 1024)

int main030601() {
    char* addr[4];
    int i = 0;

    for (i = 0; i < 4; ++i) {
        addr[i] = (char*)malloc(MEM_SIZE);
        if (addr[i] == NULL) {
            printf("执行 malloc 失败, 错误：%s\n", strerror(errno));
            // 释放已经分配的内存，避免内存泄漏
            for (int j = 0; j < i; ++j) {
                free(addr[j]);
            }
            return -1;
        }
        printf("主线程调用 malloc 后，申请 1GB 大小的内存，此内存起始地址：0X%p\n", addr[i]);
    }

    // 输入任意字符后，才结束
    getchar();

    // 释放已经分配的内存
    for (i = 0; i < 4; ++i) {
        free(addr[i]);
    }

    return 0;
}
