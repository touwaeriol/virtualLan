//
// Created by touwaerio on 2022/6/20.
//

#include "thread/ThreadPool.h"

#include <utility>

namespace vl::core {


    ThreadPool::ThreadPool(size_t taskQueueCap, size_t threadCount) :
            _taskQueueCap(taskQueueCap),
            _taskQueue(taskQueueCap),
            _threadQueue(threadCount),
            _threadCount(threadCount),
            _stop(false) {
        if (_threadCount == 0) {
            _threadCount = std::thread::hardware_concurrency() * 2;
        }
    }

    ThreadPool::~ThreadPool() {

    }

    std::pair<bool, std::string> ThreadPool::execute(std::function<void()> f) {
        //如果线程数量没有达到最大，则新建线程
        if (_threadQueue.size_approx() < _threadCount) {
            auto ok = _threadQueue.try_enqueue(std::thread([this]() -> void {
                Closure f;
                while (true) {
                    _taskQueue.wait_dequeue(f);
                    try {
                        f.run();
                    } catch (std::exception &e) {
                        ELOG << "任务抛出异常： " << e.what();
                    }
                }
            }));
            if (!ok) {
                return std::pair<bool, std::string>{false, "线程创建失败"};
            }
        }
        _taskQueue.try_enqueue(Closure(std::move(f)));

    }


    ThreadPool GLOBE_POOL(1000);


    std::pair<bool, std::string> co(std::function<void()> f) {
        return GLOBE_POOL.execute(std::move(f));
    }

    template<typename F>
    std::pair<bool, std::string> co(F &&f) {
        return GLOBE_POOL.execute([fp(f)]() -> void {
            fp();
        });
    }
}