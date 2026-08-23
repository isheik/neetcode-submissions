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
            int n = 0;

            if(x < y) {
                n = y-x;
            } else if(x > y) {
                n = x-y;
            }

            if(n != 0)
                heap.push(n);            
        }

        return heap.size() == 0 ? 0 : heap.top();
    }
};
