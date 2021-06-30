#include <iostream>
#include "../../code/src/decorator.h"
using namespace std;




int main()
{
	CBeverage *beverage = new Espress();
	cout << beverage->getDescription() << "   price:" << beverage->cost() << endl;
	beverage = new Mocha(beverage);
	cout << "desc:" << beverage->getDescription() << "   price:" << beverage->cost() << endl;
	beverage = new Mocha(beverage);
	cout << "desc:" << beverage->getDescription() << "   price:" << beverage->cost() << endl;

}