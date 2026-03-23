// Complete C++ STL in One Shot for Tech Placements

// STL -> Standard Template Library

// #include <bits/stdc++.h>
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
#include <cmath>
#include <math.h>
#include <numeric>
#include <algorithm>

using namespace std;

typedef long l;
typedef long long ll;
typedef unsigned long long ull;

void print() {
    cout<<"Raj"<<endl;
}

int sum(int a, int b) {
    return a+b;
}

// ***************************************

void explainPair() {

    pair<int,int> p1 = {1,3};
    cout<<p1.first<<" "<<p1.second<<endl; // 1 3

    pair<int,pair<int,int>> p2 = {1,{3,4}};
    cout<<p2.first<<" "<<p2.second.first<<" "<<p2.second.second<<endl; // 1 3 4

    pair<int,int> arr[] = {{1,2},{2,5},{5,1}};

    cout<<arr[0].first<<" "<<arr[0].second<<endl; // 1 2
    cout<<arr[1].first<<" "<<arr[1].second<<endl; // 2 5
    cout<<arr[2].first<<" "<<arr[2].second<<endl; // 5 1

}

// ***************************************

// Vectors are basically containers
void explainVector() {

    vector<int> v1; // empty container

    v1.push_back(1);
    v1.emplace_back(2); // relatively faster than push_back

    vector<pair<int,int>> vec;

    vec.push_back({1,2});
    vec.emplace_back(1,2);  // automatically understands

    vector<int> v2(5,100); // size 5 with all 100

    vector<int> v3(5); // size 5 with all 0

    vector<int> v4(5,20); // size 5 with all 20
    vector<int> v5(v4);   // copy of v4

    vector<int> v = {1,2,3,4};

    cout<<v[0]<<" "<<v[1]<<" "<<v.at(2)<<" "<<v.at(3)<<endl; // 1 2 3 4

    cout<<v.back()<<endl; // 4

    // iterator points to memory where the element is lying
    vector<int>::iterator it = v.begin();
    cout<<*(it)<<endl; // 1
    it++;
    cout<<*(it)<<endl; // 2
    it = it + 2;
    cout<<*(it)<<endl; // 4

    // end points to memory location that is right after the last element
    // points to after 4
    vector<int>::iterator it1 = v.end();
    cout<<*(it1-1)<<endl; // 4

    for(int i = 0 ; i < v.size() ; i++) {
        cout<<v[i]<<" ";
    }
    // 1 2 3 4
    cout<<endl;

    // forward
    for(vector<int>::iterator it = v.begin() ; it != v.end() ; it++) {
        cout<<*(it)<<" ";
    }
    // 1 2 3 4
    cout<<endl;

    // auto automatically understands the datatype
    for(auto it = v.begin() ; it != v.end() ; it++) {
        cout<<*(it)<<" ";
    }
    // 1 2 3 4
    cout<<endl;

    // reverse iterator -> backward
    for(vector<int>::reverse_iterator itr = v.rbegin() ; itr != v.rend() ; itr++) {
        cout<<*(itr)<<" ";
    }
    // 4 3 2 1
    cout<<endl;

    // auto automatically understands the datatype
    for(auto itr = v.rbegin() ; itr != v.rend() ; itr++) {
        cout<<*(itr)<<" ";
    }
    // 4 3 2 1
    cout<<endl;

    // for each loop
    for(auto it : v) {
        cout<<it<<" ";
    }
    // 1 2 3 4
    cout<<endl;

    v.push_back(5);
    v.push_back(6);

    
    for(auto it : v) {
        cout<<it<<" ";
    }
    // 1 2 3 4 5 6
    cout<<endl;

    // erase function -> O(N)
    v.erase(v.begin()+1);
    for(auto it : v) {
        cout<<it<<" ";
    }
    // 1 3 4 5 6
    cout<<endl;

    v.erase(v.begin()+1,v.begin()+3);
    for(auto it : v) {
        cout<<it<<" ";
    }
    // 1 5 6
    cout<<endl;
    

    // insert function -> O(N)
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    for(auto it : v) {
        cout<<it<<" ";
    }
    // 1 5 6 7 8 9
    cout<<endl;

    v.insert(v.begin(),10);
    for(auto it : v) {
        cout<<it<<" ";
    }
    // 10 1 5 6 7 8 9
    cout<<endl;

    v.insert(v.begin()+2,20);
    for(auto it : v) {
        cout<<it<<" ";
    }
    // 10 1 20 5 6 7 8 9
    cout<<endl;

    v.insert(v.begin()+1,2,3);
    for(auto it : v) {
        cout<<it<<" ";
    }
    // 10 3 3 1 20 5 6 7 8 9
    cout<<endl;

    vector<int> c(2,100);
    v.insert(v.begin(),c.begin(),c.end());
    for(auto it : v) {
        cout<<it<<" ";
    }
    // 100 100 10 3 3 1 20 5 6 7 8 9
    cout<<endl;

    cout<<v.size()<<endl; // 12

    v.pop_back();
    for(auto it : v) {
        cout<<it<<" ";
    }
    // 100 100 10 3 3 1 20 5 6 7 8
    cout<<endl;

    // Iterators -> v.begin() and v.end()
    cout<<*(v.begin())<<endl; // 100
    cout<<*(v.end()-1)<<endl; // 8

    vector<int> a = {1,2};
    vector<int> b = {3,4};
    a.swap(b);
    for(auto it : a) {
        cout<<it<<" ";
    }
    // 3 4
    cout<<endl;
    for(auto it : b) {
        cout<<it<<" ";
    }
    // 1 2
    cout<<endl;

    cout<<v.empty()<<endl; // 0

    v.clear(); // erases the entire vector
    for(auto it : v) {
        cout<<it<<" ";
    }
    // {}
    cout<<endl;
    cout<<v.empty()<<endl; // 1

    cout<<v.size()<<endl; // 0
    cout<<v.capacity()<<endl; // 16

}

