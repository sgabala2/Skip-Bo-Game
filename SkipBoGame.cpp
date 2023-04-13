//SKIPBOGAME.CPP FILE
#include <iostream>
#include <sstream>
#include "SkipBoGame.h"

SkipBoGame::SkipBoGame(int p, bool shuff): nump(p) {
  draw.setShuff(shuff);
    int r = 0;
    if (shuff){
      r = rand()% nump;
    }
    curp = r;
    for(int i = 0; i < nump; i++){
      std::stringstream ss;
      ss<< "Player" <<i;
      Player p = Player(ss.str());
      peep.push_back(p);
    }
}



/* for live game play - must not change format!                                                      
                                                                                                     
drawPile  build_a  build_b  build_c  build_d                                                         
playerName  stock_0                                                                                  
discards: discard_1 discard_2 discard_3 discard_4                                                    
hand: card_5 card_6 card_7 card_8 card_9                                                             
 */
void SkipBoGame::display() const {
  std::cout << "Draw: ";
  draw.display();
  std::cout << "  Build Piles: ";
  for (int j = 0; j < 4; j++) {
    build[j].display();
    std::cout << " ";
  }
  std::cout << std::endl;
  peep[curp].display();
}

void SkipBoGame::reShuffle() {
    //completeBuild.reverse();                                                                       
    // for(int i = 0; i < completeBuild.size(); i++) {                                               
    //for(int j = 0; j < 12; j++) {                                                                  
    //draw.addCard(completeBuild.removeCard());                                                      
    //}                                                                                              
    // }                                                                                             
    if(completeBuild.size() !=0){
      FaceUpPile temp1;
      FaceUpPile temp2;
      int size_draw = draw.size();
      for(int i = 0; i<size_draw; i++){
        temp1.addCard(draw.removeCard());
      }
      for(int j = 0; j<size_draw; j++){
        completeBuild.addCard(temp1.removeCard());
      }
      int size_CB = completeBuild.size();
      for(int h = 0; h<size_CB; h++){
        temp2.addCard(completeBuild.removeCard());
      }
      int size_temp2 = temp2.size();
      for(int k = 0; k<size_temp2; k++){
        draw.addCard(temp2.removeCard());
      }
    }
    if(getRand()) {
      Shuffle();
    }
 }

void SkipBoGame::setAside(std::string a3){
   int index = -1;
   if(a3 == "a") {index = 0;}
   else if(a3 == "b"){index = 1;}
   else if(a3 == "c"){index = 2;}
   else if(a3 == "d"){index = 3;}
   for(int i = 0; i<12; i++){
     temp.addCard(build[index].removeCard());
   }
   for(int i = 0; i<12; i++){
     completeBuild.addCard(temp.removeCard());
   }
 }

Card SkipBoGame::removeCard(int play, std::string a2) {
    int check = 0;
    if(a2 == "0") {check = 0;}
    else if(a2 == "1") {check = 1;}
    else if(a2 == "2") {check = 2;}
    else if(a2 == "3") {check = 3;}
    else if(a2 == "4") {check = 4;}
    else if(a2 == "5") {check = 5;}
    else if(a2 == "6") {check = 6;}
    else if(a2 == "7") {check = 7;}
    else if(a2 == "8") {check = 8;}
    else if(a2 == "9") {check = 9;}

    switch(check){
    case 0: return removeStock(play);
      break;

    case 1:
    case 2:
    case 3:
    case 4:
      return peep[play].removeDiscard(check - 1);
    break;

    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
      return peep[play].removeHand(check);
      break;
    }
    Card c(0);
    return c;
 }

Card SkipBoGame::copyCard(int play, std::string a2) {
    int check = 0;
    if(a2 == "0") {check = 0;}
    else if(a2 == "1") {check = 1;}
    else if(a2 == "2") {check = 2;}
    else if(a2 == "3") {check = 3;}
    else if(a2 == "4") {check = 4;}
    else if(a2 == "5") {check = 5;}
    else if(a2 == "6") {check = 6;}
    else if(a2 == "7") {check = 7;}
    else if(a2 == "8") {check = 8;}
    else if(a2 == "9") {check = 9;}
    return peep[play].copyCard(check);
  }

void SkipBoGame::addDiscard(int play, std::string a3, Card c){
    int index = -1;
    if(a3 == "1") {index = 0;}
    else if(a3 == "2"){index = 1;}
    else if(a3 == "3"){index = 2;}
    else if(a3 == "4"){index = 3;}
    peep[play].addDiscard(c, index);
}

