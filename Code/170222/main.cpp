#include "stdafx.h"

std::string menu();

//main
int main(void)
{
	LinkedList<Score> data;
	std::string command;
	bool exit = false;

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
			case 1: //메뉴 1: 성적 입력
			{
				calc.input(data);
				break;
			}
			case 2: //메뉴 2: 입력된 자료 확인
			{
				calc.output(data);
				break;
			}
			case 3: //메뉴 3: 계산 결과 출력
			{
				calc.calculate(data);
				break;
			}
			case 4: //메뉴 4: 계산 결과 저장
			{
				calc.saveHTML(data, "result.html");
			}
			case 5: //메뉴 4: 종료
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
	std::cout << "4. 계산 결과 저장" << std::endl;
	std::cout << "5. 종료" << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	std::cout << ">";
	std::getline(std::cin, selected);

	return selected;
}