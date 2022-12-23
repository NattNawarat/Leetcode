class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size()-1;
        while (l<r) {
            int sum = numbers.at(l)+numbers.at(r);
            if (sum > target)r--;
            else if (sum < target)l++;
            else return vector<int> {l+1, r+1};
        }
        return vector<int> {l+1, r+1};
    }
};