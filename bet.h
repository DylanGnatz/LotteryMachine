#ifndef BET_H_
#define BET_H_
#include <string>
using namespace std;

class Bet {
private:
    string _name;
    unsigned int _luckyNumber;
    double _bet;
public:
    Bet(string, unsigned int, double);
    string getName() const;
    unsigned int getLuckyNumber() const;
    double getBet() const;
};

#endif /* BET_H_ */
