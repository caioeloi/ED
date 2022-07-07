#---------------------------------------------------------------------
# Opções	: make all - compila programa principal
#			: make clean - remove objetos e executável
#			: make test - compila e executa arquivo de teste
#---------------------------------------------------------------------

CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/Lista.o $(OBJ)/Carta.o $(OBJ)/Pessoa.o
HDRS = $(INC)/Lista.h $(INC)/Pessoa.h $(INC)/Carta.h $(INC)/msgassert.h
CFLAGS = -Wall -c -I$(INC) -g

EXE = $(BIN)/main


all: $(EXE)

$(BIN)/main: $(OBJS)
	$(CC) -o $(EXE) $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/Lista.o: $(HDRS) $(SRC)/Lista.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Lista.o $(SRC)/Lista.cpp

$(OBJ)/Pessoa.o: $(HDRS) $(SRC)/Pessoa.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Pessoa.o $(SRC)/Pessoa.cpp

$(OBJ)/Carta.o: $(HDRS) $(SRC)/Carta.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Carta.o $(SRC)/Carta.cpp

	
clean:
	rm -r $(BIN)/* $(OBJ)/*
