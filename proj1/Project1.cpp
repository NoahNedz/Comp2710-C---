/*  Noah Niedzwiecki
    ID = 903731609
    filename = Project1.cpp
    "I referenced a stack overflow solution for the sort algorithm function"
    "highscores.txt must have 5 names and values in it at all times to work
    "simple bot names have been added to keep this true" 
    "I compiled my code using the GCC compiler in my os, Manjaro, an arch linux based distro"
    
*/


#include <string>
#include <iostream>
#include <random>
#include <fstream>
#include <iostream>
using namespace std;



//Character class manipulates all User Stats during game play
class Character {
string Name;
int Location;
int Time;
int Money;
int Intelligence;
int Score;

public:
Character();
void set_name(string);
void set_time(int);
void set_location(int);
void set_money(int);
void set_intelligence(int);

string get_name();
int get_time();
int get_location();
int get_money();
int get_intelligence();
int get_score();
bool check();
void start_up(string);
int reset_user();

};

void Character::set_name(string name){
    Name =  name;
}
void Character::set_time(int time){
    Time = time;
} 
void Character::set_location(int location) {
    Location = location;
}
void Character::set_money(int money) {
    Money = money;
}
void Character::set_intelligence(int intelligence) {
    Intelligence = intelligence;
}
string Character::get_name() {
    return Name;
}
int Character::get_time() {
    return Time;
}
int Character::get_location() {
    return Location;
}
int Character::get_money() {
    return Money;
}
int Character::get_intelligence(){
    return Intelligence;
}
bool Character::check(){
    if (Time<= 0 || Money<= 0|| Intelligence <= 0 || Location >= 20) {
        return false;
    }
    return true;
}
int Character::get_score() {
 Score = ((Money+100) * (Intelligence+100) * Location * (Time + 20)/10);
return Score; 
}
int Character::reset_user() {
    Time = 25;
    Location = 0;
    Money = 20;
    Intelligence = 20;
    return 0;
}
    
 Character::Character() {
    Name = "";
    Time = 25;
    Location = 0;
    Money = 20;
    Intelligence = 20;
}

//HighScores handles everything to do with the high scores list
//-View the scores, add to scores, and sorts the scores
//adding scores always calls on sort so that when viewed it is always correct
class HighScores {
    public:
    int Scores[6];
    string Names[6];
    
    int read_score();
    int add_score(string, int);
    int sort_score();
    int show_scores();

    
    int Val1,Val2,Val3,Val4,Val5;
    string Str1,Str2,Str3,Str4,Str5;
    
    int userScore;
    
    string currString;
    string nextString;
    
    ifstream scoreReader;
    int index = 1;
    int indexN = 0;
};

    int HighScores::read_score(){
        
        string filenameT = "highscores.txt";
        char *cArrayT = ((char*)filenameT.c_str());
        scoreReader.open(cArrayT);
        //cout<< cArrayT << endl;

        
        
       // bool isEmpty = scoreReader.peek() == EOF;
     
   if (scoreReader.fail()) {
       cout << "Input file opening failed" << endl;
       scoreReader.close();
       
       return 0;
    } 

    while (scoreReader >> Str1 >> Val1 >> Str2 >> Val2 >> Str3 >> Val3 >> Str4 >> Val4 >> Str5 >> Val5) {
        
        Scores[0] = Val1;
        Scores[1] = Val2;
        Scores[2] = Val3;
        Scores[3] = Val4;
        Scores[4] = Val5;
        Names[0] = Str1;
        Names[1] = Str2;
        Names[2] = Str3;
        Names[3] = Str4;
        Names[4] = Str5;

        //cout << Str1 << " " << Val1 << " " << Str2 << " " << Val2 << " " << Str3 << " " << Val3 << " " << Str4 << " " << Val4 << " " << Str5 << " " << Val5 << endl;
    }
    scoreReader.clear();  
    scoreReader.close();
    return 0;
}

