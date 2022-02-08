#include "tasks.h"

// TODO: implement functions from tasks.h


int math::fibonacci(int n)
{

    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

//  strutils::camel_to_snake("helloWorld); // "hello_world"
string strutils::camel_to_snake(string str)
{

}

/*
    Example:
    strutils::parse_uint("helloWorld", result);         // false
    strutils::parse_uint("123", result);                // true, result == 123
    strutils::parse_uint("999999999999999999", result); // false
*/
bool strutils::parse_uint(string str)
{

}
