#include <stdio.h>
#include <stdlib.h>

int main0305() {
    int* p = (int*)0xC0000fff;
    // ��Խ��̵��ں˿ռ�д�����ݣ�����
    *p = 10;
    return 0;
}