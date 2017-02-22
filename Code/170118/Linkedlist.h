#pragma once

#include <iostream>
#include <string>
#include "Score.h"

template<typename T>
struct Node
{
	T value;
	Node* next;
};

template<typename T>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void add(Node<T>* inputNode);
	T print(int index);
	void clear(); //��� ��带 ����
	int length();
	
private:
	Node<T>* head;
	int count; //����� ����
};
