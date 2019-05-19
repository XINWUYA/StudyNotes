#include <iostream>
#include <fstream>

/*istreambuf_iterator����#include <iterator>
* istreambuf_iterator��1.txt�е����ݶ�����������Ľ��ԭ�ֲ����ر�����1.txt�ĸ�ʽ��
*/

int main()
{
	std::ifstream ReadFile("1.txt");
	std::istreambuf_iterator<char> in(ReadFile), end;
	std::ostreambuf_iterator<char> out(std::cout);

	while (in != end)
	{
		*out++ = *in++;
	}
	std::cout << std::endl;
	return 0;
}