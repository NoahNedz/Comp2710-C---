/*  Noah Niedzwiecki
    ID = 903731609
    filename = Project2.cpp
    "All temporary datas are stored in their respective Temp.txt file"
    "Branch Staff and Admin user names and passwords are stored in users.txt"
    "Temporary account and client data are stored in accoutsTemp.txt or clientsTemp.txt"
    "If there are any questions you have involving my code, email me at nmn0005@auburn.edu It is probably a feature"
    "I compiled my code using the GCC compiler in my os, Manjaro, an arch linux based distro"
    
*/

#include <string>
#include <iostream>
#include <random>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <algorithm>
#include <array>

using namespace std;

class User{
string name;
string password;
int access;
public:
    string getName();
    int setName(string);
    string getPass();
    int setPass(string);
    User(string,string,int);
    int getAccess();
    int setAccess(int);
    
};
User::User(string namez,string passz,int accessz){
name = namez;
password = passz;  
access = accessz;
}
string User::getName(){
return name;
}

int User::setName(string namez){
    name = namez;
    return 0;
}
string User::getPass(){
return password;
}

int User::setPass(string passz){
    password = passz;
    return 0;
}
int User::getAccess(){
    return access;
}

int User::setAccess(int accessz){
    access = accessz;
    return 0;
}



class Menu {
public:
Menu();
string userName;
string passWord;
string userRead;
string passRead;
string authorization;
string authorizationRead;
string clientAddress;
string clientSS;
string clientEmployer;
string clientName;
string clientIncome;

string clientAddressRead;
string clientSSRead;
string clientEmployerRead;
string clientNameRead;
string clientIncomeRead;
string clientAddressRead1;
string clientSSRead1;
string clientEmployerRead1;
string clientNameRead1;
string clientIncomeRead1;

string accountNumber;
string accountType;
string accountBalance;

string accountNumberRead;
string accountTypeRead;
string accountBalanceRead;

double BalanceVal;
double depositAmount;
double withdrawAmount;

//ofstream myfileOut;
ifstream myfile;
string newUser;
string newPass;

string filenameT;
string filenameT2;

int menuSelection(int);
int MainMenu();
int loginMenu();
int adminMenu();
int branchMenu();
int addBranch();
int AccountManage();
int passMenu();
int deleteBranch();
int displayBranch();
int addClient();
int addAccount();
int editClient();
int manageAccount();
int saveClientAccount();
int MenuChoice = 0;
bool valid = false;

};
Menu::Menu(){
}


int Menu::menuSelection(int choicez){
    if(choicez == 1) {
        MainMenu();
    }
    if(choicez == 2) {
        loginMenu();
    }
    if(choicez == 3) {
        adminMenu();
    }
    if(choicez == 4) {
        branchMenu();
    }
    if(choicez == 5) {
        AccountManage();
    }
    if(choicez == 6){
        passMenu();
    }
    if(choicez == 7) {
        addBranch();
    }
    if(choicez == 8) {
        deleteBranch();
    }
    if(choicez == 9) {
        displayBranch();
    }
    if(choicez == 10){
        addClient();
    }
    if(choicez == 11){
        addAccount();
    }
    if(choicez == 12) {
        editClient();
    }
    if(choicez == 13) {
        manageAccount();
    }
    if(choicez == 14) {
        saveClientAccount();
    }
    
    return 0;
}

int Menu::branchMenu(){
    cout << "===================================================\n";
    cout << "|     Teller Terminal System - Branch Staff       |\n";
    cout << "===================================================\n";
    
    cout << "1) Client and Account Management\n";
    cout << "2) Change Password\n";
    cout << "3) Exit\n";
    while (!valid) {
        valid = true;
        cin >> MenuChoice;
        if (cin.fail() || MenuChoice < 1 || MenuChoice > 3) {
            cin.clear();
            cin.ignore();
            valid = false;
            } 
    }
    valid = false; //reset valid
    if(MenuChoice == 1) {
        menuSelection(5);
    }
    if(MenuChoice == 2) {
        menuSelection(6);
    }
    if(MenuChoice == 3) {
        MainMenu();
    }
    
    return 0;
    
}

int Menu::AccountManage(){
    cout << "===========================================================\n";
    cout << "| Teller Terminal System - Client and Account Management  |\n";
    cout << "===========================================================\n";
    cout << "1) Add a client\n";
    cout << "2) Add an account\n";
    cout << "3) Edit Client Information\n";
    cout << "4) Manage an account\n";
    cout << "5) Save Client and Account Information\n";
    cout << "6) Exit\n";
    while (!valid) {
    valid = true;
    cin >> MenuChoice;
    if (cin.fail() || MenuChoice < 1 || MenuChoice > 6) {
        cin.clear();
        cin.ignore();
        valid = false;
        } 
    }
    valid = false; //reset valid
    
    if(MenuChoice == 1){
     menuSelection(10);  
        
    }
    if(MenuChoice == 2){
        menuSelection(11);
    }
    if(MenuChoice == 3) {
        menuSelection(12);
    }
    if(MenuChoice == 4) {
        menuSelection(13);
    }
    if(MenuChoice == 5){
        saveClientAccount();
    }
    if(MenuChoice ==6) {
        std::ofstream myfileOut6("clientsTemp.txt");
        std::ofstream myfileOut7("accountsTemp.txt"); 
        if(authorization == "2") {
            menuSelection(4);
        }
        else{
            menuSelection(3);
        }
    }
    
    
    return 0;   
}

