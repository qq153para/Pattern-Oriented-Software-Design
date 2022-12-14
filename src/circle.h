#pragma once

#include <string>
#include <set>
#include <cmath>
#include "two_dimensional_vector.h"
#include "point.h"
#include "./iterator/factory/iterator_factory.h"
#include "./visitor/shape_visitor.h"

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

    Iterator *createIterator(IteratorFactory *factory) override {
        return factory->createIterator();
    }

    std::set<const Point*> getPoints() {
        std::set<const Point*> AllVertices; 
        double radius=this->radius();
        Point* UpperRight = new Point(_radiusVec->a()->x()+radius,_radiusVec->a()->y()+radius);
        Point* LowerLeft = new Point(_radiusVec->a()->x()-radius,_radiusVec->a()->y()-radius);
        AllVertices.insert(UpperRight);
        AllVertices.insert(LowerLeft);
        return AllVertices;
    };

    void accept(ShapeVisitor* visitor) override{
        visitor->visitCircle(this);
    };

    void addShape(Shape *shape) {throw "fail";};
    
    void deleteShape(Shape *shape) {throw "fail";};
};