#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include "store.h"
#include "adventure.h"
#include "robot.h"

using namespace std;

robot::robot(int a, int b, int c)
: intRobotAttack(a), intRobotArmor(b), intRobotHP(c)
{}

void robot::Fighter(int a, int b, int c) {
	
	intPlayerAttack = a;
	intPlayerArmor = b;
	intPlayerHP = c;

	while (intRobotHP > 0 && intPlayerHP > 0) {

		int AttackRun;
		
		try {
				
				//ask the player what they want to do
				cout << "1. Attack" << endl;
				cout << "2. Run" << endl;
				cin >> AttackRun;
			
			
				switch (AttackRun) {
					
					//attack
					case 1: {
						system ("clear");
			
						cout << "You strike the robots" << endl << endl;
						
						//calculate how much damage the player takes along with the robot
						intRobotHP = WinLose(intPlayerAttack, intPlayerArmor, intRobotAttack, intRobotArmor, intRobotHP);
					
						break; }
					
					//run
					case 2: {
						
						//decide whether the player is allowed to run or not
						if (intPlayerArmor > 10) {
			
								cout << "You escape easily\n" << endl << endl;
								//ends turn and returns to menu()
								int RobotHP = 0; //break the while loop
								
						} else {
							
							cout << "You cannot escape you must fight them!\n" << endl << endl;
			
						}
						break; }
				
					default: {
						
						throw 0;
			
						break; }
					
				}
		
		} catch (...) {
		
			system ("clear");
			cout << "ERROR: Invalid Input" << endl << endl;
			
		}
	
	}


}

int robot::WinLose(int intPlayerAttack, int intPlayerArmor, int intRobotAttack, int intRobotArmor, int intRobotHP) {

	
	if (intRobotArmor >= intPlayerAttack) {
		intRobotHP -= (intPlayerAttack- 2);
	} else if (intRobotArmor < intPlayerAttack) {
		intRobotHP -= (intPlayerAttack- intRobotArmor);
	}

	if (intPlayerArmor >= intRobotAttack) {
		intPlayerHP -= (intRobotAttack - 2);
	} else if (intPlayerArmor < intRobotAttack) {
		intPlayerHP -= (intRobotAttack - intPlayerArmor);
	}

	return intRobotHP;
	
}