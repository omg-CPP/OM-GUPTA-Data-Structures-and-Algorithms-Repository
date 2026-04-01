// Leetcode : 9 (EASY)

// Given an integer x, return true if x is a palindrome, and false otherwise.

#include <iostream>
using namespace std;

// digits=⌊log10​(n)⌋+1
// T.C. = O(log10(digits)) = O(logn)
// S.C. = O(1)
bool isPalindrome(int x) {
    if(x < 0) return false;
    long long rev = 0;
    int temp = x;
    while(temp > 0) {
        rev = (rev*10) + (temp % 10);
        temp /= 10;
    }
    return rev == x;
}


int main()
{
    int n;
    cout<<"Enter n : ";
    cin>>n;
    int temp = n;
    int ld;
    int rev = 0;
    while(temp != 0) {
        ld = temp % 10;
        rev = (rev * 10) + ld;
        temp = temp / 10;
    }
    if(rev == n) {
        cout<<"Palindrome Number"<<endl;
    }
    else {
        cout<<"Not a Palindrome Number"<<endl;
    }

    cout<<isPalindrome(n)<<endl; // 1
    return 0;
}

// Enter n : 12421
// Palindrome Number

// Enter n : 5689
// Not a Palindrome Number