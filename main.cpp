
#include"Circuit.hpp"

int main(int argc, char **argv){
            InputGate* a = new InputGate('a',0);
			InputGate* b = new InputGate('b',0);
			OrGate* or1 = new OrGate(a, b);
			AndGate* and1 = new AndGate(a,b);
			XorGate* xor1 = new XorGate(or1,and1); 
			OutputGate* A = new OutputGate('A',xor1);
			Negate* n= new Negate(and1);
			OutputGate* B = new OutputGate('B',n);
						Circuit * circuit1= new Circuit(std::vector<InputGate*>{a,b},
											std::vector<GateLogique*>{or1,and1,xor1,n},
											std::vector<OutputGate*>{A,B});


		
		circuit1->AfficherCircuit();
		a->setVal(1);
		circuit1->AfficherCircuit();
            
  
return 0;
}