#include <iostream>
#include <string>
#include "LinkedList.h"

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

//�� �ڿ� ��带 �߰�
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

//������ �ε����� ��带 ����
template <typename T>
void LinkedList<T>::del(int index)
{
	if (count <= 0 || head == NULL)
	{
		std::cout << "���� �Էµ� �ڷᰡ �����ϴ�." << std::endl;
		return;
	}
	else
	{
		Node<Score>* scanNode = head;
		Node<Score>* prevNode;

		for (int i = 1; i < index; i++)
		{
			if (scanNode->next == NULL)
			{
				break;
			}

			prevNode = scanNode;
			scanNode = scanNode->next;
		}

		if (nextNode == NULL)
		{
			prevNode->next = NULL;
		}
		else
		{
			prevNode->next = scanNode->next;
		}

		delete scanNode;

		count--;
	}
}

//������ �ε����� ��带 ���
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

		for (int i = 1; i < index; i++)
		{
			if (scanNode->next == NULL)
			{
				break;
			}

			scanNode = nextNode;
		}

		return scanNode;
	}
}

//��� ��带 ����
template<typename T>
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

//����� ����(�ܺ� ���ٿ�)
template<typename T>
int LinkedList<T>::length()
{
	return count;
}