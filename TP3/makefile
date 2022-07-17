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
OBJS = $(OBJ)/main.o $(OBJ)/HashLE.o $(OBJ)/Email.o $(OBJ)/Arvore.o
HDRS = $(INC)/Email.h $(INC)/Arvore.h $(INC)/HashLE.h 
CFLAGS = -Wall -c -I$(INC) -g

EXE = $(BIN)/main


all: $(EXE)

$(BIN)/main: $(OBJS)
	$(CC) -o $(EXE) $(OBJS) $(LIBS)

$(OBJ)/Email.o: $(HDRS) $(SRC)/Email.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Email.o $(SRC)/Email.cpp

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/Arvore.o: $(HDRS) $(SRC)/Arvore.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Arvore.o $(SRC)/Arvore.cpp

$(OBJ)/HashLE.o: $(HDRS) $(SRC)/HashLE.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/HashLE.o $(SRC)/HashLE.cpp
	
clean:
	rm -r $(BIN)/* $(OBJ)/*
