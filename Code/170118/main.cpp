#include <iostream>
#include <string>
#include "LinkedList_Score.h"



//�޴�
std::string menu()
{
	std::string selected;

	std::cout << "--�� ��------------------------------" << std::endl;
	std::cout << "��ɿ� �ش��ϴ� ���ڸ� �Է��Ͻʽÿ�." << std::endl;
	std::cout << "1. ���� �Է�" << std::endl;
	std::cout << "2. �Էµ� �ڷ� Ȯ��" << std::endl;
	std::cout << "3. ��� ��� ���" << std::endl;
	std::cout << "4. ����" << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	std::cout << ">";
	std::cin >> selected;

	return selected;
}

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
	Node* addNode = new Node;
	Node* scanNode;
	std::string gradeText_temp;
	char isMajor_temp;

	if (head == NULL)
	{
		std::cout << "--�� ���� �Է�-----------------------" << std::endl;

		std::cout << "- �����" << std::endl;
		std::cout << ">";
		std::cin >> addNode->value.name;

		std::cout << "- ����(1����, 2����, 3���� ��)" << std::endl;
		std::cout << ">";
		std::cin >> addNode->value.credit;

		std::cout << "- ȹ���� ����(A+, A, B ��)" << std::endl;
		std::cout << ">";
		std::cin >> gradeText_temp;

		if (gradeText_temp == "A+")
		{
			addNode->value.grade = 4.5;
			addNode->value.gradeText = "A+";
		}
		else if (gradeText_temp == "A")
		{
			addNode->value.grade = 4;
			addNode->value.gradeText = "A";
		}
		else if (gradeText_temp == "B+")
		{
			addNode->value.grade = 3.5;
			addNode->value.gradeText = "B+";
		}
		else if (gradeText_temp == "B")
		{
			addNode->value.grade = 3;
			addNode->value.gradeText = "B";
		}
		else if (gradeText_temp == "C+")
		{
			addNode->value.grade = 2.5;
			addNode->value.gradeText = "C+";
		}
		else if (gradeText_temp == "C")
		{
			addNode->value.grade = 2;
			addNode->value.gradeText = "C";
		}
		else if (gradeText_temp == "D+")
		{
			addNode->value.grade = 1.5;
			addNode->value.gradeText = "D+";
		}
		else if (gradeText_temp == "D")
		{
			addNode->value.grade = 1;
			addNode->value.gradeText = "D";
		}
		else if (gradeText_temp == "F")
		{
			addNode->value.grade = 0;
			addNode->value.gradeText = "F";
		}
		else
		{
			while (true)
			{
				std::cout << "�Է°��� �߸��Ǿ����ϴ�. ������ �ٽ� �Է��Ͻʽÿ�." << std::endl;
				std::cout << "(A+, A, B+, B, C+, C, D+, D, F)" << std::endl;
				std::cout << ">";
				std::cin >> gradeText_temp;

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
			}
		}

		std::cout << "���� ����(Y, N)" << std::endl;
		std::cout << ">";
		std::cin >> isMajor_temp;

		if (isMajor_temp == 'Y' || isMajor_temp == 'y')
		{
			addNode->value.isMajor = true;
		}
		else if (isMajor_temp == 'N' || isMajor_temp == 'n')
		{
			addNode->value.isMajor = false;
		}
		else
		{
			while (true)
			{
				std::cout << "�Է°��� �߸��Ǿ����ϴ�. ���� ���θ� �ٽ� �Է��Ͻʽÿ�." << std::endl;
				std::cout << "(Y, N)" << std::endl;
				std::cout << ">";
				std::cin >> isMajor_temp;

				if (isMajor_temp == 'Y' || isMajor_temp == 'y')
				{
					addNode->value.isMajor = true;
					break;
				}
				else if (isMajor_temp == 'N' || isMajor_temp == 'n')
				{
					addNode->value.isMajor = false;
					break;
				}
			}
		}

		std::cout << "-------------------------------------" << std::endl;

		addNode->next = NULL;
		head = addNode;
	}
	else
	{
		scanNode = head;
		while (scanNode->next != NULL)
		{
			scanNode = scanNode->next;
		}

		std::cout << "--�� ���� �Է�-----------------------" << std::endl;

		std::cout << "- �����" << std::endl;
		std::cout << ">";
		std::cin >> addNode->value.name;

		std::cout << "- ����(1����, 2����, 3���� ��)" << std::endl;
		std::cout << ">";
		std::cin >> addNode->value.credit;

		std::cout << "- ȹ���� ����(A+, A, B ��)" << std::endl;
		std::cout << ">";
		std::cin >> gradeText_temp;

		if (gradeText_temp == "A+")
		{
			addNode->value.grade = 4.5;
			addNode->value.gradeText = "A+";
		}
		else if (gradeText_temp == "A")
		{
			addNode->value.grade = 4;
			addNode->value.gradeText = "A";
		}
		else if (gradeText_temp == "B+")
		{
			addNode->value.grade = 3.5;
			addNode->value.gradeText = "B";
		}
		else if (gradeText_temp == "B")
		{
			addNode->value.grade = 3;
			addNode->value.gradeText = "B";
		}
		else if (gradeText_temp == "C+")
		{
			addNode->value.grade = 2.5;
			addNode->value.gradeText = "C+";
		}
		else if (gradeText_temp == "C")
		{
			addNode->value.grade = 2;
			addNode->value.gradeText = "C";
		}
		else if (gradeText_temp == "D+")
		{
			addNode->value.grade = 1.5;
			addNode->value.gradeText = "D+";
		}
		else if (gradeText_temp == "D")
		{
			addNode->value.grade = 1;
			addNode->value.gradeText = "D";
		}
		else if (gradeText_temp == "F")
		{
			addNode->value.grade = 0;
			addNode->value.gradeText = "F";
		}
		else
		{
			while (true)
			{
				std::cout << "�Է°��� �߸��Ǿ����ϴ�. ������ �ٽ� �Է��Ͻʽÿ�." << std::endl;
				std::cout << "(A+, A, B+, B, C+, C, D+, D, F)" << std::endl;
				std::cout << ">";
				std::cin >> gradeText_temp;

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
					addNode->value.gradeText = "B";
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
			}
		}

		std::cout << "���� ����(Y, N)" << std::endl;
		std::cout << ">";
		std::cin >> isMajor_temp;

		if (isMajor_temp == 'Y' || isMajor_temp == 'y')
		{
			addNode->value.isMajor = true;
		}
		else if (isMajor_temp == 'N' || isMajor_temp == 'n')
		{
			addNode->value.isMajor = false;
		}
		else
		{
			while (true)
			{
				std::cout << "�Է°��� �߸��Ǿ����ϴ�. ���� ���θ� �ٽ� �Է��Ͻʽÿ�." << std::endl;
				std::cout << "(Y, N)" << std::endl;
				std::cout << ">";
				std::cin >> isMajor_temp;

				if (isMajor_temp == 'Y' || isMajor_temp == 'y')
				{
					addNode->value.isMajor = true;
					break;
				}
				else if (isMajor_temp == 'N' || isMajor_temp == 'n')
				{
					addNode->value.isMajor = false;
					break;
				}
			}
		}

		std::cout << "-------------------------------------" << std::endl;

		addNode->next = NULL;
		scanNode->next = addNode;
	}

	count++;
}

