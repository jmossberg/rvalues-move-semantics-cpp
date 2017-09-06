# Rvalues and move semantics

You need a C++11 compiler in order to perform these exercises.

## How to build and run

If you save your code in `a.cpp` and use g++

    g++ --std=c++14 a.cpp -o a && ./a

## Exercise 1

Add the following to a new class A:

* A private member `_number` which is a pointer to an int
* A public constructor that:
  * Accepts an int as input argument
  * Allocates an int on the heap and sets its value  according to the input argument
  * Points `_number` to the newly allocated int
  * Prints to standard out what int value it has been initialized with
* A destructor that:
  * Prints what value `_number` points to before it frees the associated memory
  * Prints `nullptr` if `_number` does not point to an int

class A shall generate the following output:

    class A constructor: 3
    class A destructor: 3

Given this code:

    A a1{3}

## Exercise 2

Add a copy constructor to class A so that it can handle the following code. Print out a line to indicate that the copy constructor has been used.

    A a1{3};
    A a2{a1};
    A a3{A{4}};

The output shall be:

    class A constructor: 3
    class A copy constructor: 3
    class A constructor: 4
    class A destructor: 4
    class A destructor: 3
    class A destructor: 3

Please note that the copy constructor was not used when creating `a3` because of compiler optimization.

## Exercise 3

Add a move constructor to class A. Print out a line to indicate that the move constructor has been used. The following code:

    vector<A> v;
    v.push_back(A{5});

Should generate this output;

    class A constructor: 5
    class A move constructor: 5
    class A destructor: nullptr
    class A destructor: 5

## Exercise 4

Add a copy assignment operator to class A. Print out a line to indicate that the copy assignment operator has been used.

The following code:

    A a5{7};
    A a6{8};
    a6 = a5;

Shall generate this output:

    class A constructor: 7
    class A constructor: 8
    class A copy assignment operator: 7
    class A destructor: 7
    class A destructor: 7

## Exercise 5

Add a move assignment operator to class A. Print out a line to indicate that the move assignment operator has been used.

The following code:

    A a7{9};
    a7 = A{10};

Shall generate this output:

    class A constructor: 9
    class A constructor: 10
    class A move assignment operator: 10
    class A destructor: nullptr
    class A destructor: 10

## Exercise 6

Use the `move` function to force move semantics to be used when creating a new instance of class A.

The following code:

    A a8{11};
    A a9{move(a8)};

Shall generate this output:

    class A constructor: 11
    class A move constructor: 11
    class A destructor: 11
    class A destructor: nullptr
