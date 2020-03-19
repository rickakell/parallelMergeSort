CXX = g++
CYY = clang++
FLAGS = -W -Wall -pedantic-errors -g -std=c++11
LIBRARIES = -lpthread
EXECUTABLE = sort

.PHONY: default run clang

default: run

run:
		${CXX} ${FLAGS} *.cpp ${LIBRARIES} -o ${EXECUTABLE}

clang:
		${CYY} ${FLAGS} *.cpp ${LIBRARIES} -o ${EXECUTABLE}

clean:
		-@rm -rf *.o program core