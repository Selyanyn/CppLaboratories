#include <iostream>
#include <cstdlib>
#include <ctime>
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

int getLength(const SLList* list)
{
	if (!list)
		return 0;
	int length = 1;
	auto current = list;
	while (current->hasNext())
	{
		current = current->next();
		length++;
	}
	return length;
}

bool containsNumber(int* arr, int currentAmountOfNumbers, int number)
{
	for (int i = 0; i < currentAmountOfNumbers; i++)
		if (arr[i] == number)
			return true;
	return false;
}

void deleteDuplicates(SLList* list)
{
	auto current = list;
	auto uniqueNumbers = new int[getLength(list)];
	uniqueNumbers[0] = list->getData();
	int currentAmountOfNumbers = 1;
	while (current->hasNext())
	{
		if (containsNumber(uniqueNumbers, currentAmountOfNumbers, current->next()->getData()))
			current->removeNext();
		else
		{
			current = current->next();
			uniqueNumbers[currentAmountOfNumbers] = current->getData();
			currentAmountOfNumbers++;
		}
	}
}

// Метод считает позицию с 0
SLList* findElementByPosFromEnd(SLList* list, int pos)
{
	if (!list)
		return nullptr;
	int size = 1;
	auto current = list;
	while (current->hasNext())
	{
		current = current->next();
		size++;
	}
	if (pos + 1 > size)
		return nullptr;
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