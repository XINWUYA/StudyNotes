/*
 * binary_function:可以作为一个二元函数对象的基类，它只定义了参数和返回值的类型，本身并不重载()操作符，这个任务交由派生类去完成
 * template <class Arg1, class Arg2, class Result>
 * struct binary_function {
 *		typedef Arg1 first_argument_type;
 *		typedef Arg2 second_argument_type;
 *		typedef Result result_type;
 * };
*/

#include <iostream>
#include <functional>

struct SCompare : public std::binary_function<int, int, bool>
{
	bool operator()(int a, int b) { return a == b; }
};

int main()
{
	SCompare Compare;
	SCompare::first_argument_type inputA;
	SCompare::second_argument_type inputB;
	SCompare::result_type result;

	std::cout << "Please enter two number: ";
	std::cin >> inputA >> inputB;
	result = Compare(inputA, inputB);
	std::cout << "Numbers " << inputA << " and " << inputB;
	if (result)
		std::cout << " are equal.\n";
	else
		std::cout << " are not equal.\n";

	return 0;
}