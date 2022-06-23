//
// Created by touwaerio on 2022/6/19.
//

#ifndef VIRTUALLAN_THREADPOOL_H
#define VIRTUALLAN_THREADPOOL_H

#include <vector>
#include <queue>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <stdexcept>

#include <blockingconcurrentqueue.h>

#include "util/Uncopymovable.hpp"
#include "log/log.h"


namespace vl::core {
    class ThreadPool;
}


namespace vl::core {


    class ThreadPool {
    public:
        ThreadPool(size_t tasks, size_t works = 0);

        std::pair<bool, std::string> execute(std::function<void()> &&f);

        std::pair<bool, std::string> operator()(std::function<void()> &&f);


        ~ThreadPool();

    private:
        // need to keep track of threads so we can join them
        mutable moodycamel::BlockingConcurrentQueue<std::thread> _workers;
        // the task queue
        mutable moodycamel::BlockingConcurrentQueue<std::function<void()> > _tasks;

        volatile bool _stop;
    };


    extern ThreadPool GLOBE_POOL;

    std::pair<bool, std::string> co(std::function<void()> &&f);


}


#endif //VIRTUALLAN_THREADPOOL_H
