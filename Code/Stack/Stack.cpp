#include "Stack.h"

ListStack::ListStack()
{
	list.Clear();
	size = 0;
}

ListStack::~ListStack()
{
	list.Clear();
	size = 0;
}

void ListStack::Push(int value)
{
	list.AddBack(value);
	size++;
}

int ListStack::Pop()
{
	list.PrintLast();
	list.RemoveLast();
	size--;
}

int ListStack::Top()
{
	list.PrintLast();
}

bool ListStack::Empty()
{
	return list.Empty();
	size = 0;
}

