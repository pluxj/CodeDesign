#include <iostream>
#include "../../code/src/observe.h"

int main()
{
	WeatherData w;

	PersonObservers *p = new PersonObservers;
	BusinessObserves *b = new BusinessObserves;
	CoderObservers *c = new CoderObservers;

	w.registerObserver(p);
	
	w.notifyObserver();

	w.registerObserver(b);
	w.notifyObserver();

	w.registerObserver(c);
	w.notifyObserver();


	w.removeObserver(p);
	w.removeObserver(b);
	w.removeObserver(c);

	delete p;
	delete b;
	delete c;
}

