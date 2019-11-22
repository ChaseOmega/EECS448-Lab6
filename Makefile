QueueDemo: main.o Queue.o Test.o
	g++ -g -Wall -std=c++11 main.o Queue.o Test.o -o QueueDemo

main.o: main.cpp
	g++ -g -std=c++11 -c main.cpp

clean:
	rm main.o QueueDemo *~
