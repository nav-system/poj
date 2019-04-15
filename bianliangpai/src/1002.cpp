#include <cstdio>
#include <string>
#include <vector>

int main() {
  int n_telephone_numbers = 0;
  std::scanf("%d", &n_telephone_numbers);

  const static int telephone_number_length = 7;

  std::vector<std::string>
    telephone_numbers(n, std::string(telephone_number_length, '\0'));

  // create dictory-tree thread
  std::thread dictory_tree_thread(DictoryTreeThreadEntry, telephone_numbers);

  // preprocessing input telephone number format
  // TODO: use function here
  for (std::vector::iterator it = telephone_numbers.begin();
       it != telephone_numbers.end();
       ++it) {
    for (int telephone_number_it = 0;
         telephone_number_it < telephone_number_length; ) {
      char ch;
      std::getc(&ch);
      if (ch != '-') {
        it->push_back(ch);
        ++telephone_number_it
      }
      else {
        break;
      }
    }
  }

  return 0;
}