#include <iostream>
#include <fstream>

/*istreambuf_iterator不用#include <iterator>
* istreambuf_iterator把1.txt中的内容读出来，输出的结果原分不动地保留了1.txt的格式。
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