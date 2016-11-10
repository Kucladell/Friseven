#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList()
{
	head = nullptr;
	count = 0;

}
LinkedList::~LinkedList()
{
	Clear();
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
		cout << "해당 값이 존재하지 않습니다." << endl;
	}
	else
	{
		Node* skimNode = head;

		while (skimNode->next != NULL)
		{
			skimNode = skimNode->next;
		}
		skimNode->next = NULL;
		count--;
	}
}

bool LinkedList::Find(int value)
{
	Node* skimNode = head;

	while (skimNode->next != NULL)
	{
		if (skimNode->value = value) {
			return true;
			break;
		}
		skimNode = skimNode->next;
	}
	return false;
}

void LinkedList::Print()
{
	Node* skimNode = head;

	while (skimNode->next != NULL)
	{
		cout << skimNode->value << endl;
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
	}
	skimNode->value = NULL;
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



