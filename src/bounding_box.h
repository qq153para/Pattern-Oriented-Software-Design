#pragma once

#include <set>
#include <string>
#include "shape.h"

class BoundingBox
{
private:
    Point _max;
    Point _min;

public:
    BoundingBox(std::set<Point> points):_max(calMaximumPoint(points)),_min(calMinimumPoint(points)) {
        if (points.size() == 0){
            throw "At least one coordinate is required; an exception should otherwise be threw";
        }
    }

    Point calMaximumPoint(const std::set<Point > points) {
        double max_x;
        double max_y;
        int i=0;
        for (auto v : points){
            if (i==0){
                max_x = v . x();
                max_y = v . y();
            }
            else{
                if (v . x() > max_x) {
                    max_x = v . x();
                }
                if (v . y() > max_y) {
                    max_y = v . y();
                }
            } 
            ++i;   
        }
        Point p(max_x,max_y);
        return  p;
    }

    Point calMinimumPoint(const std::set< Point > points) {
        double min_x;
        double min_y;
        int i=0;
        for (auto v : points){
            if (i==0){
                min_x = v . x();
                min_y = v . y();
            }
            else{
                if (v . x() < min_x) {
                    min_x = v . x();
                }
                if (v . y() < min_y) {
                    min_y = v . y();
                }
            } 
            ++i;   
        }
        Point p (min_x,min_y);
        return  p;
    }

    Point max() {
        return _max;
    }

    Point min() {
        return _min;
    }

    bool collide(BoundingBox *box) {
        if(_max.x()<(box->min()).x() || _min.x()>(box->max()).x() 
        || _max.y()<(box->min()).y() || _min.y()>(box->max()).y()  ){
            return false;
        }
        else{
            return true;
        }
    }
};