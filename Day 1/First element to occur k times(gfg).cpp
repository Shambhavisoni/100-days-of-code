/*Use map to store the occurence of each element and return the answer once you find the  element occuring k times. 
TC: O(n)
SC: O(n)
*/

class Solution{
    public:
    int firstElementKTime(int a[], int n, int k)
    {
        unordered_map<int,int> m1;
        for(int i=0;i<n;i++){
            if(!m1.count(a[i])){
                m1[a[i]]=1;
            }
            else{
                m1[a[i]]++;
            }
            if(m1[a[i]]==k){
                return a[i];
            }
        }
        return -1;
    }
};
