#include <iostream>
#include <algorithm>
#include <vector>

/*prev_permutation
 *  按从大到小对数列数组进行全排序
 */

 /*next_permutation
  *  按从小到大对数列数组进行全排序
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