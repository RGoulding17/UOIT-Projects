import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;

public class Main {
    static class ThrowingErrorListener extends BaseErrorListener { 
        public static final ThrowingErrorListener INSTANCE 
            = new ThrowingErrorListener(); 
        @Override 
        public void syntaxError(
                Recognizer<?, ?> recognizer, 
                Object offendingSymbol, 
                int line, 
                int charPositionInLine, 
                String msg, 
                RecognitionException e) 
            throws ParseCancellationException { 
            throw new ParseCancellationException(
                    "line "
                    + line
                    + ":"
                    + charPositionInLine + " " + msg); 
        } 
    }

    public static void parse(String filename) throws Exception {
        ExprLexer lexer = new ExprLexer(CharStreams.fromFileName(filename));
        lexer.removeErrorListeners();
        lexer.addErrorListener(ThrowingErrorListener.INSTANCE);

        CommonTokenStream tokens = new CommonTokenStream(lexer);
        ExprParser parser = new ExprParser(tokens);
        parser.removeErrorListeners();
        parser.addErrorListener(ThrowingErrorListener.INSTANCE);

        // Start parsing
        parser.program();
    }
}
