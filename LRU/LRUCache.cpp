#include "LRUCache.h"



CLRUCache::CLRUCache(int vCacheCap) : m_CacheCap(vCacheCap)
{
	m_HashMap.reserve(vCacheCap);
}

//***********************************************************************
//FUNCTION:
std::string CLRUCache::getValue(const std::string& vKey)
{
	auto pNodeIter = m_HashMap.find(vKey);
	if (pNodeIter != m_HashMap.end())
	{
		__refreshNode(pNodeIter->second);
		return (pNodeIter->second)->Value;
	}

	return nullptr;	
}

//***********************************************************************
//FUNCTION:
void CLRUCache::put(const std::string& vKey, const std::string& vValue)
{
	auto pNodeIter = m_HashMap.find(vKey);
	if (pNodeIter != m_HashMap.end())
	{
		(pNodeIter->second)->Value = vValue;
		__refreshNode(pNodeIter->second);
	}
	else
	{
		if (m_HashMap.size() >= m_CacheCap)
		{
			std::string vLeastRecentlyUsedKey = __removeNode(m_pHead);
			m_HashMap.erase(vLeastRecentlyUsedKey);
		}

		std::shared_ptr<SNode> pNode = std::make_shared<SNode>(vKey, vValue);

		
		__addNode(pNode);

		m_HashMap.insert({ vKey, pNode });
	}
}

//***********************************************************************
//FUNCTION:
void CLRUCache::remove(const std::string& vKey)
{
	auto pNodeIter = m_HashMap.find(vKey);
	if (pNodeIter != m_HashMap.end())
	{
		__removeNode(pNodeIter->second);
		m_HashMap.erase(vKey);
	}
}

//***********************************************************************
//FUNCTION:
void CLRUCache::__addNode(const std::shared_ptr<SNode>& vNode)
{
	if (m_pEnd)
	{
		m_pEnd->pNext = vNode;
		vNode->pPre = m_pEnd;
		vNode->pNext = nullptr;
	}
	m_pEnd = vNode;

	if (!m_pHead)
		m_pHead = vNode;
}

//***********************************************************************
//FUNCTION:
void CLRUCache::__refreshNode(const std::shared_ptr<SNode>& vNode)
{
	if (vNode == m_pEnd)
		return;

	__removeNode(vNode);
	__addNode(vNode);
}

//***********************************************************************
//FUNCTION:
std::string CLRUCache::__removeNode(const std::shared_ptr<SNode>& vNode)
{
	if (vNode == m_pEnd)
		m_pEnd = m_pEnd->pPre;
	else if (vNode == m_pHead)
		m_pHead = m_pHead->pNext;
	else
	{
		(vNode->pPre)->pNext = vNode->pNext;
		(vNode->pNext)->pPre = vNode->pPre;
	}

	return vNode->Key;
}

