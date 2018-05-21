/*  Noah Niedzwiecki
    ID = 903731609
    filename = hw4.cpp
    "I referenced a stack overflow solution for the sort algorithm function, and aloglist.net for
    merge sort algorithm reference. THE TESTS RUN OFF OF THE GIVEN INPUT FILES BECAUSE THEY ARE STATIC"
    "THEY WILL NOT PASS IF THEY ARE NOT EQUAL TO THE STATIC ARRAYS BEING COMPARED"
    "THIS IS DONE BECAUSE READFILE NEEDS A INPUTSTREAM"
    "I compiled my code using the GCC compiler in my os, Manjaro, an arch linux based distro"
    
*/

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

const int MAX_SIZE = 100;

int readfile(int inputArray[], ifstream& instream);
int writefile(int outputArray[], int outputArray_size, string outputFileName);
int sortF(int inputArray1[], int inputArray1_size, int inputArray2[],int inputArray2_size, int outputArray[]);


main() {
   ifstream inStreamFirst;
   ifstream inStreamSecond;
   
   int iArray1[MAX_SIZE];
   int iArray1_size;
   int iArray2[MAX_SIZE];   
   int iArray2_size;
   string filename1;
   string filename2;
   string outputFileName;

   //for tests
   int iArrayT[MAX_SIZE];
   ifstream inStreamT;
   int iArrayT_size;
   string filenameT;

   int iArrayT2[MAX_SIZE];
   ifstream inStreamT2;
   int iArrayT2_size;
   string filenameT2;

   int iArrayT3[MAX_SIZE];
   ifstream inStreamT3;
   int iArrayT3_size;
   string filename3;

   ///////////

   
  
   
   
   ////////////////////////////////////////////
   
   cout << "*** Unit Test Cases ***" << endl;
   cout << "Unit Test Case 1: Function Name - readfile()" << endl;
   cout << "Case 1.1: Tests to see if correct length is generated from a known length file readfile readfile(inputArray[], ifstream& instream)\n";
   
   filenameT = "input1.txt";    
   char *cArrayT = ((char*)filenameT.c_str());
   inStreamT.open(cArrayT);
   iArrayT_size = readfile(iArrayT, inStreamT);
   if (iArrayT_size == 6) {
         cout << "passed\n";
   }
   else {
         cout << "failed\n";
   }

   ///////////////////////////////////////////
   cout << "Case 1.2: Tests to see if invalid file can be passed on(inputArray[], ifstream& instream)\n";
   
   filenameT2 = "input100.txt";
   char *cArrayT2 = ((char*)filenameT2.c_str());
   
   inStreamT2.open(cArrayT2);
     
   iArrayT2_size = (readfile(iArrayT2, inStreamT2));
   assert(iArrayT2_size == 0);
   cout << "passed\n";

//////////////////////////////////////////////
cout << "Case 2.1: Tests to see if known values are sorted correctly sortF((int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[])\n";
string filenameT3 = "input1.txt";    
   char *cArrayT3 = ((char*)filenameT3.c_str());
   inStreamT3.open(cArrayT3);
   iArrayT3_size = readfile(iArrayT3, inStreamT3);
   

   int outputArrayT[iArrayT2_size + iArrayT3_size];

   sortF(iArrayT3, iArrayT3_size, iArrayT, iArrayT_size, outputArrayT);

   int testArray[12] = {4, 4, 13, 13, 14, 14, 17, 17, 23, 23, 89, 89};
   int r = 0;
      for( int k = 0; k < 12; ++k ) {
            //cout << outputArrayT[k] << " " << testArray[k] << endl;
        if( outputArrayT[k] != testArray[k]) {
            r = 1;
        }
    }
    if (!r == 1) {
      cout << "passed\n";
    }
    else {
          cout << "failed\n";
    }
//////////////////////////////////////////////

    cout << "Case 2.2: Tests to see if an empty file can be correctly sorted with a full one ((int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[])\n";
    sortF(iArrayT2, iArrayT2_size, iArrayT3, iArrayT3_size, outputArrayT);
    int testArray2[6] = {4, 13, 14, 17, 23, 89}; 
    int y = 0;
    for( int k = 0; k < 6; ++k ) {
            //cout << outputArrayT[k] << " " << testArray2[k] << endl;
        if( outputArrayT[k] != testArray2[k]) {
            y = 1;
        }
    }
    if (!y == 1) {
      cout << "passed\n";
    }
    else {
          cout << "failed\n";
    }


   ///////////////////////////////////////////

   cout << "*** Welcome to Noah's sorting program ***\n";

   cout << "Enter the first input file name: ";
   cin >> filename1;
   char *cArray1 = ((char*)filename1.c_str());
   inStreamFirst.open(cArray1);
   iArray1_size = readfile(iArray1, inStreamFirst);
   cout << "The list of " << iArray1_size << " numbers in file " << filename1 << endl;
   int t = 0;
   while (t < iArray1_size) {
         cout << iArray1[t] << endl;
         t++;
   } 
   
   cout << "Enter the second input file name: ";
   cin >> filename2;
   char *cArray2 = ((char*)filename2.c_str());
   inStreamSecond.open(cArray2);
   iArray2_size = readfile(iArray2, inStreamSecond);
   cout << "The list of " << iArray2_size << "  numbers in file " << filename2 << endl;
   t = 0;
   while (t < iArray2_size) {
         cout << iArray2[t] << endl;
         t++;
   }

         
   ///////////////////////////////////////////
   
   int outputArray_size = iArray1_size + iArray2_size;
   int outputArray[outputArray_size];
   ///////////////////////////////////////////
   
   sortF(iArray1, iArray1_size, iArray2, iArray2_size, outputArray);
   ///////////////////////////////////////////
   cout << "The sorted list of " << outputArray_size << " is: ";
   t = 0;
   while (t < outputArray_size) {
         cout << outputArray[t] << " ";
         t++;
   }

   cout << "\n";
   cout << "Enter the output file name: ";
   cin >> outputFileName;

   ///////////////////////////////////////////
   
   writefile(outputArray, outputArray_size, outputFileName);
   cout << "Please check the new file - " << outputFileName << " ***\n";
   cout <<"Goodbye\n";   
   return 0;
}
    
