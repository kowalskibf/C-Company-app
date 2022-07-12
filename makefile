app: app.o Person.o Employee.o Manager.o Date.o FileHandler.o Interface.o Database.o
	g++ -o app.out app.o Person.o Employee.o Manager.o Date.o FileHandler.o Interface.o Database.o

app.o: app.cpp
	g++ -c app.cpp

Person.o: Person.cpp
	g++ -c Person.cpp

Employee.o: Employee.cpp
	g++ -c Employee.cpp

Manager.o: Manager.cpp
	g++ -c Manager.cpp

Date.o: Date.cpp
	g++ -c Date.cpp

FileHandler.o: FileHandler.cpp
	g++ -c FileHandler.cpp

Interface.o: Interface.cpp
	g++ -c Interface.cpp

Database.o: Database.cpp
	g++ -c Database.cpp

clean:
	rm -f app.out Person.o Employee.o Manager.o Date.o FileHandler.o Interface.o Database.o 
