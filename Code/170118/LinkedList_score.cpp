#include "LinkedList_Score.h"
#include <algorithm>
#include <iostream>
#include <string>

inline void printLine();
std::string::iterator a;
for (auto a = temp.begin(); a != temp.end(); a++)
std::sort(vec);
//LinkedList 생성자
LinkedList::LinkedList()
{
	
	head = nullptr;
	count = 0;
}

//LinkedList 소멸자
LinkedList::~LinkedList()
{
	LinkedList::clear();
}

//메뉴 1: 성적 입력
void LinkedList::add()
{
	Node* scanNode;
	
	if (head == NULL)
	{
		Node* addNode = inputScore();
		head = addNode;
	}
	else
	{
		scanNode = head;
		while (scanNode->next != NULL)
		{
			scanNode = scanNode->next;
		}

		Node* addNode = inputScore();
		scanNode->next = addNode;
	}

	count++;
}

//메뉴 2: 입력된 자료 확인
void LinkedList::print()
{
	printLine();

	if (count <= 0 || head == NULL)
	{
		std::cout << "아직 입력된 성적이 없습니다." << std::endl;
		return;
	}
	else
	{
		Node* scanNode = head;

		while (scanNode != NULL)
		{
			if (scanNode->value.isMajor)
			{
				std::cout << scanNode->value.name + "(" + std::to_string(scanNode->value.credit) + "학점, 전공): " + scanNode->value.gradeText << std::endl;
			}
			else
			{
				std::cout << scanNode->value.name << "(" << scanNode->value.credit << "학점, 교양): " << scanNode->value.gradeText << std::endl;
			}

			scanNode = scanNode->next;
		}
	}

	printLine();
}

//메뉴 3: 계산 결과 출력
void LinkedList::calculate()
{
	int credit_all_sum = 0;
	float grade_all_sum = 0.0f;
	int credit_major_sum = 0;
	float grade_major_sum = 0.0f;

	if (count <= 0 || head == NULL)
	{
		std::cout << "아직 입력된 성적이 없습니다." << std::endl;
	}
	else
	{
		Node* scanNode = head;

		while (scanNode != NULL)
		{
			credit_all_sum += scanNode->value.credit;
			grade_all_sum += scanNode->value.grade * scanNode->value.credit;
			if (scanNode->value.isMajor)
			{
				credit_major_sum += scanNode->value.credit;
				grade_major_sum += scanNode->value.grade * scanNode->value.credit;
			}

			scanNode = scanNode->next;
		}

		printLine();
		std::cout << "수강 강의 수: " << count << std::endl << std::endl;
		std::cout << "총 이수 학점: " << credit_all_sum << std::endl;
		std::cout << "총 평점평균: " << grade_all_sum / (float)credit_all_sum << std::endl << std::endl;
		std::cout << "전공 이수 학점: " << credit_major_sum << std::endl;
		std::cout << "전공 평점평균: " << grade_major_sum / (float)credit_major_sum << std::endl;
		printLine();
	}


}

//모든 노드를 삭제
void LinkedList::clear()
{
	Node* scanNode = head;
	Node* prevNode;

	while (scanNode->next != NULL)
	{
		prevNode = scanNode;
		scanNode = scanNode->next;
		delete prevNode;
	}
	delete scanNode;
	count = 0;
}

//고쳐봄
Node* LinkedList::inputScore()
{
	Node<int>* addNode = new Node<int>;
	std::string gradeText_temp;
	std::string isMajor_temp;
	std::string value_temp;

	printLine();

	//과목명 입력
	std::cout << "- 과목명" << std::endl;
	std::cout << ">";
	std::getline(std::cin, addNode->value.name);

	//단위 입력
	std::cout << "- 단위(1학점, 2학점, 3학점 등)" << std::endl;
	std::cout << ">";
	std::getline(std::cin, value_temp);
	addNode->value.credit = atoi(value_temp.c_str());//Question : 이게 왜 되나?

	//성적 입력
	while (true)
	{
		std::cout << "- 획득한 성적(A+, A, B 등)" << std::endl;
		std::cout << ">";
		std::getline(std::cin, gradeText_temp);
		
		transform(gradeText_temp.begin(), gradeText_temp.end(), gradeText_temp.begin(), toupper);//Question : begin end뭔지 암?
		//std::string에 대해서
		/*
		if (gradeText_temp == "A+")
		{
			addNode->value.grade = 4.5;
			addNode->value.gradeText = "A+";
			break;
		}
		else if (gradeText_temp == "A")
		{
			addNode->value.grade = 4;
			addNode->value.gradeText = "A";
			break;
		}
		else if (gradeText_temp == "B+")
		{
			addNode->value.grade = 3.5;
			addNode->value.gradeText = "B+";
			break;
		}
		else if (gradeText_temp == "B")
		{
			addNode->value.grade = 3;
			addNode->value.gradeText = "B";
			break;
		}
		else if (gradeText_temp == "C+")
		{
			addNode->value.grade = 2.5;
			addNode->value.gradeText = "C+";
			break;
		}
		else if (gradeText_temp == "C")
		{
			addNode->value.grade = 2;
			addNode->value.gradeText = "C";
			break;
		}
		else if (gradeText_temp == "D+")
		{
			addNode->value.grade = 1.5;
			addNode->value.gradeText = "D+";
			break;
		}
		else if (gradeText_temp == "D")
		{
			addNode->value.grade = 1;
			addNode->value.gradeText = "D";
			break;
		}
		else if (gradeText_temp == "F")
		{
			addNode->value.grade = 0;
			addNode->value.gradeText = "F";
			break;
		}
		*/
		if(gradeText_temp.length()>3)
		{
			std::cout << "입력값이 잘못되었습니다." << std::endl;
		}
		else
		{
			
			//첫번째 문자에서 숫자를 빼냄
			addNode->value.grade = 4.0f - (gradeText_temp[0] - 'A');
			//F면
			if (addNode->value.grade == -1.0f && gradeText_temp.length()==1)
			{
				addNode->value.grade = 0.0f;
				addNode->value.gradeText = gradeText_temp;
				break;
			}
			//A~D사이
			if (addNode->value.grade < 1.0f || addNode->value.grade>4.0f)
			{
				std::cout << "입력값이 잘못되었습니다." << std::endl;
			}//+
			else if(gradeText_temp[1]=='+')
			{
				
				addNode->value.grade += 0.5;
				addNode->value.gradeText = gradeText_temp;
				break;
			}//+없음
			else
			{
				addNode->value.gradeText = gradeText_temp;
				break;
			}
		}
	}

	//전공 여부 입력
	while (true)
	{
		std::cout << "전공 여부(Y, N)" << std::endl;
		std::cout << ">";
		std::getline(std::cin, isMajor_temp);
		capitalize(isMajor_temp);

		if (isMajor_temp == "Y")
		{
			addNode->value.isMajor = true;
			break;
		}
		else if (isMajor_temp == "N")
		{
			addNode->value.isMajor = false;
			break;
		}
		else
		{
			std::cout << "입력값이 잘못되었습니다." << std::endl;
		}
	}

	printLine();

	addNode->next = NULL;

	return addNode;
}

void capitalize(std::string& string)
{
	double a;
	const int c = 3;
	std::string d = "3ds";
	int b = static_cast<int>( a);
	dynamic_cast<>();
		a = reinterpret_cast<double>(d);
		const_cast<int>(c) = 5;
	for (int i = 0; i < string.length(); i++)
	{
		string[i] = toupper(string[i]);
	}
}

void printLine()
{
	std::cout << "-------------------------------------" << std::endl;
}
