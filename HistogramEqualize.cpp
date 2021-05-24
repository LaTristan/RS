#include <iostream>
#include <uchar.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

class Graph{
    private:
    vector<vector<int>> data;
    int row;
    int col;
    map<int,int>hashmap;
    public:
    /*Graph(int r,int c){
        this->row=r;
        this->col=c;
    }*/
    void readFile(ifstream ifs){
        string s;
        while(getline(ifs,s)){
            istringstream iss(s);
            int tmp;
            vector<int>t;
            while(iss>>tmp){
                t.push_back(tmp);
            }
            data.push_back(t);
            t.clear();
        }
        row=data.size();
        col=data[0].size();
    }
    void CalcHash(){
        pair<int,int>t;
        for(int i=0;i<data.size();i++){
            for(int j=0;j<data[0].size();j++){
                if(hashmap.find(data[i][j])!=hashmap.end()){
                    hashmap[data[i][j]]++;
                }else{
                    t.first=data[i][j];
                    t.second=1;
                    hashmap.insert(t);
                }
            }
        }
    }
    map<int,int> getHash(){
        return hashmap;
    }
};

int gray[256] = { 0 };
double gray_prob[256] = { 0 };
double gray_distribution[256] = { 0 };
int gray_equal[256] = { 0 };

int grey_sum = 0;

int main()
{
    grey_sum = 18;
    gray[17] = 1;
    gray[19] = 4;
    gray[20] = 3;
    gray[21] = 5;
    gray[24] = 1;
    gray[28] = 1;
    gray[30] = 1;
    gray[31] = 1;
    gray[35] = 1;
    gray_distribution[0] = gray[0];
    for (int i = 0; i < 256; i++) {
        gray_prob[i] = (double)gray[i] / grey_sum;
    }
    for (int i = 1; i < 256; i++) {
        gray_distribution[i] = gray_distribution[i - 1] + gray_prob[i];
    }
    for (int i = 0; i < 256; i++)
    {
        gray_equal[i] = 255 * gray_distribution[i] + 0.5;
    }
    cout << 17 << "->" << gray_equal[17] << endl;
    cout << 19 << "->" << gray_equal[19] << endl;
    cout << 20 << "->" << gray_equal[20] << endl;
    cout << 21 << "->" << gray_equal[21] << endl;
    cout << 24 << "->" << gray_equal[24] << endl;
    cout << 28 << "->" << gray_equal[28] << endl;
    cout << 30 << "->" << gray_equal[30] << endl;
    cout << 31 << "->" << gray_equal[31] << endl;
    cout << 35 << "->" << gray_equal[35] << endl;
}
