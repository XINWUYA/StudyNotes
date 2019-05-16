#include <iostream>
#include "LRUCache.h"
int main()
{
	CLRUCache LRUCache(5);
	LRUCache.put("000", "用户0信息");
	LRUCache.put("001", "用户1信息");
	LRUCache.put("002", "用户2信息");
	LRUCache.put("003", "用户3信息");
	LRUCache.put("004", "用户4信息");

	LRUCache.getValue("002");
	LRUCache.put("003", "新的用户3信息");
	LRUCache.put("005", "用户5信息");

	//std::cout << LRUCache.getValue("000") << std::endl;
	std::cout << LRUCache.getValue("005") << std::endl;


	return 0;
}