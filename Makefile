inference_engine_new: inference_engine_new.o
	g++ -std=c++11 inference_engine_new.o -o inference_engine_new
inference_engine_new.o: inference_engine_new.cpp
	g++ -Wall -ansi -pedantic -std=c++11 -c inference_engine_new.cpp
diagnosis_revised: diagnosis_revised.o
	g++ -std=c++11 diagnosis_revised.o -o diagnosis_revised
diagnosis_revised.o: diagnosis_revised.cpp
	g++ -Wall -ansi -pedantic -std=c++11 -c diagnosis_revised.cpp
clean:
	@rm -rf *.o inference_engine_new diagnosis_revised