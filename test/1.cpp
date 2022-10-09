#include <iostream>
#include "itertools.hpp"

int main(){
    constexpr auto range = rainboy::range(1, 10);
    auto b = range.begin();
    auto e = range.end();
    for( ; b != range.end(); ++b) {
        std::cout << *b << "\n";
    }
    std::cout << "=====================" << "\n";
    for (const auto& e : range) {
        std::cout << e << "\n";
    }
    return 0;
}
