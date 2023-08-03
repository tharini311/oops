#include <iostream>
using namespace std;
#define size 5
class stack
{
    int stck[size];
    int tos;

public:
    void init();
    void push();
    int pop();
    void display();
};
void stack::init()
{
    tos = 0;
}
void stack::push()
{
    int i;
    if (tos == size)
    {
        cout << "stack overflowl \n";
        return;
    }
    cout << "enter element \n";
    cin >> i;
    stck[tos] = i;
    tos++;
}
int stack::pop()
{
    if (tos == 0)
    {
        cout << "stack underflow \n";
        return 1;
    }
    tos--;
    cout << "popped element is" << stck[tos];
    return 0;
}
void stack::display()
{
    if (tos == 0)
    {
        cout << "stack empty \n";
        return;
    }
    for (int i = 0; i < tos; i++)
    {
        cout << stck[i] << "\n";
    }
}
int main()
{
    int ch, i;
    stack s;
    s.init();
    while (1)
    {
        cout << "1.push 2.pop 3.display \n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            s.push();
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.display();
            break;
        default:
            return 0;
        }
    }
}
