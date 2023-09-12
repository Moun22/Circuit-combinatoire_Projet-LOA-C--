#include "Gate.hpp"

Gate::Gate(){
formule="default";
val=false;
actu=false;
}

Gate::Gate(const Gate& gate) {
    Gate();
    
}

Gate::Gate(const Gate* gate) {
    Gate();
   
}

const std::string Gate::getFormule()const{
    return formule;
}

 const bool Gate::getVal()const{
    return val;
}

void Gate::setFormule(const std::string formula){
     formule=formula;
}

void Gate::setVal(const bool value){
    val=value;
    
}

const std::pair<int,int> Gate::getCoord()const{
    return std::pair<int,int>(i,j);
}

void Gate::setLigne(const int l ){
    this->i=l;
}
void Gate::setColonne(const int c){
    this->j=c;
}
void Gate::Dessiner(Schema& sh, int marge,std::string s)
{
    for (int  i = 0; i < s.size(); i++)
    {
        sh.setSchema(this->getCoord().first,this->getCoord().second-marge+i,s.substr(i,1));
    }
    sh.setSchema(this->i, this->j - marge + s.size(), ":");
	sh.setSchema(this->i, this->j - marge + s.size() + 1, std::to_string(this->getVal()));

}

bool Gate::getActu(){
    return actu;
}
void Gate::setActu(bool a){
    actu=a;
}