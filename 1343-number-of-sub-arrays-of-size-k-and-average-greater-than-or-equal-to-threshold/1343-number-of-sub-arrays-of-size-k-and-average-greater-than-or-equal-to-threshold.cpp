class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int low=0;
        int high=k-1;
        int sum=0;
       
        int count=0;
        int avg=0;
        for(int i=low;i<=high;i++){
            sum+=arr[i];
        }
        avg=sum/k;
        while(high<arr.size()){
            if(avg>=threshold){
                count++;
            }
                
            
            sum=sum-arr[low];
low++;
high++;
if(high==arr.size()){
    break;
}
sum+=arr[high];
avg=sum/k;
        }
       
        return count;
    }
};