#ifndef ROBOT_H
#define ROBOT_H

class robot {
	
	public:
		robot(int, int, int);
		void Fighter(int, int, int);
		int intPlayerHP;
		
	private:
		int WinLose(int, int, int, int, int);
		int intRobotAttack, intRobotArmor, intRobotHP, intPlayerAttack, intPlayerArmor;
	
};

#endif
