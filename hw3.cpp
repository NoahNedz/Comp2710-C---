/*  Noah Niedzwiecki
    ID = 903731609
    filename = hw3.cpp
    "I used the class notes for the random number generator and stack overflow for"
	call by reference syntax. Also all the cin ignore has been commented out at the TA's request"
    "I compiled my code using the GCC compiler in my os, Manjaro, an arch linux based distro"
    
*/

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <random>

using namespace std;

//method delcaration

void test_at_least_two_alive();
bool at_least_two_alive(bool&, bool& , bool&);

bool a_hit();
bool b_hit();
bool c_hit();

void Aaron_shoots1(bool&, bool&);
void Aaron_shoots2(bool&, bool&);
void test_Aaron_shoots1();
void test_Aaron_shoots2();

void Bob_shoots(bool&, bool&);
void test_Bob_shoots();

void Charlie_shoots(bool&, bool&);
void test_Charlie_shoots();


//one of the constant requirements detailing the max round number
const double rounds = 10000;




/* Implementation of the test driver for at_least_two_alive() */
void test_at_least_two_alive(void) {
    bool A_alive;
    bool B_alive;
    bool C_alive;
	
    cout << "Unit Testing 1: Function – at_least_two_alive()\n";
    cout << "Case 1: Aaron alive, Bob alive, Charlie alive\n";
    A_alive = true;
    B_alive = true;
    C_alive = true;
    assert(true == at_least_two_alive(A_alive, B_alive, C_alive));
    cout << "Case passed ...\n";
    cout << "Case 2: Aaron dead, Bob alive, Charlie alive\n";
    A_alive = false;
    assert(true == at_least_two_alive(A_alive, B_alive, C_alive));
    cout << "Case passed ...\n";
    cout << "Case 3: Aaron alive, Bob dead, Charlie alive\n";
    A_alive = true;
    B_alive = false;
    assert(true == at_least_two_alive(A_alive, B_alive, C_alive));
    cout << "Case passed ...\n";
    cout << "Case 4: Aaron alive, Bob alive, Charlie dead\n";
    B_alive = true;
    C_alive = false;
    assert(true == at_least_two_alive(A_alive, B_alive, C_alive));
    cout << "Case passed ...\n";
    cout << "Case 5: Aaron dead, Bob dead, Charlie alive\n";
    A_alive = false;
    B_alive = false;
    C_alive = true;
    assert(false == at_least_two_alive(A_alive, B_alive, C_alive));
    cout << "Case passed ...\n";
    cout << "Case 6: Aaron dead, Bob alive, Charlie dead\n";
    B_alive = true;
    C_alive = false;
    assert(false == at_least_two_alive(A_alive, B_alive, C_alive));
    cout << "Case passed ...\n";
    cout << "Case 7: Aaron alive, Bob dead, Charlie dead\n";
    B_alive = false;
    A_alive = true;

    assert(false == at_least_two_alive(A_alive, B_alive, C_alive));
    cout << "Case passed ...\n";
    cout << "Case 8: Aaron dead, Bob dead, Charlie dead\n";
    A_alive = false;
    assert(false == at_least_two_alive(A_alive, B_alive, C_alive));
    cout << "Case passed ...\n";
}

//test the Aaron_shoots1 method using the boolean variables of whether bob or charlie are alive
void test_Aaron_shoots1(void){
    cout << "Unit Testing 2: Function – Aaron_shoots1(Bob_alive, Charlie_alive)\n";
    bool C_alive;
    bool B_alive;
    ////////////////////////////////////////////////
    cout << "Case 1: Bob alive, Charlie alive\n";
    cout << "Aaron is shooting at Charlie\n";
    B_alive = true;
    C_alive = true;
    Aaron_shoots1(B_alive, C_alive);
    if (C_alive == true) {
        cout << "Aaron misses" << endl;
    }
    else {
        cout << "Charlie is dead" << endl;
    }
    ////////////////////////////////////////////////
    cout << "Case 2: Bob dead, Charlie alive\n";
    B_alive = false;
    C_alive = true;
    cout << "Aaron is shooting at Charlie\n";
    Aaron_shoots1(B_alive, C_alive);
    if (C_alive == true) {
        cout << "Aaron misses" << endl;
    }
    else {
        cout << "Charlie is dead" << endl;
    }

    ////////////////////////////////////////////////
    cout << "Case 3: Bob alive, Charlie dead\n";
    B_alive = true;
    C_alive = false;
    cout << "Aaron is shooting at Bob\n";
    Aaron_shoots1(B_alive, C_alive);
    if (B_alive == true) {
        cout << "Aaron misses" << endl;
    }
    else {
        cout << "Bob is dead" << endl;
    }
   
}

