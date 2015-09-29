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

void assert (int** m1, int** m2, int** ans, int n, int m, int k)
{
	bool check = true;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			if (multiply(m1, m2, n, m, k)[i][j] != ans[i][j]) check = false;
	if (check)
		cout << "OK" << endl;
	else
		cout << "FAIL" << endl;
}

int main()
{
	int** a; 
	a = new int*[2];
	a[0] = new int[3];
	a[0][0] = 2;
	a[0][1] = -1;
	a[0][2] = 0;
	a[1] = new int[3];
	a[1][0] = 1;
	a[1][1] = 0;
	a[1][2] = 1;
	int** b;
	b = new int*[3];
	b[0] = new int[2];
	b[0][0] = 1;
    b[0][1] = 3;
	b[1] = new int[2];
    b[1][0] = -2;
	b[1][1] = -3;
	b[2] = new int[2];
	b[2][0] = 0;
	b[2][1] = 2;
	int** ans1;
	ans1 = new int*[3];
	ans1[0] = new int[3];
	ans1[0][0] = 5;
    ans1[0][1] = -1;
	ans1[0][2] = 3;
	ans1[1] = new int[3];
    ans1[1][0] = -7;
	ans1[1][1] = 2;
	ans1[1][2] = -3;
	ans1[2] = new int[3];
	ans1[2][0] = 2;
	ans1[2][1] = 0;
	ans1[2][2] = 2;
	int** ans2;
	ans2 = new int*[3];
	ans2[0] = new int[2];
	ans2[0][0] = 4;
    ans2[0][1] = 9;
	ans2[1] = new int[2];
    ans2[1][0] = 1;
	ans2[1][1] = 5;

	assert(b, a, ans1, 3, 3, 2);
	assert(a, b, ans2, 2, 2, 3);

	return 0;
}
