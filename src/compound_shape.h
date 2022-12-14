#pragma once

#include "shape.h"
#include "./iterator/dfs_compound_iterator.h"
#include "./iterator/bfs_compound_iterator.h"
#include "./iterator/compound_iterator.h"

#include <list>

class CompoundShape : public Shape
{
private:
    std::list<Shape *> _shapes;

public:
    CompoundShape(Shape **shapes, int size) 
    :_shapes(shapes, shapes + size) {}

    ~CompoundShape() {}

    double area() const override {
        double result = 0;
        for (auto shape_ptr : _shapes) {
            result += shape_ptr->area();
        }
        return result;
    }

    double perimeter() const override {
        double result = 0;
        for (auto shape_ptr : _shapes) {
            result += shape_ptr->perimeter();
        }
        return result;
    }

    std::string info() const override {
        std::string Space = " ";
        std::string LeftBracket = "(";
        std::string RightBracket = ")";
        std::string CompoundShape = "CompoundShape";
        std::string Comma = ",";
        std::string result = CompoundShape + Space + LeftBracket;
        std::stringstream stream;
        int i = 0;
        int size =_shapes.size();
        for (auto shape_ptr : _shapes) {
            i++;
            result = result + shape_ptr->info() ;
            if(i < size){
                result  = result + Comma +Space;
            }
            
        }
        result = result +RightBracket;
        return result;
    }

    Iterator* createDFSIterator() override {
        return new DFSCompoundIterator<std::list<Shape *>::iterator>(_shapes.begin(), _shapes.end());
    }
    // //begin+size 即為 end
    Iterator* createBFSIterator() override {
        return new BFSCompoundIterator<std::list<Shape *>::iterator>(_shapes.begin(), _shapes.end());
    }

    Iterator* createIterator() override { 
        return new CompoundIterator<std::list<Shape *>::iterator>(_shapes.begin(), _shapes.end());
    }

    void addShape(Shape* shape) override {
        _shapes.push_back(shape);
    }

    void deleteShape(Shape* shape) override {
        _shapes.remove(shape); 
        for (auto shape_ptr : _shapes) {
            Iterator* it=shape_ptr->createBFSIterator();
            if(!it->isDone()){
                shape_ptr->deleteShape(shape);        
            }
            delete it;
        }
    }
};