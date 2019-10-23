CFLAGS = -Wall -std=c++11 -Wextra -Wno-unused -O1

OBJS = experimentoGenerico.cpp instanciasFavorablesDesfavorables.cpp longitudDeCicloVariable.cpp

.PHONY: all build clean 

all: build 

build: main.cpp $(OBJS)
	g++ $(CFLAGS) -o generator main.cpp $(OBJS) -I -v.

clean:
	rm -f generator out/*
