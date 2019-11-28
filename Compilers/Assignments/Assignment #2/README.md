# Assignment 2 - Parsing

<div style="border:thin solid red; padding: 20px; color: red">
  <p style="margin:0; padding: 0">Your submission will be processed by source code analyzers
  for plagiarism.  You <b>must</b> work on your own assignment
  <b>individually</b>.  Sharing code is strictly prohibited.</p>
</div>

<br>


In this assignment, we will be building a parser to recognize a
simple programming language.

## 1. Grammar Design

Design a grammar for the following language.

### Arithmetic expressions

The following are expressions:

```
1 + 3.1415
```

```
3 * 4 + 3.1415 * 2
```

```
1 + (2 * 3.1415) / (5 * sin(1.23))
```

### Comments

We allow comments:

```
# This is the area of a circle with radius 8.0
3.1415 * 8.0 ^ 2
```

### Precision control

We can control the precision of an expression to arbitrary
number of decimal places with a precision-control 
`... : n` expression.

```
3:2
(3.1415 * 8.0 ^ 2):2
```

### Output

The expressions are displayed to the output in decimal format. We can
optionally attach a string to the start of each line.

```
"radius is" 10
"pi is" 3.1415
"area of this circle as an integer is" (3.1415 * 10^2):0
```

### Complete program

A complete program is zero or more lines, and each line
is an expression with possible comments and output messages.


## 2. Programming

You will be provided a template project.  You need to complete the grammar file,
and ensure that all the tests pass with `gradle run`.

### SUBMISSION

> You need to author a grammar file `Expr.g4` to accept valid programs.
> The start symbol must be `program`.
