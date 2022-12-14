#pragma once
#include "../circle.h"
#include "../triangle.h"
#include "../rectangle.h"
#include "../compound_shape.h"
#include <vector>
#include <stack>

class ShapeBuilder{
public:
    ~ShapeBuilder(){
    }
    void buildCircle(Point center, Point to_radius) {
        TwoDimensionalVector t1(center,to_radius);
        Shape* circle = new Circle(t1);
        if(!composites.empty()){
            composites.top()->addShape(circle);
        }
        else{
            results.push_back(circle);
        }
    }

    void buildTriangle(Point common_point,Point v1_point, Point v2_point) {
        TwoDimensionalVector t1(common_point,v1_point);
        TwoDimensionalVector t2(common_point,v2_point);
        Shape* triangle = new Triangle( t1, t2);
        if(!composites.empty()){
            composites.top()->addShape(triangle);
        }
        else{
            results.push_back(triangle);
        } 
    }

    void buildRectangle(Point common_point, Point v1_point, Point v2_point) {
        TwoDimensionalVector t1(common_point,v1_point);
        TwoDimensionalVector t2(common_point,v2_point);
        Shape* rectangle = new Rectangle(t1,t2);
        if(!composites.empty()){
            composites.top()->addShape(rectangle);
        }
        else{
            results.push_back(rectangle);
        }
    }

    void buildCompoundShape() {
        Shape ** s1 = new Shape* {};
        CompoundShape* cs = new CompoundShape(s1,0);
        composites.push(cs);
        delete s1;
    }

    void buildCompoundEnd() {
        CompoundShape* topcs = composites.top();
            composites.pop();
            if(composites.empty()){
                results.push_back( topcs );
            }
            else{
                composites.top()->addShape(topcs);
            }
    }

    std::vector<Shape*> getResult() {
        return results;
    }
private:
    std::stack<CompoundShape*> composites;
    std::vector<Shape*> results;
};