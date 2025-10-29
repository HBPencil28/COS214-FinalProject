#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <thread>
#include <atomic>
#include <functional>

class Timer {
private:
    std::atomic<bool> active{true};
    std::thread worker;
    
public:
    void start(std::function<void()> func, int interval_ms) {
        worker = std::thread([=]() {
            while (active) {
                /*if (active)*/ func();
                std::this_thread::sleep_for(
                    std::chrono::milliseconds(interval_ms)
                );
                
            }
        });
    }
    
    void stop() {
        active = false;
        if (worker.joinable()) worker.join();
    }
    
    ~Timer() { stop(); }
};

#endif // TIMER_H