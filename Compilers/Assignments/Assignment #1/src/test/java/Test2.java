import org.junit.*;
import static org.junit.Assert.*;

public class Test2 {
    @Test
    public void test1() {
		NFA A = new NFA()
			.addStates(1,2,3,4,5)
			.start(1)
			.transition(1, 2, 'a')
			.transition(2, 3, 'a')
			.epsilon(3, 1)
			.transition(3, 4, 'b')
			.transition(1, 5, 'a')
			.epsilon(5, 1)
			.finalStates(3, 4, 5);

		String s1 = "aaaab";
        String s2 = "ab";
        assertTrue(A.accept(s1));
        assertTrue(!A.accept(s2));
    }
}
