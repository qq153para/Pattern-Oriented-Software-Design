#pragma once

#include "shape_visitor.h"
#include "../circle.h"
#include "../triangle.h"
#include "../rectangle.h"
#include "../compound_shape.h"
#include "../bounding_box.h"
#include "../iterator/factory/list_iterator_factory.h"
#include <vector>

class CollisionDetector : public ShapeVisitor
{
private:
    std::vector<Shape *> _collideResult;
    BoundingBox *_targetBoundingBox;

public:
    CollisionDetector(Shape *shape) {
        _targetBoundingBox=new BoundingBox(shape->getPoints());
    }
    ~CollisionDetector(){delete _targetBoundingBox;}
    void visitCircle(Circle *circle) override {
        BoundingBox AABB (circle->getPoints());
        if(AABB.collide(_targetBoundingBox)){
            _collideResult.push_back(circle);
        }
    }

    void visitTriangle(Triangle *triangle) override {
        BoundingBox AABB (triangle->getPoints());
        if(AABB.collide(_targetBoundingBox)){
            _collideResult.push_back(triangle);
        }
    }

    void visitRectangle(Rectangle *rectangle) override {
        BoundingBox AABB (rectangle->getPoints());
        if(AABB.collide(_targetBoundingBox)){
            _collideResult.push_back(rectangle);
        }
    }

    void visitCompoundShape(CompoundShape *compoundShape) override {
        Iterator *it = compoundShape->createIterator(IteratorFactory::getInstance("List"));
        for (it-> first();!it->isDone() ;it->next()){
            (it->currentItem())->accept(this);
        }
        delete it;
    }

    std::vector<Shape *> collidedShapes() const {
        return _collideResult;
    }
};