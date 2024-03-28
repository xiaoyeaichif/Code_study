#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <shared_mutex>

std::vector<int> sharedData;  // 共享数据结构
std::shared_mutex rwMutex;   // 读写锁

// 读取线程函数
void readFunction(int threadID) {
    std::shared_lock<std::shared_mutex> lock(rwMutex);

    // 执行读取操作
    std::cout << "Thread " << threadID << " is reading. Data: ";
    for (const auto& element : sharedData) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

// 写入线程函数
void writeFunction(int threadID, int value) {
    std::unique_lock<std::shared_mutex> lock(rwMutex);

    // 执行写入操作
    sharedData.push_back(value);
    std::cout << "Thread " << threadID << " is writing. New value: " << value << std::endl;
}

int mainRead() {
    // 启动多个读取线程和写入线程
    std::thread reader1(readFunction, 1);
    std::thread reader2(readFunction, 2);
    std::thread writer1(writeFunction, 3, 42);
    std::thread reader3(readFunction, 4);
    std::thread writer2(writeFunction, 5, 99);

    // 等待线程完成
    reader1.join();
    reader2.join();
    writer1.join();
    reader3.join();
    writer2.join();

    return 0;
}
