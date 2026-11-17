class Solution {
public:
    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList
    ) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return {};

        unordered_map<string, int> dist;
        unordered_map<string, vector<string>> parents;
        queue<string> q;

        dist[beginWord] = 0;
        q.push(beginWord);
        bool found = false;

        while (!q.empty() && !found) {
            int size = q.size();

            while (size--) {
                string word = q.front();
                q.pop();

                int nextDist = dist[word] + 1;
                string next = word;

                for (int i = 0; i < next.size(); ++i) {
                    char original = next[i];

                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == original) continue;

                        next[i] = c;
                        if (!dict.count(next)) continue;

                        // Discover this word at its shortest distance.
                        if (!dist.count(next)) {
                            dist[next] = nextDist;
                            q.push(next);
                        }

                        // Keep every parent that gives a shortest path.
                        if (dist[next] == nextDist) {
                            parents[next].push_back(word);
                            if (next == endWord) found = true;
                        }
                    }

                    next[i] = original;
                }
            }
        }

        if (!found) return {};

        vector<vector<string>> result;
        vector<string> path{endWord};

        function<void(const string&)> backtrack =
            [&](const string& word) {
                if (word == beginWord) {
                    result.emplace_back(path.rbegin(), path.rend());
                    return;
                }

                for (const string& parent : parents[word]) {
                    path.push_back(parent);
                    backtrack(parent);
                    path.pop_back();
                }
            };

        backtrack(endWord);
        return result;
    }
};