#include <iostream>
#include <string>
#include "Linkedlist.h"

//LinkedList ������
template<typename T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
	count = 0;
}

//LinkedList �Ҹ���
template<typename T>
LinkedList<T>::~LinkedList()
{
	LinkedList<T>::clear();
}

template<typename T>
void LinkedList::add(Node<T>* inputNode)
{

	if (head == NULL)
	{
		head = inputNode;
	}
	else
	{
		scanNode = head;
		while (scanNode->next != NULL)
		{
			scanNode = scanNode->next;
		}

		scanNode->next = inputNode;
	}

	count++;
}

template<typename T>
T LinkedList<T>::print(int index)
{
	if (count <= 0 || head == NULL)
	{
		std::cout << "���� �Էµ� �ڷᰡ �����ϴ�." << std::endl;
		return;
	}
	else
	{
		Node<Score>* scanNode = head;
		Node<Score>* nextNode = head->next;

		for (int i = 1; i < index; i++)
		{
			if (nextNode == NULL)
			{
				break;
			}

			scanNode = nextNode;
			nextNode = scanNode->next;
		}

		return scanNode;
	}
}

//��� ��带 ����
template<typeanme T>
void LinkedList<T>::clear()
{
	Node<T>* scanNode = head;
	Node<T>* prevNode;

	while (scanNode->next != NULL)
	{
		prevNode = scanNode;
		scanNode = scanNode->next;
		delete prevNode;
	}
	delete scanNode;
	count = 0;
}

template<typename T>
int LinkedList<T>::length()
{
	return count;
}