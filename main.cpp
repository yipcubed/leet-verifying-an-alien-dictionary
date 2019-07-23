#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

// https://leetcode.com/problems/verifying-an-alien-dictionary/

#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"
// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
  bool isgreater(string &x, string &y, int alpha[26]) {
    for (int i = 0; i < min(x.length(), y.length()); ++i) {
      if (alpha[x[i] - 'a'] != alpha[y[i] - 'a'])
        return alpha[x[i] - 'a'] < alpha[y[i] - 'a'];
    }
    return y.length() >= x.length();
  }

  bool isAlienSorted(vector<string> &words, string& order) {
    int alpha[26];
    for (int i = 0; i < 26; ++i) {
      alpha[order[i] - 'a'] = i;
    }
    for (int i = 1; i < words.size(); ++i) {
      if (!isgreater(words[i - 1], words[i], alpha)) {
        return false;
      }
    }
    return true;
  }
};

void test1() {
  vector<string> words{"hello", "leetcode"};
  string order = "hlabcdefgijkmnopqrstuvwxyz";

  cout << "1 ? " << Solution().isAlienSorted(words, order) << endl;

  vector<string> words2{"word","world","row"};
  string order2 = "worldabcefghijkmnpqstuvxyz";

  cout << "0 ? " << Solution().isAlienSorted(words2, order2) << endl;
}

void test2() {

}

void test3() {

}