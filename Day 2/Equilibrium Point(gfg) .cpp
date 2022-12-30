//APPROACH 1
/*Method 1 (Simple but inefficient) 
Use two loops. Outer loop iterates through all the element and inner loop finds out whether the current index picked by the outer loop is equilibrium index or not. 
Time complexity of this solution is O(n^2). */
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        for(int i =0;i<n;i++){
            long long ls=0,rs=0;
            for(int j=0;j<i;j++){
                ls+=a[j];
            }
            for(int j=i+1;j<n;j++){
                rs+=a[j];
            }
            if(ls==rs){
                return i+1;
            }
        }
        return -1;
    }

};
/*TC: O(n^2)
SC: O(1)
*/

/*Method 2 (Tricky and Efficient) 
The idea is to get the total sum of the array first. Then Iterate through the array and keep updating the left sum which is initialized as zero. 
  In the loop, we can get the right sum by subtracting the elements one by one. */

class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
        }
        long long s_left=0,s_right=sum;
        for(int i=0;i<n;i++){
            s_right-=a[i];
            if(s_left==s_right){
                return i+1;
            }
            s_left+=a[i];
        }
        return -1;
    }

};

/*TC: O(n)
  SC: O(1)
*/

/*Method 3 :

This is a quite simple and straightforward method. The idea is to take the prefix sum of the array twice. 
Once from the front end of array and another from the back end of array.
After taking both prefix sums run a loop and check for some i if both the prefix sum from one array is equal to prefix sum from the second 
array then that point can be considered as the Equilibrium point.*/

class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        long long forward[n]={0};
        long long rev[n]={0};
        forward[0]=a[0];
        rev[n-1]=a[n-1];
        for(int i=1;i<n;i++){
            forward[i]=forward[i-1]+a[i];
        }
        for(int i=n-2;i>=0;i--){
            rev[i]=rev[i+1]+a[i];
        }
        for(int i=0;i<n;i++){
            if(forward[i]==rev[i]){
                return i+1;
            }
        }
        return -1;
    }

};
/*TC: O(n)
  SC: O(n)
*/

/*Method 4:- Using binary search

To handle all the testcase, we can use binary search algorithm.

1.calculate the mid and then create left sum and right sum around mid

2.if left sum is greater than right sum, move to left until it become equal or less than right sum

3. else if right sum is greater than left, move right until it become equal or less than left sum.

4. finally we compare two sums if they are equal we got mid as index else its -1*/

class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        long long mid=n/2,ls=0,rs=0;
        for(int i=0;i<mid;i++){
            ls+=a[i];
        }
        for(int i=mid+1;i<n;i++){
            rs+=a[i];
        }
        if(rs>ls){
            while(rs>ls && mid<n-1){
                rs-=a[mid+1];
                ls+=a[mid];
                mid++;
            }
        }
        else{
            while(rs<ls && mid>0){
                rs+=a[mid];
                ls-=a[mid-1];
                mid--;
            }
        }
        if(ls==rs){
            return mid+1;
        }
        return -1;
    }

};

/*TC: O(n)
  SC: O(1)
*/
