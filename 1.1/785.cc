#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

const int N = 1e5 + 10;
int x[N];

void QuickSort(int *begin, int *end) {
  int size = end - begin;
  if (size <= 1)
    return;
  int *pivot = begin + rand() % size;
  std::swap(*begin, *pivot);
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
  QuickSort(begin, i);
  QuickSort(j, end);
}

int main() {
  srand(time(NULL));
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x[i]);
  }
  QuickSort(x, x + n);
  for (int i = 0; i < n; ++i) {
    printf("%d ", x[i]);
  }
}
