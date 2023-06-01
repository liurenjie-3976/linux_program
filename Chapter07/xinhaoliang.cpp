#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

class Semaphore {
public:
    explicit Semaphore(int count) : count_(count) {}

    void Acquire() {
        std::unique_lock<std::mutex> lock(mutex_);
        while (count_ == 0) {
            condition_.wait(lock);
        }
        count_--;
    }

    void Release() {
        std::unique_lock<std::mutex> lock(mutex_);
        count_++;
        condition_.notify_one();
    }

private:
    int count_;
    std::mutex mutex_;
    std::condition_variable condition_;
};

// 示例用法
Semaphore semaphore(2);  // 创建一个初始计数为2的信号量

void WorkerThread(int id) {
    semaphore.Acquire();
    std::cout << "Thread " << id << " is working..." << std::endl;
    // 执行一些工作
    semaphore.Release();
}

int main() {
    std::thread t1(WorkerThread, 1);
    std::thread t2(WorkerThread, 2);
    std::thread t3(WorkerThread, 3);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
