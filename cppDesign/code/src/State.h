#pragma once
class GumballMachine;

class State
{
public:
	State() {}
	virtual ~State() {}
	//投币
	virtual void insertQuarter() = 0;
	//退币
	virtual void ejectQuarter() = 0;
	//转动曲轴
	virtual void turnCrank() = 0;
	//发糖
	virtual void dispense() = 0;

	GumballMachine *gumballmachine;
};

class GumballMachine
{
public:
	GumballMachine(int number_gumball);
	static int SOLD_OUT;
	static int NO_QUARTER;
	static int HAS_QUARTER;
	static int SOLD;
	//投币
	void insertQuarter()
	{
		state_->insertQuarter();
	}
	//退币
	void ejectQuarter()
	{
		state_->ejectQuarter();
	}
	//转动曲轴
	void turnCrank()
	{
		state_->turnCrank();
	}
	//发糖
	void dispense()
	{
		state_->dispense();
	}

	void releaseBall();

	void set_state(int gumball_state)
	{
		switch (gumball_state)
		{
		case 0:
			state_ = soldOutState;
			break;
		case 1:
			state_ = noQuaterState;
			break;
		case 2:
			state_ = hasQuaterState;
			break;
		case 3:
			state_ = soldState;
			break;
		default:
			break;
		}
	}

	State* get_state()
	{
		return state_;
	}



	int get_count()
	{
		return count_;
	}
private:
	State *soldOutState;
	State *noQuaterState;
	State *hasQuaterState;
	State *soldState;

	State * state_;
	int count_;
};







class SoldState :public State
{
public:
	SoldState(GumballMachine* gbm)
	{
		gumballmachine = gbm;
	}
	virtual ~SoldState() {}
	void insertQuarter();
	void ejectQuarter();
	void turnCrank();
	void dispense();
};

class SoldOutState :public State
{
public:
	SoldOutState(GumballMachine* gbm)
	{
		gumballmachine = gbm;
	}

	virtual ~SoldOutState() {}
	void insertQuarter();
	void ejectQuarter();
	void turnCrank();
	void dispense();
};

class NoQuaterState :public State
{
public:
	NoQuaterState(GumballMachine* gbm)
	{
		gumballmachine = gbm;
	}

	virtual ~NoQuaterState() {}
	void insertQuarter();
	void ejectQuarter();
	void turnCrank();
	void dispense();

};

class HasQuaterState :public State
{
public:
	HasQuaterState(GumballMachine* gbm)
	{
		gumballmachine = gbm;
	}

	virtual ~HasQuaterState() {}
	void insertQuarter();
	void ejectQuarter();
	void turnCrank();
	void dispense();
};





