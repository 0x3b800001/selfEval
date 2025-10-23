#include <iostream>

int main() {
  freopen("apb.in", "r", stdin);
  freopen("apb.out", "w", stdout);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int a, b;
  std::cin >> a >> b;
  std::cout << a + b << '\n';
  return 0;
}