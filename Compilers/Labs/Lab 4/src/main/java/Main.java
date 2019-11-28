import org.antlr.v4.runtime.*;

class Main {
    public static void main(String... args) throws Exception {
        String filename = args[0];
        CharStream input = CharStreams.fromFileName(filename);
        ParenLexer lexer = new ParenLexer(input);
        CommonTokenStream tokens = new CommonTokenStream(lexer);
        ParenParser parser = new ParenParser(tokens);

        parser.expr();
		parser.exprGroup();
    }
}
