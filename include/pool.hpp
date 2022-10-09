//内容池,一切的基础

#include <cstdio>

#define __mb__(x) (x*1024*1024)
#define mb4 __mb__(4)
#define mb128 __mb__(128)

#ifndef __mymb__
#define __mymb__ mb128 - __mb__(10)
#endif

template<std::size_t size>
struct __pool {
    char buff[size];
    std::size_t tot = size;

    __pool() = default;

    template<typename T>
    void * alloc(std::size_t count){
        return buff;
    }

    template<typename T>
    void dealloc(T * ptr,std::size_t count){

    }

};

constexpr __pool<__mymb__> mypool;