int Menu::passMenu(){
    cout << "New Password:\n";
    cin.ignore();
    
    
    while (!valid) {
    valid = true;
    getline(cin,newPass);
    if (cin.fail() || newPass.length() < 1) {
        cin.clear();
        //cin.ignore();
        valid = false;
        } 
    }
    valid = false; //reset valid
    
    
    
     std::replace(newPass.begin(), newPass.end(), ' ', '_');
    filenameT = "users.txt";
    char *cArrayT = ((char*)filenameT.c_str());
    myfile.open(cArrayT);
    
    
    std::ofstream myfileOut("usersOut.txt");

    
    if (myfile.fail()) {
       cout << "Input file opening failed" << endl;
       myfile.close();
       return 0;
    }
    if (myfileOut.fail()) {
       cout << "Output file opening failed" << endl;
       myfileOut.close();
       return 0;
    }
    int found = 0;
    while(myfile >> userRead >> passRead >> authorizationRead) {
        
        if(userRead == userName && newPass != passRead){
            found = 1;
            passRead = newPass;
            
        }
        if(userRead == userName && newPass == passRead){
            
            passRead = passRead;
        }
    
    myfileOut << userRead << " " << passRead << " " << authorizationRead<<std::endl;            
    }
    
    myfile.close();  
    remove(cArrayT);
    rename("usersOut.txt", "users.txt");
    
    
    if(found == 1) {
        cout << "Password was changed!\n";
            if(authorization == "1") {
                menuSelection(3); //if admin 
            }
            if(authorization == "2") {
                menuSelection(4);
            }
    } 
    
    if(found == 0){
        
     cout <<"New password matches old, please choose a different password\n";   
         if(authorization == "1") {
                menuSelection(3); //if admin 
            }
            if(authorization == "2") {
                menuSelection(4);
            }
    }
    
    cout <<"Could not find your username in the database\n";
    if(authorization == "1") {
                menuSelection(3); //if admin 
            }
            if(authorization == "2") {
                menuSelection(4);
            }
    
    return 0;   
}
int Menu::addClient(){
    cin.ignore();
    cout << "A new client will be added: \n";
    cout << "Client name: \n";
    
    
    while (!valid) {
    valid = true;
    getline(cin,clientName);
    if (cin.fail() || clientName.length() < 1) {
        cin.clear();
        //cin.ignore();
        valid = false;
        } 
    }
    valid = false; //reset valid
    
    std::replace(clientName.begin(), clientName.end(), ' ', '_');
    
    filenameT = "clients.txt";
    char *cArrayT = ((char*)filenameT.c_str());
    myfile.open(cArrayT);
    
    if (myfile.fail()) {
       cout << "Input file opening failed" << endl;
       myfile.close();
       return 0;
    } 
    
    
    ifstream myfile10;
    string filenameT10 = "clientsTemp.txt";
    char *cArrayT10 = ((char*)filenameT10.c_str());
    myfile10.open(cArrayT10);
    
    while(myfile10 >> clientNameRead) {
        //cout << userRead << " " << passRead << endl;
        if(clientNameRead == clientName) {
            cout << "Client Already Exists\n";
            myfile10.close();
            AccountManage();
        }
    }
    myfile10.close(); 
    
    while(myfile >> clientNameRead) {
        //cout << userRead << " " << passRead << endl;
        if(clientNameRead == clientName) {
            cout << "Client Already Exists\n";
            myfile.close();
            AccountManage();
        }
    }
    myfile.close();
    
    cout << "Address: \n";
    
    while (!valid) {
    valid = true;
    getline(cin,clientAddress);
    if (cin.fail() || clientAddress.length() < 1) {
        cin.clear();
        //cin.ignore();
        valid = false;
        } 
    }
    valid = false; //reset valid
    
    std::replace(clientAddress.begin(), clientAddress.end(), ' ', '_');
    cout << "Social security number: \n";
    
    while (!valid) {
    valid = true;
    getline(cin,clientSS);
    if (cin.fail() || clientSS.length() < 1) {
        cin.clear();
        //cin.ignore();
        valid = false;
        } 
    }
    valid = false; //reset valid

    std::replace(clientSS.begin(), clientSS.end(), ' ', '_');
    cout << "Employer: \n";
    
    while (!valid) {
    valid = true;
    getline(cin,clientEmployer);
    if (cin.fail() || clientEmployer.length() < 1) {
        cin.clear();
        //cin.ignore();
        valid = false;
        } 
    }
    valid = false; //reset valid

    std::replace(clientEmployer.begin(), clientEmployer.end(), ' ', '_');
    cout << "Annual income: \n";
    while (!valid) {
    valid = true;
    getline(cin,clientIncome);
    if (cin.fail() || clientIncome.length() < 1) {
        cin.clear();
        //cin.ignore();
        valid = false;
        } 
    }
    valid = false; //reset valid
    
    
    std::replace(clientIncome.begin(), clientIncome.end(), ' ', '_');
    

    
    //goes here if not found
        
        string filenameT8 = "clientsTemp.txt";
    char *cArrayT8 = ((char*)filenameT8.c_str());
        myfile.open(cArrayT8);
        
        std::ofstream myfileOut("clientsOut.txt");
    
    if (myfile.fail()) {
       cout << "Input file opening failed" << endl;
       myfile.close();
       return 0;
    }
    if (myfileOut.fail()) {
       cout << "Output file opening failed" << endl;
       myfileOut.close();
       return 0;
    }
    
    while(myfile >> clientNameRead >> clientAddressRead >> clientSSRead >> clientEmployerRead >> clientIncomeRead) {
         myfileOut << clientNameRead << " " << clientAddressRead << " " << clientSSRead << " " <<clientEmployerRead <<" " << clientIncomeRead << std::endl;   
        }
        myfile.close();
        
    myfileOut << clientName << " " << clientAddress << " " << clientSS << " "<< clientEmployer << " " << clientIncome << std::endl;            
    myfile.close(); 
    myfileOut.close();
    remove("clientsTemp.txt");
    rename("clientsOut.txt", "clientsTemp.txt");
    cout <<"created\n";
    
    menuSelection(5);
    
    return 0;
}




