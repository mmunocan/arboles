CPP=g++

OBJETOS=libs/BST.o libs/AVL.o libs/RBT.o libs/NodeBT.o libs/AVL_Node.o libs/RBT_Node.o

BINS=time_hipotesis_1 testBST testAVL testRBT

CPPFLAGS=-Wall -g -O2 -std=c++11 -O3 -DNDEBUG -w -lm

%.o: %.c
	$(CPP) $(CPPFLAGS) -c $< -o $@

all: clean bin

bin: $(OBJETOS) $(BINS)

testBST:
	$(CPP) $(CPPFLAGS) -o ./testBST testBST.cpp $(OBJETOS) 	

testAVL:
	$(CPP) $(CPPFLAGS) -o ./testAVL testAVL.cpp $(OBJETOS) 	
	
testRBT:
	$(CPP) $(CPPFLAGS) -o ./testRBT testRBT.cpp $(OBJETOS) 	

time_hipotesis_1:
	$(CPP) $(CPPFLAGS) -o ./time_hipotesis_1 time_hipotesis_1.cpp $(OBJETOS)

clean:
	rm -f $(OBJETOS) $(BINS)
	cd .; rm -f *.a $(BINS)