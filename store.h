#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

class store {
public:
	store(int, int, int, int);
	void clerk();
	int intPlayerAttack, intPlayerArmor, intPlayerHP, intPlayerMoney, intInventoryNumber;

protected:

private:

	void AddInventory(string);
	void StoreInventory();
	bool Leave;
	vector <string> StoreVector;
	
};

#endif

