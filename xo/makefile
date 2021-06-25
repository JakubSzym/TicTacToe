TRGDIR=./
OBJ=./obj
FLAGS=-Wall -pedantic -std=c++1z -iquote inc
__start__:${TRGDIR}/xo

${TRGDIR}/xo: ${OBJ}/main.o ${OBJ}/board.o ${OBJ}/game.o
	g++ -o ${TRGDIR}/xo ${OBJ}/main.o ${OBJ}/board.o ${OBJ}/game.o
${OBJ}:
	 md ${OBJ};

${OBJ}/main.o: main.cpp game.hh
	g++ -c ${FLAGS} -o ${OBJ}/main.o main.cpp
${OBJ}/board.o: board.cpp board.hh
	g++ -c ${FLAGS} -o ${OBJ}/board.o board.cpp
${OBJ}/game.o: game.cpp game.hh
	g++ -c ${FLAGS} -o ${OBJ}/game.o game.cpp

clean:
	rm -f ${TRGDIR}/xo ${OBJ}/*