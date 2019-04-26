#ifndef __GENERIC_H__
#define __GENERIC_H__

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <algorithm>


template<
  typename T = std::string,
  template <typename = T, typename = std::allocator<T>> class SequenceContainer
>
void Split(std::string s, const std::string& delimiter,
           SequenceContainer<std::string>& sc) {
  try {
    std::size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        sc.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    sc.push_back(s);
  }
  catch (const std::exception& e) {
    std::cerr << "File: " << __FILE__ << ", Line: " << __LINE__
              << ", Reason: " << e.what() << std::endl;
    exit(1);
  }
}

#endif // __GENERIC_H__