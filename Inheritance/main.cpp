#include <iostream>

class A
{
public:
	A() { std::cout << "A constructor." << std::endl; }
	virtual ~A() { std::cout << "A destructor." << std::endl; doSomething(); }

	virtual void doSomething() { std::cout << "A doSomething." << std::endl; }
};

class B : public A
{
public:
	B() { std::cout << "B constructor." << std::endl; }
	virtual ~B() { std::cout << "B destructor." << std::endl; doSomething(); }

	virtual void doSomething() { std::cout << "B doSomething." << std::endl; }
};

class C : public B
{
public:
	C() { std::cout << "C constructor." << std::endl; }
	~C() { std::cout << "C destructor." << std::endl; doSomething(); }

	void doSomething() { std::cout << "C doSomething." << std::endl; }
};

int main()
{
	C* pTest = new C();
	delete pTest;

	return 0;
}