int Menu::addAccount(){
    cin.ignore();
    cout << "Choose a client: \n";
    getline(cin,clientName);
    std::replace(clientName.begin(), clientName.end(), ' ', '_');
    
    filenameT = "clients.txt";
    char *cArrayT = ((char*)filenameT.c_str());
    myfile.open(cArrayT);
    
    if (myfile.fail()) {
       cout << "Input file opening failed" << endl;
       myfile.close();
       return 0;
    } 
    int found = 0;
    while(myfile >> clientNameRead) {
        
        if(clientNameRead == clientName) {
            found = 1;
        }
    }
    myfile.close();
    if(found == 0) {
        cout << "Error - The client is not in the system!\n";
        myfile.close();
        AccountManage();
    }

    std::replace(clientName.begin(), clientName.end(), '_', ' ');
    cout << "A new account will be created for " << clientName << "...\n";
    std::replace(clientName.begin(), clientName.end(), ' ', '_');
    
    cout << "Account Number: \n";
    cin >> accountNumber;
    
    cout << "Account Type: \n";
    cin.ignore();
    
    
    while (!valid) {
    valid = true;
    getline(cin,accountType);
    if (cin.fail() || accountType.length() < 1) {
        cin.clear();
        cin.ignore();
        valid = false;
        } 
    }
    valid = false; //reset valid
    
   
    std::replace(accountType.begin(), accountType.end(), ' ', '_');
    
    //cin.ignore();
    cout << "Balance: \n";
     while (!valid) {
    valid = true;
    cin >> accountBalance;
    if (cin.fail()) {
        cin.clear();
        cin.ignore();
        valid = false;
        } 
    }
    
    valid = false;
    
    
    ifstream myfile2;
    filenameT2 = "accounts.txt";
    char *cArrayT2 = ((char*)filenameT2.c_str());
    myfile2.open(cArrayT2);
    
    
    ifstream myfile10;
    string filenameT10 = "accountsTemp.txt";
    char *cArrayT10 = ((char*)filenameT10.c_str());
    myfile10.open(cArrayT10);
    
    while(myfile10 >> clientNameRead >> accountNumberRead >> accountTypeRead >> accountBalanceRead ) {
        if(accountNumber == accountNumberRead){
            cout <<"Account Number already in the system\n";
            myfile2.close();
            myfile.close();
            myfile10.close();
            AccountManage();
        }
    }
    
    
    myfile10.close();
    
    if (myfile2.fail()) {
       cout << "Input file opening failed" << endl;
       myfile2.close();
       AccountManage();
       return 0;
    } 
    
    std::ofstream myfileOut("accountsOut.txt");
    if (myfileOut.fail()) {
       cout << "Output file opening failed" << endl;
       myfileOut.close();
       AccountManage();
       return 0;
    }
    
    while(myfile2 >> clientNameRead >> accountNumberRead >> accountTypeRead >> accountBalanceRead ) {
        if(accountNumber == accountNumberRead){
            cout <<"Account Number already in the system\n";
            myfile2.close();
            myfile.close();
            AccountManage();
        }
    }
    myfile.close();
    myfile2.close();
    
    ifstream myfile3;
    string filenameT3 = "accountsTemp.txt";
    char *cArrayT3 = ((char*)filenameT3.c_str());
    myfile3.open(cArrayT3);
    
    
    
    
    while(myfile3 >> clientNameRead >> accountNumberRead >> accountTypeRead >> accountBalanceRead) {
        ///cout << clientNameRead << " " << accountNumberRead << " " << accountTypeRead << " " <<accountBalanceRead << endl;
        myfileOut << clientNameRead << " " << accountNumberRead << " " << accountTypeRead << " " <<accountBalanceRead<<std::endl;   
        }
        
    myfileOut << clientName << " " << accountNumber << " " << accountType << " " <<accountBalance << std::endl;            
    myfile3.close(); 
    myfileOut.close();
    remove("accountsTemp.txt");
        rename("accountsOut.txt", "accountsTemp.txt");
    cout <<"created\n";
    menuSelection(5);
 
    return 0;    
}


