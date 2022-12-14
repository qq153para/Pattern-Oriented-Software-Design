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
    TwoDimensionalVector _radiusVec;

public:
    Circle(TwoDimensionalVector radiusVec) : _radiusVec(radiusVec){}
    ~Circle() {}

    double radius() const {return _radiusVec.length(); }

    double area() const override { return this->radius()*this->radius()*M_PI;}

    double perimeter() const override { return 2*this->radius()*M_PI;}

    std::string info() const override {
        std::string Space = " ";
        std::string LeftBracket = "(";
        std::string RightBracket = ")";
        std::string Circle = "Circle";
        std::string Comma = ",";
        return Circle+Space+LeftBracket+_radiusVec.info()+RightBracket;
    }

    Iterator *createIterator(IteratorFactory *factory) override {
        return factory->createIterator();
    }

    std::set<Point> getPoints() {
        std::set<Point> AllVertices; 
        double radius=this->radius();
        Point UpperRight (_radiusVec.a().x()+radius,_radiusVec.a().y()+radius);
        Point LowerLeft (_radiusVec.a().x()-radius,_radiusVec.a().y()-radius);
        AllVertices.insert(LowerLeft);
        AllVertices.insert(UpperRight);
        
        return AllVertices;
    };

    void accept(ShapeVisitor* visitor) override{
        visitor->visitCircle(this);
    };

    void addShape(Shape *shape) {throw "fail";};
    
    void deleteShape(Shape *shape) {throw "fail";};
};