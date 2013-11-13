#include <vector>

class Zz {
public:
  int LongestZz(vector<int> sequence)
  {
    if ((sequence.size() == 1)) {
      return 1;
    }
    vector<int> V(sequence.size() - 1);
    for (int i = 1; i < sequence.size(); i++) {
      V[i-1] = sequence[i] - sequence[i - 1];
    }

    int ii = 0;
    while (ii < V.size() && V[ii] == 0) {
      ii++;
    }
    if (ii = V.size()) {
      return 1;
    }
    int dir = V[ii];
    int len = 2;
    for (int i = ii + 1; i < V.size(); i++)
    {
      if (V[i] * dir < 0) {
        dir *= -1;
        len ++;
      }
    }
    return len;
  }
}
