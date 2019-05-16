#include <iostream>
#include "LRUCache.h"
int main()
{
	CLRUCache LRUCache(5);
	LRUCache.put("000", "�û�0��Ϣ");
	LRUCache.put("001", "�û�1��Ϣ");
	LRUCache.put("002", "�û�2��Ϣ");
	LRUCache.put("003", "�û�3��Ϣ");
	LRUCache.put("004", "�û�4��Ϣ");

	LRUCache.getValue("002");
	LRUCache.put("003", "�µ��û�3��Ϣ");
	LRUCache.put("005", "�û�5��Ϣ");

	//std::cout << LRUCache.getValue("000") << std::endl;
	std::cout << LRUCache.getValue("005") << std::endl;


	return 0;
}