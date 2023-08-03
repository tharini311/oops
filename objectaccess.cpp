#include <iostream>
using namespace std;
class ObjectCounter
{
private:
    static int count;

public:
    ObjectCounter()
    {
        count++;
    }
    ~ObjectCounter()
    {
        count--;
    }
    static int getCount()
    {
        return count;
    }
};
int ObjectCounter::count = 0;
int main()
{
    ObjectCounter obj1;
    ObjectCounter obj2;
    cout << "Number of objects: " << ObjectCounter::getCount() << endl;
    ObjectCounter obj3;
    ObjectCounter obj4;
    cout << "Number of objects: " << ObjectCounter::getCount() << endl;
    return 0;
}
