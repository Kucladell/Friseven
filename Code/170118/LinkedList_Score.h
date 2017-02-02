#pragma once
#include <iostream>
#include <string>
#include <list>
#include <map>
#include <vector>

struct Score
{
	std::string name;
	int credit;
	float grade;
	std::string gradeText;
	bool isMajor;
};

template<typename T1,typename T2> 
struct Node
{
	T1 value;
	Node* next;
};
template<typename T>
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
	Node<T>* head;
	Node<T>* inputScore();
	void capitalize(std::string& string);
	int count; //노드의 개수
	std::list<Score> Score_List;
	std::map<std::string, Score> scoremap;
	void ddd()
	{
		Score_List.push_back(input);
		Score dd;
		scoremap["컴퓨터구조"] = dd;
		scoremap.insert();
		scoremap.clear();
		std::vector<Score> sda;
		sda.size();

	}
};
