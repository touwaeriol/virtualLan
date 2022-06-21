//
// Created by touwaerio on 2022/6/19.
//

#ifndef VIRTUALLAN_THREADPOOL_H
#define VIRTUALLAN_THREADPOOL_H

#include <blockingconcurrentqueue.h>

#include "util/Uncopymovable.hpp"


namespace vl::core {
    class ThreadPool;
}


namespace vl::core {

    class Closure {

        friend std::pair<bool, std::string> execute(std::function<void()> f);


    public:
        Closure(std::function<void()>) : _f(_f) {}

        Closure() = default;

        Closure(const Closure &) = default;

        Closure(Closure &&) = default;

        Closure &operator=(Closure &&) = default;

        Closure &operator=(const Closure &) = default;

    public:
        void run()  {
            _f();
        }

    private:
        std::function<void()> _f;

    };


    class ThreadPool : public Uncopymovable {


    public:

        ThreadPool(size_t taskQueueCap, size_t threadCount = 0);

        ~ThreadPool() override;


        std::pair<bool, std::string> execute(std::function<void()> f);


    private:

        std::pair<bool,std::string> init() noexcept;


    private:

        volatile bool _stop;

        size_t _threadCount;

        size_t _taskQueueCap;

        moodycamel::BlockingConcurrentQueue<std::thread> _threadQueue;

        moodycamel::BlockingConcurrentQueue<Closure> _taskQueue;


    };


    extern ThreadPool GLOBE_POOL;

    extern std::pair<bool, std::string> co(std::function<void()> f);

    template<typename F>
    extern std::pair<bool, std::string> co(F &&f);


}


#endif //VIRTUALLAN_THREADPOOL_H
