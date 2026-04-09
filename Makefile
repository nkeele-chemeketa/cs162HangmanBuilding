tests.exe:
	g++ -g -Wall -std=c++20 tests.cpp Hangman.cpp -o tests.exe

main.exe:
	g++ -g -Wall -std=c++20 main.cpp Hangman.cpp -o tests.exe