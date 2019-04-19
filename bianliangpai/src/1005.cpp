#include <cstdio>
#include <cstdlib>
#include <stdexcept>

bool IsCurrentAreaContainsInputPoint(float x, float y, float current_area) {
  try {
    const static float pi = 3.1415926f;
    if (current_area*2 >= (x*x+y*y)*pi) {
      return true;
    }
    else {
      return false;
    }
  }
  catch (const std::exception& e) {
    printf("File: %s, Line: %d, Reason: %s\n", __FILE__, __LINE__, e.what());
    exit(1);
  }
}

int main() {
  int data_sets_num;
  std::scanf("%d", &data_sets_num);
  for (int i = 0; i < data_sets_num; ++i) {
    float x, y;
    scanf("%f %f", &x, &y);

    const static float delta_area = 50.f;
    float current_area = 0.f;
    int years = 0;
    while (!IsCurrentAreaContainsInputPoint(x, y, current_area)) {
      ++years;
      current_area += delta_area;
    }
    printf("Property %d: This property will begin eroding in year %d.\r\n",
           i+1, years);
  }
  printf("END OF OUTPUT.\r\n");
  return 0;
}