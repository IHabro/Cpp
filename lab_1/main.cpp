#include "tasks.h"

#include <iostream>

using std::cout;
using std::endl;

int main()
{
    cout << math::fibonacci(0) << endl;
    cout << math::fibonacci(1) << endl;
    cout << math::fibonacci(2) << endl;
    cout << math::fibonacci(3) << endl;

    cout << strutils::camel_to_snake("helloWorld") << endl;

    

    return 0;
}


