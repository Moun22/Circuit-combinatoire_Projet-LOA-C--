#ifndef SCHEMA
#define SCHEMA

#include <vector>
#include <iostream>


class OutputGate;
class Gate;
class GateLogique;
class Schema
{
  friend class Circuit;
private:
     int hauteur;
     int longeur;
     int nbGates;
    std::vector <std::vector <std::string> > schema;

    Schema();
	Schema(const Schema& s);
	Schema(const Schema* s);
    Schema (const int nb);

    void AjoutGateOut(const OutputGate* g);
    void AjoutGateLogic(const GateLogique* g);
    void GateOut( OutputGate* const g);
    void GateLogic( GateLogique* const g);
    void AjoutLignes(int nb);
    void AjoutColonnes(int nb);
    void ShowcaseLigne(int lc, int debut, int fin, char direction);
    
	

public:
    const int getHauteur() const;
    const int getLongeur() const;
    const int getnbGates() const;
    const std::vector <std::vector <std::string> > getSchema() const;
    void  setHauteur(const int h) ;
    void  setLongeur(const int l )  ;
    void  setnbGates(const int nb)  ;
    void setSchema(int l , int c, std::string s) ;
    void resetSchema();
    
         
    
    
};

std::ostream& operator<<(std::ostream& os, const Schema& s);




#endif
