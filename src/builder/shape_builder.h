#pragma once
#include "../circle.h"
#include "../triangle.h"
#include "../rectangle.h"
#include "../compound_shape.h"
#include <vector>
#include <stack>

class ShapeBuilder{
private:
    std::vector<Shape*> _result;
public:

    void buildCircle(const Point *center, const Point *to_radius) {
        Shape* circle = new Circle(new TwoDimensionalVector(center,to_radius));
        if(!composites.empty()){
            composites.top()->addShape(circle);
        }
        else{
            results.push_back(circle);
        }
    }

    void buildTriangle(const Point *common_point, const Point *v1_point, const Point *v2_point) {
        Shape* triangle = new Triangle(new TwoDimensionalVector(common_point,v1_point)
                                        ,new TwoDimensionalVector(common_point,v2_point));
        if(!composites.empty()){
            composites.top()->addShape(triangle);
        }
        else{
            results.push_back(triangle);
        } 
    }

    void buildRectangle(const Point *common_point, const Point *v1_point, const Point *v2_point) {
        Shape* rectangle = new Rectangle(new TwoDimensionalVector(common_point,v1_point)
                                        ,new TwoDimensionalVector(common_point,v2_point));
        if(!composites.empty()){
            composites.top()->addShape(rectangle);
        }
        else{
            results.push_back(rectangle);
        }
    }

    void buildCompoundShape() {
        CompoundShape* cs = new CompoundShape(new Shape* {},0);
        composites.push(cs);
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