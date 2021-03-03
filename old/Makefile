#inference_engine: inference_engine.o
#	g++ -std=c++11 inference_engine.o -o inference_engine
#inference_engine.o: inference_engine.cpp
#	g++ -Wall -ansi -pedantic -std=c++11 -c inference_engine.cpp
diagnosis_finalized: diagnosis_finalized.o
	g++ -std=c++11 diagnosis_finalized.o -o diagnosis_revised
diagnosis_finalized.o: diagnosis_finalized.cpp
	g++ -Wall -ansi -pedantic -std=c++11 -c diagnosis_finalized.cpp
clean:
	@rm -rf *.o inference_engine diagnosis_finalized
