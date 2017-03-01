#pragma once

#include <iostream>
#include <string>

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

	void add(Node<T>* inputNode); //맨 뒤에 노드를 추가
	void del(int index); //지정한 인덱스의 노드를 삭제
	T print(int index); //지정한 인덱스의 노드를 출력
	void clear(); //모든 노드를 삭제
	int length(); //노드의 개수(외부 접근용)

private:
	Node<T>* head;
	int count; //노드의 개수(내부용)
};
