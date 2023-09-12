#include "OrGate.hpp"

OrGate::OrGate( Gate* const g1,  Gate* const g2) : GateLogique{{g1,g2}} {Calcul();}

void OrGate::Calcul(){
    std::string s = this->FonctionLogique("or");
    this->setFormule(s);
    this->setVal(this->getPortes().at(0)->getVal()||this->getPortes().at(1)->getVal());
}

void OrGate::Afficher(Schema& sch){
    this->Dessiner(sch,1,"OR");
}