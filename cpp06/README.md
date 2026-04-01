# CPP06 Module

## Overview

This module introduces C++ casts and type conversion mechanisms, including scalar literal conversion, pointer serialization/deserialization, and runtime type identification (RTTI).

## Build

Each exercise directory contains its own `Makefile`.

```bash
cd <exercise folder>
make
```

## Contents

This module contains 3 exercises: `ex00` - `ex02`.

- [ex00 - Conversion of scalar types](#ex00)
- [ex01 - Serialization](#ex01)
- [ex02 - Identify real type](#ex02)

<a id="ex00"></a>
### ex00 - Conversion of scalar types

**Learning objective:** convert string literals to scalar C++ types and handle edge cases consistently.

**Run:**

```bash
make
./convert <literal>
```

**Behavior:**

Implements `ScalarConverter` with a static `convert()` method that parses one input literal and prints its representations as:

- `char`
- `int`
- `float`
- `double`

Handles special values and non-displayable/impossible conversions with appropriate output messages.

<a id="ex01"></a>
### ex01 - Serialization

**Learning objective:** reinterpret pointers safely through integer types using `uintptr_t`.

**Run:**

```bash
make
./ex01
```

**Behavior:**

Implements `Serializer` with:

- `serialize(Data*)` -> `uintptr_t`
- `deserialize(uintptr_t)` -> `Data*`

The test verifies that serializing then deserializing preserves the original pointer identity and accesses the same underlying `Data` object.

<a id="ex02"></a>
### ex02 - Identify real type

**Learning objective:** use `dynamic_cast` for runtime type identification through base-class interfaces.

**Run:**

```bash
make
./ex02
```

**Behavior:**

Defines polymorphic base `Base` and derived classes `A`, `B`, and `C`, then:

- generates a random derived instance via `Base*`
- identifies its real type using `identify(Base*)`
- identifies its real type using `identify(Base&)`

The implementation demonstrates pointer-based checks and reference-based checks with exception handling for failed casts.
