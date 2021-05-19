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
    ifstream band2("band2.txt");
    if(!band2)return -1;
    ifstream band3("band3.txt");
    if(!band3)return -1;
    vector<int>tmp;
    vector<vector<int>>b1;
    vector<vector<int>>b2;
    vector<vector<int>>b3;
    string s;
    int t;
    while(getline(band1,s)){
        istringstream iss(s);
        while(iss>>t){
            tmp.push_back(t);
        }
        b1.push_back(tmp);
        tmp.clear();
    }
    while(getline(band2,s)){
        istringstream iss(s);
        while(iss>>t){
            tmp.push_back(t);
        }
        b2.push_back(tmp);
        tmp.clear();
    }
    while(getline(band3,s)){
        istringstream iss(s);
        while(iss>>t){
            tmp.push_back(t);
        }
        b3.push_back(tmp);
        tmp.clear();
    }
    band1.close();
    band2.close();
    band3.close();
    ofstream BIL("bil.txt");
    //BIL
    for(int i=0;i<b1.size();i++){
        for(int j=0;j<3;j++){
            BIL<<b1[i][j]<<"\t";
        }
        BIL<<endl;
        for(int j=0;j<3;j++){
            BIL<<b2[i][j]<<"\t";
        }
        BIL<<endl;
        for(int j=0;j<3;j++){
            BIL<<b3[i][j]<<"\t";
        }
        BIL<<endl;
    }
    return 0;
}