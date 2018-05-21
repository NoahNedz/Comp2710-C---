/*  Noah Niedzwiecki
    ID = 903731609
    filename = hw2.cpp
    "I used the class notes for cout precision techniques"
    "I compiled my code using the GCC compiler in my os, Manjaro, an arch linux based distro"
    
*/

#include <iostream>
#include <string>
#include <iomanip>



using namespace std;
using std::cout;
using std::setw;

//global variables because this program is simple
double loanAmmount;
double interestRate;
double monthlyPayments;
int month = 1;
double balance;
double interestVal;
double principal;
double totalInterest;
double lastPrincipal;

int populateTable();
bool doubleCheck();


//gets the input and responds accordingly, either populateTable() or restart
int main() {

    cout << "Loan Amount: ";
        cin >> loanAmmount;
            balance = loanAmmount;

    cout << "Interest Rate (% per year): ";
        cin >> interestRate;
        

    cout << "Monthly Payments: ";
        cin >> monthlyPayments;

    //basic math
    interestVal = balance * (interestRate / 100);   
    totalInterest = 0;
    principal = monthlyPayments - interestVal;
    
    //double check if it goes to infinity
    if (doubleCheck()) {
        
        populateTable();
        cout << "It takes " << month << " months to pay off the loan." << endl;
        cout << "Total interest paid is: " << totalInterest << endl;
    }
    
    else {
        
        main();   
    } 
 return 0;       
}


//produces the table data
int populateTable() {


    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    std::cout << std::setw(7); 
    
    //initial header output
    cout << "**********************************************************"<<endl;
    cout << "       Amortization Table                                 "<<endl;
    cout << "**********************************************************"<<endl;
    cout << "Month   Balance         Payment    Rate        Interest      Princial" << endl;
    cout << "0" << setw(8) << "$" << balance << setw(11) << " N/A" << setw(11) << "N/A" << setw(12) << "N/A" << setw(14) << "N/A" <<endl;
    
    //first month balance    
    interestVal = balance * (interestRate / 100); 
    principal = (monthlyPayments - interestVal);
    balance = balance - principal;
    totalInterest = totalInterest + interestVal;
    

        //main loop for table creation until the last row
        while (balance > 0) { 
            
            cout << left << month << setw(8) << right << "$" << balance << setw(9) << "$" << monthlyPayments << setw(9) << interestRate << setw(9) << "$" <<interestVal << setw(9) << "$" << principal << endl;
            
            month++;
            interestVal = balance * (interestRate / 100); 
            principal = (monthlyPayments - interestVal);
            lastPrincipal = balance;
            balance = balance - principal;
            totalInterest = totalInterest + interestVal;
            
            double lastPrincipal = balance;

        }
        
        //last row list fill
        monthlyPayments = monthlyPayments - balance; 
        interestVal = lastPrincipal * (interestRate / 100);
        monthlyPayments = interestVal + lastPrincipal;
        balance = 0;        
        
        cout << left << month << setw(9) << right << "$" << balance << setw(9) << "$" << monthlyPayments << setw(9) << interestRate << setw(9) << "$" << interestVal << setw(9) << "$" << lastPrincipal << endl;
    return 0;
}


bool doubleCheck() {
    
    if (interestVal >= monthlyPayments) {
        cout << "Input rates would result in infinity. Please try again" << endl;
        return false;
    }
    
    return true;    
}














