//SKIPBOGAME.H FILE
#ifndef _SKIPBOGAME_H
#define _SKIPBOGAME_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "Card.h"
#include "Pile.h"
#include "BuildPile.h"
#include "Player.h"
#include "DrawPile.h"
#include <sstream>
//#include <cstdlib>                                                                                 

class SkipBoGame {

private:
  int nump;
  int curp;
  DrawPile draw;
  BuildPile b1;
  BuildPile temp;
  std::vector<BuildPile> build = { b1,b1,b1,b1};
  BuildPile  completeBuild;
  std::vector<Player> peep;

 public:
  SkipBoGame(){}
  SkipBoGame(int p, bool shuff);

  void display() const;  // for live game play, must override                                        

  void setShuff(bool shuff) {draw.setShuff(shuff);}
  void Shuffle(){draw.Shuffle();}
  void reShuffle();

  int getNumP(){return nump;}
  int getCurP() { return curp; }
  void setCurP(int n) { curp = n; }
  std::string getName(int play){return peep[play].getName();}


  int drawSize() {return draw.size();}
  void addDraw(Card card){draw.addCard(card);}
  Card removeDraw(){return draw.removeCard();}
  bool getRand(){return draw.getRandBool();}

  void addStock(int play, Card c){peep[play].addStock(c);}
  int stockSize(int play){return peep[play].stockSize();}
  Card removeStock(int play){return peep[play].removeStock();}
  
  int handSize(int play) {return peep[play].handSize();}
  void addHand(int play, Card c) {peep[play].addHand(c);}

  void setAside(std::string a3);

  void addDiscard(int play, std::string a3, Card c);

  void addBuild(std::string a3, Card c);

  bool verify(int play, std::string a2);
  bool buildVerify(std::string a3, Card c);

  Card removeCard(int play, std::string a2);
  Card copyCard(int play, std::string a2);

  std::string toString() const;
  void readIn(std::istream& is);

};

#endif
