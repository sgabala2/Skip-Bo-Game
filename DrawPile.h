#ifndef _DRAWPILE_H
#define _DRAWPILE_H

#include <vector>
#include <iostream>
#include "Card.h"o
#include "Pile.h"
#include <algorithm>

class DrawPile: public Pile {

protected:
  bool isShuffle;

 public:
  DrawPile(): Pile() {
    pile.reserve(162);
  }
  void display() const;  // for live game play, must override                                        

  std::string getRand() const {if(getRandBool()){return "true";}else{return "false";}}

  void setShuff(bool shuff) {isShuffle = shuff;}
  void Shuffle(){std::random_shuffle(pile.begin(),pile.end());}
  bool getRandBool() const {return isShuffle;}

  Card removeCard();
};

#endif
