all: proj5.x

proj5.x:proj5.o passserver.o
	g++ -std=c++11 -o proj5.x proj5.o passserver.o -lcrypt

proj5.o: proj5.cpp passserver.h hashtable.h hashtable.hpp
	g++ -std=c++11 -c proj5.cpp

passserver.o: passserver.cpp passserver.h 
	g++ -std=c++11 -c passserver.cpp

clean:
	rm -f *.o *.x core.*
