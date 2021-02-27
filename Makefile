inference_engine_new: inference_engine_new.o
	g++ -std=c++11 inference_engine_new.o -o inference_engine_new
inference_engine_new.o: inference_engine_new.cpp
	g++ -Wall -ansi -pedantic -std=c++11 -c inference_engine_new.cpp
clean:
	@rm -rf inference_engine_new.o inference_engine_new