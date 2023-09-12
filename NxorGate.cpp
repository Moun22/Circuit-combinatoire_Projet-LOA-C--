#include "NxorGate.hpp"

NxorGate::NxorGate( Gate* const g1,  Gate* const g2) : GateLogique{{g1,g2}} {Calcul();}

void NxorGate::Calcul(){
    std::string s = this->FonctionLogique("nxor");
    this->setFormule(s);
    this->setVal(!(this->getPortes().at(0)->getVal()^this->getPortes().at(1)->getVal()));
}

void NxorGate::Afficher(Schema& sch){
    this->Dessiner(sch,1,"NXOR");
}