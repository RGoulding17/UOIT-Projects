import org.junit.*;
import static org.junit.Assert.*;
import org.antlr.v4.runtime.*;
import java.util.*;
import java.util.stream.*;

public class Test1 {
    @Test
    public void test1() {
        String filename = "Test1.java";
        List<String> lexemes = Main.analyze(filename)
            .map(x -> x.lexeme)
            .collect(Collectors.toList());

        String[] expected = new String[] {
            "class",
            "Test1",
            "{",
            "void",
            "print",
            "(",
            ")",
            "{",
            "}",
            "}",
            "<EOF>"
        };

        assertArrayEquals(expected, lexemes.toArray());
    }

    @Test
    public void test2() {
        String filename = "Test2.java";
        List<String> tokenTypes = Main.analyze(filename)
            .map(x -> x.tokenType)
            .collect(Collectors.toList());

        String[] expected = new String[] {
            "COMMENT",
            "ID",
            "MEMBER",
            "MEMBER",
            "OPEN_PAREN",
            "STRING",
            "CLOSE_PAREN",
            "SEMICOLON",
            "COMMENT",
            "EOF"
        };

        assertArrayEquals(expected, tokenTypes.toArray());
    }
}
