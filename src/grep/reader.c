#include "reader.h"
#include <getopt.h>

void flagE(int argc, char **argv, char *str, char *filename) {
  char *pattern;
  int cflags = 0;
  regex_t reg;
  regmatch_t pm[1];
  const size_t nmatch = 1;
  int status_exec;
  pattern = argv[2];
  regcomp(&reg, pattern, cflags);
  status_exec = regexec(&reg, str, nmatch, pm, 0);
  if (!status_exec) {
    if (argc > 4) {
      printf("%s:%s", filename, str);
      if (str[strlen(str) - 1] != '\n') {
                printf("\n");
      }
    } else {
      printf("%s", str);
      if (str[strlen(str) - 1] != '\n') {
                printf("\n");
      }
    }
  }
  regfree(&reg);
}

void flagI(int argc, char **argv, char *str, char *filename) {
  char *pattern;
  int cflags = REG_ICASE;
  regex_t reg;
  regmatch_t pm[1];
  const size_t nmatch = 1;
  int status_exec;
  pattern = argv[2];
  regcomp(&reg, pattern, cflags);
  status_exec = regexec(&reg, str, nmatch, pm, 0);
  if (!status_exec) {
    if (argc > 4) {
      printf("%s:%s", filename, str);
      if (str[strlen(str) - 1] != '\n') {
                printf("\n");
      }
    } else {
      printf("%s", str);
      if (str[strlen(str) - 1] != '\n') {
                printf("\n");
      }
    }
  }
  regfree(&reg);
}

void flagV(int argc, char **argv, char *str, char *filename) {
  char *pattern;
  int cflags = 0;
  regex_t reg;
  regmatch_t pm[1];
  const size_t nmatch = 1;
  int status_exec;
  pattern = argv[2];
  regcomp(&reg, pattern, cflags);
  status_exec = regexec(&reg, str, nmatch, pm, 0);
  if (status_exec) {
    if (argc > 4) {
      printf("%s:%s", filename, str);
      if (str[strlen(str) - 1] != '\n') {
                printf("\n");
      }
    } else {
      printf("%s", str);
      if (str[strlen(str) - 1] != '\n') {
                printf("\n");
      }
    }
  }
  regfree(&reg);
}

void flagC(char **argv, char *str, int *counter) {
  char *pattern;
  int cflags = 0;
  regex_t reg;
  regmatch_t pm[1];
  const size_t nmatch = 1;
  int status_exec;
  pattern = argv[2];
  regcomp(&reg, pattern, cflags);
  status_exec = regexec(&reg, str, nmatch, pm, 0);
  if (!status_exec) {
    (*counter)++;
  }
  regfree(&reg);
}

void flagL(char **argv, char *str, int *counter) {
  char *pattern;
  int cflags = 0;
  regex_t reg;
  regmatch_t pm[1];
  const size_t nmatch = 1;
  int status_exec;
  pattern = argv[2];
  regcomp(&reg, pattern, cflags);
  status_exec = regexec(&reg, str, nmatch, pm, 0);
  if (!status_exec) {
    *counter = 1;
  }
  regfree(&reg);
}

void flagN(int argc, char **argv, char *str, int *counter_line,
           char *filename) {
  char *pattern;
  int cflags = 0;
  regex_t reg;
  regmatch_t pm[1];
  const size_t nmatch = 1;
  int status_exec;
  pattern = argv[2];
  regcomp(&reg, pattern, cflags);
  status_exec = regexec(&reg, str, nmatch, pm, 0);
  if (!status_exec) {
    if (argc > 4) {
      printf("%s:%d:%s", filename, *counter_line, str);
      if (str[strlen(str) - 1] != '\n') {
                printf("\n");
      }
    } else {
      printf("%d:%s", *counter_line, str);
      if (str[strlen(str) - 1] != '\n') {
                printf("\n");
      }
    }
  }
  regfree(&reg);
}

void no_flags(int argc, char **argv, char *str, char *filename) {
  char *pattern;
  int cflags = 0;
  regex_t reg;
  regmatch_t pm[1];
  const size_t nmatch = 1;
  int status_exec;
  pattern = argv[1];
  regcomp(&reg, pattern, cflags);
  status_exec = regexec(&reg, str, nmatch, pm, 0);
  if (!status_exec) {
    if (argc > 3) {
      printf("%s:%s", filename, str);
      if (str[strlen(str) - 1] != '\n') {
                printf("\n");
      }
    } else {
      printf("%s", str);
      if (str[strlen(str) - 1] != '\n') {
                printf("\n");
      }
    }
  }
  regfree(&reg);
}

void reader(int argc, char **argv, opt *options) {
  FILE *file;
  char str[999];
  char *filename;
  int counter = 0, counter_line = 1;
  for (int index = optind + 1; index < argc; index++) {
    filename = argv[index];
    file = fopen(filename, "r");
    if (file != NULL) {
      if (getc(file) != EOF) {
        fseek(file, 0, SEEK_SET);
        while (fgets(str, 999, file) != NULL) {
          if (options->e) {
              flagE(argc, argv, str, filename);
          } else if (options->i) {
              flagI(argc, argv, str, filename);
          } else if (options->v) {
              flagV(argc, argv, str, filename);
          } else if (options->c) {
              flagC(argv, str, &counter);
          } else if (options->l) {
              flagL(argv, str, &counter);
          } else if (options->n) {
              flagN(argc, argv, str, &counter_line, filename);
              counter_line++;
          } else {
              no_flags(argc, argv, str, filename);
          }
        }
        counter_line = 1;
        if (options->c) {
          if (argc > 4) {
            printf("%s:%d\n", filename, counter);
            counter = 0;
          } else {
            printf("%d\n", counter);
            counter = 0;
          }
        }
        if (options->l) {
          if (counter) {
            printf("%s\n", filename);
            counter = 0;
          }
        }
      } else {
        printf("n/a");
      }
    } else {
      printf("n/a");
    }
    fclose(file);
    file = NULL;
  }
}
