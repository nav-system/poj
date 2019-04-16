#define DEBUG_ON 0

#define DEBUG_INFO(...) \
    if(DEBUG_ON) \
        do          \
        {           \
            printf(__VA_ARGS__);\
        }while(0)

#define CHAR_TO_INT(a) \
    ((a)-'0')

#define INT_TO_CHAR(a) \
    ((a)+'0')

#define result_t int
#define SUCCESS 0
#define ERR_FAILURE 1
