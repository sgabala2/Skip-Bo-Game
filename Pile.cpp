//PILE.CPP FILE
include <vector>
#include <sstream>
#include <fstream>
#include "Pile.h"

// for saving game state - must not change!                                                          
void Pile::readIn(std::istream & is){
  int capacity  = 0;
  is >> capacity;
  int num = 0;
  for(int i = 0; i < capacity; i++){
    is >> num;
    Card c(num);
    pile.push_back(c);
  }
}

std::string Pile::toString() const {
  std::string result;
  result.append(std::to_string(size()));
  result.append("\n");
  // add all the pile elements to the string, at most 20 per line                                    
  for (int i=0; i < size(); ++i) {
    if (i % 20 == 0 && i != 0)
      result.append("\n");
    else if (i != 0)
      result.append(" ");
    result.append(pile[i].toString());
  }
  result.append("\n");
  return result;
}
