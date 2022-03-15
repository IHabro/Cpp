#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <random>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

struct Foo
{
    Foo(int x, int y) : x(x), y(y) { cout << "create" << endl; }
    Foo(const Foo &other) : x(other.x), y(other.y) { cout << "copy" << endl; }
    Foo(Foo &&other) noexcept : x(other.x), y(other.y) { cout << "move" << endl; }

    int x;
    int y;
};

int main()
{
    // vector
    vector<Foo> v;
    vector<int> vi;
    // rozdil mezi v.size() a v.capacity(), jak se mění po pushi  

    
    /*
    cout << v.size() << ", " << v.capacity() << endl;
    Foo tmp = Foo(5, 10);
    v.push_back(tmp);
    cout << v.size() << ", " << v.capacity() << endl;
    v.push_back(tmp);
    cout << v.size() << ", " << v.capacity() << endl;  
    v.push_back(tmp);
    cout << v.size() << ", " << v.capacity() << endl;  
    v.push_back(tmp);
    cout << v.size() << ", " << v.capacity() << endl;  
    v.push_back(tmp);
    cout << v.size() << ", " << v.capacity() << endl;
    */
    

    //Capacity roste exponencialne a size roste linearne
    //push_back -> pokud je size == capacity pak capacity*2, size++, a vlozi prvek k datum

    // rozdil mezi push_back a emplace_back

    //push_back     -> kopiruje data do nove promenne na konci containeru vector
    //emplace_back  -> tvori kopii pomoci std::allocator_traits::construct

    // rozdil mezi resize a reserve

    //resize    -> zvetsi nebo zmensi obsah containeru na dane mnozstvi (pridava defaultni hodnoty, nebo zadane hodnoty)
    //reserve   -> zvysuje kapacireserve


    // sum
    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int sum = std::accumulate(v1.begin(), v1.end(), 0);
    cout << "sum: " << sum << endl;

    // product
    vector<int> v2 = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2};

    double mul = std::accumulate(v2.begin(), v2.end(), 1, std::multiplies<double>());
    cout << "product: " << mul << endl;

    // sum na poli
    int *p1 = new int[10];
    for (int i = 0; i < 10; i++)
    {
        p1[i] = i + 1;
    }

    int sum_p = std::accumulate(p1, p1+10, 0);
    cout << "array sum: " << sum_p << endl;


    // product na poli
    int *p2 = new int[10];
    for (int i = 0; i < 10; i++)
    {
        p2[i] = 2;
    }

    double mul_p = std::accumulate(p2, p2+10, 1, std::multiplies<double>());
    cout << "array mul: " << mul_p << endl;


    // najit největší prvek a jeho index
    vector<int> v3 = {1, 55, 6, 8, 99, 6, 32, 15, 25, 6, 1, 2, 5, 9};

    std::vector<int>::iterator max_it = std::max_element(v3.begin(), v3.end());
    cout << "i: " << std::distance(v3.begin(), max_it) << ", value: " << v3[std::distance(v3.begin(), max_it)] << endl;

    // najít největší a nejmenší prvek pomocí jedné funkce

    const auto [min, max] = std::minmax_element(v3.begin(), v3.end());
    cout << "min = " << *min << ", max = " << *max << '\n';

    // je ve v3 něco sudeho?

    //is_any

    auto even = std::count_if(v3.begin(), v3.end(), [](int n) { return (n % 2) == 0; });
    cout << "evens: " << even << endl;

    // je všechno ve v3 nezáporné?

    if(std::all_of(v3.cbegin(), v3.cend(), [](int i){ return i >= 0; }))
    {
        cout << "Ano vse je nezaporne" << endl;
    }
    else
    {
        cout << "Vektro obsahuje zaporne cisla" << endl;
    }
    
    // najít item v v3 (co když tam je, co když tam není)

    int tmp = -1;

    auto result = std::find(begin(v3), end(v3), tmp);

    (result != std::end(v3))? std::cout << "v3 obsahuje " << tmp << endl : std::cout << "v3 neobsahuje " << tmp << endl;

    // najit prvni sude cislo

    auto firstEven = std::find_if(begin(v3), end(v3), [](int i){ return i%2 == 0; });
    (firstEven != std::end(v3))? std::cout << "v3 obsahuje sude cislo: " << *firstEven << endl : std::cout << "v3 neobsahuje sude cislo" << endl;

    // najit posledni sude cislo

    auto lastEven = std::find_if(rbegin(v3), rend(v3), [](int i){ return i%2 == 0; });
    (lastEven != std::rend(v3))? std::cout << "v3 obsahuje sude cislo: " << *lastEven << endl : std::cout << "v3 neobsahuje sude cislo" << endl;

    // seřadit od nejmenšího po největší
    vector<int> v4 = {1, 55, 6, 8, 99, 6, 32, 15, 25, 6, 1, 2, 5, 9};

    sort(v4.begin(), v4.end());

    for(const auto &el : v4)
    {
        cout << el << " ";
    }
    cout << endl;

    // seřadit od největšího po nejmenší
    vector<int> v5 = {1, 55, 6, 8, 99, 6, 32, 15, 25, 6, 1, 2, 5, 9};

    std::sort(v5.begin(), v5.end(), [](int a, int b){return a > b;});
    for(const auto &el : v5)
    {
        cout << el << " ";
    }
    cout << endl;

    // zjitit jestli je v4 a v5 seřazeno od nejmenšího po největší

    if(std::is_sorted(v4.begin(), v4.end()) && std::is_sorted(v5.begin(), v5.end()))
    {
        cout << "Oba vektory jsou serazene od nejmensiho po nejvetsi" << endl;
    }
    else
    {
        cout << "Alespon jeden vektor neni serazeny od nejmensiho po nejvetsi" << endl;
    }

    // zjitit jestli je v4 a v5 seřazeno od největšího po nejmenší

    std::sort(v4.begin(), v4.end(), [](int a, int b){return a > b;});
    if(std::is_sorted(v4.rbegin(), v4.rend()) && std::is_sorted(v5.rbegin(), v5.rend()))
    {
        cout << "Oba vektory jsou serazene od nejvetsiho po nejmensi" << endl;
    }
    else
    {
        cout << "Alespon jeden vektor neni serazeny od nejvetsiho po nejmensi" << endl;
    }


    // do v7 vyfiltrovat jenom sude
    vector<int> v6 = {1, 55, 6, 8, 99, 6, 32, 15, 25, 6, 1, 2, 5, 9};
    vector<int> v7 = {};

    std::remove_copy_if(v6.begin(), v6.end(), v7.begin(), [](int n){return n % 2 == 0;});
    
    for(const auto &el : v6)
    {
        cout << el << " ";
    }
    cout << endl;
    for(const auto &el : v7)
    {
        cout << el << " ";
    }
    cout << endl;
    

    // všechno vynásobit 2
    vector<int> v8 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // transform


    // všechno vynásobit 2 a vysledek uložit do v10, v9 zustane jak je
    vector<int> v9 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> v10 = {};



    // otočit
    vector<int> v11 = {1, 55, 6, 8, 99, 6, 32, 15, 25, 6, 1, 2, 5, 9};

    //reverse

    // psounout o 5 prvků {1, 55, 6, 8, 99, 6, 32, 15, 25, 6, 1, 2, 5, 9} -> {6, 32, 15, 25, 6, 1, 2, 5, 9, 1, 55, 6, 8, 99}
    vector<int> v12 = {1, 55, 6, 8, 99, 6, 32, 15, 25, 6, 1, 2, 5, 9};



    // zamíchat
    vector<int> v13 = {1, 1, 2, 5, 6, 6, 6, 8, 9, 15, 25, 32, 55, 99};



    // najit 8 přes binary search binary search
    vector<int> v14 = {1, 1, 2, 5, 6, 6, 6, 8, 9, 15, 15, 15, 15, 25, 32, 55, 99};
    // najít kde začínají 15 a kde končí 15, lower bound a upper boud



    // smazat dumplcitní prvky
    vector<int> v15 = {1, 1, 2, 5, 6, 6, 6, 8, 9, 15, 15, 15, 15, 25, 32, 55, 99};



    // roztřídit na sudé a liche, ve stejnem poli
    vector<int> v16 = {1, 1, 2, 5, 6, 6, 6, 8, 9, 15, 15, 15, 15, 25, 32, 55, 99};



    // vymazat sude
    vector<int> v17 = {1, 1, 2, 5, 6, 6, 6, 8, 9, 15, 15, 15, 15, 25, 32, 55, 99};



    // vypsat všechny permutace
    vector<int> v18{1, 2, 3, 4, 5};



    // sjednocení, průnik, rozdíl, vysledek uložit do nových kontejnerů
    { // with vector

        vector<int> v19{1, 2, 3, 4, 5};
        vector<int> v20{3, 4, 5, 6, 7};
    }



    { // with set
        cout << "set operations on set" << endl;
        std::set<int> s1{1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
        std::set<int> s2{3, 4, 5, 6, 7, 3, 4, 5, 6, 7, 3, 4, 5, 6, 7};
    }



    // set serazeny od nejmensiho po nejvetsi
    std::set<int> s3{1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5};



    // set serazeny od nejvetsioh po nejmensi
    std::set<int> s4{1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5};



    // seradit podle abecedy
    vector<std::string> v21{"lorem",     "ipsum",     "dolor",  "sit",       "amet",    "consectetur",  "adipiscing",
                                 "elit",      "sed",       "do",     "eiusmod",   "tempor",  "incididunt",   "ut",
                                 "labore",    "et",        "dolore", "magna",     "aliqua",  "ut",           "enim",
                                 "ad",        "minim",     "veniam", "quis",      "nostrud", "exercitation", "ullamco",
                                 "laboris",   "nisi",      "ut",     "aliquip",   "ex",      "ea",           "commodo",
                                 "consequat", "duis",      "autea",  "irure",     "dolor",   "in",           "reprehenderit",
                                 "in",        "voluptate", "aute",   "esse",      "cillum",  "dolore",       "eu",
                                 "fugiat",    "nulla",     "autez",  "excepteur", "sint",    "occaecat",     "cupidatat",
                                 "non",       "proident",  "sunt",   "culpa",     "qui",     "officia",      "deserunt",
                                 "mollit",    "anim",      "id",     "est",       "laborum"};
    
    

    // seradit podle delky
    vector<std::string> v22{"lorem",     "ipsum",     "dolor",    "sit",       "amet",    "consectetur",  "adipiscing",
                                 "elit",      "sed",       "do",       "eiusmod",   "tempor",  "incididunt",   "ut",
                                 "labore",    "et",        "dolore",   "magna",     "aliqua",  "ut",           "enim",
                                 "ad",        "minim",     "veniam",   "quis",      "nostrud", "exercitation", "ullamco",
                                 "laboris",   "nisi",      "ut",       "aliquip",   "ex",      "ea",           "commodo",
                                 "consequat", "duis",      "aute",     "irure",     "dolor",   "in",           "reprehenderit",
                                 "in",        "voluptate", "velit",    "esse",      "cillum",  "dolore",       "eu",
                                 "fugiat",    "nulla",     "pariatur", "excepteur", "sint",    "occaecat",     "cupidatat",
                                 "non",       "proident",  "sunt",     "culpa",     "qui",     "officia",      "deserunt",
                                 "mollit",    "anim",      "id",       "est",       "laborum"};
    


    
    // object Car(id, name) pouzit v set a unordered_set,  structuru Car vytvorte
    // std::set             {{123, "Skoda"}, {1001, "BMW"}, {5, "Audi"}, {5, "Audi"}};
    // std::unordered_set   {{123, "Skoda"}, {1001, "BMW"}, {5, "Audi"}, {5, "Audi"}};
    



    return 0;
}