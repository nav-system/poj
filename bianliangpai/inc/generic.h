#ifndef __GENERIC_H__
#define __GENERIC_H__

#include <cstdio>
#include <cstdlib>
#include <stdexcept>
#include <algorithm>


// Container1.size() must bigger than Container2.size()
template <
  typename T,
  template <typename = T> class Container1,
  template <typename = T> class Container2
>
bool __ContainerCompare(const typename Container1<T>::iterator c1_begin,
                        const typename Container1<T>::iterator c1_end,
                        const typename Container2<T>::iterator c2_begin) {
  try {
    typename Container1<T>::iterator c1_it = c1_begin;
    typename Container2<T>::iterator c2_it = c2_begin;
    while (c1_it != c1_end) {
      if (*c1_it != *c2_it) {
        return false;
      }
      else {
        ++c1_it;
        ++c2_it;
      }
    }
    return true;
  }
  catch (const std::exception& e) {
    printf("File: %s, Line: %d, Reason: %s\n", __FILE__, __LINE__, e.what());
    exit(1);
  }
}

#endif // __GENERIC_H__