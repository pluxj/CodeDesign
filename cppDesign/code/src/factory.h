#include <string>
#include <iostream>
#include <pthread.h>
using namespace std;

class Pizza
{
public:
    virtual void prepare() = 0;
    virtual void bake() = 0;
    virtual void cut() = 0;
    virtual void box() = 0;
};

//具体的实现类,可满足不同风格披萨店的披萨
class ChesePizza : public Pizza
{
public:
    PizzaIngredientFactory *ingredient_factory_;
    ChesePizza(PizzaIngredientFactory *ingredient_factory):ingredient_factory_(ingredient_factory) {}
    virtual void prepare()
    {
        cout << "ChesePizza prepare." << endl;
    }
    virtual void bake()
    {
        cout << "ChesePizza bake." << endl;
    }
    virtual void cut()
    {
        cout << "ChesePizza cut." << endl; 
    }
    virtual void box()
    {
        cout << "ChesePizza box." << endl;
    }
}

class ClamPizza : public Pizza
{
public:
    PizzaIngredientFactory *ingredient_factory_;
    ClamPizza(PizzaIngredientFactory *ingredient_factory):ingredient_factory_(ingredient_factory) {}
    //使用原料工厂的原料来生产需要的披萨
    virtual void prepare()
    {
        cout << "ClamPizza prepare." << endl;
    }

    virtual void bake()
    {
        cout << "ClamPizza bake." << endl;
    }

    virtual void cut()
    {
        cout << "ClamPizza cut." << endl;
    }
    virtual void box()
    {
        cout << "ClamPizza box." << endl;
    }
}

//PizzaStore 实现 orderPizza / createPizza 接口
//在接口里 依赖 原料工厂, 调用具体的Pizza 类，比如 新西兰口味pizza，纽约口味pizza
class PizzaStore
{
public:
    virtual void orderPizza() = 0;
    virtual void createPizza() = 0;
}

//实现多种类型的 Pizza 店，比如纽约披萨店，新西兰披萨店
//具体工厂
class SimpleFactory
{
	Pizza* createPizza(string strType)
	{
		Pizza *pizza = nullptr;
		if (strType == "cheese") {
			new ChesePizza();
		}
        else if(strType == "ClamPizza "){
            new ClamPizza();
        }
        else{
            return nullptr;
        }
	}
};
//原料工厂
//抽象工厂
class PizzaIngredientFactory
{
    
}
