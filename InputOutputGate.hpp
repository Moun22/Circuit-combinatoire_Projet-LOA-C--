#ifndef INPUTOUTPUTGATE
#define INPUTOUTPUTGATE

#include "Gate.hpp"


class InputOutputGate: public Gate
{
    protected:
	const char nom;
    InputOutputGate(const char name);

    private:
    InputOutputGate();
	InputOutputGate(const InputOutputGate& iogate);
	InputOutputGate(const InputOutputGate* iogate);
	
    public:
    const char getNom() const;
    virtual ~InputOutputGate() = default;
    virtual void Afficher(Schema& sch);




};


#endif