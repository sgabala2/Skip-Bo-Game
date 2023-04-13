//FACEUPPILE.H FILE
#ifndef _FACEUPPILE_H
#define _FACEUPPILE_H

#include <vector>
#include <iostream>
#include "Card.h"
#include "Pile.h"

class FaceUpPile: public Pile {

 public:
  FaceUpPile(): Pile() {}
  void display() const;

  Card removeCard(){Card c = pile.back(); pile.pop_back(); return c;}
  Card copyCard();
};

#endif
