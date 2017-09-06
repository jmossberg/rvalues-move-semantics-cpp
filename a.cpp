#include <iostream>
#include <vector>

using namespace std;

class A {
public:
    A(const int& number);
    ~A();
    A(const A& other);
    A(A&& other);
    A& operator=(const A& other);
    A& operator=(A&& other);

private:
    int* _number;
};

A& A::operator=(A&& other)
{
    delete _number;
    _number = other._number; 
    other._number = nullptr;
    cout << "  class A move assignment operator: " << *_number << endl; 
    return *this;
}

A& A::operator=(const A& other)
{
    *_number = *other._number;
    cout << "  class A copy assignment operator: " << *_number << endl; 
    return *this;
}

A::A(A&& other)
{
    _number = other._number;
    other._number = nullptr;
    cout << "  class A move constructor: " << *_number << endl; 
}

A::A(const A& other) : _number{new int{*other._number}}
{
    cout << "  class A copy constructor: " << *_number << endl; 
}

A::A(const int& number) : _number{new int{number}}
{
    cout << "  class A constructor: " << *_number << endl; 
}

A::~A()
{
    cout << "  class A destructor: "; 
    if (nullptr != _number) {
        cout << *_number;
        delete _number;
    } else {
        cout << "nullptr";
    }
    cout << endl;
}

int main(int argc, char* argv[])
{
    {
        cout << endl << "Exercise 1" << endl;
        A a1(3);
    }

    {
        cout << endl << "Exercise 2" << endl;
        A a1(3);
        A a2{a1};
        A a3{A{4}};
    }
    
    {
        cout << endl << "Exercise 3" << endl;
        vector<A> v;
        v.push_back(A{5});
    }
    
    {
        cout << endl << "Exercise 4" << endl;
        A a5{7};
        A a6{8};
        a6 = a5;
    }
    
    {
        cout << endl << "Exercise 5" << endl;
        A a7{9};
        a7 = A{10};
    }

    {
        cout << endl << "Exercise 6" << endl;
        A a8{11};
        A a9{move(a8)};
    }

    return 0;
}
