#pragma once
#include <set>
#include <string>
class Iterator;
class IteratorFactory;
class Point;
class ShapeVisitor;
class Shape
{
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual std::string info() const = 0;
    virtual Iterator* createIterator(IteratorFactory * factory) = 0;
    virtual std::set<Point> getPoints() = 0;
    virtual void accept(ShapeVisitor* visitor) = 0;
    virtual void addShape(Shape *shape) = 0;
    virtual void deleteShape(Shape *shape) = 0;
    virtual void move(double deltaX, double deltaY) = 0;
    virtual ~Shape() {}
};
