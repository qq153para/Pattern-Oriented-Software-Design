#pragma once

#include "../iterator.h"
#include <list>
#include <map>

class IteratorFactory
{
public:
    virtual Iterator *createIterator() = 0;
    virtual Iterator *createIterator(std::list<Shape *>::const_iterator begin, std::list<Shape *>::const_iterator end) = 0;
    static IteratorFactory* getInstance(std::string name);
    IteratorFactory();
protected:
    static void _register(std::string name, IteratorFactory* factory);
    
private:
    static IteratorFactory* s_self;
    static std::map<std::string,IteratorFactory*> s_registry;
};