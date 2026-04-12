// Swapping Two Numbers Using Bit Manipulation

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <string.h>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <utility>
#include <climits>
#include <cfloat>
#include <cmath>
#include <math.h>
#include <numeric>
#include <algorithm>
using namespace std;

// Approach 2: using reference-alias :: shallow copy
// Note: you are not creating a new variable.
// You are creating an alias (another name) for an existing variable.
// 👉 Think of it like:
// a is just another label attached to the same memory location.
// 🔹 One-line intuition
// int& a = x; means "a IS x", not "a points to x"
void swapNumbersI(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Approach 3: using pointers via reference
void swapNumbersII(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Approach 4: using bit-manipulation (XOR)
// a ^ a = 0
// a ^ 0 = a
void swapNumbersIII(int& a, int& b) {
    a = a ^ b; 
    b = a ^ b; // b = (a ^ b) ^ b = a ^ 0 = a
    a = a ^ b; // a = (a ^ b) ^ a = b ^ 0 = b
}

int main()
{
    int a = 2;
    int b = 3;
    // Approach 1: using built-in swap function
    cout<<a<<" "<<b<<endl; // 2 3
    swap(a,b);
    cout<<a<<" "<<b<<endl; // 3 2

    int x = 4;
    int y = 5;
    cout<<x<<" "<<y<<endl; // 4 5
    swapNumbersI(x,y);
    cout<<x<<" "<<y<<endl; // 4 5

    int p = 7;
    int q = 8;
    cout<<p<<" "<<q<<endl; // 7 8
    swapNumbersII(&p,&q);
    cout<<p<<" "<<q<<endl; // 8 7

    int m = 12;
    int n = 15;
    cout<<m<<" "<<n<<endl; // 12 15
    swapNumbersIII(m,n);
    cout<<m<<" "<<n<<endl; // 15 12
    return 0;
}