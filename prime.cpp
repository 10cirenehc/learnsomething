#include <set>
#include <cmath>
#include <unordered_map>
#include <chrono>
#include <iostream>

void better_prime(){
    std::set<int> primes;
    primes.insert(2);

    for (int i=3; i<round(sqrt(2500))+1; i+=2){
        bool is_prime = true;
        for (std::set<int>::iterator it = primes.begin(); it != primes.end(); ++it){
            if (i%(*it)==0){
                is_prime = false;
                break;
            }
        }
        if (is_prime){
            primes.insert(i);
        }
    }

    std::unordered_map<int, std::set<int> > prev_primes;
    for (int i = 2;i<=2500;i++){
        int currentPrime = i;
        bool flag = true;
        for (std::set<int>::iterator it = primes.begin(); it != primes.end(); ++it){
            if (currentPrime%(*it)==0){
                flag = false;
                prev_primes[i].insert(*it);
                currentPrime = currentPrime/(*it);
                prev_primes[i].insert(prev_primes[currentPrime].begin(), prev_primes[currentPrime].end());
                break;
            }
        }
        if (flag){
            prev_primes[i].insert(i);
        }
    }
}

int main(){

    double sum_times = 0;

    for (int i =0; i<5;i++){
        auto start = std::chrono::high_resolution_clock::now();
        better_prime();
        auto stop = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> runtime = stop - start;
        sum_times += runtime.count();
    }

    double avg_time = sum_times/5000.0;

    std::cout << "Average runtime of better_prime: " << avg_time << "s" << std::endl;
}