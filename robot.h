#ifndef ROBOT_H
#define ROBOT_H

class robot {
	
	public:
		robot(int, int, int);
		void Fighter(int, int, int);
		int getHP();
		int intRobotHP, intPlayerHP;
		
	private:
		void WinLose(int, int, int, int);
		int intRobotAttack, intRobotArmor, intPlayerAttack, intPlayerArmor, AttackRun;
	
};

#endif