int HighScores::add_score(string name, int val){
    read_score();
    
    Names[5] = name;
    Scores[5] = val;
    //cout << Names[5] << endl;
    //cout <<Scores[5] << endl;
    sort_score();
    return 0;

}
int HighScores::sort_score(){
    int j,temp;
    string tempS;

for (int i = 0; i < 6; i++){
		j = i;
		//using insertion sort
		while (j > 0 && Scores[j] >= Scores[j-1]){
			  temp = Scores[j];
              tempS = Names[j];
              //cout <<temp << endl;

			  Scores[j] = Scores[j-1];
              Names[j] = Names[j-1];
              

			  Scores[j-1] = temp;

              Names[j-1] = tempS;
			  j--;
			  }
        }


ofstream myfile;

  //cout << "Writing" << endl;
  
  try {
string filenameT = "highscores.txt";
char *cArrayT = ((char*)filenameT.c_str());
   myfile.open(cArrayT);
  }

  catch(fstream::failure const &ex) {
       cout << "output file opening failed" << endl;
       myfile.close();
       return 0;
    }
    myfile << Names[0] << " " << Scores[0] << " " << Names[1] << " " << Scores[1] << " " << Names[2] << " " << Scores[2] << " " << Names[3] << " " << Scores[3] << " " << Names[4] << " " << Scores[4];
    //cout << Names[0] << " " << Scores[0] << "\n" << Names[1] << " " << Scores[1] << "\n" << Names[2] << " " << Scores[2] << "\n" << Names[3] << " " << Scores[3] << "\n" << Names[4] << " " << Scores[4] << endl;
    myfile.close();


return 0;   
}
int HighScores::show_scores(){
    read_score();
    cout <<"TOP 5 HIGH SCORES\n";
    cout << Str1 << " " << Val1 << "\n" << Str2 << " " << Val2 << "\n" << Str3 << " " << Val3 << "\n" << Str4 << " " << Val4 << "\n" << Str5 << " " << Val5 << endl;
    return 0;
}

//encounters handles everything that the user interacts with when playing the game
//rng decides what encounter and what puzzle is selected
class Encounters {
    public:
    int choice;
    double get_random();
    double rolls(Character& user);
    double spawn_event(Character& user);
    int dragHealth;
    int userHealth;
    int pickPocket(Character& user);
    int Read(Character& user);
    double result;  
    double rng;
};

double Encounters::get_random(){
     
    result = 1.0 * rand() / RAND_MAX;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(1, 0);
    result = dis(gen);
    return result;
}

