main:Picture.o main.o
	g++ -o main main.o Picture.o
Picture.o:Picture.cpp
	g++ -c Picture.cpp
main.o: main.cpp
	g++ -c main.cpp
clean:
	rm main.o Picture.o
