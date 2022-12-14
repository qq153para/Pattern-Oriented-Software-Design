#pragma once

#include <iomanip>
#include <sstream>
#include <cmath>
#include <string>

using namespace std;
class Point
{
private:
    const double _x;
    const double _y;

public:
    Point(double x, double y) :_x(x),_y(y){
        //使用Initializer List 
    };
    ~Point(){}

    double x() const  { return  _x;}

    double y() const  { return  _y;}

    bool operator==(const Point &pt) const { 
        //const 加在成員函式後面表示不能在該成員函式裡修改類別成員變數
        //Pass by reference   
        if ((fabs(_x-pt.x()) < 1e-3) && (fabs(_y-pt.y()) < 1e-3))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator<(const Point &pt) const {
        return _x < pt.x() || (_x == pt.x() && _y < pt.y());
    }

    std::string info() const {
        std::string Space = " ";
        std::string LeftBracket = "(";
        std::string RightBracket = ")";
        std::string Comma = ",";
        std::stringstream stream;
        stream << std::fixed << std::setprecision(2) << this->_x;
        std::string str_x = stream.str();
        stream.str("");                         //清空stream
        stream << std::fixed << std::setprecision(2) << this->_y;
        std::string str_y = stream.str();       //清空stream
        return LeftBracket+str_x+Comma+Space+str_y+RightBracket;
    }
};