double Encounters::rolls(Character& user) {
rng = get_random();
//cout << rng << endl;

    if (rng <= .35) { //35%
       
        spawn_event(user);
        return 0;
    }
    if(rng > .36 && rng < .52) { 
        cout << "You travel safely!\n";
                 cout<< "You move forward 1\n";
                 user.set_location(user.get_location() + 1);

        return 0;
    }
    if (rng >= .52 && rng < .63) { //10%
        cout<<"A stealthy pickpocket steals 5 of your hard earned dollars :(\n";
                 cout<< "You move forward 1\n";

        user.set_money(user.get_money() -5);
        user.set_location(user.get_location() + 1);
        return 0;
    }
    if (rng >= .63 && rng < .74) { //10%
    cout<<"A super fun puzzle book falls to your feet and you feel compelled to solve every page! -2 Time\n";
             cout<< "You move forward 1\n";

    user.set_time(user.get_time()-2);
    user.set_location(user.get_location() + 1);
    return 0;
    }
    if (rng >= .74 && rng < .85) { //10%
        cout<<"You find a shiny piece of gold in a nearby water fountain! +5 Money\n";
                 cout<< "You move forward 1\n";

        user.set_money(user.get_money() +5);
        user.set_location(user.get_location() + 1);
        return 0;
    }
    if (rng >= .85 && rng < .99) { //14%
        cout<<"A bearded wizard appears and grants you the knowledge of his ancestors! +5 Intelligence\n";
                 cout<< "You move forward 1\n";

        user.set_intelligence(user.get_intelligence() +5);
        user.set_location(user.get_location() + 1);
        return 0;
    }
    
    //DRAGON BATTLE//////////////////////////////////////////////////////////
    if (rng > .98 && rng <= 1.0) { //1%
        cout<<"A HUGE DRAGON APPEARS OUT OF NOWHERE!!!! PREPARE FOR COMBAT\n";
        dragHealth = 100;
        userHealth = 100;
    

        while (dragHealth != 0 && userHealth != 0) {
            cout<<"1) Attack\n";
            cout<<"2) RUN and lose lots of money and intelligence\n";
            cin>> choice;

            if (choice == 1) {
                rng = get_random();
                if (rng >= .5) {
                    cout << "You strike the dragon for 20 points of health\n";
                    dragHealth = dragHealth -20;
                }
                else {
                    cout << "You miss\n";
                rng = get_random();
                }
                
                if (rng <= .05) {
                    cout << "The dragon strikes you and you lose 50 points of health\n";
                    userHealth = userHealth - 50;
                }
                else {
                    cout <<"The dragon lunges at you but narrowly misses\n";
            }
        }
            if(choice == 2) {
                cout <<"You narrowly escape death but you lose 10 gold and 10 intelligence\n";
                user.set_intelligence(user.get_intelligence()-10);
                user.set_money(user.get_money() - 10);
                return 0; 
            }

          cout <<"Current battle stats:\n";
          cout <<"Your health: " << userHealth << endl;
          cout <<"Dragons health: " << dragHealth << endl;


        }
        if (dragHealth == 0) {
            cout <<"You have succesfully slayed the dragon hero! +$20 and +30 Time\n";
            user.set_money(user.get_money() + 20);
            user.set_time(user.get_time() + 30);
            return 0;
        }

        if (userHealth == 0) {
            cout <<"You have barely escaped death! -$10 and -10 Time\n";
            user.set_money(user.get_money() - 10);
            user.set_time(user.get_time() - 10);
            return 0;
        }

        return 0;
             cout<< "You move forward 1\n";

        
    }
    return 0;
    }
 
        //DRAGON BATTLE//////////////////////////////////////////////////////////
        
int Encounters::pickPocket(Character& user){
    cout <<"You attempt to pick the pocket of a random student in the hall\n";
            
    rng = get_random();
            
    if (rng >= .50) {
        cout <<"You succesfully steal 5 gold! +$5\n";
        user.set_money(user.get_money() + 5);
        return 0;
        }
    else {
        cout <<"You fail to steal any money :(\n";
        
        return 0;
        }
    return 0;
}

