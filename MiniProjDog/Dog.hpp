#pragma once
#include "Board.hpp"
#include <iostream>
#include <string.h>
using namespace std;
class Dog{
    friend class Board; 
    string name;
    int strength;
    int x;
    int y;

public: 
    Dog(string n);//constructor
    Dog();//constructor
    bool changeStrength(int amt);//changes dog's strength
    void die();//die message when strenth at or below 0
    void printDog();//prints out info about Dog
    void won();//won mesage for when dog is at end of evil forest
    void reset(); //resets dog for starting a new game

};