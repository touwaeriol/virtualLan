//
// Created by touwaerio on 2022/6/20.
//

#include "thread/ThreadPool.h"
#include "log/log.h"

#include <utility>

namespace vl::core {
    ThreadPool::ThreadPool(size_t tasks, size_t works) : _stop(false), _tasks(
            moodycamel::BlockingConcurrentQueue<std::function<void()>>(tasks)) {
        if (works == 0) {
            works = std::thread::hardware_concurrency() * 2;
        }
        for (size_t i = 0; i < works; ++i) {
            //创建工作线程
            std::thread worker = std::thread([this]() -> void {
                std::function<void()> task;
                for (;;) {
                    if (_stop) {
                        break;
                    }
                    _tasks.wait_dequeue(task);
                    task();
                }
            });
            //将工作线程加入线程组
            _workers.try_enqueue(std::move(worker));
        }
    }


    std::pair<bool, std::string> ThreadPool::execute(std::function<void()> &&f) {
        // don't allow enqueueing after stopping the pool
        if (_stop) {
            return {false, "线程池已经停止"};
        }
        auto ok = _tasks.try_enqueue([f(std::move(f))]() -> void {
            f();
        });
        if (ok) {
            return {true, ""};
        } else {
            return {false, "任务队列已满，无法添加"};
        }
    }

    std::pair<bool, std::string> ThreadPool::operator()(std::function<void()> &&f) {
        return execute(std::move(f));
    }


    ThreadPool::~ThreadPool() {
        if (!_stop) {
            _stop = true;
        }
        auto size = _workers.size_approx();
        std::thread work;
        for (int i = 0; i < size; ++i) {
            _workers.wait_dequeue(work);
            if (work.joinable()) {
                work.join();
            }
        }
    }

    ThreadPool GLOBE_POOL(1000);

    std::pair<bool, std::string> co(std::function<void()> &&f) {
        return GLOBE_POOL.execute(std::move(f));
    }
}