/*Follow the steps below to solve the problem using this approach:

Sort both the arrays
Then linearly compare elements of both the arrays
If all are equal then return true, else return false*/

class Solution{
    public:

    //Function to check if two arrays are equal or not.
    bool check(vector<ll> A, vector<ll> B, int N) {
        //code here
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        for(int i=0;i<N;i++){
            if(A[i]!=B[i]){
                return false;
            }
        }
        return true;
    }
};
/* TC: O(NlogN)
   SC: O(1)
*/


/*Another Method: Using Map 

Initialise a map say unmap
Insert all elements of array A into map
Remove all elements of array B from map
Check if the size of unmap becomes zero
If zero, return true
Otherwise, return false

Follow the steps mentioned below to implement the approach:

First check if length of arr1 is not equal to the length of arr2 then return false
Then traverse over first array and store the count of every element in the hash map
Then traverse over second array and decrease the count of its elements in the hash map. If that element is not present or the count of that element is 
zero in the hash map, then return false, else decrease the count of that element
Return true at the end, as both the arrays are equal by now

Time Complexity: O(n)
Auxiliary Space: O(n)*/
