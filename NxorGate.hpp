#ifndef NXORGATE
#define NXORGATE

#include "GateLogique.hpp"

class NxorGate: public GateLogique{
  public:
  NxorGate( Gate* const g1,  Gate* const g2); 
   virtual void Calcul();  
   void Afficher(Schema& sch);
};

#endif
