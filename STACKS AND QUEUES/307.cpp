#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st;

    for (int a : asteroids) {
        bool destroyed = false;

        while (!st.empty() && a < 0 && st.top() > 0) {
            // Compare current with top of stack
            if (abs(a) > st.top()) {
                st.pop(); // current survives, continue checking
            } else if (abs(a) == st.top()) {
                st.pop(); // both explode
                destroyed = true;
                break;
            } else {
                destroyed = true; // current is smaller, destroyed
                break;
            }
        }

        if (!destroyed) {
            st.push(a);
        }
    }

    // Convert stack to vector (reversed)
    vector<int> result(st.size());
    for (int i = st.size() - 1; i >= 0; i--) {
        result[i] = st.top();
        st.pop();
    }

    return result;
}

int main() {
    vector<int> asteroids = {4,7,1,1,2,-3,-7,17,15,-18,-19};
    vector<int> result = asteroidCollision(asteroids);

    cout << "Final asteroids: ";
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}
