# Catalan Numbers in C++

This project implements a recursive solution for computing Catalan numbers in C++. The program takes a command-line argument and outputs the corresponding Catalan number.

Catalan numbers are widely used in combinatorics, particularly in counting problems involving recursive structures such as binary trees and valid parenthesis expressions.

## How It Works

The implementation uses the recursive definition:

C(n) = Σ (C(i) * C(n - i - 1)) for i = 0 to n - 1

Base case:
- C(0) = 1

## Features

- Recursive computation of Catalan numbers
- Command-line input support
- Input validation for incorrect or missing arguments
- Error handling for negative inputs
- Uses standard C++ I/O

## Example Usage

Compile:
g++ catalan.cpp -o catalan



Run:
./catalan <number>

Output:
<number>


## Concepts Demonstrated

- Recursion
- Mathematical combinatorics
- Command-line argument parsing
- Input validation in C++
- Basic algorithm design

## Notes

This implementation is intentionally simple and uses pure recursion, which makes it useful for demonstrating the recursive structure of Catalan numbers.
