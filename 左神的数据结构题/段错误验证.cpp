#include <stdio.h>
#include <stdlib.h>

int main0305() {
    int* p = (int*)0xC0000fff;
    // 针对进程的内核空间写入数据，崩溃
    *p = 10;
    return 0;
}