#include <iostream>
#include <string>
#include <vector>
#include <map>

#include <fmt/core.h>

#include "mathutil.h"

#define LOOPS 10

// Entry point
int main() {
    fmt::print("Hello World!\n");

    for (int i = 0; i < LOOPS; ++i) {
        fmt::print("Looping: {}\n", i);
    }

    mathutil::MyAddAndSub my_util(55);
    auto res = my_util.add(1, 2);
    fmt::print("We got add result: {}\n", res);


    // Using standard C++ library should also be debuggable
    // and it should show nice symbols in the debugger watch window
    std::string str = "Hello";
    std::string str2 = "World";
    std::string str3 = str + " " + str2;
    fmt::print("We got string result: {}\n", str3);
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::map<std::string, int> my_map = {{"one", 1}, {"two", 2}, {"three", 3}};
    for (const auto& [key, value] : my_map) {
        fmt::print("Key: {}, Value: {}\n", key, value);
    }
    for (const auto& val : vec) {
        fmt::print("Value: {}\n", val);
    }

    fmt::print("Ok that is it.\n");
    return 0;
}