
.PHONY: all debug release clean

all: debug release

debug: calculator-dbg

calculator-dbg: calculator.cpp
	g++ -g -O0 calculator.cpp -o calculator-dbg -Wall

release: calculator

calculator: calculator.cpp
	g++ -O2 calculator.cpp -o calculator -DNDEBUG -Wall

clean:
	rm -f calculator calculator-dbg

