#include "winner.h"

Winner::Winner(string name, double payoff) {
    _name = name;
    _payoff = payoff;
}

string Winner::getName() const {
    return _name;
}

double Winner::getPayoff() const {
    return _payoff;
}

