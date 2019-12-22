#include <iostream>
using namespace std;
class A {
protected:
    int val; public:
    A(int v = 0) : val(v) {};     virtual void out() {
    cout << "Base: " << val << endl;
}
};

class B : public A
{
public:
    void out() {
    cout << "Derived: " << val << endl;
}
};

int main()
{
    A a(1);
    B b;
    a.out();
    b.out();
    A* aptr = &b;
    aptr->out();
    return 0;
}
