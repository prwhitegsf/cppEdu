//
// Created by prw on 2/22/25.
//

#ifndef CPP_MIN_STACK_H
#define CPP_MIN_STACK_H

#include <stack>
#include <deque>

class MinStack{

private:
    std::stack<int> stack_{};
    std::deque<int> d_{};

public:

    void push(int val){
        stack_.push(val);

        if (d_.empty())
            d_.push_back(val);
        else
            val <= d_.front() ? d_.push_front(val) : d_.push_back(val);
    }

    void pop(){
        if (stack_.empty())
            return;

        if (d_.front() == stack_.top())
            d_.pop_front();

        stack_.pop();

    }

    int top() const {
        return stack_.top();
    }

    int GetMin() const {
        return d_.front();
    }


};







#endif //CPP_MIN_STACK_H
