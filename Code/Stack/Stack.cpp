#include "Stack.h"

ListStack::ListStack()
{
	list.removeAll();
	size = 0;
}

ListStack::~ListStack()
{
	list.removeAll();
	size = 0;
}

void ListStack::push(int value)
{
	list.addFirst(value);
	size++;
}

int ListStack::pop()
{
	int value = list.printFirst();
	list.removeFirst();
	return value;
	size--;
}

int ListStack::top()
{
	return list.printFirst();
}

int ListStack::count()
{
	return size;
}

bool ListStack::isEmpty()
{
	return list.isEmpty();
}

