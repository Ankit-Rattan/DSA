#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
// Ques : Sum of mamimum and minimum element of all subarray of size k

int solve(vector<int> &arr, int n, int k){
    deque<int> maxi(k);
    deque<int> mini(k);

    // Addition of first k sized window
    for(auto i=0; i<k; i++){
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }
        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
        
    }

    int ans = 0;
    // adding for the very first window.
    ans += arr[maxi.front()] + arr[mini.front()];


    // Now for rest of the array

    for(auto i =k; i<n; i++){

        // next window

        // removal
        while(!maxi.empty() && ( i - maxi.front() >= k)){
            maxi.pop_front();
        }
        while(!mini.empty() && ( i - mini.front() >= k)){
            mini.pop_front();
        }

        // Addition
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }
        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);

        ans += arr[maxi.front()] + arr[mini.front()];
    }
    return ans;
}
int main()
{
    // int n = 5;
    int n = 7;
    vector<int> v = {2, 5, -1, 7, -3, -1, -2};

    int ans = solve(v, n, 4);
    cout<<ans<<endl;
    
    return 0;
}