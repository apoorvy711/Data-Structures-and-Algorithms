#include <bits/stdc++.h>
using namespace std;

// Find Next Smaller Element indices
vector<int> findNSE(vector<int> &arr) {
    int n = arr.size();
    stack<int> st;
    vector<int> nse(n);
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        nse[i] = st.empty() ? n : st.top();  // if none found, take boundary
        st.push(i);
    }
    return nse;
}

// Find Previous Smaller Element indices
vector<int> findPSE(vector<int> &arr) {
    int n = arr.size();
    stack<int> st;
    vector<int> pse(n);
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        pse[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return pse;
}

// Largest rectangle area in histogram
int largestHistogramArea(vector<int> &heights) {
    int n = heights.size();
    vector<int> pse = findPSE(heights);
    vector<int> nse = findNSE(heights);

    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int width = nse[i] - pse[i] - 1;
        int area = heights[i] * width;
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

// Maximal rectangle in binary matrix
int maximalRectangle(vector<vector<int>> &mat) {
    if (mat.empty()) return 0;

    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> psum(n, vector<int>(m, 0));

    // Step 1: Build psum matrix (height of 1s in each column)
    for (int j = 0; j < m; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (mat[i][j] == 1)
                sum += 1;
            else
                sum = 0;
            psum[i][j] = sum;
        }
    }

    // Step 2: Apply histogram area for each row
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        maxArea = max(maxArea, largestHistogramArea(psum[i]));
    }

    return maxArea;
}

// Driver Code
int main() {
    vector<vector<int>> matrix = {
        {1, 0, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0}
    };

    int result = maximalRectangle(matrix);
    cout << "The largest rectangle area is: " << result << endl;

    return 0;
}
