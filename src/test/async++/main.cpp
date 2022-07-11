//
// Created by touwaerio on 2022/6/30.
//

#include <iostream>
#include <thread>
#include <utility>
#include <chrono>

#include <async++.h>

template<typename Func>
void co(Func &&f) {
    auto task = async::spawn(f);
}

int main(int argc, char **argv) {
    auto pool = async::threadpool_scheduler(10);

    for (int i = 0; i < 10000; ++i) {
        co([i]() -> void {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "程序结束了:" << std::to_string(i) << std::endl;
        });
    }


    return 0;
}
