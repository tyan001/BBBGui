all:game
PAT=imports/
game: app.o main.o cell.o person.o util.o
	g++ app.o main.o cell.o person.o util.o -o game `wx-config --libs`

app.o: Version1App.cpp Version1App.h
	g++ -c `wx-config --cxxflags` Version1App.cpp -o app.o

main.o: Version1Main.cpp Version1Main.h
	g++ -c `wx-config --cxxflags` Version1Main.cpp -o main.o

cell.o: $(PAT)Cell.cpp $(PAT)Cell.h $(PAT)Person.h $(PAT)Building.h $(PAT)Position.h
	g++ -c `wx-config --cxxflags` $(PAT)Cell.cpp -o cell.o

person.o: $(PAT)Person.cpp $(PAT)Person.h
	g++ -c `wx-config --cxxflags` $(PAT)Person.cpp -o person.o

util.o: $(PAT)Util.cpp $(PAT)Util.h Version1Main.h
	g++ -c `wx-config --cxxflags` $(PAT)Util.cpp -o util.o
