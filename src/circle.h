#pragma once

#include <string>
#include <cmath>
#include "two_dimensional_vector.h"
#include "shape.h"
#include "./iterator/null_iterator.h"

class Circle : public Shape
{
private:
    TwoDimensionalVector *_radiusVec;

public:
    Circle(TwoDimensionalVector *radiusVec) {
        this->_radiusVec=radiusVec;
    }
    ~Circle() {}

    double radius() const {return _radiusVec->length(); }

    double area() const override { return this->radius()*this->radius()*M_PI;}

    double perimeter() const override { return 2*this->radius()*M_PI;}

    std::string info() const override {
        std::string Space = " ";
        std::string LeftBracket = "(";
        std::string RightBracket = ")";
        std::string Circle = "Circle";
        std::string Comma = ",";
        return Circle+Space+LeftBracket+_radiusVec->info()+RightBracket;
    }

    Iterator* createDFSIterator() override { return new NullIterator(); }

    Iterator* createBFSIterator() override { return new NullIterator(); }

    Iterator* createIterator() override { return new NullIterator(); }

    void addShape(Shape *shape) {throw "fail";};
    
    void deleteShape(Shape *shape) {throw "fail";};
};