int Encounters::Read(Character& user){
    cout <<"You attempt to understand some of the mysteries of the lexicon\n";
            
    rng = get_random();
            
    if (rng >= .50) {
        cout <<"You succesfully transcribe a page +5 Intelligence\n";
        user.set_intelligence(user.get_intelligence() + 5);
        return 0;
        }
    else {
        cout <<"You fail to understand anything :(\n";
        return 0;
        }
    return 0;
    
    
}
            
        
double Encounters::spawn_event(Character& user){
    rng = get_random();
    //cout << "made it to event\n";
    //cout << rng << endl;

    if (rng >= 0.00 && rng < 0.10) { //10%
        cout<<"A bridgekeep steps in front of you path and says you must answer a riddle to pass!\n";
        cout<<"What is your name?\n";
        cout<<"1) " + user.get_name() << endl;
        cout<<"2) Sir Lancelot\n";
        cout<<"3) Sir Robin\n";
        cout<<"4) King Arthur\n";
        cin >> choice;
        if (choice == 1) {
         cout  << "\n";
         cout << "CORRECT!\n";
                  cout<< "You move forward 1\n";
                  user.set_location(user.get_location() + 1);

        }
        else {
            cout  << "\n";
            cout << "INCORRECT\n You are thrown backwards by a magical force and hit your head\n -3 Intelligence and you make no progress down the path\n";
            user.set_intelligence(user.get_intelligence() -3);
        }
    return 0;
    }
    if (rng >= .10 && rng < .20) { //10
        cout<<"A greasefire randomly errupts in a nearby kitchen!\n";
        cout<<"What is the proper way to put it out?\n";
        cout<<"1) Simply blow on it with your massive lungs!"<< endl;
        cout<<"2) Attempt to extinguish it with the pile of papers being held by an innocent goblin\n";
        cout<<"3) Turn off the source of heat and cover immediately, cancelling all oxygen supply\n";
        cout<<"4) Pour lots of water on it!\n";
        cin >> choice;
        if (choice == 3) {
         cout  << "\n";
         cout << "CORRECT!\n";
                  cout<< "You move forward 1\n";
                  user.set_location(user.get_location() + 1);

         return 0;   
        }
        else {
            cout  << "\n";
            cout << "INCORRECT\n You get third degree burns on 25 percent of your body and some money of yours gets destroyed\n -$3 You make no progress down the path\n";
            user.set_money(user.get_money() -3);
            return 0;   
        }
    return 0;
    }
    if (rng >= .20 && rng < .30) { //10
        cout<<"A bridgekeep steps in front of you path and says you must answer a riddle to pass!\n";
        cout<<"What is the capital of Assyria?\n";
        cout<<"1) Blue "<< endl;
        cout<<"2) London\n";
        cout<<"3) Constantinople\n";
        cout<<"4) Ashur\n";
        cin >> choice;
        if (choice == 4) {
         cout  << "\n";
         cout << "CORRECT!\n"; 
                  cout<< "You move forward 2\n";
                  user.set_location(user.get_location() + 2);

         return 0;      
        }
        else {
        cout  << "\n";
        cout << "INCORRECT\n You are thrown backwards by a magical force and hit your head\n -3 Intelligence and you make no progress down the path\n";
            user.set_intelligence(user.get_intelligence() -3);
            return 0;   
        }
    return 0;
    }
    if (rng >= .30 && rng < .40) { //10
        cout<<"A bridgekeep steps in front of you path and says you must answer a riddle to pass!\n";
        cout<<"What is the airspeed velocity of an unladen swallow?\n";
        cout<<"1) 44 mph "<< endl;
        cout<<"2) What do you mean, an African or a European swallow? \n";
        cout<<"3) Mach 2 \n";
        cout<<"4) 2 mph, they can't fly\n";
        cin >> choice;
        if (choice == 2) {
         cout  << "\n";
         cout << "CORRECT!\n";
                  cout<< "You move forward 2\n";
                  user.set_location(user.get_location() + 2);

         return 0;      
        }
        else {
        cout  << "\n";
        cout << "INCORRECT\n You are thrown backwards by a magical force and hit your head\n -3 Intelligence and you make no progress down the path\n";
            user.set_intelligence(user.get_intelligence() -3);
            return 0;   
        }
    return 0;
    }
    if (rng >= .40 && rng < .50) { //10
        cout<<"A bridgekeep steps in front of you path and says you must answer a riddle to pass!\n";
        cout<<"What is your favorite color?\n";
        cout<<"1) Grey"<< endl;
        cout<<"2) Green \n";
        cout<<"3) Purple \n";
        cout<<"4) Blue\n";
        cin >> choice;
        cout  << "\n";
        cout << "INCORRECT\n You are thrown backwards by a magical force and hit your head\n -3 Intelligence and you make no progress down the path\n";
        user.set_intelligence(user.get_intelligence() -3);
        return 0;   
        
    }
    if (rng >= .50 && rng < .60) { //10
        cout<<"What 3 positive numbers give the same result when multiplied and added together?\n";
        cout<<"1) 1,2, and 3 "<< endl;
        cout<<"2) 1,4, and 6? \n";
        cout<<"3) 7,1, and 2 \n";
        cout<<"4) 3,2, and 5\n";
        cin >> choice;
        if (choice == 1) {
         cout  << "\n";
         cout << "CORRECT!\n"; 
                  cout<< "You move forward 3 and gain +5 gold\n";
                  user.set_location(user.get_location() + 3);
                  user.set_money(user.get_money() + 5);

         return 0;     
        }
        else {
            cout  << "\n";
            cout << "INCORRECT\n You are extremely lazy with math!\n -3 Intelligence and you make no progress down the path\n";
            user.set_intelligence(user.get_intelligence() -3);
            return 0;   
        }
    return 0;
    }
    if (rng >= .60 && rng < .70) { //10
        cout<<"What is the ASCII code for the letter A?\n";
        cout<<"1) 065"<< endl;
        cout<<"2) 062\n";
        cout<<"3) 01 \n";
        cout<<"4) %00000001\n";
        cin >> choice;
        if (choice == 1) {
         cout  << "\n";
         cout << "CORRECT!\n"; 
                  cout<< "You move forward 1 and gain +3 Intelligence\n";
                  user.set_location(user.get_location() + 1);
                  user.set_intelligence(user.get_intelligence() +3);

         return 0;      
        }
        else {
            cout  << "\n";
            cout << "INCORRECT\n You are extremely lazy with math!\n -3 Intelligence and you make no progress down the path\n";
            user.set_intelligence(user.get_intelligence() -3);
            return 0;   
        }
    return 0;
    }
    if (rng >= .70 && rng < .80) { //10
        cout<<"What is %00000001 + 00000010?\n";
        cout<<"1) 10000100"<< endl;
        cout<<"2) 069\n";
        cout<<"3) 00000011 \n";
        cout<<"4) %00000001\n";
        cin >> choice;
        if (choice == 3) {
         cout  << "\n";
         cout << "CORRECT!\n"; 
                  cout<< "You move forward 2 and gain +3 intelligence\n";
                  user.set_location(user.get_location() + 2);
                  user.set_intelligence(user.get_intelligence() +3);

         return 0;      
        }
        else {
            cout  << "\n";
            cout << "INCORRECT\n You are extremely lazy with math!\n -3 Intelligence and you make no progress down the path\n";
            user.set_intelligence(user.get_intelligence() -3);
            return 0;   
        }
    return 0;
    }
    if (rng >= .80 && rng < .90) { //10
        cout<<"What is the capital of Maine?\n";
        cout<<"1) 24\n";
        cout<<"2) Augusta\n";
        cout<<"3) Little Rock \n";
        cout<<"4) Springfield\n";
        cin >> choice;
        if (choice == 2) {
         cout  << "\n";
         cout << "CORRECT!\n";
                  cout<< "You move forward 3\n";
                  user.set_location(user.get_location() + 3);

         return 0;      
        }
        else {
            cout  << "\n";
            cout << "INCORRECT!\n -3 Intelligence\n";
            user.set_intelligence(user.get_intelligence() -3);
            return 0;   
        }
    return 0;
    }
    if (rng >= .90 && rng <= 1.0) { //10
        cout<<"Who wrote this code that you are currently running?\n";
        cout<<"1) Noah Niedzwiecki\n";
        cout<<"2) George Smith\n";
        cout<<"3) Neat McGee \n";
        cout<<"4) IDK some random wizard I suppose\n";
        cin >> choice;
        if (choice == 1) {
            cout  << "\n";
         cout << "CORRECT!\n";
         cout<< "You move forward 3 and gain +5 time\n";
         user.set_location(user.get_location() + 3);
         user.set_time(user.get_time() +5);
         return 0;     
        }
        else {
            cout  << "\n";
            cout << "INCORRECT! My feelings are hurt :(\n -3 Intelligence and you make no progress down the path\n";
            user.set_intelligence(user.get_intelligence() -3);
            return 0;   
        }
    return 0;
    }
return 0;
}

