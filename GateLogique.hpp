#ifndef LOGICGATE
#define LOGICGATE
#include <vector>
#include "Gate.hpp"


class GateLogique : public Gate{
   protected:
    // const std::pair<Gate*,Gate*> portes;
    const std::vector<Gate*> portes;
    GateLogique(const std::vector<Gate*> gates);

    private:
    GateLogique();
	GateLogique(const GateLogique& lgate);
	GateLogique(const GateLogique* lgate);
    
    public:
    virtual ~GateLogique() = default;
    std::string const FonctionLogique(std::string const porte);
    std::vector<Gate*> const getPortes() const;
     virtual void Calcul()=0;
     virtual void Afficher(Schema& sch)=0;
};
std::ostream& operator<<(std::ostream& os, const GateLogique* lg);


#endif