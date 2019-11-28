grammar Expr;

program : stmt+;

stmt: expression (COMMENT)?
    | COMMENT
    | expression
    | OUTPUT;

expression: ('(')? FACTOR operator (FACTOR|expression) (')')? (precision)? 
          | FACTOR precision
          | FACTOR;

FACTOR: ('sin(')?[0-9]+(.[0-9]+)?(')')? ;

OPEN_PAREN : '(';
CLOSE_PAREN : ')';

precision : ':'FACTOR;

OUTPUT: '"'([a-zA-Z]+(' ')?)+'"';

COMMENT : '# '(([a-zA-Z0-9]+|PERIOD|EQ|PLUS|MINUS|MULT|DIV|POW|OPEN_PAREN|CLOSE_PAREN)(' ')?)+;

operator: EQ 
        | PLUS 
        | MINUS 
        | MULT 
        | DIV 
        | POW;
        
EQ : '=';
PLUS : '+';
MINUS : '-';
MULT : '*';
DIV : '/';
POW: '^';
PERIOD: '.';

NEWLINE: [\n]->skip;
WHITESPACE: (' ' | '\t' )+ -> skip;