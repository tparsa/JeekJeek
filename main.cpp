#include "timeAndDate.hpp"
#include "id.hpp"
#include <iostream>

using namespace std;

int main()
{
	TimeAndDate tnd;
	tnd.print();
	for (int i = 0; i < 1000; i++)
	{
		ID id;
		id.print();
		cout << endl;
	}

}