//PLAYER.CPP FILE
#include <iostream>
#include <string>
#include <sstream>
#include "Player.h"

// for live game play - must not change!                                                             
void Player::display() const {
  std::cout << "Current ";
  std::cout << name << ":  Stock{0}: " ;
  stock.display();
  std::cout << std::endl;
  std::cout << "   Discards{1-4}: ";
  for (int i = 0; i < 4; ++i) {
    discard[i].display();
    std::cout << "  ";
  }
  std::cout << std::endl;
  std::cout << "   Hand{5-9}: ";
  hand.display();
  std::cout << std::endl;
}

/* saving state format - must not change!                                                            
PlayerName                                                                                           
Stock size                                                                                           
01 02 03  ...                                                                                        
...                                                                                                  
Hand size                                                                                            
01 02 03 04 05                                                                                       
Discard1 size                                                                                        
01 02 03 04 ...                                                                                      
...                                                                                                  
Discard2 size                                                                                        
...                                                                                                  
Discard3 size                                                                                        
...                                                                                                  
Discard4 size                                                                                        
...                                                                                                  
*/
std::string Player::toString() const {
  std::stringstream result;
  result << name << "\n";
  result << "Stock " << stock.toString();
  result << "Hand " << hand.toString();
  for (int i = 0; i < 4; ++i) {
    result << "Discard" << i << " " << discard[i].toString();
  }
  return result.str();
}
void Player::readIn(std::istream& is){
  std::string ss;
  is>>ss; //just to get rid of the string "Stock                                                     
  stock.readIn(is);
  is>>ss; //just to get rid of the string "Hand"                                                     
  hand.readIn(is);

  for ( int dis = 0; dis < 4; dis++){ //to construct the discard piles                               
    is>>ss; //just to get rid of the string "Discard" from the file                                  
    discard[dis].readIn(is);
  }
}
Card Player::copyCard(int check){
    switch(check){
    case 0: return stock.copyCard();
      break;

    case 1:
    case 2:
    case 3:
    case 4:
      return discard[check-1].copyCard();
      break;

    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
      return hand.copyCard(check);
      break;
        
      default: Card c(0); return c;
      break;
    }
  }
