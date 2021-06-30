#include <string>
#include <iostream>
#include <vector>
using namespace std;

class CObservers
{
public:
	CObservers() {}
	~CObservers() {}
	virtual void update() = 0;
};

class PersonObservers :public CObservers
{
public:
	PersonObservers() {}
	~PersonObservers() {}

	virtual void update()
	{
		cout << "this is person observer for update." << endl;
	}
};


class BusinessObserves : public CObservers
{
public:
	BusinessObserves() {}
	~BusinessObserves() {}

	virtual void update()
	{
		cout << "this is business observer for update." << endl;
	}
};

class CoderObservers :public CObservers
{
public:
	CoderObservers() {}
	~CoderObservers() {}

	virtual void update()
	{
		cout << "this is coder observer for update." << endl;
	}
};

class WeatherData
{
public:
	WeatherData()
	{
	}
	~WeatherData() {}
	void registerObserver(CObservers *o) {
		observers_.push_back(o);
	}
	void removeObserver(CObservers *o) {
		std::vector<CObservers*>::iterator iter = observers_.begin();
		for (; iter != observers_.end(); iter++) {
			if (*iter != o)
			{
				iter = observers_.erase(iter);
			}
		}
	}
	void notifyObserver()
	{
		for (std::vector<CObservers*>::iterator iter = observers_.begin(); iter != observers_.end(); iter++)
		{
			(*iter)->update();
		}
	}
private:
	std::vector<CObservers*> observers_;

};
