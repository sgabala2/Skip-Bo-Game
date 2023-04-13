//PLAYER.H FILE
#ifndef _PLAYER_H
#define _PLAYER_H

#include <vector>
#include <iostream>
#include <fstream>
#include "Card.h"
#include "Pile.h"
#include "Hand.h"
#include "FaceUpPile.h"

class Player {
 protected:
  FaceUpPile d1;
  std::vector<FaceUpPile> discard = {d1, d1, d1, d1}; //make separate FaceUpPiles first then insert 
into vector                                                                                          
  FaceUpPile stock;
  Hand hand;
  std::string name;

 public:
  Player(std::string ss):name(ss){}
  std::string getName(){return name;}

  std::string toString() const;  // for saving state                                                 
  void readIn(std::istream & is);  // students to write this, companion to toString()                
  void display() const;  // for live game play, must override                                        


  void addHand(const Card& c) {hand.addCard(c);}
  Card removeHand(int n) {return hand.removeCard(n);}
  int handSize() {return hand.size();}

  void addDiscard(const Card& c, int index){(discard[index]).addCard(c);}
  Card removeDiscard(int index){return (discard[index]).removeCard();}
  int discardSize(int index) { return discard[index].size();}

  void addStock(const Card& c) {stock.addCard(c);}
  Card removeStock() {return stock.removeCard();}
  int stockSize(){return stock.size();}

  Card copyCard(int check);
};


#endif
