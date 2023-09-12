#include "InputOutputGate.hpp"


InputOutputGate::InputOutputGate():
Gate(),
nom(' ')
{}

InputOutputGate::InputOutputGate(const InputOutputGate& iogate): Gate(), nom(' ') 
{}

InputOutputGate::InputOutputGate(const InputOutputGate* iogate): Gate(), nom(' ')
{}

InputOutputGate::InputOutputGate(const char name) : Gate(), nom(name)
{}

const char InputOutputGate::getNom() const{
return nom;
}

void InputOutputGate::Afficher(Schema& sch){ 
    this->Dessiner(sch,0,std::string(1, this->getNom())); 
    }

