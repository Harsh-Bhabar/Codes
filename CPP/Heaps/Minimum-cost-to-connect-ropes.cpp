{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<int long long, vector<int long long>, greater<int long long>> minHeap;
        long long ans = 0 ;
        
        for(int i=0; i<n; i++){
            minHeap.push(arr[i]);    
        }
        
        while(minHeap.size() >= 2){
            long long first = minHeap.top(); minHeap.pop();
            long long second = minHeap.top(); minHeap.pop();
            long long sum = (first + second);
            
            ans += sum;
            minHeap.push(sum);
        }
        
        return ans;
    }
};