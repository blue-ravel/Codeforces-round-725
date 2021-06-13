#include <iostream>
#include <cmath>
 
using std::cin;
using std::endl;
using std::cout;
 
int gcd(const int a, const int b)
{
    if (a == 0)
       return b;
    if (b == 0)
       return a;
    if (a == b)
        return a;
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}
int primeFactors(int n)
{
    int c = 0;
    while (n % 2 == 0){
        c++;
        n = n/2;
    }
    for (int i = 3; i <= std::sqrt(n); i = i + 2){
        while (n % i == 0){
            c++;
            n = n/i;
        }
    }
    if (n > 2)
        c++;
    return c;
}
int min(const int & a, const int & b){
    return (a<b)?a:b;
}
 
int main() {
    int t, a, b, k;
    cin >> t;
    while(t-->0) {
        cin >> a >> b >> k;
        if(primeFactors(a)+primeFactors(b) < k || (a == b && k == 1))
            cout << "NO" << endl;
        else if(k > 1 || (k == 1 && gcd(a, b) == min(a, b)))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }   
}