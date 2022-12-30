/*Follow the steps below to solve the given problem:  

Keep three counters c0 to count 0s, c1 to count 1s, and c2 to count 2s
Traverse through the array and increase the count of c0 if the element is 0, increase the count of c1 if the element is 1 and increase the count of c2 if the
element is 2
Now again traverse the array and replace the first c0 elements with 0, the next c1 elements with 1, and the next c2 elements with 2.*/

class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // code here 
        int s0=0,s1=0,s2=0;
        for(int i=0;i<n;i++){
            if(a[i]==0){
                s0++;
            }
            else if(a[i]==1){
                s1++;
            }
            else{
                s2++;
            }
        }
        for(int i=0;i<s0;i++){
            a[i]=0;
        }
        for(int i=s0;i<s0+s1;i++){
            a[i]=1;
        }
        for(int i=s0+s1;i<n;i++){
            a[i]=2;
        }
    }
  /*TC: O(n)
    SC: O(1)*/  
    
  /*This approach is based on the following idea:

The problem is similar to "Segregate 0s and 1s in an array".
The problem was posed with three colors, here `0', `1' and `2'. The array is divided into four sections: 
arr[1] to arr[low - 1]
arr[low] to arr[mid - 1]
arr[mid] to arr[high - 1]
arr[high] to arr[n]
If the ith element is 0 then swap the element to the low range.
Similarly, if the element is 1 then keep it as it is.
If the element is 2 then swap it with an element in high range.*/
    class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // code here 
        int ptr1=0,ptr2=n-1;
        int i=0;
        while(i<=ptr2){
            if(a[i]==0){
                swap(a[i],a[ptr1]);
                i++;
                ptr1++;
            }
            else if(a[i]==2){
                swap(a[i],a[ptr2]);
                ptr2--;
            }
            else{
                i++;
            }
        }
    }
    
};

/*TC: O(n)
  SC: O(1)*/
