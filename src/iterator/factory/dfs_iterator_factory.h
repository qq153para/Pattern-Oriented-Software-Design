#pragma once

#include "./iterator_factory.h"
class DFSIteratorFactory : public IteratorFactory {
    DFSIteratorFactory();
    Iterator *createIterator() ;
    Iterator *createIterator(std::list<Shape *>::const_iterator begin, std::list<Shape *>::const_iterator end) ; 
    private:
        static DFSIteratorFactory s_self;
};