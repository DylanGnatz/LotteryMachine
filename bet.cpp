#include "bet.h"

Bet::Bet(string name, unsigned int luckyNumber, double bet) {
    _name = name;
    _luckyNumber = luckyNumber;
    _bet = bet;
}

string Bet::getName() const {
    return _name;
}

unsigned int Bet::getLuckyNumber() const {
    return _luckyNumber;
}

double Bet::getBet() const {
    return _bet;
}