// just like doubly linked list
void explainList() {

    list<int> ls;
    ls.push_back(2);
    ls.emplace_back(4);
    for(int it : ls) {
        cout<<it<<" ";
    }
    // 2 4
    cout<<endl;

    ls.push_front(1);
    ls.push_back(5);

    for(int it : ls) {
        cout<<it<<" ";
    }
    // 1 2 4 5
    cout<<endl;

}

// deque is implemented as dynamic arrays
void explainDeque() {

    deque<int> dq;
    dq.push_back(1);
    dq.emplace_back(2);
    dq.push_front(4);
    dq.emplace_front(3);

    for(int d : dq) {
        cout<<d<<" ";
    }
    // 3 4 1 2
    cout<<endl;

    cout<<dq[2]<<endl; // 1

    dq.pop_back();
    dq.pop_front();
    for(int d : dq) {
        cout<<d<<" ";
    }
    // 4 1
    cout<<endl;

    cout<<dq.back()<<endl; // 1
    cout<<dq.front()<<endl; // 4

}

// Last in First Out (LIFO)
// top -> O(1)
// push / pop -> O(1)
void explainStack() {

    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    // top -> {4,3,2,1} <- bottom
    st.emplace(5);
    // top -> {5,4,3,2,1} <- bottom

    st.pop();
    // top -> {4,3,2,1} <- bottom

    cout<<st.size()<<endl; // 4
    cout<<st.top()<<endl; // 4
    cout<<st.empty()<<endl; // 0

    stack<int> s;
    s.swap(st);
    cout<<s.size()<<" "<<st.size()<<endl; // 4 0

}

// First in First Out (FIFO)
// top -> O(1)
// push / pop -> O(1)
void explainQueue() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.emplace(4);
    // (dequeue) front -> {1,2,3,4} <- rear (enqueue)
    cout<<q.back()<<endl; // 4
    cout<<q.front()<<endl; // 1

    q.pop();
    // (dequeue) front -> {2,3,4} <- rear (enqueue)
    cout<<q.front()<<endl; // 2

    cout<<q.size()<<endl; // 3
}


