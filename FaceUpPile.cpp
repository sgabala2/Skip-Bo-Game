//FACEUPPILE.CPP FILE
#include <iostream>
#include "FaceUpPile.h"

// for live game play - must not change!                                                             
void FaceUpPile::display() const {
  if (size()) {
    pile[pile.size()-1].display();
  }
  else std::cout << "--";
  std::cout << "/" << size();
}

Card FaceUpPile::copyCard(){
  return pile.back();
}
