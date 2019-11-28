import org.junit.Before;
import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.Assert.*;

public class ActionAdvertiseTest {
    List<String> items = new ArrayList<>();
    String argument;

    @Before
    public void setUp() throws Exception {
        items.add("Computer                  User01          N/A             001 000150");
        items.add("Monitor                   User01          N/A             030 000200");
        argument = "Keyboard                  User02          014 000050";
    }

    @Test
    public void advertiseSuccess() {
        assertTrue("Adding Items", items.add(argument.substring(0, 42) + String.format("%-16s", "N/A") + argument.substring(42, 52)));
    }
}