//�޴� 2: �Էµ� �ڷ� Ȯ��
void LinkedList::print()
{
	std::cout << "-------------------------------------" << std::endl;

	if (count <= 0)
	{
		std::cout << "���� �Էµ� ������ �����ϴ�." << std::endl;
		return;
	}
	else if(head == NULL)
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

	std::cout << "-------------------------------------" << std::endl;
}

//�޴� 3: ��� ��� ���
void LinkedList::calculate()
{
	int credit_all_sum = 0;
	float grade_all_sum = 0.0f;
	int credit_major_sum = 0;
	float grade_major_sum = 0.0f;

	if (count <= 0)
	{
		std::cout << "���� �Էµ� ������ �����ϴ�." << std::endl;
	}
	else if(head == NULL)
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

		std::cout << "-------------------------------------" << std::endl;
		std::cout << "���� ���� ��: " << count << std::endl << std::endl;
		std::cout << "�� �̼� ����: " << credit_all_sum << std::endl;
		std::cout << "�� �������: " << grade_all_sum / (float)credit_all_sum << std::endl << std::endl;
		std::cout << "���� �̼� ����: " << credit_major_sum << std::endl;
		std::cout << "���� �������: " << grade_major_sum / (float)credit_major_sum << std::endl;
		std::cout << "-------------------------------------" << std::endl;
	}


}

//clear �Լ�
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

	//QUESTION: ���⿡�� ������ �Լ��� ȣ���ص� �Ǵ°�
}

//main
//QUESTION: �� main�� �� ���� �ø��� ������ ���°�
int main(void)
{
	LinkedList data;
	int data_count = 0;
	std::string command;
	bool exit = false;

	while (!exit)
	{
		command = menu();
		int command_int = atoi(command.c_str());
		if (command_int < 0)
		{
			command_int = 0;
		}
		switch (command_int)
		{
			case 1:
			{
				data.add();
				break;
			}
			case 2:
			{
				data.print();
				break;
			}
			case 3:
			{
				data.calculate();
				break;
			}
			case 4:
			{
				//�޴� 4: ����
				exit = true;
				break;
			}
			default:
			{
				std::cout << "�߸��� ��ɾ��Դϴ�." << std::endl;
			}
		}
	}

	return 0;
}
