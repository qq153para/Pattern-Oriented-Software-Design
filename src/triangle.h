#pragma once

#include <string>
#include <set>
#include "shape.h"
#include "two_dimensional_vector.h"
#include "point.h"
#include "./iterator/factory/iterator_factory.h"
#include "./visitor/shape_visitor.h"

class Triangle : public Shape
{
private:
    TwoDimensionalVector _v1;
    TwoDimensionalVector _v2;

public:
    Triangle(TwoDimensionalVector v1, TwoDimensionalVector v2) : _v1(v1),_v2(v2){
        //判斷兩向量是否平行   ------> 兩向量外積為0則為平行
        if (abs(v1.cross(v2))==0)
        {
            throw "Triangle should be created by two non-parallel vectors";
        }
        //判斷兩向量之兩端點是否交於一點   ---->false則表示兩向量之端點都不相交
        else if (((v1.a()).operator==( (v2.a()))||(v1.a()).operator==( (v2.b()))||
                (v1.b()).operator==( (v2.a()))||(v1.b()).operator==( (v2.b())))==false)
        {
            throw "The two vectors should be connected at either head or tail side";
        }
        
    }
    ~Triangle() {}

    double area() const override {
        return abs(_v1.cross(_v2))/2;
    }

    double perimeter() const override {
        //第三條邊之長度
        double lengthC;
        //判斷交點於何處，並計算第三邊之長度
        if ((_v1.a()).operator==((_v2.a()))){
            TwoDimensionalVector t1(_v1.b(),_v2.b());
            lengthC=t1.length();
        }
        else if((_v1.a()).operator==((_v2.b()))){
            TwoDimensionalVector t1(_v1.b(),_v2.a());
            lengthC=t1.length();
        }
        else if((_v1.b()).operator==((_v2.a()))){
            TwoDimensionalVector t1(_v1.a(),_v2.b());
            lengthC=t1.length();
        }
        else if((_v1.b()).operator==((_v2.b()))){
            TwoDimensionalVector t1(_v1.a(),_v2.a());
            lengthC=t1.length();
        }
        
        return lengthC+_v1.length()+_v2.length();
    }

    std::string info() const override {
        std::string Space = " ";
        std::string LeftBracket = "(";
        std::string RightBracket = ")";
        std::string Triangle = "Triangle";
        std::string Comma = ",";
        return Triangle+Space+LeftBracket+_v1.info()+Comma+Space+_v2.info()+RightBracket;
    }

    Iterator *createIterator(IteratorFactory *factory) override {
        return factory->createIterator();
    }

    std::set<Point> getPoints() override{
        std::set<Point> AllVertices= {
            _v1.a(),
            _v1.b(),
            _v2.a(),
            _v2.b()}; 
        return AllVertices;
    };

    void accept(ShapeVisitor* visitor) override{
        visitor->visitTriangle(this);
    };

    void addShape(Shape *shape) {throw "fail";};
    
    void deleteShape(Shape *shape) {throw "fail";};
    
};