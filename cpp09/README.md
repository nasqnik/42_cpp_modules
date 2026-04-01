# CPP09 Module

## Overview

This module introduces STL container-driven problem solving through practical parsing and algorithmic exercises: historical data lookup, stack-based expression evaluation, and performance-oriented hybrid sorting.

## Build

Each exercise directory contains its own `Makefile`.

```bash
cd <exercise folder>
make
```

## Contents

This module contains 3 exercises: `ex00` - `ex02`.

- [ex00 - Bitcoin Exchange](#ex00)
- [ex01 - Reverse Polish Notation](#ex01)
- [ex02 - PmergeMe](#ex02)

<a id="ex00"></a>
### ex00 - Bitcoin Exchange

**Learning objective:** parse structured files, validate date/value input, and perform historical lookup with `std::map`.

**Run:**

```bash
make
./btc <input_file>
```

**Behavior:**

Loads exchange-rate history from `data.csv` and processes an input file with lines in `date | value` format.

- validates file header and line format
- validates dates (`YYYY-MM-DD`) including leap-year checks
- validates numeric values (non-negative and <= 1000)
- uses closest previous available exchange rate when exact date is missing
- prints per-line errors for invalid entries and continues processing

**Input format example:**

```text
date | value
2011-01-03 | 3
2011-01-09 | 2.5
```

**Output example:**

```text
2011-01-03 => 3 = 0.9
2011-01-09 => 2.5 = 0.775
```

<a id="ex01"></a>
### ex01 - Reverse Polish Notation

**Learning objective:** evaluate postfix arithmetic expressions using a stack and strict token validation.

**Run:**

```bash
make
./RPN "<expression>"
```

**Behavior:**

Evaluates a space-separated RPN expression using `std::stack`.

- accepts single-digit operands and operators `+`, `-`, `*`, `/`
- validates token characters and expression structure
- reports `Error` for invalid tokens, malformed expressions, or division by zero
- prints the final numeric result when evaluation succeeds

**Usage example:**

```bash
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
```

<a id="ex02"></a>
### ex02 - PmergeMe

**Learning objective:** implement and benchmark a Ford-Johnson-style merge-insert sorting approach across different STL containers.

**Run:**

```bash
make
./PmergeMe <positive integers...>
```

**Behavior:**

Parses positive integer arguments, then sorts the same sequence with two container implementations:

- `std::vector<int>`
- `std::deque<int>`

The program prints:

- sequence before sorting
- sequence after sorting
- processing time in microseconds for vector and deque paths

Input is validated (digits only, positive range, no invalid values), and invalid input reports `Error`.
