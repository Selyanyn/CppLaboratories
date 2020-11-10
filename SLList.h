#pragma once

class SLList
{
private:
	SLList* m_nextElem;
	int m_data;
	SLList(int data, SLList* nextElem = nullptr);
public:
	int const getData() const;
	void setData(int data);
	SLList* const next() const;
	bool const hasNext() const;
	static SLList* beginList(int data);
	SLList* addElement(int data);
	void removeNext();
	~SLList();
};