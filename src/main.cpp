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

    fmt::print("Ok that is it.\n");
    return 0;
}