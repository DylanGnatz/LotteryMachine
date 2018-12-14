#include <iostream>
#include <vector>
#include "lottery-machine.h"
using namespace std;


int main() {
	cout << "Setting up machine" << endl;
	LotteryMachine lm(50);
	cout << "Placing bets" << endl;
	lm.addBet("Fannie", 50, 100.0);
	lm.addBet("Flo", 25, 200.0);
	lm.addBet("Jackie", 25, 100.0);
	lm.close();
	cout << "\nBets are placed, machine is closed.  Summary.\n" << endl;
	lm.summarize();

	cout << "\nWinners are:" << endl;
	vector<Winner> winners = lm.getWinners();
	for (auto iter = winners.begin(); iter < winners.end(); iter++) {
		cout << "  " << iter->getName() << " " << iter->getPayoff() << endl;
	}
}
