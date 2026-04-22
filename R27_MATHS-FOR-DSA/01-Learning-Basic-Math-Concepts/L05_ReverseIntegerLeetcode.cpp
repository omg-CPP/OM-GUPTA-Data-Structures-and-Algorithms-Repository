#include <iostream>
#include <climits>
using namespace std;
// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.

// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

int reverse(int x) {
    int ld;
    long long rev = 0;
    while(x != 0) {
        ld = x % 10;
        rev = (rev * 10) + ld;
        x = x / 10;
    }

    if(rev < INT_MIN || rev > INT_MAX) {
        return 0;
    }
    return rev;
}

int main()
{
    int num;
    cout<<"Enter the number : ";
    cin>>num;
    int ans = reverse(num);
    cout<<ans<<endl;
    return 0;
}

// Enter the number : 123456
// 654321

// Enter the number : 2147483647
// 0

// Enter the number : 214748364 
// 463847412

// Enter the number : -2147483648
// 0

// Enter the number : -214748364 
// -463847412