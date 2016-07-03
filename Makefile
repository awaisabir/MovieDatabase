OBJ = listFunctions.o main.o

executable: $(OBJ)
	gcc -o executable $(OBJ)

main.o: main.c typedefs.h
	gcc -c main.c

listFunctions.o: listFunctions.c typedefs.h

clean:
	rm executable $(OBJ)
