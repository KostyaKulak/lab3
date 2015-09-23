#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void multiply(vector <vector <int> > a, vector <vector <int> > b, vector <vector <int> > &c){
    c.resize(a.size());
    for (int i = 0; i < a.size(); ++i){
        c[i].resize(b[0].size());
        for (int j = 0; j < b[0].size(); ++j){
            c[i][j] = 0;
            for (int l = 0; l < b.size(); ++l)
                c[i][j] += a[i][l] * b[l][j];
        }
    }
}

int main(){
}
