#include <iostream>
using namespace std;

class Base {
public:
    virtual void func() { cout << "Base::func" << endl; }
    Base() {
        func();  // 构造函数内部调用虚函数
    }
};

class Derived : public Base {
public:
    virtual void func() override { cout << "Derived::func" << endl; }
};

int main() {
    Derived d;   // 创建子类对象
    Base* p = &d;
    p->func();   // 基类指针指向子类，调用虚函数
    return 0;
}