#include "cat.h"

int main(int argc, char **argv) {
  arguments opt = {0, 0, 0, 0, 0, 0, 0, 0};
  if (argc > 1) {
    int error = 1;
    error = parser(argc, &opt, argv);

    if (error == 1) {
      int i = 1, count = 1, j = 1;
      int *lastChar = (int *)malloc(1 * sizeof(int));
      *lastChar = ' ';
      while (i < argc) {
        if (argv[i][0] != '\0') {
          count = print_file(opt, argv[i], count, lastChar);
          j++;
        }
        i++;
      }
      free(lastChar);
    } else {
      printf("cat: invalid option ");
    }
  }
}

int parser(int countArg, arguments *opt, char **str) {
  int result = 1, count = 1;

  while (count < countArg && result == 1) {
    if (str[count][0] == '-' && str[count][1] == '-') {
      if (strcmp(str[count], "--number-nonblank") == 0) {
        opt->b = 1;
        str[count] = "";
      } else if (strcmp(str[count], "--number") == 0) {
        opt->n = 1;
        str[count] = "";
      } else if (strcmp(str[count], "--squeeze-blank") == 0) {
        opt->s = 1;
        str[count] = "";
      } else {
        result = 0;
      }
    } else if (str[count][0] == '-') {
      for (size_t j = 1; j < strlen(str[count]); j++) {
        if (strchr(str[count], 'b')) {
          opt->b = 1;
        }
        if (strchr(str[count], 'e')) {
          opt->e = 1;
        }
        if (strchr(str[count], 'n')) {
          opt->n = 1;
        }
        if (strchr(str[count], 's')) {
          opt->s = 1;
        }
        if (strchr(str[count], 't')) {
          opt->t = 1;
        }
        if (strchr(str[count], 'v')) {
          opt->v = 1;
        }
        if (strchr(str[count], 'E')) {
          opt->E = 1;
        }
        if (strchr(str[count], 'T')) {
          opt->T = 1;
        }

        if (str[count][j] == 'b' || str[count][j] == 'e' ||
            str[count][j] == 'n' || str[count][j] == 's' ||
            str[count][j] == 't' || str[count][j] == 'v' ||
            str[count][j] == 'E' || str[count][j] == 'T') {
        } else {
          result = 0;
        }
      }
      str[count] = "";
    }
    count++;
  }
  return result;
}

int print_file(arguments opt, char *file_name, int count, int *lastChar) {
  FILE *fp = NULL;
  int c = 0, i = 1;
  int prev_c = '\n';
  int is_squeeeze = 0;

  if ((fp = fopen(file_name, "r"))) {
    while ((c = getc(fp)) != EOF) {
      if (opt.s && c == '\n' && is_squeeeze) continue;
      is_squeeeze = (prev_c == '\n' && c == '\n') ? 1 : 0;

      if (opt.n && prev_c == '\n' && !opt.b) {
        if (*lastChar == '\n') {
          printf("%6d\t", count++);
        }
        if (count == 1 && c != ' ') {
          printf("%6d\t", count++);
        }
        print_unprinted(opt, c);
        *lastChar = c;
      } else if (opt.b && prev_c == '\n' && c != '\n') {
        if (*lastChar == '\n') {
          printf("%6d\t", count++);
        }

        if (count == 1) {
          printf("%6d\t", count++);
        }
        print_unprinted(opt, c);
        *lastChar = c;
      } else {
        print_unprinted(opt, c);
        *lastChar = c;
      }
      i++;
      prev_c = c;
    }

    fclose(fp);
  } else {
    fprintf(stderr, "File open failed: %s.\n", file_name);
  }
  return count;
}

void print_unprinted(arguments opt, int c) {
  if (opt.v || opt.e || opt.t) {
    if (c < 32 && c != 9 && c != 10) {
      printf("^%c", c + 64);
    } else if (c == 127) {
      printf("^?");
    } else if (c > 127 && c < 160) {
      printf("M-^%c", c - 64);
    } else if (c >= 160 && c != 255) {
      printf("M-%c", c - 128);
    } else if (c == 255) {
      printf("M-^?");
    } else {
      print_char(opt, c);
    }
  } else {
    print_char(opt, c);
  }
}

void print_char(arguments opt, int c) {
  if ((opt.t || opt.T) && c == 9) {
    printf("^I");
  } else if ((opt.e || opt.E) && c == '\n') {
    printf("$\n");
  } else {
    putchar(c);
  }
}
