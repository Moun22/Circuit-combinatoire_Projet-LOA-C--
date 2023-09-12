#ifndef INPUTGATE
#define INPUTGATE

#include "Schema.hpp"
#include "InputOutputGate.hpp"
class InputGate: public InputOutputGate
{
public:
    InputGate(const char name, bool value);
     

};

#endif