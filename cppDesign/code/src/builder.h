//
// Created by fcg on 2021/1/11.
//

#ifndef CPPDESIGNMODEL_BUILDER_H
#define CPPDESIGNMODEL_BUILDER_H

#include <string>
#include <List>
#include <iostream>

class Packing;

class Item {
public:
    virtual ~Item() {}

    virtual std::string name(void) = 0;

    virtual Packing *packing(void) = 0;

    virtual float price(void) = 0;
};

class Packing {
public:
    virtual ~Packing() {}

    virtual std::string pack(void) = 0;
};

class Wrapper : public Packing {
public:
    std::string pack(void) override {
        return "Wrapper";
    }
};

class Bottle : public Packing {
public:
    std::string pack(void) override {
        return "Bottle";
    }
};

class Burger : public Item {
public:
    virtual Packing *packing() override {
        return new Wrapper();
    }

    float price() override = 0;

    std::string name() override = 0;
};

class ColdDrink : public Item {
public:
    Packing *packing() override {
        return new Bottle();
    }
};

class VegBurger : public Burger {
public:
    float price() override {
        return 25.0f;
    }

    std::string name() override {
        return "Veg Burger";
    }
};

class ChickenBurger : public Burger {
public:
    float price() override {
        return 50.5f;
    }

    std::string name() {
        return "Chicken Burger";
    }
};

class Coke : public ColdDrink {
public:
    float price() override {
        return 30.5f;
    }

    std::string name() {
        return "Coke";
    }
};

class Pepsi : public ColdDrink {
public:
    float price() override {
        return 35.0f;
    }

    std::string name() {
        return "Pepsi";
    }
};

class Meal {
public:
    std::list<Item *> *items = new std::list<Item *>();

    void addItem(Item *item) {
        items->push_back(item);
    }

    float getCost() {
        float cost = 0.0f;
        std::list<Item *>::iterator iter = items->begin();
//        auto iter = items->begin();
        for (; iter != items->end(); ++iter) {
            cost += (*iter)->price();
        }
        return cost;
    }

    void showItems() {
        for (Item *i : *items) {
            std::cout << "Item : " << i->name();
            std::cout << ", Packing : " << i->packing()->pack();
            std::cout << ", Price : " << i->price() << std::endl;
        }
    }
};

class MealBuilder {
public:
    Meal *prepareVegMeal() {
        Meal *meal = new Meal();
        meal->addItem(new VegBurger);
        meal->addItem(new Coke);
        return meal;
    }

    Meal *prepareNonVegMeal() {
        Meal *meal = new Meal();
        meal->addItem(new ChickenBurger());
        meal->addItem(new Pepsi());
        return meal;
    }
};

class BuilderPatternDemo {
public:
    void printfMeal() {
        MealBuilder *mealBuilder = new MealBuilder();
        Meal *vegMeal = mealBuilder->prepareVegMeal();
        std::cout << "Veg Meal" << std::endl;
        vegMeal->showItems();
        std::cout << "Total Cost: " << vegMeal->getCost() << std::endl;

        Meal *nonVegMeal = mealBuilder->prepareNonVegMeal();
        std::cout << "Non-Veg Meal" << std::endl;
        nonVegMeal->showItems();
        std::cout << "Total Cost: " << nonVegMeal->getCost() << std::endl;
    }

};

#endif //CPPDESIGNMODEL_BUILDER_H
