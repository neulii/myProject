OBJS = object/main.o
CXX = g++
CXXFLAGS = -Wall -std=c++11

LDLIBS = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

LDFLAGS = -L "SFML/lib"
CPPFLAGS = -I "SFML/include" -I "include"

game: $(OBJS)
	$(CXX) $(CXXFLAGS) -o game $(OBJS) $(LDLIBS) $(LDFLAGS)

object/main.o: src/main.cpp
	g++ $(CXXFLAGS) -c src/main.cpp -o object/main.o $(CPPFLAGS)


clean:
	rm $(OBJS)
	rm game

cleanwin:
	del object\\*.o
	del game.exe
