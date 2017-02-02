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

	void add(); //�� ���� �Է�
	void print(); //��� ��带 ���
	void calculate(); //���� ��� ����� ���
	void clear(); //��� ��带 ����

private:
	Node<T>* head;
	Node<T>* inputScore();
	void capitalize(std::string& string);
	int count; //����� ����
	std::list<Score> Score_List;
	std::map<std::string, Score> scoremap;
	void ddd()
	{
		Score_List.push_back(input);
		Score dd;
		scoremap["��ǻ�ͱ���"] = dd;
		scoremap.insert();
		scoremap.clear();
		std::vector<Score> sda;
		sda.size();

	}
};
