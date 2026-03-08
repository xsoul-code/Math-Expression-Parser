# Math Expression Parser

A recursive descent expression parser written in C++17 that takes a math expression from user input and computes a mathematically correct result respecting order of operations.

## Features

* Operators: `+`, `-`, `*`, `/`, `^`
* Floating point numbers
* Parentheses grouping
* Correct order of operations (PEMDAS)

## Build

```bash
mkdir build && cd build
cmake ..
make
./parser
```

## Usage

Currently before every result there is token type list created from prompt for troubleshooting new features to come.

```
Math parser - Throw your equasion here: 3 + 4 * 2
= 11

Math parser - Throw your equasion here: (3 + 4) * 2
= 14

Math parser - Throw your equasion here: 2 ^ 10
= 1024
```

## Roadmap

| Phase | Features |
|-------|----------|
| ✅ 1 | Basic arithmetic, operator precedence, parentheses |
| 🔜 2 | Built-in functions: `sin()`, `cos()`, `sqrt()`, `log()` |
| 🔜 3 | Variables, expression history |
| 🔜 4 | DSP mode — FFT and signal analysis |
