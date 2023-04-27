#include "parser.h"
#include "opt.h"

void parser(int argc, char **argv, opt *options) {
  int opti = 0;
  while ((opti = getopt(argc, argv, "+eivcln")) != -1) {
    switch (opti) {
      break;
    case 'e':
      options->e = 1;
      break;
    case 'i':
      options->i = 1;
      break;
    case 'v':
      options->v = 1;
      break;
    case 'c':
      options->c = 1;
      break;
    case 'l':
      options->l = 1;
      break;
    case 'n':
      options->n = 1;
      break;
    }
  }
}
