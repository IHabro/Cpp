#include <iostream>
#include <vector>
#include <string>
#include <string_view>

using namespace std;


/**
 * An iterator has to support at least these operations:
 * 1) Dereference (`*it`) - gets the current value of the iterator.
 * 2) Move to the next element (`++it`) - moves the iterator to the next element.
 * 3) Inequality comparison (`it1 != it2`) - checks if the iterator is at the end.
 *
 * To use the iterator protocol, you have to create an object with `begin` and `end` methods, which
 * should return the iterator pointing to the first item and an iterator representing the end.
 *
 * For-each loops are translated like this:
 *
 * for (auto item: container)
 * {
 *     item.method();
 * }
 *
 * auto it = container.begin();
 * for (; it != container.end(); ++it)
 * {
 *    (*it).method();
 * }
 */

struct WordSplitIterator
{
public:
    explicit WordSplitIterator(std::string_view text): text(text)
    {

    }

private:
    std::string_view text;
};

struct MujString
{
    explicit MujString(std::string str): str(std::move(str))
    {
        
    }

    WordSplitIterator begin() const;
    WordSplitIterator end() const;
    
    std::string str;
};

int main()
{
    MujString iterable{"ahoj     karle jak se mas?"};

    for (auto word : iterable)
    {
        cout << word << endl;
    }

    cout << "konec" << endl;
    return 0;
}
