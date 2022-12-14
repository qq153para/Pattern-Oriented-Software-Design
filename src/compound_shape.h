#pragma once
#include "./iterator/factory/list_iterator_factory.h"
#include "./visitor/shape_visitor.h"
#include "shape.h"
#include <list>
#include <set>

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

	Iterator *createIterator(IteratorFactory *factory) override {
        return factory -> createIterator(_shapes.begin(), _shapes.end());
    }

	std::set<const Point*> getPoints() override {
        // Iterator* it = this->createIterator(new ListIteratorFactory());
        std::set<const Point*> AllVertices; 
        for (auto shape_ptr : _shapes) {
            for (auto v :shape_ptr->getPoints()){
                AllVertices.insert(v);
            }      
        }
        return AllVertices;
    };
	
	void accept(ShapeVisitor* visitor) override{
        visitor->visitCompoundShape(this);
    };

    void addShape(Shape* shape) override {
        _shapes.push_back(shape);
    }

    void deleteShape(Shape* shape) override {
        _shapes.remove(shape); 
        for (auto shape_ptr : _shapes) {
            Iterator* it=shape_ptr->createIterator(new ListIteratorFactory());
            if(!it->isDone()){
                shape_ptr->deleteShape(shape);        
            }
            delete it;
        }
    }
};