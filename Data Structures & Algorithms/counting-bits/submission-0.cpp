class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> output;
        for(int i=0; i<=n; i++) {
            int c = 0;
            int num = i;

            while(num > 0) {
                if(num % 2 == 1) {
                    c++;
                }
                num = num/2;
            }
            output.push_back(c);
        }

        return output;
    }
};
