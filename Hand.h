//HAND.H FILE
ifndef _HAND_H
#define _HAND_H

#include <vector>
#include <iostream>
#include "Card.h"
#include "Pile.h"

class Hand: public Pile {

public:
  Hand(): Pile() {
    pile.reserve(5);
  }

  void display() const;

  Card copyCard(int n);
  Card removeCard(int const n);
};

#endif
