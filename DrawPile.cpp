//DRAWPILE.CPP FILE
include <iostream>
#include "DrawPile.h"

// for live game play - must not change!                                                             
void DrawPile::display() const {
  std::cout << "[XX]/" << size();
}

Card DrawPile::removeCard(){
  Card c = pile.back();
  pile.pop_back();
  return c;
}
