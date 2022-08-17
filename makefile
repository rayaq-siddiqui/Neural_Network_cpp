CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = nn_test
OBJECTS = neuron.o layers/layer.o layers/dense.o layers/input.o neuralNetwork.o nn_test.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}


.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}