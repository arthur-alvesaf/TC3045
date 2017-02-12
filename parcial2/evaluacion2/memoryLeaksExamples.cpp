#include<iostream>
#include<cstring>
using namespace std;

int main(int argc, char**argv)
{
    //no memory leak
    char* string = new char[30];
    delete [] string;
    
    // invalid write
    char* sub = new char[30];
    strcpy(sub, argv[1]); //if argv[1] is bigger than 30, result is invalid write
    delete [] sub;
    
    //memory leak
    sub = new char[40];
    delete [] sub;
    
    sub = new char[50];
    delete [] sub;
    
    // //memory leak
    char* three = new char[10];
    char* four = new char[10];
    strcpy(three, "memory leak");
    // four = three; // bad copy. pointer of three is copied to four and previous pointer is lost.
    strcpy(four, three); // correct copy
    delete [] three;
    delete [] four;
    
    //
    
}