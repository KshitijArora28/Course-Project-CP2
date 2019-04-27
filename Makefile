Emergency_project.o: Emergency_project.cpp
	g++ -c -o Emergency_project.o Emergency_project.cpp

emergency: Emergency_project.o
	g++ -o emergency Emergency_project.o
