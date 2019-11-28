lexer grammar JLexer;

K_import : 'import' ;
K_public : 'public' ;
K_class : 'class' ;
K_while : 'while' ;
K_void : 'void' ;

EQ : '=';
PLUS : '+';
MINUS : '-';
MULT : '*';
DIV : '/';

OPEN_PAREN : '(';
CLOSE_PAREN : ')';

OPEN_BRACKET : '[';
CLOSE_BRACKET : ']';

OPEN_ANG_BRACKET : '<';
CLOSE_ANG_BRACKET : '>';

OPEN_CURLY_BRACE : '{';
CLOSED_CURLY_BRACE : '}';

SEMICOLON: ';';

ID : ([a-zA-Z0-9]+);

MEMBER : ('.'ID);

STRING : '"'[a-zA-Z0-9]+'"';

NUMBER: ([0-9]+);

COMMENT : ('//' ~[\r\n]* | '/*' .*? '*/')   -> channel(HIDDEN);
WHITE_SPACE : [ \r\n\t]                     -> channel(HIDDEN);