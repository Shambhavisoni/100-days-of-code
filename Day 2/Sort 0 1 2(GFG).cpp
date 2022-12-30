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
    
};
