#include "LinkedList_Score.h"
#include <iostream>
#include <string>

inline void printLine();
void capitalize(std::string& string);

//LinkedList ������
template<typename T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
	count = 0;
}

//LinkedList �Ҹ���
template<typename T>
LinkedList<T>::~LinkedList()
{
	LinkedList<T>::clear();
}

//�޴� 1: ���� �Է�
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

//�޴� 2: �Էµ� �ڷ� Ȯ��
template<typename T>
void LinkedList<T>::print()
{
	printLine();

	if (count <= 0 || head == NULL)
	{
		std::cout << "���� �Էµ� ������ �����ϴ�." << std::endl;
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
				std::cout << scanNode->value.name + "(" + std::to_string(scanNode->value.credit) + "����, ����): " + scanNode->value.gradeText << std::endl;
								
			}
			else
			{
				std::cout << scanNode->value.name << "(" << scanNode->value.credit << "����, ����): " << scanNode->value.gradeText << std::endl;
			}
			*/
			//----------------------------------------------------
			scanNode->value.Print();
			scanNode = scanNode->next;
		}
	}

	printLine();
}

//�޴� 3: ��� ��� ���
template<typename T>
void LinkedList<T>::calculate()
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
		std::cout << "���� ���� ��: " << count << std::endl << std::endl;
		std::cout << "�� �̼� ����: " << credit_all_sum << std::endl;
		std::cout << "�� �������: " << grade_all_sum / (float)credit_all_sum << std::endl << std::endl;
		std::cout << "���� �̼� ����: " << credit_major_sum << std::endl;
		std::cout << "���� �������: " << grade_major_sum / (float)credit_major_sum << std::endl;
		*/
		//----------------------------------------------------
		printLine();
	}


}

//��� ��带 ����
template<> //QUESTION: template <typename T>�� �ƴϾ��� �ǰ���
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
//���� �Է�(add�� ����)
template<class T>
Node<T>* LinkedList<T>::inputScore()
{
	Node<Score>* addNode = new Node<Score>;
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
	addNode->value.credit = atoi(value_temp.c_str());//Question : �̰� �� �ǳ�?

	//���� �Է�
	while (true)
	{
		std::cout << "- ȹ���� ����(A+, A, B ��)" << std::endl;
		std::cout << ">";
		std::getline(std::cin, gradeText_temp);
		capitalize(gradeText_temp);

		if(gradeText_temp.length()>3)
		{
			std::cout << "�Է°��� �߸��Ǿ����ϴ�." << std::endl;
		}
		else
		{
			//ù��° ���ڿ��� ���ڸ� ����(Keycode �̿�)
			addNode->value.grade = 4.0f - (gradeText_temp[0] - 'A');

			//������ F�� ���
			if (addNode->value.grade == -1.0f && gradeText_temp.length() == 1)
			{
				addNode->value.grade = 0.0f;
				addNode->value.gradeText = gradeText_temp;
				break;
			}
			//������ A���� D ������ ���
			if (addNode->value.grade < 1.0f || addNode->value.grade>4.0f)
			{
				std::cout << "�Է°��� �߸��Ǿ����ϴ�." << std::endl;
			}
			else if(gradeText_temp[1]=='+') //+�� ���� ���
			{
				addNode->value.grade += 0.5;
				addNode->value.gradeText = gradeText_temp;
				break;
			}
			else //+�� ���� ���� ���
			{
				addNode->value.gradeText = gradeText_temp;
				break;
			}
		}
	}

	//���� ���� �Է�
	while (true)
	{
		std::cout << "���� ����(Y, N)" << std::endl;
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
			std::cout << "�Է°��� �߸��Ǿ����ϴ�." << std::endl;
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
