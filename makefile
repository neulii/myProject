OBJS = object/main.o object/HooverableRectShape.o object/Library.o object/ClickableHooverableRectShape.o

CXX = g++
CXXFLAGS = -Wall -std=c++11

LDLIBS = -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system 

LDFLAGS = -L "SFML/lib" 
CPPFLAGS = -I "SFML/include" -I "include" 

game: $(OBJS) 
	$(CXX) $(CXXFLAGS) -o game $(OBJS) $(LDFLAGS) $(LDLIBS) 
	
object/main.o: src/main.cpp 
	g++ $(CXXFLAGS) -c src/main.cpp -o object/main.o $(CPPFLAGS)

object/HooverableRectShape.o: src/HooverableRectShape.cpp include/HooverableRectShape.h
	g++ $(CXXFLAGS) -c src/HooverableRectShape.cpp -o object/HooverableRectShape.o $(CPPFLAGS)

object/Library.o: src/Library.cpp include/Library.h
	g++ $(CXXFLAGS) -c src/Library.cpp -o object/Library.o $(CPPFLAGS)

object/ClickableHooverableRectShape.o: src/ClickableHooverableRectShape.cpp include/ClickableHooverableRectShape.h
	g++ $(CXXFLAGS) -c src/ClickableHooverableRectShape.cpp -o object/ClickableHooverableRectShape.o $(CPPFLAGS)

clean:
	rm $(OBJS)
	rm game

cleanwin: 
	del object\\*.o
	del game.exe

test: object/test.o
	g++ -o test object/test.o $(LDFLAGS) $(LDLIBS) 

object/test.o: src/test.cpp
	g++ $(CXXFLAGS) -c src/test.cpp -o object/test.o $(CPPFLAGS)

cleantest:
	del object\test.o
	del test.exe