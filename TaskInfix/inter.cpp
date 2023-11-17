#include "inter.hpp"

#include <algorithm>

std::string getExpression (std::vector<std::string> buffer) {
    std::vector<std::string> expressions;
    std::reverse(buffer.begin(), buffer.end());
    for(auto & elem : buffer ) {
        if(auto num = std::atoi(elem.c_str()); num) {
            expressions.push_back(elem);
        } else {
            if(expressions.size() == 1) {
                expressions.insert(expressions.begin(),elem + expressions.back());
                expressions.pop_back();
                continue;
            }
            auto str = std::string("(") + expressions[expressions.size()-1] +
            std::string(" ")+elem+std::string(" ") + expressions[expressions.size()-2] + ")";
            expressions.pop_back();
            expressions.pop_back();
            expressions.push_back(str);
        }
    }
    std::string out; //rvo
    for(auto & elem : expressions) {
        out += elem;
    }
    return out;
}