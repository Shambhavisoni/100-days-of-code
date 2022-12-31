class Solution{
  public:
    int MissingNumber(vector<int>& array, int n) {
        // Your code goes here
        sort(array.begin(),array.end());
        for(int i=0;i<n;i++){
            if(array[i]!=i+1){
                return i+1;
            }
        }
        return n;
    }
};
/*TC: O(nlogn)
SC: O(1)*/


/*Approach 2 (Using binary operations): This method uses the technique of XOR to solve the problem.  

XOR has certain properties 

Assume a1 ⊕ a2 ⊕ a3 ⊕ . . . ⊕ an = a and a1 ⊕ a2 ⊕ a3 ⊕ . . . ⊕ an-1 = b
Then a ⊕ b = an
Follow the steps mentioned below to implement the idea:

Create two variables a = 0 and b = 0
Run a loop from i = 1 to N:
For every index, update a as a = a ^ i
Now traverse the array from i = start to end.
For every index, update b as b = b ^ arr[i].
The missing number is a ^ b.*/

class Solution{
  public:
    int MissingNumber(vector<int>& array, int n) {
        // Your code goes here
        int x1=0,x2=0;
        for(int i=1;i<=n;i++){
            x1^=i;
        }
        for(int i=0;i<n;i++){
            x2^=array[i];
        }
        return (x1^x2);
    }
};
/*TC: O(n)
SC: O(1)*/

/*Approach 3 (Using Cyclic Sort): The idea behind it is as follows:

All the given array numbers are sorted and in the range of 1 to n-1. If the range is 1 to N  then the index of every array element will be the same as (value - 1).

Follow the below steps to implement the idea:

Use cyclic sort to sort the elements in linear time.
Now traverse from i = 0 to the end of the array:
If arr[i] is not the same as i+1 then the missing element is (i+1).
If all elements are present then N is the missing element in the range [1, N].
Below is the implementation of the above approach.*/

class Solution{
  public:
    int MissingNumber(vector<int>& array, int n) {
        // Your code goes here
        int i=0;
        while(i<n){                  //used cylic sort instead of build in sort method as cyclic sort complexcity-O(n)
            int correct=array[i]-1;
            if(array[i]<n && array[i]!=array[correct]){
                swap(array[i],array[correct]);
            }
            else{
                i++;
            }
        }
        for(int i=0;i<n;i++){
            if(array[i]!=i+1){
                return i+1;
            }
        }
        return n;
    }
};

/*TC: O(n)
SC: O(1)*/
