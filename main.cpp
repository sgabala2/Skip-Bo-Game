//main.cpp FILE
#include <fstream>
#include <string>
#include "Card.h"
#include "Hand.h"
#include "Pile.h"
#include "DrawPile.h"
#include "SkipBoGame.h"
#include "Player.h"
#include "FaceUpPile.h"
#include "BuildPile.h"

using std::ifstream;
using std::endl;
using std::cout;
using std::vector;
using std::cerr;
using std::string;
using std::cin;

int main( int argc, char * argv[]){
  //Command-Lind error checking and creating SkipBo Object with provided information                 
  SkipBoGame Game;

  if (argc == 3 || argc == 5) { //First make sure that there are 5 and 3 inputs in line commands for new Game and loading Game respectively                                                              
    bool boolean;//captures whether or not user wants shuffle mode to be true or false               

    if( ((string)argv[1] != "false") && ((string)argv[1] != "true") ){
      cerr<< "invalid program usage: invalid first argument" <<endl;
      return 1;
    }
    if( (string)argv[1] == "false"){
      boolean = false;
    }
    else{
      boolean = true;
    }
    //Loading a saved Game                                                                           
    if(argc == 3){
      ifstream ifile(argv[2]);
      if (!ifile.is_open()) {//checks if the save file can be opened or not                          
        cerr<<"invalid program usage: can't open input game file"<<endl;
        return 1;
      }
      else { //the save                                                                              
        Game.readIn(ifile);
        //cout << Game.getCurP()<<endl;                                                              
        Game.setShuff(boolean); //whatever the user inputs for shuffle Mode on commandLine will be overridden                                                                                            
        if (boolean){
          Game.Shuffle(); //when shuffle mode is true, the game will shuffle the deck                
        }
      }
    }
    //Creating a new game with information provided on the command line                              
    else if(argc == 5){
      ifstream ifile(argv[4]);
       if ((atoi(argv[2]) < 2 ) || (atoi(argv[2]) > 6 )){ //checking number of players               
        cerr<<"invalid program usage: num players must be 2-6"<<endl;
        return 1;
      }
      cout<<"num players is "<<atoi(argv[2]) <<endl;

      if( (atoi(argv[3]) * atoi(argv[2]) > (162-(atoi(argv[2])*5))) || atoi(argv[3]) <=0 ) {//checking for stock size: if numplayer *stock is greater than numcards in deck                              
        cerr<<"invalid program usage: bad stock size"<<endl;
        return 1;
      }
      cout<<"stock size is "<<atoi(argv[3]) <<endl;
      if (!ifile.is_open()) { //checking if deck file provided  is valid                             
        cerr<<"invalid program usage: can't open deck file"<<endl;
        return 1;
      }
      cout << endl;
      SkipBoGame game = SkipBoGame(atoi(argv[2]), boolean); //copying information for game to this temporary SkipBoGame variable                                                                         
      int card;
      
      while (ifile >> card) { //adds all cards from deck file to drawPile                            
        Card c(card);
        game.addDraw(c);
      }
      if (game.getRand()){ //drawPile gets shuffled if shuffle mode is true                          
        game.Shuffle();
      }
      for (int stock = 1; stock <= atoi(argv[3]); stock ++){ //round robin give out card to each player                                                                                                  
        for (int player = 0; player < game.getNumP(); player++){
          game.addStock(player , game.removeDraw());
        }
      }
      Game = game; //copying info from game to Game because game is local variable within if statement                                                                                                   
    }
  }
  else { //if inline arguments is not sufficient, i.e if arg number is not 5 or 3                    
    cerr<<"invalid program usage: invalid number of arguments"<<endl;
    return 1;
  }
  //SkipBo Gameplay                                                                                  
  bool done = false; //controlling                                                                   
  while (!done) { //Win condition: if game is not done, then game will continue, every iteration here is a different player                                                                              
    string choice; // storage variable for p, s, q                                                   
    int check = -1;
    //cout <<Game.getCurP() << endl;                                                                 
    cout<< " >> " << Game.getName(Game.getCurP())<< " turn next" << endl << "(p)lay, (s)ave, or (q)u\
it ? ";

    if (!(cin >> choice)){//accounts for if user his ctrl + d here                                   
      cout<<endl;
      return 0;
    }
    //changing s, q, p from string to int so that we can use switch statement                        
    if(choice=="s"){
      check = 0;
    }
    else if(choice == "q"){
      check = 1;
    }
    else if(choice == "p"){
      check = 2;
    }

    switch (check){
    case 0: //if option s                                                                            
      {
        string saveFile;
        cout<<"save filename: " ;
        cin>> saveFile;
        std::ofstream oFile(saveFile);
        Game.reShuffle();
        oFile<<Game.toString();
        return 0;
      }
        
      case 1:{ //if option q                                                                           
      cout<<"thanks for playing"<<endl;
      return 0; }

    case 2:{//if option p, proceed to playing game                                                   
      int hasDiscard = 0;
      if (Game.handSize(Game.getCurP()) < 5){
        for ( int i = Game.handSize(Game.getCurP()); i < 5; i++){ //refills the Players hand to 5 at the start of their turn                                                                             
          if ( Game.drawSize() == 0){ //refills the draw pile if empty                               
            Game.reShuffle();
          }
          Game.addHand(Game.getCurP(), Game.removeDraw());
        }

        while(hasDiscard == 0 && (Game.stockSize(Game.getCurP())!=0)){ //current Player keeps playing until they discard                                                                                 
          Game.display();
          cout<<"(m)ove [start] [end] or (d)raw ? ";
          string a1;
          if (!(cin >> a1)){ //when user wants to end program with ctrl +d                           
            cout<<endl;
            return 0;
          }
          
