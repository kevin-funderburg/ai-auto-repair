repair: repair.o
	g++ -std=c++11 repair.o -o repair
sim.o: repair.cpp
	g++ -Wall -ansi -pedantic -std=c++11 -c repair.cpp
clean:
	@rm -rf repair.o repair