int Menu::editClient(){
    cout <<"Choose a client: \n";
    cin.ignore();
    getline(cin,clientName);
    std::replace(clientName.begin(), clientName.end(), ' ', '_');
    
    
    ifstream myfile;
    string filenameT = "clients.txt";
    char *cArrayT = ((char*)filenameT.c_str());
    myfile.open(cArrayT);
    int found =0;
    
    
    
    ifstream myfile3;
    string filenameT3 = "clientsTemp.txt";
    char *cArrayT3 = ((char*)filenameT3.c_str());
    myfile3.open(cArrayT3);
    
    std::ofstream myfileOut3("clientsOut.txt");
    
    while(myfile3 >> clientNameRead >> clientAddressRead >> clientSSRead >> clientEmployerRead >> clientIncomeRead) {
        
        if(clientName == clientNameRead){
           cout<<"Please save your current edits!\n";
           myfileOut3.close();
           myfile3.close();
           AccountManage();
        }
        cout <<"Writing\n";
        
        
    }
    myfile3.close();
    
    
    
    while(myfile >> clientNameRead >> clientAddressRead >> clientSSRead >> clientEmployerRead >> clientIncomeRead) {
        if(clientName == clientNameRead){
            found = 1;
            clientAddress = clientAddressRead;
            clientSS = clientSSRead;
            clientEmployer = clientEmployerRead;
            clientIncome = clientIncomeRead;
            
        }
    }
    if (found ==0){
        cout << "Could not find Client\n";
        myfile.close();
        AccountManage();
    }
    myfile.close();
    std::replace(clientName.begin(), clientName.end(), '_', ' ');
    std::replace(clientAddress.begin(), clientAddress.end(), '_', ' ');
    std::replace(clientEmployer.begin(), clientEmployer.end(), '_', ' ');
    cout <<"Display " << clientName << "'s Information:\n";
    cout <<"Address: " << clientAddress << endl;
    cout <<"Social security number: "<< clientSS << endl;
    cout <<"Employer: " << clientEmployer << endl;
    
    cout<<"Client " << clientName << "'s information will be updated ...\n";
    cout<<"1) Confirm\n";
    cout<<"2) Cancel\n";
    
    cout << "Please choose an option: \n";
    
    while (!valid) {
    valid = true;
    cin >> MenuChoice;
    if (cin.fail() || MenuChoice < 1 || MenuChoice > 2) {
        cin.clear();
        cin.ignore();
        valid = false;
        } 
    }
    valid = false; //reset valid
    
    if(MenuChoice == 1) {
      
    cin.ignore();    
    cout << "Address: \n";
    
    while (!valid) {
    valid = true;
    getline(cin,clientAddress);
    if (cin.fail() || clientAddress.length() < 1) {
        cin.clear();
        //cin.ignore();
        valid = false;
        } 
    }
    valid = false; //reset valid
    
    
    
    
    std::replace(clientAddress.begin(), clientAddress.end(), ' ', '_');
    cout << "Social security number: \n";
    
    while (!valid) {
    valid = true;
    getline(cin,clientSS);
    if (cin.fail() || clientSS.length() < 1) {
        cin.clear();
        //cin.ignore();
        valid = false;
        } 
    }
    valid = false; //reset valid
    
    
    std::replace(clientSS.begin(), clientSS.end(), ' ', '_');
    cout << "Employer: \n";
    
    while (!valid) {
    valid = true;
    getline(cin,clientEmployer);
    if (cin.fail() || clientEmployer.length() < 1) {
        cin.clear();
        //cin.ignore();
        valid = false;
        } 
    }
    valid = false; //reset valid
    
    
    
    std::replace(clientEmployer.begin(), clientEmployer.end(), ' ', '_');
    cout << "Annual income: \n";
    while (!valid) {
    valid = true;
    getline(cin,clientIncome);
    if (cin.fail() || clientIncome.length() < 1) {
        cin.clear();
        //cin.ignore();
        valid = false;
        } 
    }
    valid = false; //reset valid
    
    
    std::replace(clientIncome.begin(), clientIncome.end(), ' ', '_');
    
    myfile.close();
    
    //goes here if not found
        
    
    string filenameT9 = "clientsTemp.txt";
    char *cArrayT9 = ((char*)filenameT9.c_str());
    myfile.open(cArrayT9);
        
        std::ofstream myfileOut("clientsOut.txt");
    
    if (myfile.fail()) {
       cout << "Input file opening failed" << endl;
       myfile.close();
       return 0;
    }
    if (myfileOut.fail()) {
       cout << "Output file opening failed" << endl;
       myfileOut.close();
       return 0;
    }
    
    
    
     while(myfile >> clientNameRead >> clientAddressRead >> clientSSRead >> clientEmployerRead >> clientIncomeRead) {
         myfileOut << clientNameRead << " " << clientAddressRead << " " << clientSSRead << " " <<clientEmployerRead <<" " << clientIncomeRead << std::endl;   
        }
        
    myfileOut << clientName << " " << clientAddress << " " << clientSS << " "<< clientEmployer << " " << clientIncome << std::endl;            
    
    myfile.close(); 
    myfileOut.close();
    remove("clientsTemp.txt");
    rename("clientsOut.txt", "clientsTemp.txt");    
    std::replace(clientName.begin(), clientName.end(), '_', ' ');    
    cout <<"Client " << clientName <<"'s information was updated ...\n";    
    AccountManage();     
    }
    
    if(MenuChoice == 2) {
     AccountManage();        
    }
    
    return 0;    
}




