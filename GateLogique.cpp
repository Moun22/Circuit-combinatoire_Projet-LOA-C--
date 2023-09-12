#include"GateLogique.hpp"

GateLogique::GateLogique():
Gate(),
portes(std::vector<Gate*> ())
{}

GateLogique::GateLogique(const GateLogique& lgate): Gate(), portes(lgate.getPortes()) 
{}

GateLogique::GateLogique(const GateLogique* lgate): Gate(), portes(lgate->getPortes())
{}

GateLogique::GateLogique(const std::vector<Gate*> gates): Gate(), portes(gates)
{}

 std::vector<Gate*> const GateLogique::getPortes() const { return this->portes; }

std::string const GateLogique::FonctionLogique(std::string const porte){
    std::string s= porte + "(";
    if(this->getPortes().size()==1){
        s.append(this->getPortes().at(0)->getFormule());
    }
    else {
         s.append(this->getPortes().at(0)->getFormule()+","+this->getPortes().at(1)->getFormule());
    }
    s.append(")");
    return s;
}

std::ostream& operator<<(std::ostream& os, const GateLogique* lg){
    os << lg->getFormule()<< "="<<lg->getVal()<<std::endl<< std::endl << std::endl;
    return os;
}






