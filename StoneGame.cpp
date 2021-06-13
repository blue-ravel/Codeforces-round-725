#include <iostream>

using std::cin;
using std::endl;
using std::cout;
using std::string;

void input2Darray(int* a, const int n){
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
}
void getPosOfMinMax(int* a, int n, int & minp, int & maxp) {
    int max = INT_MIN;
    int min = INT_MAX;
    for(int i=0;i<n;i++) {
        if(a[i] > max) {
            max = a[i];
            maxp = i;
        }
        if(a[i] < min) {
            min = a[i];
            minp = i;
        }
    }
}
int min(const int & a, const int & b){
    return (a<b)?a:b;
}
int max(const int & a, const int & b){
    return (a>b)?a:b;
}

int main() {
    int t, n, ans;
    int minp, maxp;
    int a[100]; 
    cin >> t;
    while(t-->0) {
        cin >> n;
        input2Darray(a, n);
        getPosOfMinMax(a, n, minp, maxp);
        cout << min(min(max(minp+1, maxp+1), max(n-minp, n-maxp)), min(minp+1, n-minp)+min(maxp+1, n-maxp)) << endl;
    }   
}