//menu is the character interface, it lets the user select what actions to take in order to reach the end
//valid is used to guarantee input, the game does not progress unless a recognizable input is recieved
class Menu{
public:
    
    int mainMenuChoice;
    int gameChoice;
    bool valid = false;
    Encounters encounter;
    string mainMenu(Character& user);
    string gameStart(Character& user);
    HighScores scores;
        
    //Menu(Character& user);
      
};

string Menu::mainMenu(Character& user){
user.reset_user();
cout  << "\n";
cout << "WELCOME TO COLLEGE 101\n";
cout << "=====================================" << endl;
cout << "Welcome, " << user.get_name() << endl;
cout << "=====================================" << endl;
cout << "1) Start a new game" << endl;
cout << "2) View top 5 High Scores" << endl;
cout << "3) Quit" << endl;
mainMenuChoice = 0;

while (!valid) {
    valid = true;
    cin >> mainMenuChoice;
    if (cin.fail() || mainMenuChoice < 0 || mainMenuChoice > 3) {
        cin.clear();
        cin.ignore();
        valid = false;
    } 
}
valid = false; //reset valid
if (mainMenuChoice == 1) {
        
        gameStart(user);
    }
    if (mainMenuChoice == 2){
        scores.show_scores();
        mainMenu(user);
    }
    if (mainMenuChoice == 3){
        exit(0);
    }
return "nice";
}

