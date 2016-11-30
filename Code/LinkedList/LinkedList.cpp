#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList()
{
	head = nullptr;
	count = 0;
}
LinkedList::~LinkedList()
{
	Clear();

	//수정 코드 시작
	removeAll();
	//수정 코드 끝
}

void LinkedList::AddBack(int value)
{
	Node* newNode = new Node;
	Node* skimNode;

	if (head == NULL)
	{
		newNode->value = value;
		newNode->next = NULL;
		head = newNode;
	}
	else
	{
		skimNode = head;
		while (skimNode->next != NULL)
		{
			skimNode = skimNode->next;
		}
		newNode->value = value;
		newNode->next = NULL;
		skimNode->next = newNode;
	}
	count++;

}

void LinkedList::RemoveValue(int value)
{
	if (LinkedList::Find(value) == false)
	{
		std::cout << "해당 값이 존재하지 않습니다." << std::endl;
	}
	else
	{
		Node* skimNode = head;
		Node* nextNode;

		while (skimNode->next != NULL)
		{
			nextNode = skimNode->next;
			if (nextNode->value == value)
			{
				skimNode->next = nextNode->next;
				nextNode->value = NULL;
				nextNode->next = NULL;
				break;
			}
			skimNode = skimNode->next;
		}
		skimNode->next = NULL;
		count--;
	}
}

void LinkedList::RemoveLast()
{
	Node* skimNode = head;
	Node* nextNode;

	while (skimNode->next != NULL)
	{
		nextNode = skimNode->next;
		if (nextNode->next == NULL)
		{
			nextNode->value = NULL;
			nextNode->next = NULL;
			skimNode->next = NULL;
		}
		skimNode = skimNode->next;
	}
}

bool LinkedList::Find(int value)
{
	Node* skimNode = head;

	while (skimNode->next != NULL)
	{
		if (skimNode->value == value)
		{
			return true;
			break;
		}
		skimNode = skimNode->next;
	}
	return false;
}

void LinkedList::Print(int value)
{
	if (LinkedList::Find(value) == false)
	{
		std::cout << "해당 값이 존재하지 않습니다." << std::endl;
	}
	else
	{
		Node* skimNode = head;

		while (skimNode->next != NULL)
		{
			if (skimNode->value == value)
			{
				std::cout << skimNode->value << std::endl;
				break;
			}
		}
	}
}

void LinkedList::PrintLast()
{
	Node* skimNode = head;

	while (skimNode->next != NULL)
	{
		skimNode = skimNode->next;
	}
	std::cout << skimNode->value << std::endl;
}

void LinkedList::PrintAll()
{
	Node* skimNode = head;

	while (skimNode->next != NULL)
	{
		std::cout << skimNode->value << std::endl;
		skimNode = skimNode->next;
	}
}

void LinkedList::Clear()
{
	Node* delNode;
	Node* skimNode = head;

	while (skimNode->next != NULL)
	{
		delNode = skimNode;
		skimNode = skimNode->next;
		delNode->value = NULL;
		delNode->next = NULL;
		delete[] delNode;
	}
	skimNode->value = NULL;
	delete[] skimNode;
	count = 0;
}

bool LinkedList::Empty()
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

//수정 코드 시작

void LinkedList::add(int value, int index)
{
	Node* addNode = new Node;
	Node* scanNode;

	if (head == NULL)
	{

	}
}