// top -> O(1)
// push / pop -> O(logN) -> sorting
void explainPQ() {
    
    priority_queue<int> pq; // by default max-heap
    pq.push(1);
    pq.push(5);
    pq.push(3);
    pq.push(18);

    cout<<pq.size()<<endl; // 4
    cout<<pq.empty()<<endl; // 0

    while(!pq.empty()) {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    // 18 5 3 1 -> sorted order
    cout<<endl;

    //            type  container   functor
    priority_queue<int,vector<int>,greater<int>> minH; // min-heap
    minH.push(1);
    minH.push(5);
    minH.push(3);
    minH.push(18);

    while(!minH.empty()) {
        cout<<minH.top()<<" ";
        minH.pop();
    }
    // 1 3 5 18 -> sorted order
    cout<<endl;

}


// Map is used to store key-value pair, key is always unique
void explainMap() {
    
    // map are implemented by self balancing trees
    // map -> insert,erase,count -> O(logN)

    map<string,int> mp;
    mp["tv"] = 100;
    mp["laptop"] = 500;
    mp["headphones"] = 50;

    for(auto p : mp) {
        cout<<p.first<<" -> "<<p.second<<endl;
    }
    // lexographically ascending sorted order 

    // headphones -> 50
    // laptop -> 500
    // tv -> 100

    mp.insert({"tablet",200});
    mp.insert({"i-phone",50000});

    for(auto p : mp) {
        cout<<p.first<<" -> "<<p.second<<endl;
    }
    // lexographically ascending sorted order 

    // headphones -> 50
    // i-phone -> 50000
    // laptop -> 500
    // tablet -> 200
    // tv -> 100


    cout<<"count : "<<mp.count("laptop")<<endl; // count : 1
    cout<<"value : "<<mp["laptop"]<<endl; // value : 500

    mp.erase("tv");
    for(auto p : mp) {
        cout<<p.first<<" -> "<<p.second<<endl;
    }
    // headphones -> 50
    // i-phone -> 50000
    // laptop -> 500
    // tablet -> 200

    if(mp.find("i-phone") != mp.end()) {
        cout<<"i-phone found"<<endl;
    }
    else {
        cout<<"i-phone does not found"<<endl;
    }
    // i-phone found

    cout<<mp.size()<<endl; // 4
    cout<<mp.empty()<<endl; // 0


    // multi-map

    multimap<string,int> M;
    M.insert({"tv",100});
    M.insert({"tablet",200});
    M.insert({"i-phone",50000});
    M.insert({"tv",100});
    M.insert({"tv",200});

    for(auto p : M) {
        cout<<p.first<<" -> "<<p.second<<endl;
    }

    // i-phone -> 50000
    // tablet -> 200
    // tv -> 100
    // tv -> 100
    // tv -> 200

    // deletes only single instance
    M.erase(M.find("tv"));

    for(auto p : M) {
        cout<<p.first<<" -> "<<p.second<<endl;
    }

    // i-phone -> 50000
    // tablet -> 200
    // tv -> 100
    // tv -> 200


    // unordered-map -> insert,erase,count -> O(1)
    unordered_map<string,int> ump;
    ump.insert({"tv",100});
    ump.insert({"fridge",200});
    ump.insert({"phone",300});
    ump.insert({"ro-uv",400});

    for(auto p : ump) {
        cout<<p.first<<" -> "<<p.second<<endl;
    }
    // random order

    // ro-uv -> 400
    // fridge -> 200
    // phone -> 300
    // tv -> 100

}


void explainSet() {

    // set -> insert,erase,count,find -> O(logN)
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);

    s.insert(1);
    s.insert(2);
    s.insert(3);

    cout<<s.size()<<endl; // 5

    for(auto val : s) {
        cout<<val<<" ";
    }
    // 1 2 3 4 5 -> duplicates are removed and sorted order
    cout<<endl;

    s.erase(3);
    for(auto val : s) {
        cout<<val<<" ";
    }
    // 1 2 4 5
    cout<<endl;

    // lower-bound -> if key is present than key, otherwise next greater than key
    cout<<*(s.lower_bound(4))<<endl; // 4
    cout<<*(s.lower_bound(3))<<endl; // 4
    cout<<*(s.lower_bound(6))<<endl; // 0

    // upper-bound -> value must be greater than key
    cout<<*(s.upper_bound(4))<<endl; // 5
    cout<<*(s.upper_bound(3))<<endl; // 4


    // unordered_set -> O(1) for all operations
    unordered_set<int> us;
    us.insert(1);
    us.insert(2);
    us.insert(3);
    us.insert(4);
    us.insert(5);

    us.insert(1);
    us.insert(2);
    us.insert(3);

    for(auto val : us) {
        cout<<val<<" ";
    }
    // 5 1 2 3 4 -> random order
    cout<<endl;

    // multiset -> duplicates are also present
    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    ms.insert(2);
    ms.insert(3);
    ms.insert(4);

    ms.insert(5);
    ms.insert(5);

    for(auto val : ms) {
        cout<<val<<" ";
    }
    // 1 1 1 2 3 4 5 5
    cout<<endl;
    
}


// Algorithms

