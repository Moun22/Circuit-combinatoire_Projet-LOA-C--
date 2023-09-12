#include "NorGate.hpp"

NorGate::NorGate( Gate* const g1,  Gate* const g2) : GateLogique{{g1,g2}} {Calcul();}

void NorGate::Calcul(){
    std::string s = this->FonctionLogique("nor");
    this->setFormule(s);
    this->setVal(!(this->getPortes().at(0)->getVal()||this->getPortes().at(1)->getVal()));
}

void NorGate::Afficher(Schema& sch){
    this->Dessiner(sch,1,"NOR");
}