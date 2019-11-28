import org.junit.Before;
import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.Assert.*;

public class ActionDeleteTest {

    List<String> users = new ArrayList<>();
    String argument;

    @Before
    public void setUp() throws Exception {
        users.add("User01          FS 000100");
        users.add("User02          FS 000100");
        argument = "User02          FS 000100";
    }

    @Test
    public void userDoesntExist() {
        argument = "User03          FS 000100";
        //get name from arguments
        String username = argument.substring(0, 15);
        boolean found = false;

        for(int i = 0; i<users.size(); i++){
            if(users.get(i).substring(0, 15).trim().toLowerCase().contains(username.trim().toLowerCase())){
                found = true;
            }
        }
        assertFalse("User Found", found);
    }

    @Test
    public void userExist() {
        //get name from arguments
        String username = argument.substring(0, 15);
        boolean found = false;

        for(int i = 0; i<users.size(); i++){
            if(users.get(i).substring(0, 15).trim().toLowerCase().contains(username.trim().toLowerCase())){
                found = true;
            }
        }
        assertTrue("User Not Found", found);
    }

    @Test
    public void userSuccessDelete() {
        //get name from arguments
        String username = argument.substring(0, 15);

        for(int i = 0; i<users.size(); i++){
            if(users.get(i).substring(0, 15).trim().toLowerCase().contains(username.trim().toLowerCase())){
                users.remove(i);
            }
        }
        boolean Exists = Actions.searchArray(users, username);
        assertFalse("User Deleted", Exists);
    }
}