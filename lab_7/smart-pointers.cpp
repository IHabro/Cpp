#include <iostream>
#include <memory>
#include <utility>

using std::cout;
using std::endl;
using std::unique_ptr;
using std::shared_ptr;
using std::weak_ptr;
using std::move;
using std::make_shared;


class Foo
{
  public:
    explicit Foo(int x) : x(x)
    {

    }

    ~Foo()
    {
      cout << "Foo Destructor" << endl;
    }

    int get_x() const
    { 
      return this->x; 
    }

  private:
    int x;
};

class Node
{
public:
  int value;
  weak_ptr<Node> next;

  Node(int v) : value(v)
  {

  }

  Node(const Node &node) = delete;
  Node operator=(const Node &node) = delete;

  ~Node()
  {
    cout << "Node Destructor" << endl;
  }
};


void uniqueFunction1(unique_ptr<Foo> input)
{
  cout << "unique function 1" << endl;
}

void uniqueFunction2(unique_ptr<Foo> &input)
{
  cout << "unique function 2" << endl;
}

void sharedFunction1(shared_ptr<Foo> input)
{
  cout << "shared function 1: " << input.use_count() << endl;
}

void sharedFunction2(shared_ptr<Foo> input)
{
  cout << "shared function 2: " << input.use_count() << endl;
}

int main()
{
    system("clear");
    // vlastnosti/rozdíly

    // std::unique_ptr
    // jednina kopie objektu

    // std::shared_ptr
    // odkazuje se na nejakou hodnotu, pocita svoje reference

    // std::weak_ptr
    // pouziva se spolecne se shared_ptr, musi byt convertovan na shared_ptr


    // vytvorit unique_ptr Foo
    unique_ptr<Foo> uFoo(new Foo(5));

    // vytvorit shared_ptr Foo
    shared_ptr<Foo> sFoo(new Foo(10));

    // nejlepší způsob jak vytvořit shared_ptr a unique_ptr

    // poslat unique_ptr Foo do funkce
    uniqueFunction1(move(uFoo));
    uniqueFunction2(uFoo);

    // pokud pošlu unique_ptr do funkce, mužu po konci funkce volat metody na unique_ptr?
    cout << "uFoo.get: " << uFoo.get() << endl;

    // poslat shared_ptr Foo do funkce
    cout << "use before: " << sFoo.use_count() << endl;

    sharedFunction1(move(sFoo));
    sharedFunction2(sFoo);

    cout << "use after: " << sFoo.use_count() << endl;

    // jak se mění count shared_ptr když se pošle do funkce
    // jak se mění count při přiřazení std::shared_ptr do jineho std::shared_ptr
    // kdy se zavolá destruktor?


    // jak dostat raw pointer z shared ptr
    uFoo = unique_ptr<Foo>(new Foo(5));
    sFoo = shared_ptr<Foo>(new Foo(10));

    Foo *rFoo = sFoo.get();

    cout << "rFoo: " << rFoo->get_x() << endl;

    // jak udělat aby se unique_ptr přestal starat o objekt který v sobě má
    // uFoo.release();

    // jak udělat aby se shared_ptr přestal starat o objekt který v sobě má
    // ???

    // jak volat metody/přistupovat k properties na smart pointerech?
    cout << "uFoo: " << uFoo.get()->get_x() << endl;

    // udělat třídu Node, která bude v sobě mít uloženou hodnotu int a nějaký smart ptr na další node (linked list)
    Node n = Node(5);
    cout << n.value << endl;

    // udělat cyklus node1 bude ukazovat na node2 a node2 bude ukazovat na node1
    shared_ptr<Node> node1 = make_shared<Node>(5);
    shared_ptr<Node> node2 = make_shared<Node>(10);
    shared_ptr<Node> node3 = make_shared<Node>(15);

    node1->next = node2;
    node2->next = node3;
    node3->next = node1;

    // zavolá se v tomto případě někdy destruktor?

    // jak vyřešit jestli se nevolá?



    // jak přistupovat k weak_ptr?
    // weak_ptr<Foo> wFoo(new Foo(5));

    // udělat pole intů pomocí shared_ptr
    shared_ptr<int[]> sArray(new int[10]);

    // udělat pole intů pomocí unique_ptr
    unique_ptr<int[]> uArray(new int[10]);

    return 0;
}
