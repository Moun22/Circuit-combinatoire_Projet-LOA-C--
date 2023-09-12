#ifndef NANDGATE
#define NANDGATE

#include "GateLogique.hpp"

class NandGate: public GateLogique{
  public:
  NandGate( Gate* const g1,  Gate* const g2); 
   virtual void Calcul();  
   void Afficher(Schema& sch);
};

#endif
