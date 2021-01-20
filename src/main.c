/**
 * Main driver code for the fabric interpreter, compiles the source file into
 * an abstract representation and executes it until stopped or the end of 
 * bytecodes is reached.
 */

#include <stdio.h>     /* fprintf, printf, stderr */
#include <stdlib.h>    /* exit */

#include <argparse.h>  /* fc_parse_all */
#include <util.h>      /* FC_FAILURE, etc. */

/**
 * Display help message without running anything.
 * @param args the arguments to parse
 */
void _fc_help(fc_args_t args) {

	if (args.empty) {
		fprintf(stderr, "fabric: expected arguments (try --help)\n");
		exit(-FC_FAILED);
	}

	if (args.vinfo) {
		printf("fabric: version 0.0.0\n");
		exit(FC_SUCCESS);
	}

	if (args.args) {
		printf(
			"--args / --info / --help : display this message\n"
			"--version                : display version number\n"
			"[file]                   : run the given file\n"
		);
		exit(FC_SUCCESS);
	}

}

/**
 * Main function for Fabric.
 * @param argc the argument count
 * @param argv the arguments themselves
 * @return success code of the program itself
 * @author Adam Hutchings
 */
int main(int argc, char** argv) {

	/* File name unneeded */
	--argc, ++argv;

	fc_args_t pargs = fc_parse_all(argc, argv);

	_fc_help(pargs);

	/* We need to run the file because _fc_help exits otherwise */

	/* TODO interpret the file */

}
