CC = g++

OBJ_FILES = Card.o Hand.o CardComparator.o Deck.o

all: unit_test game

unit_test: unit_test.cc $(OBJ_FILES)
	$(CC) -o unit_test unit_test.cc $(OBJ_FILES)

game: game.cc $(OBJ_FILES)
	$(CC) -o game game.cc $(OBJ_FILES)

.c.o:
	$(CC) -c $< -o $@

