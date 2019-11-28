grammar Paren;

/* Complete the grammar */

WHITESPACE : (' ' | '\t' | '\n' | '\r')+ -> skip;

expr : '()'
     | '(' expr ')'
     ;
	 
exprGroup : expr expr;

exprTree : exprGroup exprGroup;