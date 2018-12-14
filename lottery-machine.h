#ifndef LOTTERY_MACHINE_H_
#define LOTTERY_MACHINE_H_
#include <string>
#include <vector>
#include "winner.h"
#include "bet.h"

using namespace std;

class LotteryMachine {
private:
    constexpr static double PAYOFF_PERCENTAGE = 0.95;
    unsigned int _winningNumber;
    bool _open;
    vector<Bet> _bets;

public:
    // Assign winning number randomly
    LotteryMachine();

    // Assign this winning number
    LotteryMachine(const unsigned int);

    // Bet is name, chosen lucky number, and bet amount
    void addBet(string, unsigned int, double);

    // Close down the machine
    void close();

    // Calculate payoffs for winning bets -- error to call if
    // machine is open
    vector<Winner> getWinners();

    // Diagnostics only -- write a pretty summary to cout
    void summarize() const;
};

#endif /* LOTTERY_MACHINE_H_ */
