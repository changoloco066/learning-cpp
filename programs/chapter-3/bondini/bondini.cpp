// bondino.cpp -- using escape sequences

#include <iostream>

int main(){
     using namespace std;
     cout << "\aOperation \"Hyperhype\" is now activated!\n";
     cout << "Enter your agent code:_______\b\b\b\b\b\b\b\b";
     long code;
     cin >> code;
     cout << "\aYou entered " << code << "....\n";
     cout << "\aCode verified! Proceed with plan Z3!\n";
     return 0; 
}
