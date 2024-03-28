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
            printf("ִ�� malloc ʧ��, ����%s\n", strerror(errno));
            // �ͷ��Ѿ�������ڴ棬�����ڴ�й©
            for (int j = 0; j < i; ++j) {
                free(addr[j]);
            }
            return -1;
        }
        printf("���̵߳��� malloc ������ 1GB ��С���ڴ棬���ڴ���ʼ��ַ��0X%p\n", addr[i]);
    }

    // ���������ַ��󣬲Ž���
    getchar();

    // �ͷ��Ѿ�������ڴ�
    for (i = 0; i < 4; ++i) {
        free(addr[i]);
    }

    return 0;
}
