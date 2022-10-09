//fp style program
#pragma once

#include <utility>

template<typename T,typename U>
auto operator|(T&& a,U &&b) {
    return b(std::forward<T>(a));
}
