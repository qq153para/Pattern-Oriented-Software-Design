#include "./dfs_iterator_factory.h"
#include "../null_iterator.h"
#include "../dfs_compound_iterator.h"

DFSIteratorFactory DFSIteratorFactory::s_self;
Iterator * DFSIteratorFactory::createIterator(){
        return new NullIterator();
};
Iterator * DFSIteratorFactory::createIterator(std::list<Shape *>::const_iterator begin, std::list<Shape *>::const_iterator end){
        return new DFSCompoundIterator<std::list<Shape *>::const_iterator>(begin, end);
};
DFSIteratorFactory::DFSIteratorFactory(){
        IteratorFactory::_register(std::string("DFS"),this);
}
