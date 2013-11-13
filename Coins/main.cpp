#include <iostream>

using namespace std;

int Coins[3] = {1, 3, 5};

int DynamicProgramming(int sum, int coins[])
{
  int i, j;
  int MinCoins[sum + 1];
  MinCoins[0] = 0;
  for (int k = 1; k <= sum; k++) {
    MinCoins[k] = 777;
  }
  for (i = 1; i <= sum; i++) {
  // always find the minimum Coins
    for (j = 0; j < 3; j++) {
      if (coins[j] <= i && (MinCoins[i - coins[j]] + 1) < MinCoins[i]) {
  //      cout << i << ":...We tried coins " << coins[j] << endl;
        MinCoins[i] = MinCoins[i - coins[j]] + 1;
      }
    }
  }
  return MinCoins[sum];
}

int Greeding(int sum, int coins[])
{
  int CoinsNum;
  for (int i = 2; i >= 0; i--) {
    while (sum >= coins[i]) {
      sum -= coins[i];
      CoinsNum++;
   //   cout << "coin " << i << endl;
    }
  }
  return CoinsNum;
}

int main()
{
    int Price;
    int Diff;
    for (Price = 1; Price < 100; Price++) {
      Diff = Greeding(Price, Coins) - DynamicProgramming(Price, Coins);
      if (Diff != 0) {
        cout << "Price: " << Price << endl;
      }
    }
    return 0;
}
