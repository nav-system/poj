#ifndef __POJ_LOG_H__
#define __POJ_LOG_H__

#include <cstdio>

#ifdef DEBUG
  #ifndef POJ_LOGI
  #define POJ_LOGI(msg, ...)                                              \
    do {                                                                  \
      char buf[52];                                                       \
      sprintf(buf, msg);                                                  \
      printf("[Info][File: %s, Line: %d] %s\n", __FILE__, __LINE__, buf); \
    } while(0);
  #endif //POJ_LOGI
#else //DEBUG
  #define POJ_LOGI(msg, ...)
#endif //DEBUG

#endif //__POJ_LOG_H__