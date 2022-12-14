#pragma once

#include <string>
#include "shape.h"
#include "two_dimensional_vector.h"

class Rectangle : public Shape
{
private:
    TwoDimensionalVector *_lengthVec;
    TwoDimensionalVector *_widthVec;

public:
    Rectangle(TwoDimensionalVector *lengthVec, TwoDimensionalVector *widthVec) {
        //判斷兩向量是否正交  -----> 兩內積為0則正交
        if (lengthVec->dot(widthVec)!=0)
        {
            throw "This recthangle isn't created by two orthogonal vectors";
        }
        //判斷兩向量之兩端點是否交於一點  ----> False則兩向量之端點都不相交
        else if ((lengthVec->a()->operator==( *widthVec->a())||lengthVec->a()->operator==( *widthVec->b())||
                lengthVec->b()->operator==( *widthVec->a())||lengthVec->b()->operator==( *widthVec->b()))==false)
        {
            throw "The two vectors should be connected at either head or tail side"; 
        }
        //符合Rectangle創建之規範
        else{
            this->_lengthVec = lengthVec;
            this->_widthVec = widthVec;
        }
        
    }
    ~Rectangle() {}

    double length() const { return _lengthVec->length();}

    double width() const { return _widthVec->length();}
    
    double area() const override {return this->length()*this->width();}

    double perimeter() const override {return 2*(this->length()+this->width());}

    std::string info() const override {
        std::string Space = " ";
        std::string LeftBracket = "(";
        std::string RightBracket = ")";
        std::string Rectangle = "Rectangle";
        std::string Comma = ",";
        return Rectangle+Space+LeftBracket+_lengthVec->info()+Comma+Space+_widthVec->info()+RightBracket;
    }
};