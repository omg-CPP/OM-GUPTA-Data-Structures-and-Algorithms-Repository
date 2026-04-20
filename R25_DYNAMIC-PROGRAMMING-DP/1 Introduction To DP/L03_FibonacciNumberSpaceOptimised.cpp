// Leetcode : 509

#include <iostream>
#include <vector>
using namespace std;

// Space Optimised Technique
// T.C. = O(N)
// S.C. = O(1)
int fib(int n) {
    if(n <= 1) {
        return n;
    }
    int prev2 = 0;
    int prev1 = 1;
    for(int i = 2 ; i <= n ; i++) {
        int curr = prev2 + prev1;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;
    cout<<fib(n)<<endl;
    return 0;
}