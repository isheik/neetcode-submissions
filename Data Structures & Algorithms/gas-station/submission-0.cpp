class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // get gas at current
        // consume gas at current
        // if not enough gas, try next start
        // go to next index
        // repeat until going back to the start index

        bool goal = false;

        int k = gas.size();
        int g = 0;
        int count = 0;

        for(int i=0; i<k; i++){
            for(int j=i; j<k+i; j++) {
                if(j>=k) {
                    g += gas[j-k];
                    g -= cost[j-k];                    
                } else {
                    g += gas[j];
                    g -= cost[j];                    
                }

                if(g < 0) {
                    break;
                }

                count++;
                if(count == k) {
                    return i;
                }
            }
            count = 0;
            g = 0;
        }

        return -1;
    }
};
