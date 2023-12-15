#include "set.h"
#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    Set<int> set;
    while (n--) {
      string in;
      cin >> in;
      if (in == "insert") {
        int x;
        cin >> x;
        set.Insert(x);
        cout << set.GetDepth(x) << '\n';
      } else if (in == "find") {
        int x;
        cin >> x;
        cout << set.GetDepth(x) << '\n';
      } else if (in == "empty") {
        cout << set.IsEmpty() << '\n';
      } else if (in == "minimum") {
        int x;
        cin >> x;
        int key = set.GetMinKey(x);
        cout << key << ' ';
        cout << set.GetDepth(key) << '\n';
      } else if (in == "maximum") {
        int x;
        cin >> x;
        int key = set.GetMaxKey(x);
        cout << key << ' ';
        cout << set.GetDepth(key) << '\n';
      } else if (in == "size") {
        cout << set.GetSize() << '\n';
      } else if (in == "erase") {
        int x;
        cin >> x;
        cout << set.Erase(x) << '\n';
      } else if (in == "rank") {
        int x;
        cin >> x;
        int rank;
        if ((rank = set.GetRank(x)) == 0) {
          cout << rank << '\n';
        } else {
          cout << set.GetDepth(x) << ' ' << rank << '\n';
        }
      }
    }
  }
}