int Menu::manageAccount(){
    cout << "Which account will be managed?\n";
    cin >> accountNumber;   
    
    //search for this account number
    
    
    filenameT = "accounts.txt";
    char *cArrayT = ((char*)filenameT.c_str());
    myfile.open(cArrayT);
    
    if (myfile.fail()) {
       cout << "Input file opening failed" << endl;
       myfile.close();
       return 0;
    } 
    int found = 0;
    while(myfile >> clientNameRead >> accountNumberRead >> accountTypeRead >> accountBalanceRead) {
        
        if(accountNumberRead == accountNumber) {
            found = 1;
            std::replace(clientNameRead.begin(), clientNameRead.end(), '_', ' ');
            clientName = clientNameRead;
            accountType = accountTypeRead;
            accountBalance = accountBalanceRead;
            myfile.close();
        }
    }
    if(found == 0) {
        cout << "Error - The account is not in the system!\n";
        myfile.close();
        AccountManage();
    }
    
    cout << "Manage account " << accountNumber << " for " << clientName << " ..." << endl;
    cout << "1) Deposit\n";
    cout << "2) Withdraw\n";
    cout << "3) Cancel\n";
    cout << "Please choose an option: \n";
    
    while (!valid) {
    valid = true;
    cin >> MenuChoice;
    if (cin.fail() || MenuChoice < 1 || MenuChoice > 3) {
        cin.clear();
        cin.ignore();
        valid = false;
        } 
    }
    
    valid = false;
    
    if(MenuChoice == 1) {
        cout << "Deposit Amount: \n";
        
        cin >> depositAmount;
        
        if(depositAmount < 0){
            cout << "Input is not valid\n";
            manageAccount();
        }
    
        
        stringstream(accountBalance)>>BalanceVal;
        BalanceVal +=depositAmount;
        
    }
    if(MenuChoice == 2) {
     cout << "Withdraw Amount: \n";
        
        while (!valid) {
    valid = true;
    cin >> withdrawAmount;
    if (cin.fail()) {
        cin.clear();
        cin.ignore();
        valid = false;
        } 
    }
    
    valid = false;
      stringstream(accountBalance)>>BalanceVal;
        BalanceVal -=withdrawAmount;   
    }
    if(MenuChoice == 3) {
       AccountManage();
    }
       

        cout << "Balance of account " << accountNumber << " is: " << BalanceVal<< endl;
        myfile.close();
        
        
        std::ofstream myfileOut("accountsOut.txt");
        myfile.open(cArrayT);
    
    if (myfile.fail()) {
       cout << "Input file opening failed" << endl;
       myfile.close();
       return 0;
    }
    if (myfileOut.fail()) {
       cout << "Output file opening failed" << endl;
       myfileOut.close();
       return 0;
    }
    
    while(myfile >> clientNameRead >> accountNumberRead >> accountTypeRead >> accountBalanceRead) {
        
        if(accountNumberRead == accountNumber){
            std::ostringstream strs;
            strs << BalanceVal;
            std::string str = strs.str();
            std::replace(clientNameRead.begin(), clientNameRead.end(), ' ', '_');
            accountBalanceRead = str;
        }
    
    myfileOut << clientNameRead << " " << accountNumberRead << " " << accountTypeRead << " " << accountBalanceRead <<std::endl;            
    }
    
    myfile.close();  
    remove("accountsTemp.txt");
    rename("accountsOut.txt", "accountsTemp.txt");
    myfileOut.close();
    AccountManage();    
    
    return 0;
}

