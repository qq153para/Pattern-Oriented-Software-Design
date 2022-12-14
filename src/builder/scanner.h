#pragma once

#include <string>

class Scanner
{
public:
    Scanner(std::string input = "") :_input(input){}

    std::string next() {
        std::string result = "";
        if(this->isDone()){
            throw "This input is Done";
        }
        else{
            _skipWhiteSpace();
            for(auto token: tokenList) {
                if(_input.compare(pos, token.length(), token) == 0) {
                    pos = pos + token.length();
                    result = token;
                    break;
                }
            }
            return result;
        }
    }

    void _skipWhiteSpace() {
        
        while(_input[pos] == ' ' || _input[pos] == '\n') {
            pos++;
        }
    }

    double nextDouble() {
        std::string s = "";
        if(this->isDone()){
            throw "This input is Done";
        }
        else{
            _skipWhiteSpace();
            while ((_input[pos] <= '9' && _input[pos] >= '0' )|| _input[pos] == '-')
                s = s + _input[pos++];
            if (_input[pos] == '.')
                s = s + _input[pos++];
            while (_input[pos] <= '9' && _input[pos] >= '0')
                s = s + _input[pos++];
            return std::stod(s);
        }
    }

    bool isDone(){
        _skipWhiteSpace();
        return pos == _input.length();
    }

private:
    std::string _input;
    std::string::size_type pos = 0;
    const std::vector<std::string> tokenList = {"Circle", "Rectangle", "Triangle", "CompoundShape"
                                                , "Vector", "(", ")", ","};
    
};