//test the bob_shoots method using the boolean values of whether aaron or charlie are alive
void test_Bob_shoots(void){
    cout << "Unit Testing 3: Function – Bob_shoots(Aaron_alive, Charlie_alive)\n";
bool A_alive;
bool C_alive;
////////////////////////////////////////////////
    cout << "Case 1: Aaron alive, Charlie alive\n";
    cout << "Bob is shooting at Charlie\n";
    A_alive = true;
    C_alive = true;
    Bob_shoots(A_alive, C_alive);
    if (C_alive == true) {
        cout << "Bob misses" << endl;
    }
    else {
        cout << "Charlie is dead" << endl;
    }

    ////////////////////////////////////////////////
    cout << "Case 2: Aaron dead, Charlie alive\n";
    cout << "Bob is shooting at Charlie\n";
    A_alive = false;
    C_alive = true;
    Bob_shoots(A_alive, C_alive);
    if (C_alive == true) {
        cout << "Bob misses" << endl;
    }
    else {
        cout << "Charlie is dead" << endl;
    }

    ////////////////////////////////////////////////
    cout << "Case 3: Aaron alive, Charlie dead\n";
    cout << "Bob is shooting at Aaron\n";
    A_alive = true;
    C_alive = false;
    Bob_shoots(A_alive, C_alive);
    if (A_alive == true) {
        cout << "Bob misses" << endl;
    }
    else {
        cout << "Aaron is dead" << endl;
    }
}


//tests the Charlie_shoots method using boolean values of whether aaron or bob are alive
void test_Charlie_shoots(void){
 cout << "Unit Testing 4: Function – Charlie_shoots(Aaron_alive, Bob_alive)\n";
bool A_alive;
bool B_alive;


////////////////////////////////////////////////
    cout << "Case 1: Aaron alive, Bob alive\n";
    cout << "Charlie is shooting at Bob\n";
    A_alive = true;
    B_alive = true;
    Charlie_shoots(A_alive, B_alive);
    if (B_alive == true) {
        cout << "Charlie misses" << endl;
    }
    else {
        cout << "Bob is dead" << endl;
    }
    ////////////////////////////////////////////////
    cout << "Case 2: Aaron dead, Bob alive\n";
    cout << "Charlie is shooting at Bob\n";
    A_alive = false;
    B_alive = true;
    
    Charlie_shoots(A_alive, B_alive);
    
    if (B_alive == true) {
        cout << "Charlie misses" << endl;
    }
    else {
        cout << "Bob is dead" << endl;
    }
    ////////////////////////////////////////////////
    cout << "Case 3: Aaron alive, Bob dead\n";
    cout << "Charlie is shooting at Aaron\n";
    A_alive = true;
    B_alive = false;
    Charlie_shoots(A_alive, B_alive);
    if (A_alive == true) {
        cout << "Charlie misses" << endl;
    }
    else {
        cout << "Aaron is dead" << endl;
    }
}


//Tests the aaron_shoots2 method
void test_Aaron_shoots2(void){
////////////////////////////////////////////////
bool C_alive = true;
bool B_alive = true;
    cout << "Unit Testing 5: Function – Aaron_shoots2(Bob_alive, Charlie_alive)\n";

    cout << "Case 1: Bob alive, Charlie alive\n";
    cout << "Aaron intentionally misses his first shot" << endl;
    
	
    Aaron_shoots2(B_alive, C_alive);
    if (C_alive == true && B_alive == true) {
        cout << "Both Bob and Charlie are alive" << endl;
    }
    else {
        cout << "Error" << endl;
    }
    ////////////////////////////////////////////////
    cout << "Case 2: Bob dead, Charlie alive\n";
    B_alive = false;
    C_alive = true;
    cout << "Aaron is shooting at Charlie\n";
    Aaron_shoots2(B_alive, C_alive);
    if (C_alive == true) {
        cout << "Aaron misses" << endl;
    }
    else {
        cout << "Charlie is dead" << endl;
    }

    ////////////////////////////////////////////////
    cout << "Case 3: Bob alive, Charlie dead\n";
    B_alive = true;
    C_alive = false;
    cout << "Aaron is shooting at Bob\n";
    Aaron_shoots2(B_alive, C_alive);
    if (B_alive == true) {
        cout << "Aaron misses" << endl;
    }
    else {
        cout << "Bob is dead" << endl;
    }
   
}



//dont judge the simplicity >.>
 bool at_least_two_alive(bool& A_alive, bool& B_alive, bool& C_alive) {
    int i = 0;

    if (A_alive){
        i ++;
    }
    if (B_alive) {
        i++;
    }
    if (C_alive) {
        i++;
    }
    
    if (i >= 2) {
        return true;
    }
    else {
        return false;
    }


}

 
 //method for changing alive statuses for whoever aaron shoots at
 void Aaron_shoots1(bool& B_alive, bool& C_alive) {
    
    if (C_alive) {
        if (a_hit()) {
            C_alive = false;
            return;
        }
    }
    
    if (!C_alive) {
        if (a_hit()) {
            B_alive = false;
            return;
        }
    }
 }
 
 //second method for aaron shooting
void Aaron_shoots2(bool& B_alive, bool& C_alive) {

if (C_alive && !B_alive) {
    if (a_hit()) {
        C_alive = false;
        return;
        }
}

if (C_alive && B_alive) {
    C_alive = true;
    return;        
}
    
if (!C_alive) {
    if (a_hit()) {
        B_alive = false;
        return;
        }
    }
}


