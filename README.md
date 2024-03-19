# GrepUtility

GrepUtility is a simple command-line utility written in C, that searches files for lines matching a regular expression pattern and prints them to the console.

## Build

To build the GrepUtility, please make sure you have the following dependencies installed:

- GCC compiler
- PCRE libraries

### Makefile Targets

- `all`: build the program
- `clean`: remove build and library files
- `test`: runs tests
- `clang-format`: format the source code using clang-format

To build the utility, run the following commands:

```sh
make
```

## Usage

To use grep, run the following command:

```sh
./grep [options] pattern [file_name]
```

Here are the available options:

- `-e pattern`: Use `pattern` as the search pattern.
- `-i`: Ignore case distinctions in both the pattern and the input files.
- `-v`: Invert the sense of matching, to select non-matching lines.
- `-c`: Only output the count of matching lines.
- `-l`: Only output the names of files containing at least one matching line.
- `-n`: Prefix each line of output with its 1-based line number within its input file.
- `-h`: Never print filename headers (i.e. file names) with output lines.
- `-s`: Suppress error messages about nonexistent or unreadable files.
- `-f file`: Obtain patterns from file, one per line.

## Development

Integration tests cover all flag variants and input values, based on a comparison with the behavior of real Bash utilities.

# Cat Utility in C

This project is an implementation of the `cat` utility in C, based on the C11 standard and compiled with gcc. The `cat` utility is used to display, combine, and create text files. This implementation supports all flags specified in the project requirements, including the GNU versions.

## Makefile Targets

- `all`: build the program
- `clean`: remove build and library files
- `test`: runs tests
- `clang-format`: format the source code using clang-format

To build the utility, run the following commands:

```sh
make
```

## Usage

The `cat` utility takes one or more file names as arguments. It reads each file in sequence and writes its contents to the standard output. If no files are specified, it reads from the standard input.

The following flags are supported:

- `-b` (`--number-nonblank`): Numbers only non-empty lines.
- `-e` (implies `-v`, GNU only: `-E` the same, but without implying `-v`): Displays end-of-line characters as `$`.
- `-n` (`--number`): Numbers all output lines.
- `-s` (`--squeeze-blank`): Squeezes multiple adjacent blank lines.
- `-t` (implies `-v`, GNU: `-T` the same, but without implying `-v`): Displays tabs as `^I`.

For example, to display the contents of a file named `example.txt` and number all output lines, run:

```
./cat -n example.txt
```

To display the contents of multiple files and display end-of-line characters as `$`, run:

```
./cat -e file1.txt file2.txt file3.txt
```

## Dependencies

This implementation does not use any third-party libraries. It only uses the standard C libraries.

## Development

Integration tests cover all flag variants and input values, based on a comparison with the behavior of real Bash utilities.