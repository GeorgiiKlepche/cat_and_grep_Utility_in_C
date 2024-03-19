#!/bin/bash

./s21_grep -c for s21_grep.c > s21_grep.txt
grep -c for s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt

./s21_grep -i for s21_grep.c > s21_grep.txt
grep -i for s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt

./s21_grep -v for s21_grep.c > s21_grep.txt
grep -v for s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt

./s21_grep -l for s21_grep.c > s21_grep.txt
grep -l for s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt

./s21_grep -n for s21_grep.c > s21_grep.txt
grep -n for s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt

./s21_grep -h for s21_grep.c > s21_grep.txt
grep -h for s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt

./s21_grep -s for s21_grep.c > s21_grep.txt
grep -s for s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt

./s21_grep -o for s21_grep.c > s21_grep.txt
grep -o for s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt