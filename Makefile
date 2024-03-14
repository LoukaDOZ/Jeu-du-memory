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

executable:
	$(CC) -ansi -o executable $(OFILES) $(CFLAGS) -lgraph

clean-o-files:
	rm -f $(OFILES)


#-------------------------

.PHONY : build clean

install:
	tar -xf bibliotheque-graphique-iut-1.1.tar.xz
	cd bibliotheque-graphique-iut-1.1 && ./configure && make && make install

uninstall:
	cd bibliotheque-graphique-iut-1.1 && make uninstall
	rm -rf bibliotheque-graphique-iut-1.1 

build : $(OFILES) executable clean-o-files

run :
	./executable

clean : clean-o-files
	rm -f executable