int Menu::saveClientAccount(){
    
    ifstream myfile0;
    string filename0 = "clients.txt";
    char *cArrayT0 = ((char*)filename0.c_str());
    myfile0.open(cArrayT0);
    
    ifstream myfile1;
    string filename1 = "clientsTemp.txt";
    char *cArrayT1 = ((char*)filename1.c_str());
    myfile1.open(cArrayT1);
    
    
    std::ofstream myfileOut3("clientsOut.txt");
    
    
    string array1[100];
    int i = 0;
    int j = 0;
    bool inThere = false;
    while(myfile1 >> clientNameRead >> clientAddressRead >> clientSSRead >> clientEmployerRead >> clientIncomeRead){//fills array with new elements to be added
        array1[i] = clientNameRead;
        //cout << "IN THE TEMP " << array1[i] << endl;
        i++;
        
    }
    
    
    while(myfile0 >> clientNameRead >> clientAddressRead >> clientSSRead >> clientEmployerRead >> clientIncomeRead){//reading clients
     while(j <= i){
         //cout << "comparing " << array1[j] << " to " << clientNameRead << endl;
         if(array1[j] == clientNameRead) {
             inThere = true;
             break;
         }
         
         
        j++;
     }
     
     if(inThere == false){
         
      myfileOut3 <<  clientNameRead << " " << clientAddressRead << " " << clientSSRead << " " << clientEmployerRead<< " " << clientIncomeRead<<std::endl;
     }
     else{
         
      myfileOut3 <<"" << "" << "" << "" << ""<<std::endl;
       //cout << "EMPTY\n";
      inThere = false;
     }
     
     
    }
    
     myfile1.close();
     myfile0.close();
     myfileOut3.close();
    remove("clients.txt");
    rename("clientsOut.txt", "clients.txt");
    
    //////
    
    ifstream myfile2;
    string filename2 = "clients.txt";
    char *cArrayT2 = ((char*)filename2.c_str());
    myfile2.open(cArrayT2);
    
    ifstream myfile3;
    string filename3 = "clientsTemp.txt";
    char *cArrayT3 = ((char*)filename3.c_str());
    myfile3.open(cArrayT3);
    
    
    std::ofstream myfileOut4("clientsOut.txt");
    
    
    while(myfile2 >> clientNameRead >> clientAddressRead >> clientSSRead >> clientEmployerRead >> clientIncomeRead) {
        myfileOut4 <<  clientNameRead << " " << clientAddressRead << " " << clientSSRead << " " << clientEmployerRead<< " " << clientIncomeRead<<std::endl;
    }
    while(myfile3 >> clientNameRead >> clientAddressRead >> clientSSRead >> clientEmployerRead >> clientIncomeRead) {
         myfileOut4 <<  clientNameRead << " " << clientAddressRead << " " << clientSSRead << " " << clientEmployerRead<< " " << clientIncomeRead<<std::endl;
    }
    
    
    myfile2.close();
    myfile3.close();
    myfileOut4.close();
    std::ofstream myfileOut5("clientsTemp.txt");
    myfileOut5.close();
    
    remove("clients.txt");
    rename("clientsOut.txt", "clients.txt");  
        
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    ifstream myfile10;
    string filename10 = "accounts.txt";
    char *cArrayT10 = ((char*)filename10.c_str());
    myfile10.open(cArrayT10);
    
    ifstream myfile11;
    string filename11 = "accountsTemp.txt";
    char *cArrayT11 = ((char*)filename11.c_str());
    myfile11.open(cArrayT11);
    
    
    std::ofstream myfileOut31("accountsOut.txt");
    
    
    string array11[100];
    int i1 = 0;
    int j1 = 0;
    bool inThere1 = false;
    while(myfile11 >> clientNameRead >> accountNumberRead >> accountTypeRead >> accountBalanceRead){//fills array with new elements to be added
        array11[i1] = accountNumberRead;
        
        i1++;
        
    }
    
    
    while(myfile10 >> clientNameRead >> accountNumberRead >> accountTypeRead >> accountBalanceRead){//reading accounts
     while(j1 <= i1){
         
         if(array11[j1] == clientNameRead) {
             inThere1 = true;
             break;
         }
         
         
        j1++;
     }
     
     if(inThere1 == false){
         
      myfileOut31 <<  clientNameRead << " " << accountNumberRead << " " << accountTypeRead << " " << accountBalanceRead <<std::endl; 
     }
     else{
         
      myfileOut31 <<"" << "" << "" << "" <<std::endl;
       //cout << "EMPTY\n";
      inThere1 = false;
     }
     
     
    }
    
     myfile11.close();
     myfile10.close();
     myfileOut31.close();
    remove("accounts.txt");
    rename("accountsOut.txt", "accounts.txt");
    
    //////
    
    ifstream myfile21;
    string filename21 = "accounts.txt";
    char *cArrayT21 = ((char*)filename21.c_str());
    myfile21.open(cArrayT21);
    
    ifstream myfile31;
    string filename31 = "accountsTemp.txt";
    char *cArrayT31 = ((char*)filename31.c_str());
    myfile31.open(cArrayT31);
    
    
    std::ofstream myfileOut41("accountsOut.txt");
    
    
    while(myfile21 >> clientNameRead >> accountNumberRead >> accountTypeRead >> accountBalanceRead) {
        myfileOut41 << clientNameRead << " " << accountNumberRead << " " << accountTypeRead << " " << accountBalanceRead <<std::endl; 
    }
    while(myfile31 >> clientNameRead >> accountNumberRead >> accountTypeRead >> accountBalanceRead) {
         myfileOut41 <<  clientNameRead << " " << accountNumberRead << " " << accountTypeRead << " " << accountBalanceRead <<std::endl; 
    }
    
    
    myfile21.close();
    myfile31.close();
    myfileOut41.close();
    std::ofstream myfileOut51("accountsTemp.txt");
    myfileOut5.close();
    
    remove("accounts.txt");
    rename("accountsOut.txt", "accounts.txt"); 
    
    
    cout <<"-Saved-\n";
    AccountManage();
    
    return 0;
}



