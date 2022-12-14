#include "./dfs_iterator_factory.h"
#include "../null_iterator.h"
#include "../dfs_compound_iterator.h"

Iterator * DFSIteratorFactory::createIterator(){
        return new NullIterator();
        // throw "qweqwe";
};
Iterator * DFSIteratorFactory::createIterator(std::list<Shape *>::const_iterator begin, std::list<Shape *>::const_iterator end){
        return new DFSCompoundIterator(begin, end);
        // throw "qweqwe";
};
