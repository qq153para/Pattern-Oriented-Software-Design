#include "./bfs_iterator_factory.h"
#include "../null_iterator.h"
#include "../bfs_compound_iterator.h"

BFSIteratorFactory BFSIteratorFactory::s_self ;
Iterator * BFSIteratorFactory::createIterator(){
        return new NullIterator();
};
Iterator * BFSIteratorFactory::createIterator(std::list<Shape *>::const_iterator begin, std::list<Shape *>::const_iterator end){
        return new BFSCompoundIterator<std::list<Shape *>::const_iterator>(begin, end);
};
BFSIteratorFactory::BFSIteratorFactory(){
        IteratorFactory::_register(std::string("BFS"),this);
}
