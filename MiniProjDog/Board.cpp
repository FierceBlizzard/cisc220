#include "Board.hpp"
#include <iostream>
using namespace std;


Board::Board(char diff, bool d){
	level = diff;
	debug = d;
	wallStrength = 6;
	InitAll();
}
Board::Board(bool d){
	level = 'e';
	debug = d;
	wallStrength = 6;
	InitAll();
}
Board::Board(char diff, string name, bool d) {
	level = diff;
	debug = d;
	//mydog.name = name;
	wallStrength = 6;
	InitAll();
}
void Board::InitAll() {
	bool keepPlaying = true;
	while (keepPlaying) {
		cout << "What level of difficulty do you want (e, m, or h)?" << endl;
		char c;
		cin >> c;
		level = c;
		startx = rand() % size;
		starty = 0;
		endx = rand() % size;
		endy = size-1;

		//mydog.x = startx;
		//mydog.y = starty;
		boardConfig();
		//addFood();
		//addTraps();
		printBoard();
		playGame();

		//cout << "Play again? " << endl;
		//string s = "no";
		//cin>>s;
		//if (s == "yes" || s == "Yes" || s == "Y" || s == "y") {
		//	keepPlaying = true;
		//	mydog.reset();
		//}
		//else {
		//	cout <<"Thanks for playing!" << endl;
		//	keepPlaying = false;
		//}
	}
}
void Board::playGame() {
	bool play = true;
	while (play) {
		cout << "Move (u, d, l, r) "<<endl;
		char c;
		cin >> c;
		//play = moveDog(c);
		printBoard();
	}


}

void Board::addFood() {
/* (5 pts) code for the addFood method goes here
*/
}
void Board::addTraps() {
/* (5 pts) code for the addTraps method goes here
*/
}

void Board::boardConfig() {
	for(int i=0;i<size;i++){
        board[0][i] = '_';
    }
    for(int i=1;i<size-1;i++){
        for(int j=0;j<size;j++){
            if(j==0||j==size-1){
                board[i][j] = '|';
            }
            else{
                board[i][j] = '+';
            }
        }
    }
    for(int i=0;i<size;i++){
            board[size-1][i] = '_';
    }
}

void Board::printBoard() {
/* (8 pts) code for the printBoard method goes here 
*/
	for(int i=1;i<size-1;i++){
        for(int j=0;j<size;j++){
            cout << board[i][j]; 
        }
		cout<<endl;
    }
}
bool Board::moveDog(char c) {
/* (12 pts) code for the moveDog method goes here
*/
	return c;
}