//bobs shooting method that changes alive status
void Bob_shoots(bool& A_alive, bool& C_alive) {

if (C_alive) {
        if (b_hit()) {
            C_alive = false;
            return;
        }
    }
    
    if (!C_alive) {
        if (b_hit()) {
            A_alive = false;
            return;
        }
    }
 }

//charlie's shooting method, always kills
void Charlie_shoots(bool& A_alive, bool& B_alive) {
    
    if (B_alive) {
        B_alive = false;
        return;
    }
        
    if (!B_alive) {
        A_alive = false;
        return;    
        }
 }



// calls random number to see if with aarons odds he hits the mark
bool a_hit() {
	
	//constant accuracy for aaron's shooting
    const double aOdds = .33;
    double shoot_target_result;
    shoot_target_result = 1.0 * rand() / RAND_MAX;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(1, 0);
    shoot_target_result = dis(gen);
    
	if (shoot_target_result <= aOdds) {
        return true;
    }
    else {
        return false;
    }
}

//calls random number to see if bob hits the mark
bool b_hit() {
	
	//constant for accuracy of bob
	const double bOdds = .5;
    
    double shoot_target_result;
    shoot_target_result = 1.0 * rand() / RAND_MAX;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(1, 0);
    shoot_target_result = dis(gen);
    
	if (shoot_target_result <= bOdds) {
        return true;
    }
    else {
        return false;
    }
}


int main() {
    bool A_alive;
    bool B_alive;
    bool C_alive;
	int i = 0;
	//constant for getting the wins into percentage form
	const double divider = 100.00;
    
    
    int A_won2 = 0;
    int B_won2 = 0;
    int C_won2 = 0;
    int A_won = 0;
    int B_won = 0;
    int C_won = 0;
    

    cout << "****Welcome to Noah's duel simulator****"<< endl;
    //silly testing 
   
    test_at_least_two_alive();
    cout << "Press any key to continue..." << endl;
    cout << "\n";

    //cin.ignore().get();
    test_Aaron_shoots1();
    cout << "Press any key to continue..." << endl;
    cout << "\n";
    //cin.ignore().get();
    test_Bob_shoots();
    cout << "Press any key to continue..." << endl;
    cout << "\n";
    //cin.ignore().get();
    test_Charlie_shoots();
    cout << "Press any key to continue..." << endl;
    cout << "\n";
    //cin.ignore().get();
    test_Aaron_shoots2();
    cout << "Press any key to continue..." << endl;
    cout << "\n";
    
    cout << "Ready to test strategy 1 (run 10000 times)" << endl;
    cout << "Press any key to continue..." << endl;
    cout << "\n";
   //cin.ignore().get();

    
        
    do {
     A_alive = true;
     B_alive = true;
     C_alive = true;
     
        do {
            if (A_alive) {
            Aaron_shoots1(B_alive, C_alive);
            }
            if (B_alive) {
            Bob_shoots(A_alive, C_alive);
            }
            if (C_alive) {
            Charlie_shoots(A_alive, B_alive);
            }
        } while(at_least_two_alive(A_alive, B_alive, C_alive));
        
       
        
        if (A_alive) {
            A_won++;
        }
        if (B_alive) {
            B_won++;
        }
        if (C_alive) {
            C_won++;
        }
        i++;
    } while (i < rounds);
    
	//set the print accuracy
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
	
	//print the results
	
    cout <<"Aaron won " << A_won << "/10000 duels or " << (A_won/divider) << "%\n";
    cout <<"Bob won " << B_won << "/10000 duels or " << (B_won/divider) << "%\n";
    cout <<"Charlie won " << C_won << "/10000 duels or " << (C_won/divider) << "%\n";
    
    cout << "Ready to test strategy 2 (run 10000 times)" << endl;
    cout << "Press any key to continue..." << endl;
    cout << "\n";

    
    //cin.ignore().get();
    
	//reset the variables
    i = 0;
    A_won2 = 0;
    B_won2 = 0;
    C_won2 = 0;
    
    do {
     
     A_alive = true;
     B_alive = true;
     C_alive = true;
     
        do {
            if (A_alive) {
            Aaron_shoots2(B_alive, C_alive);
            }
            if (B_alive) {
            Bob_shoots(A_alive, C_alive);
            }
            if (C_alive) {
            Charlie_shoots(A_alive, B_alive);
            }
        } while(at_least_two_alive(A_alive, B_alive, C_alive));
       
      
        
        if (A_alive) {
            A_won2++;
        }
        if (B_alive) {
            B_won2++;
        }
        if (C_alive) {
            C_won2++;
        }
        i++;
    } while (i < rounds);
    
    cout <<"Aaron won " << A_won2 << "/10000 duels or " << (A_won2/divider) << "%\n";
    cout <<"Bob won " << B_won2 << "/10000 duels or " << (B_won2/divider) << "%\n";
    cout <<"Charlie won " << C_won2 << "/10000 duels or " << (C_won2/divider) << "%\n";

    if(A_won > A_won2){
        cout << "Strategy 1 is better than strategy 2" << endl;
    }
    else {
        cout << "Stategy 2 is better than strategy 1" << endl;
    }
}