int Menu::addBranch(){
    
    int role;
    
    cin.ignore();
    cout <<"User Name: \n";
    
    while (!valid) {
    valid = true;
    getline(cin,newUser);
    if (cin.fail() || newUser.length() < 1) {
        cin.clear();
        valid = false;
        } 
    }
    valid = false; //reset valid
    
    std::replace(newUser.begin(), newUser.end(), ' ', '_');
    cout <<"Password: \n";
    
    while (!valid) {
    valid = true;
    getline(cin,newPass);
    if (cin.fail() || newPass.length() < 1) {
        cin.clear();
        valid = false;
        } 
    }
    valid = false; //reset valid
    std::replace(newPass.begin(), newPass.end(), ' ', '_');
    cout <<"Role (1 - Administration; 2 - Branch Staff): \n";
    
    while (!valid) {
        valid = true;
        cin >> role;
        if (cin.fail() || role < 1 || role > 2) {
            cin.clear();
            cin.ignore();
            valid = false;
        } 
    }
    valid = false; //reset valid
    
    cout << "1) Confirm\n";
    cout << "2) Cancel\n";
    cout << "Please choose an option: \n";
    
    while (!valid) {
    valid = true;
    cin >> MenuChoice;
    if (cin.fail() || MenuChoice < 1 || MenuChoice > 2) {
        cin.clear();
        cin.ignore();
        valid = false;
        } 
    }
    valid = false; //reset valid
    
    if(MenuChoice == 1) {
        
        filenameT = "users.txt";
        char *cArrayT = ((char*)filenameT.c_str());
        myfile.open(cArrayT);
        
        std::ofstream myfileOut("usersOut.txt");
    
    if (myfile.fail()) {
       cout << "Input file opening failed" << endl;
       myfile.close();
       return 0;
    }
    if (myfileOut.fail()) {
       cout << "Output file opening failed" << endl;
       myfileOut.close();
       return 0;
    }
    
    while(myfile >> userRead >> passRead >> authorizationRead) {
        if(userRead == newUser){
         cout <<"User Already Exists\n"; 
         myfile.close();
         menuSelection(7);         
        }
        myfileOut << userRead << " " << passRead << " " << authorizationRead<<std::endl;
        }
        
    myfileOut << newUser << " " << newPass << " " << role<<std::endl;            
    myfile.close();  
    remove(cArrayT);
    rename("usersOut.txt", "users.txt");
    cout <<"created\n";
    
    if(authorization == "1") {
        menuSelection(3); //if admin 
     }
     if(authorization == "2") {
         menuSelection(4);
     }    
    }
    
        
    if(MenuChoice == 2) {
        if(authorization == "1") {
        menuSelection(3); //if admin 
     }
     if(authorization == "2") {
         menuSelection(4);
     }
    }
    
    return 0;
}
int Menu::deleteBranch(){
   cout << "Delete a user - User Name : \n";
   cin.ignore();
   getline(cin,newUser);
   std::replace(newUser.begin(), newUser.end(), ' ', '_');
   if(newUser == userName) {
       cout <<"Cannot delete yourself!\n";
       if(authorization == "2") {
                //cout << "logging in as staff\n";
                menuSelection(4);
            }
            else{
                //cout << "logging in as admin\n";
                menuSelection(3);
            }
   }
   valid = false; //reset valid
    
    cout << "1) Confirm\n";
    cout << "2) Cancel\n";
    cout << "Please choose an option: \n";
    
    while (!valid) {
    valid = true;
    cin >> MenuChoice;
    if (cin.fail() || MenuChoice < 1 || MenuChoice > 2) {
        cin.clear();
        cin.ignore();
        valid = false;
        } 
    }
    valid = false; //reset valid
    if(MenuChoice == 1) {
        
        filenameT = "users.txt";
        char *cArrayT = ((char*)filenameT.c_str());
        myfile.open(cArrayT);
        
        std::ofstream myfileOut("usersOut.txt");
    
    if (myfile.fail()) {
       cout << "Input file opening failed" << endl;
       myfile.close();
       return 0;
    }
    if (myfileOut.fail()) {
       cout << "Output file opening failed" << endl;
       myfileOut.close();
       return 0;
    }
        
        int found = 0;
        while(myfile >> userRead >> passRead >> authorizationRead) {
            
            if(userRead == newUser){
                found = 1;
                passRead = "";
                userRead ="";
                authorizationRead = "";
            
        }
    
    myfileOut << userRead << " " << passRead << " " << authorizationRead<<std::endl;            
    }
    myfile.close();  
    remove(cArrayT);
    rename("usersOut.txt", "users.txt");
    
    
    if(found == 1) {
        cout << "Account Deleted\n";
            if(authorization == "1") {
                menuSelection(3); //if admin 
            }
            if(authorization == "2") {
                menuSelection(4);
            }
    }  
    
    cout <<"Could not find that username in the database\n";
    if(authorization == "1") {
                menuSelection(3); //if admin 
            }
            if(authorization == "2") {
                menuSelection(4);
            }
    }
    
    if(MenuChoice == 2) {
        if(authorization == "2") {
                //cout << "logging in as staff\n";
                menuSelection(4);
            }
            else{
                //cout << "logging in as admin\n";
                menuSelection(3);
            }
        
    }
    return 0;
   }
   
   
