# Final Project Makefile

myprogram : Mult.o FinalProjMain.o FinalProjWrapper.o
	g++ -o myprogram Mult.o FinalProjMain.o FinalProjWrapper.o 

Mult.o : Mult.cpp Mult.h
	g++ -c Mult.cpp

FinalProjMain.o : FinalProjMain.cpp FinalProjMain.h Mult.h 
	g++ -c FinalProjMain.cpp

FinalProjWrapper.o : FinalProjWrapper.cpp FinalProjMain.h
	g++ -c FinalProjWrapper.cpp

clean :
	rm *.o myprogram
