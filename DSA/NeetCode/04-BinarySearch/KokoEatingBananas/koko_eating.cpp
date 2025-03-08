//
// Created by prw on 3/8/25.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int banana_rate(std::vector<int> piles, int h){

    int min_rate{1};
    int max_rate = *std::max_element(piles.begin(),piles.end());

    int result{};

    while(min_rate <= max_rate){

        int rate = (min_rate+max_rate) / 2;
        int total_time{};

        // number of hours to eat piles given current rate
        for(auto p : piles){
            total_time += ceil(static_cast<double>(p) / rate);
        }

        if (total_time <= h){
            result = rate;
            max_rate = rate - 1;
        }
        else{
            min_rate = rate +1;
        }


    }

    return result;
}



int main(){

    std::vector<int> piles{1,1,1,1,25};
    int h{100};

    std::cout << "Banana Rate: " << banana_rate(piles, h);

    return 0;
}