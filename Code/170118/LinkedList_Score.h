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
	//----------------------------------------------------
	void Print();
	//----------------------------------------------------
};

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

	//void add(); //새 값을 입력
	void print(); //모든 노드를 출력
	void calculate(); //학점 계산 결과를 출력
	void clear(); //모든 노드를 삭제
	void add(Node<T>* inputNode);
private:
	Node<T>* head;
	//Node<T>* inputScore();
	int count; //노드의 개수
};