void explainSortingComparators() {

    vector<int> nums1 = {1,4,3,6,5,8};
    vector<int> nums2 = {1,4,3,6,5,8};
    // sorting in ascending order
    sort(nums1.begin(),nums1.end());
    for(int& num : nums1) {
        cout<<num<<" ";
    }
    // 1 3 4 5 6 8
    cout<<endl;
    // sorting in descending order
    sort(nums2.begin(),nums2.end(),greater<int>());
    for(int& num : nums2) {
        cout<<num<<" ";
    }
    // 8 6 5 4 3 1
    cout<<endl;


    int arr[5] = {2,7,6,4,8};
    int brr[5] = {2,7,6,4,8};

    // (arr,arr+n) -> sort complete array in ascending order
    sort(arr,arr+5); 
    for(int it : arr) {
        cout<<it<<" ";
    }
    // 2 4 6 7 8
    cout<<endl;


    // (arr,arr+n,greater<int>()) -> sort complete array in descending order
    sort(brr,brr+5,greater<int>()); 
    for(int it : brr) {
        cout<<it<<" ";
    }
    // 8 7 6 4 2
    cout<<endl;


    vector<pair<int,int>> vec = {{3,1},{2,3},{7,4},{5,8},{1,6}};
    // sorting happens on the basis of first 
    sort(vec.begin(),vec.end());

    for(auto& p : vec) {
        cout<<p.first<<"->"<<p.second<<"   ";
    }
    // 1->6   2->3   3->1   5->8   7->4
    cout<<endl;

    // defining a custom comparator
    // sorting on the basis of second
    auto lambda = [](pair<int,int>& p1, pair<int,int>& p2) {
        if(p1.second < p2.second) {
            return true;
        }
        else if(p1.second > p2.second) {
            return false;
        }
        else { // p1.second == p2.second 
            // -> if second of both pairs are equal
            // sort on the basis of first
            if(p1.first < p2.first) {
                return true;
            }
            else {
                return false;
            }
        }
    };

    vector<pair<int,int>> vop = {{3,1},{2,3},{7,1},{5,8},{1,6}};
    sort(vop.begin(),vop.end(),lambda);

    for(auto& p : vop) {
        cout<<p.first<<"->"<<p.second<<"   ";
    }
    // 3->1   7->1   2->3   1->6   5->8
    cout<<endl;

}


void explainMiscellaneousAlgorithms() {

    vector<int> nums = {1,2,3,4,5};

    reverse(nums.begin(),nums.end());
    for(int& num : nums) {
        cout<<num<<" ";
    }
    // 5 4 3 2 1
    cout<<endl;

    // for reversing a particular range
    reverse(nums.begin()+1,nums.begin()+3);
    for(int& num : nums) {
        cout<<num<<" ";
    }
    // 5 3 4 2 1
    cout<<endl;

    // next and previous permutations of a string
    string s = "abc";
    next_permutation(s.begin(),s.end());
    cout<<s<<endl; // acb

    prev_permutation(s.begin(),s.end());
    cout<<s<<endl; // abc

    // max and min
    cout<<max(4,5)<<" "<<min(6,10)<<endl; // 5 6

    // swap two numbers
    int a = 7;
    int b = 8;
    cout<<a<<" "<<b<<endl; // 7 8
    swap(a,b);
    cout<<a<<" "<<b<<endl; // 8 7

    vector<int> v = {1,2,3,4,5};
    // max and min in a array
    cout<<*(max_element(v.begin(),v.end()))<<endl; // 5
    cout<<*(min_element(v.begin(),v.end()))<<endl; // 1

    // binary-search
    cout<<binary_search(v.begin(),v.end(),5)<<endl; // 1 -> true
    cout<<binary_search(v.begin(),v.end(),8)<<endl; // 0 -> false

    // count set bits
    int x = 15;
    l y = 15;
    ll z = 15;
    cout<<__builtin_popcount(x)<<endl; // 4
    cout<<__builtin_popcountl(y)<<endl; // 4
    cout<<__builtin_popcountll(z)<<endl; // 4

}

// main function

int main() {

    int x = 5;
    std :: cout<<x<<std :: endl; // 5
    cout<<x<<endl; // 5

    // void function with no return type
    print(); // Raj

    // int function with integer return type
    int s = sum(1,5);
    cout<<s<<endl; // 6


    // ***************************************

    explainPair();

    explainVector();

    explainList();

    explainDeque();

    explainStack();

    explainQueue();

    explainPQ();

    explainMap();

    explainSet();

    explainSortingComparators();

    explainMiscellaneousAlgorithms();

}





















