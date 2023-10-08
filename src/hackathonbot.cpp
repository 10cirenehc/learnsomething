//
// Created by Ethan on 9/13/2023.
//
#include "hackathonbot.h"

HackathonBot::HackathonBot(): buyPrice(100.0), balance(0.0), afterSellDownStreak(0),
holding(true), downStreak(0), upStreak(0), fivePercentStreak(0){
    this->histPrices.push_back(100.0);
};

void HackathonBot::takeAction(float price){

    // Update upStreak and downStreak
    if (this->histPrices.size() > 0) {
        if (price < this->histPrices.back()) {
            this->downStreak++;
            this->upStreak = 0;
            if (!this->holding) {
                this->afterSellDownStreak++;
            }
        } else if (price > this->histPrices.back()) {
            this->upStreak++;
            this->downStreak = 0;
        }
        else {
            this->upStreak = 0;
            this->downStreak = 0;
        }
    }

    // Update histPrices
    this->histPrices.push_back(price);

    // Determine sell conditions
    if (this->holding) {
        // Update fivePercentStreak
        if (abs(price-this->buyPrice)/this->buyPrice <= 0.05) {
            this->fivePercentStreak++;
        } else {
            this->fivePercentStreak = 0;
        }

        // streaks
        if (this->downStreak >= 47 || this->upStreak >= 52) {
            this->sell(&price);
            return;
        }

        // total ratios
        if ((price-this->buyPrice)/this->buyPrice > 0.89){
            this->sell(&price);
            return;
        }
        else if((price-this->buyPrice)/this->buyPrice < -0.62){
            this->sell(&price);
            return;
        }

        // fivePercentStreak
        if (this->fivePercentStreak >= 10) {
            this->sell(&price);
            return;
        }

        if (this->histPrices.size() >= 4){
            std::vector<float>::iterator it = histPrices.end();
            it -= 4;
            float seriesStart = *it;
            std::vector<float> percentChange;
            while (it != histPrices.end()){
                it++;
                percentChange.push_back((*it - *(it-1))/(*(it-1)));
            }
            // raise 20, drop 15, raise 30, %change 3 series >= 50
            if (percentChange[0] >= 0.2 && percentChange[1] <= -0.15 && percentChange[3] >= 0.3 
            && (this->histPrices.back()-seriesStart)/seriesStart >= 0.5){
                this->sell(&price);
                return;
            }
            else if(percentChange[0] <= -0.15 && percentChange[1] >= 0.15 && percentChange[3] <= -0.25
            && (this->histPrices.back()-this->buyPrice)/this->buyPrice <= -0.45){
                this->sell(&price);
                return;
            }
        }
    }

    // Determine buy conditions
    else{
        if(price<52 || afterSellDownStreak >= 5){
            this->buy(&price);
        }
    }
    
}
double HackathonBot::getBalance() {
    return this->balance;
}

bool HackathonBot::isHolding() {
    return this->holding; 
}

void HackathonBot::buy(float *price) {
    this->holding = true;
    this->balance -= *price;
    this->fivePercentStreak = 0;
    this->histPrices.clear();
    this->histPrices.push_back(*price);
}

void HackathonBot::sell(float *price){
    this->holding = false; 
    this->histPrices.clear();
    this->balance += *price;
    this->buyPrice = *price;
    this->afterSellDownStreak = 0;
}

