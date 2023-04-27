#include "reader.h"
#include <unistd.h> //>

void flagS(char symbol, int *pr_previous_symbol, int *previous_symbol,
           opt *options) {
  if (options->s) {
    if ((symbol != 10) || (*previous_symbol != 10) ||
        (*pr_previous_symbol != 10)) {
      *pr_previous_symbol = *previous_symbol;
      flagNB(symbol, previous_symbol, options);
      *previous_symbol = symbol;
    }
  } else {
    flagNB(symbol, previous_symbol, options);
  }
}

void flagNB(char symbol, int *previous_symbol, opt *options) {
  static int index = 1;
  if (options->n) {
    if (*previous_symbol == 10) {
      printf("%6d\t", index++);
      flagTE(symbol, options);
      *previous_symbol = symbol;
    } else {
      flagTE(symbol, options);
      *previous_symbol = symbol;
    }
  } else if (options->b) {
    if ((*previous_symbol == 10) && (symbol != 10)) {
      printf("%6d\t", index++);
      *previous_symbol = symbol;
      flagTE(symbol, options);
    } else {
      *previous_symbol = symbol;
      flagTE(symbol, options);
    }
  } else {
    flagTE(symbol, options);
  }
}

void flagTE(char symbol, opt *options) {
  if ((options->t) && (options->e)) {
    if (symbol == 10) {
      printf("$\n");
    } else if (symbol == 9) {
      printf("^I");
    } else {
      flagV(symbol, options);
    }
  } else if (options->t) {
    if (symbol == 9) {
      printf("^I");
    } else {
      flagV(symbol, options);
    }
  } else if (options->e) {
    if (symbol == 10) {
      printf("$\n");
    } else {
      flagV(symbol, options);
    }
  } else {
    flagV(symbol, options);
  }
}

void flagV(char symbol, opt *options) {
  if (options->v) {
    if ((symbol < 32) || (symbol > 126)) {
      printf("%s", spec_symbols[(int)symbol]);
    } else {
      printf("%c", symbol);
    }
  } else {
    printf("%c", symbol);
  }
}

void reader(int argc, char **argv, opt *options) {
  FILE *file;
  char symbol;
  int previous_symbol = 10;
  int pr_previous_symbol = 0;
  for (int i = optind; i < argc; i++) {
    file = fopen(argv[i], "r");
    if (file != NULL) {
      if (getc(file) != EOF) {
        fseek(file, 0, SEEK_SET);
        while ((symbol = getc(file)) != EOF) {
          flagS(symbol, &pr_previous_symbol, &previous_symbol, options);
        }
      } else {
        printf("n/a");
      }
    } else {
      printf("n/a");
    }
    fclose(file);
  }
}
