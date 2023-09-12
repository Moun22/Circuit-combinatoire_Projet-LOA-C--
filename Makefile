CPP=g++ --std=c++11

CFLAGS= -Wall

all : main.o Gate.o InputGate.o OutputGate.o InputOutputGate.o GateLogique.o AndGate.o OrGate.o XorGate.o NorGate.o NandGate.o NxorGate.o Circuit.o Schema.o Negate.o
	$(CPP) $(CFLAGS) -o $@ $^

main.o : main.cpp
	$(CPP) $(CFLAGS) -c $<

GateLogique.o : GateLogique.cpp GateLogique.hpp 
	$(CPP) $(CFLAGS) -c $<

Circuit.o : Circuit.cpp Circuit.hpp 
	$(CPP) $(CFLAGS) -c $<	

Schema.o : Schema.cpp Schema.hpp 
	$(CPP) $(CFLAGS) -c $<	

NorGate.o : NorGate.cpp NorGate.hpp 
	$(CPP) $(CFLAGS) -c $<

NxorGate.o : NxorGate.cpp NxorGate.hpp 
	$(CPP) $(CFLAGS) -c $<	

NandGate.o : NandGate.cpp NandGate.hpp 
	$(CPP) $(CFLAGS) -c $<		

AndGate.o : AndGate.cpp AndGate.hpp 
	$(CPP) $(CFLAGS) -c $<

Negate.o : Negate.cpp Negate.hpp 
	$(CPP) $(CFLAGS) -c $<	

OrGate.o : OrGate.cpp OrGate.hpp 
	$(CPP) $(CFLAGS) -c $<

XorGate.o : XorGate.cpp XorGate.hpp 
	$(CPP) $(CFLAGS) -c $<		

InputGate.o : InputGate.cpp InputGate.hpp 
	$(CPP) $(CFLAGS) -c $<

OutPutGate.o : OutputGate.cpp OutputGate.hpp
	$(CPP) $(CFLAGS) -c $<
InputOutputGate.o : InputOutputGate.cpp InputOutputGate.hpp
	$(CPP) $(CFLAGS) -c $<

Gate.o : Gate.cpp Gate.hpp
	$(CPP) $(CFLAGS) -c $<
	
clean :
	rm *.o
test:
	./all