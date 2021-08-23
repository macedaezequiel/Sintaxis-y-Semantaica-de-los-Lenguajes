SOURCE = scanner.c parser.c calc.c logger.c tablaSimbolos.c
BIN = calc
OBJ = scanner.o parser.o calc.o logger.o tablaSimbolos.o
CC = gcc
CFLAGS = -std=c11 -g 

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN) $(CFLAGS)

run: $(BIN)
	$(BIN)
	

clean:
	rm -rf $(OBJ) $(BIN)

$(OBJ): $(SOURCE)
	$(CC) -c $(SOURCE) $(CFLAGS)