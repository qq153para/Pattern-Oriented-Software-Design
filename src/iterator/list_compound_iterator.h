#pragma once

#include "./iterator.h"

template <class ForwardIterator>
class ListCompoundIterator : public Iterator
{
public:
    ListCompoundIterator(ForwardIterator begin, ForwardIterator end) :_begin(begin),_end(end)
    { 
        this->first();  
    }

    void first() override {
        _thiscurrent = _begin;   
    }

    Shape *currentItem() const override {
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
    std::list<Shape *>::const_iterator _thiscurrent;
};
