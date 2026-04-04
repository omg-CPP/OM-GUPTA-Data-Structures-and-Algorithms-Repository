
// code -> 1 sec -> max ~10^8 operations can run
// if no of operations > 10^8 :: Time Limit Exceeded (TLE)

// Constraints Analysis:
// n > 10^8   ::  O(logn), O(1)
// n <= 10^8  ::  O(n), O(logn), O(1)
// n <= 10^6  ::  O(nlogn), O(n), O(logn), O(1)ṇ
// n <= 10^4  ::  O(n^2), O(nlogn), O(n), O(logn), O(1)
// n <= 500   ::  O(n^3), O(n^2), O(nlogn), O(n), O(logn), O(1)
// n <= 25    ::  O(2^n), O(n^6), O(n^4), O(n^3), O(n^2), O(nlogn), O(n), O(logn), O(1)
// n <= 12    ::  O(n!), O(3^n), O(n*2^n), O(2^n), O(n^6), O(n^4), O(n^3), O(n^2), O(nlogn), O(n), O(logn), O(1)

