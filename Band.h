#ifndef _BAND_H_
#define _BAND_H_

#include <vector>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Band{
private:
    vector<vector<int>> data;
    int col=0;
    int row=0;
public:
/*Input data must be like "12 34 56 78"*/
    void importDataFromString(string import){
        vector<int>tmp;
        istringstream iss(import);
        int r;
        while(iss>>r){
            tmp.push_back(r);
        }
        data.push_back(tmp);
        tmp.clear();
        row=data.size();
        col=data[0].size();
    }
    /*Print information about this band*/
    void printInfo(){
        cout<<"********Info********"<<endl;
        cout<<"Row:\t"<<row<<endl;
        cout<<"Col:\t"<<col<<endl;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                cout<<data[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
    string getLineData(int n){
        if(n>=row)return "Require out of bound.";
        string res;
        vector<int> tmp=data[n];
        for(vector<int>::iterator it=tmp.begin();it!=tmp.end();it++){
            res+=(" "+to_string(*it));
        }
        return res;
    }
};

#endif