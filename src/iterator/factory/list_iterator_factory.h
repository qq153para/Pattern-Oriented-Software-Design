#pragma once
#include "./iterator_factory.h"
#include "../list_compound_iterator.h"
#include "../null_iterator.h"

class ListIteratorFactory : public IteratorFactory {
    ListIteratorFactory();
    Iterator *createIterator();
    Iterator *createIterator(std::list<Shape *>::const_iterator begin, std::list<Shape *>::const_iterator end) ; 
    private:
        static ListIteratorFactory s_self;
};
