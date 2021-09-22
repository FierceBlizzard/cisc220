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
	mydog.name = name;
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

		mydog.strength = 50; 

		mydog.x = startx;
		mydog.y = starty;
		boardConfig();
		addFood();
		addTraps();
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
		mydog.printDog();
		cout << endl;
		cout << "Move (u, d, l, r) "<<endl;
		char c;
		cin >> c;
		play = moveDog(c);
		printBoard(); 
	}


}

void Board::addFood() {
	/* (5 pts) code for the addFood method goes here*/
	if(level == 'e'){
		for(int i = 0; i < size; i++){
			board[(rand()%18)+1][(rand()%18)+1] = 'F';
		}
	}else if(level == 'm'){
		for(int i = 0; i < size-2; i++){
			board[(rand()%18)+1][(rand()%18)+1] = 'F';
		}
	}else{
		for(int i = 0; i < size-4; i++){
			board[(rand()%18)+1][(rand()%18)+1] = 'F';
		}
	}
	
}
void Board::addTraps() {
	/* (5 pts) code for the addTraps method goes here*/
	int trapnum = 0; 
	if(level == 'e'){
		trapnum = size-6;
	}else if(level == 'm'){
		trapnum = size-8; 
	}else{
		trapnum = size-10; 
	}
	for(int i = 0; i < trapnum; i++){
		board[(rand()%18)+1][(rand()%18)+1] = 'T';
	}

}

void Board::boardConfig() {
	for(int i=0;i<size;i++){
        for(int j=0;j<size;j++)
            board[i][j] = ' ';
    } // board is filled with dummy characters
    int walls[10];
    for(int i=0;i<10;i++){
        walls[i] = rand()%size; //creating random indexes for the walls
    }

    int tempindex;
    for(int i=0;i<10;i++){
        tempindex=walls[i];
        if(i%2==1){
            for(int j=0;j<size;j+=rand()%5){
                board[j][tempindex] = '|';
            }
        }
        if(i%2==0){
            for(int j=0;j<size;j+=rand()%5){
                    board[tempindex][j] = '-';
            }
        }
    }

	board[mydog.x][mydog.y] = 'D'; 
}

void Board::printBoard() {
/* (8 pts) code for the printBoard method goes here */

	//top
	for(int i = 0; i < size-5; i++){
		cout<<" - ";
	}
	cout<<endl; 
	//board itself
	for(int i=1;i<size-1;i++){
		cout<<"/ ";
        for(int j=0;j<size;j++){
            cout << board[i][j] << " "; 
        }
		cout<<" /";
		cout<<endl;
    }
	//bottom
	for(int i = 0; i < size-5; i++){
		cout<<" - ";
	}
	cout<<endl;
}
bool Board::moveDog(char c) {
	/* (12 pts) code for the moveDog method goes here*/
	board[mydog.x][mydog.y] = ' ';
	char ans;
	if(c == 'r'){
		mydog.y++; 
	}
	if(c == 'l'){
		mydog.y--; 
	}
	if(c == 'u'){
		mydog.x--; 
	}
	if(c == 'd'){
		mydog.x++; 
	}
	if(board[mydog.x][mydog.y] == 'T'){
		mydog.changeStrength((-1)*((rand()%15)+2));
	}
	if(board[mydog.x][mydog.y] == 'F'){
		mydog.changeStrength(((rand()%15)+2));
	}
	if(board[mydog.x][mydog.y] == '|' || board[mydog.x][mydog.y] == '-'){
		cout << "Do you want to knock down that wall, it costs 6 strength?(y/n)"<<endl;
		cin >> ans;
		if(ans == 'y'){
			mydog.changeStrength(-6);
		}
		if(ans == 'n'){
			if(c == 'r'){
				mydog.y--; 
			}
			if(c == 'l'){
				mydog.y++; 
			}
			if(c == 'u'){
				mydog.x++; 
			}
			if(c == 'd'){
				mydog.x--; 
			}
		}
	}
	board[mydog.x][mydog.y] = 'D';

	return c;
}
