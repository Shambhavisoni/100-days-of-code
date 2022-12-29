/*Follow the steps mentioned below to implement the idea:

Sort the array.
Traverse the array from index 1 to N-1, and increase the value of index by 2.
While traversing the array swap arr[i] with arr[i+1].
Print the final array.*/

void zigZag(int arr[], int n) {
        // code here
        sort(arr,arr+n);
        for(int i=1;i<n-1;i+=2){
            swap(arr[i],arr[i+1]);
        }
}
/*TC: O(nlogn) as sorting is used
SC: O(1)
*/


/*Follow the steps mentioned below to implement the idea:

Create a bool variable flag and set it to true
Traverse the array from index 0 to N-1 
If the value of flag is true then check if  arr[i] < arr[i+1] or not , if not then swap
Flip the value of flag
If the value of flag is false then check if  arr[i] > arr[i+1] or not , if not then swap
Print the final array.*/

void zigZag(int arr[], int n) {
        // code here
        bool flag=true;
        for(int i=0;i<n-1;i++){
            if(flag){ 
                if(arr[i]>arr[i+1]){
                    swap(arr[i],arr[i+1]);
                }
            }
            else{ 
                if(arr[i]<arr[i+1]){
                    swap(arr[i],arr[i+1]);
                }
            }
            flag=!flag;
        }
        
    }
/*TC: O(n)
SC: O(1)
*/
