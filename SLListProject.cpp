#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>
#include "SLList.h"

using namespace std;

void printSLList(const SLList* list)
{
	auto current = list;
	while (current->hasNext())
	{
		cout << current->getData() << '\n';
		current = current->next();
	}
	cout << current->getData() << '\n';
}

void deleteDuplicates(SLList* list)
{
	auto current = list;
	auto uniqueNumbers = set<int>();
	uniqueNumbers.insert(current->getData());
	while (current->hasNext())
	{
		if (uniqueNumbers.count(current->next()->getData()))
		{
			current->removeNext();
		}
		else
		{
			current = current->next();
			uniqueNumbers.insert(current->getData());
		}
	}
}

// Метод считает позицию с 0
SLList* findElementByPosFromEnd(SLList* list, int pos)
{
	if (!list) throw invalid_argument("List was nullptr!");
	int size = 1;
	auto current = list;
	while (current->hasNext())
	{
		current = current->next();
		size++;
	}
	if (pos + 1 > size) throw invalid_argument("Position was bigger than the size of list!");
	current = list;
	for (int i = 0; i < size - pos - 1; i++)
	{
		current = current->next();
	}
	return current;
}

int main()
{
	srand(int(time(0)));
	auto list = SLList::beginList(rand() % 6);
	for (int i = 0; i < 9; i++)
	{
		list->addElement(rand() % 6);
	}
	printSLList(list);
	cout << '\n';
	deleteDuplicates(list);
	printSLList(list);
	cout << '\n' << "Second element from the end is: " << findElementByPosFromEnd(list, 2)->getData();
}