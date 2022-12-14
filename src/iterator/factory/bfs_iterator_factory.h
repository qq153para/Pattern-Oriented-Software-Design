#pragma once

#include "./iterator_factory.h"

class BFSIteratorFactory : public IteratorFactory {
    BFSIteratorFactory();
    Iterator *createIterator() ;
    Iterator *createIterator(std::list<Shape *>::const_iterator begin, std::list<Shape *>::const_iterator end) ;
    private:
        static BFSIteratorFactory s_self;
};