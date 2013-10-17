#include "store.h"
#include "adventure.h"

store::store(int a, int b, int c, int d)
: intPlayerAttack(a), intPlayerArmor(b), intPlayerMoney(c), intPlayerHP(d) {
	cout << "Clerk: Hello, Sir. Welcome to my store" << endl << endl;
}

void store::clerk() {
	
	int BuySell, OPTION;
	Leave = false;
	
	do {

		try {

			cout << "1. Talk to the clerk" << endl;
			cout << "2. Leave" << endl;
			cin >> OPTION;
			
			switch (OPTION) {
				
				case 1:
					system ("clear");
					cout << "Clerk: Are you here to buy items or sell something?" << endl << endl;
					cout << "1. Buy" << endl;
					cout << "2. Sell" << endl;
					cin >> BuySell;
					
					switch (BuySell) {
					
						case 1:
							system ("clear");
							StoreInventory();
							break;
							
						case 2:
							//Inventory
							break;
						
						default:
							system ("clear");
							throw 0;
							break;
					}
					break;
				
				case 2:
				
					system ("clear");
					Leave = true;
					break;
					
				default:
				
					system ("clear");
					throw 0;
					
			}
		
		} catch (...) {
		
			system ("clear");
			cout << "Clerk: I'm sorry, I don't understand" << endl << endl;
			
		}
	
	} while (Leave == false);
	
	cout << "Clerk: Thank you, come again" << endl << endl;
	
}

void store::StoreInventory() {
	
	int intSelectedItem;
	
	cout << "Player Money: $" << intPlayerMoney << endl << endl;
	
	try {
		
		//Print out all of the items in the StoreVector
		for (unsigned int x = 0; x < StoreVector.size(); x++) {
			
			intInventoryNumber = x + 1;
			
			cout << intInventoryNumber << ". " << StoreVector[x] << endl;
			
		}
		
		cout << "1. Shield - $30" << endl;
		cout << "2. Double Handed Sword - $30" << endl;
		cout << "3. First Aid Kit - $10" << endl;
		cout << "4. Leave" << endl;
		cin >> intSelectedItem;
		
		switch (intSelectedItem) {
			
			case 1:
				
				system ("clear");
				if (intPlayerMoney >= 30) {
					intPlayerArmor+= 5;
					intPlayerMoney-= 30;
					cout << "Shield Purchased\nPlayer Money: $" << intPlayerMoney << endl << endl;
					StoreVector.clear();
					AddInventory("Double Handed Sword");
					AddInventory("First Aid Kit");
					
				} else {
					system ("clear");
					cout << "You cannot afford this item" << endl;
				}
				break;
			case 2:
				
				system ("clear");
				if (intPlayerMoney >= 30) {
					intPlayerAttack+= 10;
					intPlayerMoney-= 30;
					cout << "Double Handed Sword Purchased\nPlayer Money: $" << intPlayerMoney << endl << endl;
					StoreVector.clear();
					AddInventory("Sheild");
					AddInventory("First Aid Kit");
				} else {
					system ("clear");
					cout << "You cannot afford this item" << endl;
				}
				
				break;
			case 3:
				
				system ("clear");
				if (intPlayerMoney >= 10) {
					intPlayerHP += 10;
					intPlayerMoney -= 10;
					cout << "First Aid Kit Purchased\nPlayer Money: $" << intPlayerMoney << endl << endl;
					StoreVector.clear();
					AddInventory("Sheild");
					AddInventory("Double Handed Sword");
					AddInventory("First Aid Kit");
				} else {
					system ("clear");
					cout << "You cannot afford this item" << endl;
				}
				break;
			case 4: {
				system ("clear");
				Leave = true;
				break;
			}
			default:
				throw 0;
				break;
		}
		
	} catch (...) {
		
		system ("clear");
		cout << "Clerk: I'm sorry I don't understand" << endl << endl;
		
	}
	
}

//Add inventory to the Store
void store::AddInventory(string newItem) {

	StoreVector.push_back(newItem);

}

int store::getAttack() {
	return intPlayerAttack;
}

int store::getArmor() {
	return intPlayerArmor;
}

int store::getMoney() {
	return intPlayerMoney;
}

int store::getHP() {
	return intPlayerHP;
}