class Solution {
  int countAtom(string &formula, int &j) {
    string countStr;
    while (j < formula.size() && formula[j] >= '0' && formula[j] <= '9') {
      countStr += formula[j];
      j++;
    }
    return countStr.empty() ? 1 : stoi(countStr);
  }

public:
  string countOfAtoms(string &formula) {
    stack<pair<string, int>> stck;
    for (int i = 0; i < formula.size(); i++) {
      if (formula[i] >= 'A' && formula[i] <= 'Z') {
        string atom;
        atom += formula[i];
        int j = i + 1;
        while (j < formula.size() && formula[j] >= 'a' && formula[j] <= 'z') {
          atom += formula[j];
          j++;
        }
        stck.push({atom, countAtom(formula, j)});
        i = j - 1;
      } else if (formula[i] == '(') {
        stck.push({"(", 0});
      } else {
        int j = i + 1;
        int atomCount = countAtom(formula, j);
        unordered_map<string, int> umap;
        while (stck.top().first != "(") {
          pair<string, int> top = stck.top();
          stck.pop();
          umap[top.first] += top.second * atomCount;
        }
        stck.pop();
        for (auto &it : umap) {
          stck.push(it);
        }
        i = j - 1;
      }
    }
    map<string, int> mp;
    while (!stck.empty()) {
      pair<string, int> top = stck.top();
      stck.pop();
      mp[top.first] += top.second;
    }
    string ans;
    for (auto &it : mp) {
      ans += it.first;
      if (it.second > 1) {
        ans += to_string(it.second);
      }
    }
    return ans;
  }
};