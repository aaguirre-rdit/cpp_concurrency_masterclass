#pragma once
#include <iostream>
#include <thread>

void hello_world(){
    printf("Hello World - %d \n",std::this_thread::get_id());
}
class callable_class{
public:
    void operator()()
    {
        printf("Hello from class with fn called operator - %d \n",std::this_thread::get_id());
    }
};

void run(){
    std::thread thread1(hello_world);
    
    printf("Hello from main - %d \n", std::this_thread::get_id());
    callable_class obj;
    std::thread thread2(obj);
    std::thread thread3([]{
        printf("Hello from lambda - %d \n", std::this_thread::get_id());
    });
    thread1.join();
    thread2.join();
}