class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int totalCount = 0;
        priority_queue<int> maxHeap;
        for(int i=0;i<heights.size()-1;i++){
            // If height of next building is smaller jump on it
            if(heights[i]>=heights[i+1]){
                continue;
            }else {
                // Difference between both heights
                int diff = heights[i+1]-heights[i];
                
                //Total count of bricks needed
                totalCount+=diff;
                
                // If count of bricks is greater than existing bricks return the current height as no ladder is remaining
                if(ladders==0 && totalCount>bricks) return i;
				
                 // If count of bricks is lesser than existing bricks move to next building
                if(ladders==0 && totalCount<=bricks) continue;
                
                // Insert the current differnce into maxheap to retrive the highest diff if needed for the ladder
                maxHeap.push(diff);
                
				// If total count of bricks is greater than the max bricks retrive the highest diff and use ladder and delete it from total count
                if(totalCount>bricks){
                    totalCount-=maxHeap.top();
                    maxHeap.pop();
                    ladders--;
                }
            }
        }
		// Return the last element as it reached till the end
        return heights.size()-1;
    }
};