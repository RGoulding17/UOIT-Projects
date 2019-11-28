import org.junit.*;
import static org.junit.Assert.*;
import org.antlr.v4.runtime.*;

public class TestParser {
    static int goodCount = 4;
    static int badCount = 4;

    public void testGood(String filename) {
        try {
            Main.parse(filename);
            assertTrue(true);
        } catch(Exception e) {
            fail("Parser error \"" + filename + "\": " + e.getMessage());
        }
    }

    public void testBad(String filename) {
        try {
            Main.parse(filename);
            fail("Failed: " + filename);
        } catch(Exception e) {
            assertTrue(true);
            System.out.println(e);
        }

    }

    @Test
    public void testGood1() {
        testGood("good_1.expr");
    }

    @Test
    public void testGood2() {
        testGood("good_2.expr");
    }

    @Test
    public void testGood3() {
        testGood("good_3.expr");
    }

    @Test
    public void testGood4() {
        testGood("good_4.expr");
    }

    @Test
    public void testBad1() {
        testBad("bad_1.expr");
    }

    @Test
    public void testBad2() {
        testBad("bad_2.expr");
    }

    @Test
    public void testBad3() {
        testBad("bad_3.expr");
    }

    @Test
    public void testBad4() {
        testBad("bad_4.expr");
    }
}
