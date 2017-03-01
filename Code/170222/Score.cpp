#include "LinkedList.h"
#include "Score.h"

void capitalize(std::string& string);
inline void printLine();

void Score::Print()
{

	printLine();
	if (this->isMajor)
	{
		std::cout << this->name + "(" + std::to_string(this->credit) + "����, ����): " + data.print(i).gradeText << std::endl;
	}
	else
	{
		std::cout << data.print(i).name + "(" + std::to_string(data.print(i).credit) + "����, ����): " + data.print(i).gradeText << std::endl;
	}
	printLine();
}

void Score::input(LinkedList<Score>& data)
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
	addNode->value.credit = atoi(value_temp.c_str());

	while (true)
	{
		std::cout << "- ȹ���� ����(A+, A, B ��)" << std::endl;
		std::cout << ">";
		std::getline(std::cin, gradeText_temp);
		capitalize(gradeText_temp);

		if (gradeText_temp.length()>3)
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
			else if (gradeText_temp[1] == '+') //+�� ���� ���
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

	addNode->next = NULL;

	data.add(addNode);

	printLine();
}

void ScoreCalculator::output(LinkedList<Score>& data)
{
	printLine();

	for (int i = 1; i < data.length() + 1; i++)
	{
		if (data.print(i).isMajor)
		{
			std::cout << data.print(i).name + "(" + std::to_string(data.print(i).credit) + "����, ����): " + data.print(i).gradeText << std::endl;
		}
		else
		{
			std::cout << data.print(i).name + "(" + std::to_string(data.print(i).credit) + "����, ����): " + data.print(i).gradeText << std::endl;
		}
	}

	printLine();
}

void ScoreCalculator::calculate(LinkedList<Score>& data)
{
	int credit_all_sum = 0;
	float grade_all_sum = 0.0f;
	int credit_major_sum = 0;
	float grade_major_sum = 0.0f;

	printLine();

	if (data.length() <= 0)
	{
		std::cout << "���� �Էµ� ������ �����ϴ�." << std::endl;
	}
	else
	{
		for (int i = 1; i < data.length() + 1; i++)
		{
			credit_all_sum += data.print(i).credit;
			grade_all_sum += data.print(i).grade * data.print(i).credit;

			if (data.print(i).isMajor)
			{
				credit_major_sum += data.print(i).credit;
				grade_major_sum += data.print(i).grade * data.print(i).credit;
			}
		}

		std::cout << "���� ���� ��: " << data.length() << std::endl << std::endl;
		std::cout << "�� �̼� ����: " << credit_all_sum << std::endl;
		std::cout << "�� �������: " << grade_all_sum / (float)credit_all_sum << std::endl << std::endl;
		std::cout << "���� �̼� ����: " << credit_major_sum << std::endl;
		std::cout << "���� �������: " << grade_major_sum / (float)credit_major_sum << std::endl;
	}

	printLine();
}

void ScoreCalculator::saveHTML(LinkedList<Score>& data, std::string fileName)
{
	std::ofstream file;
	int credit_all_sum = 0;
	float grade_all_sum = 0.0f;
	int credit_major_sum = 0;
	float grade_major_sum = 0.0f;

	printLine();

	if (data.length() <= 0)
	{
		std::cout << "���� �Էµ� ������ �����ϴ�." << std::endl;
	}
	else
	{
		file.open(fileName.c_str());

		file << "<HTML>\
			<HEAD><TITLE>����ǥ</TITLE></HEAD><BODY>����ǥ<br><br>";

		for (int i = 1; i < data.length() + 1; i++)
		{
			if (data.print(i).isMajor)
			{
				file << data.print(i).name + "(" + std::to_string(data.print(i).credit) + "����, ����): " + data.print(i).gradeText + "<br>";
			}
			else
			{
				file << data.print(i).name + "(" + std::to_string(data.print(i).credit) + "����, ����): " + data.print(i).gradeText + "<br>";
			}
		}
		file << "<br>";

		for (int i = 1; i < data.length() + 1; i++)
		{
			credit_all_sum += data.print(i).credit;
			grade_all_sum += data.print(i).grade * data.print(i).credit;

			if (data.print(i).isMajor)
			{
				credit_major_sum += data.print(i).credit;
				grade_major_sum += data.print(i).grade * data.print(i).credit;
			}
		}

		file << "���� ���� ��: " << data.length() << "<br><br>";
		file << "�� �̼� ����: " << credit_all_sum << "<br>";
		file << "�� �������: " << grade_all_sum / (float)credit_all_sum << "<br><br>";
		file << "���� �̼� ����: " << credit_major_sum << "<br>";
		file << "���� �������: " << grade_major_sum / (float)credit_major_sum << "<br>";

		file << "</BODY></HTML>";
		file.close();

		std::cout << "����ǥ�� " << fileName << "�� ����߽��ϴ�." << std::endl;
	}

	printLine();
}

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
