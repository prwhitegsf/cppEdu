#include <vector>
#include <iostream>




int MaxProfit(std::vector<int> prices){

    int lhs{};
    int rhs{1};
    int max_profit{};

    while (rhs < prices.size()){

        if (prices[lhs] < prices[rhs])
            max_profit = std::max(max_profit, (prices[rhs]-prices[lhs]));
        else
            lhs = rhs;

        rhs++;
    }

    return max_profit;



}




int main(){

    std::vector<int> prices{10,1,5,6,7,1};

    std::cout << "Max Profit: " << MaxProfit(prices);


    return 0;
}