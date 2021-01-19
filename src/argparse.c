#include "argparse.h"

fc_status_t fc_parse_one(fc_args_t* args, char* next) {

    if (next == NULL) return -FC_NULLPTR; /* Should never happen */

    if (strlen(next) == 6) {

        /* --help or --info or --args */
        if (
            U_STREQ(next, "--help")
         || U_STREQ(next, "--info")
         || U_STREQ(next, "--args")) {
            args->args = true;
            goto out;
        }

        /* More 6-letter flags here later */

    }

    if (strlen(next) == 9) {

        /* --version */
        if (U_STREQ(next, "--version")) {
            args->vinfo = true;
            goto out;
        }

    }

    /* Now we search for a file. */

    /* Can't specify multiple files */
    if (args->file != NULL) {
        return -FC_DUP;
    }

    args->file = next;

    out:
    /* This has been processed, and everything is good. */
    args->empty = false;
    return FC_SUCCESS;

}

fc_args_t fc_parse_all(int argc, char** argv) {

    fc_args_t ret;

    for (int i = 0; i < argc; i++) {

        int st = fc_parse_one(&ret, argv[i]);

        /* Check the status */
        if (st < 0) {
            switch (-st) {
                case FC_FAILED:
                    FC_ERROR("unknown error while parsing arguments.");
                case FC_NULLPTR:
                    FC_ERROR("internal error (fc_parse_one given nullptr)");
                case FC_MEM:
                    FC_ERROR("memory exhausted.");
                case FC_DUP:
                    FC_ERROR("duplicate argument given: %s\n", argv[i]);
            }
        }

    }

    return ret;

}
