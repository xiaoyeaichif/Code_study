#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <shared_mutex>

std::vector<int> sharedData;  // �������ݽṹ
std::shared_mutex rwMutex;   // ��д��

// ��ȡ�̺߳���
void readFunction(int threadID) {
    std::shared_lock<std::shared_mutex> lock(rwMutex);

    // ִ�ж�ȡ����
    std::cout << "Thread " << threadID << " is reading. Data: ";
    for (const auto& element : sharedData) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

// д���̺߳���
void writeFunction(int threadID, int value) {
    std::unique_lock<std::shared_mutex> lock(rwMutex);

    // ִ��д�����
    sharedData.push_back(value);
    std::cout << "Thread " << threadID << " is writing. New value: " << value << std::endl;
}

int mainRead() {
    // ���������ȡ�̺߳�д���߳�
    std::thread reader1(readFunction, 1);
    std::thread reader2(readFunction, 2);
    std::thread writer1(writeFunction, 3, 42);
    std::thread reader3(readFunction, 4);
    std::thread writer2(writeFunction, 5, 99);

    // �ȴ��߳����
    reader1.join();
    reader2.join();
    writer1.join();
    reader3.join();
    writer2.join();

    return 0;
}
