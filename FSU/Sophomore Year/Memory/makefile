all:proj2.x test_list.x

proj2.x: mem_manager.o MyMemory.o MyMemoryBlock.o
        g++ -std=c++11 -o proj2.x mem_manager.o MyMemory.o MyMemoryBlock.o

mem_manager.o: mem_manager.cpp MyMemory.h
        g++ -std=c++11 -c mem_manager.cpp

MyMemory.o: MyMemory.cpp MyMemory.h List.h List.hpp
        g++ -std=c++11 -c MyMemory.cpp

MyMemoryBlock.o: MyMemoryBlock.cpp MyMemoryBlock.h
        g++ -std=c++11 -c MyMemoryBlock.cpp

test_list.x:test_list.o
        g++ -std=c++11 -o test_list.x test_list.o

test_list.o: test_list.cpp List.h List.hpp
        g++ -std=c++11 -c test_list.cpp
