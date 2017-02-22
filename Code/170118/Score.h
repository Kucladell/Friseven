#pragma once

#include <iostream>
#include <string>

struct Score
{
	std::string name;
	int credit;
	float grade;
	std::string gradeText;
	bool isMajor;
	//----------------------------------------------------
	void Print();
	//----------------------------------------------------
};