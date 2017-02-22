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
	void clear(); //모든 노드를 삭제
	int length();
	
private:
	Node<T>* head;
	int count; //노드의 개수
};
