#include <iostream>
#include <string>
#include "LinkedList.h"

//LinkedList 생성자
template<typename T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
	count = 0;
}

//LinkedList 소멸자
template<typename T>
LinkedList<T>::~LinkedList()
{
	LinkedList<T>::clear();
}

//맨 뒤에 노드를 추가
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

//지정한 인덱스의 노드를 삭제
template <typename T>
void LinkedList<T>::del(int index)
{
	if (count <= 0 || head == NULL)
	{
		std::cout << "아직 입력된 자료가 없습니다." << std::endl;
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

//지정한 인덱스의 노드를 출력
template<typename T>
T LinkedList<T>::print(int index)
{
	if (count <= 0 || head == NULL)
	{
		std::cout << "아직 입력된 자료가 없습니다." << std::endl;
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

//모든 노드를 삭제
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

//노드의 개수(외부 접근용)
template<typename T>
int LinkedList<T>::length()
{
	return count;
}