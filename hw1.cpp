/*  Noah Niedzwiecki
    ID = 903731609
    filename = hw1.cpp
    "I used tutorialspoint.com to refresh on basic syntax that is unique to cpp"
    "I compiled my code using the GCC compiler in my os, Manjaro, a arch linux based distro"
    
*/


#include <iostream>
#include <string>
//#include <iomanip> if i need to change precision

using namespace std;
const double SWEET = .001;

int main() {
    double needed2Kill;
    double mouseWeight;
    double dieterWeight;
    double needed2Die;
    double numCans;
    
    cout << "What is the amount of artificial sweetener needed to kill a mouse: ";
    cin >> needed2Kill;

    
    cout << "What is the weight of the mouse: ";
    cin >> mouseWeight;

    
    cout << "What is the weight of the dieter: ";
    cin >> dieterWeight;

    
    needed2Die = (needed2Kill/mouseWeight) * dieterWeight;
    numCans = (needed2Die/SWEET);
    
    cout << "You can drink " << numCans << " diet sodas without dying as a result. \n";

    return 0;

}


