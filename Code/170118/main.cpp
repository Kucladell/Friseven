#include "stdafx.h"

//main
int main(void)
{
	LinkedList<Score> data;
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
			case 1: //메뉴 1: 성적 입력
			{
				//----------------------------------------------------
				//data.add();
				//----------------------------------------------------
				break;
			}
			case 2: //메뉴 2: 입력된 자료 확인
			{
				data.print();
				break;
			}
			case 3: //메뉴 3: 계산 결과 출력
			{
				data.calculate();
				break;
			}
			case 4: //메뉴 4: 종료
			{
				exit = true;
				break;
			}
			default:
			{
				std::cout << "잘못된 명령어입니다." << std::endl;
			}
		}
	}

	return 0;
}

//메뉴
std::string menu()
{
	std::string selected;

	std::cout << "--메 뉴------------------------------" << std::endl;
	std::cout << "명령에 해당하는 숫자를 입력하십시오." << std::endl;
	std::cout << "1. 성적 입력" << std::endl;
	std::cout << "2. 입력된 자료 확인" << std::endl;
	std::cout << "3. 계산 결과 출력" << std::endl;
	std::cout << "4. 종료" << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	std::cout << ">";
	std::getline(std::cin, selected);

	return selected;
}
