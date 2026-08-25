// convert.cpp -- convert stone to pound

#include <iostream>
int stoneToLb(int);
int main(){

    using namespace std;
    int stone;
    cout << "Enter the weight in stone: ";
    cin >> stone;
    int pounds = stoneToLb(stone);
    cout << stone << " Stone = ";
    cout << pounds << " pounds." << endl;
    return 0;
}

int stoneToLb(int sts){
    
    return 14 * sts;
}