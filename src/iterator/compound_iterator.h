#pragma once

#include "iterator.h"
#include "../shape.h"
#include <list>

class CompoundShape;

template<class ForwardIterator>
class CompoundIterator : public Iterator
{
public:
    CompoundIterator(ForwardIterator begin, ForwardIterator end) 
    :_begin(begin),_end(end)
    { 
        this->first();  
    }

    void first() override {
        _thiscurrent = _begin;   
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
            return _thiscurrent == _end ;       
    }
private:
    ForwardIterator _begin;
    ForwardIterator _end; 
    std::list<Shape *>::iterator _thiscurrent;
};