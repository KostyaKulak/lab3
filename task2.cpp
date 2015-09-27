#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

void solve(int a[], int n, int res[3])
{
    sort(a, a + n);
    if (1ll * a[0] * a[1] * a[n-1] >= 1ll * a[n-3] * a[n-2] * a[n-1])
        res[0] = a[0], res[1] = a[1], res[2] = a[n-1];
    else
        res[0] = a[n-3], res[1] = a[n-2], res[2] = a[n-1];
}

void assert(int a[], int n, int reqAns[3])
{
	int codeAns[3];
	solve(a, n, codeAns);
	bool check = true;
	for (int i=0;i<3;i++)
		if (codeAns[i]!=reqAns[i]) check = false;
	if (check) 
		cout << "OK" << endl;
	else 
		cout << "FAIL" << endl;
}

int main()
{
	int test1[5] = {0, -2, -3, 14, 10}; 
	int ans1[3] = {-3, -2, 14};
	int test2[10] = {-24, -10, 5, 0, 25, 6, 3, 12, 20, 10}; 
	int ans2[3] = {-24, -10, 25};
	int test3[7] = {1, 0, 2, 3, 12, 4, 0}; 
	int ans3[3] = {3, 4, 12};
	int test4[6] = {-3, 0, 0, 0, 100};
	int ans4[3] = {-3, 0, 100};
	
	assert(test1, 5, ans1);
	assert(test2, 10, ans2);
	assert(test3, 7, ans3);
	assert(test4, 6, ans4);
	return 0;

}





