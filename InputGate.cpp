#include "InputGate.hpp"


InputGate::InputGate(const char name, bool value): InputOutputGate(name)  
{
    formule= std::string(1, name);
    val=value;
    
}

