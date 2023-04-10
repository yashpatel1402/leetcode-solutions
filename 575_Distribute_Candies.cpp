#include <bits/stdc++.h>
using namespace std;

/**
 * @link https://leetcode.com/problems/distribute-candies/description/
 * @time-taken: 00:02:31
 */
class Solution {
 public:
  int distributeCandies(vector<int>& candyType) {
    // set<int> occ(candyType.begin(), candyType.end());
    // return min(occ.size(), candyType.size() / 2);
    unsigned long occ = 0;
    unordered_map<int, int> mp;
    for (auto i : candyType) {
      mp[i]++;
      if (mp[i] == 1) occ++;
    }

    return min(occ, candyType.size() / 2);
  }
};