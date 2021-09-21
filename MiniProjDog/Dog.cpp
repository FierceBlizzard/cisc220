#include "Board.hpp"
#include "Dog.hpp"
#include <iostream>

using namespace std;

Dog::Dog(string n){
    name = n; 
    strength = 50; 
    x = 0;
    y = 0; 

}

Dog::Dog(){
    name = "D"; 
    strength = 50; 
    x = 0;
    y = 0; 
}

bool Dog::changeStrength(int amt){
    return false; 
}

void Dog::die(){
   

}

void Dog::printDog(){

}

void Dog::won(){

}

void Dog::reset(){
    
}
