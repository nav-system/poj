#include <cstdio>

int main() {
  const static int months = 12;
  float sum = 0.f;
  for (int i = 0; i < months; ++i) {
    float balance;
    std::scanf("%f", &balance);
    sum += balance;
  }
  float avg = sum / months;
  avg = (float)((int)(avg*100))/100;
  printf("$%.2f\n", avg);
}