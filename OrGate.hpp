#ifndef ORGATE
#define ORGATE

#include "GateLogique.hpp"

class OrGate: public GateLogique{
  public:
  OrGate( Gate* const g1,  Gate* const g2); 
   virtual void Calcul();  
   void Afficher(Schema& sch);
};

#endif
