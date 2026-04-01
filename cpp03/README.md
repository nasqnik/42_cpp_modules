# CPP03 Module

## Overview

This module introduces inheritance in C++, including single inheritance, method overriding, constructor/destructor chaining, and multiple inheritance with diamond-shaped hierarchy handling.

## Build

Each exercise directory contains its own `Makefile`.

```bash
cd <exercise folder>
make
```

## Contents

This module contains 4 exercises: `ex00` - `ex03`.

- [ex00 - Aaaaand... OPEN!](#ex00)
- [ex01 - Serena, my love!](#ex01)
- [ex02 - Repetitive work](#ex02)
- [ex03 - Now it's weird!](#ex03)

<a id="ex00"></a>
### ex00 - Aaaaand... OPEN!

**Learning objective:** implement a base class with state and actions in Orthodox Canonical Form.

**Run:**

```bash
make
./ClapTrap
```

**Behavior:**

Implements `ClapTrap` with core attributes (`name`, `hit points`, `energy points`, `attack damage`) and actions:

- `attack()`
- `takeDamage()`
- `beRepaired()`

The test checks normal combat flow, energy depletion, and copy/assignment behavior.

<a id="ex01"></a>
### ex01 - Serena, my love!

**Learning objective:** derive a class from `ClapTrap` and add specialized behavior.

**Run:**

```bash
make
./ScavTrap
```

**Behavior:**

Introduces `ScavTrap` as a `ClapTrap` child class with adjusted default stats and a new method:

- `guardGate()`

The test demonstrates inherited actions, damage/repair flow, and the ScavTrap-specific guard mode.

<a id="ex02"></a>
### ex02 - Repetitive work

**Learning objective:** extend an inheritance tree with another derived class and verify polymorphic-like behavior through overriding.

**Run:**

```bash
make
./FragTrap
```

**Behavior:**

Adds `FragTrap` with its own defaults and special ability:

- `highFivesGuys()`

The test exercises `ClapTrap`, `ScavTrap`, and `FragTrap` objects, including copy/assignment checks and boundary cases.

<a id="ex03"></a>
### ex03 - Now it's weird!

**Learning objective:** implement multiple inheritance and resolve duplicated base subobjects in a diamond hierarchy.

**Run:**

```bash
make
./DiamondTrap
```

**Behavior:**

Introduces `DiamondTrap`, combining `ScavTrap` and `FragTrap` traits while keeping distinct identity handling.

- Uses `ScavTrap::attack()` behavior
- Exposes `whoAmI()` to print both DiamondTrap name and inherited ClapTrap name

The test validates constructor/assignment flow and identity reporting across objects.
