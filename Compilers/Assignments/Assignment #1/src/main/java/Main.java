import org.antlr.v4.runtime.*;
import java.util.*;
import java.util.stream.*;
import java.io.*;
import static java.lang.System.out;

public class Main {
    public static class MyToken {
        public String tokenType;
        public String lexeme;
        public MyToken(String tokenType, String lexeme) {
            this.tokenType = tokenType;
            this.lexeme = lexeme;
        }
    }

    public static Stream<MyToken> analyze(String filename) {
        ArrayList<MyToken> result = new ArrayList<MyToken>();

        try{
            JLexer lexer = new JLexer(CharStreams.fromFileName("./resources/"+filename));
            CommonTokenStream stream = new CommonTokenStream(lexer);
            stream.fill();

            for(Token tok : stream.getTokens()) {
                if(tok.getType() == lexer.K_class){
                    result.add(new MyToken("K_class", tok.getText()));
                }else if(tok.getType() == lexer.K_import){
                    result.add(new MyToken("K_import", tok.getText()));
                }else if(tok.getType() == lexer.K_public){
                    result.add(new MyToken("K_public", tok.getText()));
                }else if(tok.getType() == lexer.K_while){
                    result.add(new MyToken("K_while", tok.getText()));
                }else if(tok.getType() == lexer.K_void){
                    result.add(new MyToken("K_void", tok.getText()));
                }else if(tok.getType() == lexer.EQ){
                    result.add(new MyToken("EQ", tok.getText()));
                }else if(tok.getType() == lexer.PLUS){
                    result.add(new MyToken("PLUS", tok.getText()));
                }else if(tok.getType() == lexer.MINUS){
                    result.add(new MyToken("MINUS", tok.getText()));
                }else if(tok.getType() == lexer.MULT){
                    result.add(new MyToken("MULT", tok.getText()));
                }else if(tok.getType() == lexer.DIV){
                    result.add(new MyToken("DIV", tok.getText()));
                }else if(tok.getType() == lexer.OPEN_PAREN){
                    result.add(new MyToken("OPEN_PAREN", tok.getText()));
                }else if(tok.getType() == lexer.CLOSE_PAREN){
                    result.add(new MyToken("CLOSE_PAREN", tok.getText()));
                }else if(tok.getType() == lexer.OPEN_BRACKET){
                    result.add(new MyToken("OPEN_BRACKET", tok.getText()));
                }else if(tok.getType() == lexer.CLOSE_BRACKET){
                    result.add(new MyToken("CLOSE_BRACKET", tok.getText()));
                }else if(tok.getType() == lexer.OPEN_ANG_BRACKET){
                    result.add(new MyToken("OPEN_ANG_BRACKET", tok.getText()));
                }else if(tok.getType() == lexer.CLOSE_ANG_BRACKET){
                    result.add(new MyToken("CLOSE_ANG_BRACKET", tok.getText()));
                }else if(tok.getType() == lexer.OPEN_CURLY_BRACE){
                    result.add(new MyToken("OPEN_CURLY_BRACE", tok.getText()));
                }else if(tok.getType() == lexer.CLOSED_CURLY_BRACE){
                    result.add(new MyToken("CLOSED_CURLY_BRACE", tok.getText()));
                }else if(tok.getType() == lexer.SEMICOLON){
                    result.add(new MyToken("SEMICOLON", tok.getText()));
                }else if(tok.getType() == lexer.ID){
                    result.add(new MyToken("ID", tok.getText()));
                }else if(tok.getType() == lexer.MEMBER){
                    result.add(new MyToken("MEMBER", tok.getText()));
                }else if(tok.getType() == lexer.NUMBER){
                    result.add(new MyToken("NUMBER", tok.getText()));
                }else if(tok.getType() == lexer.STRING){
                    result.add(new MyToken("STRING", tok.getText()));
                }else if(tok.getType() == lexer.COMMENT){
                    result.add(new MyToken("COMMENT", tok.getText()));
                }else if(tok.getType() == Token.EOF){
                    result.add(new MyToken("EOF", "<EOF>"));
                }
            }
        }catch(Exception ex){
            System.out.println(ex.toString());
        }
        return result.stream();
    }
	
    public static void main(String[] args) {
        String filename = args[0];
        analyze(filename)
            .forEach(x -> {
                out.println(x);
            });

    }
}
