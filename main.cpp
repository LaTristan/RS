#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ifstream band1("band1.txt");
    if(!band1)return -1;
    string s;
    while(getline(band1,s)){
        cout<<s<<endl;
    }
    band1.close();
    return 0;
}