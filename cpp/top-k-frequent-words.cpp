class Solution {
public:
    
    static bool comp(pair<int, string> &a, pair<int, string> &b) {
        return (a.first == b.first ? a.second < b.second : a.first > b.first);
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        map<string, int> m;
        for(auto i : words) {
            m[i]++;
        }
        vector<pair<int, string> > ans;
        for(auto i : m) {
            ans.push_back({i.second, i.first});
            
        }
        vector<string> res;
        sort(ans.begin(), ans.end(), comp);
        
        for(int  i = 0; i < k; i++) {
            res.push_back(ans[i].second);
        }
        return res;
        
        
        
    }
};