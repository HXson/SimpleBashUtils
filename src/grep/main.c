#include "opt.h"
#include "parser.h"
#include "reader.h"

int main(int argc, char *argv[]) {
  opt option = {0};
  parser(argc, argv, &option);
  reader(argc, argv, &option);
}
