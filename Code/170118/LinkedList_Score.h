#pragma once
#include <iostream>
#include <string>

struct Score
{
	std::string name;
	int credit;
	float grade;
	std::string gradeText;
	bool isMajor;
};

struct Node
{
	Score value;
	Node* next;
};

class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void add(); //�� ���� �Է�
	void print(); //��� ��带 ���
	void calculate(); //���� ��� ����� ���
	void clear(); //��� ��带 ����

private:
	Node* head;
	int count; //����� ����

};
