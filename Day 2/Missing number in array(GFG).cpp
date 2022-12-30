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
