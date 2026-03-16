# Math Expression Parser

A recursive descent expression parser written in C++17 that takes a math expression from user input and computes a mathematically correct result respecting order of operations.

## Features

* Operators: `+`, `-`, `*`, `/`, `^` 
* Math functions: `sin()`, `cos()`, `tan()`, `ln()`, `log()`, `sqrt()`
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

Recently implemented working math functions sin, cos, tan, ln, log, sqrt coming
with PHASE 2 of this project's roadmap. 

```
Math parser - Throw your equasion here: 3 + 4 * 2
= 11

Math parser - Throw your equasion here: (3 + 4) * 2
= 14

Math parser - Throw your equasion here: 2 ^ 10
= 1024

Math parser - Throw your equasion here: 5 + cos(120)
= 4.5

Math parser - Throw your equasion here: 2*ln(30) + 230*sin(45)             
= 169.437

```

## Roadmap

| Phase | Features |
|-------|----------|
| ✅ 1 | Basic arithmetic, operator precedence, parentheses |
| ✅ 2 | Built-in functions: `sin()`, `cos()`, `sqrt()`, `log()` ... |
| 🔜 3 | Variables, expression history |
| 🔜 4 | DSP mode — FFT and signal analysis |
