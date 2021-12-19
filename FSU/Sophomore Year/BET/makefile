all: proj4_driver.x

proj4_driver.x:proj4_driver.o
	g++ -std=c++11 -o proj4_driver.x proj4_driver.o

proj4_driver.o: proj4_driver.cpp bet.h 
	g++ -std=c++11 -c proj4_driver.cpp

clean:
	rm -f *.o *.x core.*
