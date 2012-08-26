Project4: Project4.o  PolicyManager.o AutoPolicy.o HomePolicy.o LifePolicy.o \
	Policy.o Manager.o Salesperson.o Employee.o
	g++ -o Project4 Project4.o AutoPolicy.o HomePolicy.o LifePolicy.o \
	Policy.o Manager.o Salesperson.o Employee.o PolicyManager.o

Project4.o: Project4.cpp Project4.h
	g++ -c Project4.cpp

PolicyManager.o: PolicyManager.cpp PolicyManager.h
	g++ -c PolicyManager.cpp

AutoPolicy.o: AutoPolicy.cpp AutoPolicy.h
	g++ -c AutoPolicy.cpp

HomePolicy.o: HomePolicy.cpp HomePolicy.h
	g++ -c HomePolicy.cpp

LifePolicy.o: LifePolicy.cpp LifePolicy.h
	g++ -c LifePolicy.cpp

Policy.o: Policy.cpp Policy.h
	g++ -c Policy.cpp

Manager.o: Manager.cpp Manager.h
	g++ -c Manager.cpp

Salesperson.o: Salesperson.cpp Salesperson.h
	g++ -c Salesperson.cpp

Employee.o: Employee.cpp Employee.h
	g++ -c Employee.cpp
