#ifndef GATE
#define GATE
#include<iostream>

#include "Schema.hpp"

class Gate
{
protected:    
 std::string formule; bool val; bool actu;
 int i; int j; //Coordoonées sur le schéma


Gate();

void setFormule(const std::string formula);




private:
Gate(const Gate* gate);
Gate(const Gate& gate);


public:
virtual const std::string getFormule() const;
const bool getVal() const;
const std::pair<int,int> getCoord() const ;
void setLigne(const int l);
void setColonne(const int c);
void Dessiner(Schema& sh,int marge,std::string ss);
void setActu(bool a);
 bool getActu();
 void setVal(const bool value);

    

};
#endif