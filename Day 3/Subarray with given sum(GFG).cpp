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

/*Follow the steps given below to implement the approach:

Create two variables, start=0, currentSum = arr[0]
Traverse the array from index 1 to end.
Update the variable currentSum by adding current element, currentSum = currentSum + arr[i]
If the currentSum is greater than the given sum, update the variable currentSum as currentSum = currentSum - arr[start],
and update start as, start++.
If the currentSum is equal to given sum, print the subarray and break the loop.*/
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        int start=0,sum=arr[0];
        for(int i=1;i<=n;i++){
            while(s<sum && start<i-1){
                sum-=arr[start];
                start++;
            }
            if(s==sum){
                return{start+1,i};
            }
            if(i<n){
                sum+=arr[i];
            }
        }
        return{-1};
    }
        /*int start=0,end=-1,sum=0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==s){
                start=0;
                end=i;
                v.push_back(start+1);
                v.push_back(end+1);
                break;
            }
            else if(m.find(sum-s)!=m.end()){
                start=m[sum-s]+1;
                end=i;
                v.push_back(start+1);
                v.push_back(end+1);
                break;
            }
            else{
                m[sum]=i;
            }
        }
        if(end==-1){
            v.push_back(end);
        }
        return v;*/
};
