#pragma once
#include "..\LinkedList\LinkedList.h"

class ListStack
{
public: 
	ListStack();
	~ListStack();
	void Push(int value); //value를 넣는다
	int Pop(); //맨 위값을 리턴하고 스택에서 뺀다
	int Count() { return size; } // 스택에 들어 있는 원소 개수를 리턴한다
	int Top(); // 맨 위 값을 리턴만 한다
	bool Empty(); // 스택이 비어있는지 검사한다
private:
	int size;
	LinkedList list;
};