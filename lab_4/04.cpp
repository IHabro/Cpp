#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Animal
{
public:
  Animal() {};
  virtual void Sound() {cout << "Jsem zvire..." << endl;};
};

class Dog : public Animal
{
public:
  Dog() {};
  void Sound() {cout << "Bark! Bark!" << endl;};

};

class Cat : public Animal
{
public:
  Cat() {};
  void Sound() {cout << "Meow! Meow!" << endl;};

};

class Snake : public Animal
{
public:
  Snake() {};
  void Sound() {cout << "Sssssssssssssssss..." << endl;};
};

//new namespace
//using Animal = std::variant<Dog, Cat>;

int main() 
{
  Animal *a = new Animal();
  Dog *b = new Dog();
  Cat *c = new Cat();
  Snake *d = new Snake();

  vector<Animal*> animals;
  animals.push_back(a);
  animals.push_back(b);
  animals.push_back(c);
  animals.push_back(d);

  cout << "Animal noises: " << endl;
  a->Sound();
  b->Sound();
  c->Sound();
  d->Sound();

  cout << endl;

  cout << "Homunculus animal noises: " << endl;
  a = b;
  a->Sound();

  a = c;
  a->Sound();

  a = d;
  a->Sound();

  cout << endl;

  cout << "Vector animal noises:" << endl;

  for(unsigned int i = 0;i < animals.size();i++)
  {
    animals[i]->Sound();
  }

  cout << endl;

  return 0;
}