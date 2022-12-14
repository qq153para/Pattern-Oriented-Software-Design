#pragma once

#include <string>
#include <set>
#include "shape.h"
#include "two_dimensional_vector.h"
#include "point.h"
#include "./iterator/factory/iterator_factory.h"
#include "./visitor/shape_visitor.h"

class Rectangle : public Shape
{
private:
    TwoDimensionalVector _lengthVec;
    TwoDimensionalVector _widthVec;

public:
    Rectangle(TwoDimensionalVector lengthVec, TwoDimensionalVector widthVec) : _lengthVec(lengthVec),_widthVec(widthVec){
        //判斷兩向量是否正交  -----> 兩內積為0則正交
        if (lengthVec.dot(widthVec)!=0)
        {
            throw "This recthangle isn't created by two orthogonal vectors";
        }
        //判斷兩向量之兩端點是否交於一點  ----> False則兩向量之端點都不相交
        else if ((lengthVec.a().operator==( widthVec.a())||lengthVec.a().operator==( widthVec.b())||
                lengthVec.b().operator==( widthVec.a())||lengthVec.b().operator==( widthVec.b()))==false)
        {
            throw "The two vectors should be connected at either head or tail side"; 
        }     
    }
    ~Rectangle() {}

    double length() const { return _lengthVec.length();}

    double width() const { return _widthVec.length();}
    
    double area() const override {return this->length()*this->width();}

    double perimeter() const override {return 2*(this->length()+this->width());}

    std::string info() const override {
        std::string Space = " ";
        std::string LeftBracket = "(";
        std::string RightBracket = ")";
        std::string Rectangle = "Rectangle";
        std::string Comma = ",";
        return Rectangle+Space+LeftBracket+_lengthVec.info()+Comma+Space+_widthVec.info()+RightBracket;
    }

    Iterator *createIterator(IteratorFactory *factory) override {
        return factory->createIterator();
    }

	std::set<Point> getPoints() override {
        
        std::set<Point> AllVertices; 
        if (_lengthVec.a().operator==( _widthVec.a())){
            Point fourthVertex(_lengthVec.b().x()+_widthVec.b().x()-_lengthVec.a().x()
            ,_lengthVec.b().y()+_widthVec.b().y()-_lengthVec.a().y());
            AllVertices = {
            _lengthVec.a(),
            _lengthVec.b(),
            _widthVec.a(),
            _widthVec.b(),
            fourthVertex
            };
        }
        else if(_lengthVec.a().operator==( _widthVec.b())){
            Point fourthVertex(_lengthVec.b().x()+_widthVec.a().x()-_lengthVec.a().x()
            ,_lengthVec.b().y()+_widthVec.a().y()-_lengthVec.a().y());
            AllVertices = {
            _lengthVec.a(),
            _lengthVec.b(),
            _widthVec.a(),
            _widthVec.b(),
            fourthVertex
            };
        }
        else if(_lengthVec.b().operator==( _widthVec.a())){
            Point fourthVertex(_lengthVec.a().x()+_widthVec.b().x()-_widthVec.a().x()
            ,_lengthVec.a().y()+_widthVec.b().y()-_widthVec.a().y());
            AllVertices = {
            _lengthVec.a(),
            _lengthVec.b(),
            _widthVec.a(),
            _widthVec.b(),
            fourthVertex
            };
        }
        else if(_lengthVec.b().operator==( _widthVec.b())){
            Point fourthVertex (_lengthVec.a().x()+_widthVec.a().x()-_lengthVec.b().x()
            ,_lengthVec.a().y()+_widthVec.a().y()-_lengthVec.b().y());
            AllVertices = {
            _lengthVec.a(),
            _lengthVec.b(),
            _widthVec.a(),
            _widthVec.b(),
            fourthVertex
            };
        }
        
        // AllVertices.insert(_lengthVec.a());
        // AllVertices.insert(_lengthVec.b());
        // AllVertices.insert(_widthVec.a());
        // AllVertices.insert(_widthVec.b());
		

        return AllVertices;
    };

    void accept(ShapeVisitor* visitor) override{
        visitor->visitRectangle(this);
    };

    void addShape(Shape *shape) {throw "fail";};
    
    void deleteShape(Shape *shape) {throw "fail";};
};