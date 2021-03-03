inference_engine: inference_engine.o
	g++ -std=c++11 inference_engine.o -o inference_engine
inference_engine.o: inference_engine.cpp
	g++ -Wall -ansi -pedantic -std=c++11 -c inference_engine.cpp
diagnosis_revised: diagnosis_revised.o
	g++ -std=c++11 diagnosis_revised.o -o diagnosis_revised
diagnosis_revised.o: diagnosis_revised.cpp
	g++ -Wall -ansi -pedantic -std=c++11 -c diagnosis_revised.cpp
clean:
	@rm -rf *.o inference_engine diagnosis_revised
