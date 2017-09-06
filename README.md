#Rvalues and move semantics

## Exercise 1

Create a class A with:

* A pointer to an int as a private member
* A constructor that accepts a reference to an int and allocates an int on the heap
* A destructor that frees the memory associated with the int on the heap
* A public method get_number() that return the value of the private int member

class A should be able to handle the following code:

A a1{3}
cout << "a1: " << a1.get_number() << endl;

The output shall be:

a1: 3

## Exercise 2

Overload the << insertion operator for class A. So that you can do:

cout << "a1: " << a1 << endl;

And get:

a1: 3

Google "c++ overload insertation << operator" to learn how.
 
## Exercise 3

Add a copy constructor to class A so that it can handle the following code:

A a1{3};
A a2{a1};
A a3{A{4}};
cout << "a1: " << a1 << ", a2: " << a2 << ", a3: " << a3 << endl;

The output shall be:

a1: 3, a2: 3, a3: 4

## Exercise 4

Add a move constructor to class A. Print out a line to indicate that the move constructor has been used. The following code:

    vector<A> v;
    v.push_back(A(5));

Should generate this output;

    initializing _number to 5 in class A constructor
    initializing _number to 5 in class A move constructor

## Exercise 5

Add a copy assignment operator to class A. Print out a line to indicate that the copy assignment operator has been used.

The following code:

    A a5(7);
    A a6(8);
    a6 = a5;

Shall generate this output:

    initializing _number to 7 in class A constructor
    initializing _number to 8 in class A constructor
    setting _number to 7 in class A copy assignment operator

## Exercise 6

Add a move assignment operator to class A. Print out a line to indicate that the move assignment oeprator has been used.

The following code:

    A a7{9};
    a7 = A{10};

Shall generate this output:

    initializing _number to 9 in class A constructor
    initializing _number to 10 in class A constructor
    setting _number to 10 in class A move assignment operator

## Exercise 7

Use the move function to force move semantics to be used when creating a new instance of class A.

The following code:

    A a8{11};
    A a9{move(a8)};

Shall generate this output:

  initializing _number to 11 in class A constructor
  initializing _number to 11 in class A move constructor
  running class A destructor for instance with _number set to 11
  running class A destructor for instance with _number set to nullptr
