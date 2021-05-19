#ifndef _FACTORY_H_
#define _FACTORY_H_

#include "Band.h"
#include <fstream>
using namespace std;

class Factory{
    vector<Band>bands;
    int bandNum=0;
public:
    void printInfo(){
        cout<<"****Data Info****"<<endl;
        cout<<"Bands Amount:"<<bandNum<<endl;
        cout<<"Data Size:"<<bands.size();
    }
    /*Get BIL format data. Input file name or path/name*/
    void convertBIL(string outputPath){
        int n=bands.size();
        ofstream ofs(outputPath+".txt");
        for(int i=0;i<n;i++){
            
        }
    }
};

#endif