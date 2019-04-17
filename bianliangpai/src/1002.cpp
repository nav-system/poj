#include "1002.h"

int main() {
  int n_telephone_numbers = 0;
  char enter;
  if (2 != std::scanf("%d%c", &n_telephone_numbers, &enter)) {
    return 1;
  }

  std::map<std::string, std::size_t> telephone_numbers;
  for (int i = 0; i < n_telephone_numbers; ++i) {

    // preprocess line input
    std::string telephone_number(telephone_number_length, '\0');
    std::string line;
    std::getline(std::cin, line);
    GetTelephoneNumber(line, telephone_number);

    // search and count
    std::map<std::string, std::size_t>::iterator it =
      telephone_numbers.find(telephone_number);
    if (it != telephone_numbers.end()) {
      ++it->second;
    }
    else {
      telephone_numbers[telephone_number] = 1;
      // telephone_numbers.insert( { telephone_number, 1 } );
    }

  }

  bool have_duplicates = false;
  for (std::map<std::string, std::size_t>::iterator it = telephone_numbers.begin();
       it != telephone_numbers.end(); ++it) {
    if (it->second > 1) {
      have_duplicates = true;
      printf("%s %d\r\n", it->first.c_str(), it->second);
    }
  }
  if (!have_duplicates) {
    printf("No duplicates.\r\n");
  }

  return 0;
}