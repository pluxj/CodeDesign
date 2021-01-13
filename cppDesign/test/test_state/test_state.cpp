// code_design.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "../../code/src/State.h"
int main()
{
	GumballMachine gumball{ 4 };
	gumball.insertQuarter();
	gumball.turnCrank();
	gumball.dispense();

	gumball.insertQuarter();
	gumball.turnCrank();
	gumball.dispense();

	gumball.insertQuarter();
	gumball.turnCrank();
	gumball.dispense();

	gumball.insertQuarter();
	gumball.turnCrank();
	gumball.dispense();

	gumball.insertQuarter();
	gumball.turnCrank();
	gumball.dispense();

}


