/**
 * General utilities for string checking, assertions, etc.
 */

#ifndef FC_UTIL_H
#define FC_UTIL_H

#include <stdio.h> /* fprintf, stderr */
#include <stdlib.h> /* exit */
#include <string.h> /* strlen, strncmp */

/**
 * General error codes.
 */
typedef enum {

    FC_SUCCESS, /* Everything was fine. */
    FC_FAILED,  /* Some unknown error. */
    FC_NULLPTR, /* A null pointer was passed in. */
    FC_MEM,     /* A malloc failed. */
    FC_DUP,     /* A duplicate of something */

} fc_status_t;

/**
 * Internal thing for varargs
 */
#define _LF_VA_ARGS(...) , ##__VA_ARGS__

/**
 * Exit with an error message.
 * @param msg the format (does not need a newline at the end)
 * @param ... format parameters
 */
#define FC_ERROR(msg, ...)                                                    \
    do {                                                                      \
        fprintf(stderr, "Error: fabric: " msg "\n" _LF_VA_ARGS(__VA_ARGS__)); \
        exit(-FC_FAILED);                                                     \
    } while (0)


/**
 * Display a warning but keep execution going.
 * @param msg the format (does not need a newline at the end)
 * @param ... format parameters
 */
#define FC_WARN(msg, ...)                                                      \
    do {                                                                       \
        fprintf(stderr, "Warning: fabric: " msg "\n" _LF_VA_ARGS(__VA_ARGS__));\
    } while (0)

/**
 * Make sure that something is true. If not, exit with an error.
 */
#define FC_ASSERT(cond)                               \
    do {                                              \
        if (!(cond)) {                                \
            FC_ERROR(                                 \
                "assertion failed: "                  \
                "File \"%s\", "                       \
                "line %d:\n\t%s",                     \
                __FILE__, __LINE__,                   \
                #cond                                 \
            );                                        \
        }                                             \
    } while (0)

/**
 * "Safe" string comparison - takes in a length
 */
#define S_STREQ(x, y, l) ( !strncmp( (x), (y), (l) ) )

/**
 * "Unsafe" - uses the length of the SECOND one
 */
#define U_STREQ(x, y) ( !strncmp( (x), (y), strlen((y)) ) )

#endif /* FC_UTIL_H */
