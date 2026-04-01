# CPP02 Module

## Overview

This module introduces ad-hoc polymorphism in C++ through operator overloading and Orthodox Canonical Form, using a fixed-point number class and a geometric point-in-triangle check.

## Build

Each exercise directory contains its own `Makefile`.

```bash
cd <exercise folder>
make
```

## Contents

This module contains 4 exercises: `ex00` - `ex03`.

- [ex00 - My First Class in Orthodox Canonical Form](#ex00)
- [ex01 - Towards a More Useful Fixed-Point Number Class](#ex01)
- [ex02 - Now We're Talking](#ex02)
- [ex03 - BSP](#ex03)

<a id="ex00"></a>
### ex00 - My First Class in Orthodox Canonical Form

**Learning objective:** implement a class in Orthodox Canonical Form (default constructor, copy constructor, copy assignment operator, destructor).

**Run:**

```bash
make
./fixed
```

**Behavior:**

Implements a basic `Fixed` class that stores an integer raw fixed-point value and exposes:

- `getRawBits()`
- `setRawBits()`

The test checks object creation, copy construction, assignment, and raw value access.

**Output example:**

```bash
./fixed
0
0
0
```

<a id="ex01"></a>
### ex01 - Towards a More Useful Fixed-Point Number Class

**Learning objective:** add numeric conversions and stream output for a fixed-point class.

**Run:**

```bash
make
./fixed2
```

**Behavior:**

Extends `Fixed` with:

- constructors from `int` and `float`
- conversion methods `toInt()` and `toFloat()`
- overloaded output operator (`operator<<`) for readable printing

The test prints instances as fixed-point values and as converted integer/float values.

<a id="ex02"></a>
### ex02 - Now We're Talking

**Learning objective:** implement full operator overloading for arithmetic, comparison, and increment/decrement.

**Run:**

```bash
make
./fixed3
```

**Behavior:**

Adds support for:

- comparison operators (`<`, `<=`, `>`, `>=`, `==`, `!=`)
- arithmetic operators (`+`, `-`, `*`, `/`)
- pre/post increment and decrement
- static `min()` and `max()` overloads (const and non-const)

The test program demonstrates each operator family and validates `min`/`max` behavior.

<a id="ex03"></a>
### ex03 - BSP

**Learning objective:** apply fixed-point math to geometry with immutable point objects.

**Run:**

```bash
make
./bsp
```

**Behavior:**

Introduces a `Point` class (based on `Fixed`) and a `bsp()` function that checks whether a point lies strictly inside a triangle.

- Inside points return `true`
- Outside points return `false`
- Points on triangle edges/vertices are treated as outside

**Output example:**

```bash
./bsp
insidePoint is inside? Yes
outsidePoint is inside? No
edgePoint is inside? No
```
