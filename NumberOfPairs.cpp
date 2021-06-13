#include <iostream>
#include <algorithm>

using std::cin;
using std::endl;
using std::cout;
using std::sort;

void input2Darray(int* a, const int & n){
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);    
}
int binSearch(int* a, int l, int e, int v, std::string cnd){
    if(l >= e) {
        return l;
    }
    int m = (l+e)/2;
    if(a[m] < v)
        return binSearch(a, m+1, e, v, cnd);
    else if(a[m] > v)
        return binSearch(a, l, m, v, cnd);
    else {
        if(cnd == "ul")
            return binSearch(a, m+1, e, v, cnd);
        else if(cnd == "ll")
            return binSearch(a, l, m, v, cnd);
    }
}

int main() {
    int t, n, val;
    long long int ans; // CORRECTED: was using int before caused overflow
    int l, r;
    int a[200000]; 
    cin >> t;
    while(t-->0) {
        ans = 0;
        cin >> n >> l >> r;
        input2Darray(a, n);
        sort(a, a+n);

        for(int i=0;i<n-1;i++){
            val = binSearch(a, i+1, n, l-a[i], "ll"); //ll -> lower limt to select the lower value when v = a[m]
            ans += binSearch(a, val, n, r-a[i], "ul") - val;//ul -> upper limt to select the upper value when v = a[m]
        }
        cout << ans << endl;
    }   
}