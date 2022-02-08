#pragma once
#include <iostream>
#include <thread>

void test(){
    printf("Hello from test C - %d\n", std::this_thread::get_id());
}
void funcA(){
    printf("Hello from A - %d\n",std::this_thread::get_id());
    std::thread threadC(test);
    threadC.join();
}
void funcB(){
    printf("Hello from B - %d\n",std::this_thread::get_id());
}
void run(){
    printf("Hello from main - %d \n", std::this_thread::get_id());
    std::thread threadA(funcA);
    std::thread threadB(funcB);

    threadA.join();
    threadB.join();
}