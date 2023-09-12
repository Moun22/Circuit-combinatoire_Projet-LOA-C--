#include "OutputGate.hpp"

OutputGate::OutputGate(const char name, Gate* const gate) :
	InputOutputGate(name)
    {
        porte=gate;
        std::string s(1,name);
        formule=s+"="+gate->getFormule();
        val = gate->getVal();
	}

Gate* const OutputGate::getPorte() const { return porte;} 

void OutputGate::Calcul(){
     this->setVal(this->getPorte()->getVal());
     std::string s(1,getNom());
     setFormule(s+"="+getPorte()->getFormule());
    
} 

void OutputGate::setGate( Gate* gate){
    porte=gate;
    this->Calcul();

}

std::ostream& operator<<(std::ostream& os, const OutputGate* og) {
  os<<og->getFormule()<<"="<<og->getVal() <<std::endl;
  return os;
}
