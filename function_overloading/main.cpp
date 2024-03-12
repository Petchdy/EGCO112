// this file is presenting some commands and features in C++ and what function overloading is

#include<iostream>
#include<stdlib.h>
using namespace std;

// Function overloading is a feature to make it possible to create function with the same name but different parameters
// in this case there are 2 void func with different parameter this is called function overloading
// the example could be hard to read and hard to understand cause they have the same name
void func(int n, char * arr[]);
void func(char * arr);

string func(string);

// main argument is still usable
int main(int argc, char * argv[]) {

    // there is a string (type of variable in C++)
    string str;

    // cout is refer to character output
    cout << "argc = " << argc << endl;

    cout << "Print from loop + function\n=>";
    for (int i = 1; i < argc; i++) {
        func(argv[i]);
    }
    cout << "\n";
    
    func(argc, argv);

    cout << "insert 1 input: ";
    // cin is refer to character input
    cin >> str;
    cout << func(str) << endl;

    return 0;
}

void func(int n, char * arr[]) {

    cout << "Print from void func\n=> ";

    for (int i = 1; i < n; i++)
    {
        // atoi is still usable
        cout << atoi(arr[i]) << " ";
    }
    cout << endl;

}

void func(char * arr) {
    cout << arr << " ";
}

string func(string str) {
    // in C++ it is possible to add a string using '+'
    return "Name: "+str;
}