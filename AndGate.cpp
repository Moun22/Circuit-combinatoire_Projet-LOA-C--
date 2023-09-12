#include "AndGate.hpp"

AndGate::AndGate( Gate* const g1,  Gate* const g2) : GateLogique{{g1,g2}} {Calcul();}

void AndGate::Calcul(){
    std::string s = this->FonctionLogique("and");
    this->setFormule(s);
    this->setVal(this->getPortes().at(0)->getVal()&&this->getPortes().at(1)->getVal());
    
}

void AndGate::Afficher(Schema& sch){
    this->Dessiner(sch,1,"AND");
}