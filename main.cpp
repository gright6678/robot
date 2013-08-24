#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include "store.h"
#include "adventure.h"

using namespace std;

void stats(), menu(), MoveOn();

int intPlayerAttack, intPlayerArmor, intPlayerHP, intPlayerMoney, intTurn, SaveID;
bool ChangeSaveID;

int main() {
	
	char CreateLoad;
	int UserSaveID, fileintPlayerAttack, fileintPlayerArmor, fileintPlayerHP, fileintPlayerMoney, fileintTurn, fileSaveID;;

	//initial prompt. ask whether to create a new game or load a saved game from file
	system ("clear");
	cout << "Welcome to Fighting Robots" << endl;
	cout << "Would you like to (c)reate a new adventure or (l)oad an existing adventure?" << endl;
	cin >> CreateLoad;
	cout << endl;
	
	try {
		
		if (CreateLoad == 'c' || CreateLoad == 'C') {
			
			intPlayerAttack = 0;
			intPlayerArmor = 0;
			intPlayerHP = 100;
			intPlayerMoney = 20;
			intTurn = 1;
			ChangeSaveID = false;
			system ("clear");
			MoveOn();
			intTurn++;
			menu();
			system ("clear");
			
		} else if (CreateLoad == 'l' || CreateLoad == 'L') {
			
			ifstream LoadGame("SavedGame");
		
			//get SaveID number from user
			cout << endl << "Save ID: ";
			cin >> UserSaveID;
			cout << endl;
			
			//search for the SaveID number that the user entered
			while (LoadGame >> fileSaveID >> fileintPlayerAttack >> fileintPlayerArmor >> fileintPlayerHP >> fileintPlayerMoney >> fileintTurn) {
				
				//stop at the SaveID number that the user entered and load the variables and close the file
				if (UserSaveID == fileSaveID) {

					SaveID = fileSaveID;
					intPlayerAttack = fileintPlayerAttack;
					intPlayerArmor = fileintPlayerArmor;
					intPlayerHP = fileintPlayerHP;
					intPlayerMoney = fileintPlayerMoney;
					intTurn = fileintTurn;
					
				}
			}
				
				//resume the game by showing the menu
				menu();
			
		} else {
			
			throw 0;
			
		}
	
	} catch (...) {
		
		system ("clear");
		cout << "ERROR: Invalid Input" << endl;
		
	}

	return 0;
	
}

void MoveOn() {
	
	adventure getgoing(intPlayerAttack, intPlayerArmor, intPlayerMoney, intPlayerHP, intTurn);
			
	//execute the adventure class
	getgoing.begin();
	
	//get the new variables from the adventure class
	intPlayerAttack= getgoing.intPlayerAttack;
	intPlayerArmor= getgoing.intPlayerArmor;
	intPlayerMoney= getgoing.intPlayerMoney;
	intPlayerHP= getgoing.intPlayerHP;
	intTurn= getgoing.intTurn;
	
}

void menu() {

		int a, b, c, d, e, f, PastSaveID, Option;
		char Save;
		bool Quit;

		do {
		
			try {
			
				cout << "1. Move on" << endl;
				cout << "2. View Stats" << endl;
				cout << "3: Quit" << endl;
				cin >> Option;
				
				switch (Option) {
					
					case 1: {
						system ("clear");
						MoveOn();
						intTurn++;
						break; }
					
					case 2: {
						system ("clear");
						stats();
						break; }
					
					case 3: {
						system ("clear");
						Quit = true;
						break; }
					
					default: {
						system ("clear");
						throw 0;
						break; }
					
				}
			
			} catch (...) {
		
				system ("clear");
				cout << "ERROR: Invalid Input" << endl;
				
			}
		
		} while (Quit == false && intPlayerHP > 0); //keep showing the menu as long as the player has HP left and has not told the program to quit
		
		
	if (intPlayerHP <= 0) { //show this when the player has no HP left
		system ("clear");
		cout << ":::::GAME OVER:::::" << endl << endl;
	}

		//prompt the user to save the game
		cout << "Would you like to save your game?(y/n)" << endl;
		cin >> Save;
					
		if (Save == 'y'){
			
			ifstream ReadSaveID("SavedGame");
			
			//if the file was newly created then change SaveID to the next available number			
			if (ChangeSaveID == false) { //if game was created
				
				while (ReadSaveID >> a >> b >> c >> d >> e >> f) {
					SaveID = a;
				}
			
				SaveID++;
				
				//Save the game and append it to the end of the file
				ofstream SaveGame("SavedGame", ios::app);
			
				SaveGame << SaveID << " "
							<< intPlayerAttack << " "
							<< intPlayerArmor << " "
							<< intPlayerHP << " "
							<< intPlayerMoney << " "
							<< intTurn << "\n";
							
				SaveGame.close();

			} else { //if game was loaded then replace the old saved game with the new saved game
					
					ofstream SaveGame("SavedGame", ios::app);
					ofstream oldSaveGame("SavedGame");
					
					//find the old saved game
					while (ReadSaveID >> PastSaveID >> intPlayerAttack >> intPlayerArmor >> intPlayerHP >> intPlayerMoney >> intTurn) {
						
						oldSaveGame << PastSaveID << " "
										<< intPlayerAttack << " "
										<< intPlayerArmor << " "
										<< intPlayerHP << " "
										<< intPlayerMoney << " "
										<< intTurn << "\n";
						
						//find the SaveID in the file
						if (PastSaveID == SaveID) {							
					
							SaveGame << SaveID << " "
										<< intPlayerAttack << " "
										<< intPlayerArmor << " "
										<< intPlayerHP << " "
										<< intPlayerMoney << " "
										<< intTurn << "\n";

						}
								
					}
				
				SaveGame.close();
				
			}

			
		}
	
	system ("clear");
}

void stats() {
	
	cout << "Attack: " << intPlayerAttack<< endl;
	cout << "Armor: " << intPlayerArmor<< endl;
	cout << "HP: " << intPlayerHP<< endl;
	cout << "Money: " << intPlayerMoney<< endl;
	cout << "\n";
	
}