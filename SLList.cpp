#include "SLList.h"

SLList::SLList(int data, SLList* nextElem)
{
	m_data = data;
	m_nextElem = nextElem;
}

int const SLList::getData() const
{
	return m_data;
}

void SLList::setData(int data)
{
	m_data = data;
}

SLList* const SLList::next() const
{
	return m_nextElem;
}

bool const SLList::hasNext() const
{
	return m_nextElem;
}

SLList* SLList::beginList(int data)
{
	return new SLList(data);
}

SLList* SLList::addElement(int data)
{
	auto current = this;
	while (current->hasNext())
	{
		current = current->next();
	}
	current->m_nextElem = new SLList(data);
	return current->m_nextElem;
}

void SLList::removeNext()
{
	if (m_nextElem->hasNext())
	{
		auto removingElement = m_nextElem;
		m_nextElem = m_nextElem->m_nextElem;
		removingElement->m_nextElem = nullptr;
		delete removingElement;
	}
	else
	{
		delete m_nextElem;
		m_nextElem = nullptr;
	}
}

SLList::~SLList()
{
	if (hasNext())
	{
		delete m_nextElem;
	}
}