#include "lottery-machine.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include "winner.h"
#include "bet.h"
using namespace std;

using namespace std;

// Makes sure all doubles are rounded to two decimal places
double toDollarAmount(double d) {
    return round(d*100)/100.0;
}

LotteryMachine::LotteryMachine() {
    _open = true;
    _winningNumber = rand() % 101;
}

LotteryMachine::LotteryMachine(const unsigned int lucky) {
    if (lucky < 0 || lucky > 100)
        throw "Lucky number out of bounds! (0-100)";
    _open = true;
    _winningNumber = lucky;
}

void LotteryMachine::addBet(string name, unsigned int luckyNumber, double bet){
    if (luckyNumber < 0 || luckyNumber > 100)
        throw (string) "Lucky number out of bounds! (0-100)";
    if (bet <= 0)
        throw (string) "Invalid bet amount.";
    if (name == "")
        throw (string) "Invalid name.";
    _bets.push_back(Bet(name, luckyNumber, toDollarAmount(bet)));
}

void LotteryMachine::close() {
    _open = false;
}

vector<Winner> LotteryMachine::getWinners() {
    if (_open)
        throw (string) "Lottery is still open!";
    vector <Winner> winners;
    double winningTotal = 0;
    double totalBet = 0;


    for (const auto& bet : _bets){
        totalBet += bet.getBet();
        if (bet.getLuckyNumber() == _winningNumber){
            winningTotal += bet.getBet();
        }
    }

    for (const auto& bet : _bets){
        if (bet.getLuckyNumber() == _winningNumber){
            winners.push_back(Winner(bet.getName(), toDollarAmount(bet.getBet()/winningTotal*totalBet*PAYOFF_PERCENTAGE)));
        }
    }
    return winners;

}


void LotteryMachine::summarize() const {
    cout << "Lottery Machine Summary" << endl;
    cout << " The machine is " << (_open ? "OPEN" : "CLOSED") << endl;
    cout << " Lucky number is " << _winningNumber << endl;
    cout << " Bets are: " << endl;
    for (auto iter = _bets.begin(); iter < _bets.end(); iter++) {
        cout << iter->getName() << " " << iter->getBet() << endl;
    }
    double totalBet = 0;
    for (const auto& bet : _bets){
        totalBet += bet.getBet();

    }
    /* deleted */
    cout << " Total bet: " << toDollarAmount(totalBet) << endl;
    cout << " Payout: " << toDollarAmount(totalBet * PAYOFF_PERCENTAGE) << endl;
}


