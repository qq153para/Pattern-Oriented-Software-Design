#pragma once

#include "iterator.h"

class NullIterator : public Iterator
{
public:
    void first() override {
        throw "It's not a shapes";
    }

    Shape* currentItem() const override {
        throw "It's not a shapes";
    }

    void next() override {
        throw "It's no more shapes are at the next level";
    }

    bool isDone() const override { return true ;}
};