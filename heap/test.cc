#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	std::vector<int> vec{ 10,20,30,5,15 };

	std::make_heap(vec.begin(), vec.end());

	for (auto it : vec)
	{
		std::cout << it << "  ";  // 输出 30 20 10 5 15
	}
	std::cout << std::endl;

	return 0;
}
