#include <bits/stdc++.h>
using namespace std;

/**
 * @link https://leetcode.com/problems/making-file-names-unique/
 * @time_taken:
 */
class Solution {
 public:
  vector<string> getFolderNames(vector<string>& names) {
    unordered_map<string, int> hsh;

    for (int i = 0; i < names.size(); ++i) {
      if (hsh.find(names[i]) == hsh.end()) {
        hsh[names[i]] = 1;
      } else {
        int nextMin = hsh[names[i]];
        while (true) {
          string newName = names[i] + '(' + to_string(nextMin) + ')';
          if (hsh.find(newName) == hsh.end()) {
            hsh[names[i]] = nextMin + 1;
            hsh[newName] = 1;
            names[i] = newName;
            break;
          }
          ++nextMin;
        }
      }
    }

    return names;
  }
};