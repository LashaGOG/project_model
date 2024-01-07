# Polynom Multiplicaton Project

## Overview

This project implements and compares naive and fft based multiplication of 2 polynoms.

## Dependencies

- GCC Compiler for C programs.
- python3 if you want to visualise the graphs of comparaison of two algorithms.

## Compilation

The project contains one main program.

To compile the program, run:

```bash
make main
```

## Execution

After the compilation you can execute the program as follows :

```bash
./main
```

In main.c, define POLY_SIZE_ANY as 1 if you need to handle polynomials of any degree. Define it as 0 for polynomials of degrees that are powers of 2.

# Graphical rendering

For graphical rendering of simulation results run :

```bash
python3 [filename.txt]
```

## Cleaning Build Files

To clean up the build files and remove executables, you can use the clean target in the Makefile:

```bash
make clean
```

## Authors@

- **CHEN Virginie** - [Virgs13](https://github.com/Virgs13)
- **GOGRITCHIANI Lasha** - [LashaGOG](https://github.com/LashaGOG)
- **TAN Philippe** - [superfiloche](https://github.com/superfiloche)
