#include "NandGate.hpp"

NandGate::NandGate( Gate* const g1,  Gate* const g2) : GateLogique{{g1,g2}} {Calcul();}

void NandGate::Calcul(){
    std::string s = this->FonctionLogique("nand");
    this->setFormule(s);
    this->setVal(!(this->getPortes().at(0)->getVal()&&this->getPortes().at(1)->getVal()));
}
void NandGate::Afficher(Schema& sch){
    this->Dessiner(sch,1,"NAND");
}