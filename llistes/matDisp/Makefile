OPCIONS = -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11
G++ = g++-10 # nomes necessari a versions antigues de g++

program.exe: program.o llegirMat.o
	$(G++) -o program.exe program.o llegirMat.o

program.o: program.cc llegirMat.hh
	$(G++) -c program.cc $(OPCIONS) 

llegirMat.o: llegirMat.cc llegirMat.hh
	$(G++) -c llegirMat.cc $(OPCIONS) 

clean:
	rm -f *.o
	rm -f *.exe
