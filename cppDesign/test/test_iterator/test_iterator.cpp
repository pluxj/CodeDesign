#include <iostream>
#include "../../code/src/iterator.h"
using namespace std;




int main()
{
	PancaKeHouseMenu menu;
	std::shared_ptr<PancaKeHouseMenuIterator> it(menu.create_iterator());

	while (it->has_next())
	{
		MenuItem obj = it->next();
		cout << "name :" << obj.get_name() << ", description:" << obj.ger_description() << ", price:" << obj.get_price() << endl;
	}


}