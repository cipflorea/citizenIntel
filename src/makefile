CPP=g++
heap: heap_test.o
	$(CPP) -std=c++11 -o heap heap_test.o
heap_test.o: heap_test.cpp
.PHONY: clean
clean: 
	$(RM) heap heap_test.o