/**
 * Parsing arguments to extract all of the info
 */

#ifndef FC_ARGPARSE_H
#define FC_ARGPARSE_H

#include <stdbool.h> /* bool */

#include <util.h> /* status, streq, error, etc */

/**
 * A structure holding all argument information.
 */
typedef struct {

    bool  vinfo; /* Show version info? */
    bool  args;  /* Display all arguments? */
    char* file;  /* Which file to run */
    bool  empty; /* Whether any arguments have been parsed */

} fc_args_t;

/**
 * Parse a single argument into a structure.
 * @param args the argument structure to fill
 * @param next the string to fill with
 * @return the error code (or hopefully success)
 */
fc_status_t fc_parse_one(fc_args_t* args, char* next);

/**
 * Parse all command line arguments.
 * @param argc the argument count
 * @param argv the arguments themselves
 * @return the argument structure
 */
fc_args_t fc_parse_all(int argc, char** argv);

#endif /* FC_ARGPARSE_H */
