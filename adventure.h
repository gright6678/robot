#ifndef ADVENTURE_H
#define ADVENTURE_H


class adventure {
public:

	adventure(int, int, int, int, int);
	void begin();
	int getAttack();
	int getArmor();
	int getMoney();
	int getHP();
	int getTurn();

private:
	int intPlayerAttack, intPlayerArmor, intPlayerHP, intPlayerMoney, intTurn;
	void battle();
	void lost();	
	void StoreVisit();
	
};

#endif