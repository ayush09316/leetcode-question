class Solution {
public:
    int calculateCombination(int n, int r) {
        long long result = 1;
        for (int i = 0; i < r; i++) {
            result = result * (n - i) / (i + 1);
        }
        return result;
    }

    vector<int> getRow(int rowIndex) {
        vector<int> lastRow;

        for (int j = 0; j <= rowIndex; j++) {
            lastRow.push_back(calculateCombination(rowIndex, j));
        }
        
        return lastRow;
    }
};