/*Naive Approach: Follow the steps below to solve the problem using this approach:

Consider all sub-arrays one by one and check the sum of every sub-array.
If the sum of the current subarray is equal to zero then update the maximum length accordingly*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        int i,max_len=0;
        for(i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=A[j];
                if(sum==0){
                    max_len=max(max_len,j-i+1);
                }
            }
        }
        return max_len;
    }
};
/*TC:O(n^2)
  SC:O(1)
  */

/*Efficient Approach 1 (Hash map):  Follow the below idea to solve the problem using this approach: 

Create a variable sum and while traversing the input array, for every index add the value of the element into the sum variable and then store the sum-index pair 
in a hash-map. So, if the same value appears twice in the array, it will be guaranteed that the particular array will be a zero-sum sub-array. 

Mathematical Proof:  

prefix(i) = arr[0] + arr[1] +...+ arr[i] 
prefix(j) = arr[0] + arr[1] +...+ arr[j], j > i 
ifprefix(i) == prefix(j) then prefix(j) - prefix(i) = 0 that means arr[i+1] + .. + arr[j] = 0, So a sub-array has zero sum , 
and the length of that sub-array is j-i+1  

Follow the steps mentioned below to implement the approach:

Create a variable (sum), length (max_len), and a hash map (hm) to store the sum-index pair as a key-value pair.
Traverse the input array and For every index, update the value of sum = sum + array[i].
Check every index, if the current sum is present in the hash map or not.
If present, update the value of max_len to a maximum difference of two indices (current index and index in the hash-map) and max_len.
Else, put the value (sum) in the hash map, with the index as a key-value pair.
Print the maximum length (max_len).
*/
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int,int> m1;
        int sum=0,max_len=0;
        for(int i=0;i<n;i++){
            sum+=A[i];
            if(sum==0){
                max_len=i+1;
            }
            if(m1.count(sum)){
                max_len=max(max_len,i-m1[sum]);
            }
            else{
                m1[sum]=i;
            }
        }
        return max_len;
        
    }
};

/*TC:O(n)
  SC:O(n)
  */