//reads instream and populates inputArray and returns size of a
// array filled
int readfile(int inputArray[], ifstream& instream) {
    int index = 0;
    
      bool isEmpty = instream.peek() == EOF;
     
   if (instream.fail() || isEmpty) {
       //cout << "Input file opening failed" << endl;
       instream.close();
       return 0;
    } 
   
   
   instream.clear();  
   //first value
   instream >> inputArray[index];
   //cout << inputArray[index] << endl;
   index++;

    while (instream >> inputArray[index]) {
            //cout << inputArray[index] << endl;
        index++;
}

    instream.clear();  
    instream.close();
        
    sort(inputArray, inputArray + index);
    return (index);
}



int sortF(int inputArray1[], int inputArray1_size, int inputArray2[],int inputArray2_size, int outputArray[]) {
   
   int size = inputArray1_size + inputArray2_size;
   

   if (size == 0) {
       cout << "Not enough numbers to sort" << endl;
        return 0;
   }                   
    
    
   int i, j, k;
      i = 0;
      j = 0;
      k = 0;



      while (i < inputArray1_size && j < inputArray2_size) {
            if (inputArray1[i] <= inputArray2[j]) {
                  outputArray[k] = inputArray1[i];
                  i++;
            } 
            else {
                  outputArray[k] = inputArray2[j];
                  j++;
            }
            k++;
      }
      if (i < inputArray1_size) {
            for (int p = i; p < inputArray1_size; p++) {
                  outputArray[k] = inputArray1[p];
                  k++;
            }

      } 
      else {   
        for (int p = j; p < inputArray2_size; p++) {
                  outputArray[k] = inputArray2[p];
                  k++;
            }
      }

    return 1;
}


int writefile(int outputArray[], int outputArray_size, string outputFileName) {
   ofstream myfile;
  //cout << "Writing" << endl;
  try {
   myfile.open(outputFileName);
  }
  catch(fstream::failure const &ex) {
       cout << "output file opening failed" << endl;
       myfile.close();
       return 0;
    }



   int z = 0;
   //cout << "size of final = " << outputArray_size << endl;
   
   while (z < outputArray_size) {
       //cout << outputArray[z] << endl;
       myfile << outputArray[z] << endl;
       z++;
   }
   myfile.close();
   return 1;
    
}



