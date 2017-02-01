#include "LinkedList_Score.h"
#include <algorithm>
#include <iostream>
#include <string>

Node* inputScore();
void printLine();

//LinkedList ������
LinkedList::LinkedList()
{
	head = nullptr;
	count = 0;
}

//LinkedList �Ҹ���
LinkedList::~LinkedList()
{
	LinkedList::clear();
}

//�޴� 1: ���� �Է�
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

//�޴� 2: �Էµ� �ڷ� Ȯ��
void LinkedList::print()
{
	printLine();

	if (count <= 0 || head == NULL)
	{
		std::cout << "���� �Էµ� ������ �����ϴ�." << std::endl;
		return;
	}
	else
	{
		Node* scanNode = head;

		while (scanNode != NULL)
		{
			if (scanNode->value.isMajor)
			{
				std::cout << scanNode->value.name << "(" << scanNode->value.credit << "����, ����): " << scanNode->value.gradeText << std::endl;
			}
			else
			{
				std::cout << scanNode->value.name << "(" << scanNode->value.credit << "����, ����): " << scanNode->value.gradeText << std::endl;
			}

			scanNode = scanNode->next;
		}
	}

	printLine();
}

//�޴� 3: ��� ��� ���
void LinkedList::calculate()
{
	int credit_all_sum = 0;
	float grade_all_sum = 0.0f;
	int credit_major_sum = 0;
	float grade_major_sum = 0.0f;

	if (count <= 0 || head == NULL)
	{
		std::cout << "���� �Էµ� ������ �����ϴ�." << std::endl;
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
		std::cout << "���� ���� ��: " << count << std::endl << std::endl;
		std::cout << "�� �̼� ����: " << credit_all_sum << std::endl;
		std::cout << "�� �������: " << grade_all_sum / (float)credit_all_sum << std::endl << std::endl;
		std::cout << "���� �̼� ����: " << credit_major_sum << std::endl;
		std::cout << "���� �������: " << grade_major_sum / (float)credit_major_sum << std::endl;
		printLine();
	}


}

//��� ��带 ����
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

Node* inputScore()
{
	Node* addNode = new Node;
	std::string gradeText_temp;
	std::string isMajor_temp;
	std::string value_temp;

	printLine();

	//����� �Է�
	std::cout << "- �����" << std::endl;
	std::cout << ">";
	std::getline(std::cin, addNode->value.name);

	//���� �Է�
	std::cout << "- ����(1����, 2����, 3���� ��)" << std::endl;
	std::cout << ">";
	std::getline(std::cin, value_temp);
	addNode->value.credit = atoi(value_temp.c_str());

	//���� �Է�
	while (true)
	{
		std::cout << "- ȹ���� ����(A+, A, B ��)" << std::endl;
		std::cout << ">";
		std::getline(std::cin, gradeText_temp);
		transform(gradeText_temp.begin(), gradeText_temp.end(), gradeText_temp.begin(), toupper);

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
		else
		{
			std::cout << "�Է°��� �߸��Ǿ����ϴ�." << std::endl;
		}
	}

	//���� ���� �Է�
	while (true)
	{
		std::cout << "���� ����(Y, N)" << std::endl;
		std::cout << ">";
		std::getline(std::cin, isMajor_temp);
		transform(isMajor_temp.begin(), isMajor_temp.end(), isMajor_temp.begin(), toupper);

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
			std::cout << "�Է°��� �߸��Ǿ����ϴ�." << std::endl;
		}
	}

	printLine();

	addNode->next = NULL;

	return addNode;
}

void printLine()
{
	std::cout << "-------------------------------------" << std::endl;
}