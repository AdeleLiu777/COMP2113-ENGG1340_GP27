FLAGS = -pedantic-errors -std=c++11
newgame.o: newgame.cpp newgame.h
	g++ $(FLAGS) -c newgame.cpp
board.o: board.cpp board.h
	g++ $(FLAGS) -c board.cpp
deal_hide.o: deal_hide.cpp deal_hide.h
	g++ $(FLAGS) -c deal_hide.cpp
collect.o: collect.cpp collect.h deal_hide.h
	g++ $(FLAGS) -c collect.cpp
move.o: move.cpp move.h deal_hide.h
	g++ $(FLAGS) -c move.cpp
success.o: success.cpp success.h
	g++ $(FLAGS) -c success.cpp
deal.o: deal.cpp deal.h
	g++ $(FLAGS) -c deal.cpp
main.o: main.cpp newgame.h board.h deal_hide.h collect.h move.h success.h deal.h
	g++ $(FLAGS) -c main.cpp
main: newgame.o board.o deal_hide.o collect.o move.o success.o deal.o main.o
	g++ $(FLAGS) $^ -o main
clean:
	rm -f newgame.o board.o collect.o deal_hide.o move.o success.o deal.o main.o main my*.txt
.PHONY: clean
