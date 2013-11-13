#include <iostream>
#include <vector>

using namespace std;

int Max(int arr[])
{
  int temp;
  for (int i = 0; i < 6; i++) {
    if (arr[i] > temp) {
      temp = arr[i];
    }
  }
  return temp;
}

int LongestZigZag(vector<int> sequence)
{
  vector <int> V (sequence.size() -1);
  for(int i = 0; i < sequence.size() - 1; i++) {
    V[i] = sequence[i + 1] - sequence[i];
  }

  int A[6] = {0};
  A[0] = 1;
  A[1] = 2;
  for (int i = 0; i < sequence.size() - 1; i++) {
    if ( V[i] > 0) {
      if (V[i + 1] < 0) {
        A[i + 2] = A[i + 1] + 1;
        cout << "=====" << A[i + 2] << " " << endl;
      }
      else {
        A[i + 2] = 1;
      }
    }

    else if (V[i] < 0) {
      if (V[i + 1] > 0) {
        A[i + 2] = A[i + 1] + 1;
        cout << "~~~~~~" << A[i + 2] << " " << endl;
      }
      else {
        A[i + 2] = 1;
      }
    }
  }

  for (int i = 0; i < 6; i++) {
    cout << A[i] << " ";
  }
  cout << endl;
  return Max(A);
}

int main()
{
  int myArr[6] = {1, 7, 4, 1, 2, 5};
  vector<int> seq;
  for (int i = 0; i < 6; i++) {
    cout << myArr[i] << " ";
    seq.push_back(myArr[i]);
  }
  cout << endl;

  cout << LongestZigZag(seq) << endl;

  return 0;
}
