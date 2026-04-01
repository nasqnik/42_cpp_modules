# CPP07 Module

## Overview

This module introduces C++ templates through generic functions, template iteration utilities, and a templated dynamic array class with bounds checking and deep-copy behavior.

## Build

Each exercise directory contains its own `Makefile`.

```bash
cd <exercise folder>
make
```

## Contents

This module contains 3 exercises: `ex00` - `ex02`.

- [ex00 - Start with a few functions](#ex00)
- [ex01 - Iter](#ex01)
- [ex02 - Array](#ex02)

<a id="ex00"></a>
### ex00 - Start with a few functions

**Learning objective:** write reusable function templates operating on multiple types.

**Run:**

```bash
make
./ex00
```

**Behavior:**

Implements templated utility functions:

- `swap(T&, T&)`
- `min(const T&, const T&)`
- `max(const T&, const T&)`

The test demonstrates the same functions with `int` and `std::string` values.

<a id="ex01"></a>
### ex01 - Iter

**Learning objective:** apply function templates to arrays with support for const and non-const elements.

**Run:**

```bash
make
./ex01
```

**Behavior:**

Implements `iter` as a template function that applies a callback to each element of an array.

The test covers:

- printing integer arrays
- mutating integer arrays (increment)
- iterating const arrays
- mutating string arrays (uppercase conversion)

<a id="ex02"></a>
### ex02 - Array

**Learning objective:** implement a templated container class with safe indexing and canonical copy semantics.

**Run:**

```bash
make
./ex02
```

**Behavior:**

Implements a generic `Array<T>` class with:

- default and sized constructors
- deep-copy constructor and assignment operator
- `size()` accessor
- bounds-checked `operator[]` that throws on invalid index

The test validates empty/sized arrays, out-of-bounds exceptions, deep-copy independence, const access, and usage with multiple types.
