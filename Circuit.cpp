#include"Circuit.hpp"
#include <sstream>



Circuit::Circuit() : ingates( std::vector<InputGate*>() ), logicgates( std::vector<GateLogique*>()),
					outgates(std::vector<OutputGate*>()) {
                        schema=new Schema(1);
                        }


Circuit::Circuit(const Circuit* c): ingates( c->getIngates() ), logicgates( c->getLogicgates()),
					outgates(c->getOutgates()){
                        schema=c->getSchema();
                    }

Circuit::Circuit(const Circuit& c): ingates( c.getIngates() ), logicgates( c.getLogicgates()),
					outgates(c.getOutgates()){
                        schema=c.getSchema();
                    }

Circuit::Circuit(const std::vector<InputGate*>& inportes,const std::vector<GateLogique*>& logicportes,const std::vector<OutputGate*>& outportes)
: ingates(inportes),logicgates(logicportes),outgates(outportes)
{
    schema=new Schema(ingates.size());
}

Circuit::~Circuit(){
   for (InputGate* ingate :ingates) {
        delete ingate; }

	for (GateLogique* logicgate : logicgates) { 
        delete logicgate; 
        }

	for (OutputGate* outgate : outgates) {
         delete outgate;
    
     }
     
}

void Circuit::AfficherCircuit(){
    std::string s;
    this->schema.setHauteur(this->getSchema().getnbGates());
    this->schema.setLongeur(1);
	this->schema.resetSchema();
    int l=0;
    for(GateLogique* gate: this->getLogicgates()){
            gate->setActu(false);
    }
     std::cout<< "Les portes d’entrée:"<<std::endl;
     std::string change;
     std::string newvalue;
     
    for(InputGate* gate: this->getIngates()){
    
        gate->setLigne(l);
        gate->setColonne(0);
        gate->Afficher(this->schema);
        l++;
           std::cout<< gate->getNom()<<"="<<gate->getVal()<<" Voulez-vous changé la valeur de cette porte ?"<<std::endl;
           std::cin>> change ;
           if(change=="y" || change =="yes" || change=="oui"){
            
                std::cout<<"Donnez la nouvelle valeur de "<<gate->getNom()<<" : ";
               do
               {
                std::cin>> newvalue;
                if(newvalue=="1" || newvalue=="true" || newvalue=="vrai")
                    gate->setVal(true);
                    else if(newvalue=="0" || newvalue=="faux" || newvalue=="false")
                    gate->setVal(false);
                    else
                    std::cout<<std::endl<<"Valeur invalide, donnez la nouvelle valeur de "<<gate->getNom()<<" : ";

               } while (newvalue!="1" && newvalue!="true" && newvalue != "vrai" && newvalue=="0" && newvalue=="faux" && newvalue=="false");
               gate->Afficher(this->schema);

           
    }}
    bool complet=false;
    
    while(!complet){
        
        complet=true;
        for(GateLogique* lg: this->getLogicgates()){
            
            if(!lg->getActu()){
                std::cout << "__________________________________" << std::endl<< std::endl;
                bool actu2=true;
                for(Gate* g:lg->getPortes()){
                    if(!g->getActu()){
                        actu2=true;
                        complet=false;
                    }
                }
                if(actu2){
                    
                    lg->Calcul();
                    lg->setActu(true);
                    std::cout<<lg;
                    this->schema.GateLogic(lg);
                    lg->Afficher(this->schema);
                    this->schema.AjoutGateLogic(lg);
                    std::cout<<*this;
                    
                }
            }
        }
        
    }
 std::cout << "__________________________________" << std::endl<< std::endl;
 std::cout<< "Les portes de sortie:"<<std::endl;
    for(OutputGate* og: this->getOutgates()){
        og->Calcul();
		this->schema.GateOut(og);
        og->Afficher(this->schema);
		this->schema.AjoutGateOut(og);
		std::cout<<og<<std::endl;
	}
	std::cout <<*this;
    std::cout<<"Voulez vous sauvegarder ce circuit? ";
    std::cin >>s;
           if(s=="y" || s =="yes" || s=="oui"){
               this->Save();
    }
    
}

const std::vector<InputGate*>& Circuit::getIngates() const { return this->ingates; }
const std::vector<GateLogique*>& Circuit::getLogicgates() const { return this->logicgates; }
const std::vector<OutputGate*>& Circuit::getOutgates() const { return this->outgates; }
 const Schema& Circuit::getSchema() const {
     return this->schema;
 }

 void Circuit::Save(){
 std::ofstream file;
 std::string s; 
 std::cout<<"Donnez un nom au fichier: ";
 std::cin>>s;
 file.open(s+".txt");
    for (OutputGate* gate: this->getOutgates())
     {
         file << gate->getFormule()<<std::endl;
        
     }
     
     file<< this->getSchema();
     
 

 }


std::ostream& operator<<(std::ostream& os, const Circuit& circuit){
	os << circuit.getSchema();
	return os;
}

