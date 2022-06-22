class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        // using max heap
        priority_queue <int> pq;
        for(int i=0;i<nums.size();i++)
        {
            // pushing all the elements into the maxheap and maxheap will automatically sort the elements in 
            // descending order with max element on top
            pq.push(nums[i]);
        }
        k=k-1;
        // to find k th largest we will remove k-1 elements from top
        while(k--)
        {
            pq.pop();
        }
        // top of the heap will give the kth maximum element
        return pq.top();
        
        }
};
