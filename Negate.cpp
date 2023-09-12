#include "Negate.hpp"

Negate::Negate( Gate* const g) : GateLogique{{g}} {Calcul();}

void Negate::Calcul(){
    std::string s = this->FonctionLogique("not");
    this->setFormule(s);
    this->setVal(!(this->getPortes().at(0)->getVal()));
}

void Negate::Afficher(Schema& sch){
    this->Dessiner(sch,1,"NOT");
}