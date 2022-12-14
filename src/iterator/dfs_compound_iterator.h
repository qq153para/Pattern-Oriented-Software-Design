#pragma once

#include "iterator.h"
#include "../shape.h"
#include <list>
#include <iostream>
class CompoundShape;

template<class ForwardIterator>
class DFSCompoundIterator : public Iterator
{
public:
    DFSCompoundIterator(ForwardIterator begin, ForwardIterator end) 
    :_begin(begin),_end(end)
    {
        this ->first();
    }

    void first() override {

        if(_begin == _end){
            _thiscurrent=_shpaes.begin();
        }
        else{
            _shpaes.clear();
            for (std::list<Shape*>::const_iterator it = _begin; it != _end; ++it){
                _currentIterator=(*it)->createDFSIterator();
                _shpaes.push_back((*it));
                while(_currentIterator->isDone()==false){
                    _shpaes.push_back(_currentIterator->currentItem());
                    _currentIterator->next();
                }

            }
            _thiscurrent=_shpaes.begin();
        }
    }

    Shape* currentItem() const override {
        if(this->isDone()){
            throw "It is done ";
        }
        else{
            return *_thiscurrent ;
        }
        
    }

    void next() override {
        if(this->isDone()){
            throw "It is done ";
        }
        else{
            _thiscurrent++;
        }
    }

    bool isDone() const override {
        return _thiscurrent==_shpaes.end();
    }
private:
    ForwardIterator _begin;
    ForwardIterator _end;
    std::list<Shape *>::iterator _thiscurrent;
    Iterator* _currentIterator;
    std::list<Shape *> _shpaes;
};