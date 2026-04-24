// Matrix Exponentiation
//This is an example code for Matrix Exponentiaon of Degree-2 recurrence relation. For example : F(n) = F(n-1) + F(n-2)

// f(n) = f(n-1) + f(n-2)
// [f(2) f(1)] (2*1)  =  T (2*2)  *  [f(1) f(0)] (2*1)
// [f(n) f(n-1)] (2*1)  =  T^(n-1) (2*2)  *  [f(1) f(0)] (2*1)

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

const int M = 1e9+7;
typedef vector<vector<long long>> Matrix;

// O(1)
// Function to multiply two matrices
// A: (m1*n1), B: (m2*n2)
Matrix matrixMultiplication(Matrix& A, Matrix& B) {
    int m1 = A.size();
    int n1 = A[0].size();
    int m2 = B.size();
    int n2 = B[0].size();
    Matrix result(m1,vector<long long>(n2,0));
    if(n1 == m2) {
        for(int i = 0 ; i < m1 ; i++) {
            for(int j = 0 ; j < n2 ; j++) {
                // iterating over summing elements after multiply for each cell
                for(int k = 0 ; k < n1 ; k++) {
                    result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % M;
                }
            }
        }
    }
    return result;
}

//T.C : O(log(n))
//S.C : O(1)
// Function to raise matrix base to the power exponent (Just like Binary exponentiation)
Matrix matrixExponentiation(Matrix& base, int exponent) {
    if(exponent == 0) {
        Matrix identity(2,vector<long long>(2,0));
        //making an Identity matrix
        for(int i = 0 ; i < 2 ; i++) {
            identity[i][i] = 1;
        }
        return identity;
    }

    Matrix half = matrixExponentiation(base,exponent/2);
    Matrix result = matrixMultiplication(half,half);

    if(exponent & 1) {
        result = matrixMultiplication(result,base);
    }
    return result;
}

// Fibonacci Series
// 0 1 2 3 4 5 6 7   8  9 10 11
// 0 1 1 2 3 5 8 13 21 34 55 89
int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;

    if(n == 0) {
        cout<<"Fibonacci("<<n<<") = 0"<<endl;
        return 0;
    }

    // a = 1, b = 1, c = 1, d = 0
    Matrix T = {{1, 1}, {1, 0}};
    Matrix mat = {{1}, {0}}; // Base case matrix: F(1) = 1, F(0) = 0

    // reqT = T^n-1
    Matrix reqT = matrixExponentiation(T,n-1);
    Matrix result = matrixMultiplication(reqT,mat);

    cout<<"Fibonacci("<<n<<") = "<<result[0][0]<<endl;
    return 0;
}

// Enter n: 0
// Fibonacci(0) = 0

// Enter n: 1
// Fibonacci(1) = 1

// Enter n: 2
// Fibonacci(2) = 1

// Enter n: 3
// Fibonacci(3) = 2

// Enter n: 4
// Fibonacci(4) = 3

// Enter n: 5
// Fibonacci(5) = 5

// Enter n: 8
// Fibonacci(8) = 21

// Enter n: 10
// Fibonacci(10) = 55

// Enter n: 11
// Fibonacci(11) = 89