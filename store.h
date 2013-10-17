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
	int getAttack();
	int getArmor();
	int getMoney();
	int getHP();

protected:

private:
	int intPlayerAttack, intPlayerArmor, intPlayerHP, intPlayerMoney, intInventoryNumber;
	void AddInventory(string);
	void StoreInventory();
	bool Leave;
	vector <string> StoreVector;
	
};

#endif

