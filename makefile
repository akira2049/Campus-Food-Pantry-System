CXX = g++
CXXFLAGS = -Wall -std=c++11

OBJS = main.o Item.o User.o Student.o Staff.o Pantry.o RequestHistory.o unitTest.o

main: $(OBJS)
	$(CXX) $(CXXFLAGS) -o main $(OBJS)

main.o: main.cpp Pantry.h Student.h Staff.h unitTest.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Item.o: Item.cpp Item.h
	$(CXX) $(CXXFLAGS) -c Item.cpp

User.o: User.cpp User.h
	$(CXX) $(CXXFLAGS) -c User.cpp

Student.o: Student.cpp Student.h User.h
	$(CXX) $(CXXFLAGS) -c Student.cpp

Staff.o: Staff.cpp Staff.h User.h
	$(CXX) $(CXXFLAGS) -c Staff.cpp

Pantry.o: Pantry.cpp Pantry.h Item.h RequestHistory.h
	$(CXX) $(CXXFLAGS) -c Pantry.cpp

RequestHistory.o: RequestHistory.cpp RequestHistory.h
	$(CXX) $(CXXFLAGS) -c RequestHistory.cpp

unitTest.o: unitTest.cpp unitTest.h Item.h Pantry.h
	$(CXX) $(CXXFLAGS) -c unitTest.cpp

clean:
	rm -f *.o main