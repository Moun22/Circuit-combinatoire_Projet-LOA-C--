#ifndef XORGATE
#define XORGATE

#include "GateLogique.hpp"

class XorGate: public GateLogique{
  public:
  XorGate( Gate* const g1,  Gate* const g2); 
   virtual void Calcul();  
   void Afficher(Schema& sch);
};

#endif
