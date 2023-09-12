#ifndef CIRCUIT
#define CIRCUIT

#include "InputGate.hpp"
#include "OutputGate.hpp"
#include "Negate.hpp"
#include "AndGate.hpp"
#include "OrGate.hpp"
#include "XorGate.hpp"
#include "Negate.hpp"
#include "NandGate.hpp"
#include "NxorGate.hpp"
#include "Schema.hpp"
#include "NorGate.hpp"
#include<fstream>




class Circuit
{
private:
    const std::vector<InputGate*> ingates;
    const std::vector<GateLogique*> logicgates;
    const std::vector<OutputGate*> outgates;
     Schema schema;
public:
    Circuit();
    Circuit(const Circuit* c);
    Circuit(const Circuit& c);
    Circuit(const std::vector<InputGate*>& inportes,const std::vector<GateLogique*>& logicportes,const std::vector<OutputGate*>&outportes);
   virtual ~Circuit();

   void AfficherCircuit();
   

    const std::vector<InputGate*>& getIngates() const;
    const std::vector<GateLogique*>& getLogicgates() const;
    const std::vector<OutputGate*>& getOutgates() const;
     const Schema& getSchema() const ;

    void setIngates() const;
    void setLogicgates() const;
    void setOutgates() const;
    void Save();
    

};
std::ostream& operator<<(std::ostream& os, const Circuit& circuit);




#endif