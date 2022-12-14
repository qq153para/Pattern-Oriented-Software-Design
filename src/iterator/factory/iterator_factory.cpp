#include "./iterator_factory.h"
#include <map>
IteratorFactory* IteratorFactory::s_self=0;
std::map<std::string,IteratorFactory*> IteratorFactory::s_registry;
IteratorFactory::IteratorFactory(){
    
};

IteratorFactory* IteratorFactory::getInstance(std::string name){
    std::map<std::string,IteratorFactory*>::iterator it =s_registry.find(name);
    if(s_registry.end()!=it){
        return it->second;
    }
    return nullptr;
};
void IteratorFactory::_register(std::string name, IteratorFactory* factory){
    if(s_registry.find(name)!=s_registry.end()){
        throw name +" has been instantiated!";
    }
    s_registry[name]=factory;
};