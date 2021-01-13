#include <iostream>
#include "../../code/src/command.h"



int main()
{

	//COMMAND DESIGN
	CLight light;
	CLightOnCommand lightCommand(&light);
	CButton button;
	button.SetCommand(&lightCommand);
	button.Press();
	//system("pause");
}