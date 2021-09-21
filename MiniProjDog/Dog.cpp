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
    Dog("D");
}

bool Dog::changeStrength(int amt){
    strength += amt; 
    cout<<" Strength: "<<strength;
    if(strength <= 0){
        die();
    }
    return true; 
}

void Dog::die(){
   cout << "You are hit with the BIG SAD cause "<< name << " has died"<<endl; 

}

void Dog::printDog(){
    cout<<"Name: " << name <<" Strength: "<<strength;
}

void Dog::won(){

}

void Dog::reset(){
    Dog();
}
