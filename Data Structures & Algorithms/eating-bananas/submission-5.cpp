class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // if k is set to the highest of piles, then can finish in piles.size hour
        // as piles.len <= h, guaranteed to finish eating in that case

        // then, find min k that within h
        // do 

        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int res = r;

        while(l<=r) {
            int k = (l+r) / 2;

            long long totalTime = 0;
            for(int p:piles) {
                totalTime += ceil(static_cast<double>(p)/k);
            }
            if(totalTime <=h) {
                res = k;
                r=k-1;
            } else {
                l=k+1;
            }


        }
                    return res;
    }
};



// class Solution {
// public:
//     int minEatingSpeed(vector<int>& piles, int h) {
//         int l = 1;
//         int r = *max_element(piles.begin(), piles.end());
//         int res = r;

//         while (l <= r) {
//             int k = (l + r) / 2;

//             long long totalTime = 0;
//             for (int p : piles) {
//                 totalTime += ceil(static_cast<double>(p) / k);
//             }
//             if (totalTime <= h) {
//                 res = k;
//                 r = k - 1;
//             } else {
//                 l = k + 1;
//             }
//         }
//         return res;
//     }
// };