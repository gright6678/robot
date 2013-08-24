#ifndef ADVENTURE_H
#define ADVENTURE_H


class adventure {
public:

	adventure(int, int, int, int, int);
	void begin();
	int intPlayerAttack, intPlayerArmor, intPlayerHP, intPlayerMoney, intTurn, AttackRun;

private:
	void battle();
	void lost();	
	void StoreVisit();
};

#endif