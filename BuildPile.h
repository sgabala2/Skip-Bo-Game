#ifndef _BUILDPILE_H
#define _BUILDPILE_H

#include <vector>
#include <iostream>
#include "Card.h"
#include "Pile.h"
#include "FaceUpPile.h"

class BuildPile: public FaceUpPile {

 public:
  BuildPile(): FaceUpPile(){}
  /*void addCard(const Card& c) {if((size() + 1== c.getValue())||((c.getValue()==0)&&(size() < 12)))\
{pile.push_back(c);};}*/
  void reverse();
};

#endif
