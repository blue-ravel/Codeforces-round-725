#include <iostream>

using std::cin;
using std::endl;
using std::cout;

int input2Darray(int* a, const int & n){
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    return sum;   
}

int main() {
    int t, n, val, sum, ans;
    int a[200000]; 
    cin >> t;
    while(t-->0) {
        ans = 0;
        cin >> n;
        sum = input2Darray(a, n);
        if(sum%n != 0) { // if it is not possible to distribute equal candies to all
            cout << "-1" << endl;
            continue;
        }
        val = sum/n; // The value which each friend will have
        for(int i=0;i<n;i++)
            if(a[i] > val) // Anyone having more than avg will be collected and distributed
                ans++;
        
        cout << ans << endl;
    }   
}