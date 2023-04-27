#include "opt.h"
#include "parser.h"
#include "reader.h"

int main(int argc, char **argv) {
  opt option = {0};
  parser(argc, argv, &option);
  if (option.b) {
    option.n = 0;
  }
  reader(argc, argv, &option);
}
