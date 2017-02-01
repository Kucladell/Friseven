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

	void add(); //새 값을 입력
	void print(); //모든 노드를 출력
	void calculate(); //학점 계산 결과를 출력
	void clear(); //모든 노드를 삭제

private:
	Node* head;
	int count; //노드의 개수

};
