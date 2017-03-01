#include "stdafx.h"

std::string menu();

//main
int main(void)
{
	LinkedList<int> data;
	std::list<Score> data2;
	data2.push_back();
	std::string command;
	bool exit = false;
	std::string name;
	int credit;
	float grade;
	std::string gradeText;
	bool isMajor;



	while (!exit)
	{
		ScoreCalculator calc;
		command = menu();
		int command_int = atoi(command.c_str());

		if (command_int < 0)
		{
			command_int = 0;
		}
		switch (command_int)
		{
			case 1: //�޴� 1: ���� �Է�
			{
				Node<Score>* addnode = new Node<Score>();
				addnode->value = *Score::input("3", 3, 2, "A+", true);
				data.add(addnode);
				calc.input(data);
				break;
			}
			case 2: //�޴� 2: �Էµ� �ڷ� Ȯ��
			{
				calc.output(data);
				break;
			}
			case 3: //�޴� 3: ��� ��� ���
			{
				calc.calculate(data);
				break;
			}
			case 4: //�޴� 4: ��� ��� ����
			{
				calc.saveHTML(data, "result.html");
			}
			case 5: //�޴� 4: ����
			{
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

//�޴�
std::string menu()
{
	std::string selected;

	std::cout << "--�� ��------------------------------" << std::endl;
	std::cout << "��ɿ� �ش��ϴ� ���ڸ� �Է��Ͻʽÿ�." << std::endl;
	std::cout << "1. ���� �Է�" << std::endl;
	std::cout << "2. �Էµ� �ڷ� Ȯ��" << std::endl;
	std::cout << "3. ��� ��� ���" << std::endl;
	std::cout << "4. ��� ��� ����" << std::endl;
	std::cout << "5. ����" << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	std::cout << ">";
	std::getline(std::cin, selected);

	return selected;
}