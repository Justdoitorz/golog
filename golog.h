#ifndef __GOLOG_H__
#define __GOLOG_H__


#define GOLOG_LEVEL_OFF           0
#define GOLOG_LEVEL_FATAL         1
#define GOLOG_LEVEL_ERROR         2
#define GOLOG_LEVEL_WARN          3
#define GOLOG_LEVEL_INFO          4
#define GOLOG_LEVEL_DEBUG         5
#define GOLOG_LEVEL_VERBOSE       6


#ifndef GOLOG_LEVEL
#   define GOLOG_LEVEL    GOLOG_LEVEL_INFO
#endif


#ifdef GOLOG_TAG
#   define GOLOG_CALL(FN, ...)     FN(__VA_ARGS__)
#else 
#   define GOLOG_CALL(FN, ...)     
#endif 

#ifndef FN_GOLOG    
#   define FN_GOLOG  golog_function    
#endif

#if (GOLOG_LEVEL >= GOLOG_LEVEL_FATAL) 
#    define GOLOG_F(fmt, ...)   GOLOG_CALL(FN_GOLOG, GOLOG_LEVEL_FATAL, GOLOG_TAG, fmt, ##__VA_ARGS__)
#else
#    define GOLOG_F(...)
#endif 

#if (GOLOG_LEVEL >= GOLOG_LEVEL_ERROR) 
#    define GOLOG_E(fmt, ...)   GOLOG_CALL(FN_GOLOG, GOLOG_LEVEL_ERROR, GOLOG_TAG, fmt,  ##__VA_ARGS__)
#else
#    define GOLOG_E(...)
#endif 

#if (GOLOG_LEVEL >= GOLOG_LEVEL_WARN) 
#    define GOLOG_W(fmt, ...)   GOLOG_CALL(FN_GOLOG, GOLOG_LEVEL_WARN, GOLOG_TAG, fmt,  ##__VA_ARGS__)
#else
#    define GOLOG_W(...)
#endif 

#if (GOLOG_LEVEL >= GOLOG_LEVEL_INFO) 
#    define GOLOG_I(fmt, ...)   GOLOG_CALL(FN_GOLOG, GOLOG_LEVEL_INFO, GOLOG_TAG, fmt, ##__VA_ARGS__)
#else
#    define GOLOG_I(...)
#endif 

#if (GOLOG_LEVEL >= GOLOG_LEVEL_DEBUG) 
#    define GOLOG_D(fmt, ...)   GOLOG_CALL(FN_GOLOG, GOLOG_LEVEL_DEBUG, GOLOG_TAG, fmt, ##__VA_ARGS__)
#else
#    define GOLOG_D(...)
#endif 

#if (GOLOG_LEVEL >= GOLOG_LEVEL_VERBOSE) 
#    define GOLOG_V(fmt, ...)   GOLOG_CALL(FN_GOLOG, GOLOG_LEVEL_VERBOSE, GOLOG_TAG, fmt, ##__VA_ARGS__)
#else
#    define GOLOG_V(...)
#endif 


#ifdef __cplusplus
extern "C" {
#endif

const char *golog_tostring_lv(unsigned lv);

__attribute__((format(printf, 3, 4)))
int golog_function(unsigned lv, const char *tag, const char *fmt, ...);

#ifdef __cplusplus
}
#endif


#endif

