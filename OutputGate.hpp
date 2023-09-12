#ifndef OUTPUTGATE
#define OUTPUTGATE
#include "Schema.hpp"
#include "InputOutputGate.hpp"


class OutputGate: public InputOutputGate
{
private:
    Gate* porte;

public:
    OutputGate(const char name, Gate* const gate );
    Gate* const getPorte() const;
    virtual void Calcul();
    void setGate( Gate* gate);
    

};
std::ostream& operator<<(std::ostream& os, const OutputGate* og);

#endif