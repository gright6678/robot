#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include "store.h"
#include "adventure.h"
#include "robot.h"

using namespace std;

adventure::adventure(int a, int b, int c, int d, int e)
: intPlayerAttack(a), intPlayerArmor(b), intPlayerMoney(c), intPlayerHP(d), intTurn(e)
{}

void adventure::StoreVisit() {
	
	store storeObj(intPlayerAttack, intPlayerArmor, intPlayerMoney, intPlayerHP);
			
	storeObj.clerk();
	
	//receive all variables from adventure class
	intPlayerAttack= storeObj.intPlayerAttack;
	intPlayerArmor= storeObj.intPlayerArmor;
	intPlayerMoney= storeObj.intPlayerMoney;
	intPlayerHP= storeObj.intPlayerHP;
	
}

void adventure::begin()
{

	//create the random variable
	srand(time(0));
	int random = rand() % 6;
	
	//the first intTurnsets the scene and gives the player a sword
	if (intTurn == 1) {
	
		cout << "You are stuck in an abandoned city that you once called home before it was taken over by robots.\nThese robots once helped you with every aspect of your life but their incredibly AI programming has allowed them take over the city and killed your family and friends.\nYou must escape the city and get help before they destroy you, too.\n\nYou encounter your old robot that you built yourself when you were young. He says, \"It's dangerous to go alone! Take this.\" and then mysteriously powers down.\nYou have recieved a sword.\n" << endl;
		
		//the sword gives the player an extra 5 intPlayerAttackpoints
		intPlayerAttack += 5;
		
	//the second intTurnforces a battle
	} else if (intTurn == 2) {
		
		battle();
		
	} else if ((intTurn % 5) == 0) {
		
		StoreVisit();
		
	} else {
		
		//use the random variable to decide whether the player should go into battle or be lost
		system ("clear");
		if (random < 3) {
			battle();
		} else if (random >= 3) {
			lost();
		}
	
	}
	
}

void adventure::battle() {

	//gives the player a chance to battle some weaker robots
	if (intTurn < 10) {
		
		cout << "You encounter a field of tiny robots. You recognize them to be cleaning robots that worked in your apartment building. They do not have much power or strong defenses. However, they seem to be giving off electrical surges. What do you do?\n" << endl;
		
		robot WeakRobot(5,5,10);
		
		WeakRobot.Fighter(intPlayerAttack, intPlayerArmor, intPlayerHP);
		
		intPlayerHP = WeakRobot.intPlayerHP;
		
		if (intPlayerHP <= 0) {
			
			system ("clear");
			//cout << ":::::GAME OVER:::::" << endl;

		} else {
		
			cout << "You have defeated the robot and gathered $15 worth in scrap to trade" << endl << endl;
			intPlayerMoney += 15;
	
		}
			
		
	} else if (intTurn >= 20) {
		
		cout << "You encoutner a large robot" << endl;
		
		robot LargeRobot(70,70,90);
		
		LargeRobot.Fighter(intPlayerAttack, intPlayerArmor, intPlayerHP);
		
		intPlayerHP = LargeRobot.intPlayerHP;
		
		if (intPlayerHP <= 0) {
			
			system ("clear");
			//cout << ":::::GAME OVER:::::" << endl << endl;

		} else {
			
			cout << "You have defeated the robot and gathered $40 worth in scrap to trade" << endl << endl;
			intPlayerMoney += 40;
		
		}

	} else if (intTurn >= 10) {
		
		cout << "You encounter a stronger robot" << endl;
		
		robot StrongRobot(10,10,20);
		
		StrongRobot.Fighter(intPlayerAttack, intPlayerArmor, intPlayerHP);
		
		intPlayerHP = StrongRobot.intPlayerHP;
		
		if (intPlayerHP <= 0) {
			
			system ("clear");
			//cout << ":::::GAME OVER:::::" << endl;

		} else {
			
			cout << "You have defeated the robot and gathered $30 worth in scrap to trade" << endl << endl;
		intPlayerMoney += 30;
		}
	}

}

void adventure::lost() {

	cout << "You are travelling through the abandoned city and you are lost" << endl;
		cout << "You find your way out" << endl;
		
}
