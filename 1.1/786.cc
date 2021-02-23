#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 1e5 + 10;
int x[N];

int QuickSelect(int *begin, int *end, int target) {
  int size = end - begin;
  int *pivot = begin + rand() % size;
  swap(*begin, *pivot);

  int *i = begin, *j = begin + 1, *k = begin + 1;
  for (; k != end; ++k) {
    if (*k < *i) {
      swap(*k, *j);
      swap(*j, *i);
      ++i, ++j;
    } else if (*k == *i) {
      swap(*k, *j);
      ++j;
    }
  }

  if (target < i - begin) {
    return QuickSelect(begin, i, target);
  } else if (target >= j - begin) {
    return QuickSelect(j, end, target - (j - begin));
  } else {
    return *(begin + target);
  }
}

int main() {
  srand(time(NULL));
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x[i]);
  }
  printf("%d\n", QuickSelect(x, x + n, k - 1));
}