void SkipBoGame::addBuild(std::string a3, Card c){
  if(a3 == "a") {
    build[0].addCard(c);
    if(build[0].size() == 12){
      std::cout<<"build pile a full, set aside"<<std::endl;
      setAside(a3);
    }
  }
  else if(a3 == "b") {
    build[1].addCard(c);
    if(build[1].size() == 12){
      std::cout<<"build pile b full, set aside"<<std::endl;
      setAside(a3);
    }
  }
  else if(a3 == "c") {
    build[2].addCard(c);
    if(build[2].size() == 12){
      std::cout<<"build pile b full, set aside"<<std::endl;
      setAside(a3);
    }
  }
  else if(a3 == "d") {
      build[3].addCard(c);
      if(build[3].size() == 12){
        std::cout<<"build pile d full, set aside"<<std::endl;
        setAside(a3);
      }
    }
}

bool SkipBoGame::verify(int play, std::string a2) {
    int check = -1;
    if(a2 == "0") {check = 0;}
    else if(a2 == "1") {check = 1;}
    else if(a2 == "2") {check = 2;}
    else if(a2 == "3") {check = 3;}
    else if(a2 == "4") {check = 4;}
    else if(a2 == "5") {check = 5;}
    else if(a2 == "6") {check = 6;}
    else if(a2 == "7") {check = 7;}
    else if(a2 == "8") {check = 8;}
    else if(a2 == "9") {check = 9;}

    switch(check){
    case 0: return true;
      break;

    case 1:
    case 2:
    case 3:
    case 4:
      if(peep[play].discardSize(check-1) != 0) {return true;}
      else { return false;}
    break;

    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
      if(handSize(play) >= (check - 4)) {return true;}
      else {return false;}
      break;

    default: return false;
      break;
    }
  
  }

bool SkipBoGame::buildVerify(std::string a3, Card c) {
    if(a3=="a"){
      if( (build[0].size() + 1 == c.getValue())||((c.getValue()==0)&&(build[0].size() < 12)) ) {
        return true;
      } else {return false;}
    }
    if(a3=="b"){
      if( (build[1].size() + 1 == c.getValue())||((c.getValue()==0)&&(build[1].size() < 12)) ) {
        return true;
      } else {return false;}
    }
    if(a3=="c"){
      if( (build[2].size() + 1 == c.getValue())||((c.getValue()==0)&&(build[2].size() < 12)) ) {
        return true;
      } else {return false;}
    }
    if(a3=="d"){
      if( (build[3].size() + 1 == c.getValue())||((c.getValue()==0)&&(build[3].size() < 12)) ) {
        return true;
      } else {return false;}
    }
    return false;
  }



/* for saving state - must not change format!                                                        
                                                                                                     
shuffle numplayers currplayer                                                                        
PlayerCurp [display]                                                                                 
PlayerCurp+1 [display]                                                                               
[etc for all players]                                                                                
Draw [display]                                                                                       
Build_a [display]                                                                                    
Build_b [display]                                                                                    
Build_c [display]                                                                                    
Build_d [display]                                                                                    
*/
std::string SkipBoGame::toString() const {
  std::stringstream result;
  int idx;
  result << draw.getRand() << " " << nump << " " << curp << "\n";
  for (int i = 0; i < nump; ++i) {
    idx = (curp+i) % nump;
    result << peep[idx].toString();
  }
  result << "Draw " << draw.toString();
  for (int j = 0; j < 4; j++) {
    result << "Build_" << char('a'+j) << " ";
    result << build[j].toString();
  }
  return result.str();
}

void SkipBoGame::readIn(std::istream& is){
  bool shuff;
  std::string as;
  is >> as; //captures the first arg of the first line true or false;                                
  //if (ss.str() != "true") && (ss.str() != "false"){ Maybe create check for first arg}              
  if (as == "true"){
    shuff = true;
  }
  else {
    shuff = false;
  }
  draw.setShuff(shuff);

  is>>as; //second argument in first line , numP                                                     
  if( as == "2") {nump = 2;}
  else if(as == "3"){nump = 3;}
  else if(as == "4"){nump = 4;}
  else if(as == "5"){nump = 5;}
  else if(as == "6"){nump = 6;}


  is>>as; // third argument in second line, currP                                                    
    // std::string input = as;                                                                       
  //std::stringstream str;                                                                           
  for(int i = 0; i <nump; i++){
    std::stringstream str;
    str << i;
    if(str.str() == as){
      curp = i;
    }
  }
  std::vector<Player> ptemp;
  for (int i = 0; i < nump; i++) {
    is >> as; //gets the name of the Player from the file                                            
    //std::cout << as <<std::endl;                                                                   
    Player p  = Player(as);
    p.readIn(is);
    ptemp.push_back(p);
  }
  // <P2, P3, P0, P1>                                                                                
  for(int j = 0; j< nump; j++){
    peep.push_back(ptemp[(j+curp)%4]);
  }
  is>>as; //take "Draw" away because in the Pile code, when you do is>>num; it cannot convert a stri\
ng "Draw" to int val                                                                                 
  draw.readIn(is);
  
   for ( int bld = 0; bld < 4; bld++){ //to construct the build piles    
      is>>as; //just to get rid of the string                                                          
    build[bld].readIn(is);
    }
}
