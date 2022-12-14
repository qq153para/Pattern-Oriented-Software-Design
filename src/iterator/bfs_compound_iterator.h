#pragma once

#include "iterator.h"
#include "../shape.h"
#include <list>
#include <queue>
#include<iostream>
class CompoundShape;

template<class ForwardIterator>
class BFSCompoundIterator : public Iterator
{
public:
    BFSCompoundIterator(ForwardIterator begin, ForwardIterator end) 
    :_begin(begin),_end(end)
    { 
        this->first();  
    }

    void first() override {
        _thiscurrent = _begin;
        _current= this;
        bfs.clear();
       for (std::list<Shape*>::const_iterator it = _begin; it != _end; ++it){
                // _current=(*it)->createDFSIterator();
                _shapes.push_back((*it));
                _shapesout.push_back((*it));
        }
        while(_shapes.empty()==false){
            _currentShape=_shapes.front();
            _current=_currentShape->createIterator();
            _shapes.pop_front();
            while(_current->isDone()==false){
                _shapes.push_back(_current->currentItem());
                _shapesout.push_back(_current->currentItem());
                _current->next();
            }
        }
        // } 
        _thiscurrent=_shapesout.begin();
    }

    Shape* currentItem() const override {
        // if(_begin==_end){
        //     throw "this compoundshpae does not have any shapes";
        // }
        // else if(_thiscurrent==_end){
        //     return _current->currentItem();
        // }
        // else{
            if(this->isDone()){
                throw "It is done";
            }
            else{
                return *_thiscurrent;
            }
        // } 
        
    }

    void next() override {
        if(this->isDone()){
                throw "It is done";
        }
        else{
        // if(_thiscurrent != _end){
            _thiscurrent++;
        // }
        // else{
        //     _current->next();
        // }
        }
    }

    bool isDone() const override {
        // if(this == _current ){

            return _thiscurrent == _shapesout.end() ;
        // }
        // else{

        //     return _current -> isDone();
        // }
         
    }
private:
    ForwardIterator _begin;
    ForwardIterator _end; 
    std::list<Shape *>::iterator _thiscurrent;
    Iterator* _current;
    Shape* _currentShape;
    std::list<Iterator *> bfs;
    std::list<Shape *> _shapes;
    std::list<Shape *> _shapesout;
    bool _isDone;   // 判斷父節點是否為最後

};