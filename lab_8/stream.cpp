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
using std::system;
using std::ios;

struct Point 
{
    int x;
    int y;
};

std::ostream& operator<<(std::ostream& os, const Point& point)
{
    os << "[" << point.x << ", " << point.y << "]";

    return os;
}

std::istream& operator>>(std::istream& is, Point& point)
{
    is >> point.x >> point.y;

    return is;
}


int main() 
{
    system("clear");
    std::random_device rd;
    std::mt19937 generator{rd()};

    cout << generator() << endl;

    std::uniform_real_distribution<double> distribution_utery(0, 20);
    std::vector<std::vector<double>> cisla{};

    for (int i = 0; i < 10; ++i) 
    {
        std::vector<double> row{};

        for (int j = 0; j < 10; ++j) 
        {
            row.push_back(distribution_utery(generator));
        }

        cisla.push_back(row);
    }

    for (int i = 0; i < 10; ++i) 
    {
        for (int j = 0; j < 10; ++j) 
        {
            cout << cisla[i][j] << " ";
        }

        cout << endl;
    }

    // naformatovat takto
    //            1       2       3       4       5       6       7       8       9      10       
    //    1 [    0.94   11.28   14.94    8.12    3.49    6.38    7.10   14.14   12.79   19.07  ] 1
    //    2 [    1.43   10.38   12.79    4.13    7.51    2.28    0.35    1.39   10.08   19.26  ] 2
    //    3 [    5.75    0.02   19.18   16.81   16.90   13.39    6.60   16.15    6.30    4.70  ] 3
    //    4 [   15.84    3.00   12.56   19.89    7.67   18.56   11.07    2.79   10.46   18.35  ] 4
    //    5 [   13.64    6.26    1.98    3.67   16.78   14.97   18.37    1.83    4.60    5.99  ] 5
    //    6 [   11.24    1.27    7.76    4.27   11.10   13.76    9.40   10.01   14.88   12.44  ] 6
    //    7 [   13.82    0.88    8.49   16.59   11.34   15.39    2.30   10.87    4.38    7.54  ] 7
    //    8 [   14.83   15.07   12.11    6.41   12.76    4.37    5.83    8.76   17.33    2.15  ] 8
    //    9 [    9.47    4.92   10.82    8.27   17.68    6.54   13.36   19.74    0.22    5.67  ] 9
    //   10 [    5.98    4.57    6.06   18.66    8.69    8.62    3.88   15.73   18.72   18.30  ] 10
    //            1       2       3       4       5       6       7       8       9      10

    cout << "\n         1       2       3       4       5       6       7       8       9      10       " << endl;

    for(unsigned int r = 0;r < cisla.size();r++)
    {
        cout << std::setw(2) << r+1 << " [";
        
        cout << std::fixed;
        cout << std::setprecision(2);

        for(unsigned int s = 0; s < cisla[r].size();s++)
        {
            cout << std::setw(8) << cisla[r][s];
        }

        cout << "  ] " << r+1 << endl;
    }

    cout << "         1       2       3       4       5       6       7       8       9      10       " << endl;

    // přetížit operator<< a operator>> pro point, aby šel přímo použít v cin a cout

    Point p{1, 2};
    cout << p << "\n";

    // Point point2{};
    // cin >> point2;
    // cout << point2 << "\n";

    // streams can be combined with iterators
    std::vector<int> v1{1, 2, 3, 4, 5};
    // pomoci std::copy_if std::ostream_iterator vypsat do console odděleno čárkami jenom sude

    std::copy_if(v1.begin(), v1.end(), std::ostream_iterator<int>(std::cout, " "),[](int x) { return x % 2 == 0; });

    cout << "\n";
    
    std::vector<int> vec_to_text{6, 7, 8, 9, 10, 11, 1, 22, 33};
    std::ofstream fsout_vec("out_vec.txt");

    std::copy_if(vec_to_text.begin(), vec_to_text.end(), std::ostream_iterator<int>(fsout_vec, " "),[](int x) { return x % 2 == 0; });

    fsout_vec.close();

    std::vector<int> text_to_vec;
    int tmp;

    std::ifstream fsin_vec;
    fsin_vec.open("out_vec.txt");

    while (true)
    {
        fsin_vec >> tmp;

        if (fsin_vec.eof())
        {
            break;
        }

        text_to_vec.push_back(tmp);
    }

    fsin_vec.close();

    for(const auto i : text_to_vec)
    {
        cout << i << " ";
    }

    cout << "\n";


    // Binary mode
    // uložit pole do binarniho souboru a načist z binarniho souboru do pole
    int items[] = {1, 2, 3, 4, 5};

    std::ofstream binItems;
    binItems.open("bin_array.bin", ios::binary | ios::out);

    binItems.write(reinterpret_cast<const char*>(items), sizeof(items));

    binItems.close();


    int items2[5];

    std::ifstream itemsBin;
    itemsBin.open("bin_array.bin", ios::binary | ios::in);

    itemsBin.read(reinterpret_cast<char*>(items2), sizeof(items2));

    itemsBin.close();

    for(const auto i : items2)
    {
        cout << i << " ";
    }

    cout << "\n";

    // uložit vectoru do binarniho souboru a načist z binarniho souboru do vectoru
    std::vector<int> items_v{6, 7, 8, 9, 10, 11, 1, 22, 33};

    std::fstream binVector;

    binVector.open("bin_vector.bin", ios::binary | ios::out);

    binVector.write(reinterpret_cast<const char*>(items_v.data()), sizeof(int) * items_v.size());

    binVector.close();

    std::vector<int> items_v2(items_v.size());

    binVector.open("bin_vector.bin", ios::binary | ios::in);

    binVector.read(reinterpret_cast<char*>(items_v2.data()), sizeof(int) * items_v2.size());

    binVector.close();


    for(const auto i : items_v2)
    {
        cout << i << " ";
    }

    cout << "\n";



    return 0;
}
