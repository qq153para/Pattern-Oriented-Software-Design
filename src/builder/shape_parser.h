#pragma once

#include "./scanner.h"
#include "./shape_builder.h"
#include "../two_dimensional_vector.h"
#include <string>
#include <vector>

class ShapeParser
{
private:
    Scanner *_scanner;
    ShapeBuilder _builder;
    std::string _input;
    std::stack<string> _token;

public:
    ShapeParser(std::string input):_input(input) {}

    ~ShapeParser() {
        delete _scanner;
    }

    void parse() {
        _scanner=new Scanner(_input);
        
        while( !_scanner->isDone() ) {
            std::string token = _scanner->next();
            if ( token=="Circle" ) {
                _scanner->next();
                _scanner->next();
                _scanner->next();
                _scanner->next();
                double x1 = _scanner->nextDouble();
                _scanner->next();
                double y1 = _scanner->nextDouble();
                _scanner->next();
                _scanner->next();
                _scanner->next();
                double x2 = _scanner->nextDouble();
                _scanner->next();
                double y2 = _scanner->nextDouble();
                _scanner->next();
                _scanner->next();
                _scanner->next();
                Point p1(x1,y1);Point p2(x2,y2);
                _builder.buildCircle(p1,p2);
            }
            if ( token=="Rectangle" ) {
                _scanner->next();
                _scanner->next();
                _scanner->next();
                _scanner->next();
                double x1 = _scanner->nextDouble();
                _scanner->next();
                double y1 = _scanner->nextDouble();
                _scanner->next();
                _scanner->next();
                _scanner->next();
                double x2 = _scanner->nextDouble();
                _scanner->next();
                double y2 = _scanner->nextDouble();
                _scanner->next();
                _scanner->next();
                _scanner->next();
                _scanner->next();
                _scanner->next();
                _scanner->next();
                double x3 = _scanner->nextDouble();
                _scanner->next();
                double y3 = _scanner->nextDouble();
                _scanner->next();
                _scanner->next();
                _scanner->next();
                double x4 = _scanner->nextDouble();
                _scanner->next();
                double y4 = _scanner->nextDouble();
                _scanner->next();
                _scanner->next();
                _scanner->next();
                Point p1(x1,y1);Point p2(x2,y2);Point p3(x3,y3);Point p4(x4,y4);
                std::vector<Point> input= _findCommonPoint(p1,p2,p3,p4);
                _builder.buildRectangle(input[0],input[1],input[2]);
                // _builder.buildRectangle(new Point(0,0),new Point(2,0),new Point(0,2));
            }
            if ( token=="Triangle" ) {
                _scanner->next();
                _scanner->next();
                _scanner->next();
                _scanner->next();
                double x1 = _scanner->nextDouble();
                _scanner->next();
                double y1 = _scanner->nextDouble();
                _scanner->next();
                _scanner->next();
                _scanner->next();
                double x2 = _scanner->nextDouble();
                _scanner->next();
                double y2 = _scanner->nextDouble();
                _scanner->next();
                _scanner->next();
                _scanner->next();
                _scanner->next();
                _scanner->next();
                _scanner->next();
                double x3 = _scanner->nextDouble();
                _scanner->next();
                double y3 = _scanner->nextDouble();
                _scanner->next();
                _scanner->next();
                _scanner->next();
                double x4 = _scanner->nextDouble();
                _scanner->next();
                double y4 = _scanner->nextDouble();
                _scanner->next();
                _scanner->next();
                _scanner->next();
                Point p1(x1,y1);Point p2(x2,y2);Point p3(x3,y3);Point p4(x4,y4);
                std::vector<Point> input= _findCommonPoint(p1,p2,p3,p4);
                _builder.buildTriangle(input[0],input[1],input[2]);
            }
            else if( token=="CompoundShape" ) {
                _builder.buildCompoundShape();
                _scanner->next();
            }
            else if( token=="(" ) {
                _token.push(token);
                // _scanner->next();
            }
            else if( token == ")" ) {
                if(_token.empty()){
                    _builder.buildCompoundEnd();
                }
                else{
                    _token.pop();
                }
                // _scanner->next();
            }
        }
    }

    std::vector<Shape*> getResult() {
        return _builder.getResult();
    }

    std::vector<Point> _findCommonPoint(Point a , Point b ,Point c , Point d){
        std::vector<Point> result;
        if(a.operator==(b)){
            result.push_back(a); 
            result.push_back(c);
            result.push_back(d);
        }
        else if(a.operator==(c)){
            result.push_back(a); 
            result.push_back(b);
            result.push_back(d);
        }
        else if(a.operator==(d)){
            result.push_back(a); 
            result.push_back(b);
            result.push_back(c);
        }
        else if(b.operator==(c)){
            result.push_back(b); 
            result.push_back(a);
            result.push_back(d);
        }
        else if(b.operator==(d)){
            result.push_back(b); 
            result.push_back(a);
            result.push_back(c);
        }
        else if(c.operator==(d)){
            result.push_back(c); 
            result.push_back(a);
            result.push_back(b);
        }
        return result;
    }
};