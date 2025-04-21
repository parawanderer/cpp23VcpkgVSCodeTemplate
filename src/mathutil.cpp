#include "mathutil.h"

#include <fmt/core.h>

mathutil::MyAddAndSub::MyAddAndSub(int state)
{
    fmt::print("MyAddAndSub constructor called with state: {}\n", state);
    this->m_state = state;
}

int mathutil::MyAddAndSub::add(int a, int b)
{
    fmt::print("MyAddAndSub::add called with a: {}, b: {}\n", a, b);
    return a + b;
}

int mathutil::MyAddAndSub::diff(int a, int b)
{
    fmt::print("MyAddAndSub::diff called with a: {}, b: {}\n", a, b);
    return a - b;
}

int mathutil::MyAddAndSub::addToState(int integer)
{
    fmt::print("MyAddAndSub::addToState called with integer: {} while this->m_state was {}\n", integer, this->m_state);
    return this->add(this->m_state, integer);
}
