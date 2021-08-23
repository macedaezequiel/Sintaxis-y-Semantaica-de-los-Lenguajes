SOURCE = scanner.c calc.c logger.c tablaSimbolos.c parser.c
BIN = calc
OBJ = scanner.o parser.o calc.o logger.o tablaSimbolos.o
CC = gcc
CFLAGS = -std=c11 -g 
FLEXL=scanner.l
FLEXC=scanner.c
BISONY=parser.y
BISONC=parser.c
BISONH=bison.h
LEXC=scanner.c
RM = rm -f

$(BIN): $(OBJ)  $(BISONC) $(LEXC)
	$(CC) $(OBJ) -o $(BIN) $(CFLAGS)

$(OBJ): $(SOURCE)
	$(CC) -c $(SOURCE) $(CFLAGS)

run: $(BIN)
	./$(BIN) <calcIn.txt> calcOut.txt
	

clean:
	$(RM) $(OBJ) $(BIN)
	$(RM) $(LEXC)
	$(RM) $(BISONC)
	$(RM) $(BISONH)
	$(RM) calcOut.txt

all: clean $(BIN) run

$(FLEXC): $(FLEXL)
	flex -o$(FLEXC) $(FLEXL)


$(BISONC): $(BISONY)
	bison -o$(BISONC) $(BISONY) --defines=$(BISONH)
	