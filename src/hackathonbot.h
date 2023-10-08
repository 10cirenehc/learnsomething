//
// Created by Ethan on 9/13/2023.
//

#include <vector>
#include "action.h"

#ifndef LEARNSOMETHING_HACKATHONBOT_H
#define LEARNSOMETHING_HACKATHONBOT_H

class HackathonBot {
public:
    HackathonBot();
    void takeAction(float price);
    double getBalance();
    bool isHolding();
private:
    double balance;
    double buyPrice; 
    bool holding;
    int downStreak;
    int afterSellDownStreak;
    int upStreak;
    int fivePercentStreak;
    std::vector<float> histPrices;
    void buy(float *price);
    void sell(float *price);
};

#endif //LEARNSOMETHING_HACKATHONBOT_H
