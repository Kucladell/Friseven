#pragma once

#include <iostream>
#include <string>

template<typename T>
struct Node
{
	T value;
	Node* next;
	void Print() { T.print(); }

};

template<typename T>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void add(Node<T>* inputNode); //�� �ڿ� ��带 �߰�
	void del(int index); //������ �ε����� ��带 ����
	T print(int index); //������ �ε����� ��带 ���
	void clear(); //��� ��带 ����
	int length(); //����� ����(�ܺ� ���ٿ�)

private:
	Node<T>* head;
	int count; //����� ����(���ο�)
};
