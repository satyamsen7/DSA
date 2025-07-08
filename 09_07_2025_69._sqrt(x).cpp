#include <iostream>

int mySqrt(int x) {
  if (x == 0) return 0;
  if (x == 1) return 1;

  long long low = 1, high = x / 2;
  long long ans = 1;

  while (low <= high) {
    long long mid = low + (high - low) / 2;
    long long square = mid * mid;

    if (square == x) {
      return (int)mid;
    } else if (square < x) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return (int)ans;
}