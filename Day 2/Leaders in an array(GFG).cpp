class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code here
        vector<int> v1;
        int i,j;
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if(a[i]<a[j]){
                    break;
                }
            }
            if(j==n || i==n-1){
                v1.push_back(a[i]);
            }
        }
        return v1;
    }
};

/*TC: O(n^2)
  SC: O(1)
 */

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code here
        vector<int> v1;
        int maximum=a[n-1];
        v1.push_back(maximum);
        for(int i=n-2;i>=0;i--){
            if(maximum<=a[i]){
                maximum=a[i];
                v1.push_back(maximum);
            }
        }
        int si=0,ei=v1.size()-1;
        while(si<ei){
            swap(v1[si],v1[ei]);
            si++;
            ei--;
        }
        return v1;
    }
};

/*TC: O(n)
  SC: O(n)
 */
