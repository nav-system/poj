#ifndef __1002_H__
#define __1002_H__

#include <vector>
#include <string>
#include <mutex>

std::mutex telephone_numbers_mutex;

void DirectoryTreeThreadEntry(const std::vector<std::string>& telephone_numbers) {
  try {
    return;
  }
  catch (std::exception& e) {
    printf("File: %s, Line: %d, Reason: %s\n", __FILE__, __LINE__, e.what());
    exit(1);
  }
}

#endif // __1002_H__