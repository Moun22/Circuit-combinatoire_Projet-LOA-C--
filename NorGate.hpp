#ifndef NORGATE
#define NORGATE

#include "GateLogique.hpp"

class NorGate: public GateLogique{
  public:
  NorGate( Gate* const g1,  Gate* const g2); 
   virtual void Calcul();  
   void Afficher(Schema& sch);
};

#endif
