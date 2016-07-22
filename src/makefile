CPP=g++
CPPFLAGS=-std=c++11
heap: heap_test.o
	$(CPP) $(CPPFLAGS) -o heap heap_test.o
heap_test.o: heap_test.cpp
.PHONY: clean
clean: 
	$(RM) heap heap_test.o