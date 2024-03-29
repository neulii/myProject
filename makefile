OBJS = \
	object/main.o \
	object/HooverableRectShape.o \
	object/Library.o \
	object/ClickableHooverableRectShape.o \
	object/DragNDropField.o \
	object/Button.o \
	object/MenuButton.o \
	object/GameObject.o \
	object/Tile.o \
	object/ActionTile.o \
	object/Bar.o \
	object/BarGraph.o

OBJS_TEST = \
	object/test.o \

CXX = g++
CXXFLAGS = -Wall -std=c++11

LDLIBS = -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network 

LDFLAGS = -L "SFML/lib" 
CPPFLAGS = -I "SFML/include" -I "include" 

game: $(OBJS) 
	$(CXX) $(CXXFLAGS) -o game $(OBJS) $(LDFLAGS) $(LDLIBS)

test: $(OBJS_TEST)
	$(CXX) $(CXXFLAGS) -o test $(OBJS_TEST) $(LDFLAGS) $(LDLIBS)
	

object/main.o: src/main.cpp 
	g++ $(CXXFLAGS) -c src/main.cpp -o object/main.o $(CPPFLAGS)

object/HooverableRectShape.o: src/HooverableRectShape.cpp include/HooverableRectShape.h
	g++ $(CXXFLAGS) -c src/HooverableRectShape.cpp -o object/HooverableRectShape.o $(CPPFLAGS)

object/Library.o: src/Library.cpp include/Library.h
	g++ $(CXXFLAGS) -c src/Library.cpp -o object/Library.o $(CPPFLAGS)

object/ClickableHooverableRectShape.o: src/ClickableHooverableRectShape.cpp include/ClickableHooverableRectShape.h
	g++ $(CXXFLAGS) -c src/ClickableHooverableRectShape.cpp -o object/ClickableHooverableRectShape.o $(CPPFLAGS)

object/DragNDropField.o: src/DragNDropField.cpp include/DragNDropField.h
	g++ $(CXXFLAGS) -c src/DragNDropField.cpp -o object/DragNDropField.o $(CPPFLAGS)

object/Button.o: src/Button.cpp include/Button.h
	g++ $(CXXFLAGS) -c src/Button.cpp -o object/Button.o $(CPPFLAGS)

object/MenuButton.o: src/MenuButton.cpp include/MenuButton.h
	g++ $(CXXFLAGS) -c src/MenuButton.cpp -o object/MenuButton.o $(CPPFLAGS)

object/GameObject.o: src/GameObject.cpp include/GameObject.h
	g++ $(CXXFLAGS) -c src/GameObject.cpp -o object/GameObject.o $(CPPFLAGS)

object/Tile.o: src/Tile.cpp include/Tile.h
	g++ $(CXXFLAGS) -c src/Tile.cpp -o object/Tile.o $(CPPFLAGS)

object/ActionTile.o: src/ActionTile.cpp include/ActionTile.h
	g++ $(CXXFLAGS) -c src/ActionTile.cpp -o object/ActionTile.o $(CPPFLAGS)

object/Bar.o: src/Bar.cpp include/Bar.h
	g++ $(CXXFLAGS) -c src/Bar.cpp -o object/Bar.o $(CPPFLAGS)
	
object/BarGraph.o: src/BarGraph.cpp include/BarGraph.h
	g++ $(CXXFLAGS) -c src/BarGraph.cpp -o object/BarGraph.o $(CPPFLAGS)
	
#object/TitleBar.o: src/TitleBar.cpp include/TitleBar.h
#	g++  $(CXXFLAGS) -c src/TitleBar.cpp -o object/TitleBar.o $(CPPFLAGS)

clean:
	rm $(OBJS)
	rm game

cleanwin: 
	del game.exe
	rm object/*.o
	del object\*.o

test.exe: object/test.o object/Library.o
	g++ -o test.exe object/test.o object/Library.o $(LDFLAGS)

object/test.o: src/test.cpp src/Library.cpp
	g++ $(CXXFLAGS) -c src/test.cpp -o object/test.o $(CPPFLAGS)

cleantest:
	del test.exe
	rm object/*.o
	del object\test.o
