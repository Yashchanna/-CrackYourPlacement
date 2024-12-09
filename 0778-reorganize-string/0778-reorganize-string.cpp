#include <string>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        int freq[26] = {0};
        
        // Count the frequency of each character
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        
        // Use a max heap to store characters by their frequency
        priority_queue<pair<int, char>> maxHeap;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                maxHeap.push({freq[i], 'a' + i});
            }
        }
        
        string ans = "";
        while (maxHeap.size() > 1) {
            // Pop two most frequent characters
            auto first = maxHeap.top(); maxHeap.pop();
            auto second = maxHeap.top(); maxHeap.pop();
            
            // Append them to the result
            ans.push_back(first.second);
            ans.push_back(second.second);
            
            // Decrease their counts and reinsert if still valid
            if (--first.first > 0) maxHeap.push(first);
            if (--second.first > 0) maxHeap.push(second);
        }
        
        // Handle the last remaining character
        if (!maxHeap.empty()) {
            auto last = maxHeap.top(); maxHeap.pop();
            if (last.first > 1) {
                return ""; // Not possible to reorganize
            }
            ans.push_back(last.second);
        }
        
        return ans;
    }
};
