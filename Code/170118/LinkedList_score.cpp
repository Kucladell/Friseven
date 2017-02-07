#include "LinkedList_Score.h"
#include <iostream>
#include <string>

inline void printLine();
void capitalize(std::string& string);

//LinkedList 생성자
template<typename T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
	count = 0;
}

//LinkedList 소멸자
template<typename T>
LinkedList<T>::~LinkedList()
{
	LinkedList<T>::clear();
}

//메뉴 1: 성적 입력
//----------------------------------------------------
/*
template<typename T>
void LinkedList<T>::add()
{
	Node<T>* scanNode;
	
	if (head == NULL)
	{
		Node<T>* addNode = inputScore();
		head = addNode;
	}
	else
	{
		scanNode = head;
		while (scanNode->next != NULL)
		{
			scanNode = scanNode->next;
		}

		Node<T>* addNode = inputScore();
		scanNode->next = addNode;
	}

	count++;
}
*/
//----------------------------------------------------
template<typename T>
void LinkedList::add(Node<T>* inputNode)
{

	if (head == NULL)
	{
		
		head = inputNode;
	}
	else
	{
		scanNode = head;
		while (scanNode->next != NULL)
		{
			scanNode = scanNode->next;
		}

		
		scanNode->next = inputNode;
	}

	count++;
}

//메뉴 2: 입력된 자료 확인
template<typename T>
void LinkedList<T>::print()
{
	printLine();

	if (count <= 0 || head == NULL)
	{
		std::cout << "아직 입력된 성적이 없습니다." << std::endl;
		return;
	}
	else
	{
		Node<Score>* scanNode = head;

		while (scanNode != NULL)
		{
			//----------------------------------------------------
			/*
			if (scanNode->value.isMajor)
			{
				std::cout << scanNode->value.name + "(" + std::to_string(scanNode->value.credit) + "학점, 전공): " + scanNode->value.gradeText << std::endl;
								
			}
			else
			{
				std::cout << scanNode->value.name << "(" << scanNode->value.credit << "학점, 교양): " << scanNode->value.gradeText << std::endl;
			}
			*/
			//----------------------------------------------------
			scanNode->value.Print();
			scanNode = scanNode->next;
		}
	}

	printLine();
}

//메뉴 3: 계산 결과 출력
template<typename T>
void LinkedList<T>::calculate()
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
		Node<T>* scanNode = head;

		while (scanNode != NULL)
		{

			//----------------------------------------------------
			/*
			credit_all_sum += scanNode->value.credit;
			grade_all_sum += scanNode->value.grade * scanNode->value.credit;
			if (scanNode->value.isMajor)
			{
				credit_major_sum += scanNode->value.credit;
				grade_major_sum += scanNode->value.grade * scanNode->value.credit;
			}
			*/
			//---------------------------------------------------
			//TODO
			scanNode = scanNode->next;
		}

		printLine();
		//----------------------------------------------------
		/*
		std::cout << "수강 강의 수: " << count << std::endl << std::endl;
		std::cout << "총 이수 학점: " << credit_all_sum << std::endl;
		std::cout << "총 평점평균: " << grade_all_sum / (float)credit_all_sum << std::endl << std::endl;
		std::cout << "전공 이수 학점: " << credit_major_sum << std::endl;
		std::cout << "전공 평점평균: " << grade_major_sum / (float)credit_major_sum << std::endl;
		*/
		//----------------------------------------------------
		printLine();
	}


}

//모든 노드를 삭제
template<> //QUESTION: template <typename T>가 아니었던 건가요
void LinkedList<Score>::clear()
{
	Node<Score>* scanNode = head;
	Node<Score>* prevNode;

	while (scanNode->next != NULL)
	{
		prevNode = scanNode;
		scanNode = scanNode->next;
		delete prevNode;
	}
	delete scanNode;
	count = 0;
}

/*
//성적 입력(add와 연동)
template<class T>
Node<T>* LinkedList<T>::inputScore()
{
	Node<Score>* addNode = new Node<Score>;
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
		capitalize(gradeText_temp);

		if(gradeText_temp.length()>3)
		{
			std::cout << "입력값이 잘못되었습니다." << std::endl;
		}
		else
		{
			//첫번째 문자에서 숫자를 산출(Keycode 이용)
			addNode->value.grade = 4.0f - (gradeText_temp[0] - 'A');

			//성적이 F일 경우
			if (addNode->value.grade == -1.0f && gradeText_temp.length() == 1)
			{
				addNode->value.grade = 0.0f;
				addNode->value.gradeText = gradeText_temp;
				break;
			}
			//성적이 A에서 D 사이일 경우
			if (addNode->value.grade < 1.0f || addNode->value.grade>4.0f)
			{
				std::cout << "입력값이 잘못되었습니다." << std::endl;
			}
			else if(gradeText_temp[1]=='+') //+가 붙은 경우
			{
				addNode->value.grade += 0.5;
				addNode->value.gradeText = gradeText_temp;
				break;
			}
			else //+가 붙지 않은 경우
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
*/
void capitalize(std::string& string)
{
	for (int i = 0; i < (int)string.length(); i++)
	{
		string[i] = toupper(string[i]);
	}
}

void printLine()
{
	std::cout << "-------------------------------------" << std::endl;
}
