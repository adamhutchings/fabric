/**
 * Main driver code for the fabric interpreter, compiles the source file into
 * an abstract representation and executes it until stopped or the end of 
 * bytecodes is reached.
 */

#include <argparse.h>  /* fc_parse_all */

/**
 * Main function for Fabric.
 * @param argc the argument count
 * @param argv the arguments themselves
 * @return success code of the program itself
 * @author Adam Hutchings
 */
int main(int argc, char** argv) {

	fc_args_t pargs = fc_parse_all(argc, argv);

}
