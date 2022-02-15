#include "tasks.h"

int main()
{
    int tmp = calculate_checksum("255.17.0.0");

    cout << "checksum: " << tmp << endl;

    return 0;
}
