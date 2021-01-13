#include "State.h"
#include <iostream>
using namespace std;

int GumballMachine::SOLD_OUT = 0;
int GumballMachine::NO_QUARTER = 1;
int GumballMachine::HAS_QUARTER = 2;
int GumballMachine::SOLD = 3;

GumballMachine::GumballMachine(int number_gumball) : count_(number_gumball)
{
	soldOutState = new SoldOutState(this);
	soldState = new SoldState(this);
	noQuaterState = new NoQuaterState(this);
	hasQuaterState = new HasQuaterState(this);
	if (count_ > 0)
		state_ = noQuaterState;
}

void GumballMachine::releaseBall()
{
	cout << "a gumball comes rolling out the slot" << endl;
	if (count_ != 0)
		count_ -= 1;
}


//SoldState
void SoldState::insertQuarter()
{
	cout << "please wait ,we're already giving you a gumball" << endl;
}

void SoldState::ejectQuarter()
{
	cout << "you alreay turned the crank" << endl;
}

void SoldState::turnCrank()
{
	cout << "turing twice doesn't get you another gumball" << endl;
}

void SoldState::dispense()
{
	gumballmachine->releaseBall();
	if (gumballmachine->get_count() > 0)
	{
		gumballmachine->set_state(gumballmachine->NO_QUARTER);
	}
	else
	{
		gumballmachine->set_state(gumballmachine->SOLD_OUT);
	}
}

//SoldOutState
void SoldOutState::insertQuarter()
{
	cout << "sorry don't have gumball" << endl;
}

void SoldOutState::ejectQuarter()
{
	cout << "you haven't inserted a quater" << endl;
}

void SoldOutState::turnCrank()
{
	cout << "sorry don't have gumball" << endl;
}

void SoldOutState::dispense()
{
	cout << "sorry don't have gumball" << endl;
}


//NoQuaterState
void NoQuaterState::insertQuarter()
{
	cout << "insert a quarter" << endl;
	gumballmachine->set_state(gumballmachine->HAS_QUARTER);

}

void NoQuaterState::ejectQuarter()
{
	cout << "you haven't inserted a quater" << endl;
}

void NoQuaterState::turnCrank()
{
	cout << "you turned,but there's no quarter" << endl;
}

void NoQuaterState::dispense()
{
	cout << "you need to pay first" << endl;
}


//HasQuaterState
void HasQuaterState::insertQuarter()
{
	cout << "you can't insert another quarter" << endl;
}

void HasQuaterState::ejectQuarter()
{
	cout << "quarter returned" << endl;
	gumballmachine->set_state(gumballmachine->NO_QUARTER);
}

void HasQuaterState::turnCrank()
{
	cout << "you turned" << endl;
	gumballmachine->set_state(gumballmachine->SOLD);
}

void HasQuaterState::dispense()
{
	cout << "no gumball dispensed" << endl;
}