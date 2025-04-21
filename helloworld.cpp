#include <fmt/core.h>

#define LOOPS 10

int add(int a, int b);


int main() {
    fmt::print("Hello World!\n");

    for (int i = 0; i < LOOPS; ++i) {
        fmt::print("Looping: {}\n", i);
    }

    auto res = add(1, 2);
    fmt::print("We got add result: {}\n", res);

    fmt::print("Ok that is it.\n");

    return 0;
}

int add(int a, int b) {
    return a + b;
}