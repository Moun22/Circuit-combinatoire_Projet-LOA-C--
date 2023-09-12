#include "Schema.hpp"
#include "GateLogique.hpp"
#include "OutputGate.hpp"

Schema::Schema(){
    hauteur=0;
    longeur=0;
    nbGates=0;
    schema= std::vector<std::vector<std::string>>();
}

Schema::Schema(const Schema& s){
    hauteur= s.getHauteur();
    longeur=s.getLongeur();
    nbGates= s.getnbGates();
    schema= s.getSchema();
}

Schema::Schema(const Schema* s){
    hauteur= s->getHauteur();
    longeur=s->getLongeur();
    nbGates= s->getnbGates();
    schema= s->getSchema();
}

Schema::Schema (const int nb){
    hauteur= nb ;
    longeur = 1;
    nbGates= nb; 
     schema=std::vector<std::vector<std::string>>(nb,std::vector<std::string>(4," "));

}


    void Schema::AjoutGateOut(const OutputGate* g){
        int finL= g->getCoord().first;
        int finC = g->getCoord().second;
        int l = g->getPorte()->getCoord().first;
        int c= g->getPorte()->getCoord().second;

         if (l < this->getnbGates()) {
		this->ShowcaseLigne(l, c + 1, finC - 1,'h');
        this->setSchema(l,finC,"*");
	
	}
        this->ShowcaseLigne(finC,l+1,finL-1,'v'); 
         
         
         }

    void Schema::AjoutGateLogic(const GateLogique* g){
         int finL= g->getCoord().first-1;
         int nbGate= 1;
         int margeV=-1;
         
         for(Gate* gate: g->getPortes()){
        int finC = g->getCoord().second+margeV;
        int l = gate->getCoord().first;
        int c= gate->getCoord().second;

        if(this->getnbGates()<l){
            int margeH=c/10;
            this->ShowcaseLigne(c, l+1, l+margeH+1,'v');
            l+=(margeH+2);
            this->schema.at(l).at(c)="*";
        
        }

       if (nbGate == 1 && ((finC-c) < 0 || l < this->getnbGates())) {
           margeV=-3; finC+= 2;
			}
		if ((finC-c) != 0) {
			if ((finC-c) > 0) { this->ShowcaseLigne(l, c+1, finC-1,'h'); }
			else { this->ShowcaseLigne(l, finC+1, c-1,'h'); }
            this->schema.at(l).at(finC)= "*";
			l++;
			nbGate++;
		}
		this->ShowcaseLigne(finC, l, finL,'v');
		margeV += 2;
             }
     }    

     void Schema::AjoutLignes(int nb){
         
         for (int i = 0; i < nb; i++)
         { 
             this->schema.push_back({});
            (this->hauteur)++;
            for (int j = 0; j < longeur; j++)
            {
              schema.at(hauteur-1).push_back(" ");
            }
           
         }
         
     }


void Schema::AjoutColonnes(int nb){
    for (int i = 0; i < this->getHauteur(); i++)
    { 
      for ( int j = 0; j < nb; j++)
      {
         this->schema.at(i).push_back(" ");
      }
       
    }
     (this->longeur)+=nb;
}

void Schema::ShowcaseLigne(int lc, int debut , int fin , char direction){
    if(direction == 'h'){
        for (int i = debut; i <=fin; i++)
        {
            if  (this->schema.at(lc).at(i)==" ") {
			this->schema.at(lc).at(i) = "-"; 
		}
		else if (this->schema.at(lc).at(i) == "|") {
            this->schema.at(lc).at(i) = "+";  
		}

        }
        
    }
    else if(direction == 'v'){

         for (int i = debut; i <=fin; i++)
        {
            if  (this->schema.at(i).at(lc)==" ") {
			this->schema.at(i).at(lc) = "|"; 
		}
		else if (this->schema.at(i).at(lc) == "-") {
            this->schema.at(i).at(lc) = "+";  
		}

        }

    }
}

void Schema::GateOut( OutputGate* const g){
    int l = g->getPorte()->getCoord().first;
    if(l<this->getnbGates()){
        l=this->getnbGates()+12;
        }
    else{
        l+=8;
    }
      g->setLigne(l);
      if(l+2>this->getHauteur()){
          this->AjoutLignes(10);
      }

   int c = g->getPorte()->getCoord().second;
	if (c == 0) {
		this->AjoutColonnes(10);
		g->setColonne(this->getLongeur() - 5);
	}
	else { g->setColonne(c); }   
}

void Schema::GateLogic(GateLogique* const g){
    int finL= this->getnbGates()-1;
    for (const Gate* gate : g->getPortes())
    {
        if (gate->getCoord().first > finL)
         { 
             finL = gate->getCoord().first;
          }
}

if(finL+10>this->getHauteur()){
    this->AjoutLignes(10);
    }
    g->setLigne(finL+10);

    int nb=0;
    float div=0;
     for (const Gate* gate : g->getPortes()){
         if(gate->getCoord().second==0){
             this->AjoutColonnes(10);
             g->setColonne(this->getLongeur()-5);
            break;
         }
         nb++;
         div+= ((gate->getCoord().second - div) / nb);

     }

    if(nb== g->getPortes().size()){
        int c = div;
             bool f=false;
        while(!f){
            if(c+5>this->getLongeur()){
                this->AjoutColonnes(10);
            }
            for (int i = -3; i < 1; i++)
            {
             std::string st = this->getSchema().at(g->getCoord().first).at(c+i);
             f=true;
             for(const char ch : st){
                 if(isalpha(ch)||isdigit(ch)||ch=='-'||ch==':'){
                        f=false; break;
                 }
             }
            
             }
             if(!f){
                 c+=10;
             }
            
        }
         g->setColonne(c);
    }
}

 const int Schema::getHauteur() const{
     return hauteur;
 }

    const int Schema::getLongeur() const{
        return longeur;
    }

    const int Schema::getnbGates() const{
        return nbGates;
    }

     void  Schema::setHauteur(const int h) {
         hauteur=h;
     }

    void  Schema::setLongeur(const int l)  {
        longeur= l ;
    }

    void  Schema::setnbGates(const int nb) {
        nbGates= nb;
    } 

    void Schema::setSchema(int l, int c,std::string s) {
        schema.at(l).at(c)=s;
    }
         

    const std::vector <std::vector <std::string>> Schema::getSchema() const{
        return schema;
    }

      void Schema::resetSchema(){
        this->schema=std::vector <std::vector <std::string>>(this->getnbGates(), std::vector <std::string>(10, " "));
    }

    std::ostream& operator<<(std::ostream& os, const Schema& s){

        for ( std::vector<std::string> ligne :s.getSchema())
        {   
            for ( std::string c :ligne)
        {
                os<<c;
        }
        os<<std::endl;

        }
        return os;
    }

   



