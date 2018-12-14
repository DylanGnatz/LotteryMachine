#ifndef WINNER_H_
#define WINNER_H_
#include <string>
using namespace std;

class Winner {
private:
    string _name;
    double _payoff;
public:
    Winner(string, double);
    string getName() const;
    double getPayoff() const;
};

#endif /* WINNER_H_ */
