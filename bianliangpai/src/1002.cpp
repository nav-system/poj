#include "1002.h"

int main() {
  int n_telephone_numbers = 0;
  char enter;
  if (2 != std::scanf("%d%c", &n_telephone_numbers, &enter)) {
    return 1;
  }

  std::vector<std::string>
    telephone_numbers(n_telephone_numbers,
                      std::string(telephone_number_length, '\0'));

  ReadTelephoneNumbersFromConsole(telephone_numbers);

  return 0;
}