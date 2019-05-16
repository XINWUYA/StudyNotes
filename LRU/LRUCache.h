#pragma once
#include <string>
#include <unordered_map>
#include <memory>

struct SNode
{
	std::string Key;
	std::string Value;
	std::shared_ptr<SNode> pPre = nullptr;
	std::shared_ptr<SNode> pNext = nullptr;

	SNode() { }
	SNode(const std::string vKey, const std::string vValue) : Key(vKey), Value(vValue)
	{ }

	bool operator==(const SNode& vRight) const 
	{
		return (Key == vRight.Key) && (Value == vRight.Key) && (pPre == vRight.pPre) && (pNext == vRight.pNext);
	}
};

class CLRUCache
{
public:
	CLRUCache() = default;
	CLRUCache(int vCacheCap);
	~CLRUCache() = default;

	std::string getValue(const std::string& vKey);
	void put(const std::string& vKey, const std::string& vValue);
	void remove(const std::string& vKey);

private:
	void __addNode(const std::shared_ptr<SNode>& vioNode);
	void __refreshNode(const std::shared_ptr<SNode>& vioNode);
	std::string __removeNode(const std::shared_ptr<SNode>& vNode);

	std::shared_ptr<SNode> m_pHead = nullptr;
	std::shared_ptr<SNode> m_pEnd = nullptr;
	int m_CacheCap = 5;//Cache…œœﬁ
	std::unordered_map<std::string, std::shared_ptr<SNode>> m_HashMap;
};

