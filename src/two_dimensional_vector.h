#pragma once

#include <cmath>
#include "point.h"

class TwoDimensionalVector
{
private:
    Point _a;
    Point _b;

public:
    TwoDimensionalVector(Point a, Point b) :_a(a),_b(b){
        //使用Initializer List
    }
    ~TwoDimensionalVector() {}

    Point a() const {return _a;}

    Point b() const {return _b;}

    double length() const {
        double length_x=pow(_b.x() - _a.x(),2);
        double length_y=pow(_b.y() - _a.y(),2);
        return sqrt(length_x+length_y);
    }

    double dot(TwoDimensionalVector vec) const {

        double VectorAX=_a.x() - _b.x();
        double VectorAY=_a.y() - _b.y();
        double VectorBX=(vec.a()).x() - (vec.b()).x();
        double VectorBY=(vec.a()).y() - (vec.b()).y();      
        return VectorAX*VectorBX+VectorAY*VectorBY;
    }

    double cross(TwoDimensionalVector vec) const {
        double VectorAX=_a.x() - _b.x();
        double VectorAY=_a.y() - _b.y();
        double VectorBX=(vec.a()).x() - (vec.b()).x();
        double VectorBY=(vec.a()).y() - (vec.b()).y();
        return VectorAX * VectorBY - VectorBX * VectorAY;
    }

    void move(double deltaX, double deltaY)
    {
        _a.move(deltaX, deltaY);
        _b.move(deltaX, deltaY);
    }
    
    std::string info() const {
        std::string Space = " ";
        std::string LeftBracket = "(";
        std::string RightBracket = ")";
        std::string Vector = "Vector";
        std::string Comma = ",";
        std::stringstream stream;
        //將ax從double轉為string
        stream << std::fixed << std::setprecision(2) << this->_a.x();
        std::string str_ax = stream.str();
        stream.str("");
        //將ay從double轉為string
        stream << std::fixed << std::setprecision(2) << this->_a.y();
        std::string str_ay = stream.str();
        stream.str("");
        //將bx從double轉為string
        stream << std::fixed << std::setprecision(2) << this->_b.x();
        std::string str_bx = stream.str();
        stream.str("");
        //將by從double轉為string
        stream << std::fixed << std::setprecision(2) << this->_b.y();
        std::string str_by = stream.str();
        stream.str("");
        return Vector+Space+LeftBracket+LeftBracket+str_ax+Comma+Space+str_ay+RightBracket+Comma+Space+LeftBracket+str_bx+Comma+Space+str_by+RightBracket+RightBracket;
    }
};