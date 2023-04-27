#ifndef SRC_GREP_READER_H_
#define SRC_GREP_READER_H_
#include "opt.h"
#include <regex.h>
#include <stdio.h>
#include <string.h>
void reader(int argc, char **argv, opt *options);
void flagE(int argc, char **argv, char *str, char *filename);
void flagI(int argc, char **argv, char *str, char *filename);
void flagV(int argc, char **argv, char *str, char *filename);
void flagC(char **argv, char *str, int *counter);
void flagL(char **argv, char *str, int *counter);
void flagN(int argc, char **argv, char *str, int *counter_line, char *filename);
void no_flags(int argc, char **argv, char *str, char *filename);
#endif // SRC_GREP_READER_H_
