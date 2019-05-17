/*
 * binary_function:������Ϊһ����Ԫ��������Ļ��࣬��ֻ�����˲����ͷ���ֵ�����ͣ�����������()�����������������������ȥ���
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