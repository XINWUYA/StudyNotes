#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	std::vector<int> DataArray = { 1,3,4,4,5 };
	std::sort(DataArray.begin(), DataArray.end());
	do {
		for (auto i : DataArray)
			std::cout << i << " ";
		std::cout << std::endl;
	} while (std::next_permutation(DataArray.begin(), DataArray.end()));

	std::cout << "After Loop, the next one: " << std::endl;
	for (auto i : DataArray)
		std::cout << i << " ";
	std::cout << std::endl;

	return 0;
}