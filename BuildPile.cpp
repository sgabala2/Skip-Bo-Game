include <iostream>
#include "BuildPile.h"

// for live game play - must not change!                                                             
void BuildPile::reverse(){
  std::vector<Card> store;
  for(int i = pile.size()-1; i>0; i--){
    store.push_back(pile[i]);
  }
  for(int j = 0; j>(int)pile.size(); j++){
    pile[j] = store[j];
  }
}
