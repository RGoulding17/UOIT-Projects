import org.junit.*;
import static org.junit.Assert.*;

public class TestApp {
    @Test
    public void Test0() {
        assertTrue("Just checking...", true);
    }

    @Test
    public void TestReverse() {
        assertEquals(App.reverse(""), "");
        assertEquals(App.reverse(null), null);
        assertEquals(App.reverse("abc"), "cba");
    }

    @Test
    public void TestMain() {
        try {
            App.main(new String[] {"this-does-not-exist"});
            fail("Should throw exception");
        } catch(Exception e) {
            assertTrue(true);
        }
    }

}