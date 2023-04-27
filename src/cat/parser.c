#include "parser.h"

void parser(int argc, char **argv, opt *options) {
  int opti = 0;
  int option_index = 0;
  static struct option long_options[] = {{"number-nonblank", 0, 0, 'b'},
                                         {"number", 0, 0, 'n'},
                                         {"squeeze-blank", 0, 0, 's'},
                                         {0, 0, 0, 0}};
  while ((opti = getopt_long(argc, argv, "+benstvTE", long_options,
                             &option_index)) != -1) {
    switch (opti) {
      break;
    case 'b':
      options->b = 1;
      break;
    case 'e':
      options->e = 1;
      options->v = 1;
      break;
    case 'n':
      options->n = 1;
      break;
    case 's':
      options->s = 1;
      break;
    case 't':
      options->t = 1;
      options->v = 1;
      break;
    case 'v':
      options->v = 1;
      break;
    case 'T':
      options->t = 1;
      options->v = 0;
      break;
    case 'E':
      options->e = 1;
      options->v = 0;
      break;
    }
  }
}
