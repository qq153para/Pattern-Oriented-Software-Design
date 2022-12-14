#pragma once
#include<iostream>
#include <list>
#include "iterator.h"
#include "./factory/list_iterator_factory.h"

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
       for (std::list<Shape*>::const_iterator it = _begin; it != _end; ++it){
                _shapes.push_back((*it));
                _shapesout.push_back((*it));
        }
        while(_shapes.empty()==false){
            _currentShape=_shapes.front();
            _current=_currentShape->createIterator(new ListIteratorFactory());
            _shapes.pop_front();
            while(_current->isDone()==false){
                _shapes.push_back(_current->currentItem());
                _shapesout.push_back(_current->currentItem());
                _current->next();
            }
        }
        _thiscurrent=_shapesout.begin();
    }

    Shape* currentItem() const override {
            if(this->isDone()){
                throw "It is done";
            }
            else{
                return *_thiscurrent;
            }    
    }

    void next() override {
        if(this->isDone()){
                throw "It is done";
        }
        else{
            _thiscurrent++;
        }
    }

    bool isDone() const override {
        return _thiscurrent == _shapesout.end() ;        
    }
private:
    ForwardIterator _begin;
    ForwardIterator _end; 
    std::list<Shape *>::const_iterator _thiscurrent;
    Iterator* _current;
    Shape* _currentShape;
    std::list<Shape *> _shapes;
    std::list<Shape *> _shapesout;
    bool _isDone;   // 判斷父節點是否為最後

};