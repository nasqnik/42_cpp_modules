# CPP05 Module

## Overview

This module introduces exception handling in C++, focusing on robust class invariants, grade-based authorization, and polymorphic form execution workflows.

## Build

Each exercise directory contains its own `Makefile`.

```bash
cd <exercise folder>
make
```

## Contents

This module contains 4 exercises: `ex00` - `ex03`.

- [ex00 - Mommy, when I grow up, I want to be a bureaucrat!](#ex00)
- [ex01 - Form up, maggots!](#ex01)
- [ex02 - No, you need form 28B, not 28C...](#ex02)
- [ex03 - At least this beats coffee-making](#ex03)

<a id="ex00"></a>
### ex00 - Mommy, when I grow up, I want to be a bureaucrat!

**Learning objective:** design a class with strict value bounds and custom exceptions.

**Run:**

```bash
make
./ex00
```

**Behavior:**

Implements `Bureaucrat` with immutable name and bounded grade (`1` highest, `150` lowest).

- constructing with invalid grades throws exceptions
- `incrementGrade()` and `decrementGrade()` enforce limits
- stream output (`operator<<`) prints a readable bureaucrat summary

The test covers valid/invalid construction and boundary-grade increment/decrement failures.

<a id="ex01"></a>
### ex01 - Form up, maggots!

**Learning objective:** model interactions between classes with validation and exception-safe signing logic.

**Run:**

```bash
make
./ex01
```

**Behavior:**

Introduces `Form`, which has:

- immutable name
- immutable signing/execution grade requirements
- mutable signed state

`Bureaucrat` can attempt to sign forms; signing fails when grade is too low and reports the reason.

The test checks form grade validation and multiple signing scenarios.

<a id="ex02"></a>
### ex02 - No, you need form 28B, not 28C...

**Learning objective:** use abstract base classes and derived implementations for extensible behavior.

**Run:**

```bash
make
./ex02
```

**Behavior:**

Replaces `Form` with abstract `AForm` and adds concrete forms:

- `ShrubberyCreationForm`
- `RobotomyRequestForm`
- `PresidentialPardonForm`

Execution requires:

- form is signed
- executor grade is high enough

Each derived form implements its own action (file creation, randomized robotomy, pardon message). The test exercises sign/execute success and failure paths for each form type.

<a id="ex03"></a>
### ex03 - At least this beats coffee-making

**Learning objective:** implement a factory-style creator that instantiates derived forms from string identifiers.

**Run:**

```bash
make
./ex03
```

**Behavior:**

Adds `Intern` with `makeForm(formName, target)` that creates the requested concrete `AForm`.

- known names create the matching form
- unknown names throw an exception

The test validates unknown-form handling and full create/sign/execute flow for all supported form types.
