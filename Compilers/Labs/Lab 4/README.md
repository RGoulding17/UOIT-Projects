# Context Free Grammar with Antlr

In this lab, we will be looking at parsing strings with _context free grammar_
(CFG) using ANTLR.

Consider the _non regular_ language of arbitrary
nested and matching parentheses.  Here are some
examples of strings that belong to the language:

- `()`
- `(())`
- `()(())`
- `((()()()))(())`

Let's first author a CFG.

## Step 1: match parentheses

We first will design a language of simple match parentheses that consists
of strings like:

- `()`
- `(())`
- `((()))`

Here are the ANTLR grammar rules that express this language.

```
expr : '()'
     | '(' expr ')'
     ;
```

### Step 2: Try it out

- Develop a complete `Paren.g4` file. You should *ignore* any whitespace
by introducing a lexer rule:
  ```
  WHITESPACE : (' ' | '\t' | '\n' | '\r')+ -> skip;
  ```

- Write a driver `Main.java` to parse a given text file.  It needs to:

    1. Construct the CharStream
    2. Construct a `ParenLexer` which is generated from the `Paren.g4` grammar.
    3. Construct the CommonTokenStream
    4. Construct a `ParenParser` which is generated from the `Paren.g4` grammar.
    5. Perform parsing by `parser.expr()`.  Note `expr` is the head of
       the rule.

Use the provided `build.gradle` to compile and run your Main class with:

```
gradle run --args="<filename>"
```

where the filename is the file containing a string.

### Step 3: Multiple matching parentheses groups

Let's extend the grammar to handle the following _additional_ strings:

- `()()`
- `((()))(())`

Do so, by creating new grammar rules.

```
exprGroup : ...
```

Use as many additional rules as you feel necessary to express the extended
language.

Modify `Main.java` to perform parsing using `parser.exprGroup()`.

Make sure that you can parse both `test1.expr` and `test2.exprGroup`.

### Step 4: Challenge

Can your parser successfully accept `test3.exprTree`?

If not, can you enhance your grammar so that it can accept all three test files?
