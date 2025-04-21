#ifndef MATHUTIL_H
#define MATHUTIL_H

/// @brief Some math-related utilities
namespace mathutil {

    /// @brief Example class for adding and subtraction :)
    class MyAddAndSub {
    public:
        /// @brief Generic constructor
        ///
        /// @param state  Which state to initialise the instance with
        MyAddAndSub(int state);

        /// @brief Computes the sum of `a + b`
        ///
        /// @param a    Some integer to be summed
        /// @param b    Another integer to be summed
        ///
        /// @return     The sum `a + b`
        int add(int a, int b);

        /// @brief Computes the difference of `a - b`
        ///
        /// @param a    Some integer
        /// @param b    Some other integer to subtract off of `a`
        ///
        /// @return     The difference `a - b`
        int diff(int a, int b);

        /// @brief Sums `integer` to the `state` the instance was initialised with
        ///
        /// @param integer      Some integer to sum to `state`
        ///
        /// @return             The sum of `this->state + integer`
        int addToState(int integer);
    private:
        int m_state;
    };

}

#endif