// Solved by myself in 20 min or so! but got priority_queue declaration as
// I wrote less() instead of less<> to make max heap

// Time: O(nlogn), Space: O(n)

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Construct max heap
        // put all stones
        // loop until heap length <=1
        //  - get 2 heaviest stones (2 top from heap)
        //  - calc y vs x
        //  - put result to heap
        // return top if size is 1, otherwize 0
        
        priority_queue<int, vector<int>, less<>> heap;

        for(int stone : stones) {
            heap.push(stone);
        }

        while(heap.size() > 1) {
            int x = heap.top(); heap.pop();
            int y = heap.top(); heap.pop();
            
            if(x > y) {
                heap.push(x-y);
            }
        }

        return heap.size() == 0 ? 0 : heap.top();
    }
};
