#ifndef ANDGATE
#define ANDGATE

#include "GateLogique.hpp"

class AndGate: public GateLogique{
  public:
  AndGate( Gate* const g1,  Gate* const g2); 
  virtual void Calcul();  
    void Afficher(Schema& sch);
};

#endif
