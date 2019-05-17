
/*
 * unary: /ˈyo͞onərē/一元
 * unary_function:可以作为一个一元函数对象的基类，它只定义了参数和返回值的类型，本身并不重载()操作符，这个任务交由派生类去完成
 * template <class Arg, class Result>
 * struct unary_function {
 *		typedef Arg argument_type;
 *		typedef Result result_type;
 * };
*/

#include <iostream>
#include <functional>

struct SIsOdd : public std::unary_function<int, bool>
{
	bool operator()(int vNumber) { return vNumber % 2 != 0; }
};

int main()
{
	SIsOdd IsOdd;
	SIsOdd::argument_type input;
	SIsOdd::result_type result;

	std::cout << "Please enter a number: ";
	std::cin >> input;
	result = IsOdd(input);
	std::cout << "Number " << input << " is " << (result ? "odd" : "even") << ".\n";

	return 0;
}