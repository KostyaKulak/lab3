#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

void solve(int a[], int n, int res[3]){
    sort(a, a + n);
    if (1ll * a[0] * a[1] * a[n-1] >= 1ll * a[n-3] * a[n-2] * a[n-1])
        res[0] = a[0], res[1] = a[1], res[2] = a[n-1];
    else
        res[0] = a[n-3], res[1] = a[n-2], res[2] = a[n-1];
}

int main(){
}
