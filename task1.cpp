#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int** multiply(int** a, int** b, int n, int m, int k){ // a[n][k], b[k][m]
    int** c=new int*[n];
    for (int i = 0; i < n; ++i){
        c[i]=new int[m];
        for (int j = 0; j < m; ++j){
            c[i][j] = 0;
            for (int l = 0; l < k; ++l)
                c[i][j] += a[i][l] * b[l][j];
        }
    }
    return c;
}

int main(){
}
