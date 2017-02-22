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

	//void add(); //�� ���� �Է�
	void print(); //��� ��带 ���
	void calculate(); //���� ��� ����� ���
	void clear(); //��� ��带 ����
	void add(Node<T>* inputNode);
private:
	Node<T>* head;
	//Node<T>* inputScore();
	int count; //����� ����
};
