#include "XorGate.hpp"

XorGate::XorGate( Gate* const g1,  Gate* const g2) : GateLogique{{g1,g2}} {Calcul();}

void XorGate::Calcul(){
    std::string s = this->FonctionLogique("xor");
    this->setFormule(s);
    this->setVal(this->getPortes().at(0)->getVal()^this->getPortes().at(1)->getVal());
}

void XorGate::Afficher(Schema& sch){
    this->Dessiner(sch,1,"XOR");
}