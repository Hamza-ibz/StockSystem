CXX = g++
CXXFLAGS = -g -Wall -Wextra
.PHONY: all
all : store
store: mainstore.cpp store2.o
	$(CXX) $(CXXFLAGS) -o $@ $^
store2.o: store2.cpp  store.h
	$(CXX) $(CXXFLAGS) -c $<
.PHONY : clean
clean:
	rm *~ *.o store
