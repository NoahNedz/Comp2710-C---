#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Money{
public:
    int dollar;
    int cents;
    Money();
    Money(int,int);
    int getCents();
    int getDollars();
   
    
};





 const Money operator +(Money& ammount1,Money& ammount2) {
      int  dollar1 = ammount1.getDollars();
      int dollar2 = ammount2.getDollars();
      int cents1 = ammount1.getCents();
      int cents2 = ammount2.getCents();
      int* pointer;
      
      int finalDol = dollar1 + dollar2;
      int finalCen = cents1 + cents2;
      
      return Money(finalDol,finalCen);
    }
Money::Money(int dola,int centa) {
    dollar = dola;
    cents = centa;
}
Money::Money() {
}
int Money::getCents() {
    return cents;
}
int Money::getDollars(){
    return dollar;
}

int main(){
    Money noah(12,20);
    Money bob(5,22);
     
    Money total(1,20);
    total = (bob+noah);
    //cout << total.dollar << " " << total.cents << endl;
    
    typedef int* wow;
    Money* neat;
    neat = new Money();
    neat->dollar = 22;
    cout << neat->dollar<< endl;
    
    
    
    
    wow p = new int;
    wow z = new int;
    int* sheet;
    int seven = 7;
    sheet = &seven;
    
    int zest[2] = {1};
    p = &zest[0];
    cout << *p << endl;
    
    
    return 0;
}
