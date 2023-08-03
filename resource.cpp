#include <iostream>
using namespace std;
class SharedResource
{
private:
    static int resource;

public:
    void accessResource()
    {
        if (resource > 0)
        {
            cout << "Access granted to the shared resource." << endl;
            resource--;
        }
        else
        {
            cout << "Access denied. Shared resource is currently unavailable." << endl;
        }
    }
    static void setResourceCount(int count)
    {
        resource = count;
    }
};
int SharedResource::resource = 0;
int main()
{
    SharedResource obj1;
    SharedResource obj2;
    SharedResource::setResourceCount(5);
    obj1.accessResource();
    obj2.accessResource();
    obj1.accessResource();
    obj2.accessResource();
    obj1.accessResource();
    obj2.accessResource();
    obj1.accessResource();
    obj2.accessResource();
    return 0;
}
