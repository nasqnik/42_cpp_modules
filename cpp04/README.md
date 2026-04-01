# CPP04 Module

## Overview

This module introduces subtype polymorphism in C++, including virtual functions, abstract classes, and deep copy management for dynamically allocated members.

## Build

Each exercise directory contains its own `Makefile`.

```bash
cd <exercise folder>
make
```

## Contents

This module contains 3 exercises: `ex00` - `ex02`.

- [ex00 - Polymorphism](#ex00)
- [ex01 - I don't want to set the world on fire](#ex01)
- [ex02 - Abstract class](#ex02)

<a id="ex00"></a>
### ex00 - Polymorphism

**Learning objective:** understand runtime polymorphism with virtual methods and virtual destructors.

**Run:**

```bash
make
./ex00
```

**Behavior:**

Implements `Animal`, `Dog`, and `Cat` classes using virtual `makeSound()` for proper dynamic dispatch through base pointers.

Also includes `WrongAnimal` and `WrongCat` to demonstrate what happens when methods are not virtual.

- `Animal*` to `Dog`/`Cat` calls the derived `makeSound()`
- `WrongAnimal*` to `WrongCat` does not dispatch as expected

<a id="ex01"></a>
### ex01 - I don't want to set the world on fire

**Learning objective:** manage dynamically allocated composition (`Brain`) with deep copy semantics.

**Run:**

```bash
make
./ex01
```

**Behavior:**

Adds a `Brain` member to `Dog` and `Cat`, then validates Orthodox Canonical Form behavior (copy constructor and assignment) with independent brain data after copying.

The test creates an array of `Animal*`, allocates `Dog`/`Cat` objects, compares copied ideas, mutates originals, and verifies copies stay unchanged.

<a id="ex02"></a>
### ex02 - Abstract class

**Learning objective:** enforce abstraction by making the base class non-instantiable with pure virtual methods.

**Run:**

```bash
make
./ex02
```

**Behavior:**

Replaces concrete `Animal` with abstract `AAnimal` (pure virtual `makeSound()`), so only derived concrete classes (`Dog`, `Cat`) can be instantiated.

The test uses `AAnimal*` polymorphic arrays, invokes sounds via virtual dispatch, and deletes through base pointers to validate proper destruction.
