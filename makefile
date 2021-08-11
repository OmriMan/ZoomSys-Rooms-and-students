ZoomSystem: hw5.o ZoomSys.o Student.o S_Lazy.o S_Worker.o S_Responsible.o Room.o Room_L.o Room_W.o
	g++ hw5.o ZoomSys.o Student.o S_Lazy.o S_Worker.o S_Responsible.o Room.o Room_L.o Room_W.o -o ZoomSystem
	
hw5.o : hw5.cpp Student.h Room.h S_Lazy.h S_Worker.h S_Responsible.h Error.h ZoomSys.h
	g++ -c hw5.cpp
	
ZoomSys.o: ZoomSys.cpp ZoomSys.h Room.h Student.h Error.h S_Lazy.h S_Worker.h S_Responsible.h
	g++ -c ZoomSys.cpp
	
Student.o: Student.cpp Student.h Room.h Error.h
	g++ -c Student.cpp
	
S_Lazy.o : S_Lazy.cpp S_Lazy.h Student.h Room.h Error.h
	g++ -c S_Lazy.cpp
	
S_Worker.o: S_Worker.cpp S_Worker.h Student.h Room.h Error.h
	g++ -c S_Worker.cpp
	
S_Responsible.o: S_Responsible.cpp S_Responsible.h Student.h Room.h Error.h
	g++ -c S_Responsible.cpp
	
Room.o: Room.cpp Room.h Student.h Error.h
	g++ -c Room.cpp
	
Room_W.o: Room_W.cpp Room_W.h Room.h Student.h Error.h
	g++ -c Room_W.cpp
	
Room_L.o: Room_L.cpp Room_L.h Room.h Student.h Error.h
	g++ -c Room_L.cpp
	
clean:
	rm -f *.o ZoomSystem
