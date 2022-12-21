#pragma once
#include "./sdl/sdl.h"
#include "canvas.h"

class SDLAdapter : public Canvas {
private:
    SDL *adaptee_;

public:
    SDLAdapter(int width, int height, SDL* adaptee) :adaptee_(adaptee){
        if(width>0 && height>0){
            adaptee->init(width,height);
        }
        else{
            throw "width And Height Should Be Greater Than Zero";
        } 
    }
    ~SDLAdapter(){
        adaptee_->destroy();
    }
    void drawCircle(Circle *cir) override {
        std::set<Point> AllVertices = cir->getPoints();
        std::set<Point>::iterator it = AllVertices.begin();
        Point Min = *it;
        it++;
        Point Max = *it;
        double radius = (Max.x() - Min.x())/2 ;
        double x = Max.x()-radius;
        double y = Max.y()-radius;
        adaptee_->renderDrawCircle(x,y,radius);
    }
    void  drawTriangle(Triangle *tri) override{
        std::set<Point> points = tri->getPoints();
        double *pValues = new double[6];
        int i =0;
        for (std::set<Point>::iterator it = points.begin(); it != points.end();it++)
        {
            pValues[i]=(*it).x();
            pValues[i+1]=(*it).y();
            i+=2;
        }
        adaptee_->renderDrawLines(pValues, 6);
    };
    void drawRectangle(Rectangle *rect) override{
        std::set<Point> points = rect->getPoints();
        
        double *pValues = new double[8];
        pValues[0] = (*std::next(points.begin(),0)).x();
        pValues[1] = (*std::next(points.begin(),0)).y();
        pValues[2] = (*std::next(points.begin(),1)).x();
        pValues[3] = (*std::next(points.begin(),1)).y();
        pValues[4] = (*std::next(points.begin(),3)).x();
        pValues[5] = (*std::next(points.begin(),3)).y();
        pValues[6] = (*std::next(points.begin(),2)).x();
        pValues[7] = (*std::next(points.begin(),2)).y();

        adaptee_->renderDrawLines(pValues, 8);
    };
    void display() override{
        adaptee_->renderPresent();
    };
};