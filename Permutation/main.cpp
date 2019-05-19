#include <iostream>
#include <algorithm>
#include <vector>

/*prev_permutation
 *  ���Ӵ�С�������������ȫ����
 */

 /*next_permutation
  *  ����С����������������ȫ����
  */

#define USE_INCREMENT

int main()
{
	std::vector<int> DataArray = { 1,3,4,4,5 };
	std::sort(DataArray.begin(), DataArray.end());

#ifndef USE_INCREMENT
	std::reverse(DataArray.begin(), DataArray.end());
#endif

	do {
		for (auto i : DataArray)
			std::cout << i << " ";
		std::cout << std::endl;
	}
#ifdef USE_INCREMENT
	while (std::next_permutation(DataArray.begin(), DataArray.end()));
#else
	while (std::prev_permutation(DataArray.begin(), DataArray.end()));
#endif

	std::cout << "After Loop, the next one: " << std::endl;
	for (auto i : DataArray)
		std::cout << i << " ";
	std::cout << std::endl;

	return 0;
}