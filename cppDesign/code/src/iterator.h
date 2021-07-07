#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

template <class T>
class Iterator
{
public:
	virtual bool has_next() = 0;
	virtual T next() = 0;
};

class MenuItem
{
public:
	MenuItem(string name, string description, bool vegetarain, double price):name_(name),description_(description),
		vegetarain_(vegetarain),price_(price);

	string get_name()
	{
		return name_;
	}

	string ger_description()
	{
		return description_;
	}

	double get_price()
	{
		return price_;
	}

	bool is_vegetarain()
	{
		return vegetarain_;
	}
private:
	string name_;
	string description_;
	bool vegetarain_;
	double price_;
};

class PancaKeHouseMenu 
{
public:
	PancaKeHouseMenu()
	{
		add_item("t1", "pppppp", false, 9.88);
		add_item("t2", "pppppp", false, 19.88);
		add_item("t3", "pppppp", false, 29.88);
		add_item("t4", "pppppp", false, 39.88);
	}

	void add_item(string name, string description, bool vegetarain, double price)
	{
		menulist_.push_back(MenuItem(name, description, vegetarain, price));
	}

	std::shared_ptr<PancaKeHouseMenuIterator > create_iterator()
	{
		std::shared_ptr<PancaKeHouseMenuIterator > ptr(new PancaKeHouseMenuIterator(menulist_));
		return ptr;
	}

private:
	vector<MenuItem> menulist_;
};


class PancaKeHouseMenuIterator :public Iterator<MenuItem>
{
public:
	PancaKeHouseMenuIterator(vector<MenuItem> &menus) {
		menulist_ = menus;
	};
	~PancaKeHouseMenuIterator() {};

	MenuItem next()
	{
		MenuItem menu_item = menulist_[position++];
		return menu_item;
	}

	bool has_next()
	{
		if (position >= menulist_.length())
		{
			return false;
		}
		return true;
	}

private:
	vector<MenuItem> menulist_;
	int position;
};