#include <iostream>
#include <fstream>
#include <iterator>

/*istream_iterator��Ҫ#include <iterator>
 * istream_iteratorֻ��1.txt�е��ַ��������������������еĿո�ͻس�����ʽ���иĶ���
 */

int main()
{
	std::ifstream ReadFile("1.txt");
	std::istream_iterator<char> in(ReadFile), end;
	std::ostream_iterator<char> out(std::cout);

	while (in != end)
	{
		*out++ = *in++;
	}
	std::cout << std::endl;
	return 0;
}