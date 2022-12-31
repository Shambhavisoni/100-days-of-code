/*Follow the steps given below to implement the approach:

Traverse the array from start to end.
From every index start another loop from i to the end of the array to get all subarrays starting from i, and keep a variable currentSum to calculate the sum of every
subarray.
For every index in inner loop update currentSum = currentSum + arr[j]
If the currentSum is equal to the given sum then print the subarray.*/

class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        vector<int> v1;
        for(int i=0;i<n;i++){
            long long sum=0;
            for(int j=i;j<n;j++){
                sum+=arr[j];
                if(sum==s){
                    v1.push_back(i+1);
                    v1.push_back(j+1);
                    break;
                }
                else if(sum>s){
                    break;
                }
            }
            if(v1.size()==2){
                break;
            }
        }
        if(v1.size()==0){
            v1.push_back(-1);
        }
        return v1;
    }
};

