all:
	g++ -std=c++17 InteractiveModeHelper.cpp StringsModyfier.cpp main.cpp

clean:
	rm -rf a.out
