# Math Expression Parser

A recursive descent expression parser written in C++17 that takes a math expression from user input and computes a mathematically correct result respecting order of operations.

## Features

* Operators: `+`, `-`, `*`, `/`, `^`
* Math functions: `sin()`, `cos()`, `tan()`, `ln()`, `log()`, `sqrt()`
* Floating point numbers
* Parentheses grouping
* Correct order of operations (PEMDAS)
* REPL — interactive loop with `quit` to exit
* Expression history — type `history` to see past results

## Build

```bash
mkdir build && cd build
cmake ..
make
./parser
```

## Usage

The parser runs in an interactive REPL loop. Type math expressions to evaluate them,
`history` to view past results, or `quit` to exit.

```
Math parser - Throw your equasion here: 3 + 4 * 2
= 11

Math parser - Throw your equasion here: (3 + 4) * 2
= 14

Math parser - Throw your equasion here: 2 ^ 10
= 1024

Math parser - Throw your equasion here: sin(45)
= 0.707107

Math parser - Throw your equasion here: history
Output 0: 3 + 4 * 2 = 11
Output 1: (3 + 4) * 2 = 14
Output 2: 2 ^ 10 = 1024
Output 3: sin(45) = 0.707107

Math parser - Throw your equasion here: quit
```

## Roadmap

| Phase | Features |
|-------|----------|
| ✅ 1 | Basic arithmetic, operator precedence, parentheses |
| ✅ 2 | Built-in functions: `sin()`, `cos()`, `sqrt()`, `log()` ... |
| 🔜 3 | Variables, expression history |
| 🔜 4 | DSP mode — FFT and signal analysis |
