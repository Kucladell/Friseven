#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList()
{
	head = nullptr;
	count = 0;
}

LinkedList::~LinkedList()
{
	LinkedList::removeAll();
}

void LinkedList::add(int value, int index)
{
	if (index > length())
	{
		std::cout << "잘못된 인덱스값입니다." << std::endl;
	}
	else if (index < 0)
	{
		std::cout << "잘못된 인덱스값입니다." << std::endl;
	}
	else if (head == NULL && index != 0)
	{
		std::cout << "잘못된 인덱스값입니다." << std::endl;
	}
	else
	{
		Node* addNode = new Node;
		Node* scanNode;

		if (head == NULL)
		{
			addNode->value = value;
			addNode->next = NULL;
			head = addNode;
		}
		else
		{
			if (index == 0)
			{
				addNode->value = value;
				addNode->next = head;
				head = addNode;
			}
			else if (index == length())
			{
				scanNode = head;
				while (scanNode->next != NULL)
				{
					scanNode = scanNode->next;
				}
				addNode->value = value;
				addNode->next = NULL;
				scanNode->next = addNode;
			}
			else
			{
				scanNode = head;
				for (int i = 0; i < index - 1; i++)
				{
					scanNode = scanNode->next;
				}
				addNode->value = value;
				addNode->next = scanNode->next;
				scanNode->next = addNode;
			}
		}

		count++;
	}
	
}

void LinkedList::addFirst(int value)
{
	LinkedList::add(value, 0);
}

void LinkedList::addLast(int value)
{
	LinkedList::add(value, length());
}

void LinkedList::remove(int value)
{
	if (LinkedList::find(value) == false)
	{
		std::cout << "해당 값이 존재하지 않습니다." << std::endl;
	}
	else
	{
		Node* scanNode = head;
		Node* nextNode;

		while (scanNode->next != NULL)
		{
			nextNode = scanNode->next;
			if (nextNode->value == value)
			{
				scanNode->next = nextNode->next;
				delete nextNode;
				break;
			}
			scanNode = scanNode->next;
		}

		count--;
	}
}

void LinkedList::removeFirst()
{
	Node* scanNode = head;

	head = scanNode->next;
	delete scanNode;

	count--;
}

void LinkedList::removeLast()
{
	Node* scanNode = head;
	Node* prevNode;

	while (scanNode->next != NULL)
	{
		prevNode = scanNode;
		scanNode = scanNode->next;
	}
	prevNode->next = NULL;
	delete scanNode;

	count--;
}

void LinkedList::removeAll()
{
	Node* scanNode = head;
	Node* prevNode;

	while (scanNode->next != NULL)
	{
		prevNode = scanNode;
		scanNode = scanNode->next;
		delete prevNode;
	}
	delete scanNode;
	count == 0;
}

bool LinkedList::find(int value)
{
	Node* scanNode = head;

	while (scanNode->next != NULL)
	{
		if (scanNode->value == value)
		{
			return true;
		}
		scanNode = scanNode->next;
	}
	return false;
}

int LinkedList::findIndex(int value)
{
	if (LinkedList::find(value) == false)
	{
		std::cout << "해당 값이 존재하지 않습니다." << std::endl;
		return -1;
	}
	else
	{
		Node* scanNode = head;

		for (int i = 0; i < length(); i++)
		{
			if (scanNode->value == value)
			{
				return i;
			}
			scanNode = scanNode->next;
		}
	}
}

int LinkedList::print(int index)
{
	if (index +1 > LinkedList::length())
	{
		std::cout << "잘못된 인덱스값입니다." << std::endl;
		return -1;
	}
	else if (index < 0)
	{
		std::cout << "잘못된 인덱스값입니다." << std::endl;
		return -1;
	}
	else if (head == NULL)
	{
		std::cout << "잘못된 대상입니다." << std::endl;
	}
	else
	{
		Node* scanNode = head;

		for (int i = 0; i < length(); i++)
		{
			if (i == index)
			{
				return scanNode->value;
			}
			scanNode = scanNode->next;
		}
	}
}

int LinkedList::printFirst()
{
	return LinkedList::print(0);
}

int LinkedList::printLast()
{
	return LinkedList::print(LinkedList::length());
}

int LinkedList::printValue(int value)
{
	return LinkedList::print(LinkedList::findIndex(value));
}
void LinkedList::printAll()
{
	if (head == NULL)
	{
		std::cout << "잘못된 대상입니다." << std::endl;
	}
	else
	{
		Node* scanNode = head;

		while(scanNode->next != NULL)
		{
			std::cout << scanNode->value << std::endl;
			scanNode = scanNode->next;
		}
	}
}

int LinkedList::length()
{
	return count;
}

bool LinkedList::isEmpty()
{
	if (head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

