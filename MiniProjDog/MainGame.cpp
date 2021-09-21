#include "Board.hpp"
#include "Dog.hpp"
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

//clang++-7 -pthread -std=c++17 -o main Board.cpp Dog.cpp MainGame.cpp
//to run code
//then ./main

int main() {
	srand(time(NULL));
	Board board('m',"fido", true);
	return 0;
}
