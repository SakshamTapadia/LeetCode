class Solution {
private:
std::unordered_map<string, std::vector<char>> allowedTops_;
std::unordered_map<string, bool> memo_;
    bool generateNextLevels(string& previous, string current) { 
        if (previous.size() == 1) { 
            return true;
        }
        if (previous.length() - 1 == current.length()) {
            if (memo_.contains(current)) { 
                return memo_[current];
            }
            bool result = generateNextLevels(current, "");
            memo_[current] = result;
            return result;
        }
        int idx = current.length();
        for (const auto& top : allowedTops_[previous.substr(idx, 2)]) {
            if (generateNextLevels(previous, current+top)) { 
                return true;
            }
        }
        return false;
    }
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (const auto& triple : allowed) { 
            allowedTops_[triple.substr(0,2)].push_back(triple.back());
        }
        return generateNextLevels(bottom, "");
    }
};