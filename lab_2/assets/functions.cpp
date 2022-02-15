#include <iostream>

// You can use the C standard library, but with different paths
// Instead of `stdint.h` use `cstdint`, instead of `stdio.h` use `cstdio`, etc.
#include <cstdint>

void type_deduction() {
    // auto can be used to infer the type (type deduction)
    auto inferred1 = 1; // int
    auto inferred2 = 1ul; // unsigned long int

    const auto inferred3 = 1;   // const int
    decltype(auto) inferred4 = inferred1;   // Might (?) be useful for templates later
}

// Functions can have a trailing return type
// This will be useful later with templates + auto
auto trailing_return() -> int {
    return 5;
}

// Return type determined by first return statement
auto auto_return() {
    if (true)
    {
        return 42;
    }
    return 1;   // return type here must match the previous return
}

/*
 * Functions can be overloaded (multiple functions with the same name may exist)
 * They must have different parameter types/order/count.
 * Function names are mangled to allow calling from other translation units (https://demangler.com/).
 */
int fun1() { return 0; }
float fun1(float x) { return x; }           // Valid overload, differs by parameter count
float fun1(double x) { return x + 1; }      // Valid overload, differs by parameter type
// void fun1() {}                           // Invalid overload, differs only by return type

// Overloading also allows function parameters to have default values
int fun2(int x = 1, int y = 2) { return x + y; }

void overloads() {
    std::cout << fun1() << std::endl;

    // What will be printed here? 1 or 2?
    std::cout << fun1(1.0) << std::endl;

    // And here?
    std::cout << fun1(1.0f) << std::endl;

    // What about this?
    // std::cout << fun1(1) << std::endl;

    std::cout << fun2() << std::endl;
    std::cout << fun2(5) << std::endl;
    std::cout << fun2(5, 6) << std::endl;
}

int main() {
    overloads();

    return 0;
}
