# Numeric_Library
Development of a Numeric Library in Modern C++

Project Objective:

To design and implement a versatile numeric library utilizing the power of Modern C++ templates, demonstrating a solid understanding of template programming, arithmetic operations, and operator overloading.
Core Features:
 - Numeric Operations: The library will feature the following key numeric operations:
        max: Returns the maximum value among its arguments.
        min: Returns the minimum value among its arguments.
        sub: Returns the difference between its arguments.
        sum: Returns the summation between its arguments.

Template Programming: All functions must be implemented using C++ templates, allowing them to accept one or more parameters of arithmetic data types (e.g., int, float, double).
Arithmetic Data Types Support: The functions should work exclusively with arithmetic data types, demonstrating the library's focus on numeric operations.

------------------
Bonus Feature: Custom Data Type Support:
Implement support for a custom data type named Custom, which includes a specific behavior for the sub function:Custom Data Type Definition:

class Custom {
public:
    Custom(string b) : m_b{b} {}
private:
    string m_b;
};


