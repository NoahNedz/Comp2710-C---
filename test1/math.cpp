
#include <iostream>
#include <cstdlib>
#include <random>
#include <fstream>



using namespace std;

int main() {

    double a = 5.0;
    int b = 3;
    int d = 5;

    cout << (a/b) << endl;
    // = 1.6667

    double c = static_cast<double>(d/b);
    cout << c << endl;
    // = 1

    double e = (a/(double)b);
    cout << e << endl;
    // = 1.66667

    double doubleVar = static_cast<double>(d / b);
    cout << doubleVar << endl;
    
    int x[10] = {1,2,3,4,5,6,7,8,9};
    
    cout << "array = " << x[9] << endl;
    
    int y = 5;
    double g = (6 % 5);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    double t = 5.123423434;

    cout << (t) << endl;

    double f = 1.0 * rand() / RAND_MAX;
    cout << f << endl;


    cout << "given an array find all vals disible by 5" << endl;
    int j[10] = {10,67,45,32,21,77,89,90,100,54};
    int newArray[100];
    for(int g = 0; g < 10; ++g){
        if (j[g] % 5 == 0) {
            newArray[g] = j[g];
            cout << j[g] << endl;
        } 
    }



/*
ifstream filereader;
filereader.open(filename);

while(filereader >> array[x]) {
    x++;
}

ofstream outputfile;
outputfile.open(filename);
while (z < outputArray_size)
myfile << outputArray[z]
*/
}


