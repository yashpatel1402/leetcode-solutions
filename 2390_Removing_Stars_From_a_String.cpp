#include <bits/stdc++.h>
using namespace std;

/**
 * @link https://leetcode.com/problems/removing-stars-from-a-string/description/
 * @time_taken:
 */
class Solution {
 public:
  string removeStars(string s) {
    stack<char> st;
    for (char i : s) {
      if (i == '*')
        st.pop();
      else
        st.push(i);
    }

    string ans;
    while (!st.empty()) {
      ans += st.top();
      st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
  }
};

class SolutionByString {
 public:
  string removeStars(string s) {
    string ans = "";

    for (char c : s) {
      if (c == '*') {
        if (ans.size() > 0) ans.pop_back();
      } else {
        ans.push_back(c);
      }
    }

    return ans;
  }
};

class SolutionWith2Pointers {
 public:
  string removeStars(string s) {
    int j = 0;
    string ans = string(s.size(), '*');

    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '*') {
        j = max(0, j - 1);
      } else {
        ans[j] = s[i];
        j++;
      }
    }

    return ans.substr(0, j);
  }
};