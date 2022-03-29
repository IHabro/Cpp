#include <algorithm>
#include <cassert>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <random>
#include <sstream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

struct Point {
    int x;
    int y;
};

std::ostream &operator<<(std::ostream &os, const Point &point) {
    os << "Point(" << point.x << ", " << point.y << ")";
    return os;
}
std::istream &operator>>(std::istream &is, Point &point) {
    is >> point.x >> point.x;
    return is;
}

int main() {
    // Streams are abstractions for reading/writing data
    // They provide the same interface for writing, regardless of the backend (file, terminal, socket, memory buffer, ...)
    // https://en.cppreference.com/w/cpp/io#Stream-based_I.2FO

    // Standard output
    // std::cout, std::cerr are global variables, instances of std::ostream

    // C++ streams are by default synchronized with C output.
    // You can turn it off to get more I/O performance:
    std::ios::sync_with_stdio(false);

    // You can write to an output stream with <<
    cout << "Hello" << 1 << "\n";
    // Support for custom types can be provided with operator<< overload
    Point p{1, 2};
    cout << p << "\n";

        Point point2{};
    cin >> point2;

    // There are I/O manipulators to modify output (https://en.cppreference.com/w/cpp/io/manip)
    cout << std::hex << 15 << "\n";
    // Manipulators change the state of the stream
    cout << 16 << std::dec << " " << 16 << "\n";

    std::random_device rd;
    std::mt19937 generator{rd()};
    cout << generator() << endl;
    std::uniform_real_distribution<double> distribution_utery(0, 20);
    std::vector<std::vector<double>> cisla{};
    for (int i = 0; i < 10; ++i) {
        std::vector<double> row{};
        for (int j = 0; j < 10; ++j) {
            row.push_back(distribution_utery(generator));
        }
        cisla.push_back(row);
    }

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << cisla[i][j] << " ";
        }
        cout << endl;
    }

    //           1       2       3       4       5       6       7       8       9      10
    //   1 [    0.94   11.28   14.94    8.12    3.49    6.38    7.10   14.14   12.79   19.07  ] 1
    //   2 [    1.43   10.38   12.79    4.13    7.51    2.28    0.35    1.39   10.08   19.26  ] 2
    //   3 [    5.75    0.02   19.18   16.81   16.90   13.39    6.60   16.15    6.30    4.70  ] 3
    //   4 [   15.84    3.00   12.56   19.89    7.67   18.56   11.07    2.79   10.46   18.35  ] 4
    //   5 [   13.64    6.26    1.98    3.67   16.78   14.97   18.37    1.83    4.60    5.99  ] 5
    //   6 [   11.24    1.27    7.76    4.27   11.10   13.76    9.40   10.01   14.88   12.44  ] 6
    //   7 [   13.82    0.88    8.49   16.59   11.34   15.39    2.30   10.87    4.38    7.54  ] 7
    //   8 [   14.83   15.07   12.11    6.41   12.76    4.37    5.83    8.76   17.33    2.15  ] 8
    //   9 [    9.47    4.92   10.82    8.27   17.68    6.54   13.36   19.74    0.22    5.67  ] 9
    //  10 [    5.98    4.57    6.06   18.66    8.69    8.62    3.88   15.73   18.72   18.30  ] 10
    //           1       2       3       4       5       6       7       8       9      10


    std::vector<int> v1{1, 2, 3, 4, 5};
    //pomoci std::copy_if std::ostream_iterator vypsat do console odděleno čárkami jenom sude
    std::copy_if(v1.begin(), v1.end(), std::ostream_iterator<int>(cout, ", "), [](auto value) { return value % 2 == 0; });

  

    // Files are handled with std::fstream
    // uložit vectoru do textoveho souboru a načist z textoveho souboru do vectoru
    std::vector<int> vec_to_text{6, 7, 8, 9, 10, 11, 1, 22, 33};
    std::ofstream fs("out_vec.txt"); // or std::fstream fs("out.txt", std::ios::out);
    assert(fs.is_open());        // should be always checked first!
    for (auto &i : vec_to_text) {
        fs << i << " ";
    }
    // Binary mode
    // uložit pole do binarniho souboru a načist z binarniho souboru do pole

    int items[] = {1, 2, 3, 4, 5};
    std::ofstream fs2("out.bin", std::ios::binary);
    fs2.write(reinterpret_cast<const char *>(items), sizeof(int) * 5);
    fs2.close();

    int items2[5]{};
    std::ifstream fs3("out.bin", std::ios::binary);
    fs3.read(reinterpret_cast<char *>(items2), sizeof(int) * 5);
    fs3.close();

    for (auto item : items2) {
        cout << item << endl;
    }

    // uložit vectoru do binarniho souboru a načist z binarniho souboru do vectoru
    std::vector<int> items_v{6, 7, 8, 9, 10, 11, 1, 22, 33};
    std::ofstream fs2_v("out.bin", std::ios::binary);
    fs2_v.write(reinterpret_cast<const char *>(items_v.data()), sizeof(int) * items_v.size());
    fs2_v.close();

    std::vector<int> items2_v(items_v.size());
    std::ifstream fs3_v("out.bin", std::ios::binary);
    fs3_v.read(reinterpret_cast<char *>(items2_v.data()), sizeof(int) * items2_v.size());
    fs3_v.close();
    cout << "item vec" << endl;
    for (auto item : items2_v) {
        cout << item << endl;
    }

    return 0;
}
