#include <iostream>
#include <fstream>
#include <iterator>

/*istream_iterator需要#include <iterator>
 * istream_iterator只把1.txt中的字符读出来，但丢弃了其中的空格和回车，格式会有改动。
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