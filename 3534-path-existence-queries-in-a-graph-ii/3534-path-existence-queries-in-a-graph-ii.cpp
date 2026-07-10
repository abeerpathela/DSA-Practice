class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                     vector<vector<int>>& queries) {

        vector<pair<int,int>> arr;
        for(int i = 0; i < n; i++)
            arr.push_back({nums[i], i});

        sort(arr.begin(), arr.end());

        vector<int> pos(n);
        for(int i = 0; i < n; i++)
            pos[arr[i].second] = i;

        vector<int> far(n);

        int j = 0;
        for(int i = 0; i < n; i++) {
            while(j + 1 < n && arr[j + 1].first - arr[i].first <= maxDiff)
                j++;
            far[i] = j;
        }

        const int LOG = 18;
        vector<vector<int>> up(LOG, vector<int>(n));

        for(int i = 0; i < n; i++)
            up[0][i] = far[i];

        for(int k = 1; k < LOG; k++) {
            for(int i = 0; i < n; i++) {
                up[k][i] = up[k-1][ up[k-1][i] ];
            }
        }

        vector<int> ans;

        for(auto &q : queries) {

            int a = pos[q[0]];
            int b = pos[q[1]];

            if(a > b) swap(a, b);

            if(a == b) {
                ans.push_back(0);
                continue;
            }

            if(far[a] < a + 1) {
                ans.push_back(-1);
                continue;
            }

            int cur = a;
            int steps = 0;

            for(int k = LOG - 1; k >= 0; k--) {
                if(up[k][cur] < b) {
                    cur = up[k][cur];
                    steps += (1 << k);
                }
            }

            if(far[cur] >= b)
                ans.push_back(steps + 1);
            else
                ans.push_back(-1);
        }

        return ans;
    }
};