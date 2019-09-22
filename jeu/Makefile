but : Executable

OFILES = 	main.o \
			game.o \
			fin.o\
			accueil.o

CC = gcc

#-------------------------

fin.o : fin.h

accueil.o : accueil.h

game.o : game.h

main.o : accueil.h game.h fin.h


#-------------------------

Executable : $(OFILES)
			$(CC) -ansi -o Executable $(OFILES) $(CFLAGS) -lgraph

clean : -rm -f $(OFILES)

.PHONY : but clean

run : but
	./Executable