int Menu::displayBranch(){
    
    filenameT = "users.txt";
    char *cArrayT = ((char*)filenameT.c_str());
    myfile.open(cArrayT);
    
    if (myfile.fail()) {
       cout << "Input file opening failed" << endl;
       myfile.close();
       return 0;
    } 
    int numberPeople = 0;
    while(myfile >> userRead >> passRead >> authorizationRead) {
    numberPeople++;
    }
    myfile.close();
    myfile.open(cArrayT);
    
    if (myfile.fail()) {
       cout << "Input file opening failed" << endl;
       myfile.close();
       return 0;
    } 
    cout << "There are " << numberPeople << " users in the system\n";
    while(myfile >> userRead >> passRead >> authorizationRead) {
        if(authorizationRead == "1"){
            authorizationRead = "System Administrator";
        }
        if(authorizationRead == "2") {
            authorizationRead = "Branch Staff";
        }
        std::replace(userRead.begin(), userRead.end(), '_', ' ');
        cout << "User Name: " << userRead << " Role: " << authorizationRead << endl;
    }
    myfile.close();
    if(authorization == "2") {
                //cout << "logging in as staff\n";
                menuSelection(4);
            }
            else{
                //cout << "logging in as admin\n";
                menuSelection(3);
            }
    
    return 0;
}

int Menu::adminMenu(){
    cout << "===================================================\n";
    cout << "| Teller Terminal System - System Administration  |\n";
    cout << "===================================================\n";
    cout << "1) Client and Account Management\n";
    cout << "2) Add a Branch Staff Member\n";
    cout << "3) Delete a Brance Staff Member\n";
    cout << "4) Display Branch Staff\n";
    cout << "5) Change Password\n";
    cout << "6) Exit\n";
    
    
    while (!valid) {
    valid = true;
    cin >> MenuChoice;
    if (cin.fail() || MenuChoice < 1 || MenuChoice > 6) {
        cin.clear();
        cin.ignore();
        valid = false;
        } 
    }
    valid = false; //reset valid
    
    if(MenuChoice == 1) {
        menuSelection(5);
    }
    if(MenuChoice == 2) {
        menuSelection(7);
    }
    if(MenuChoice == 3) {
        menuSelection(8);
    }
    if(MenuChoice == 4) {
        menuSelection(9);
    }
    if(MenuChoice == 5) {
        menuSelection(6);
    }
    if(MenuChoice == 6) {
        MainMenu();
    }
    
   return 0; 
}

int Menu::loginMenu(){
    string lines;
    int success = 0;
    cout << "===================================================\n";
    cout << "|   Login to Access the Teller Terminal System    |\n";
    cout << "===================================================\n";
    cout << "User Name: \n";
    
    
    //cin.ignore();
    getline(cin, userName);
    
    std::replace(userName.begin(), userName.end(), ' ', '_'); 
    
    cout << "Password: \n";
    
    getline(cin, passWord);
    std::replace(passWord.begin(), passWord.end(), ' ', '_');
    filenameT = "users.txt";
    char *cArrayT = ((char*)filenameT.c_str());
    myfile.open(cArrayT);
    
    if (myfile.fail()) {
       cout << "Input file opening failed" << endl;
       myfile.close();
       return 0;
    } 

    while(myfile >> userRead >> passRead >> authorization) {
        //cout << userRead << " " << passRead << endl;
        if(userRead == userName && passRead == passWord) {
            cout << "login successful\n";
            success = 1;
            myfile.close();
            
            if(authorization == "2") {
                //cout << "logging in as staff\n";
                menuSelection(4);
            }
            else{
                //cout << "logging in as admin\n";
                menuSelection(3);
            }
        }
    }
    
    if(success == 0) {
        cout << "The  user name or password is incorrect. Try again!\n";
        myfile.close();
        MainMenu();   
    }
    
    return 0;
}

int Menu::MainMenu(){
    cout << "===================================================\n";
    cout << "|   Welcome to the Auburn Branch of Tiger Bank!   |\n";
    cout << "===================================================\n";
    cout << "1) Login\n";
    cout << "2) Quit\n";
    cout << "Please choose an option\n";
    
    while (!valid) {
    valid = true;
    cin >> MenuChoice;
    if (cin.fail() || MenuChoice < 1 || MenuChoice > 2) {
        cin.clear();
        cin.ignore();
        valid = false;
        } 
    }
    valid = false; //reset valid
    
    if(MenuChoice == 1) {
        cin.ignore();
        menuSelection(2);
    }
    if(MenuChoice == 2) {
        exit(0);
    }


    
    return 0;
}

int main(){
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    Menu menu;
    menu.menuSelection(1); 
    
    return 0;
}
