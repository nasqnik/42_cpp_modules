# CPP08 Module

## Overview

This module introduces STL containers and algorithms in C++, focusing on generic search in containers, span computations over numeric sets, and extending container adaptors with iterator access.

## Build

Each exercise directory contains its own `Makefile`.

```bash
cd <exercise folder>
make
```

## Contents

This module contains 3 exercises: `ex00` - `ex02`.

- [ex00 - Easy find](#ex00)
- [ex01 - Span](#ex01)
- [ex02 - Mutated abomination](#ex02)

<a id="ex00"></a>
### ex00 - Easy find

**Learning objective:** implement a generic algorithm helper for STL-like containers.

**Run:**

```bash
make
./ex00
```

**Behavior:**

Implements `easyfind` as a template function that searches for an integer in a container and returns an iterator to the found element.

- works with mutable and const containers
- throws an exception when the value is not found

The test demonstrates usage with `std::vector` and `std::list`, including success and failure cases.

<a id="ex01"></a>
### ex01 - Span

**Learning objective:** manage a bounded numeric collection and compute minimal/maximal pairwise differences.

**Run:**

```bash
make
./ex01
```

**Behavior:**

Implements `Span` with:

- capacity-limited number storage (`addNumber`)
- shortest distance between any two stored numbers (`shortestSpan`)
- longest distance between min and max values (`longestSpan`)
- range insertion overload using iterators

The test covers the subject example, insertion overflow handling, range insertion, and large random datasets.

<a id="ex02"></a>
### ex02 - Mutated abomination

**Learning objective:** extend `std::stack` behavior by exposing iterators while preserving stack operations.

**Run:**

```bash
make
./ex02
```

**Behavior:**

Implements `MutantStack`, a stack-like container adaptor with iterator support:

- `begin()` / `end()`
- `rbegin()` / `rend()`
- const iterator variants

The test reproduces the subject scenario, compares behavior with `std::list`, and checks reverse iteration, copy construction, and assignment.
