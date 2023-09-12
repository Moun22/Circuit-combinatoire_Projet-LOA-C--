#ifndef NEGATE
#define NEGATE

#include "GateLogique.hpp"

class Negate: public GateLogique{
  public:
  Negate( Gate* const g); 
   virtual void Calcul();  
   void Afficher(Schema& sch);
};

#endif
