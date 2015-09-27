#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

inline void solve(int n, int a[], int m, int b[], int &n_sum, int sum[], int &n_pr, int pr[]){

int mem_n = n;
	if (n!=m)
		n_sum = max(n, m);
	else
	{
		int mem_n = n;
		while (a[n-1]+b[n-1]==0) n--;
		n_sum = n;
		n = mem_n;
	}
	for (int i=0;i < min (n, m);i++)
		sum[i] = a[i] + b[i];
	if (n!=m)
		if (n < m)
			for (int i=n;i < m;i++) sum[i] = b[i];
		else
			for (int i=m;i < n;i++) sum[i] = a[i];
	if (n_sum = 0)
	{
		n_sum = 1;
		sum[0] = 0;
	}

	n_pr = n + m - 1;
	for (int i=0;i < n_pr;i++)
	{
		pr[i] = 0;
		if (i>=n) a[i]=0;
		if (i>=m) b[i]=0;
	}
	for (int i=0;i < n_pr;i++)
		for (int j=0;j <= i;j++)
			pr[i] += a[j]*b[i-j];


}

inline void assert(int n, int a[], int m, int b[], int sum[], int pr[]){
    int sum_[111];
    int pr_[111];
    int sz_sum, sz_pr;
    solve(n, a, m, b, sz_sum, sum_, sz_pr, pr_);
    if (sz_sum != max(n, m) || sz_pr != n + m - 1){
        puts("WA");
        return;
    }
    bool ok = true;
    for (int i = 0; i < sz_sum; ++i)
        ok &= (sum[i] == sum_[i]);
    for (int i = 0; i < sz_pr; ++i)
        ok &= (pr[i] == pr_[i]);
    if (ok)
        puts("OK");
    else
        puts("WA");
}

int main() {
	int a1[2] = {3, 2}, b1[3] = {0, 4, 1};
	int sum1[3] = {3, 6, 1}, pr1[4] = {0, 12, 11, 2};
	assert(2, a1, 3, b1, sum1, pr1);
    int a2[4] = {7, 0, -2, 3}, b2[4] = {2, -1, 0, -1};
	int sum2[4] = {9, -1, -2, 2}, pr2[7] = {14, -7, -4, 1, -3, 2, -3};
	assert(4, a2, 4, b2, sum2, pr2);
	return 0;
}
