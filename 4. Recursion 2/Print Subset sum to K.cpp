/*

Print Subset Sum to K
Send Feedback
Given an array A and an integer K, print all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. 
But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print them in different lines.

Input format :
Line 1 : Size of input array
Line 2 : Array elements separated by space
Line 3 : K 

Sample Input:
9 
5 12 3 17 1 18 15 3 17 
6
Sample Output:
3 3
5 1

*/

#include<bits/stdc++.h>
using namespace std;

void helper(int arr[],int i,int n,int target,vector <int> v)
{
  
  if(i == n)
  {
    if(target == 0)
    {
       for(auto x : v)
       {
           cout << x <<" ";
       }
       cout << endl;
    }
    return;
  }


    // including that element in our vector
    target -= arr[i];
    v.push_back(arr[i]);
    helper(arr,i+1,n,target,v);
    
    // backtrack
    target += arr[i];
    v.pop_back();

    // not including that element in our vector
    helper(arr,i+1,n,target,v);


}

void printSubsetSumToK(int input[], int size, int k) {
     
    vector <int> v;

    helper(input,0,size,k,v);

}
