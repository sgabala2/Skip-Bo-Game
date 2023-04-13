//HAND.CPP FILE
include <iostream>
#include "Hand.h"

// for live game play - must not change!                                                             
void Hand::display() const {
  int i;
  for (i = 0; i < size(); i++) {
    pile[i].display();
    std::cout << "  ";
  }
  for ( ; i < 5; i++)
    std::cout << "--  ";
}

Card Hand::removeCard(int const n){
  Card c = *(pile.begin() + n-5);
  pile.erase(pile.begin() + n-5);
  return c;
}

Card Hand::copyCard(int n){
  return pile[n-5];
}