string Menu::gameStart(Character& user){
cout << "Entering the game..." << endl;

while (user.check()){
    cout <<"\n";
    cout <<"====================================================================\n";
    cout << "You have:\nintelligence: " << user.get_intelligence() << "\ntime:" << user.get_time() << "\nmoney:" << user.get_money() << endl;
    cout <<"\n";
    cout << "You are " << (20-user.get_location()) << " from the goal. Time left: " << user.get_time() << endl;
    cout << "1) Move forward" << endl;
    cout << "2) Transcribe the Runed Lexicon" << endl;
    cout << "3) Pickpocket" << endl;
    cout << "4) View Character" << endl;
    cout << "5) Quit" << endl;//quiting does not store your score
    cout <<"====================================================================\n";

    while (!valid) {
        valid = true;
        cin >> gameChoice;
        if (cin.fail() || gameChoice < 0 || gameChoice > 6) {
            cin.clear();
            cin.ignore();
            valid = false;
        } 
    }
    valid = false; //reset valid
    if (gameChoice == 1) {
        //user.set_location(user.get_location() + 1);
        user.set_time(user.get_time() -1);
        encounter.rolls(user);
        gameChoice = 0;
        }
        if (gameChoice == 2){
            encounter.Read(user);
            user.set_time(user.get_time() -1);
            gameChoice = 0;
        }
        if (gameChoice == 3){
            encounter.pickPocket(user);
            user.set_time(user.get_time() -1);
            gameChoice = 0;
        }
        if (gameChoice == 4){
            cout << "CURRENT STATS:\n";
            cout <<"NAME: " << user.get_name() << endl;
            cout <<"GOLD: " << user.get_money() << endl;
            cout <<"INTELLIGENCE: " << user.get_intelligence() << endl;
            cout <<"TIME LEFT: " << user.get_time() << endl;
            cout <<"CURRENT LOCATION: " << user.get_location() << endl;
            cout <<"CURRENT SCORE: " << user.get_score() << endl;
            
        }
        if (gameChoice == 5){
            cout << "\n";
            return "nice";
            //exits to main menu
        }

    }
    //check what condition made it leave the loop and display properly
//return "nice";
    if (user.get_location() >= 20) {
        cout <<"YOU WIN!!!!\n";
        cout <<"Final Score = " << user.get_score() << endl;
        scores.add_score(user.get_name(),user.get_score());
    }
    else {
    cout<<"YOU LOSE!!!\n";
    cout <<"Final Score = " << user.get_score() << endl;
    scores.add_score(user.get_name(),user.get_score());
    }
        
  return "nice"; //continues in the main while loop  
}


//Main menu gets a proper character name and initializes the Character and Menu class.
//The created character gets passed into the menu class by reference
int main() {
    Character user;
    cout << "Enter Your Name(No Spaces)" << endl;
    string Name4Character = "";
    

    cin >> Name4Character;
   
    int strSiz = Name4Character.size();
    
    while (strSiz > 10)  {
        cout << "Please input a shorter name";
        cin >> Name4Character;
        strSiz = Name4Character.size();
    }
user.set_name(Name4Character); 

while (true) {
    
    Menu wow;
    wow.mainMenu(user);
    }
return 0;    
}




