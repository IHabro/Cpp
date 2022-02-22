#include <iostream>

class MojePole
{
  public:
    //static int MPC = 0; //MojePoleCount
    int *pole{nullptr};
    size_t velikost{0};

    //default
    MojePole();

    //size
    MojePole(size_t size)
    {
      velikost = static_cast<int>(size);
      pole = new int[velikost];

      for(size_t i = 0;i < velikost;i++)
      {
          pole[i] = i+1;
      }
    }

    //listostream& operator<<(ostream &output, MojePole &input)
    MojePole(std::initializer_list<int> input) : MojePole(static_cast<int>(input.size()))
    {
      int count{ 0 };

      for (auto element : input)
      {
        pole[count] = element;
        ++count;
      }
    };

    //Copy
    MojePole(const MojePole &input)
    {
      velikost = input.velikost;

      for(size_t i = 0;i < velikost;i++)
      {
        pole[i] = input.pole[i];
      }
    };

    //Move
    MojePole(MojePole &&input)
    {
      this->velikost = input.velikost;
      this->pole = input.pole;
      input.pole = nullptr;
    };

    //Destructor
    ~MojePole()
    {
      free(pole);
    };

    //Copy asignment operator
    MojePole& operator=(MojePole &other)
    {
      std::swap(velikost, other.velikost);
      std::swap(pole, other.pole);

      return *this;
    };

    //Move asignment operator
    MojePole& operator=(MojePole &&input) = delete;
    /*
    {
      velikost = input.velikost;
      this->pole = input.pole;
      input.pole = nullptr;

      return *this;
    };
    */
};

    std::ostream& operator<<(std::ostream &output, MojePole &input)
    {
        output << "[";

        for(size_t i = 0;i < input.velikost;i++)
        {
          output << input.pole[i] << ",";
        }

        output << "]";

        return output;
    }

// pro MojePole dodělat
// empty constructor
// contructor co dostane size, vytvoří pole a naplního ho čisly 1,2,3...n
// contructor co dostane přímo prvky a vytvoří uvnitř nové pole (std::initializer_list)
// destructorhoda co bude vracet počet všech vytvoé třídy (counter kolikrat se zavolal contructor)

// c++ style enum, bude používat 2 byte datatype

// z prvního domaciho ukolu vzít funkci
// bool parse_uint(const std::string &input, uint32_t &result)
// upravit aby vracela výsledek jako std::optional<uint32_t> místo uint32_t &result v prametru
// std::optional<uint32_t> parse_uint(const std::string &input)

// struct co bude mít 4 fieldy, .a .b .c .d ale sizeof(MojeStruktura) bude vypisovat 1 (velikost 1 byte)


int main() 
{
    // MojePole mojePole(5);
    // MojePole mojePole2({1,1,2,2}); // std::initializer_list example
    // std::cout << mojePole << std::endl; // [1,2,3,4,5]

    // std::cout << "MojeStruktura: " << sizeof(MojeStruktura) << std::endl; // MojeStruktura: 1

    return 0;
}